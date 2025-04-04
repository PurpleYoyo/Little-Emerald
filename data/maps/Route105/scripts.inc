# 1 "data/maps/Route105/scripts.pory"

# 2 "data/maps/Route105/scripts.pory"
Route105_MapScripts::
# 3 "data/maps/Route105/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route105_OnLoad
# 4 "data/maps/Route105/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route105_OnTransition
# 5 "data/maps/Route105/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route105_OnFrame
# 6 "data/maps/Route105/scripts.pory"
	.byte 0
# 7 "data/maps/Route105/scripts.pory"

# 8 "data/maps/Route105/scripts.pory"
Route105_OnLoad:
# 9 "data/maps/Route105/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_105_NORTH, AbnormalWeather_EventScript_PlaceTilesRoute105North
# 10 "data/maps/Route105/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_105_SOUTH, AbnormalWeather_EventScript_PlaceTilesRoute105South
# 11 "data/maps/Route105/scripts.pory"
	end
# 12 "data/maps/Route105/scripts.pory"

# 13 "data/maps/Route105/scripts.pory"
Route105_CloseRegiEntrance::
# 14 "data/maps/Route105/scripts.pory"
	setmetatile 9, 19, METATILE_General_RockWall_RockBase, TRUE
# 15 "data/maps/Route105/scripts.pory"
	setmetatile 9, 20, METATILE_General_RockWall_SandBase, TRUE
# 16 "data/maps/Route105/scripts.pory"
	return
# 17 "data/maps/Route105/scripts.pory"

# 18 "data/maps/Route105/scripts.pory"
Route105_OnTransition:
# 19 "data/maps/Route105/scripts.pory"
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
# 20 "data/maps/Route105/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_105_NORTH, AbnormalWeather_StartKyogreWeather
# 21 "data/maps/Route105/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_105_SOUTH, AbnormalWeather_StartKyogreWeather
# 22 "data/maps/Route105/scripts.pory"
	end
# 23 "data/maps/Route105/scripts.pory"

# 24 "data/maps/Route105/scripts.pory"
Route105_OnFrame:
# 25 "data/maps/Route105/scripts.pory"
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
# 26 "data/maps/Route105/scripts.pory"
	.2byte 0
# 27 "data/maps/Route105/scripts.pory"

# 28 "data/maps/Route105/scripts.pory"
Route105_EventScript_Foster::
# 29 "data/maps/Route105/scripts.pory"
	trainerbattle_single TRAINER_FOSTER, Route105_Text_FosterIntro, Route105_Text_FosterDefeated
# 30 "data/maps/Route105/scripts.pory"
	msgbox Route105_Text_FosterPostBattle, MSGBOX_AUTOCLOSE
# 31 "data/maps/Route105/scripts.pory"
	end
# 32 "data/maps/Route105/scripts.pory"

# 33 "data/maps/Route105/scripts.pory"
Route105_EventScript_Luis::
# 34 "data/maps/Route105/scripts.pory"
	trainerbattle_single TRAINER_LUIS, Route105_Text_LuisIntro, Route105_Text_LuisDefeated
# 35 "data/maps/Route105/scripts.pory"
	msgbox Route105_Text_LuisPostBattle, MSGBOX_AUTOCLOSE
# 36 "data/maps/Route105/scripts.pory"
	end
# 37 "data/maps/Route105/scripts.pory"

# 38 "data/maps/Route105/scripts.pory"
Route105_EventScript_Dominik::
# 39 "data/maps/Route105/scripts.pory"
	trainerbattle_single TRAINER_DOMINIK, Route105_Text_DominikIntro, Route105_Text_DominikDefeated
# 40 "data/maps/Route105/scripts.pory"
	msgbox Route105_Text_DominikPostBattle, MSGBOX_AUTOCLOSE
# 41 "data/maps/Route105/scripts.pory"
	end
# 42 "data/maps/Route105/scripts.pory"

# 43 "data/maps/Route105/scripts.pory"
Route105_EventScript_Beverly::
# 44 "data/maps/Route105/scripts.pory"
	trainerbattle_single TRAINER_BEVERLY, Route105_Text_BeverlyIntro, Route105_Text_BeverlyDefeated
# 45 "data/maps/Route105/scripts.pory"
	msgbox Route105_Text_PostBattle, MSGBOX_AUTOCLOSE
# 46 "data/maps/Route105/scripts.pory"
	end
# 47 "data/maps/Route105/scripts.pory"

# 48 "data/maps/Route105/scripts.pory"
Route105_EventScript_Imani::
# 49 "data/maps/Route105/scripts.pory"
	trainerbattle_single TRAINER_IMANI, Route105_Text_ImaniIntro, Route105_Text_ImaniDefeated
