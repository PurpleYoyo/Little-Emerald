# 1 "data/maps/SootopolisCity_Mart/scripts.pory"

# 2 "data/maps/SootopolisCity_Mart/scripts.pory"
SootopolisCity_Mart_MapScripts::
# 3 "data/maps/SootopolisCity_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/SootopolisCity_Mart/scripts.pory"

# 5 "data/maps/SootopolisCity_Mart/scripts.pory"
SootopolisCity_Mart_EventScript_Clerk::
# 6 "data/maps/SootopolisCity_Mart/scripts.pory"
	lock
# 7 "data/maps/SootopolisCity_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/SootopolisCity_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 9 "data/maps/SootopolisCity_Mart/scripts.pory"
	waitmessage
# 10 "data/maps/SootopolisCity_Mart/scripts.pory"
	pokemart SootopolisCity_Mart_Pokemart
# 11 "data/maps/SootopolisCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 12 "data/maps/SootopolisCity_Mart/scripts.pory"
	release
# 13 "data/maps/SootopolisCity_Mart/scripts.pory"
	end
# 14 "data/maps/SootopolisCity_Mart/scripts.pory"

# 15 "data/maps/SootopolisCity_Mart/scripts.pory"
	.align 2
# 16 "data/maps/SootopolisCity_Mart/scripts.pory"
SootopolisCity_Mart_Pokemart:
# 17 "data/maps/SootopolisCity_Mart/scripts.pory"
	.2byte ITEM_POKE_BALL
# 18 "data/maps/SootopolisCity_Mart/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 19 "data/maps/SootopolisCity_Mart/scripts.pory"
	.2byte ITEM_ULTRA_BALL
# 20 "data/maps/SootopolisCity_Mart/scripts.pory"
	.2byte ITEM_DIVE_BALL
# 21 "data/maps/SootopolisCity_Mart/scripts.pory"
	.2byte ITEM_DREAM_BALL
# 22 "data/maps/SootopolisCity_Mart/scripts.pory"
	.2byte ITEM_REVIVE
# 23 "data/maps/SootopolisCity_Mart/scripts.pory"
	pokemartlistend
# 24 "data/maps/SootopolisCity_Mart/scripts.pory"

# 25 "data/maps/SootopolisCity_Mart/scripts.pory"
SootopolisCity_Mart_EventScript_FatMan::
# 26 "data/maps/SootopolisCity_Mart/scripts.pory"
	lock
# 27 "data/maps/SootopolisCity_Mart/scripts.pory"
	faceplayer
# 28 "data/maps/SootopolisCity_Mart/scripts.pory"
	goto_if_ge VAR_SKY_PILLAR_STATE, 2, SootopolisCity_Mart_EventScript_FatManNoLegendaries
# 29 "data/maps/SootopolisCity_Mart/scripts.pory"
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_Mart_EventScript_FatManNoLegendaries
# 30 "data/maps/SootopolisCity_Mart/scripts.pory"
	msgbox SootopolisCity_Mart_Text_TooScaryOutside, MSGBOX_DEFAULT
# 31 "data/maps/SootopolisCity_Mart/scripts.pory"
	release
# 32 "data/maps/SootopolisCity_Mart/scripts.pory"
	end
# 33 "data/maps/SootopolisCity_Mart/scripts.pory"

# 34 "data/maps/SootopolisCity_Mart/scripts.pory"
SootopolisCity_Mart_EventScript_FatManNoLegendaries::
# 35 "data/maps/SootopolisCity_Mart/scripts.pory"
	msgbox SootopolisCity_Mart_Text_PPUpIsGreat, MSGBOX_DEFAULT
# 36 "data/maps/SootopolisCity_Mart/scripts.pory"
	release
# 37 "data/maps/SootopolisCity_Mart/scripts.pory"
	end
# 38 "data/maps/SootopolisCity_Mart/scripts.pory"

