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

enum BaseMenu
{
    BASE_MENU_ITEM_SANDBOX_MENU,
    BASE_MENU_ITEM_UTILITIES_MENU
};

#define BASE_WINDOW_HEIGHT 2

struct BaseMenuListData
{
    struct ListMenuItem listItems[20 + 1];
    u8 itemNames[51][26];
    u8 listId;
};

static EWRAM_DATA struct BaseMenuListData *sBaseMenuListData = NULL;

void Base_ShowMainMenu(void);
static void Base_ShowMenu(void (*HandleInput)(u8), struct ListMenuTemplate LMtemplate);
static void Base_DestroyMenu(u8 taskId);
static void Base_DestroyMenu_Cancel(u8 taskId);
static void BaseTask_HandleMenuInput(u8 taskId);

void Utilities_ShowMainMenu(void);
static void Utilities_ShowMenu(void (*HandleInput)(u8), struct ListMenuTemplate LMtemplate);
static void Utilities_DestroyMenu(u8 taskId);
static void Utilities_DestroyMenu_Cancel(u8 taskId);
static void UtilitiesTask_HandleMenuInput(u8 taskId);

void Sandbox_ShowMainMenu(void);
static void Sandbox_ShowMenu(void (*HandleInput)(u8), struct ListMenuTemplate LMtemplate);
static void Sandbox_DestroyMenu(u8 taskId);
static void Sandbox_DestroyMenu_Cancel(u8 taskId);
static void SandboxTask_HandleMenuInput(u8 taskId);

static void BaseAction_SandboxMenu(u8 taskId);
static void BaseAction_UtilitiesMenu(u8 taskId);

static const u8 sBaseText_SandboxMenu[] = _("Sandbox Menu");
static const u8 sBaseText_UtilitiesMenu[] = _("Utilities Menu");

static const struct ListMenuItem sBaseMenu_Items[] =
{
    [BASE_MENU_ITEM_UTILITIES_MENU]                 = {sBaseText_UtilitiesMenu,              BASE_MENU_ITEM_UTILITIES_MENU},
    [BASE_MENU_ITEM_SANDBOX_MENU]                   = {sBaseText_SandboxMenu,                BASE_MENU_ITEM_SANDBOX_MENU},
};

static void (*const sBaseMenu_Actions[])(u8) =
{
    [BASE_MENU_ITEM_SANDBOX_MENU]                   = BaseAction_SandboxMenu,
    [BASE_MENU_ITEM_UTILITIES_MENU]                 = BaseAction_UtilitiesMenu
};

static const struct WindowTemplate sBaseMenuWindowTemplate =
{.bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 14,
    .height = 2 * BASE_WINDOW_HEIGHT,
    .paletteNum = 15,
    .baseBlock = 1,
};

static const struct ListMenuTemplate sBaseMenu_ListTemplate =
{
    .items = sBaseMenu_Items,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .totalItems = ARRAY_COUNT(sBaseMenu_Items),
};

#define tMenuTaskId   data[0]
#define tWindowId     data[1]

static void Base_DestroyMenu_SubMenu(u8 taskId)
{
    DestroyListMenuTask(gTasks[taskId].tMenuTaskId, NULL, NULL);
    ClearStdWindowAndFrame(gTasks[taskId].tWindowId, TRUE);
    RemoveWindow(gTasks[taskId].tWindowId);
    DestroyTask(taskId);
    Free(sBaseMenuListData);
}

static void Base_DestroyMenu(u8 taskId)
{
    DestroyListMenuTask(gTasks[taskId].tMenuTaskId, NULL, NULL);
    ClearStdWindowAndFrame(gTasks[taskId].tWindowId, TRUE);
    RemoveWindow(gTasks[taskId].tWindowId);
    DestroyTask(taskId);
    ScriptContext_Enable();
    UnfreezeObjectEvents();
    Free(sBaseMenuListData);
}

static void Base_DestroyMenu_Cancel(u8 taskId)
{
    SetMainCallback2(CB2_Overworld);
    Base_DestroyMenu(taskId);
}

void Base_ShowMainMenu(void)
{
    sBaseMenuListData = AllocZeroed(sizeof(*sBaseMenuListData));

    Base_ShowMenu(BaseTask_HandleMenuInput, sBaseMenu_ListTemplate);
}

