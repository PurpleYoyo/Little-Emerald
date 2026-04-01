#include "global.h"
#include "overworld.h"
#include "battle.h"
#include "battle_setup.h"
#include "berry.h"
#include "clock.h"
#include "coins.h"
#include "credits.h"
#include "data.h"
#include "daycare.h"
#include "debug.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "field_message_box.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "international_string_util.h"
#include "item.h"
#include "item_icon.h"
#include "list_menu.h"
#include "m4a.h"
#include "main.h"
#include "main_menu.h"
#include "malloc.h"
#include "map_name_popup.h"
#include "menu.h"
#include "money.h"
#include "naming_screen.h"
#include "new_game.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokedex.h"
#include "pokemon.h"
#include "pokemon_icon.h"
#include "pokemon_storage_system.h"
#include "random.h"
#include "region_map.h"
#include "rtc.h"
#include "script.h"
#include "script_pokemon_util.h"
#include "sound.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "pokemon_summary_screen.h"
#include "wild_encounter.h"
#include "constants/abilities.h"
#include "constants/battle_ai.h"
#include "constants/battle_frontier.h"
#include "constants/coins.h"
#include "constants/expansion.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/map_groups.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/weather.h"
#include "save.h"

void DestroySelectDamageScreen(u8 taskId);

#define TASKIDX_EXIT_CALLBACK 4

#define tHP           data[0]
#define tWindowId     data[1]
#define tFuncId       data[2]
#define tExitCallback data[TASKIDX_EXIT_CALLBACK] // Occupies 4 and 5

static const struct WindowTemplate sSelectDamageWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 12,
    .tilemapTop = 4,
    .width = 8,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 8
};

static const u8 sText_Amount[] = _("HP: {STR_VAR_3}/{STR_VAR_2}");

void SelectDamageHandleInput(u8 taskId)
{
    u32 max_hp = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_MAX_HP);

    ConvertIntToDecimalStringN(gStringVar3, gTasks[taskId].tHP, STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar2, max_hp, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar4, sText_Amount);
    AddTextPrinterParameterized(gTasks[taskId].tWindowId, FONT_NORMAL, gStringVar4, 0, 0, 0, NULL);

    if (JOY_NEW(DPAD_ANY))
    {
        PlaySE(SE_SELECT);

        if (JOY_NEW(DPAD_UP))
        {
            gTasks[taskId].tHP += 1;
            if (gTasks[taskId].tHP >= max_hp)
                gTasks[taskId].tHP = max_hp - 1;
        }
        if (JOY_NEW(DPAD_DOWN))
        {
            gTasks[taskId].tHP -= 1;
            if (gTasks[taskId].tHP < 1)
                gTasks[taskId].tHP = 1;
        }
        if (JOY_NEW(DPAD_LEFT))
        {
            gTasks[taskId].tHP -= 10;
            if (gTasks[taskId].tHP < 1)
                gTasks[taskId].tHP = 1;
        }
        if (JOY_NEW(DPAD_RIGHT))
        {
            gTasks[taskId].tHP += 10;
            if (gTasks[taskId].tHP >= max_hp)
                gTasks[taskId].tHP = max_hp - 1;
        }

        ClearStdWindowAndFrame(gTasks[taskId].tWindowId, FALSE); 

        ConvertIntToDecimalStringN(gStringVar3, gTasks[taskId].tHP, STR_CONV_MODE_LEFT_ALIGN, 3);
        ConvertIntToDecimalStringN(gStringVar2, max_hp, STR_CONV_MODE_LEFT_ALIGN, 3);
        StringExpandPlaceholders(gStringVar4, sText_Amount);
        AddTextPrinterParameterized(gTasks[taskId].tWindowId, FONT_NORMAL, gStringVar4, 0, 0, 0, NULL);
    }

    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);

        SetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_HP, &gTasks[taskId].tHP);

        DestroySelectDamageScreen(taskId);

    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);

        DestroySelectDamageScreen(taskId);
    }
}

void DestroySelectDamageScreen(u8 taskId)
{
    SetMainCallback2(CB2_Overworld);
    ClearStdWindowAndFrame(gTasks[taskId].tWindowId, FALSE);
    DestroyTask(taskId);
    ScriptContext_Enable();
    UnfreezeObjectEvents();
}

void SelectDamage(u8 taskId)
{
    u8 windowId;

    HideMapNamePopUpWindow();
    LoadMessageBoxAndBorderGfx();
    windowId = AddWindow(&sSelectDamageWindowTemplate);
    DrawStdWindowFrame(windowId, FALSE);

    CopyWindowToVram(windowId, COPYWIN_FULL);

    gTasks[taskId].func = SelectDamageHandleInput;
    gTasks[taskId].tWindowId = windowId;
    gTasks[taskId].tHP = 1;
}

static void CB2_SelectDamageScreen(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void DoSelectDamageScreen(MainCallback exitCallback)
{
    u8 taskId;

    ResetTasks();
    taskId = CreateTask(SelectDamage, 0);
    SetMainCallback2(CB2_SelectDamageScreen);
    SetWordTaskArg(taskId, TASKIDX_EXIT_CALLBACK, (u32)exitCallback);
}

void ShowSelectDamageScreen(void)
{
    DoSelectDamageScreen(CB2_ReturnToFieldContinueScript);
}