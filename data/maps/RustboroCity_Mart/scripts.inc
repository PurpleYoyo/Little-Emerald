# 1 "data/maps/RustboroCity_Mart/scripts.pory"

# 2 "data/maps/RustboroCity_Mart/scripts.pory"
RustboroCity_Mart_MapScripts::
# 3 "data/maps/RustboroCity_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/RustboroCity_Mart/scripts.pory"

# 5 "data/maps/RustboroCity_Mart/scripts.pory"
RustboroCity_Mart_EventScript_Clerk::
# 6 "data/maps/RustboroCity_Mart/scripts.pory"
	lock
# 7 "data/maps/RustboroCity_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/RustboroCity_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 9 "data/maps/RustboroCity_Mart/scripts.pory"
	waitmessage
# 10 "data/maps/RustboroCity_Mart/scripts.pory"
	goto RustboroCity_Mart_EventScript_PokemartExpanded
# 11 "data/maps/RustboroCity_Mart/scripts.pory"
	end
# 12 "data/maps/RustboroCity_Mart/scripts.pory"

# 13 "data/maps/RustboroCity_Mart/scripts.pory"
RustboroCity_Mart_EventScript_PokemartBasic::
# 14 "data/maps/RustboroCity_Mart/scripts.pory"
	pokemart RustboroCity_Mart_Pokemart_Basic
# 15 "data/maps/RustboroCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 16 "data/maps/RustboroCity_Mart/scripts.pory"
	release
# 17 "data/maps/RustboroCity_Mart/scripts.pory"
	end
# 18 "data/maps/RustboroCity_Mart/scripts.pory"

# 19 "data/maps/RustboroCity_Mart/scripts.pory"
	.align 2
# 20 "data/maps/RustboroCity_Mart/scripts.pory"
RustboroCity_Mart_Pokemart_Basic:
# 21 "data/maps/RustboroCity_Mart/scripts.pory"
	.2byte ITEM_REPEL
# 22 "data/maps/RustboroCity_Mart/scripts.pory"
	.2byte ITEM_POKE_BALL
# 23 "data/maps/RustboroCity_Mart/scripts.pory"
	pokemartlistend
# 24 "data/maps/RustboroCity_Mart/scripts.pory"

# 25 "data/maps/RustboroCity_Mart/scripts.pory"
RustboroCity_Mart_EventScript_PokemartExpanded::
# 26 "data/maps/RustboroCity_Mart/scripts.pory"
	pokemart RustboroCity_Mart_Pokemart_Expanded
# 27 "data/maps/RustboroCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 28 "data/maps/RustboroCity_Mart/scripts.pory"
	release
# 29 "data/maps/RustboroCity_Mart/scripts.pory"
	end
# 30 "data/maps/RustboroCity_Mart/scripts.pory"

# 31 "data/maps/RustboroCity_Mart/scripts.pory"
	.align 2
# 32 "data/maps/RustboroCity_Mart/scripts.pory"
RustboroCity_Mart_Pokemart_Expanded:
# 33 "data/maps/RustboroCity_Mart/scripts.pory"
	.2byte ITEM_POKE_BALL
# 34 "data/maps/RustboroCity_Mart/scripts.pory"
	.2byte ITEM_TIMER_BALL
# 35 "data/maps/RustboroCity_Mart/scripts.pory"
	.2byte ITEM_REPEAT_BALL
# 36 "data/maps/RustboroCity_Mart/scripts.pory"
	.2byte ITEM_REPEL
# 37 "data/maps/RustboroCity_Mart/scripts.pory"
	.2byte ITEM_REVIVE
# 38 "data/maps/RustboroCity_Mart/scripts.pory"
	pokemartlistend
# 39 "data/maps/RustboroCity_Mart/scripts.pory"

# 40 "data/maps/RustboroCity_Mart/scripts.pory"
RustboroCity_Mart_EventScript_PokefanF::
# 41 "data/maps/RustboroCity_Mart/scripts.pory"
	msgbox RustboroCity_Mart_Text_BuyingHealsInCaseOfShroomish, MSGBOX_NPC
# 42 "data/maps/RustboroCity_Mart/scripts.pory"
	end
# 43 "data/maps/RustboroCity_Mart/scripts.pory"

# 44 "data/maps/RustboroCity_Mart/scripts.pory"
RustboroCity_Mart_EventScript_Boy::
# 45 "data/maps/RustboroCity_Mart/scripts.pory"
	msgbox RustboroCity_Mart_Text_ShouldBuySuperPotionsInstead, MSGBOX_NPC
# 46 "data/maps/RustboroCity_Mart/scripts.pory"
	end
# 47 "data/maps/RustboroCity_Mart/scripts.pory"

# 48 "data/maps/RustboroCity_Mart/scripts.pory"
RustboroCity_Mart_EventScript_BugCatcher::
# 49 "data/maps/RustboroCity_Mart/scripts.pory"
	msgbox RustboroCity_Mart_Text_GettingEscapeRopeJustInCase, MSGBOX_NPC
# 50 "data/maps/RustboroCity_Mart/scripts.pory"
	end
# 51 "data/maps/RustboroCity_Mart/scripts.pory"

# 52 "data/maps/RustboroCity_Mart/scripts.pory"
RustboroCity_Mart_Text_BuyingHealsInCaseOfShroomish:
# 53 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "I'm buying some PARLYZ HEALS and\n"
# 54 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "ANTIDOTES.\p"
# 55 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "Just in case I run into SHROOMISH\n"
# 56 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "in PETALBURG WOODS.$"
# 57 "data/maps/RustboroCity_Mart/scripts.pory"

# 58 "data/maps/RustboroCity_Mart/scripts.pory"
RustboroCity_Mart_Text_ShouldBuySuperPotionsInstead:
# 59 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "My POKéMON evolved.\n"
# 60 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "It has a lot of HP now.\p"
# 61 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "I should buy SUPER POTIONS for it\n"
# 62 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "instead of ordinary POTIONS.$"
# 63 "data/maps/RustboroCity_Mart/scripts.pory"

# 64 "data/maps/RustboroCity_Mart/scripts.pory"
RustboroCity_Mart_Text_GettingEscapeRopeJustInCase:
# 65 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "I'm getting an ESCAPE ROPE just in\n"
# 66 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "case I get lost in a cave.\p"
# 67 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "I just need to use it to get back to\n"
# 68 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "the entrance.$"
