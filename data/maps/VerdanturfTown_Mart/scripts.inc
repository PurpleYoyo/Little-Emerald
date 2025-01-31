# 1 "data/maps/VerdanturfTown_Mart/scripts.pory"

# 2 "data/maps/VerdanturfTown_Mart/scripts.pory"
VerdanturfTown_Mart_MapScripts::
# 3 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/VerdanturfTown_Mart/scripts.pory"

# 5 "data/maps/VerdanturfTown_Mart/scripts.pory"
VerdanturfTown_Mart_EventScript_Clerk::
# 6 "data/maps/VerdanturfTown_Mart/scripts.pory"
	lock
# 7 "data/maps/VerdanturfTown_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/VerdanturfTown_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 9 "data/maps/VerdanturfTown_Mart/scripts.pory"
	waitmessage
# 10 "data/maps/VerdanturfTown_Mart/scripts.pory"
	pokemart VerdanturfTown_Mart_Pokemart
# 11 "data/maps/VerdanturfTown_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 12 "data/maps/VerdanturfTown_Mart/scripts.pory"
	release
# 13 "data/maps/VerdanturfTown_Mart/scripts.pory"
	end
# 14 "data/maps/VerdanturfTown_Mart/scripts.pory"

# 15 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.align 2
# 16 "data/maps/VerdanturfTown_Mart/scripts.pory"
VerdanturfTown_Mart_Pokemart:
# 17 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.2byte ITEM_POKE_BALL
# 18 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 19 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.2byte ITEM_NEST_BALL
# 20 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.2byte ITEM_FRIEND_BALL
# 21 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.2byte ITEM_FLUFFY_TAIL
# 22 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.2byte ITEM_REVIVE
# 23 "data/maps/VerdanturfTown_Mart/scripts.pory"
	pokemartlistend
# 24 "data/maps/VerdanturfTown_Mart/scripts.pory"

# 25 "data/maps/VerdanturfTown_Mart/scripts.pory"
VerdanturfTown_Mart_EventScript_Boy::
# 26 "data/maps/VerdanturfTown_Mart/scripts.pory"
	msgbox VerdanturfTown_Mart_Text_XSpecialIsCrucial, MSGBOX_NPC
# 27 "data/maps/VerdanturfTown_Mart/scripts.pory"
	end
# 28 "data/maps/VerdanturfTown_Mart/scripts.pory"

# 29 "data/maps/VerdanturfTown_Mart/scripts.pory"
VerdanturfTown_Mart_EventScript_ExpertF::
# 30 "data/maps/VerdanturfTown_Mart/scripts.pory"
	msgbox VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent, MSGBOX_NPC
# 31 "data/maps/VerdanturfTown_Mart/scripts.pory"
	end
# 32 "data/maps/VerdanturfTown_Mart/scripts.pory"

# 33 "data/maps/VerdanturfTown_Mart/scripts.pory"
VerdanturfTown_Mart_EventScript_Lass::
# 34 "data/maps/VerdanturfTown_Mart/scripts.pory"
	msgbox VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon, MSGBOX_NPC
# 35 "data/maps/VerdanturfTown_Mart/scripts.pory"
	end
# 36 "data/maps/VerdanturfTown_Mart/scripts.pory"

# 37 "data/maps/VerdanturfTown_Mart/scripts.pory"
VerdanturfTown_Mart_Text_XSpecialIsCrucial:
# 38 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.string "For any POKéMON match, X SPECIAL\n"
# 39 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.string "is crucial.\p"
# 40 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.string "It jacks up the power of some moves\n"
# 41 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.string "even though it's only for one battle.$"
# 42 "data/maps/VerdanturfTown_Mart/scripts.pory"

# 43 "data/maps/VerdanturfTown_Mart/scripts.pory"
VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent:
# 44 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.string "They don't seem to sell any winning\n"
# 45 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.string "strategy guides for the BATTLE TENT…\p"
# 46 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.string "It seems one must rely on one's\n"
# 47 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.string "own wits after all…$"
# 48 "data/maps/VerdanturfTown_Mart/scripts.pory"

# 49 "data/maps/VerdanturfTown_Mart/scripts.pory"
VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon:
# 50 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.string "The NEST BALL works better on\n"
# 51 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.string "weakened POKéMON.\p"
# 52 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.string "VERDANTURF is the only place you can\n"
# 53 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.string "buy it.$"