# 39 "data/maps/SootopolisCity_Mart/scripts.pory"
SootopolisCity_Mart_EventScript_Gentleman::
# 40 "data/maps/SootopolisCity_Mart/scripts.pory"
	lock
# 41 "data/maps/SootopolisCity_Mart/scripts.pory"
	faceplayer
# 42 "data/maps/SootopolisCity_Mart/scripts.pory"
	goto_if_ge VAR_SKY_PILLAR_STATE, 2, SootopolisCity_Mart_EventScript_GentlemanNoLegendaries
# 43 "data/maps/SootopolisCity_Mart/scripts.pory"
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_Mart_EventScript_GentlemanNoLegendaries
# 44 "data/maps/SootopolisCity_Mart/scripts.pory"
	msgbox SootopolisCity_Mart_Text_DidSomethingAwaken, MSGBOX_DEFAULT
# 45 "data/maps/SootopolisCity_Mart/scripts.pory"
	release
# 46 "data/maps/SootopolisCity_Mart/scripts.pory"
	end
# 47 "data/maps/SootopolisCity_Mart/scripts.pory"

# 48 "data/maps/SootopolisCity_Mart/scripts.pory"
SootopolisCity_Mart_EventScript_GentlemanNoLegendaries::
# 49 "data/maps/SootopolisCity_Mart/scripts.pory"
	msgbox SootopolisCity_Mart_Text_FullRestoreItemOfDreams, MSGBOX_DEFAULT
# 50 "data/maps/SootopolisCity_Mart/scripts.pory"
	release
# 51 "data/maps/SootopolisCity_Mart/scripts.pory"
	end
# 52 "data/maps/SootopolisCity_Mart/scripts.pory"

# 53 "data/maps/SootopolisCity_Mart/scripts.pory"
SootopolisCity_Mart_Text_PPUpIsGreat:
# 54 "data/maps/SootopolisCity_Mart/scripts.pory"
	.string "PP UP is great!\p"
# 55 "data/maps/SootopolisCity_Mart/scripts.pory"
	.string "It raises the POWER POINTS, the PP,\n"
# 56 "data/maps/SootopolisCity_Mart/scripts.pory"
	.string "of a POKéMON move.$"
# 57 "data/maps/SootopolisCity_Mart/scripts.pory"

# 58 "data/maps/SootopolisCity_Mart/scripts.pory"
SootopolisCity_Mart_Text_TooScaryOutside:
# 59 "data/maps/SootopolisCity_Mart/scripts.pory"
	.string "What…\n"
# 60 "data/maps/SootopolisCity_Mart/scripts.pory"
	.string "What is happening?\p"
# 61 "data/maps/SootopolisCity_Mart/scripts.pory"
	.string "I really want to know, but it's too\n"
# 62 "data/maps/SootopolisCity_Mart/scripts.pory"
	.string "scary to go outside.$"
# 63 "data/maps/SootopolisCity_Mart/scripts.pory"

# 64 "data/maps/SootopolisCity_Mart/scripts.pory"
SootopolisCity_Mart_Text_FullRestoreItemOfDreams:
# 65 "data/maps/SootopolisCity_Mart/scripts.pory"
	.string "Do you know FULL RESTORE?\p"
# 66 "data/maps/SootopolisCity_Mart/scripts.pory"
	.string "Full restoration of HP!\n"
# 67 "data/maps/SootopolisCity_Mart/scripts.pory"
	.string "Eradication of all status problems!\p"
# 68 "data/maps/SootopolisCity_Mart/scripts.pory"
	.string "It's truly an item of your dreams!$"
# 69 "data/maps/SootopolisCity_Mart/scripts.pory"

# 70 "data/maps/SootopolisCity_Mart/scripts.pory"
SootopolisCity_Mart_Text_DidSomethingAwaken:
# 71 "data/maps/SootopolisCity_Mart/scripts.pory"
	.string "This weather…\n"
# 72 "data/maps/SootopolisCity_Mart/scripts.pory"
	.string "Did something awaken?$"
