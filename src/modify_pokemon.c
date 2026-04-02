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

void DestroySelectIvsScreen(u8 taskId);

#define TASKIDX_EXIT_CALLBACK 4

#define tIV           data[0]
#define tWindowId     data[1]
#define tFuncId       data[2]
#define tExitCallback data[TASKIDX_EXIT_CALLBACK] // Occupies 4 and 5

static const struct WindowTemplate sSelectIvsWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 12,
    .tilemapTop = 4,
    .width = 8,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 8
};

static const u8 sText_Amount[] = _("IV: {STR_VAR_3}/{STR_VAR_2}");

void SelectIvsHandleInput(u8 taskId)
{
    u32 max_iv = 31;

    ConvertIntToDecimalStringN(gStringVar3, gTasks[taskId].tIV, STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar2, max_iv, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar4, sText_Amount);
    AddTextPrinterParameterized(gTasks[taskId].tWindowId, FONT_NORMAL, gStringVar4, 0, 0, 0, NULL);

    if (JOY_NEW(DPAD_ANY))
    {
        PlaySE(SE_SELECT);

        if (JOY_NEW(DPAD_UP))
        {
            gTasks[taskId].tIV += 1;
            if (gTasks[taskId].tIV >= max_iv)
                gTasks[taskId].tIV = max_iv;
        }
        if (JOY_NEW(DPAD_DOWN))
        {
            gTasks[taskId].tIV -= 1;
            if (gTasks[taskId].tIV < 0)
                gTasks[taskId].tIV = 0;
        }
        if (JOY_NEW(DPAD_LEFT))
        {
            gTasks[taskId].tIV -= 10;
            if (gTasks[taskId].tIV < 0)
                gTasks[taskId].tIV = 0;
        }
        if (JOY_NEW(DPAD_RIGHT))
        {
            gTasks[taskId].tIV += 10;
            if (gTasks[taskId].tIV >= max_iv)
                gTasks[taskId].tIV = max_iv;
        }

        ClearStdWindowAndFrame(gTasks[taskId].tWindowId, FALSE); 

        ConvertIntToDecimalStringN(gStringVar3, gTasks[taskId].tIV, STR_CONV_MODE_LEFT_ALIGN, 3);
        ConvertIntToDecimalStringN(gStringVar2, max_iv, STR_CONV_MODE_LEFT_ALIGN, 3);
        StringExpandPlaceholders(gStringVar4, sText_Amount);
        AddTextPrinterParameterized(gTasks[taskId].tWindowId, FONT_NORMAL, gStringVar4, 0, 0, 0, NULL);
    }

    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        ConvertIntToDecimalStringN(gStringVar2, gTasks[taskId].tIV, STR_CONV_MODE_LEFT_ALIGN, 3);

        switch (VarGet(STAT))
        {
            default:
            case 0:
                SetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_HP_IV, &gTasks[taskId].tIV);
                break;
            case 1:
                SetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_ATK_IV, &gTasks[taskId].tIV);
                break;
            case 2:
                SetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_DEF_IV, &gTasks[taskId].tIV);
                break;
            case 3:
                SetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPATK_IV, &gTasks[taskId].tIV);
                break;
            case 4:
                SetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPDEF_IV, &gTasks[taskId].tIV);
                break;
            case 5:
                SetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPEED_IV, &gTasks[taskId].tIV);
                break;
        }

        DestroySelectIvsScreen(taskId);

    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);

        DestroySelectIvsScreen(taskId);
    }
}

void DestroySelectIvsScreen(u8 taskId)
{
    SetMainCallback2(CB2_Overworld);
    ClearStdWindowAndFrame(gTasks[taskId].tWindowId, FALSE);
    DestroyTask(taskId);
    ScriptContext_Enable();
    UnfreezeObjectEvents();
}

void SelectIvs(u8 taskId)
{
    u8 windowId;

    HideMapNamePopUpWindow();
    LoadMessageBoxAndBorderGfx();
    windowId = AddWindow(&sSelectIvsWindowTemplate);
    DrawStdWindowFrame(windowId, FALSE);

    CopyWindowToVram(windowId, COPYWIN_FULL);

    gTasks[taskId].func = SelectIvsHandleInput;
    gTasks[taskId].tWindowId = windowId;
    gTasks[taskId].tIV = 1;
}

