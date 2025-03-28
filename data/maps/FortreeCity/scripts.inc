# 1 "data/maps/FortreeCity/scripts.pory"

# 2 "data/maps/FortreeCity/scripts.pory"
FortreeCity_MapScripts::
# 3 "data/maps/FortreeCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_OnTransition
# 4 "data/maps/FortreeCity/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_OnResume
# 5 "data/maps/FortreeCity/scripts.pory"
	.byte 0
# 6 "data/maps/FortreeCity/scripts.pory"

# 7 "data/maps/FortreeCity/scripts.pory"
FortreeCity_OnTransition:
# 8 "data/maps/FortreeCity/scripts.pory"
	setflag FLAG_VISITED_FORTREE_CITY
# 9 "data/maps/FortreeCity/scripts.pory"
	end
# 10 "data/maps/FortreeCity/scripts.pory"

# 11 "data/maps/FortreeCity/scripts.pory"
FortreeCity_OnResume:
# 12 "data/maps/FortreeCity/scripts.pory"
	setstepcallback STEP_CB_FORTREE_BRIDGE
# 13 "data/maps/FortreeCity/scripts.pory"
	end
# 14 "data/maps/FortreeCity/scripts.pory"

# 15 "data/maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_Man::
# 16 "data/maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_SawGiganticPokemonInSky, MSGBOX_NPC
# 17 "data/maps/FortreeCity/scripts.pory"
	end
# 18 "data/maps/FortreeCity/scripts.pory"

# 19 "data/maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_Woman::
# 20 "data/maps/FortreeCity/scripts.pory"
	lock
# 21 "data/maps/FortreeCity/scripts.pory"
	faceplayer
# 22 "data/maps/FortreeCity/scripts.pory"
	goto_if_set FLAG_KECLEON_FLED_FORTREE, FortreeCity_EventScript_WomanGymAccessible
# 23 "data/maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_SomethingBlockingGym, MSGBOX_DEFAULT
# 24 "data/maps/FortreeCity/scripts.pory"
	release
# 25 "data/maps/FortreeCity/scripts.pory"
	end
# 26 "data/maps/FortreeCity/scripts.pory"

# 27 "data/maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_WomanGymAccessible::
# 28 "data/maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_ThisTimeIllBeatWinona, MSGBOX_DEFAULT
# 29 "data/maps/FortreeCity/scripts.pory"
	release
# 30 "data/maps/FortreeCity/scripts.pory"
	end
# 31 "data/maps/FortreeCity/scripts.pory"

# 32 "data/maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_Girl::
# 33 "data/maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_TreesGrowByDrinkingRainwater, MSGBOX_NPC
# 34 "data/maps/FortreeCity/scripts.pory"
	end
# 35 "data/maps/FortreeCity/scripts.pory"

# 36 "data/maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_OldMan::
# 37 "data/maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_EveryoneHealthyAndLively, MSGBOX_NPC
# 38 "data/maps/FortreeCity/scripts.pory"
	end
# 39 "data/maps/FortreeCity/scripts.pory"

# 40 "data/maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_Boy::
# 41 "data/maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_BugPokemonComeThroughWindow, MSGBOX_NPC
# 42 "data/maps/FortreeCity/scripts.pory"
	end
# 43 "data/maps/FortreeCity/scripts.pory"

# 44 "data/maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_GameboyKid::
# 45 "data/maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_PokemonThatEvolveWhenTraded, MSGBOX_NPC
# 46 "data/maps/FortreeCity/scripts.pory"
	end
# 47 "data/maps/FortreeCity/scripts.pory"

# 48 "data/maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_CitySign::
# 49 "data/maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_CitySign, MSGBOX_SIGN
# 50 "data/maps/FortreeCity/scripts.pory"
	end
# 51 "data/maps/FortreeCity/scripts.pory"

# 52 "data/maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_GymSign::
# 53 "data/maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_GymSign, MSGBOX_SIGN
# 54 "data/maps/FortreeCity/scripts.pory"
	end
# 55 "data/maps/FortreeCity/scripts.pory"

# 56 "data/maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_Kecleon::
# 57 "data/maps/FortreeCity/scripts.pory"
	lock
# 58 "data/maps/FortreeCity/scripts.pory"
	faceplayer
# 59 "data/maps/FortreeCity/scripts.pory"
	setvar VAR_0x8009, 8
# 60 "data/maps/FortreeCity/scripts.pory"
	checkitem ITEM_DEVON_SCOPE
