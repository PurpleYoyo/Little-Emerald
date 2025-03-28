#include "global.h"
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
#include "../include/item_use.h"
#include "../include/item_menu.h"
#include "../include/field_effect.h"

enum UtilitiesMenu
{
    UTILITIES_MENU_ITEM_POKEMON_BOX_LINK,
    UTILITIES_MENU_ITEM_POKEVIAL,
    UTILITIES_MENU_ITEM_INFINITE_REPEL,
    UTILITIES_MENU_ITEM_HATCH_EGG,
    UTILITIES_MENU_ITEM_CHANGE_TIME,
    UTILITIES_MENU_ITEM_AUTO_RUN,
    UTILITIES_MENU_ITEM_FLASH,
    UTILITIES_MENU_ITEM_ESCAPE_ROPE,
    UTILITIES_MENU_ITEM_WARP_PANEL,
};

#define UTILITIES_WINDOW_HEIGHT 9

struct UtilitiesMenuListData
{
    struct ListMenuItem listItems[20 + 1];
    u8 itemNames[51][26];
    u8 listId;
};

static EWRAM_DATA struct UtilitiesMenuListData *sUtilitiesMenuListData = NULL;

static void Utilities_ShowMenu(void (*HandleInput)(u8), struct ListMenuTemplate LMtemplate);
static void Utilities_DestroyMenu(u8 taskId);
static void Utilities_DestroyMenu_Cancel(u8 taskId);
static void Utilities_RefreshListMenu(u8 taskId);
static void UtilitiesTask_HandleMenuInput(u8 taskId);

static void UtilitiesAction_InfiniteRepel(u8 taskId);
static void UtilitiesAction_HatchEgg(u8 taskId);
static void UtilitiesAction_PokemonBoxLink(u8 taskId);
static void UtilitiesAction_Pokevial(u8 taskId);
static void UtilitiesAction_WarpPanel(u8 taskId);
static void UtilitiesAction_EscapeRope(u8 taskId);
static void UtilitiesAction_AutoRun(u8 taskId);
static void UtilitiesAction_Flash(u8 taskId);
static void UtilitiesAction_ChangeTime(u8 taskId);

extern const u8 PlayersHouse_2F_EventScript_SetWallClock[];

static const u8 sUtilitiesText_InfiniteRepel[] = _("{STR_VAR_1}Infinite Repel");
static const u8 sUtilitiesText_HatchEgg[] = _("Hatch Egg");
static const u8 sUtilitiesText_PokemonBoxLink[] = _("Pokémon Box Link");
static const u8 sUtilitiesText_Pokevial[] = _("Pokévial");
static const u8 sUtilitiesText_WarpPanel[] = _("Warp Panel");
static const u8 sUtilitiesText_EscapeRope[] = _("Escape Rope");
static const u8 sUtilitiesText_AutoRun[] = _("{STR_VAR_1}Auto Run");
static const u8 sUtilitiesText_Flash[] = _("Flashlight");
static const u8 sUtilitiesText_ChangeTime[] = _("Change Time");