# 50 "data/maps/Route105/scripts.pory"
	msgbox Route105_Text_ImaniPostBattle, MSGBOX_AUTOCLOSE
# 51 "data/maps/Route105/scripts.pory"
	end
# 52 "data/maps/Route105/scripts.pory"

# 53 "data/maps/Route105/scripts.pory"
Route105_EventScript_Josue::
# 54 "data/maps/Route105/scripts.pory"
	trainerbattle_single TRAINER_JOSUE, Route105_Text_JosueIntro, Route105_Text_JosueDefeated
# 55 "data/maps/Route105/scripts.pory"
	msgbox Route105_Text_JosuePostBattle, MSGBOX_AUTOCLOSE
# 56 "data/maps/Route105/scripts.pory"
	end
# 57 "data/maps/Route105/scripts.pory"

# 58 "data/maps/Route105/scripts.pory"
Route105_EventScript_Andres::
# 59 "data/maps/Route105/scripts.pory"
	trainerbattle_single TRAINER_ANDRES_1, Route105_Text_AndresIntro, Route105_Text_AndresDefeated, Route105_EventScript_AndresRegisterMatchCallAfterBattle
# 60 "data/maps/Route105/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 61 "data/maps/Route105/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route105_EventScript_AndresRematch
# 62 "data/maps/Route105/scripts.pory"
	msgbox Route105_Text_AndresPostBattle, MSGBOX_DEFAULT
# 63 "data/maps/Route105/scripts.pory"
	release
# 64 "data/maps/Route105/scripts.pory"
	end
# 65 "data/maps/Route105/scripts.pory"

# 66 "data/maps/Route105/scripts.pory"
Route105_EventScript_AndresRegisterMatchCallAfterBattle::
# 67 "data/maps/Route105/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 68 "data/maps/Route105/scripts.pory"
	waitmovement 0
# 69 "data/maps/Route105/scripts.pory"
	msgbox Route105_Text_AndresRegister, MSGBOX_DEFAULT
# 70 "data/maps/Route105/scripts.pory"
	register_matchcall TRAINER_ANDRES_1
# 71 "data/maps/Route105/scripts.pory"
	release
# 72 "data/maps/Route105/scripts.pory"
	end
# 73 "data/maps/Route105/scripts.pory"

# 74 "data/maps/Route105/scripts.pory"
Route105_EventScript_AndresRematch::
# 75 "data/maps/Route105/scripts.pory"
	trainerbattle_rematch TRAINER_ANDRES_1, Route105_Text_AndresRematchIntro, Route105_Text_AndresRematchDefeated
# 76 "data/maps/Route105/scripts.pory"
	msgbox Route105_Text_AndresRematchPostBattle, MSGBOX_AUTOCLOSE
# 77 "data/maps/Route105/scripts.pory"
	end
# 78 "data/maps/Route105/scripts.pory"

# 79 "data/maps/Route105/scripts.pory"
Route104_Text_DadPokenavCall:
# 80 "data/maps/Route105/scripts.pory"
	.string "… … … … … …\n"
# 81 "data/maps/Route105/scripts.pory"
	.string "… … … … … Beep!\p"
# 82 "data/maps/Route105/scripts.pory"
	.string "DAD: Oh, {PLAYER}?\p"
# 83 "data/maps/Route105/scripts.pory"
	.string "… … … … … …\n"
# 84 "data/maps/Route105/scripts.pory"
	.string "Where are you now?\l"
# 85 "data/maps/Route105/scripts.pory"
	.string "It sounds windy wherever you are.\p"
# 86 "data/maps/Route105/scripts.pory"
	.string "I just heard from DEVON's MR. STONE\n"
# 87 "data/maps/Route105/scripts.pory"
	.string "about your POKéNAV, so I decided\l"
# 88 "data/maps/Route105/scripts.pory"
	.string "to give you a call.\p"
# 89 "data/maps/Route105/scripts.pory"
	.string "It sounds like you're doing fine,\n"
# 90 "data/maps/Route105/scripts.pory"
	.string "so that's fine with me.\p"
# 91 "data/maps/Route105/scripts.pory"
	.string "You take care now.\p"
# 92 "data/maps/Route105/scripts.pory"
	.string "… … … … … …\n"
# 93 "data/maps/Route105/scripts.pory"
	.string "… … … … … Click!$"
# 94 "data/maps/Route105/scripts.pory"

# 95 "data/maps/Route105/scripts.pory"
Route104_Text_RegisteredDadInPokenav:
# 96 "data/maps/Route105/scripts.pory"
	.string "Registered DAD NORMAN\n"
# 97 "data/maps/Route105/scripts.pory"
	.string "in the POKéNAV.$"
