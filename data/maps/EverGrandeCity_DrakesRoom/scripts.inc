# 1 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 2 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
.set LOCALID_TOTODILE, 2
# 3 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 4 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_MapScripts::
# 5 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_DrakesRoom_OnFrame
# 6 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_DrakesRoom_OnLoad
# 7 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
# 8 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.byte 0
# 9 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 10 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
@ Unused, Drake uses Sidneys identical OnWarp for some reason
# 11 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_OnWarp:
# 12 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth
# 13 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.2byte 0
# 14 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 15 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth::
# 16 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 17 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	end
# 18 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 19 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_OnFrame:
# 20 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	map_script_2 VAR_ELITE_4_STATE, 3, EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor
# 21 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.2byte 0
# 22 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 23 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor::
# 24 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	lockall
# 25 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
# 26 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	setvar VAR_ELITE_4_STATE, 4
# 27 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	releaseall
# 28 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	end
# 29 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 30 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_OnLoad:
# 31 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	call_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom
# 32 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	call_if_eq VAR_ELITE_4_STATE, 4, EverGrandeCity_DrakesRoom_EventScript_CloseDoor
# 33 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	end
# 34 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 35 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom::
# 36 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
# 37 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	return
# 38 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 39 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_EventScript_CloseDoor::
# 40 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	call PokemonLeague_EliteFour_EventScript_CloseDoor
# 41 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	return
# 42 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 43 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_EventScript_Drake::
# 44 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	lock
# 45 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	faceplayer
# 46 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech
# 47 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
# 48 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	msgbox EverGrandeCity_DrakesRoom_Text_IntroSpeech, MSGBOX_DEFAULT
# 49 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	playse SE_M_BATON_PASS
# 50 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	waitse
# 51 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	removeobject LOCALID_TOTODILE
# 52 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	setflag FLAG_HIDE_DRAKES_TOTODILE
# 53 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_DRAKE, EverGrandeCity_DrakesRoom_Text_Defeat
# 54 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	goto EverGrandeCity_DrakesRoom_EventScript_Defeated
# 55 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	end
# 56 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 57 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech::
# 58 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
# 59 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	release
# 60 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	end
# 61 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 62 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_EventScript_Defeated::
# 63 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	setvar VAR_0x8004, FANCOUNTER_DEFEATED_DRAKE
# 64 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	special Script_TryGainNewFanFromCounter
# 65 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	setflag FLAG_DEFEATED_ELITE_4_DRAKE
# 66 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
# 67 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
# 68 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	release
# 69 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	end
# 70 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 71 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_Text_IntroSpeech:
# 72 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "I am the last of the POKéMON LEAGUE\n"
# 73 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "ELITE FOUR, DRAKE the DRAGON master!\p"
# 74 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "In their natural state, POKéMON are\n"
# 75 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "wild living things. They are free.\p"
# 76 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "At times, they hinder us.\n"
# 77 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "At times, they help us.\p"
# 78 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "For us to battle with POKéMON as\n"
# 79 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "partners, do you know what it takes?\p"
# 80 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "Do you know what is needed?\p"
# 81 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "If you don't, then you will never\n"
# 82 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "prevail over me!$"
# 83 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 84 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_Text_Defeat:
# 85 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "Superb, it should be said.$"
# 86 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"

# 87 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
EverGrandeCity_DrakesRoom_Text_PostBattleSpeech:
# 88 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "You deserve every credit for coming\n"
# 89 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "this far as a TRAINER of POKéMON.\p"
# 90 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "You do seem to know what is needed.\p"
# 91 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "Yes, what a TRAINER needs is a\n"
# 92 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "virtuous heart.\p"
# 93 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "POKéMON touch the good hearts of\n"
# 94 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "TRAINERS and learn good from wrong.\p"
# 95 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "They touch the good hearts of\n"
# 96 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "TRAINERS and grow strong.\p"
# 97 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "Go! Go onwards!\n"
# 98 "data/maps/EverGrandeCity_DrakesRoom/scripts.pory"
	.string "The CHAMPION is waiting!$"