static const struct ListMenuItem sUtilitiesMenu_Items[] =
{
    [UTILITIES_MENU_ITEM_POKEMON_BOX_LINK]         = {sUtilitiesText_PokemonBoxLink,        UTILITIES_MENU_ITEM_POKEMON_BOX_LINK},
    [UTILITIES_MENU_ITEM_POKEVIAL]                 = {sUtilitiesText_Pokevial,              UTILITIES_MENU_ITEM_POKEVIAL},
    [UTILITIES_MENU_ITEM_INFINITE_REPEL]           = {sUtilitiesText_InfiniteRepel,         UTILITIES_MENU_ITEM_INFINITE_REPEL},
    [UTILITIES_MENU_ITEM_HATCH_EGG]                = {sUtilitiesText_HatchEgg,              UTILITIES_MENU_ITEM_HATCH_EGG},
    [UTILITIES_MENU_ITEM_CHANGE_TIME]              = {sUtilitiesText_ChangeTime,            UTILITIES_MENU_ITEM_CHANGE_TIME},
    [UTILITIES_MENU_ITEM_AUTO_RUN]                 = {sUtilitiesText_AutoRun,               UTILITIES_MENU_ITEM_AUTO_RUN},
    [UTILITIES_MENU_ITEM_FLASH]                    = {sUtilitiesText_Flash,                 UTILITIES_MENU_ITEM_FLASH},
    [UTILITIES_MENU_ITEM_ESCAPE_ROPE]              = {sUtilitiesText_EscapeRope,            UTILITIES_MENU_ITEM_ESCAPE_ROPE},
    [UTILITIES_MENU_ITEM_WARP_PANEL]               = {sUtilitiesText_WarpPanel,             UTILITIES_MENU_ITEM_WARP_PANEL},
};

static void (*const sUtilitiesMenu_Actions[])(u8) =
{
    [UTILITIES_MENU_ITEM_POKEMON_BOX_LINK]         = UtilitiesAction_PokemonBoxLink,
    [UTILITIES_MENU_ITEM_POKEVIAL]                 = UtilitiesAction_Pokevial,
    [UTILITIES_MENU_ITEM_INFINITE_REPEL]           = UtilitiesAction_InfiniteRepel,
    [UTILITIES_MENU_ITEM_HATCH_EGG]                = UtilitiesAction_HatchEgg,
    [UTILITIES_MENU_ITEM_CHANGE_TIME]              = UtilitiesAction_ChangeTime,
    [UTILITIES_MENU_ITEM_AUTO_RUN]                 = UtilitiesAction_AutoRun,
    [UTILITIES_MENU_ITEM_FLASH]                    = UtilitiesAction_Flash,
    [UTILITIES_MENU_ITEM_ESCAPE_ROPE]              = UtilitiesAction_EscapeRope,
    [UTILITIES_MENU_ITEM_WARP_PANEL]               = UtilitiesAction_WarpPanel,
};

static const struct WindowTemplate sUtilitiesMenuWindowTemplate =
{.bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 14,
    .height = 2 * UTILITIES_WINDOW_HEIGHT,
    .paletteNum = 15,
    .baseBlock = 1,
};

static const struct ListMenuTemplate sUtilitiesMenu_ListTemplate =
{
    .items = sUtilitiesMenu_Items,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .totalItems = ARRAY_COUNT(sUtilitiesMenu_Items),
};

#define tMenuTaskId   data[0]
#define tWindowId     data[1]

static void Utilities_DestroyMenu(u8 taskId)
{
    DestroyListMenuTask(gTasks[taskId].tMenuTaskId, NULL, NULL);
    ClearStdWindowAndFrame(gTasks[taskId].tWindowId, TRUE);
    RemoveWindow(gTasks[taskId].tWindowId);
    DestroyTask(taskId);
    ScriptContext_Enable();
    UnfreezeObjectEvents();
    Free(sUtilitiesMenuListData);
}

static void Utilities_DestroyMenu_Cancel(u8 taskId)
{
    SetMainCallback2(CB2_Overworld);
    Utilities_DestroyMenu(taskId);
}

void Utilities_ShowMainMenu(void)
{
    sUtilitiesMenuListData = AllocZeroed(sizeof(*sUtilitiesMenuListData));

    Utilities_ShowMenu(UtilitiesTask_HandleMenuInput, sUtilitiesMenu_ListTemplate);
}

static void UtilitiesTask_HandleMenuInput(u8 taskId)
{
    void (*func)(u8);
    u32 input = ListMenu_ProcessInput(gTasks[taskId].tMenuTaskId);

    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        if ((func = sUtilitiesMenu_Actions[input]) != NULL)
            func(taskId);
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        Utilities_DestroyMenu_Cancel(taskId);
    }
}

