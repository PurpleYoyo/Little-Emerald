# 1 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 2 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
.set LOCALID_SNORUNT, 2
# 3 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 4 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_MapScripts::
# 5 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_GlaciasRoom_OnFrame
# 6 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_GlaciasRoom_OnLoad
# 7 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_GlaciasRoom_OnWarp
# 8 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.byte 0
# 9 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 10 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_OnWarp:
# 11 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_GlaciasRoom_EventScript_PlayerTurnNorth
# 12 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.2byte 0
# 13 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 14 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_EventScript_PlayerTurnNorth::
# 15 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 16 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	end
# 17 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 18 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_OnFrame:
# 19 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	map_script_2 VAR_ELITE_4_STATE, 2, EverGrandeCity_GlaciasRoom_EventScript_WalkInCloseDoor
# 20 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.2byte 0
# 21 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 22 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_EventScript_WalkInCloseDoor::
# 23 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	lockall
# 24 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
# 25 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	setvar VAR_ELITE_4_STATE, 3
# 26 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	releaseall
# 27 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	end
# 28 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 29 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_OnLoad:
# 30 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	call_if_set FLAG_DEFEATED_ELITE_4_GLACIA, EverGrandeCity_GlaciasRoom_EventScript_ResetAdvanceToNextRoom
# 31 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	call_if_eq VAR_ELITE_4_STATE, 3, EverGrandeCity_GlaciasRoom_EventScript_CloseDoor
# 32 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	end
# 33 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 34 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_EventScript_ResetAdvanceToNextRoom::
# 35 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
# 36 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	return
# 37 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 38 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_EventScript_CloseDoor::
# 39 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	call PokemonLeague_EliteFour_EventScript_CloseDoor
# 40 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	return
# 41 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 42 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_EventScript_Glacia::
# 43 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	lock
# 44 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	faceplayer
# 45 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ELITE_4_GLACIA, EverGrandeCity_GlaciasRoom_EventScript_PostBattleSpeech
# 46 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
# 47 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	msgbox EverGrandeCity_GlaciasRoom_Text_IntroSpeech, MSGBOX_DEFAULT
# 48 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	playse SE_M_BATON_PASS
# 49 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	waitse
# 50 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	removeobject LOCALID_SNORUNT
# 51 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	setflag FLAG_HIDE_GLACIAS_SNORUNT
# 52 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_GLACIA, EverGrandeCity_GlaciasRoom_Text_Defeat
# 53 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	goto EverGrandeCity_GlaciasRoom_EventScript_Defeated
# 54 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	end
# 55 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 56 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_EventScript_PostBattleSpeech::
# 57 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	msgbox EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
# 58 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	release
# 59 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	end
# 60 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 61 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_EventScript_Defeated::
# 62 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	setflag FLAG_DEFEATED_ELITE_4_GLACIA
# 63 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
# 64 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	msgbox EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
# 65 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	release
# 66 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	end
# 67 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 68 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_Text_IntroSpeech:
# 69 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "Welcome, my name is GLACIA\n"
# 70 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "of the ELITE FOUR.\p"
# 71 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "I've traveled from afar to HOENN\n"
# 72 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "so that I may hone my ice skills.\p"
# 73 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "But all I have seen are challenges by\n"
# 74 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "weak TRAINERS and their POKéMON.\p"
# 75 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "What about you?\p"
# 76 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "It would please me to no end if I could\n"
# 77 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "go all out against you!$"
# 78 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 79 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_Text_Defeat:
# 80 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "You and your POKéMON…\n"
# 81 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "How hot your spirits burn!\p"
# 82 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "The all-consuming heat overwhelms.\p"
# 83 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "It's no surprise that my icy skills\n"
# 84 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "failed to harm you.$"
# 85 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 86 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech:
# 87 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "Advance to the next room.\p"
# 88 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "And there, confirm the truly fearsome\n"
# 89 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "side of the POKéMON LEAGUE.$"
