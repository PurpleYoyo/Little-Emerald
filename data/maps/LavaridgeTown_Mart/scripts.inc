# 1 "data/maps/LavaridgeTown_Mart/scripts.pory"

# 2 "data/maps/LavaridgeTown_Mart/scripts.pory"
LavaridgeTown_Mart_MapScripts::
# 3 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/LavaridgeTown_Mart/scripts.pory"

# 5 "data/maps/LavaridgeTown_Mart/scripts.pory"
LavaridgeTown_Mart_EventScript_Clerk::
# 6 "data/maps/LavaridgeTown_Mart/scripts.pory"
	lock
# 7 "data/maps/LavaridgeTown_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/LavaridgeTown_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 9 "data/maps/LavaridgeTown_Mart/scripts.pory"
	waitmessage
# 10 "data/maps/LavaridgeTown_Mart/scripts.pory"
	pokemart LavaridgeTown_Mart_Pokemart
# 11 "data/maps/LavaridgeTown_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 12 "data/maps/LavaridgeTown_Mart/scripts.pory"
	release
# 13 "data/maps/LavaridgeTown_Mart/scripts.pory"
	end
# 14 "data/maps/LavaridgeTown_Mart/scripts.pory"

# 15 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.align 2
# 16 "data/maps/LavaridgeTown_Mart/scripts.pory"
LavaridgeTown_Mart_Pokemart:
# 17 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_POKE_BALL
# 18 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 19 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_HEAL_BALL
# 20 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_LOVE_BALL
# 21 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_REVIVE
# 22 "data/maps/LavaridgeTown_Mart/scripts.pory"
	pokemartlistend
# 23 "data/maps/LavaridgeTown_Mart/scripts.pory"

# 24 "data/maps/LavaridgeTown_Mart/scripts.pory"
LavaridgeTown_Mart_EventScript_ExpertM::
# 25 "data/maps/LavaridgeTown_Mart/scripts.pory"
	msgbox LavaridgeTown_Mart_Text_XSpeedFirstStrike, MSGBOX_NPC
# 26 "data/maps/LavaridgeTown_Mart/scripts.pory"
	end
# 27 "data/maps/LavaridgeTown_Mart/scripts.pory"

# 28 "data/maps/LavaridgeTown_Mart/scripts.pory"
LavaridgeTown_Mart_EventScript_OldWoman::
# 29 "data/maps/LavaridgeTown_Mart/scripts.pory"
	msgbox LavaridgeTown_Mart_Text_LocalSpecialtyOnMtChimney, MSGBOX_NPC
# 30 "data/maps/LavaridgeTown_Mart/scripts.pory"
	end
# 31 "data/maps/LavaridgeTown_Mart/scripts.pory"

# 32 "data/maps/LavaridgeTown_Mart/scripts.pory"
LavaridgeTown_Mart_Text_XSpeedFirstStrike:
# 33 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.string "Use X SPEED to add to a POKéMON's\n"
# 34 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.string "SPEED in battle.\p"
# 35 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.string "That will help it get in the first\n"
# 36 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.string "strike--a decided advantage!$"
# 37 "data/maps/LavaridgeTown_Mart/scripts.pory"

# 38 "data/maps/LavaridgeTown_Mart/scripts.pory"
LavaridgeTown_Mart_Text_LocalSpecialtyOnMtChimney:
# 39 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.string "On MT. CHIMNEY's peak, there's a local\n"
# 40 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.string "specialty that you can buy only there.\p"
# 41 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.string "Give it to a POKéMON--it will be elated.$"
