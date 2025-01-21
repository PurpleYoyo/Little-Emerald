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
	yesnobox 8, 4
# 47 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_2
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_1:
# 50 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	checkitem ITEM_BLANK_MINT, 1
# 51 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_ne DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_5
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_4:
# 55 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_2
# 56 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	multichoicegrid 10, 4, MULTI_STAT_NAMES_NO_HP, 2, 0
# 57 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 5
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_8
# 60 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_9
# 63 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_10
# 66 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_11
# 69 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_12
# 72 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_13
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_7:
# 75 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_3
# 76 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	multichoicegrid 8, 4, MULTI_STAT_NAMES_NO_HP, 2, 0
# 77 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 5
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_21
# 80 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_22
# 83 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_23
# 86 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_24
# 89 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_25
# 92 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_26
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_20:
# 95 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare RAISE, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_36
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_35:
# 96 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare RAISE, 1
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_40
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_39:
# 97 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare RAISE, 2
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_44
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_43:
# 98 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare RAISE, 3
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_48
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_47:
# 99 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare RAISE, 4
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_51
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_33:
# 107 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	switch RAISE
# 108 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	case 0, DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_56
# 145 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	case 1, DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_57
# 182 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	case 2, DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_58
# 219 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	case 3, DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_59
# 256 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	case 4, DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_60
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_54:
# 294 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	closemessage
# 295 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	release
	return

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_2:
# 48 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_1

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_5:
# 52 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_1
# 53 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_4

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_8:
# 58 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_7

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_9:
# 61 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setvar RAISE, 0
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_7

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_10:
# 64 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setvar RAISE, 1
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_7

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_11:
# 67 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setvar RAISE, 2
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_7

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_12:
# 70 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setvar RAISE, 3
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_7

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_13:
# 73 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setvar RAISE, 4
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_7

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_21:
# 78 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_20

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_22:
# 81 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setvar LOWER, 0
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_20

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_23:
# 84 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setvar LOWER, 1
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_20

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_24:
# 87 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setvar LOWER, 2
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_20

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_25:
# 90 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setvar LOWER, 3
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_20

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_26:
# 93 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setvar LOWER, 4
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_20

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_34:
# 100 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	message DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_4
# 101 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	yesnobox 5, 2
# 102 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_61
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_33

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_36:
# 95 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare LOWER, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_34
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_35

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_40:
# 96 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare LOWER, 1
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_34
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_39

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_44:
# 97 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare LOWER, 2
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_34
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_43

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_48:
# 98 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare LOWER, 3
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_34
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_47

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_51:
# 99 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare LOWER, 4
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_34
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_33

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_56:
# 109 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	switch LOWER
# 110 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	case 1, DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_64
# 118 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	case 2, DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_65
# 126 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	case 3, DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_66
# 134 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	case 4, DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_67
# 143 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_54

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_57:
# 146 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	switch LOWER
# 147 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	case 0, DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_70
# 155 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	case 2, DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_71
# 163 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	case 3, DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_72
# 171 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	case 4, DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_73
# 180 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_54

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_58:
# 183 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	switch LOWER
# 184 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	case 0, DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_76
# 192 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	case 1, DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_77
# 200 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	case 3, DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_78
# 208 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	case 4, DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_79
# 217 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_54

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_59:
# 220 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	switch LOWER
# 221 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	case 0, DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_82
# 229 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	case 1, DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_83
# 237 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	case 2, DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_84
# 245 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	case 4, DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_85
# 254 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_54

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_60:
# 257 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	switch LOWER
# 258 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	case 0, DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_88
# 266 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	case 1, DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_89
# 274 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	case 2, DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_90
# 282 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	case 3, DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_91
# 291 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_54

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_61:
# 103 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_SERIOUS_MINT
# 104 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_33

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_64:
# 111 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	message DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_5
# 112 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	yesnobox 5, 2
# 113 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_94
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_93:
# 116 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_LONELY_MINT
# 117 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_54

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_65:
# 119 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	message DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_6
# 120 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	yesnobox 5, 2
# 121 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_97
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_96:
# 124 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_ADAMANT_MINT
# 125 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_54

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_66:
# 127 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	message DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_7
# 128 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	yesnobox 5, 2
# 129 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_100
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_99:
# 132 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_NAUGHTY_MINT
# 133 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_54

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_67:
# 135 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	message DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_8
# 136 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	yesnobox 5, 2
# 137 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_103
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_102:
# 140 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_BRAVE_MINT
# 141 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_54

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_70:
# 148 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	message DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_9
# 149 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	yesnobox 5, 2
# 150 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_106
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_105:
# 153 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_BOLD_MINT
# 154 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_54

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_71:
# 156 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	message DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_10
# 157 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	yesnobox 5, 2
# 158 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_109
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_108:
# 161 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_IMPISH_MINT
# 162 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_54

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_72:
# 164 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	message DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_11
# 165 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	yesnobox 5, 2
# 166 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_112
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_111:
# 169 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_LAX_MINT
# 170 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_54

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_73:
# 172 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	message DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_12
# 173 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	yesnobox 5, 2
# 174 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_115
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_114:
# 177 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_RELAXED_MINT
# 178 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_54

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_76:
# 185 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	message DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_13
# 186 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	yesnobox 5, 2
# 187 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_118
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_117:
# 190 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_MODEST_MINT
# 191 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_54

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_77:
# 193 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	message DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_14
# 194 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	yesnobox 5, 2
# 195 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_121
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_120:
# 198 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_MILD_MINT
# 199 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_54

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_78:
# 201 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	message DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_15
# 202 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	yesnobox 5, 2
# 203 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_124
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_123:
# 206 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_RASH_MINT
# 207 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_54

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_79:
# 209 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	message DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_16
# 210 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	yesnobox 5, 2
# 211 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_127
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_126:
# 214 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_QUIET_MINT
# 215 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_54

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_82:
# 222 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	message DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_17
# 223 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	yesnobox 5, 2
# 224 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_130
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_129:
# 227 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_CALM_MINT
# 228 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_54

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_83:
# 230 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	message DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_18
# 231 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	yesnobox 5, 2
# 232 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_133
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_132:
# 235 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_GENTLE_MINT
# 236 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_54

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_84:
# 238 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	message DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_19
# 239 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	yesnobox 5, 2
# 240 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_136
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_135:
# 243 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_CAREFUL_MINT
# 244 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_54

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_85:
# 246 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	message DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_20
# 247 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	yesnobox 5, 2
# 248 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_139
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_138:
# 251 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_SASSY_MINT
# 252 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_54

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_88:
# 259 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	message DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_21
# 260 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	yesnobox 5, 2
# 261 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_142
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_141:
# 264 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_TIMID_MINT
# 265 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_54

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_89:
# 267 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	message DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_22
# 268 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	yesnobox 5, 2
# 269 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_145
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_144:
# 272 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_HASTY_MINT
# 273 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_54

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_90:
# 275 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	message DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_23
# 276 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	yesnobox 5, 2
# 277 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_148
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_147:
# 280 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_JOLLY_MINT
# 281 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_54

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_91:
# 283 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	message DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_24
# 284 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	yesnobox 5, 2
# 285 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_151
DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_150:
# 288 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	giveitem ITEM_NAIVE_MINT
# 289 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_54

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_94:
# 114 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_93

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_97:
# 122 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_96

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_100:
# 130 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_99

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_103:
# 138 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_102

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_106:
# 151 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_105

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_109:
# 159 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_108

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_112:
# 167 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_111

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_115:
# 175 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_114

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_118:
# 188 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_117

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_121:
# 196 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_120

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_124:
# 204 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_123

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_127:
# 212 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_126

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_130:
# 225 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_129

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_133:
# 233 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_132

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_136:
# 241 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_135

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_139:
# 249 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_138

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_142:
# 262 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_141

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_145:
# 270 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_144

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_148:
# 278 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_147

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_151:
# 286 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_150


DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse::
# 299 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	lock
# 300 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_0
# 301 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	multichoice 10, 4, MULTI_PREDAMAGE, 0
# 302 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_2
# 322 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_3
DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_1:
# 444 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
End::
# 445 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	closemessage
# 446 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	release
	return

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_2:
# 303 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special ChoosePartyMon
# 304 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitstate
# 305 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 306 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_7
DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_6:
# 310 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special IsChosenMonFainted
# 311 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_13
DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_12:
# 315 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	call Common_ShowSelectDamageScreen
# 316 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitstate
# 317 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar 0x8007, GetSelectedMonNicknameAndSpecies
# 318 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	playmoncry 0x8007, 0
# 319 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitmoncry
# 320 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_3
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_1

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_3:
# 323 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special ChoosePartyMon
# 324 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitstate
# 325 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 326 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_10
DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_9:
# 330 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special IsChosenMonFainted
# 331 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_16
DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_15:
# 335 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_6
# 336 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	multichoicegrid 8, 4, MULTI_STATUSES, 2, 0
# 337 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_19
# 339 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_20
# 341 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_21
# 343 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_22
# 345 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_23
# 347 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 5
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_24
DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_18:
# 350 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	switch STATUS
# 351 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	case 0, DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_32
# 373 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	case 1, DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_33
# 384 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	case 2, DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_34
# 396 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	case 3, DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_35
# 407 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	case 4, DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_36
# 418 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	case 5, DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_37
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_1

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_7:
# 307 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_1
# 308 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_6

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_10:
# 327 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_4
# 328 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_9

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_13:
# 312 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_2
# 313 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_12

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_16:
# 332 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_5
# 333 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_15

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_19:
# 338 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setvar STATUS, 0
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_18

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_20:
# 340 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setvar STATUS, 1
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_18

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_21:
# 342 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setvar STATUS, 2
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_18

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_22:
# 344 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setvar STATUS, 3
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_18

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_23:
# 346 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setvar STATUS, 4
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_18

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_24:
# 348 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setvar STATUS, 5
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_18

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_32:
# 352 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special IsChosenMonSteelType
# 353 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_39
DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_38:
# 360 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special IsChosenMonPoisonType
# 361 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_57
DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_56:
# 368 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setstatus1 STATUS1_POISON, VAR_0x8004
# 369 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar 0x8007, GetSelectedMonNicknameAndSpecies
# 370 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	playmoncry 0x8007, 0
# 371 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitmoncry
# 372 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_9
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_1

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_33:
# 374 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special IsChosenMonElectricType
# 375 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_42
DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_41:
# 379 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setstatus1 STATUS1_PARALYSIS, VAR_0x8004
# 380 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar 0x8007, GetSelectedMonNicknameAndSpecies
# 381 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	playmoncry 0x8007, 0
# 382 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitmoncry
# 383 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_11
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_1

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_34:
# 385 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special IsChosenMonImmuneToSleepDueToAbility
# 386 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_45
DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_44:
# 391 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setstatus1 STATUS1_SLEEP_TURN ( 1 ), VAR_0x8004
# 392 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar 0x8007, GetSelectedMonNicknameAndSpecies
# 393 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	playmoncry 0x8007, 0
# 394 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitmoncry
# 395 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_13
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_1

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_35:
# 397 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special IsChosenMonFireType
# 398 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_48
DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_47:
# 402 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setstatus1 STATUS1_BURN, VAR_0x8004
# 403 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar 0x8007, GetSelectedMonNicknameAndSpecies
# 404 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	playmoncry 0x8007, 0
# 405 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitmoncry
# 406 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_15
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_1

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_36:
# 408 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special IsChosenMonIceType
# 409 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_51
DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_50:
# 413 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setstatus1 STATUS1_FREEZE, VAR_0x8004
# 414 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar 0x8007, GetSelectedMonNicknameAndSpecies
# 415 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	playmoncry 0x8007, 0
# 416 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitmoncry
# 417 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_17
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_1

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_37:
# 419 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special IsChosenMonSteelType
# 420 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_54
DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_53:
# 427 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special IsChosenMonPoisonType
# 428 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_62
DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_61:
# 435 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setstatus1 STATUS1_TOXIC_POISON, VAR_0x8004
# 436 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar 0x8007, GetSelectedMonNicknameAndSpecies
# 437 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	playmoncry 0x8007, 0
# 438 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitmoncry
# 439 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_20
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_1

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_39:
# 354 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	getseenmon 757
# 355 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_59
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_38

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_42:
# 376 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_10
# 377 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_41

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_45:
# 387 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar 0x8007, GetSelectedMonNicknameAndSpecies
# 388 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_12
# 389 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_44

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_48:
# 399 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_14
# 400 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_47

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_51:
# 410 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_16
# 411 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_50

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_54:
# 421 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	getseenmon 757
# 422 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_64
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_53

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_57:
# 362 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	getseenmon 757
# 363 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_66
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_56

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_59:
# 356 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_7
# 357 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_38

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_62:
# 429 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	getseenmon 757
# 430 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_68
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_61

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_64:
# 423 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_18
# 424 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_53

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_66:
# 364 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_8
# 365 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_56

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_68:
# 431 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_19
# 432 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	goto End
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_61


DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_0:
# 45 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Would you like to make a Nature Mint\n"
	.string "with a Blank Nature Mint?$"

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_1:
# 52 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "You do not have any Blank Nature Mints.$"

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_2:
# 55 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Which stat would you like the mint to\n"
	.string "increase?$"

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_3:
# 75 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Which stat would you like the mint to\n"
	.string "decrease?$"

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_4:
# 100 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Are you sure you want to make a Neutral\n"
	.string "Nature Mint?$"

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_5:
# 111 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "You would like to make a Lonely Nature\n"
	.string "Mint (+Atk -Def)?$"

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_6:
# 119 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "You would like to make an Adamant\n"
	.string "Nature Mint (+Atk -SpA)?$"

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_7:
# 127 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "You would like to make a Naughty Nature\n"
	.string "Mint (+Atk -SpD)?$"

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_8:
# 135 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "You would like to make a Brave Nature\n"
	.string "Mint (+Atk -Spe)?$"

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_9:
# 148 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "You would like to make a Bold Nature\n"
	.string "Mint (+Def -Atk)?$"

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_10:
# 156 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "You would like to make an Impish Nature\n"
	.string "Mint (+Def -SpA)?$"

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_11:
# 164 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "You would like to make a Lax Nature Mint\n"
	.string "(+Def -SpD)?$"

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_12:
# 172 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "You would like to make a Relaxed Nature\n"
	.string "Mint (+Def -Spe)?$"

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_13:
# 185 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "You would like to make a Modest Nature\n"
	.string "Mint (+SpA -Atk)?$"

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_14:
# 193 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "You would like to make a Mild Nature\n"
	.string "Mint (+SpA -Def)?$"

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_15:
# 201 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "You would like to make a Rash Nature\n"
	.string "Mint (+SpA -SpD)?$"

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_16:
# 209 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "You would like to make a Quiet Nature\n"
	.string "Mint (+SpA -Spe)?$"

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_17:
# 222 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "You would like to make a Calm Nature\n"
	.string "Mint (+SpD -Atk)?$"

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_18:
# 230 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "You would like to make a Gentle Nature\n"
	.string "Mint (+SpD -Def)?$"

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_19:
# 238 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "You would like to make a Careful Nature\n"
	.string "Mint (+SpD -SpA)?$"

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_20:
# 246 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "You would like to make a Sassy Nature\n"
	.string "Mint (+SpD -Spe)?$"

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_21:
# 259 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "You would like to make a Timid Nature\n"
	.string "Mint (+Spe -Atk)?$"

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_22:
# 267 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "You would like to make a Hasty Nature\n"
	.string "Mint (+Spe -Def)?$"

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_23:
# 275 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "You would like to make a Jolly Nature\n"
	.string "Mint (+Spe -SpA)?$"

