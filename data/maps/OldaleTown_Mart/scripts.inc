# 1 "data/maps/OldaleTown_Mart/scripts.pory"

# 2 "data/maps/OldaleTown_Mart/scripts.pory"
OldaleTown_Mart_MapScripts::
# 3 "data/maps/OldaleTown_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/OldaleTown_Mart/scripts.pory"

# 5 "data/maps/OldaleTown_Mart/scripts.pory"
OldaleTown_Mart_EventScript_Clerk::
# 6 "data/maps/OldaleTown_Mart/scripts.pory"
	lock
# 7 "data/maps/OldaleTown_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/OldaleTown_Mart/scripts.pory"
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_ExpandedItems
# 9 "data/maps/OldaleTown_Mart/scripts.pory"
	pokemart OldaleTown_Mart_Pokemart_Basic
# 10 "data/maps/OldaleTown_Mart/scripts.pory"
	release
# 11 "data/maps/OldaleTown_Mart/scripts.pory"
	end
# 12 "data/maps/OldaleTown_Mart/scripts.pory"

# 13 "data/maps/OldaleTown_Mart/scripts.pory"
	.align 2
# 14 "data/maps/OldaleTown_Mart/scripts.pory"
OldaleTown_Mart_Pokemart_Basic:
# 15 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_REPEL
# 16 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_REVIVE
# 17 "data/maps/OldaleTown_Mart/scripts.pory"
	pokemartlistend
# 18 "data/maps/OldaleTown_Mart/scripts.pory"

# 19 "data/maps/OldaleTown_Mart/scripts.pory"
OldaleTown_Mart_ExpandedItems::
# 20 "data/maps/OldaleTown_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 21 "data/maps/OldaleTown_Mart/scripts.pory"
	waitmessage
# 22 "data/maps/OldaleTown_Mart/scripts.pory"
	pokemart OldaleTown_Mart_Pokemart_Expanded
# 23 "data/maps/OldaleTown_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 24 "data/maps/OldaleTown_Mart/scripts.pory"
	release
# 25 "data/maps/OldaleTown_Mart/scripts.pory"
	end
# 26 "data/maps/OldaleTown_Mart/scripts.pory"

# 27 "data/maps/OldaleTown_Mart/scripts.pory"
	.align 2
# 28 "data/maps/OldaleTown_Mart/scripts.pory"
OldaleTown_Mart_Pokemart_Expanded:
# 29 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_POKE_BALL
# 30 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_CHERISH_BALL
# 31 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_REPEL
# 32 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_REVIVE
# 33 "data/maps/OldaleTown_Mart/scripts.pory"
	pokemartlistend
# 34 "data/maps/OldaleTown_Mart/scripts.pory"

# 35 "data/maps/OldaleTown_Mart/scripts.pory"
OldaleTown_Mart_EventScript_Woman::
# 36 "data/maps/OldaleTown_Mart/scripts.pory"
	lock
# 37 "data/maps/OldaleTown_Mart/scripts.pory"
	faceplayer
# 38 "data/maps/OldaleTown_Mart/scripts.pory"
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_EventScript_PokeBallsInStock
# 39 "data/maps/OldaleTown_Mart/scripts.pory"
	msgbox OldaleTown_Mart_Text_PokeBallsAreSoldOut, MSGBOX_DEFAULT
# 40 "data/maps/OldaleTown_Mart/scripts.pory"
	release
# 41 "data/maps/OldaleTown_Mart/scripts.pory"
	end
# 42 "data/maps/OldaleTown_Mart/scripts.pory"

# 43 "data/maps/OldaleTown_Mart/scripts.pory"
OldaleTown_Mart_EventScript_PokeBallsInStock::
# 44 "data/maps/OldaleTown_Mart/scripts.pory"
	msgbox OldaleTown_Mart_Text_ImGoingToBuyPokeBalls, MSGBOX_DEFAULT
# 45 "data/maps/OldaleTown_Mart/scripts.pory"
	release
# 46 "data/maps/OldaleTown_Mart/scripts.pory"
	end
# 47 "data/maps/OldaleTown_Mart/scripts.pory"

# 48 "data/maps/OldaleTown_Mart/scripts.pory"
OldaleTown_Mart_EventScript_Boy::
# 49 "data/maps/OldaleTown_Mart/scripts.pory"
	msgbox OldaleTown_Mart_Text_RestoreHPWithPotion, MSGBOX_NPC
# 50 "data/maps/OldaleTown_Mart/scripts.pory"
	end
# 51 "data/maps/OldaleTown_Mart/scripts.pory"

# 52 "data/maps/OldaleTown_Mart/scripts.pory"
OldaleTown_Mart_Text_PokeBallsAreSoldOut:
# 53 "data/maps/OldaleTown_Mart/scripts.pory"
	.string "The clerk says they're all sold out.\n"
# 54 "data/maps/OldaleTown_Mart/scripts.pory"
	.string "I can't buy any POKé BALLS.$"
# 55 "data/maps/OldaleTown_Mart/scripts.pory"

# 56 "data/maps/OldaleTown_Mart/scripts.pory"
OldaleTown_Mart_Text_ImGoingToBuyPokeBalls:
# 57 "data/maps/OldaleTown_Mart/scripts.pory"
	.string "I'm going to buy a bunch of POKé BALLS\n"
# 58 "data/maps/OldaleTown_Mart/scripts.pory"
	.string "and catch a bunch of POKéMON!$"
# 59 "data/maps/OldaleTown_Mart/scripts.pory"

# 60 "data/maps/OldaleTown_Mart/scripts.pory"
OldaleTown_Mart_Text_RestoreHPWithPotion:
# 61 "data/maps/OldaleTown_Mart/scripts.pory"
	.string "If a POKéMON gets hurt and loses its HP\n"
# 62 "data/maps/OldaleTown_Mart/scripts.pory"
	.string "and faints, it won't be able to battle.\p"
# 63 "data/maps/OldaleTown_Mart/scripts.pory"
	.string "To prevent your POKéMON from fainting,\n"
# 64 "data/maps/OldaleTown_Mart/scripts.pory"
	.string "restore its HP with a POTION.$"