static void Utilities_ShowMenu(void (*HandleInput)(u8), struct ListMenuTemplate LMtemplate)
{
    struct ListMenuTemplate menuTemplate;
    u8 windowId;
    u8 menuTaskId;
    u8 inputTaskId;

    // create window
    HideMapNamePopUpWindow();
    LoadMessageBoxAndBorderGfx();
    windowId = AddWindow(&sUtilitiesMenuWindowTemplate);
    DrawStdWindowFrame(windowId, FALSE);

    // create list menu
    menuTemplate = LMtemplate;
    menuTemplate.maxShowed = UTILITIES_WINDOW_HEIGHT;
    menuTemplate.windowId = windowId;
    menuTemplate.header_X = 0;
    menuTemplate.item_X = 8;
    menuTemplate.cursor_X = 0;
    menuTemplate.upText_Y = 1;
    menuTemplate.cursorPal = 2;
    menuTemplate.fillValue = 1;
    menuTemplate.cursorShadowPal = 3;
    menuTemplate.lettersSpacing = 1;
    menuTemplate.itemVerticalPadding = 0;
    menuTemplate.scrollMultiple = LIST_MULTIPLE_SCROLL_DPAD;
    menuTemplate.fontId = FONT_NORMAL;
    menuTemplate.cursorKind = 0;
    menuTaskId = ListMenuInit(&menuTemplate, 0, 0);

    // create input handler task
    inputTaskId = CreateTask(HandleInput, 3);
    gTasks[inputTaskId].tMenuTaskId = menuTaskId;
    gTasks[inputTaskId].tWindowId = windowId;

    Utilities_RefreshListMenu(inputTaskId);

    // draw everything
    CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void Utilities_RefreshListMenu(u8 taskId)
{
    u8 totalItems = 0;
    totalItems = min(totalItems, 51);
    const u8 sColor_Red[] = _("{COLOR RED}");
    const u8 sColor_Green[] = _("{COLOR GREEN}");

    if (FlagGet(FLAG_RUNNING_SHOES_TOGGLE))
    {
        StringCopy(gStringVar1, sColor_Green);
        StringExpandPlaceholders(gStringVar4, sUtilitiesText_AutoRun);
        StringCopy(&sUtilitiesMenuListData->itemNames[3][0], gStringVar4);
    }
    else
    {
        StringCopy(gStringVar1, sColor_Red);
        StringExpandPlaceholders(gStringVar4, sUtilitiesText_AutoRun);
        StringCopy(&sUtilitiesMenuListData->itemNames[3][0], gStringVar4);
    }
    sUtilitiesMenuListData->listItems[3].name = &sUtilitiesMenuListData->itemNames[3][0];
    
    // Set list menu data
    gMultiuseListMenuTemplate.items = sUtilitiesMenuListData->listItems;
    gMultiuseListMenuTemplate.totalItems = totalItems;
    gMultiuseListMenuTemplate.maxShowed = UTILITIES_WINDOW_HEIGHT;
    gMultiuseListMenuTemplate.windowId = gTasks[taskId].tWindowId;
    gMultiuseListMenuTemplate.header_X = 0;
    gMultiuseListMenuTemplate.item_X = 8;
    gMultiuseListMenuTemplate.cursor_X = 0;
    gMultiuseListMenuTemplate.upText_Y = 1;
    gMultiuseListMenuTemplate.cursorPal = 2;
    gMultiuseListMenuTemplate.fillValue = 1;
    gMultiuseListMenuTemplate.cursorShadowPal = 3;
    gMultiuseListMenuTemplate.lettersSpacing = 1;
    gMultiuseListMenuTemplate.itemVerticalPadding = 0;
    gMultiuseListMenuTemplate.scrollMultiple = LIST_MULTIPLE_SCROLL_DPAD;
    gMultiuseListMenuTemplate.fontId = 1;
    gMultiuseListMenuTemplate.cursorKind = 0;
}

// Actions
static void UtilitiesAction_InfiniteRepel(u8 taskId)
{
    Utilities_DestroyMenu(taskId);
    ScriptContext_SetupScript(EventScript_UseInfiniteRepel);
    DestroyTask(taskId);
    SetMainCallback2(CB2_Overworld);
}

static void UtilitiesAction_PokemonBoxLink(u8 taskId)
{
    Utilities_DestroyMenu(taskId);
    ScriptContext_SetupScript(EventScript_AccessPokemonBoxLink);
    DestroyTask(taskId);
    SetMainCallback2(CB2_Overworld);
}

static void UtilitiesAction_Pokevial(u8 taskId)
{
    Utilities_DestroyMenu(taskId);
    ScriptContext_SetupScript(EventScript_Pokevial);
    DestroyTask(taskId);
    SetMainCallback2(CB2_Overworld);
}

static void UtilitiesAction_WarpPanel(u8 taskId)
{
    ScriptContext_SetupScript(EventScript_UseWarpPanel);
    if (!(gSpecialVar_Result == TRUE))
        SetMainCallback2(CB2_OpenWarpMap);
}

static void UtilitiesAction_EscapeRope(u8 taskId)
{
    if (CanUseDigOrEscapeRopeOnCurMap() == TRUE)
    {
        ResetInitialPlayerAvatarState();
        StartEscapeRopeFieldEffect();
        DestroyListMenuTask(gTasks[taskId].tMenuTaskId, NULL, NULL);
        ClearStdWindowAndFrame(gTasks[taskId].tWindowId, TRUE);
        RemoveWindow(gTasks[taskId].tWindowId);
        DestroyTask(taskId);
        Overworld_ResetStateAfterDigEscRope();
        CopyItemName(gSpecialVar_ItemId, gStringVar2);
        StringExpandPlaceholders(gStringVar4, gText_PlayerUsedVar2);
        gTasks[taskId].data[0] = 0;
    }
    else
    {
        DisplayDadsAdviceCannotUseItemMessage(taskId, TRUE);
        DestroyListMenuTask(gTasks[taskId].tMenuTaskId, NULL, NULL);
        ClearStdWindowAndFrame(gTasks[taskId].tWindowId, TRUE);
        RemoveWindow(gTasks[taskId].tWindowId);
    }
}

static void UtilitiesAction_AutoRun(u8 taskId)
{
    Utilities_DestroyMenu(taskId);
    if ((FlagGet(FLAG_SYS_B_DASH)))
        ScriptContext_SetupScript(EventScript_ToggleAutoRun);
    DestroyTask(taskId);
    SetMainCallback2(CB2_Overworld);
}

static void UtilitiesAction_Flash(u8 taskId)
{
    Utilities_DestroyMenu(taskId);
    if (!(gMapHeader.cave == TRUE))
        ScriptContext_SetupScript(EventScript_CantUseFlashHere);
    else if (FlagGet(FLAG_SYS_USE_FLASH))
        ScriptContext_SetupScript(EventScript_AlreadyUsedFlash);
    else
    {
        ScriptContext_SetupScript(EventScript_UseFlash);
        PlaySE(SE_M_REFLECT);
        AnimateFlash(1);
        SetFlashLevel(0);
    }
    DestroyTask(taskId);
    SetMainCallback2(CB2_Overworld);
}

static void UtilitiesAction_HatchEgg(u8 taskId)
{
    Utilities_DestroyMenu(taskId);
    ScriptContext_SetupScript(EventScript_HatchEgg);
    DestroyTask(taskId);
    SetMainCallback2(CB2_Overworld);
}

static void UtilitiesAction_ChangeTime(u8 taskId)
{
    Utilities_DestroyMenu(taskId);
    ScriptContext_SetupScript(PlayersHouse_2F_EventScript_SetWallClock);
    DestroyTask(taskId);
    SetMainCallback2(CB2_Overworld);
}