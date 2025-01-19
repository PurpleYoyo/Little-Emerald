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
# 46 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_2
DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_1:
# 55 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_5
DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_4:
# 144 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	release
	return

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_2:
# 47 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special ChoosePartyMon
# 48 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitstate
# 49 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	call Common_SelectDamage
# 53 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	sethp 5, VAR_0x8004
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_1

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_5:
# 56 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	closemessage
# 57 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_1
# 58 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	multichoicegrid 5, 2, MULTI_STATUSES, 2, 0
# 59 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_8
DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_7:
# 73 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_11
DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_10:
# 87 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_18
DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_17:
# 101 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_24
DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_23:
# 115 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_30
DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_29:
# 129 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 5
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_35
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_4

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_8:
# 60 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special ChoosePartyMon
# 61 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitstate
# 62 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 63 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_13
# 65 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_NONE
	goto_if_ne DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_14
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_7

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_11:
# 74 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special ChoosePartyMon
# 75 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitstate
# 76 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 77 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_20
# 80 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setstatus1 STATUS1_PARALYSIS, VAR_0x8004
# 81 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar 0x8007, GetSelectedMonNicknameAndSpecies
# 82 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	playmoncry 0x8007, 0
# 83 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitmoncry
# 84 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_5
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_10

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_13:
# 64 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_2
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_7

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_14:
# 66 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setstatus1 STATUS1_POISON, VAR_0x8004
# 67 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar 0x8007, GetSelectedMonNicknameAndSpecies
# 68 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	playmoncry 0x8007, 0
# 69 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitmoncry
# 70 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_3
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_7

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_18:
# 88 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special ChoosePartyMon
# 89 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitstate
# 90 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 91 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_26
# 94 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setstatus1 STATUS1_SLEEP_TURN ( 1 ), VAR_0x8004
# 95 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar 0x8007, GetSelectedMonNicknameAndSpecies
# 96 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	playmoncry 0x8007, 0
# 97 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitmoncry
# 98 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_7
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_17

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_20:
# 78 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_4
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_10

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_24:
# 102 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special ChoosePartyMon
# 103 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitstate
# 104 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 105 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_32
# 108 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setstatus1 STATUS1_BURN, VAR_0x8004
# 109 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar 0x8007, GetSelectedMonNicknameAndSpecies
# 110 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	playmoncry 0x8007, 0
# 111 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitmoncry
# 112 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_9
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_23

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_26:
# 92 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_6
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_17

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_30:
# 116 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special ChoosePartyMon
# 117 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitstate
# 118 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 119 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_37
# 122 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setstatus1 STATUS1_FREEZE, VAR_0x8004
# 123 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar 0x8007, GetSelectedMonNicknameAndSpecies
# 124 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	playmoncry 0x8007, 0
# 125 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitmoncry
# 126 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_11
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_29

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_32:
# 106 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_8
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_23

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_35:
# 130 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	special ChoosePartyMon
# 131 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitstate
# 132 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 133 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_40
# 136 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	setstatus1 STATUS1_TOXIC_POISON, VAR_0x8004
# 137 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	specialvar 0x8007, GetSelectedMonNicknameAndSpecies
# 138 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	playmoncry 0x8007, 0
# 139 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	waitmoncry
# 140 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_13
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_4

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_37:
# 120 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_10
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_29

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_40:
# 134 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_12
	goto DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_4


DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_0:
# 44 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Would you like to Pre-Damage or\n"
	.string "Pre-Status one of your Pokémon?$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_1:
# 57 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Which Status would you like to give the\n"
	.string "Pokémon?$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_2:
# 64 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "I can't inflict a Pokémon egg with\n"
	.string "Poison.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_3:
# 70 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Inflicted your {STR_VAR_1} with\n"
	.string "Poison.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_4:
# 78 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "A Pokémon egg can't have Paralysis.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_5:
# 84 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Gave your {STR_VAR_1} Paralysis.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_6:
# 92 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "I can't put a Pokémon egg to Sleep.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_7:
# 98 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Put your {STR_VAR_1} to Sleep.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_8:
# 106 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "I can't Burn a Pokémon egg.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_9:
# 112 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Inflicted your {STR_VAR_1} with\n"
	.string "Burn.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_10:
# 120 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "I can't Freeze a Pokémon egg.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_11:
# 126 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Inflicted your {STR_VAR_1} with\n"
	.string "Freeze.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_12:
# 134 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "I can't inflict a Pokémon egg with\n"
	.string "Toxic.$"

DewfordTown_PokemonCenter_1F_EventScript_PreDamageNurse_Text_13:
# 140 "data/maps/DewfordTown_PokemonCenter_1F/scripts.pory"
	.string "Inflicted your {STR_VAR_1} with\n"
	.string "Toxic.$"