static void CB2_SelectIvsScreen(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void DoSelectIvsScreen(MainCallback exitCallback)
{
    u8 taskId;

    ResetTasks();
    taskId = CreateTask(SelectIvs, 0);
    SetMainCallback2(CB2_SelectIvsScreen);
    SetWordTaskArg(taskId, TASKIDX_EXIT_CALLBACK, (u32)exitCallback);
}

void ShowSelectIvsScreen(void)
{
    DoSelectIvsScreen(CB2_ReturnToFieldContinueScript);
}

///////////////////////////////////////////////////////////////////////////////////////////////

void DestroySelectEvsScreen(u8 taskId);

#define TASKIDX_EXIT_CALLBACK 4

#define tEV           data[0]
#define tWindowId     data[1]
#define tFuncId       data[2]
#define tExitCallback data[TASKIDX_EXIT_CALLBACK] // Occupies 4 and 5

static const struct WindowTemplate sSelectEvsWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 12,
    .tilemapTop = 4,
    .width = 8,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 8
};

void SelectEvsHandleInput(u8 taskId)
{
    u32 max_ev = 252;

    ConvertIntToDecimalStringN(gStringVar3, gTasks[taskId].tEV, STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar2, max_ev, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar4, sText_Amount);
    AddTextPrinterParameterized(gTasks[taskId].tWindowId, FONT_NORMAL, gStringVar4, 0, 0, 0, NULL);

    if (JOY_NEW(DPAD_ANY))
    {
        PlaySE(SE_SELECT);

        if (JOY_NEW(DPAD_UP))
        {
            gTasks[taskId].tEV += 1;
            if (gTasks[taskId].tEV >= max_ev)
                gTasks[taskId].tEV = max_ev;
        }
        if (JOY_NEW(DPAD_DOWN))
        {
            gTasks[taskId].tEV -= 1;
            if (gTasks[taskId].tEV < 0)
                gTasks[taskId].tEV = 0;
        }
        if (JOY_NEW(DPAD_LEFT))
        {
            gTasks[taskId].tEV -= 10;
            if (gTasks[taskId].tEV < 0)
                gTasks[taskId].tEV = 0;
        }
        if (JOY_NEW(DPAD_RIGHT))
        {
            gTasks[taskId].tEV += 10;
            if (gTasks[taskId].tEV >= max_ev)
                gTasks[taskId].tEV = max_ev;
        }

        ClearStdWindowAndFrame(gTasks[taskId].tWindowId, FALSE); 

        ConvertIntToDecimalStringN(gStringVar3, gTasks[taskId].tEV, STR_CONV_MODE_LEFT_ALIGN, 3);
        ConvertIntToDecimalStringN(gStringVar2, max_ev, STR_CONV_MODE_LEFT_ALIGN, 3);
        StringExpandPlaceholders(gStringVar4, sText_Amount);
        AddTextPrinterParameterized(gTasks[taskId].tWindowId, FONT_NORMAL, gStringVar4, 0, 0, 0, NULL);
    }

    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        ConvertIntToDecimalStringN(gStringVar2, gTasks[taskId].tEV, STR_CONV_MODE_LEFT_ALIGN, 3);

        switch (VarGet(STAT))
        {
            default:
            case 0:
                SetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_HP_EV, &gTasks[taskId].tEV);
                break;
            case 1:
                SetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_ATK_EV, &gTasks[taskId].tEV);
                break;
            case 2:
                SetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_DEF_EV, &gTasks[taskId].tEV);
                break;
            case 3:
                SetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPATK_EV, &gTasks[taskId].tEV);
                break;
            case 4:
                SetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPDEF_EV, &gTasks[taskId].tEV);
                break;
            case 5:
                SetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPEED_EV, &gTasks[taskId].tEV);
                break;
        }

        DestroySelectEvsScreen(taskId);

    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);

        DestroySelectEvsScreen(taskId);
    }
}

void DestroySelectEvsScreen(u8 taskId)
{
    SetMainCallback2(CB2_Overworld);
    ClearStdWindowAndFrame(gTasks[taskId].tWindowId, FALSE);
    DestroyTask(taskId);
    ScriptContext_Enable();
    UnfreezeObjectEvents();
}

void SelectEvs(u8 taskId)
{
    u8 windowId;

    HideMapNamePopUpWindow();
    LoadMessageBoxAndBorderGfx();
    windowId = AddWindow(&sSelectEvsWindowTemplate);
    DrawStdWindowFrame(windowId, FALSE);

    CopyWindowToVram(windowId, COPYWIN_FULL);

    gTasks[taskId].func = SelectEvsHandleInput;
    gTasks[taskId].tWindowId = windowId;
    gTasks[taskId].tEV = 1;
}

static void CB2_SelectEvsScreen(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void DoSelectEvsScreen(MainCallback exitCallback)
{
    u8 taskId;

    ResetTasks();
    taskId = CreateTask(SelectEvs, 0);
    SetMainCallback2(CB2_SelectEvsScreen);
    SetWordTaskArg(taskId, TASKIDX_EXIT_CALLBACK, (u32)exitCallback);
}

void ShowSelectEvsScreen(void)
{
    DoSelectEvsScreen(CB2_ReturnToFieldContinueScript);
}