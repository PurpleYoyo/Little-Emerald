EventScript_PC::
	lockall
	setvar VAR_0x8004, PC_LOCATION_OTHER
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox Text_BootUpPC, MSGBOX_DEFAULT
	goto EventScript_PCMainMenu
	end

EventScript_PCMainMenu::
	message gText_WhichPCShouldBeAccessed
	waitmessage
	special ScriptMenu_CreatePCMultichoice
	waitstate
	goto EventScript_AccessPC
	end

EventScript_AccessPC::
	switch VAR_RESULT
	case 0, EventScript_AccessPokemonStorage
	case 1, EventScript_AccessPlayersPC
	case 2, EventScript_AccessHallOfFame
	case 3, EventScript_TurnOffPC
	case MULTI_B_PRESSED, EventScript_TurnOffPC
	end

EventScript_AccessPlayersPC::
	playse SE_PC_LOGIN
	msgbox gText_AccessedPlayersPC, MSGBOX_DEFAULT
	special PlayerPC
	waitstate
	goto EventScript_PCMainMenu
	end

EventScript_AccessPokemonStorage::
	playse SE_PC_LOGIN
	call_if_unset FLAG_SYS_PC_LANETTE, EventScript_AccessSomeonesPC
	call_if_set FLAG_SYS_PC_LANETTE, EventScript_AccessLanettesPC
	msgbox gText_StorageSystemOpened, MSGBOX_DEFAULT
	special ShowPokemonStorageSystemPC
	waitstate
	goto EventScript_PCMainMenu
	end

EventScript_AccessSomeonesPC::
	msgbox gText_AccessedSomeonesPC, MSGBOX_DEFAULT
	return

EventScript_AccessLanettesPC::
	msgbox gText_AccessedLanettesPC, MSGBOX_DEFAULT
	return

EventScript_TurnOffPC::
	setvar VAR_0x8004, PC_LOCATION_OTHER
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

EventScript_AccessHallOfFame::
	goto_if_unset FLAG_SYS_GAME_CLEAR, EventScript_TurnOffPC
	playse SE_PC_LOGIN
	special AccessHallOfFamePC
	waitstate
	goto EventScript_AccessPC
	end

EventScript_UseWarpPanel::
	special IsPlayerInPokemonLeague
	goto_if_eq VAR_RESULT, TRUE, EventScript_CantUseWarpPanel
	return

EventScript_CantUseWarpPanel::
	msgbox gText_CantUseWarpPanel, MSGBOX_DEFAULT
	closemessage
	return

EventScript_AccessPokemonBoxLink::
	special IsPlayerInPokemonLeague
	goto_if_eq VAR_RESULT, FALSE, EventScript_PokemonBoxLink
	goto_if_eq VAR_RESULT, TRUE, EventScript_CantUseBoxLink
	return

EventScript_CantUseBoxLink::
	msgbox gText_CantUseBoxLink, MSGBOX_DEFAULT
	closemessage
	return

EventScript_PokemonBoxLink::
	playse SE_PC_LOGIN
	msgbox gText_StorageSystemOpened, MSGBOX_DEFAULT
	special ShowPokemonStorageSystemPC
	waitstate
	goto EventScript_TurnOffPC
	end

EventScript_UseInfiniteRepel::
	special GetInfiniteRepelFlag
	goto_if_eq VAR_RESULT, FALSE, EventScript_InfiniteRepelOn
    goto_if_eq VAR_RESULT, TRUE, EventScript_InfiniteRepelOff
	return

EventScript_InfiniteRepelOn::
    playse SE_REPEL
	msgbox gText_InfiniteRepelOn, MSGBOX_DEFAULT
	setflag FLAG_UNUSED_0x04F
	closemessage
	return

EventScript_InfiniteRepelOff::
    playse SE_POKENAV_OFF
	msgbox gText_InfiniteRepelOff, MSGBOX_DEFAULT
	clearflag FLAG_UNUSED_0x04F
	closemessage
	return