static void BaseTask_HandleMenuInput(u8 taskId)
{
    void (*func)(u8);
    u32 input = ListMenu_ProcessInput(gTasks[taskId].tMenuTaskId);

    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        if ((func = sBaseMenu_Actions[input]) != NULL)
            func(taskId);
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        Base_DestroyMenu_Cancel(taskId);
    }
}

static void Base_ShowMenu(void (*HandleInput)(u8), struct ListMenuTemplate LMtemplate)
{
    struct ListMenuTemplate menuTemplate;
    u8 windowId;
    u8 menuTaskId;
    u8 inputTaskId;

    // create window
    HideMapNamePopUpWindow();
    LoadMessageBoxAndBorderGfx();
    windowId = AddWindow(&sBaseMenuWindowTemplate);
    DrawStdWindowFrame(windowId, FALSE);

    // create list menu
    menuTemplate = LMtemplate;
    menuTemplate.maxShowed = BASE_WINDOW_HEIGHT;
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

    // draw everything
    CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void BaseAction_SandboxMenu(u8 taskId)
{
    PlaySE(SE_WIN_OPEN);
    Base_DestroyMenu_SubMenu(taskId);
    Sandbox_ShowMainMenu();
}

static void BaseAction_UtilitiesMenu(u8 taskId)
{
    PlaySE(SE_WIN_OPEN);
    Base_DestroyMenu_SubMenu(taskId);
    Utilities_ShowMainMenu();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

enum SandboxMenu
{
    SANDBOX_MENU_ITEM_SET_IVS,
    SANDBOX_MENU_ITEM_SET_EVS,
    SANDBOX_MENU_ITEM_GIVE_MONEY,
    SANDBOX_MENU_ITEM_GIVE_BP,
    SANDBOX_MENU_ITEM_TOGGLE_EV_GAIN,
    SANDBOX_MENU_ITEM_TOGGLE_ALWAYS_CATCH,
    SANDBOX_MENU_ITEM_TOGGLE_NO_TRAINERS,
    SANDBOX_MENU_ITEM_TOGGLE_WALK_THROUGH_WALLS,
};

#define SANDBOX_WINDOW_HEIGHT 8

struct SandboxMenuListData
{
    struct ListMenuItem listItems[20 + 1];
    u8 itemNames[51][26];
    u8 listId;
};

static EWRAM_DATA struct SandboxMenuListData *sSandboxMenuListData = NULL;

static void SandboxAction_SetIvs(u8 taskId);
static void SandboxAction_SetEvs(u8 taskId);
static void SandboxAction_GiveMaxMoney(u8 taskId);
static void SandboxAction_GiveMaxBP(u8 taskId);
static void SandboxAction_ToggleEVGain(u8 taskId);
static void SandboxAction_ToggleAlwaysCatch(u8 taskId);
static void SandboxAction_ToggleNoTrainers(u8 taskId);
static void SandboxAction_ToggleWalkThroughWalls(u8 taskId);

static const u8 sSandboxText_SetIvs[] = _("Set IVs");
static const u8 sSandboxText_SetEvs[] = _("Set EVs");
static const u8 sSandboxText_GiveMoney[] = _("Give Max Money");
static const u8 sSandboxText_GiveBP[] = _("Give Max BP");
static const u8 sSandboxText_EvGain[] = _("{STR_VAR_1}EV Gain");
static const u8 sSandboxText_AlwaysCatch[] = _("{STR_VAR_1}100% Catch Rate");
static const u8 sSandboxText_NoTrainers[] = _("{STR_VAR_1}No Trainer Battles");
static const u8 sSandboxText_WalkThroughWalls[] = _("{STR_VAR_1}Walk Through Walls");

static const struct ListMenuItem sSandboxMenu_Items[] =
{
    [SANDBOX_MENU_ITEM_SET_IVS]                   = {sSandboxText_SetIvs,              SANDBOX_MENU_ITEM_SET_IVS},
    [SANDBOX_MENU_ITEM_SET_EVS]                   = {sSandboxText_SetEvs,              SANDBOX_MENU_ITEM_SET_EVS},
    [SANDBOX_MENU_ITEM_GIVE_MONEY]                = {sSandboxText_GiveMoney,           SANDBOX_MENU_ITEM_GIVE_MONEY},
    [SANDBOX_MENU_ITEM_GIVE_BP]                   = {sSandboxText_GiveBP,              SANDBOX_MENU_ITEM_GIVE_BP},
    [SANDBOX_MENU_ITEM_TOGGLE_EV_GAIN]            = {sSandboxText_EvGain,              SANDBOX_MENU_ITEM_TOGGLE_EV_GAIN},
    [SANDBOX_MENU_ITEM_TOGGLE_ALWAYS_CATCH]       = {sSandboxText_AlwaysCatch,         SANDBOX_MENU_ITEM_TOGGLE_ALWAYS_CATCH}, 
    [SANDBOX_MENU_ITEM_TOGGLE_NO_TRAINERS]        = {sSandboxText_NoTrainers,          SANDBOX_MENU_ITEM_TOGGLE_NO_TRAINERS}, 
    [SANDBOX_MENU_ITEM_TOGGLE_WALK_THROUGH_WALLS] = {sSandboxText_WalkThroughWalls,    SANDBOX_MENU_ITEM_TOGGLE_WALK_THROUGH_WALLS}, 
};

static void (*const sSandboxMenu_Actions[])(u8) =
{
    [SANDBOX_MENU_ITEM_SET_IVS]                   = SandboxAction_SetIvs,
    [SANDBOX_MENU_ITEM_SET_EVS]                   = SandboxAction_SetEvs,
    [SANDBOX_MENU_ITEM_GIVE_MONEY]                = SandboxAction_GiveMaxMoney,
    [SANDBOX_MENU_ITEM_GIVE_BP]                   = SandboxAction_GiveMaxBP,
    [SANDBOX_MENU_ITEM_TOGGLE_EV_GAIN]            = SandboxAction_ToggleEVGain,
    [SANDBOX_MENU_ITEM_TOGGLE_ALWAYS_CATCH]       = SandboxAction_ToggleAlwaysCatch,
    [SANDBOX_MENU_ITEM_TOGGLE_NO_TRAINERS]        = SandboxAction_ToggleNoTrainers,
    [SANDBOX_MENU_ITEM_TOGGLE_WALK_THROUGH_WALLS] = SandboxAction_ToggleWalkThroughWalls,
};

static const struct WindowTemplate sSandboxMenuWindowTemplate =
{.bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 14,
    .height = 2 * SANDBOX_WINDOW_HEIGHT,
    .paletteNum = 15,
    .baseBlock = 1,
};

static const struct ListMenuTemplate sSandboxMenu_ListTemplate =
{
    .items = sSandboxMenu_Items,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .totalItems = ARRAY_COUNT(sSandboxMenu_Items),
};

#define tMenuTaskId   data[0]
#define tWindowId     data[1]

static void Sandbox_DestroyMenu(u8 taskId)
{
    DestroyListMenuTask(gTasks[taskId].tMenuTaskId, NULL, NULL);
    ClearStdWindowAndFrame(gTasks[taskId].tWindowId, TRUE);
    RemoveWindow(gTasks[taskId].tWindowId);
    DestroyTask(taskId);
    ScriptContext_Enable();
    UnfreezeObjectEvents();
    Free(sSandboxMenuListData);
}

static void Sandbox_DestroyMenu_Cancel(u8 taskId)
{
    SetMainCallback2(CB2_Overworld);
    Sandbox_DestroyMenu(taskId);
}

void Sandbox_ShowMainMenu(void)
{
    sSandboxMenuListData = AllocZeroed(sizeof(*sSandboxMenuListData));

    Sandbox_ShowMenu(SandboxTask_HandleMenuInput, sSandboxMenu_ListTemplate);
}

static void SandboxTask_HandleMenuInput(u8 taskId)
{
    void (*func)(u8);
    u32 input = ListMenu_ProcessInput(gTasks[taskId].tMenuTaskId);

    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        if ((func = sSandboxMenu_Actions[input]) != NULL)
            func(taskId);
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        Sandbox_DestroyMenu_Cancel(taskId);
    }
}

static void Sandbox_ShowMenu(void (*HandleInput)(u8), struct ListMenuTemplate LMtemplate)
{
    struct ListMenuTemplate menuTemplate;
    u8 windowId;
    u8 menuTaskId;
    u8 inputTaskId;

    // create window
    HideMapNamePopUpWindow();
    LoadMessageBoxAndBorderGfx();
    windowId = AddWindow(&sSandboxMenuWindowTemplate);
    DrawStdWindowFrame(windowId, FALSE);

    // create list menu
    menuTemplate = LMtemplate;
    menuTemplate.maxShowed = SANDBOX_WINDOW_HEIGHT;
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

    u8 totalItems = 8;
    const u8 sColor_Red[] = _("{COLOR RED}");
    const u8 sColor_Green[] = _("{COLOR GREEN}");
    u8 const *name = NULL;
    u32 i;

    for (i = 0; i < totalItems; i++)
    {
        name = sSandboxMenu_Items[i].name;

        if (i == 4)
        {
            if (VarGet(VAR_EV_GAIN) == 1)
            {
                StringCopy(gStringVar1, sColor_Green);
                StringExpandPlaceholders(gStringVar4, name);
                StringCopy(&sSandboxMenuListData->itemNames[i][0], gStringVar4);
            }
            else
            {
                StringCopy(gStringVar1, sColor_Red);
                StringExpandPlaceholders(gStringVar4, name);
                StringCopy(&sSandboxMenuListData->itemNames[i][0], gStringVar4);
            }
        }
        else if (i == 5)
        {
            if (VarGet(VAR_ALWAYS_CATCH) == 1)
            {
                StringCopy(gStringVar1, sColor_Green);
                StringExpandPlaceholders(gStringVar4, name);
                StringCopy(&sSandboxMenuListData->itemNames[i][0], gStringVar4);
            }
            else
            {
                StringCopy(gStringVar1, sColor_Red);
                StringExpandPlaceholders(gStringVar4, name);
                StringCopy(&sSandboxMenuListData->itemNames[i][0], gStringVar4);
            }
        }
        else if (i == 6)
        {
            if (FlagGet(FLAG_NO_TRAINERS))
            {
                StringCopy(gStringVar1, sColor_Green);
                StringExpandPlaceholders(gStringVar4, name);
                StringCopy(&sSandboxMenuListData->itemNames[i][0], gStringVar4);
            }
            else
            {
                StringCopy(gStringVar1, sColor_Red);
                StringExpandPlaceholders(gStringVar4, name);
                StringCopy(&sSandboxMenuListData->itemNames[i][0], gStringVar4);
            }
        }
        else if (i == 7)
        {
            if (FlagGet(FLAG_WALK_THROUGH_WALLS))
            {
                StringCopy(gStringVar1, sColor_Green);
                StringExpandPlaceholders(gStringVar4, name);
                StringCopy(&sSandboxMenuListData->itemNames[i][0], gStringVar4);
            }
            else
            {
                StringCopy(gStringVar1, sColor_Red);
                StringExpandPlaceholders(gStringVar4, name);
                StringCopy(&sSandboxMenuListData->itemNames[i][0], gStringVar4);
            }
        }
        else
        {
            StringCopy(&sSandboxMenuListData->itemNames[i][0], name);
        }

        sSandboxMenuListData->listItems[i].name = &sSandboxMenuListData->itemNames[i][0];
        sSandboxMenuListData->listItems[i].id = i;
    }
    
    menuTemplate.items = sSandboxMenuListData->listItems;

    menuTaskId = ListMenuInit(&menuTemplate, 0, 0);

    // create input handler task
    inputTaskId = CreateTask(HandleInput, 3);
    gTasks[inputTaskId].tMenuTaskId = menuTaskId;
    gTasks[inputTaskId].tWindowId = windowId;
    // draw everything
    CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void SandboxAction_SetIvs(u8 taskId)
{
    Utilities_DestroyMenu(taskId);
    ScriptContext_SetupScript(EventScript_SetIvs);
    DestroyTask(taskId);
    SetMainCallback2(CB2_Overworld);
}

static void SandboxAction_SetEvs(u8 taskId)
{
    Utilities_DestroyMenu(taskId);
    ScriptContext_SetupScript(EventScript_SetEvs);
    DestroyTask(taskId);
    SetMainCallback2(CB2_Overworld);
}

static void SandboxAction_GiveMaxMoney(u8 taskId)
{
    Utilities_DestroyMenu(taskId);
    ScriptContext_SetupScript(EventScript_GiveMaxMoney);
    DestroyTask(taskId);
    SetMainCallback2(CB2_Overworld);
}

static void SandboxAction_GiveMaxBP(u8 taskId)
{
    Utilities_DestroyMenu(taskId);
    ScriptContext_SetupScript(EventScript_GiveMaxBP);
    DestroyTask(taskId);
    SetMainCallback2(CB2_Overworld);
}

static void SandboxAction_ToggleEVGain(u8 taskId)
{
    Utilities_DestroyMenu(taskId);
    ScriptContext_SetupScript(EventScript_ToggleEvGain);
    DestroyTask(taskId);
    SetMainCallback2(CB2_Overworld);
}

static void SandboxAction_ToggleAlwaysCatch(u8 taskId)
{
    Utilities_DestroyMenu(taskId);
    ScriptContext_SetupScript(EventScript_ToggleAlwaysCatch);
    DestroyTask(taskId);
    SetMainCallback2(CB2_Overworld);
}

static void SandboxAction_ToggleNoTrainers(u8 taskId)
{
    Utilities_DestroyMenu(taskId);
    ScriptContext_SetupScript(EventScript_ToggleNoTrainers);
    DestroyTask(taskId);
    SetMainCallback2(CB2_Overworld);
}

static void SandboxAction_ToggleWalkThroughWalls(u8 taskId)
{
    Utilities_DestroyMenu(taskId);
    ScriptContext_SetupScript(EventScript_ToggleWalkThroughWalls);
    DestroyTask(taskId);
    SetMainCallback2(CB2_Overworld);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

    u8 totalItems = 9;
    const u8 sColor_Red[] = _("{COLOR RED}");
    const u8 sColor_Green[] = _("{COLOR GREEN}");
    u8 const *name = NULL;
    u32 i;

    for (i = 0; i < totalItems; i++)
    {
        name = sUtilitiesMenu_Items[i].name;

        if (i == 2)
        {
            if (FlagGet(FLAG_UNUSED_0x04F))
            {
                StringCopy(gStringVar1, sColor_Green);
                StringExpandPlaceholders(gStringVar4, name);
                StringCopy(&sUtilitiesMenuListData->itemNames[i][0], gStringVar4);
            }
            else
            {
                StringCopy(gStringVar1, sColor_Red);
                StringExpandPlaceholders(gStringVar4, name);
                StringCopy(&sUtilitiesMenuListData->itemNames[i][0], gStringVar4);
            }
        }
        else if (i == 5)
        {
            if (FlagGet(FLAG_RUNNING_SHOES_TOGGLE))
            {
                StringCopy(gStringVar1, sColor_Green);
                StringExpandPlaceholders(gStringVar4, name);
                StringCopy(&sUtilitiesMenuListData->itemNames[i][0], gStringVar4);
            }
            else
            {
                StringCopy(gStringVar1, sColor_Red);
                StringExpandPlaceholders(gStringVar4, name);
                StringCopy(&sUtilitiesMenuListData->itemNames[i][0], gStringVar4);
            }
        }
        else
        {
            StringCopy(&sUtilitiesMenuListData->itemNames[i][0], name);
        }

        sUtilitiesMenuListData->listItems[i].name = &sUtilitiesMenuListData->itemNames[i][0];
        sUtilitiesMenuListData->listItems[i].id = i;
    }
    
    menuTemplate.items = sUtilitiesMenuListData->listItems;

    menuTaskId = ListMenuInit(&menuTemplate, 0, 0);

    // create input handler task
    inputTaskId = CreateTask(HandleInput, 3);
    gTasks[inputTaskId].tMenuTaskId = menuTaskId;
    gTasks[inputTaskId].tWindowId = windowId;
    // draw everything
    CopyWindowToVram(windowId, COPYWIN_FULL);
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