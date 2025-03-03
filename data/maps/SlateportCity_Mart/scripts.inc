# 1 "data/maps/SlateportCity_Mart/scripts.pory"

# 2 "data/maps/SlateportCity_Mart/scripts.pory"
SlateportCity_Mart_MapScripts::
# 3 "data/maps/SlateportCity_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/SlateportCity_Mart/scripts.pory"

# 5 "data/maps/SlateportCity_Mart/scripts.pory"
SlateportCity_Mart_EventScript_Clerk::
# 6 "data/maps/SlateportCity_Mart/scripts.pory"
	lock
# 7 "data/maps/SlateportCity_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/SlateportCity_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 9 "data/maps/SlateportCity_Mart/scripts.pory"
	waitmessage
# 10 "data/maps/SlateportCity_Mart/scripts.pory"
	pokemart SlateportCity_Mart_Pokemart
# 11 "data/maps/SlateportCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 12 "data/maps/SlateportCity_Mart/scripts.pory"
	release
# 13 "data/maps/SlateportCity_Mart/scripts.pory"
	end
# 14 "data/maps/SlateportCity_Mart/scripts.pory"

# 15 "data/maps/SlateportCity_Mart/scripts.pory"
	.align 2
# 16 "data/maps/SlateportCity_Mart/scripts.pory"
SlateportCity_Mart_Pokemart:
# 17 "data/maps/SlateportCity_Mart/scripts.pory"
	.2byte ITEM_POKE_BALL
# 18 "data/maps/SlateportCity_Mart/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 19 "data/maps/SlateportCity_Mart/scripts.pory"
	.2byte ITEM_LURE_BALL
# 20 "data/maps/SlateportCity_Mart/scripts.pory"
	.2byte ITEM_REVIVE
# 21 "data/maps/SlateportCity_Mart/scripts.pory"
	.2byte ITEM_HARBOR_MAIL
# 22 "data/maps/SlateportCity_Mart/scripts.pory"
	pokemartlistend
# 23 "data/maps/SlateportCity_Mart/scripts.pory"

# 24 "data/maps/SlateportCity_Mart/scripts.pory"
SlateportCity_Mart_EventScript_BlackBelt::
# 25 "data/maps/SlateportCity_Mart/scripts.pory"
	msgbox SlateportCity_Mart_Text_SomeItemsOnlyAtMart, MSGBOX_NPC
# 26 "data/maps/SlateportCity_Mart/scripts.pory"
	end
# 27 "data/maps/SlateportCity_Mart/scripts.pory"

# 28 "data/maps/SlateportCity_Mart/scripts.pory"
SlateportCity_Mart_EventScript_Man::
# 29 "data/maps/SlateportCity_Mart/scripts.pory"
	msgbox SlateportCity_Mart_Text_GreatBallIsBetter, MSGBOX_NPC
# 30 "data/maps/SlateportCity_Mart/scripts.pory"
	end
# 31 "data/maps/SlateportCity_Mart/scripts.pory"

# 32 "data/maps/SlateportCity_Mart/scripts.pory"
SlateportCity_Mart_Text_SomeItemsOnlyAtMart:
# 33 "data/maps/SlateportCity_Mart/scripts.pory"
	.string "The MARKET does have some interesting\n"
# 34 "data/maps/SlateportCity_Mart/scripts.pory"
	.string "merchandise.\p"
# 35 "data/maps/SlateportCity_Mart/scripts.pory"
	.string "But there are some items you can only\n"
# 36 "data/maps/SlateportCity_Mart/scripts.pory"
	.string "get at a POKéMON MART.$"
# 37 "data/maps/SlateportCity_Mart/scripts.pory"

# 38 "data/maps/SlateportCity_Mart/scripts.pory"
SlateportCity_Mart_Text_GreatBallIsBetter:
# 39 "data/maps/SlateportCity_Mart/scripts.pory"
	.string "A GREAT BALL is better than a POKé BALL\n"
# 40 "data/maps/SlateportCity_Mart/scripts.pory"
	.string "at catching POKéMON.\p"
# 41 "data/maps/SlateportCity_Mart/scripts.pory"
	.string "With this, I should be able to get that\n"
# 42 "data/maps/SlateportCity_Mart/scripts.pory"
	.string "elusive POKéMON…$"
