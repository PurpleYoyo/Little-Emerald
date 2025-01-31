# 1 "data/maps/FallarborTown_Mart/scripts.pory"

# 2 "data/maps/FallarborTown_Mart/scripts.pory"
FallarborTown_Mart_MapScripts::
# 3 "data/maps/FallarborTown_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/FallarborTown_Mart/scripts.pory"

# 5 "data/maps/FallarborTown_Mart/scripts.pory"
FallarborTown_Mart_EventScript_Clerk::
# 6 "data/maps/FallarborTown_Mart/scripts.pory"
	lock
# 7 "data/maps/FallarborTown_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/FallarborTown_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 9 "data/maps/FallarborTown_Mart/scripts.pory"
	waitmessage
# 10 "data/maps/FallarborTown_Mart/scripts.pory"
	pokemart FallarborTown_Mart_Pokemart
# 11 "data/maps/FallarborTown_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 12 "data/maps/FallarborTown_Mart/scripts.pory"
	release
# 13 "data/maps/FallarborTown_Mart/scripts.pory"
	end
# 14 "data/maps/FallarborTown_Mart/scripts.pory"

# 15 "data/maps/FallarborTown_Mart/scripts.pory"
	.align 2
# 16 "data/maps/FallarborTown_Mart/scripts.pory"
FallarborTown_Mart_Pokemart:
# 17 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_POKE_BALL
# 18 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 19 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_HEAVY_BALL
# 20 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_LUXURY_BALL
# 21 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_REVIVE
# 22 "data/maps/FallarborTown_Mart/scripts.pory"
	pokemartlistend
# 23 "data/maps/FallarborTown_Mart/scripts.pory"

# 24 "data/maps/FallarborTown_Mart/scripts.pory"
FallarborTown_Mart_EventScript_Woman::
# 25 "data/maps/FallarborTown_Mart/scripts.pory"
	msgbox FallarborTown_Mart_Text_DecidingSkittyEvolve, MSGBOX_NPC
# 26 "data/maps/FallarborTown_Mart/scripts.pory"
	end
# 27 "data/maps/FallarborTown_Mart/scripts.pory"

# 28 "data/maps/FallarborTown_Mart/scripts.pory"
FallarborTown_Mart_EventScript_PokefanM::
# 29 "data/maps/FallarborTown_Mart/scripts.pory"
	msgbox FallarborTown_Mart_Text_SellNuggetIFound, MSGBOX_NPC
# 30 "data/maps/FallarborTown_Mart/scripts.pory"
	end
# 31 "data/maps/FallarborTown_Mart/scripts.pory"

# 32 "data/maps/FallarborTown_Mart/scripts.pory"
FallarborTown_Mart_EventScript_Skitty::
# 33 "data/maps/FallarborTown_Mart/scripts.pory"
	lock
# 34 "data/maps/FallarborTown_Mart/scripts.pory"
	faceplayer
# 35 "data/maps/FallarborTown_Mart/scripts.pory"
	waitse
# 36 "data/maps/FallarborTown_Mart/scripts.pory"
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
# 37 "data/maps/FallarborTown_Mart/scripts.pory"
	msgbox FallarborTown_Mart_Text_Skitty, MSGBOX_DEFAULT
# 38 "data/maps/FallarborTown_Mart/scripts.pory"
	waitmoncry
# 39 "data/maps/FallarborTown_Mart/scripts.pory"
	release
# 40 "data/maps/FallarborTown_Mart/scripts.pory"
	end
# 41 "data/maps/FallarborTown_Mart/scripts.pory"

# 42 "data/maps/FallarborTown_Mart/scripts.pory"
FallarborTown_Mart_Text_DecidingSkittyEvolve:
# 43 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "I'm having a hard time deciding if I\n"
# 44 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "should make my SKITTY evolve or not.\p"
# 45 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "I only have to use this MOON STONE,\n"
# 46 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "but it's so hard to decide…\p"
# 47 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "If I make it evolve, it will become\n"
# 48 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "much stronger.\p"
# 49 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "But it will look so different, too.$"
# 50 "data/maps/FallarborTown_Mart/scripts.pory"

# 51 "data/maps/FallarborTown_Mart/scripts.pory"
FallarborTown_Mart_Text_Skitty:
# 52 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "SKITTY: Miyao?$"
# 53 "data/maps/FallarborTown_Mart/scripts.pory"

# 54 "data/maps/FallarborTown_Mart/scripts.pory"
FallarborTown_Mart_Text_SellNuggetIFound:
# 55 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "This NUGGET I found here…\n"
# 56 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "I suppose I'll have to sell it, seeing\l"
# 57 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "as how it has no other use.$"
