# 1 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"

# 2 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
.set LOCALID_NURSE, 1
# 3 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"

# 4 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
DewfordTown_PokemonCenter_1F_MapScripts::
# 5 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_PokemonCenter_1F_OnTransition
# 6 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 7 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.byte 0
# 8 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"

# 9 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
DewfordTown_PokemonCenter_1F_OnTransition:
# 10 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setrespawn HEAL_LOCATION_DEWFORD_TOWN
# 11 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_UpdateBrineyLocation
# 12 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	end
# 13 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"

# 14 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
DewfordTown_PokemonCenter_1F_EventScript_Nurse::
# 15 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x800B, LOCALID_NURSE
# 16 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 17 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 18 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitbuttonpress
# 19 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	release
# 20 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	end
# 21 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"

# 22 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
DewfordTown_PokemonCenter_1F_EventScript_PokefanF::
# 23 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_Text_StoneCavern, MSGBOX_NPC
# 24 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	end
# 25 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"

# 26 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
DewfordTown_PokemonCenter_1F_EventScript_Man::
# 27 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_Text_FaintedMonCanUseHM, MSGBOX_NPC
# 28 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	end
# 29 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"

# 30 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
DewfordTown_PokemonCenter_1F_Text_StoneCavern:
# 31 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "There's a stone cavern at the edge\n"
# 32 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "of town.\p"
# 33 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "I've heard you can find rare stones\n"
# 34 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "there.$"
# 35 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"

# 36 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
DewfordTown_PokemonCenter_1F_Text_FaintedMonCanUseHM:
# 37 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Even if a POKéMON faints and can't\n"
# 38 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "battle, it can still use a move learned\l"
# 39 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "from a HIDDEN MACHINE (HM).$"

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse::
# 44 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	lock
# 45 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	message DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_0
# 46 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	yesnobox 5, 2
# 47 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_2
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_1:
# 125 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	release
	return

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_2:
# 48 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	checkitem ITEM_BLANK_MINT, 1
# 49 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_ne DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_4
# 52 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_2
# 53 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	multichoice 5, 2, MULTI_STAT_NAMES_NO_HP, 0
# 54 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_8
# 56 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_9
# 58 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_10
# 60 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_11
# 62 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_12
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_7:
# 65 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_3
# 66 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	multichoice 5, 2, MULTI_STAT_NAMES_NO_HP, 0
# 67 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_19
# 69 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_20
# 71 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_21
# 73 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_22
# 75 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_23
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_18:
# 80 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare RAISE, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_47
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_46:
# 81 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare RAISE, 1
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_51
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_50:
# 82 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare RAISE, 2
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_55
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_54:
# 83 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare RAISE, 3
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_59
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_58:
# 84 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare RAISE, 4
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_62
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_44:
# 94 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare RAISE, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_43
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_41:
# 101 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare RAISE, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_40
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_38:
# 108 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare RAISE, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_37
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_35:
# 115 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare RAISE, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_34
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_1

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_4:
# 50 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_1
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_1

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_8:
# 55 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setvar RAISE, 0
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_7

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_9:
# 57 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setvar RAISE, 1
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_7

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_10:
# 59 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setvar RAISE, 2
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_7

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_11:
# 61 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setvar RAISE, 3
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_7

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_12:
# 63 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setvar RAISE, 4
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_7

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_19:
# 68 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setvar LOWER, 0
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_18

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_20:
# 70 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setvar LOWER, 1
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_18

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_21:
# 72 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setvar LOWER, 2
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_18

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_22:
# 74 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setvar LOWER, 3
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_18

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_23:
# 76 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setvar LOWER, 4
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_18

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_29:
# 85 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	message DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_4
# 86 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	yesnobox 5, 2
# 87 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_65
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_1

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_30:
# 95 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	message DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_5
# 96 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	yesnobox 5, 2
# 97 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_67
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_1

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_31:
# 102 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	message DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_6
# 103 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	yesnobox 5, 2
# 104 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_69
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_1

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_32:
# 109 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	message DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_7
# 110 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	yesnobox 5, 2
# 111 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_71
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_1

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_33:
# 116 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	message DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_8
# 117 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	yesnobox 5, 2
# 118 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_73
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_1

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_34:
# 115 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare LOWER, 4
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_33
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_1

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_37:
# 108 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare LOWER, 3
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_32
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_35

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_40:
# 101 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare LOWER, 2
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_31
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_38

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_43:
# 94 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare LOWER, 1
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_30
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_41

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_47:
# 80 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare LOWER, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_29
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_46

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_51:
# 81 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare LOWER, 1
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_29
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_50

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_55:
# 82 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare LOWER, 2
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_29
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_54

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_59:
# 83 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare LOWER, 3
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_29
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_58

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_62:
# 84 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare LOWER, 4
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_29
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_44

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_65:
# 88 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_SERIOUS_MINT
# 89 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_1

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_67:
# 98 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_LONELY_MINT
# 99 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_1

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_69:
# 105 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_ADAMANT_MINT
# 106 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_1

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_71:
# 112 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_NAUGHTY_MINT
# 113 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_1

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_73:
# 119 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_BRAVE_MINT
# 120 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_1


DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse::
# 129 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	lock
# 130 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	message DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_0
# 131 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	multichoice 5, 2, MULTI_PREDAMAGE, 0
# 132 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_2
DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_1:
# 141 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_5
DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_4:
# 285 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	release
	return

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_2:
# 133 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special ChoosePartyMon
# 134 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitstate
# 135 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	call Common_SelectDamage
# 139 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	sethp 5, VAR_0x8004
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_1

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_5:
# 142 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	closemessage
# 143 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_1
# 144 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	multichoicegrid 5, 2, MULTI_STATUSES, 2, 0
# 145 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_8
# 147 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_9
# 149 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_10
# 151 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_11
# 153 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_12
# 155 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 5
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_13
DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_7:
# 159 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare STATUS, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_21
DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_20:
# 183 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare STATUS, 1
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_24
DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_23:
# 202 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare STATUS, 2
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_31
DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_30:
# 222 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare STATUS, 3
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_41
DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_40:
# 241 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare STATUS, 4
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_54
DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_53:
# 260 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare STATUS, 5
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_63
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_4

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_8:
# 146 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setvar STATUS, 0
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_7

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_9:
# 148 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setvar STATUS, 1
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_7

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_10:
# 150 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setvar STATUS, 2
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_7

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_11:
# 152 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setvar STATUS, 3
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_7

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_12:
# 154 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setvar STATUS, 4
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_7

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_13:
# 156 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setvar STATUS, 5
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_7

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_21:
# 160 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special ChoosePartyMon
# 161 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitstate
# 162 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 163 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_26
# 165 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_NONE
	goto_if_ne DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_27
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_20

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_24:
# 184 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special ChoosePartyMon
# 185 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitstate
# 186 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 187 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_33
# 189 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_NONE
	goto_if_ne DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_34
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_23

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_26:
# 164 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_2
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_20

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_27:
# 166 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special IsChosenMonSteelType
# 167 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_37
# 170 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special IsChosenMonPoisonType
# 171 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_50
# 174 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setstatus1 STATUS1_POISON, VAR_0x8004
# 175 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar 0x8007, GetSelectedMonNicknameAndSpecies
# 176 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	playmoncry 0x8007, 0
# 177 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitmoncry
# 178 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_5
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_20

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_31:
# 203 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special ChoosePartyMon
# 204 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitstate
# 205 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 206 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_43
# 208 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_NONE
	goto_if_ne DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_44
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_30

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_33:
# 188 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_6
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_23

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_34:
# 190 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special IsChosenMonElectricType
# 191 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_47
# 194 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setstatus1 STATUS1_PARALYSIS, VAR_0x8004
# 195 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar 0x8007, GetSelectedMonNicknameAndSpecies
# 196 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	playmoncry 0x8007, 0
# 197 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitmoncry
# 198 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_8
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_23

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_37:
# 168 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_3
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_20

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_41:
# 223 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special ChoosePartyMon
# 224 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitstate
# 225 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 226 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_56
# 228 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_NONE
	goto_if_ne DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_57
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_40

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_43:
# 207 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_9
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_30

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_44:
# 209 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special IsChosenMonImmuneToSleepDueToAbility
# 210 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_60
# 214 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setstatus1 STATUS1_SLEEP_TURN ( 1 ), VAR_0x8004
# 215 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar 0x8007, GetSelectedMonNicknameAndSpecies
# 216 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	playmoncry 0x8007, 0
# 217 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitmoncry
# 218 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_11
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_30

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_47:
# 192 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_7
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_23

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_50:
# 172 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_4
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_20

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_54:
# 242 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special ChoosePartyMon
# 243 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitstate
# 244 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 245 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_65
# 247 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_NONE
	goto_if_ne DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_66
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_53

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_56:
# 227 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_12
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_40

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_57:
# 229 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special IsChosenMonFireType
# 230 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_69
# 233 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setstatus1 STATUS1_BURN, VAR_0x8004
# 234 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar 0x8007, GetSelectedMonNicknameAndSpecies
# 235 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	playmoncry 0x8007, 0
# 236 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitmoncry
# 237 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_14
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_40

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_60:
# 211 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar 0x8007, GetSelectedMonNicknameAndSpecies
# 212 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_10
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_30

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_63:
# 261 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special ChoosePartyMon
# 262 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitstate
# 263 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 264 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_72
# 266 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_NONE
	goto_if_ne DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_73
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_4

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_65:
# 246 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_15
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_53

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_66:
# 248 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special IsChosenMonSteelType
# 249 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_76
# 252 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setstatus1 STATUS1_FREEZE, VAR_0x8004
# 253 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar 0x8007, GetSelectedMonNicknameAndSpecies
# 254 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	playmoncry 0x8007, 0
# 255 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitmoncry
# 256 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_17
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_53

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_69:
# 231 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_13
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_40

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_72:
# 265 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_18
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_4

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_73:
# 267 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special IsChosenMonSteelType
# 268 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_79
# 271 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special IsChosenMonPoisonType
# 272 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_82
# 275 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setstatus1 STATUS1_TOXIC_POISON, VAR_0x8004
# 276 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar 0x8007, GetSelectedMonNicknameAndSpecies
# 277 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	playmoncry 0x8007, 0
# 278 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitmoncry
# 279 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_21
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_4

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_76:
# 250 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_16
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_53

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_79:
# 269 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_19
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_4

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_82:
# 273 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_20
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_4


DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_0:
# 45 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Would you like to make a Nature Mint\n"
	.string "with a Blank Nature Mint?$"

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_1:
# 50 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "You do not have any Blank Nature Mints.$"

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_2:
# 52 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Which stat would you like the mint to\n"
	.string "increase?$"

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_3:
# 65 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Which stat would you like the mint to\n"
	.string "decrease?$"

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_4:
# 85 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want to make a Neutral\n"
	.string "Nature Mint?$"

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_5:
# 95 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "You would like to make a Lonely Nature\n"
	.string "Mint (+Atk -Def)?$"

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_6:
# 102 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "You would like to make an Adamant\n"
	.string "Nature Mint (+Atk -SpA)?$"

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_7:
# 109 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "You would like to make a Naughty Nature\n"
	.string "Mint (+Atk -SpD)?$"

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_8:
# 116 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "You would like to make a Brave Nature\n"
	.string "Mint (+Atk -Spe)?$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_0:
# 130 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Would you like to Pre-Damage or\n"
	.string "Pre-Status one of your Pokémon?$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_1:
# 143 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Which Status would you like to give the\n"
	.string "Pokémon?$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_2:
# 164 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "A Pokémon Egg cannot be Poisoned.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_3:
# 168 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Steel-type Pokémon cannot be\n"
	.string "Poisoned.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_4:
# 172 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Poison-type Pokémon cannot be\n"
	.string "Poisoned.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_5:
# 178 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Inflicted your {STR_VAR_1} with\n"
	.string "Poison.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_6:
# 188 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "A Pokémon Egg cannot be Paralyzed.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_7:
# 192 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Electric-type Pokémon cannot be\n"
	.string "Paralyzed.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_8:
# 198 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Inflicted your {STR_VAR_1} with\n"
	.string "Paralysis.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_9:
# 207 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "A Pokémon Egg cannot be put to Sleep.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_10:
# 212 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "{STR_VAR_1}'s ability prevents it\n"
	.string "from being put to Sleep.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_11:
# 218 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Inflicted your {STR_VAR_1} with\n"
	.string "Sleep.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_12:
# 227 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "A Pokémon Egg cannot be burned.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_13:
# 231 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Fire-type Pokémon cannot be Burned.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_14:
# 237 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Inflicted your {STR_VAR_1} with\n"
	.string "Burn.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_15:
# 246 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "A Pokémon Egg cannot be frozen.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_16:
# 250 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Ice-type Pokémon cannot be Frozen.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_17:
# 256 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Inflicted your {STR_VAR_1} with\n"
	.string "Freeze.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_18:
# 265 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "A Pokémon Egg cannot be Badly\n"
	.string "Poisoned.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_19:
# 269 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Steel-type Pokémon cannot be Badly\n"
	.string "Poisoned.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_20:
# 273 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Poison-type Pokémon cannot be Badly\n"
	.string "Poisoned.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_21:
# 279 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Inflicted your {STR_VAR_1} with\n"
	.string "Toxic Poison.$"
