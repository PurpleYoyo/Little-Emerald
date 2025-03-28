# 1 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 2 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
.set LOCALID_IMPIDIMP, 2
# 3 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 4 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_MapScripts::
# 5 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_SidneysRoom_OnLoad
# 6 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
# 7 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_SidneysRoom_OnTransition
# 8 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_SidneysRoom_OnFrame
# 9 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.byte 0
# 10 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 11 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_OnTransition:
# 12 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	setflag FLAG_MET_SCOTT_IN_EVERGRANDE
# 13 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	setflag FLAG_HIDE_EVER_GRANDE_POKEMON_CENTER_1F_SCOTT
# 14 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	end
# 15 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 16 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_OnLoad:
# 17 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	call_if_set FLAG_DEFEATED_ELITE_4_SIDNEY, EverGrandeCity_SidneysRoom_EventScript_ResetAdvanceToNextRoom
# 18 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	call_if_eq VAR_ELITE_4_STATE, 1, EverGrandeCity_SidneysRoom_EventScript_CloseDoor
# 19 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	end
# 20 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 21 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_EventScript_ResetAdvanceToNextRoom::
# 22 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
# 23 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	return
# 24 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 25 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_EventScript_CloseDoor::
# 26 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	call PokemonLeague_EliteFour_EventScript_CloseDoor
# 27 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	return
# 28 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 29 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_OnWarp:
# 30 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_SidneysRoom_EventScript_PlayerTurnNorth
# 31 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.2byte 0
# 32 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 33 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_EventScript_PlayerTurnNorth::
# 34 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 35 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	end
# 36 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 37 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_OnFrame:
# 38 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	map_script_2 VAR_ELITE_4_STATE, 0, EverGrandeCity_SidneysRoom_EventScript_WalkInCloseDoor
# 39 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.2byte 0
# 40 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 41 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_EventScript_WalkInCloseDoor::
# 42 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	lockall
# 43 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
# 44 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	setvar VAR_ELITE_4_STATE, 1
# 45 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	releaseall
# 46 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	end
# 47 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 48 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_EventScript_Sidney::
# 49 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	lock
# 50 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	faceplayer
# 51 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ELITE_4_SIDNEY, EverGrandeCity_SidneysRoom_EventScript_PostBattleSpeech
# 52 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
# 53 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	msgbox EverGrandeCity_SidneysRoom_Text_IntroSpeech, MSGBOX_DEFAULT
# 54 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	playse SE_M_BATON_PASS
# 55 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	waitse
# 56 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	removeobject LOCALID_IMPIDIMP
# 57 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	setflag FLAG_HIDE_SIDNEYS_IMPIDIMP
# 58 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_SIDNEY, EverGrandeCity_SidneysRoom_Text_Defeat
# 59 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	goto EverGrandeCity_SidneysRoom_EventScript_Defeated
# 60 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	end
# 61 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 62 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_EventScript_PostBattleSpeech::
# 63 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	msgbox EverGrandeCity_SidneysRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
# 64 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	release
# 65 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	end
# 66 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 67 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_EventScript_Defeated::
# 68 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	setflag FLAG_DEFEATED_ELITE_4_SIDNEY
# 69 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
# 70 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	msgbox EverGrandeCity_SidneysRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
# 71 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	release
# 72 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	end
# 73 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 74 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_Text_IntroSpeech:
# 75 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "Welcome, challenger!\n"
# 76 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "I'm SIDNEY of the ELITE FOUR.\p"
# 77 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "I like that look you're giving me.\n"
# 78 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "I guess you'll give me a good match.\l"
# 79 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "That's good! Looking real good!\p"
# 80 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "All right! You and me, let's enjoy\n"
# 81 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "a battle that can only be staged\l"
# 82 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "here in the POKéMON LEAGUE!$"
# 83 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 84 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_Text_Defeat:
# 85 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "Well, how do you like that? I lost!\n"
# 86 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "Eh, it was fun, so it doesn't matter.$"
# 87 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 88 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_Text_PostBattleSpeech:
# 89 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "Well, listen to what this loser has\n"
# 90 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "to say.\p"
# 91 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "You've got what it takes to go far.\n"
# 92 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "Now, go on to the next room and enjoy\l"
# 93 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "your next battle!$"
