# 1 "data/maps/EverGrandeCity/scripts.pory"

# 2 "data/maps/EverGrandeCity/scripts.pory"
.set LOCALID_HONEDGE, 2
# 3 "data/maps/EverGrandeCity/scripts.pory"

# 4 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_MapScripts::
# 5 "data/maps/EverGrandeCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_OnTransition
# 6 "data/maps/EverGrandeCity/scripts.pory"
	.byte 0
# 7 "data/maps/EverGrandeCity/scripts.pory"

# 8 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_OnTransition:
# 9 "data/maps/EverGrandeCity/scripts.pory"
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
# 10 "data/maps/EverGrandeCity/scripts.pory"
	end
# 11 "data/maps/EverGrandeCity/scripts.pory"

# 12 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_VictoryRoadSign::
# 13 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_EnteringVictoryRoad, MSGBOX_SIGN
# 14 "data/maps/EverGrandeCity/scripts.pory"
	end
# 15 "data/maps/EverGrandeCity/scripts.pory"

# 16 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_CitySign::
# 17 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_CitySign, MSGBOX_SIGN
# 18 "data/maps/EverGrandeCity/scripts.pory"
	end
# 19 "data/maps/EverGrandeCity/scripts.pory"

# 20 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_PokemonLeagueSign::
# 21 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_EnteringPokemonLeague, MSGBOX_SIGN
# 22 "data/maps/EverGrandeCity/scripts.pory"
	end
# 23 "data/maps/EverGrandeCity/scripts.pory"

# 24 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_SetVisitedEverGrande::
# 25 "data/maps/EverGrandeCity/scripts.pory"
	setflag FLAG_VISITED_EVER_GRANDE_CITY
# 26 "data/maps/EverGrandeCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 27 "data/maps/EverGrandeCity/scripts.pory"
	end
# 28 "data/maps/EverGrandeCity/scripts.pory"

# 29 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_Text_EnteringVictoryRoad:
# 30 "data/maps/EverGrandeCity/scripts.pory"
	.string "ENTERING VICTORY ROAD$"
# 31 "data/maps/EverGrandeCity/scripts.pory"

# 32 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_Text_EnteringPokemonLeague:
# 33 "data/maps/EverGrandeCity/scripts.pory"
	.string "ENTERING POKéMON LEAGUE\n"
# 34 "data/maps/EverGrandeCity/scripts.pory"
	.string "CENTER GATE$"
# 35 "data/maps/EverGrandeCity/scripts.pory"

# 36 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_Text_CitySign:
# 37 "data/maps/EverGrandeCity/scripts.pory"
	.string "EVER GRANDE CITY\p"
# 38 "data/maps/EverGrandeCity/scripts.pory"
	.string "“The paradise of flowers, the sea,\n"
# 39 "data/maps/EverGrandeCity/scripts.pory"
	.string "and POKéMON.”$"