EventScript_SetIvs::
	special ChoosePartyMon
	waitstate
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, EventScript_CantModifyEgg
	msgbox gText_WhichStat, MSGBOX_DEFAULT
	multichoicegrid 10, 4, MULTI_STAT_NAMES, 2, 0
	call_if_eq VAR_RESULT, 0, SetStatHP
	call_if_eq VAR_RESULT, 1, SetStatAtk
	call_if_eq VAR_RESULT, 2, SetStatDef
	call_if_eq VAR_RESULT, 3, SetStatSpA
	call_if_eq VAR_RESULT, 4, SetStatSpD
	call_if_eq VAR_RESULT, 5, SetStatSpe
	call Common_ShowSelectIvsScreen
	waitstate
	sethypertrainstat STAT
	specialvar 0x8007, GetSelectedMonNicknameAndSpecies
	playmoncry 0x8007, 0
	waitmoncry
	msgbox gText_SetIvTo, MSGBOX_DEFAULT
	closemessage
	return

EventScript_SetEvs::
	special ChoosePartyMon
	waitstate
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, EventScript_CantModifyEgg
	msgbox gText_WhichStat, MSGBOX_DEFAULT
	multichoicegrid 10, 4, MULTI_STAT_NAMES, 2, 0
	call_if_eq VAR_RESULT, 0, SetStatHP
	call_if_eq VAR_RESULT, 1, SetStatAtk
	call_if_eq VAR_RESULT, 2, SetStatDef
	call_if_eq VAR_RESULT, 3, SetStatSpA
	call_if_eq VAR_RESULT, 4, SetStatSpD
	call_if_eq VAR_RESULT, 5, SetStatSpe
	call Common_ShowSelectEvsScreen
	waitstate
	sethypertrainstat STAT
	specialvar 0x8007, GetSelectedMonNicknameAndSpecies
	playmoncry 0x8007, 0
	waitmoncry
	msgbox gText_SetEvTo, MSGBOX_DEFAULT
	closemessage
	return

SetStatHP::
	setvar STAT, 0
	return
SetStatAtk::
	setvar STAT, 1
	return
SetStatDef::
	setvar STAT, 2
	return
SetStatSpA::
	setvar STAT, 3
	return
SetStatSpD::
	setvar STAT, 4
	return
SetStatSpe::
	setvar STAT, 5
	return

EventScript_CantModifyEgg::
	msgbox gText_CantModifyEgg, MSGBOX_DEFAULT
	closemessage
	return

EventScript_ToggleAutoRun::
	special GetAutoRunFlag
	goto_if_eq VAR_RESULT, FALSE, EventScript_AutoRunOn
    goto_if_eq VAR_RESULT, TRUE, EventScript_AutoRunOff
	return

EventScript_AutoRunOn::
    playse SE_POKENAV_ON
	msgbox gText_AutoRunOn, MSGBOX_DEFAULT
	setflag FLAG_RUNNING_SHOES_TOGGLE
	closemessage
	return

EventScript_AutoRunOff::
    playse SE_POKENAV_OFF
	msgbox gText_AutoRunOff, MSGBOX_DEFAULT
	clearflag FLAG_RUNNING_SHOES_TOGGLE
	closemessage
	return

EventScript_HatchEgg::
	lockall
	getpartysize
	goto_if_eq VAR_RESULT, 0, EventScript_NoPokemon
	special ChoosePartyMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, EventScript_HatchEgg_End
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_ne VAR_RESULT, SPECIES_EGG, EventScript_HatchEgg_CantForceHatch
	special EggHatch
	waitstate
EventScript_HatchEgg_End::
	releaseall
	end

EventScript_NoPokemon::
	msgbox EventScript_Text_EmptyParty, MSGBOX_DEFAULT
	releaseall
	end

EventScript_HatchEgg_CantForceHatch::
	msgbox EventScript_HatchEgg_Text_NotAnEgg, MSGBOX_DEFAULT
	releaseall
	end

EventScript_Text_EmptyParty::
	.string "You have no Pokémon nor Eggs.$"

EventScript_HatchEgg_Text_NotAnEgg::
	.string "That's not a Pokémon Egg.$"

EventScript_Pokevial::
	playse SE_USE_ITEM
	special HealPlayerParty
	msgbox gText_Pokevial, MSGBOX_DEFAULT
	closemessage
	return