DewfordTown_PokemonCenter_1F_EventScript_NatureMintNurse_Text_24:
# 283 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "You would like to make a Naive Nature\n"
	.string "Mint (+Spe -SpD)?$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_0:
# 300 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Would you like to Pre-Damage or\n"
	.string "Pre-Status one of your Pokémon?$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_1:
# 307 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "A Pokémon Egg cannot be Pre-Damaged.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_2:
# 312 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "A Fainted Pokémon cannot be\n"
	.string "Pre-Damaged.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_3:
# 320 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Set your {STR_VAR_1}'s HP to\n"
	.string "{STR_VAR_3}.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_4:
# 327 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "A Pokémon Egg cannot be Pre-Statused.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_5:
# 332 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "A Fainted Pokémon cannot be\n"
	.string "Pre-Statused.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_6:
# 335 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Which Status would you like to give the\n"
	.string "Pokémon?$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_7:
# 356 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Steel-type Pokémon cannot be\n"
	.string "Poisoned.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_8:
# 364 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Poison-type Pokémon cannot be\n"
	.string "Poisoned.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_9:
# 372 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Inflicted your {STR_VAR_1} with\n"
	.string "Poison.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_10:
# 376 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Electric-type Pokémon cannot be\n"
	.string "Paralyzed.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_11:
# 383 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Inflicted your {STR_VAR_1} with\n"
	.string "Paralysis.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_12:
# 388 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "{STR_VAR_1}'s ability prevents it\n"
	.string "from being put to Sleep.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_13:
# 395 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Inflicted your {STR_VAR_1} with\n"
	.string "Sleep.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_14:
# 399 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Fire-type Pokémon cannot be Burned.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_15:
# 406 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Inflicted your {STR_VAR_1} with\n"
	.string "Burn.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_16:
# 410 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Ice-type Pokémon cannot be Frozen.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_17:
# 417 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Inflicted your {STR_VAR_1} with\n"
	.string "Freeze.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_18:
# 423 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Steel-type Pokémon cannot be Badly\n"
	.string "Poisoned.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_19:
# 431 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Poison-type Pokémon cannot be Badly\n"
	.string "Poisoned.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_20:
# 439 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Inflicted your {STR_VAR_1} with\n"
	.string "Toxic Poison.$"
