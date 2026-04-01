# 1 "data/maps/SootopolisCity_House1/scripts.pory"

# 2 "data/maps/SootopolisCity_House1/scripts.pory"
.set LOCALID_TURTWIG, 1
# 3 "data/maps/SootopolisCity_House1/scripts.pory"

# 4 "data/maps/SootopolisCity_House1/scripts.pory"
SootopolisCity_House1_MapScripts::
# 5 "data/maps/SootopolisCity_House1/scripts.pory"
	.byte 0
# 6 "data/maps/SootopolisCity_House1/scripts.pory"

# 7 "data/maps/SootopolisCity_House1/scripts.pory"
SootopolisCity_House1_EventScript_BrickBreakBlackBelt::
# 8 "data/maps/SootopolisCity_House1/scripts.pory"
	lock
# 9 "data/maps/SootopolisCity_House1/scripts.pory"
	faceplayer
# 10 "data/maps/SootopolisCity_House1/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_BRICK_BREAK, SootopolisCity_House1_EventScript_ReceivedBrickBreak
# 11 "data/maps/SootopolisCity_House1/scripts.pory"
	msgbox SootopolisCity_House1_Text_DevelopedThisTM, MSGBOX_DEFAULT
# 12 "data/maps/SootopolisCity_House1/scripts.pory"
	giveitem ITEM_TM_LIQUIDATION
# 13 "data/maps/SootopolisCity_House1/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 14 "data/maps/SootopolisCity_House1/scripts.pory"
	setflag FLAG_RECEIVED_TM_BRICK_BREAK
# 15 "data/maps/SootopolisCity_House1/scripts.pory"
	msgbox SootopolisCity_House1_Text_ExplainBrickBreak, MSGBOX_DEFAULT
# 16 "data/maps/SootopolisCity_House1/scripts.pory"
	release
# 17 "data/maps/SootopolisCity_House1/scripts.pory"
	end
# 18 "data/maps/SootopolisCity_House1/scripts.pory"

# 19 "data/maps/SootopolisCity_House1/scripts.pory"
SootopolisCity_House1_EventScript_ReceivedBrickBreak::
# 20 "data/maps/SootopolisCity_House1/scripts.pory"
	msgbox SootopolisCity_House1_Text_ExplainBrickBreak, MSGBOX_DEFAULT
# 21 "data/maps/SootopolisCity_House1/scripts.pory"
	release
# 22 "data/maps/SootopolisCity_House1/scripts.pory"
	end
# 23 "data/maps/SootopolisCity_House1/scripts.pory"

# 24 "data/maps/SootopolisCity_House1/scripts.pory"
SootopolisCity_House1_EventScript_Kecleon::
# 25 "data/maps/SootopolisCity_House1/scripts.pory"
	lock
# 26 "data/maps/SootopolisCity_House1/scripts.pory"
	faceplayer
# 27 "data/maps/SootopolisCity_House1/scripts.pory"
	waitse
# 28 "data/maps/SootopolisCity_House1/scripts.pory"
	playmoncry SPECIES_ZORUA, CRY_MODE_NORMAL
# 29 "data/maps/SootopolisCity_House1/scripts.pory"
	msgbox SootopolisCity_House1_Text_Kecleon, MSGBOX_DEFAULT
# 30 "data/maps/SootopolisCity_House1/scripts.pory"
	waitmoncry
# 31 "data/maps/SootopolisCity_House1/scripts.pory"
	release
# 32 "data/maps/SootopolisCity_House1/scripts.pory"
	end
# 33 "data/maps/SootopolisCity_House1/scripts.pory"

# 34 "data/maps/SootopolisCity_House1/scripts.pory"
SootopolisCity_House1_Text_DevelopedThisTM:
# 35 "data/maps/SootopolisCity_House1/scripts.pory"
	.string "For thirty years I've remained in\n"
# 36 "data/maps/SootopolisCity_House1/scripts.pory"
	.string "SOOTOPOLIS honing my skills.\p"
# 37 "data/maps/SootopolisCity_House1/scripts.pory"
	.string "I developed a shattering TM.\n"
# 38 "data/maps/SootopolisCity_House1/scripts.pory"
	.string "I bequeath it to you!$"
# 39 "data/maps/SootopolisCity_House1/scripts.pory"

# 40 "data/maps/SootopolisCity_House1/scripts.pory"
SootopolisCity_House1_Text_ExplainBrickBreak:
# 41 "data/maps/SootopolisCity_House1/scripts.pory"
	.string "TM71 contains LIQUIDATION! It's a move\n"
# 42 "data/maps/SootopolisCity_House1/scripts.pory"
	.string "so horrible that I can't describe it.$"
# 43 "data/maps/SootopolisCity_House1/scripts.pory"

# 44 "data/maps/SootopolisCity_House1/scripts.pory"
SootopolisCity_House1_Text_Kecleon:
# 45 "data/maps/SootopolisCity_House1/scripts.pory"
	.string "ZORUA: Puu puhyaah.$"