# 61 "data/maps/FortreeCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, EventScript_AskUseDevonScope2
# 62 "data/maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_SomethingUnseeable, MSGBOX_DEFAULT
# 63 "data/maps/FortreeCity/scripts.pory"
	release
# 64 "data/maps/FortreeCity/scripts.pory"
	end
# 65 "data/maps/FortreeCity/scripts.pory"

# 66 "data/maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_AskUseDevonScope::
# 67 "data/maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_UnseeableUseDevonScope, MSGBOX_YESNO
# 68 "data/maps/FortreeCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, FortreeCity_EventScript_UseDevonScope
# 69 "data/maps/FortreeCity/scripts.pory"
	release
# 70 "data/maps/FortreeCity/scripts.pory"
	end
# 71 "data/maps/FortreeCity/scripts.pory"

# 72 "data/maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_UseDevonScope::
# 73 "data/maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_UsedDevonScopePokemonFled, MSGBOX_DEFAULT
# 74 "data/maps/FortreeCity/scripts.pory"
	closemessage
# 75 "data/maps/FortreeCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Movement_KecleonAppears
# 76 "data/maps/FortreeCity/scripts.pory"
	waitmovement 0
# 77 "data/maps/FortreeCity/scripts.pory"
	waitse
# 78 "data/maps/FortreeCity/scripts.pory"
	playmoncry SPECIES_ZORUA, CRY_MODE_ENCOUNTER
# 79 "data/maps/FortreeCity/scripts.pory"
	delay 40
# 80 "data/maps/FortreeCity/scripts.pory"
	waitmoncry
# 81 "data/maps/FortreeCity/scripts.pory"
	setwildbattle SPECIES_ZORUA, 30
# 82 "data/maps/FortreeCity/scripts.pory"
	setvar VAR_0x8009, 0
# 83 "data/maps/FortreeCity/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 84 "data/maps/FortreeCity/scripts.pory"
	dowildbattle
# 85 "data/maps/FortreeCity/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 86 "data/maps/FortreeCity/scripts.pory"
	applymovement VAR_LAST_TALKED, FortreeCity_Movement_KecleonFlee
# 87 "data/maps/FortreeCity/scripts.pory"
	waitmovement 0
# 88 "data/maps/FortreeCity/scripts.pory"
	removeobject VAR_LAST_TALKED
# 89 "data/maps/FortreeCity/scripts.pory"
	setflag FLAG_KECLEON_FLED_FORTREE
# 90 "data/maps/FortreeCity/scripts.pory"
	release
# 91 "data/maps/FortreeCity/scripts.pory"
	end
# 92 "data/maps/FortreeCity/scripts.pory"

# 93 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Movement_KecleonFlee:
# 94 "data/maps/FortreeCity/scripts.pory"
	walk_right
# 95 "data/maps/FortreeCity/scripts.pory"
	step_end
# 96 "data/maps/FortreeCity/scripts.pory"

# 97 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Text_SawGiganticPokemonInSky:
# 98 "data/maps/FortreeCity/scripts.pory"
	.string "No one believes me, but I saw this\n"
# 99 "data/maps/FortreeCity/scripts.pory"
	.string "gigantic POKéMON in the sky.\p"
# 100 "data/maps/FortreeCity/scripts.pory"
	.string "It seemed to squirm as it flew toward\n"
# 101 "data/maps/FortreeCity/scripts.pory"
	.string "ROUTE 131.\p"
# 102 "data/maps/FortreeCity/scripts.pory"
	.string "By the way… Sniff…\n"
# 103 "data/maps/FortreeCity/scripts.pory"
	.string "Um… You, uh…smell singed.\p"
# 104 "data/maps/FortreeCity/scripts.pory"
	.string "Were you at a volcano or something?$"
# 105 "data/maps/FortreeCity/scripts.pory"

# 106 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Text_SomethingBlockingGym:
# 107 "data/maps/FortreeCity/scripts.pory"
	.string "I want to go to the POKéMON GYM,\n"
# 108 "data/maps/FortreeCity/scripts.pory"
	.string "but something's blocking the way.\p"
# 109 "data/maps/FortreeCity/scripts.pory"
	.string "After all the bother I went through\n"
# 110 "data/maps/FortreeCity/scripts.pory"
	.string "training on ROUTE 120…$"
# 111 "data/maps/FortreeCity/scripts.pory"

# 112 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Text_ThisTimeIllBeatWinona:
# 113 "data/maps/FortreeCity/scripts.pory"
	.string "I've got my pride-and-joy POKéMON\n"
