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

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse::
# 43 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	lock
# 44 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	message DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_0
# 45 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	multichoice 5, 2, MULTI_PREDAMAGE, 0
# 47 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_2
DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_1:
# 111 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	release
	return

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_2:
# 48 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	closemessage
# 49 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_1
# 50 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	multichoice 5, 2, MULTI_STATUS_INFO, 0
# 51 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_5
DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_4:
# 66 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_8
DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_7:
# 77 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_14
DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_13:
# 88 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_20
DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_19:
# 99 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_25
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_1

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_5:
# 52 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special ChoosePartyMon
# 53 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitstate
# 54 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 55 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_10
# 59 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setstatus1 STATUS1_POISON, VAR_0x8004
# 60 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar 0x8007, GetSelectedMonNicknameAndSpecies
# 61 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	playmoncry 0x8007, 0
# 62 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitmoncry
# 63 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_3
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_4

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_8:
# 67 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special ChoosePartyMon
# 68 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitstate
# 69 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 70 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_16
# 74 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setstatus1 STATUS1_PARALYSIS, VAR_0x8004
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_7

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_10:
# 56 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	message DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_2
# 57 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	closemessage
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_4

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_14:
# 78 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special ChoosePartyMon
# 79 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitstate
# 80 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 81 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_22
# 85 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setstatus1 STATUS1_SLEEP, VAR_0x8004
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_13

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_16:
# 71 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	message DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_2
# 72 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	closemessage
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_7

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_20:
# 89 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special ChoosePartyMon
# 90 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitstate
# 91 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 92 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_27
# 96 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setstatus1 STATUS1_BURN, VAR_0x8004
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_19

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_22:
# 82 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	message DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_2
# 83 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	closemessage
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_13

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_25:
# 100 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special ChoosePartyMon
# 101 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitstate
# 102 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 103 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_30
# 107 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setstatus1 STATUS1_FREEZE, VAR_0x8004
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_1

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_27:
# 93 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	message DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_2
# 94 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	closemessage
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_19

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_30:
# 104 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	message DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_2
# 105 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	closemessage
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_1


DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_0:
# 44 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Would you like to Pre-Damage or\n"
	.string "Pre-Status one of your Pokémon?$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_1:
# 49 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Which Status would you like to give the\n"
	.string "Pokémon?$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_2:
# 56 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "egg$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_3:
# 63 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Inflicted your {STR_VAR_1} with\n"
	.string "Poison.$"
