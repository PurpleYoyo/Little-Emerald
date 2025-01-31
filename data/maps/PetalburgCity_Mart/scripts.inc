# 1 "data/maps/PetalburgCity_Mart/scripts.pory"

# 2 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_MapScripts::
# 3 "data/maps/PetalburgCity_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/PetalburgCity_Mart/scripts.pory"

# 5 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_EventScript_Clerk::
# 6 "data/maps/PetalburgCity_Mart/scripts.pory"
	lock
# 7 "data/maps/PetalburgCity_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/PetalburgCity_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 9 "data/maps/PetalburgCity_Mart/scripts.pory"
	waitmessage
# 10 "data/maps/PetalburgCity_Mart/scripts.pory"
	goto_if_set FLAG_PETALBURG_MART_EXPANDED_ITEMS, PetalburgCity_Mart_EventScript_ExpandedItems
# 11 "data/maps/PetalburgCity_Mart/scripts.pory"
	pokemart PetalburgCity_Mart_Pokemart_Basic
# 12 "data/maps/PetalburgCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 13 "data/maps/PetalburgCity_Mart/scripts.pory"
	release
# 14 "data/maps/PetalburgCity_Mart/scripts.pory"
	end
# 15 "data/maps/PetalburgCity_Mart/scripts.pory"

# 16 "data/maps/PetalburgCity_Mart/scripts.pory"
	.align 2
# 17 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_Pokemart_Basic:
# 18 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_POKE_BALL
# 19 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_LEVEL_BALL
# 20 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_REVIVE
# 21 "data/maps/PetalburgCity_Mart/scripts.pory"
	pokemartlistend
# 22 "data/maps/PetalburgCity_Mart/scripts.pory"

# 23 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_EventScript_ExpandedItems::
# 24 "data/maps/PetalburgCity_Mart/scripts.pory"
	pokemart PetalburgCity_Mart_Pokemart_Expanded
# 25 "data/maps/PetalburgCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 26 "data/maps/PetalburgCity_Mart/scripts.pory"
	release
# 27 "data/maps/PetalburgCity_Mart/scripts.pory"
	end
# 28 "data/maps/PetalburgCity_Mart/scripts.pory"

# 29 "data/maps/PetalburgCity_Mart/scripts.pory"
	.align 2
# 30 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_Pokemart_Expanded:
# 31 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_POKE_BALL
# 32 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_LEVEL_BALL
# 33 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_REVIVE
# 34 "data/maps/PetalburgCity_Mart/scripts.pory"
	pokemartlistend
# 35 "data/maps/PetalburgCity_Mart/scripts.pory"

# 36 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_EventScript_Woman::
# 37 "data/maps/PetalburgCity_Mart/scripts.pory"
	msgbox PetalburgCity_Mart_Text_WeakWillGrowStronger, MSGBOX_NPC
# 38 "data/maps/PetalburgCity_Mart/scripts.pory"
	end
# 39 "data/maps/PetalburgCity_Mart/scripts.pory"

# 40 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_EventScript_Boy::
# 41 "data/maps/PetalburgCity_Mart/scripts.pory"
	msgbox PetalburgCity_Mart_Text_RepelIsUseful, MSGBOX_NPC
# 42 "data/maps/PetalburgCity_Mart/scripts.pory"
	end
# 43 "data/maps/PetalburgCity_Mart/scripts.pory"

# 44 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_EventScript_Man::
# 45 "data/maps/PetalburgCity_Mart/scripts.pory"
	msgbox PetalburgCity_Mart_Text_TakeSomeAntidotesWithYou, MSGBOX_NPC
# 46 "data/maps/PetalburgCity_Mart/scripts.pory"
	end
# 47 "data/maps/PetalburgCity_Mart/scripts.pory"

# 48 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_Text_WeakWillGrowStronger:
# 49 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "Even if a POKéMON is weak now,\n"
# 50 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "it will grow stronger.\p"
# 51 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "The most important thing is love!\n"
# 52 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "Love for your POKéMON!$"
# 53 "data/maps/PetalburgCity_Mart/scripts.pory"

# 54 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_Text_RepelIsUseful:
# 55 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "Do you use REPEL?\n"
# 56 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "It keeps POKéMON away, so it's\l"
# 57 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "useful when you're in a hurry.$"
# 58 "data/maps/PetalburgCity_Mart/scripts.pory"

# 59 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_Text_TakeSomeAntidotesWithYou:
# 60 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "Do you have any ANTIDOTES with\n"
# 61 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "you?\p"
# 62 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "If you walk around with a poisoned\n"
# 63 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "POKéMON, it will lose HP until it faints.\l"
# 64 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "Take some ANTIDOTES with you.$"