# 114 "data/maps/FortreeCity/scripts.pory"
	.string "with me. This time, I'll beat WINONA.$"
# 115 "data/maps/FortreeCity/scripts.pory"

# 116 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Text_TreesGrowByDrinkingRainwater:
# 117 "data/maps/FortreeCity/scripts.pory"
	.string "The ground absorbs rainwater, and\n"
# 118 "data/maps/FortreeCity/scripts.pory"
	.string "trees grow by drinking that water…\p"
# 119 "data/maps/FortreeCity/scripts.pory"
	.string "Our FORTREE CITY exists because\n"
# 120 "data/maps/FortreeCity/scripts.pory"
	.string "there's both water and soil.$"
# 121 "data/maps/FortreeCity/scripts.pory"

# 122 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Text_EveryoneHealthyAndLively:
# 123 "data/maps/FortreeCity/scripts.pory"
	.string "The CITY consists of homes built on\n"
# 124 "data/maps/FortreeCity/scripts.pory"
	.string "trees.\p"
# 125 "data/maps/FortreeCity/scripts.pory"
	.string "Perhaps because of that lifestyle,\n"
# 126 "data/maps/FortreeCity/scripts.pory"
	.string "everyone is healthy and lively.\p"
# 127 "data/maps/FortreeCity/scripts.pory"
	.string "Why, even myself--I feel as if I've\n"
# 128 "data/maps/FortreeCity/scripts.pory"
	.string "grown thirty years younger.$"
# 129 "data/maps/FortreeCity/scripts.pory"

# 130 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Text_BugPokemonComeThroughWindow:
# 131 "data/maps/FortreeCity/scripts.pory"
	.string "Living on top of trees is okay.\p"
# 132 "data/maps/FortreeCity/scripts.pory"
	.string "But sometimes BUG POKéMON come in\n"
# 133 "data/maps/FortreeCity/scripts.pory"
	.string "through windows.\l"
# 134 "data/maps/FortreeCity/scripts.pory"
	.string "It can be really startling.$"
# 135 "data/maps/FortreeCity/scripts.pory"

# 136 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Text_PokemonThatEvolveWhenTraded:
# 137 "data/maps/FortreeCity/scripts.pory"
	.string "There are POKéMON that evolve when\n"
# 138 "data/maps/FortreeCity/scripts.pory"
	.string "you trade them! That's what I heard.$"
# 139 "data/maps/FortreeCity/scripts.pory"

# 140 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Text_SomethingUnseeable:
# 141 "data/maps/FortreeCity/scripts.pory"
	.string "Something unseeable is in the way.$"
# 142 "data/maps/FortreeCity/scripts.pory"

# 143 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Text_UnseeableUseDevonScope:
# 144 "data/maps/FortreeCity/scripts.pory"
	.string "Something unseeable is in the way.\p"
# 145 "data/maps/FortreeCity/scripts.pory"
	.string "Want to use the DEVON SCOPE?$"
# 146 "data/maps/FortreeCity/scripts.pory"

# 147 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Text_UsedDevonScopePokemonFled:
# 148 "data/maps/FortreeCity/scripts.pory"
	.string "{PLAYER} used the DEVON SCOPE.\p"
# 149 "data/maps/FortreeCity/scripts.pory"
	.string "An invisible POKéMON became completely\n"
# 150 "data/maps/FortreeCity/scripts.pory"
	.string "visible!\p"
# 151 "data/maps/FortreeCity/scripts.pory"
	.string "The startled POKéMON fled!$"
# 152 "data/maps/FortreeCity/scripts.pory"

# 153 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Text_CitySign:
# 154 "data/maps/FortreeCity/scripts.pory"
	.string "FORTREE CITY\n"
# 155 "data/maps/FortreeCity/scripts.pory"
	.string "“The treetop city that frolics with\l"
# 156 "data/maps/FortreeCity/scripts.pory"
	.string "nature.”$"
# 157 "data/maps/FortreeCity/scripts.pory"

# 158 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Text_GymSign:
# 159 "data/maps/FortreeCity/scripts.pory"
	.string "FORTREE CITY POKéMON GYM\n"
# 160 "data/maps/FortreeCity/scripts.pory"
	.string "LEADER: WINONA\p"
# 161 "data/maps/FortreeCity/scripts.pory"
	.string "“The bird user taking flight into\n"
# 162 "data/maps/FortreeCity/scripts.pory"
	.string "the world.”$"
