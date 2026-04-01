# 1 "data/maps/FortreeCity_DecorationShop/scripts.pory"

# 2 "data/maps/FortreeCity_DecorationShop/scripts.pory"
.set LOCALID_SPRIGATITO, 5
# 3 "data/maps/FortreeCity_DecorationShop/scripts.pory"

# 4 "data/maps/FortreeCity_DecorationShop/scripts.pory"
FortreeCity_DecorationShop_MapScripts::
# 5 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	.byte 0
# 6 "data/maps/FortreeCity_DecorationShop/scripts.pory"

# 7 "data/maps/FortreeCity_DecorationShop/scripts.pory"
FortreeCity_DecorationShop_EventScript_PokefanM::
# 8 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	msgbox FortreeCity_DecorationShop_Text_MerchandiseSentToPC, MSGBOX_NPC
# 9 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	end
# 10 "data/maps/FortreeCity_DecorationShop/scripts.pory"

# 11 "data/maps/FortreeCity_DecorationShop/scripts.pory"
FortreeCity_DecorationShop_EventScript_Girl::
# 12 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	msgbox FortreeCity_DecorationShop_Text_BuyingDeskForDolls, MSGBOX_NPC
# 13 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	end
# 14 "data/maps/FortreeCity_DecorationShop/scripts.pory"

# 15 "data/maps/FortreeCity_DecorationShop/scripts.pory"
FortreeCity_DecorationShop_EventScript_ClerkDesks::
# 16 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	lock
# 17 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	faceplayer
# 18 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	message gText_HowMayIServeYou
# 19 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	waitmessage
# 20 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	pokemartdecoration FortreeCity_DecorationShop_PokemartDecor_Desks
# 21 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 22 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	release
# 23 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	end
# 24 "data/maps/FortreeCity_DecorationShop/scripts.pory"

# 25 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	.align 2
# 26 "data/maps/FortreeCity_DecorationShop/scripts.pory"
FortreeCity_DecorationShop_PokemartDecor_Desks:
# 27 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	.2byte DECOR_SMALL_DESK
# 28 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	.2byte DECOR_POKEMON_DESK
# 29 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	.2byte DECOR_HEAVY_DESK
# 30 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	.2byte DECOR_RAGGED_DESK
# 31 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	.2byte DECOR_COMFORT_DESK
# 32 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	.2byte DECOR_BRICK_DESK
# 33 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	.2byte DECOR_CAMP_DESK
# 34 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	.2byte DECOR_HARD_DESK
# 35 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	pokemartlistend
# 36 "data/maps/FortreeCity_DecorationShop/scripts.pory"

# 37 "data/maps/FortreeCity_DecorationShop/scripts.pory"
FortreeCity_DecorationShop_EventScript_ClerkChairs::
# 38 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	lock
# 39 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	faceplayer
# 40 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	message gText_HowMayIServeYou
# 41 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	waitmessage
# 42 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	pokemartdecoration FortreeCity_DecorationShop_PokemartDecor_Chairs
# 43 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 44 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	release
# 45 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	end
# 46 "data/maps/FortreeCity_DecorationShop/scripts.pory"

# 47 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	.align 2
# 48 "data/maps/FortreeCity_DecorationShop/scripts.pory"
FortreeCity_DecorationShop_PokemartDecor_Chairs:
# 49 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	.2byte DECOR_SMALL_CHAIR
# 50 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	.2byte DECOR_POKEMON_CHAIR
# 51 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	.2byte DECOR_HEAVY_CHAIR
# 52 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	.2byte DECOR_RAGGED_CHAIR
# 53 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	.2byte DECOR_COMFORT_CHAIR
# 54 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	.2byte DECOR_BRICK_CHAIR
# 55 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	.2byte DECOR_CAMP_CHAIR
# 56 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	.2byte DECOR_HARD_CHAIR
# 57 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	pokemartlistend
# 58 "data/maps/FortreeCity_DecorationShop/scripts.pory"

# 59 "data/maps/FortreeCity_DecorationShop/scripts.pory"
FortreeCity_DecorationShop_Text_MerchandiseSentToPC:
# 60 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	.string "Merchandise you buy here is sent to\n"
# 61 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	.string "your own PC.\p"
# 62 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	.string "That's fantastic! I wish they could\n"
# 63 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	.string "also deliver me home like that.$"
# 64 "data/maps/FortreeCity_DecorationShop/scripts.pory"

# 65 "data/maps/FortreeCity_DecorationShop/scripts.pory"
FortreeCity_DecorationShop_Text_BuyingDeskForDolls:
# 66 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	.string "I'm buying a pretty desk and I'm\n"
# 67 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	.string "putting my cute DOLLS on it.\p"
# 68 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	.string "If I don't, when I decorate my\n"
# 69 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	.string "SECRET BASE, my DOLLS will get\l"
# 70 "data/maps/FortreeCity_DecorationShop/scripts.pory"
	.string "dirty or poked with splinters.$"
