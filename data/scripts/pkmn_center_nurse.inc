# 1 "data/scripts/pkmn_center_nurse.pory"

# 2 "data/scripts/pkmn_center_nurse.pory"
Common_EventScript_PkmnCenterNurse::
# 3 "data/scripts/pkmn_center_nurse.pory"
	lock
# 4 "data/scripts/pkmn_center_nurse.pory"
	faceplayer
# 5 "data/scripts/pkmn_center_nurse.pory"
	setvar VAR_0x8004, 0
# 6 "data/scripts/pkmn_center_nurse.pory"
	specialvar VAR_RESULT, CountPlayerTrainerStars
# 7 "data/scripts/pkmn_center_nurse.pory"
	goto_if_eq VAR_RESULT, 4, EventScript_PkmnCenterNurse_GoldCard
# 8 "data/scripts/pkmn_center_nurse.pory"

# 9 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_HealPkmn
# 10 "data/scripts/pkmn_center_nurse.pory"
	end
# 11 "data/scripts/pkmn_center_nurse.pory"

# 12 "data/scripts/pkmn_center_nurse.pory"
EventScript_PkmnCenterNurse_Goodbye::
# 13 "data/scripts/pkmn_center_nurse.pory"
	return
# 14 "data/scripts/pkmn_center_nurse.pory"

# 15 "data/scripts/pkmn_center_nurse.pory"
@ VAR_0x8004 is 1 when player has Gold Card; jumps are identical
# 16 "data/scripts/pkmn_center_nurse.pory"
EventScript_PkmnCenterNurse_HealPkmn::
# 17 "data/scripts/pkmn_center_nurse.pory"
	incrementgamestat GAME_STAT_USED_POKECENTER
# 18 "data/scripts/pkmn_center_nurse.pory"
	call EventScript_PkmnCenterNurse_TakeAndHealPkmn
# 19 "data/scripts/pkmn_center_nurse.pory"
	end
# 20 "data/scripts/pkmn_center_nurse.pory"

# 21 "data/scripts/pkmn_center_nurse.pory"
EventScript_PkmnCenterNurse_IllTakeYourPkmn::
# 22 "data/scripts/pkmn_center_nurse.pory"
	message gText_IllTakeYourPkmn
# 23 "data/scripts/pkmn_center_nurse.pory"
	return
# 24 "data/scripts/pkmn_center_nurse.pory"

# 25 "data/scripts/pkmn_center_nurse.pory"
EventScript_PkmnCenterNurse_IllTakeYourPkmn2::
# 26 "data/scripts/pkmn_center_nurse.pory"
	message gText_IllTakeYourPkmn2
# 27 "data/scripts/pkmn_center_nurse.pory"
	return
# 28 "data/scripts/pkmn_center_nurse.pory"

# 29 "data/scripts/pkmn_center_nurse.pory"
EventScript_PkmnCenterNurse_TakeAndHealPkmn::
# 30 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Turn @ Changed from Common_Movement_WalkInPlaceFasterLeft to force the follower to enter their Poké Ball
# 31 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 32 "data/scripts/pkmn_center_nurse.pory"
	dofieldeffect FLDEFF_POKECENTER_HEAL
# 33 "data/scripts/pkmn_center_nurse.pory"
.if OW_UNION_DISABLE_CHECK == FALSE && OW_FLAG_MOVE_UNION_ROOM_CHECK != 0
# 34 "data/scripts/pkmn_center_nurse.pory"
	setflag OW_FLAG_MOVE_UNION_ROOM_CHECK
# 35 "data/scripts/pkmn_center_nurse.pory"
	call CableClub_OnResume
# 36 "data/scripts/pkmn_center_nurse.pory"
	clearflag OW_FLAG_MOVE_UNION_ROOM_CHECK
# 37 "data/scripts/pkmn_center_nurse.pory"
.endif
# 38 "data/scripts/pkmn_center_nurse.pory"
	waitfieldeffect FLDEFF_POKECENTER_HEAL
# 39 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_0x800B, Common_Movement_WalkInPlaceFasterDown
# 40 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 41 "data/scripts/pkmn_center_nurse.pory"
	special HealPlayerParty
# 42 "data/scripts/pkmn_center_nurse.pory"
	callnative UpdateFollowingPokemon
# 43 "data/scripts/pkmn_center_nurse.pory"
	return
# 44 "data/scripts/pkmn_center_nurse.pory"

# 45 "data/scripts/pkmn_center_nurse.pory"
EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom::
# 46 "data/scripts/pkmn_center_nurse.pory"
	specialvar VAR_RESULT, PlayerNotAtTrainerHillEntrance
# 47 "data/scripts/pkmn_center_nurse.pory"
	goto_if_eq VAR_RESULT, 0, EventScript_PkmnCenterNurse_ReturnPkmn
# 48 "data/scripts/pkmn_center_nurse.pory"
	specialvar VAR_RESULT, BufferUnionRoomPlayerName
# 49 "data/scripts/pkmn_center_nurse.pory"
	copyvar VAR_0x8008, VAR_RESULT
# 50 "data/scripts/pkmn_center_nurse.pory"
	goto_if_eq VAR_0x8008, 0, EventScript_PkmnCenterNurse_ReturnPkmn
# 51 "data/scripts/pkmn_center_nurse.pory"
	goto_if_eq VAR_0x8008, 1, EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom
# 52 "data/scripts/pkmn_center_nurse.pory"
	end
# 53 "data/scripts/pkmn_center_nurse.pory"

# 54 "data/scripts/pkmn_center_nurse.pory"
@ VAR_0x8004 is 1 when player has Gold Card
# 55 "data/scripts/pkmn_center_nurse.pory"
EventScript_PkmnCenterNurse_ReturnPkmn::
# 56 "data/scripts/pkmn_center_nurse.pory"
	goto_if_eq VAR_0x8004, 1, EventScript_PkmnCenterNurse_ReturnPkmn2
# 57 "data/scripts/pkmn_center_nurse.pory"
	message gText_RestoredPkmnToFullHealth
# 58 "data/scripts/pkmn_center_nurse.pory"
	waitmessage
# 59 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
# 60 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 61 "data/scripts/pkmn_center_nurse.pory"
	message gText_WeHopeToSeeYouAgain
# 62 "data/scripts/pkmn_center_nurse.pory"
	return
# 63 "data/scripts/pkmn_center_nurse.pory"

# 64 "data/scripts/pkmn_center_nurse.pory"
EventScript_PkmnCenterNurse_ReturnPkmn2::
# 65 "data/scripts/pkmn_center_nurse.pory"
	message gText_ThankYouForWaiting
# 66 "data/scripts/pkmn_center_nurse.pory"
	waitmessage
# 67 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
# 68 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 69 "data/scripts/pkmn_center_nurse.pory"
	message gText_WeHopeToSeeYouAgain2
# 70 "data/scripts/pkmn_center_nurse.pory"
	return
# 71 "data/scripts/pkmn_center_nurse.pory"

# 72 "data/scripts/pkmn_center_nurse.pory"
EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom::
# 73 "data/scripts/pkmn_center_nurse.pory"
	goto_if_set FLAG_NURSE_UNION_ROOM_REMINDER, EventScript_PkmnCenterNurse_ReturnPkmn
# 74 "data/scripts/pkmn_center_nurse.pory"
	msgbox gText_RestoredPkmnToFullHealth, MSGBOX_DEFAULT
# 75 "data/scripts/pkmn_center_nurse.pory"
	setflag FLAG_NURSE_UNION_ROOM_REMINDER
# 76 "data/scripts/pkmn_center_nurse.pory"
	message CableClub_Text_PlayerIsWaiting
# 77 "data/scripts/pkmn_center_nurse.pory"
	waitmessage
# 78 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
# 79 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 80 "data/scripts/pkmn_center_nurse.pory"
	message gText_WeHopeToSeeYouAgain
# 81 "data/scripts/pkmn_center_nurse.pory"
	return
# 82 "data/scripts/pkmn_center_nurse.pory"

# 83 "data/scripts/pkmn_center_nurse.pory"
EventScript_PkmnCenterNurse_CheckPokerus::
# 84 "data/scripts/pkmn_center_nurse.pory"
	specialvar VAR_RESULT, IsPokerusInParty
# 85 "data/scripts/pkmn_center_nurse.pory"
	goto_if_eq VAR_RESULT, TRUE, EventScript_PkmnCenterNurse_ExplainPokerus
# 86 "data/scripts/pkmn_center_nurse.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom
# 87 "data/scripts/pkmn_center_nurse.pory"
	end
# 88 "data/scripts/pkmn_center_nurse.pory"

# 89 "data/scripts/pkmn_center_nurse.pory"
EventScript_PkmnCenterNurse_ExplainPokerus::
# 90 "data/scripts/pkmn_center_nurse.pory"
	message gText_PokerusExplanation
# 91 "data/scripts/pkmn_center_nurse.pory"
	setflag FLAG_POKERUS_EXPLAINED
# 92 "data/scripts/pkmn_center_nurse.pory"
	return
# 93 "data/scripts/pkmn_center_nurse.pory"

# 94 "data/scripts/pkmn_center_nurse.pory"
EventScript_PkmnCenterNurse_GoldCard::
# 95 "data/scripts/pkmn_center_nurse.pory"
	goto_if_set FLAG_NURSE_MENTIONS_GOLD_CARD, EventScript_PkmnCenterNurse_AskForUsual
# 96 "data/scripts/pkmn_center_nurse.pory"
	setflag FLAG_NURSE_MENTIONS_GOLD_CARD
# 97 "data/scripts/pkmn_center_nurse.pory"
	msgbox gText_WelcomeCutShort, MSGBOX_DEFAULT
# 98 "data/scripts/pkmn_center_nurse.pory"
	playse SE_PIN
# 99 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_0x800B, Common_Movement_ExclamationMark
# 100 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 101 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_0x800B, Common_Movement_Delay48
# 102 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 103 "data/scripts/pkmn_center_nurse.pory"
	msgbox gText_NoticesGoldCard, MSGBOX_YESNO
# 104 "data/scripts/pkmn_center_nurse.pory"
	goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_GoldCardHealPkmn
# 105 "data/scripts/pkmn_center_nurse.pory"
	message gText_WeHopeToSeeYouAgain2
# 106 "data/scripts/pkmn_center_nurse.pory"
	return
# 107 "data/scripts/pkmn_center_nurse.pory"

# 108 "data/scripts/pkmn_center_nurse.pory"
EventScript_PkmnCenterNurse_AskForUsual::
# 109 "data/scripts/pkmn_center_nurse.pory"
	msgbox gText_YouWantTheUsual, MSGBOX_YESNO
# 110 "data/scripts/pkmn_center_nurse.pory"
	goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_GoldCardHealPkmn
# 111 "data/scripts/pkmn_center_nurse.pory"
	message gText_WeHopeToSeeYouAgain2
# 112 "data/scripts/pkmn_center_nurse.pory"
	return
# 113 "data/scripts/pkmn_center_nurse.pory"

# 114 "data/scripts/pkmn_center_nurse.pory"
EventScript_PkmnCenterNurse_GoldCardHealPkmn::
# 115 "data/scripts/pkmn_center_nurse.pory"
	setvar VAR_0x8004, 1
# 116 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_HealPkmn
# 117 "data/scripts/pkmn_center_nurse.pory"
	end
# 118 "data/scripts/pkmn_center_nurse.pory"

# 119 "data/scripts/pkmn_center_nurse.pory"
Movement_PkmnCenterNurse_Bow:
# 120 "data/scripts/pkmn_center_nurse.pory"
	nurse_joy_bow
# 121 "data/scripts/pkmn_center_nurse.pory"
	delay_4
# 122 "data/scripts/pkmn_center_nurse.pory"
	step_end
# 123 "data/scripts/pkmn_center_nurse.pory"

# 124 "data/scripts/pkmn_center_nurse.pory"
Movement_PkmnCenterNurse_Turn:
# 125 "data/scripts/pkmn_center_nurse.pory"
	walk_in_place_faster_left
# 126 "data/scripts/pkmn_center_nurse.pory"
	step_end

EventScript_NatureMintNPC::
# 130 "data/scripts/pkmn_center_nurse.pory"
	lock
# 131 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_NatureMintNPC_Text_0
# 132 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 8, 4
# 133 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq EventScript_NatureMintNPC_2
EventScript_NatureMintNPC_1:
# 136 "data/scripts/pkmn_center_nurse.pory"
	checkitem ITEM_BLANK_MINT, 1
# 137 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 1
	goto_if_ne EventScript_NatureMintNPC_5
EventScript_NatureMintNPC_4:
# 141 "data/scripts/pkmn_center_nurse.pory"
	msgbox EventScript_NatureMintNPC_Text_2
# 142 "data/scripts/pkmn_center_nurse.pory"
	multichoicegrid 10, 4, MULTI_STAT_NAMES_NO_HP, 2, 0
# 143 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 5
	goto_if_eq EventScript_NatureMintNPC_8
# 146 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq EventScript_NatureMintNPC_9
# 149 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 1
	goto_if_eq EventScript_NatureMintNPC_10
# 152 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 2
	goto_if_eq EventScript_NatureMintNPC_11
# 155 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 3
	goto_if_eq EventScript_NatureMintNPC_12
# 158 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 4
	goto_if_eq EventScript_NatureMintNPC_13
EventScript_NatureMintNPC_7:
# 161 "data/scripts/pkmn_center_nurse.pory"
	msgbox EventScript_NatureMintNPC_Text_3
# 162 "data/scripts/pkmn_center_nurse.pory"
	multichoicegrid 8, 4, MULTI_STAT_NAMES_NO_HP, 2, 0
# 163 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 5
	goto_if_eq EventScript_NatureMintNPC_21
# 166 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq EventScript_NatureMintNPC_22
# 169 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 1
	goto_if_eq EventScript_NatureMintNPC_23
# 172 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 2
	goto_if_eq EventScript_NatureMintNPC_24
# 175 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 3
	goto_if_eq EventScript_NatureMintNPC_25
# 178 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 4
	goto_if_eq EventScript_NatureMintNPC_26
EventScript_NatureMintNPC_20:
# 181 "data/scripts/pkmn_center_nurse.pory"
	compare RAISE, 0
	goto_if_eq EventScript_NatureMintNPC_36
EventScript_NatureMintNPC_35:
# 182 "data/scripts/pkmn_center_nurse.pory"
	compare RAISE, 1
	goto_if_eq EventScript_NatureMintNPC_40
EventScript_NatureMintNPC_39:
# 183 "data/scripts/pkmn_center_nurse.pory"
	compare RAISE, 2
	goto_if_eq EventScript_NatureMintNPC_44
EventScript_NatureMintNPC_43:
# 184 "data/scripts/pkmn_center_nurse.pory"
	compare RAISE, 3
	goto_if_eq EventScript_NatureMintNPC_48
EventScript_NatureMintNPC_47:
# 185 "data/scripts/pkmn_center_nurse.pory"
	compare RAISE, 4
	goto_if_eq EventScript_NatureMintNPC_51
EventScript_NatureMintNPC_33:
# 193 "data/scripts/pkmn_center_nurse.pory"
	switch RAISE
# 194 "data/scripts/pkmn_center_nurse.pory"
	case 0, EventScript_NatureMintNPC_56
# 231 "data/scripts/pkmn_center_nurse.pory"
	case 1, EventScript_NatureMintNPC_57
# 268 "data/scripts/pkmn_center_nurse.pory"
	case 2, EventScript_NatureMintNPC_58
# 305 "data/scripts/pkmn_center_nurse.pory"
	case 3, EventScript_NatureMintNPC_59
# 342 "data/scripts/pkmn_center_nurse.pory"
	case 4, EventScript_NatureMintNPC_60
EventScript_NatureMintNPC_54:
# 380 "data/scripts/pkmn_center_nurse.pory"
	goto End
	return

EventScript_NatureMintNPC_2:
# 134 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_NatureMintNPC_1

EventScript_NatureMintNPC_5:
# 138 "data/scripts/pkmn_center_nurse.pory"
	msgbox EventScript_NatureMintNPC_Text_1
# 139 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_NatureMintNPC_4

EventScript_NatureMintNPC_8:
# 144 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_NatureMintNPC_7

EventScript_NatureMintNPC_9:
# 147 "data/scripts/pkmn_center_nurse.pory"
	setvar RAISE, 0
	goto EventScript_NatureMintNPC_7

EventScript_NatureMintNPC_10:
# 150 "data/scripts/pkmn_center_nurse.pory"
	setvar RAISE, 1
	goto EventScript_NatureMintNPC_7

EventScript_NatureMintNPC_11:
# 153 "data/scripts/pkmn_center_nurse.pory"
	setvar RAISE, 2
	goto EventScript_NatureMintNPC_7

EventScript_NatureMintNPC_12:
# 156 "data/scripts/pkmn_center_nurse.pory"
	setvar RAISE, 3
	goto EventScript_NatureMintNPC_7

EventScript_NatureMintNPC_13:
# 159 "data/scripts/pkmn_center_nurse.pory"
	setvar RAISE, 4
	goto EventScript_NatureMintNPC_7

EventScript_NatureMintNPC_21:
# 164 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_NatureMintNPC_20

EventScript_NatureMintNPC_22:
# 167 "data/scripts/pkmn_center_nurse.pory"
	setvar LOWER, 0
	goto EventScript_NatureMintNPC_20

EventScript_NatureMintNPC_23:
# 170 "data/scripts/pkmn_center_nurse.pory"
	setvar LOWER, 1
	goto EventScript_NatureMintNPC_20

EventScript_NatureMintNPC_24:
# 173 "data/scripts/pkmn_center_nurse.pory"
	setvar LOWER, 2
	goto EventScript_NatureMintNPC_20

EventScript_NatureMintNPC_25:
# 176 "data/scripts/pkmn_center_nurse.pory"
	setvar LOWER, 3
	goto EventScript_NatureMintNPC_20

EventScript_NatureMintNPC_26:
# 179 "data/scripts/pkmn_center_nurse.pory"
	setvar LOWER, 4
	goto EventScript_NatureMintNPC_20

EventScript_NatureMintNPC_34:
# 186 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_NatureMintNPC_Text_4
# 187 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 5, 2
# 188 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 1
	goto_if_eq EventScript_NatureMintNPC_61
	goto EventScript_NatureMintNPC_33

EventScript_NatureMintNPC_36:
# 181 "data/scripts/pkmn_center_nurse.pory"
	compare LOWER, 0
	goto_if_eq EventScript_NatureMintNPC_34
	goto EventScript_NatureMintNPC_35

EventScript_NatureMintNPC_40:
# 182 "data/scripts/pkmn_center_nurse.pory"
	compare LOWER, 1
	goto_if_eq EventScript_NatureMintNPC_34
	goto EventScript_NatureMintNPC_39

EventScript_NatureMintNPC_44:
# 183 "data/scripts/pkmn_center_nurse.pory"
	compare LOWER, 2
	goto_if_eq EventScript_NatureMintNPC_34
	goto EventScript_NatureMintNPC_43

EventScript_NatureMintNPC_48:
# 184 "data/scripts/pkmn_center_nurse.pory"
	compare LOWER, 3
	goto_if_eq EventScript_NatureMintNPC_34
	goto EventScript_NatureMintNPC_47

EventScript_NatureMintNPC_51:
# 185 "data/scripts/pkmn_center_nurse.pory"
	compare LOWER, 4
	goto_if_eq EventScript_NatureMintNPC_34
	goto EventScript_NatureMintNPC_33

EventScript_NatureMintNPC_56:
# 195 "data/scripts/pkmn_center_nurse.pory"
	switch LOWER
# 196 "data/scripts/pkmn_center_nurse.pory"
	case 1, EventScript_NatureMintNPC_64
# 204 "data/scripts/pkmn_center_nurse.pory"
	case 2, EventScript_NatureMintNPC_65
# 212 "data/scripts/pkmn_center_nurse.pory"
	case 3, EventScript_NatureMintNPC_66
# 220 "data/scripts/pkmn_center_nurse.pory"
	case 4, EventScript_NatureMintNPC_67
# 229 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_NatureMintNPC_54

EventScript_NatureMintNPC_57:
# 232 "data/scripts/pkmn_center_nurse.pory"
	switch LOWER
# 233 "data/scripts/pkmn_center_nurse.pory"
	case 0, EventScript_NatureMintNPC_70
# 241 "data/scripts/pkmn_center_nurse.pory"
	case 2, EventScript_NatureMintNPC_71
# 249 "data/scripts/pkmn_center_nurse.pory"
	case 3, EventScript_NatureMintNPC_72
# 257 "data/scripts/pkmn_center_nurse.pory"
	case 4, EventScript_NatureMintNPC_73
# 266 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_NatureMintNPC_54

EventScript_NatureMintNPC_58:
# 269 "data/scripts/pkmn_center_nurse.pory"
	switch LOWER
# 270 "data/scripts/pkmn_center_nurse.pory"
	case 0, EventScript_NatureMintNPC_76
# 278 "data/scripts/pkmn_center_nurse.pory"
	case 1, EventScript_NatureMintNPC_77
# 286 "data/scripts/pkmn_center_nurse.pory"
	case 3, EventScript_NatureMintNPC_78
# 294 "data/scripts/pkmn_center_nurse.pory"
	case 4, EventScript_NatureMintNPC_79
# 303 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_NatureMintNPC_54

EventScript_NatureMintNPC_59:
# 306 "data/scripts/pkmn_center_nurse.pory"
	switch LOWER
# 307 "data/scripts/pkmn_center_nurse.pory"
	case 0, EventScript_NatureMintNPC_82
# 315 "data/scripts/pkmn_center_nurse.pory"
	case 1, EventScript_NatureMintNPC_83
# 323 "data/scripts/pkmn_center_nurse.pory"
	case 2, EventScript_NatureMintNPC_84
# 331 "data/scripts/pkmn_center_nurse.pory"
	case 4, EventScript_NatureMintNPC_85
# 340 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_NatureMintNPC_54

EventScript_NatureMintNPC_60:
# 343 "data/scripts/pkmn_center_nurse.pory"
	switch LOWER
# 344 "data/scripts/pkmn_center_nurse.pory"
	case 0, EventScript_NatureMintNPC_88
# 352 "data/scripts/pkmn_center_nurse.pory"
	case 1, EventScript_NatureMintNPC_89
# 360 "data/scripts/pkmn_center_nurse.pory"
	case 2, EventScript_NatureMintNPC_90
# 368 "data/scripts/pkmn_center_nurse.pory"
	case 3, EventScript_NatureMintNPC_91
# 377 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_NatureMintNPC_54

EventScript_NatureMintNPC_61:
# 189 "data/scripts/pkmn_center_nurse.pory"
	giveitem ITEM_SERIOUS_MINT
# 190 "data/scripts/pkmn_center_nurse.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto EventScript_NatureMintNPC_33

EventScript_NatureMintNPC_64:
# 197 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_NatureMintNPC_Text_5
# 198 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 5, 2
# 199 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq EventScript_NatureMintNPC_94
EventScript_NatureMintNPC_93:
# 202 "data/scripts/pkmn_center_nurse.pory"
	giveitem ITEM_LONELY_MINT
# 203 "data/scripts/pkmn_center_nurse.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto EventScript_NatureMintNPC_54

EventScript_NatureMintNPC_65:
# 205 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_NatureMintNPC_Text_6
# 206 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 5, 2
# 207 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq EventScript_NatureMintNPC_97
EventScript_NatureMintNPC_96:
# 210 "data/scripts/pkmn_center_nurse.pory"
	giveitem ITEM_ADAMANT_MINT
# 211 "data/scripts/pkmn_center_nurse.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto EventScript_NatureMintNPC_54

EventScript_NatureMintNPC_66:
# 213 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_NatureMintNPC_Text_7
# 214 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 5, 2
# 215 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq EventScript_NatureMintNPC_100
EventScript_NatureMintNPC_99:
# 218 "data/scripts/pkmn_center_nurse.pory"
	giveitem ITEM_NAUGHTY_MINT
# 219 "data/scripts/pkmn_center_nurse.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto EventScript_NatureMintNPC_54

EventScript_NatureMintNPC_67:
# 221 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_NatureMintNPC_Text_8
# 222 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 5, 2
# 223 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq EventScript_NatureMintNPC_103
EventScript_NatureMintNPC_102:
# 226 "data/scripts/pkmn_center_nurse.pory"
	giveitem ITEM_BRAVE_MINT
# 227 "data/scripts/pkmn_center_nurse.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto EventScript_NatureMintNPC_54

EventScript_NatureMintNPC_70:
# 234 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_NatureMintNPC_Text_9
# 235 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 5, 2
# 236 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq EventScript_NatureMintNPC_106
EventScript_NatureMintNPC_105:
# 239 "data/scripts/pkmn_center_nurse.pory"
	giveitem ITEM_BOLD_MINT
# 240 "data/scripts/pkmn_center_nurse.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto EventScript_NatureMintNPC_54

EventScript_NatureMintNPC_71:
# 242 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_NatureMintNPC_Text_10
# 243 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 5, 2
# 244 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq EventScript_NatureMintNPC_109
EventScript_NatureMintNPC_108:
# 247 "data/scripts/pkmn_center_nurse.pory"
	giveitem ITEM_IMPISH_MINT
# 248 "data/scripts/pkmn_center_nurse.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto EventScript_NatureMintNPC_54

EventScript_NatureMintNPC_72:
# 250 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_NatureMintNPC_Text_11
# 251 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 5, 2
# 252 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq EventScript_NatureMintNPC_112
EventScript_NatureMintNPC_111:
# 255 "data/scripts/pkmn_center_nurse.pory"
	giveitem ITEM_LAX_MINT
# 256 "data/scripts/pkmn_center_nurse.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto EventScript_NatureMintNPC_54

EventScript_NatureMintNPC_73:
# 258 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_NatureMintNPC_Text_12
# 259 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 5, 2
# 260 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq EventScript_NatureMintNPC_115
EventScript_NatureMintNPC_114:
# 263 "data/scripts/pkmn_center_nurse.pory"
	giveitem ITEM_RELAXED_MINT
# 264 "data/scripts/pkmn_center_nurse.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto EventScript_NatureMintNPC_54

EventScript_NatureMintNPC_76:
# 271 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_NatureMintNPC_Text_13
# 272 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 5, 2
# 273 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq EventScript_NatureMintNPC_118
EventScript_NatureMintNPC_117:
# 276 "data/scripts/pkmn_center_nurse.pory"
	giveitem ITEM_MODEST_MINT
# 277 "data/scripts/pkmn_center_nurse.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto EventScript_NatureMintNPC_54

EventScript_NatureMintNPC_77:
# 279 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_NatureMintNPC_Text_14
# 280 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 5, 2
# 281 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq EventScript_NatureMintNPC_121
EventScript_NatureMintNPC_120:
# 284 "data/scripts/pkmn_center_nurse.pory"
	giveitem ITEM_MILD_MINT
# 285 "data/scripts/pkmn_center_nurse.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto EventScript_NatureMintNPC_54

EventScript_NatureMintNPC_78:
# 287 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_NatureMintNPC_Text_15
# 288 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 5, 2
# 289 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq EventScript_NatureMintNPC_124
EventScript_NatureMintNPC_123:
# 292 "data/scripts/pkmn_center_nurse.pory"
	giveitem ITEM_RASH_MINT
# 293 "data/scripts/pkmn_center_nurse.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto EventScript_NatureMintNPC_54

EventScript_NatureMintNPC_79:
# 295 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_NatureMintNPC_Text_16
# 296 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 5, 2
# 297 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq EventScript_NatureMintNPC_127
EventScript_NatureMintNPC_126:
# 300 "data/scripts/pkmn_center_nurse.pory"
	giveitem ITEM_QUIET_MINT
# 301 "data/scripts/pkmn_center_nurse.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto EventScript_NatureMintNPC_54

EventScript_NatureMintNPC_82:
# 308 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_NatureMintNPC_Text_17
# 309 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 5, 2
# 310 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq EventScript_NatureMintNPC_130
EventScript_NatureMintNPC_129:
# 313 "data/scripts/pkmn_center_nurse.pory"
	giveitem ITEM_CALM_MINT
# 314 "data/scripts/pkmn_center_nurse.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto EventScript_NatureMintNPC_54

EventScript_NatureMintNPC_83:
# 316 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_NatureMintNPC_Text_18
# 317 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 5, 2
# 318 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq EventScript_NatureMintNPC_133
EventScript_NatureMintNPC_132:
# 321 "data/scripts/pkmn_center_nurse.pory"
	giveitem ITEM_GENTLE_MINT
# 322 "data/scripts/pkmn_center_nurse.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto EventScript_NatureMintNPC_54

EventScript_NatureMintNPC_84:
# 324 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_NatureMintNPC_Text_19
# 325 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 5, 2
# 326 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq EventScript_NatureMintNPC_136
EventScript_NatureMintNPC_135:
# 329 "data/scripts/pkmn_center_nurse.pory"
	giveitem ITEM_CAREFUL_MINT
# 330 "data/scripts/pkmn_center_nurse.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto EventScript_NatureMintNPC_54

EventScript_NatureMintNPC_85:
# 332 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_NatureMintNPC_Text_20
# 333 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 5, 2
# 334 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq EventScript_NatureMintNPC_139
EventScript_NatureMintNPC_138:
# 337 "data/scripts/pkmn_center_nurse.pory"
	giveitem ITEM_SASSY_MINT
# 338 "data/scripts/pkmn_center_nurse.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto EventScript_NatureMintNPC_54

EventScript_NatureMintNPC_88:
# 345 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_NatureMintNPC_Text_21
# 346 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 5, 2
# 347 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq EventScript_NatureMintNPC_142
EventScript_NatureMintNPC_141:
# 350 "data/scripts/pkmn_center_nurse.pory"
	giveitem ITEM_TIMID_MINT
# 351 "data/scripts/pkmn_center_nurse.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto EventScript_NatureMintNPC_54

EventScript_NatureMintNPC_89:
# 353 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_NatureMintNPC_Text_22
# 354 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 5, 2
# 355 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq EventScript_NatureMintNPC_145
EventScript_NatureMintNPC_144:
# 358 "data/scripts/pkmn_center_nurse.pory"
	giveitem ITEM_HASTY_MINT
# 359 "data/scripts/pkmn_center_nurse.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto EventScript_NatureMintNPC_54

EventScript_NatureMintNPC_90:
# 361 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_NatureMintNPC_Text_23
# 362 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 5, 2
# 363 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq EventScript_NatureMintNPC_148
EventScript_NatureMintNPC_147:
# 366 "data/scripts/pkmn_center_nurse.pory"
	giveitem ITEM_JOLLY_MINT
# 367 "data/scripts/pkmn_center_nurse.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto EventScript_NatureMintNPC_54

EventScript_NatureMintNPC_91:
# 369 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_NatureMintNPC_Text_24
# 370 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 5, 2
# 371 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq EventScript_NatureMintNPC_151
EventScript_NatureMintNPC_150:
# 374 "data/scripts/pkmn_center_nurse.pory"
	giveitem ITEM_NAIVE_MINT
# 375 "data/scripts/pkmn_center_nurse.pory"
	removeitem ITEM_BLANK_MINT, 1
	goto EventScript_NatureMintNPC_54

EventScript_NatureMintNPC_94:
# 200 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_NatureMintNPC_93

EventScript_NatureMintNPC_97:
# 208 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_NatureMintNPC_96

EventScript_NatureMintNPC_100:
# 216 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_NatureMintNPC_99

EventScript_NatureMintNPC_103:
# 224 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_NatureMintNPC_102

EventScript_NatureMintNPC_106:
# 237 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_NatureMintNPC_105

EventScript_NatureMintNPC_109:
# 245 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_NatureMintNPC_108

EventScript_NatureMintNPC_112:
# 253 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_NatureMintNPC_111

EventScript_NatureMintNPC_115:
# 261 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_NatureMintNPC_114

EventScript_NatureMintNPC_118:
# 274 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_NatureMintNPC_117

EventScript_NatureMintNPC_121:
# 282 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_NatureMintNPC_120

EventScript_NatureMintNPC_124:
# 290 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_NatureMintNPC_123

EventScript_NatureMintNPC_127:
# 298 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_NatureMintNPC_126

EventScript_NatureMintNPC_130:
# 311 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_NatureMintNPC_129

EventScript_NatureMintNPC_133:
# 319 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_NatureMintNPC_132

EventScript_NatureMintNPC_136:
# 327 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_NatureMintNPC_135

EventScript_NatureMintNPC_139:
# 335 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_NatureMintNPC_138

EventScript_NatureMintNPC_142:
# 348 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_NatureMintNPC_141

EventScript_NatureMintNPC_145:
# 356 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_NatureMintNPC_144

EventScript_NatureMintNPC_148:
# 364 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_NatureMintNPC_147

EventScript_NatureMintNPC_151:
# 372 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_NatureMintNPC_150


EventScript_PreDamageNPC::
# 384 "data/scripts/pkmn_center_nurse.pory"
	lock
# 385 "data/scripts/pkmn_center_nurse.pory"
	msgbox EventScript_PreDamageNPC_Text_0
# 386 "data/scripts/pkmn_center_nurse.pory"
	multichoice 10, 4, MULTI_PREDAMAGE, 0
# 387 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq EventScript_PreDamageNPC_2
# 407 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 1
	goto_if_eq EventScript_PreDamageNPC_3
EventScript_PreDamageNPC_1:
# 529 "data/scripts/pkmn_center_nurse.pory"
	goto End
	return

EventScript_PreDamageNPC_2:
# 388 "data/scripts/pkmn_center_nurse.pory"
	special ChoosePartyMon
# 389 "data/scripts/pkmn_center_nurse.pory"
	waitstate
# 390 "data/scripts/pkmn_center_nurse.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 391 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq EventScript_PreDamageNPC_7
EventScript_PreDamageNPC_6:
# 395 "data/scripts/pkmn_center_nurse.pory"
	special IsChosenMonFainted
# 396 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_PreDamageNPC_13
EventScript_PreDamageNPC_12:
# 400 "data/scripts/pkmn_center_nurse.pory"
	call Common_ShowSelectDamageScreen
# 401 "data/scripts/pkmn_center_nurse.pory"
	waitstate
# 402 "data/scripts/pkmn_center_nurse.pory"
	specialvar 0x8007, GetSelectedMonNicknameAndSpecies
# 403 "data/scripts/pkmn_center_nurse.pory"
	playmoncry 0x8007, 0
# 404 "data/scripts/pkmn_center_nurse.pory"
	waitmoncry
# 405 "data/scripts/pkmn_center_nurse.pory"
	msgbox EventScript_PreDamageNPC_Text_3
	goto EventScript_PreDamageNPC_1

EventScript_PreDamageNPC_3:
# 408 "data/scripts/pkmn_center_nurse.pory"
	special ChoosePartyMon
# 409 "data/scripts/pkmn_center_nurse.pory"
	waitstate
# 410 "data/scripts/pkmn_center_nurse.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 411 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq EventScript_PreDamageNPC_10
EventScript_PreDamageNPC_9:
# 415 "data/scripts/pkmn_center_nurse.pory"
	special IsChosenMonFainted
# 416 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_PreDamageNPC_16
EventScript_PreDamageNPC_15:
# 420 "data/scripts/pkmn_center_nurse.pory"
	msgbox EventScript_PreDamageNPC_Text_6
# 421 "data/scripts/pkmn_center_nurse.pory"
	multichoicegrid 8, 4, MULTI_STATUSES, 2, 0
# 422 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq EventScript_PreDamageNPC_19
# 424 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 1
	goto_if_eq EventScript_PreDamageNPC_20
# 426 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 2
	goto_if_eq EventScript_PreDamageNPC_21
# 428 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 3
	goto_if_eq EventScript_PreDamageNPC_22
# 430 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 4
	goto_if_eq EventScript_PreDamageNPC_23
# 432 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 5
	goto_if_eq EventScript_PreDamageNPC_24
EventScript_PreDamageNPC_18:
# 435 "data/scripts/pkmn_center_nurse.pory"
	switch STATUS
# 436 "data/scripts/pkmn_center_nurse.pory"
	case 0, EventScript_PreDamageNPC_32
# 458 "data/scripts/pkmn_center_nurse.pory"
	case 1, EventScript_PreDamageNPC_33
# 469 "data/scripts/pkmn_center_nurse.pory"
	case 2, EventScript_PreDamageNPC_34
# 481 "data/scripts/pkmn_center_nurse.pory"
	case 3, EventScript_PreDamageNPC_35
# 492 "data/scripts/pkmn_center_nurse.pory"
	case 4, EventScript_PreDamageNPC_36
# 503 "data/scripts/pkmn_center_nurse.pory"
	case 5, EventScript_PreDamageNPC_37
# 526 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_PreDamageNPC_1

EventScript_PreDamageNPC_7:
# 392 "data/scripts/pkmn_center_nurse.pory"
	msgbox EventScript_PreDamageNPC_Text_1
# 393 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_PreDamageNPC_6

EventScript_PreDamageNPC_10:
# 412 "data/scripts/pkmn_center_nurse.pory"
	msgbox EventScript_PreDamageNPC_Text_4
# 413 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_PreDamageNPC_9

EventScript_PreDamageNPC_13:
# 397 "data/scripts/pkmn_center_nurse.pory"
	msgbox EventScript_PreDamageNPC_Text_2
# 398 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_PreDamageNPC_12

EventScript_PreDamageNPC_16:
# 417 "data/scripts/pkmn_center_nurse.pory"
	msgbox EventScript_PreDamageNPC_Text_5
# 418 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_PreDamageNPC_15

EventScript_PreDamageNPC_19:
# 423 "data/scripts/pkmn_center_nurse.pory"
	setvar STATUS, 0
	goto EventScript_PreDamageNPC_18

EventScript_PreDamageNPC_20:
# 425 "data/scripts/pkmn_center_nurse.pory"
	setvar STATUS, 1
	goto EventScript_PreDamageNPC_18

EventScript_PreDamageNPC_21:
# 427 "data/scripts/pkmn_center_nurse.pory"
	setvar STATUS, 2
	goto EventScript_PreDamageNPC_18

EventScript_PreDamageNPC_22:
# 429 "data/scripts/pkmn_center_nurse.pory"
	setvar STATUS, 3
	goto EventScript_PreDamageNPC_18

EventScript_PreDamageNPC_23:
# 431 "data/scripts/pkmn_center_nurse.pory"
	setvar STATUS, 4
	goto EventScript_PreDamageNPC_18

EventScript_PreDamageNPC_24:
# 433 "data/scripts/pkmn_center_nurse.pory"
	setvar STATUS, 5
	goto EventScript_PreDamageNPC_18

EventScript_PreDamageNPC_32:
# 437 "data/scripts/pkmn_center_nurse.pory"
	special IsChosenMonSteelType
# 438 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_PreDamageNPC_40
EventScript_PreDamageNPC_39:
# 445 "data/scripts/pkmn_center_nurse.pory"
	special IsChosenMonPoisonType
# 446 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_PreDamageNPC_58
EventScript_PreDamageNPC_57:
# 453 "data/scripts/pkmn_center_nurse.pory"
	setstatus1 STATUS1_POISON, VAR_0x8004
# 454 "data/scripts/pkmn_center_nurse.pory"
	specialvar 0x8007, GetSelectedMonNicknameAndSpecies
# 455 "data/scripts/pkmn_center_nurse.pory"
	playmoncry 0x8007, 0
# 456 "data/scripts/pkmn_center_nurse.pory"
	waitmoncry
# 457 "data/scripts/pkmn_center_nurse.pory"
	msgbox EventScript_PreDamageNPC_Text_9
	goto EventScript_PreDamageNPC_1

EventScript_PreDamageNPC_33:
# 459 "data/scripts/pkmn_center_nurse.pory"
	special IsChosenMonElectricType
# 460 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_PreDamageNPC_43
EventScript_PreDamageNPC_42:
# 464 "data/scripts/pkmn_center_nurse.pory"
	setstatus1 STATUS1_PARALYSIS, VAR_0x8004
# 465 "data/scripts/pkmn_center_nurse.pory"
	specialvar 0x8007, GetSelectedMonNicknameAndSpecies
# 466 "data/scripts/pkmn_center_nurse.pory"
	playmoncry 0x8007, 0
# 467 "data/scripts/pkmn_center_nurse.pory"
	waitmoncry
# 468 "data/scripts/pkmn_center_nurse.pory"
	msgbox EventScript_PreDamageNPC_Text_11
	goto EventScript_PreDamageNPC_1

EventScript_PreDamageNPC_34:
# 470 "data/scripts/pkmn_center_nurse.pory"
	special IsChosenMonImmuneToSleepDueToAbility
# 471 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_PreDamageNPC_46
EventScript_PreDamageNPC_45:
# 476 "data/scripts/pkmn_center_nurse.pory"
	setstatus1 STATUS1_SLEEP_TURN ( 1 ), VAR_0x8004
# 477 "data/scripts/pkmn_center_nurse.pory"
	specialvar 0x8007, GetSelectedMonNicknameAndSpecies
# 478 "data/scripts/pkmn_center_nurse.pory"
	playmoncry 0x8007, 0
# 479 "data/scripts/pkmn_center_nurse.pory"
	waitmoncry
# 480 "data/scripts/pkmn_center_nurse.pory"
	msgbox EventScript_PreDamageNPC_Text_13
	goto EventScript_PreDamageNPC_1

EventScript_PreDamageNPC_35:
# 482 "data/scripts/pkmn_center_nurse.pory"
	special IsChosenMonFireType
# 483 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_PreDamageNPC_49
EventScript_PreDamageNPC_48:
# 487 "data/scripts/pkmn_center_nurse.pory"
	setstatus1 STATUS1_BURN, VAR_0x8004
# 488 "data/scripts/pkmn_center_nurse.pory"
	specialvar 0x8007, GetSelectedMonNicknameAndSpecies
# 489 "data/scripts/pkmn_center_nurse.pory"
	playmoncry 0x8007, 0
# 490 "data/scripts/pkmn_center_nurse.pory"
	waitmoncry
# 491 "data/scripts/pkmn_center_nurse.pory"
	msgbox EventScript_PreDamageNPC_Text_15
	goto EventScript_PreDamageNPC_1

EventScript_PreDamageNPC_36:
# 493 "data/scripts/pkmn_center_nurse.pory"
	special IsChosenMonIceType
# 494 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_PreDamageNPC_52
EventScript_PreDamageNPC_51:
# 498 "data/scripts/pkmn_center_nurse.pory"
	setstatus1 STATUS1_FREEZE, VAR_0x8004
# 499 "data/scripts/pkmn_center_nurse.pory"
	specialvar 0x8007, GetSelectedMonNicknameAndSpecies
# 500 "data/scripts/pkmn_center_nurse.pory"
	playmoncry 0x8007, 0
# 501 "data/scripts/pkmn_center_nurse.pory"
	waitmoncry
# 502 "data/scripts/pkmn_center_nurse.pory"
	msgbox EventScript_PreDamageNPC_Text_17
	goto EventScript_PreDamageNPC_1

EventScript_PreDamageNPC_37:
# 504 "data/scripts/pkmn_center_nurse.pory"
	special IsChosenMonSteelType
# 505 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_PreDamageNPC_55
EventScript_PreDamageNPC_54:
# 512 "data/scripts/pkmn_center_nurse.pory"
	special IsChosenMonPoisonType
# 513 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_PreDamageNPC_63
EventScript_PreDamageNPC_62:
# 520 "data/scripts/pkmn_center_nurse.pory"
	setstatus1 STATUS1_TOXIC_POISON, VAR_0x8004
# 521 "data/scripts/pkmn_center_nurse.pory"
	specialvar 0x8007, GetSelectedMonNicknameAndSpecies
# 522 "data/scripts/pkmn_center_nurse.pory"
	playmoncry 0x8007, 0
# 523 "data/scripts/pkmn_center_nurse.pory"
	waitmoncry
# 524 "data/scripts/pkmn_center_nurse.pory"
	msgbox EventScript_PreDamageNPC_Text_20
	goto EventScript_PreDamageNPC_1

EventScript_PreDamageNPC_40:
# 439 "data/scripts/pkmn_center_nurse.pory"
	getseenmon 757
# 440 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_PreDamageNPC_60
	goto EventScript_PreDamageNPC_39

EventScript_PreDamageNPC_43:
# 461 "data/scripts/pkmn_center_nurse.pory"
	msgbox EventScript_PreDamageNPC_Text_10
# 462 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_PreDamageNPC_42

EventScript_PreDamageNPC_46:
# 472 "data/scripts/pkmn_center_nurse.pory"
	specialvar 0x8007, GetSelectedMonNicknameAndSpecies
# 473 "data/scripts/pkmn_center_nurse.pory"
	msgbox EventScript_PreDamageNPC_Text_12
# 474 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_PreDamageNPC_45

EventScript_PreDamageNPC_49:
# 484 "data/scripts/pkmn_center_nurse.pory"
	msgbox EventScript_PreDamageNPC_Text_14
# 485 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_PreDamageNPC_48

EventScript_PreDamageNPC_52:
# 495 "data/scripts/pkmn_center_nurse.pory"
	msgbox EventScript_PreDamageNPC_Text_16
# 496 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_PreDamageNPC_51

EventScript_PreDamageNPC_55:
# 506 "data/scripts/pkmn_center_nurse.pory"
	getseenmon 757
# 507 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_PreDamageNPC_65
	goto EventScript_PreDamageNPC_54

EventScript_PreDamageNPC_58:
# 447 "data/scripts/pkmn_center_nurse.pory"
	getseenmon 757
# 448 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_PreDamageNPC_67
	goto EventScript_PreDamageNPC_57

EventScript_PreDamageNPC_60:
# 441 "data/scripts/pkmn_center_nurse.pory"
	msgbox EventScript_PreDamageNPC_Text_7
# 442 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_PreDamageNPC_39

EventScript_PreDamageNPC_63:
# 514 "data/scripts/pkmn_center_nurse.pory"
	getseenmon 757
# 515 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_PreDamageNPC_69
	goto EventScript_PreDamageNPC_62

EventScript_PreDamageNPC_65:
# 508 "data/scripts/pkmn_center_nurse.pory"
	msgbox EventScript_PreDamageNPC_Text_18
# 509 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_PreDamageNPC_54

EventScript_PreDamageNPC_67:
# 449 "data/scripts/pkmn_center_nurse.pory"
	msgbox EventScript_PreDamageNPC_Text_8
# 450 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_PreDamageNPC_57

EventScript_PreDamageNPC_69:
# 516 "data/scripts/pkmn_center_nurse.pory"
	msgbox EventScript_PreDamageNPC_Text_19
# 517 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_PreDamageNPC_62


EventScript_HyperTrainNPC::
# 533 "data/scripts/pkmn_center_nurse.pory"
	lock
# 534 "data/scripts/pkmn_center_nurse.pory"
	msgbox EventScript_HyperTrainNPC_Text_0
# 535 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 8, 4
# 536 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq EventScript_HyperTrainNPC_2
EventScript_HyperTrainNPC_1:
# 539 "data/scripts/pkmn_center_nurse.pory"
	checkitem ITEM_BOTTLE_CAP, 1
# 540 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 1
	goto_if_ne EventScript_HyperTrainNPC_5
EventScript_HyperTrainNPC_4:
# 544 "data/scripts/pkmn_center_nurse.pory"
	special ChoosePartyMon
# 545 "data/scripts/pkmn_center_nurse.pory"
	waitstate
# 546 "data/scripts/pkmn_center_nurse.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 547 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq EventScript_HyperTrainNPC_8
EventScript_HyperTrainNPC_7:
# 551 "data/scripts/pkmn_center_nurse.pory"
	msgbox EventScript_HyperTrainNPC_Text_3
# 552 "data/scripts/pkmn_center_nurse.pory"
	multichoicegrid 10, 4, MULTI_STAT_NAMES, 2, 0
# 553 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq EventScript_HyperTrainNPC_11
# 558 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 1
	goto_if_eq EventScript_HyperTrainNPC_12
# 563 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 2
	goto_if_eq EventScript_HyperTrainNPC_13
# 568 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 3
	goto_if_eq EventScript_HyperTrainNPC_14
# 573 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 4
	goto_if_eq EventScript_HyperTrainNPC_15
# 578 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 5
	goto_if_eq EventScript_HyperTrainNPC_16
EventScript_HyperTrainNPC_10:
# 583 "data/scripts/pkmn_center_nurse.pory"
	sethypertrainstat STAT
# 584 "data/scripts/pkmn_center_nurse.pory"
	specialvar 0x8007, GetSelectedMonNicknameAndSpecies
# 585 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_HyperTrainNPC_24
EventScript_HyperTrainNPC_23:
# 589 "data/scripts/pkmn_center_nurse.pory"
	switch STAT
# 591 "data/scripts/pkmn_center_nurse.pory"
	case 0, EventScript_HyperTrainNPC_28
# 593 "data/scripts/pkmn_center_nurse.pory"
	case 1, EventScript_HyperTrainNPC_29
# 595 "data/scripts/pkmn_center_nurse.pory"
	case 2, EventScript_HyperTrainNPC_30
# 597 "data/scripts/pkmn_center_nurse.pory"
	case 3, EventScript_HyperTrainNPC_31
# 599 "data/scripts/pkmn_center_nurse.pory"
	case 4, EventScript_HyperTrainNPC_32
# 601 "data/scripts/pkmn_center_nurse.pory"
	case 5, EventScript_HyperTrainNPC_33
EventScript_HyperTrainNPC_26:
# 604 "data/scripts/pkmn_center_nurse.pory"
	playmoncry 0x8007, 0
# 605 "data/scripts/pkmn_center_nurse.pory"
	waitmoncry
# 606 "data/scripts/pkmn_center_nurse.pory"
	msgbox EventScript_HyperTrainNPC_Text_5
# 607 "data/scripts/pkmn_center_nurse.pory"
	removeitem ITEM_BOTTLE_CAP, 1
# 608 "data/scripts/pkmn_center_nurse.pory"
	goto End
	return

EventScript_HyperTrainNPC_2:
# 537 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_HyperTrainNPC_1

EventScript_HyperTrainNPC_5:
# 541 "data/scripts/pkmn_center_nurse.pory"
	msgbox EventScript_HyperTrainNPC_Text_1
# 542 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_HyperTrainNPC_4

EventScript_HyperTrainNPC_8:
# 548 "data/scripts/pkmn_center_nurse.pory"
	msgbox EventScript_HyperTrainNPC_Text_2
# 549 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_HyperTrainNPC_7

EventScript_HyperTrainNPC_11:
# 555 "data/scripts/pkmn_center_nurse.pory"
	setvar STAT, 0
# 556 "data/scripts/pkmn_center_nurse.pory"
	canhypertrain 0, VAR_0x8004
	goto EventScript_HyperTrainNPC_10

EventScript_HyperTrainNPC_12:
# 560 "data/scripts/pkmn_center_nurse.pory"
	setvar STAT, 1
# 561 "data/scripts/pkmn_center_nurse.pory"
	canhypertrain 1, VAR_0x8004
	goto EventScript_HyperTrainNPC_10

EventScript_HyperTrainNPC_13:
# 565 "data/scripts/pkmn_center_nurse.pory"
	setvar STAT, 2
# 566 "data/scripts/pkmn_center_nurse.pory"
	canhypertrain 2, VAR_0x8004
	goto EventScript_HyperTrainNPC_10

EventScript_HyperTrainNPC_14:
# 570 "data/scripts/pkmn_center_nurse.pory"
	setvar STAT, 3
# 571 "data/scripts/pkmn_center_nurse.pory"
	canhypertrain 3, VAR_0x8004
	goto EventScript_HyperTrainNPC_10

EventScript_HyperTrainNPC_15:
# 575 "data/scripts/pkmn_center_nurse.pory"
	setvar STAT, 4
# 576 "data/scripts/pkmn_center_nurse.pory"
	canhypertrain 4, VAR_0x8004
	goto EventScript_HyperTrainNPC_10

EventScript_HyperTrainNPC_16:
# 580 "data/scripts/pkmn_center_nurse.pory"
	setvar STAT, 5
# 581 "data/scripts/pkmn_center_nurse.pory"
	canhypertrain 5, VAR_0x8004
	goto EventScript_HyperTrainNPC_10

EventScript_HyperTrainNPC_24:
# 586 "data/scripts/pkmn_center_nurse.pory"
	msgbox EventScript_HyperTrainNPC_Text_4
# 587 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_HyperTrainNPC_23

EventScript_HyperTrainNPC_28:
# 592 "data/scripts/pkmn_center_nurse.pory"
	hypertrain 0, VAR_0x8004
	goto EventScript_HyperTrainNPC_26

EventScript_HyperTrainNPC_29:
# 594 "data/scripts/pkmn_center_nurse.pory"
	hypertrain 1, VAR_0x8004
	goto EventScript_HyperTrainNPC_26

EventScript_HyperTrainNPC_30:
# 596 "data/scripts/pkmn_center_nurse.pory"
	hypertrain 2, VAR_0x8004
	goto EventScript_HyperTrainNPC_26

EventScript_HyperTrainNPC_31:
# 598 "data/scripts/pkmn_center_nurse.pory"
	hypertrain 3, VAR_0x8004
	goto EventScript_HyperTrainNPC_26

EventScript_HyperTrainNPC_32:
# 600 "data/scripts/pkmn_center_nurse.pory"
	hypertrain 4, VAR_0x8004
	goto EventScript_HyperTrainNPC_26

EventScript_HyperTrainNPC_33:
# 602 "data/scripts/pkmn_center_nurse.pory"
	hypertrain 5, VAR_0x8004
	goto EventScript_HyperTrainNPC_26


BPShopClerk::
# 612 "data/scripts/pkmn_center_nurse.pory"
	special ShowBattlePointsWindow
# 613 "data/scripts/pkmn_center_nurse.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_HOLD_ITEM_VENDOR
# 619 "data/scripts/pkmn_center_nurse.pory"
	special ShowFrontierExchangeCornerItemIconWindow
# 620 "data/scripts/pkmn_center_nurse.pory"
	special ShowScrollableMultichoice
# 621 "data/scripts/pkmn_center_nurse.pory"
	waitstate
# 622 "data/scripts/pkmn_center_nurse.pory"
	special CloseFrontierExchangeCornerItemIconWindow
# 623 "data/scripts/pkmn_center_nurse.pory"
	special CloseBattlePointsWindow
# 624 "data/scripts/pkmn_center_nurse.pory"
	switch VAR_RESULT
# 625 "data/scripts/pkmn_center_nurse.pory"
	case 0, BPShopClerk_3
BPShopClerk_1:
# 654 "data/scripts/pkmn_center_nurse.pory"
	goto End
	return

BPShopClerk_3:
# 626 "data/scripts/pkmn_center_nurse.pory"
	msgbox BPShopClerk_Text_0
# 627 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 8, 4
# 628 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq BPShopClerk_5
BPShopClerk_4:
# 635 "data/scripts/pkmn_center_nurse.pory"
	setvar VAR_0x8009, ITEM_EVIOLITE
# 636 "data/scripts/pkmn_center_nurse.pory"
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
# 637 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_TEMP_1, 4
	goto_if_lt BPShopClerk_8
BPShopClerk_7:
# 641 "data/scripts/pkmn_center_nurse.pory"
	checkitemspace VAR_0x8009
# 642 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq BPShopClerk_11
BPShopClerk_10:
# 647 "data/scripts/pkmn_center_nurse.pory"
	setvar VAR_0x8004, 4
# 648 "data/scripts/pkmn_center_nurse.pory"
	special TakeFrontierBattlePoints
# 649 "data/scripts/pkmn_center_nurse.pory"
	playse SE_SHOP
# 650 "data/scripts/pkmn_center_nurse.pory"
	additem VAR_0x8009
# 651 "data/scripts/pkmn_center_nurse.pory"
	msgbox BPShopClerk_Text_3
# 652 "data/scripts/pkmn_center_nurse.pory"
	special UpdateBattlePointsWindow
	goto BPShopClerk_1

BPShopClerk_5:
# 629 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto BPShopClerk_4

BPShopClerk_8:
# 638 "data/scripts/pkmn_center_nurse.pory"
	msgbox BPShopClerk_Text_1
# 639 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto BPShopClerk_7

BPShopClerk_11:
# 643 "data/scripts/pkmn_center_nurse.pory"
	msgbox BPShopClerk_Text_2
# 644 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto BPShopClerk_10


EggMoveTutor::
# 658 "data/scripts/pkmn_center_nurse.pory"
	msgbox EggMoveTutor_Text_0
# 659 "data/scripts/pkmn_center_nurse.pory"
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
# 660 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_TEMP_1, 1
	goto_if_lt EggMoveTutor_2
EggMoveTutor_1:
# 664 "data/scripts/pkmn_center_nurse.pory"
	msgbox EggMoveTutor_Text_2
# 665 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 8, 4
# 666 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq EggMoveTutor_5
EggMoveTutor_4:
# 669 "data/scripts/pkmn_center_nurse.pory"
	special ChooseMonForMoveRelearner
# 670 "data/scripts/pkmn_center_nurse.pory"
	waitstate
# 671 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq EggMoveTutor_8
EggMoveTutor_7:
# 674 "data/scripts/pkmn_center_nurse.pory"
	special IsSelectedMonEgg
# 675 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EggMoveTutor_11
EggMoveTutor_10:
# 679 "data/scripts/pkmn_center_nurse.pory"
	special DoesChosenMonHaveEggMoves
# 680 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EggMoveTutor_14
EggMoveTutor_13:
# 684 "data/scripts/pkmn_center_nurse.pory"
	specialvar 0x8007, GetSelectedMonNicknameAndSpecies
# 685 "data/scripts/pkmn_center_nurse.pory"
	msgbox EggMoveTutor_Text_5
# 686 "data/scripts/pkmn_center_nurse.pory"
	special TeachEggMove
# 687 "data/scripts/pkmn_center_nurse.pory"
	waitstate
# 688 "data/scripts/pkmn_center_nurse.pory"
	setvar VAR_0x8004, 1
# 689 "data/scripts/pkmn_center_nurse.pory"
	special TakeFrontierBattlePoints
# 690 "data/scripts/pkmn_center_nurse.pory"
	playse SE_SHOP
# 691 "data/scripts/pkmn_center_nurse.pory"
	goto End
	return

EggMoveTutor_2:
# 661 "data/scripts/pkmn_center_nurse.pory"
	msgbox EggMoveTutor_Text_1
# 662 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EggMoveTutor_1

EggMoveTutor_5:
# 667 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EggMoveTutor_4

EggMoveTutor_8:
# 672 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EggMoveTutor_7

EggMoveTutor_11:
# 676 "data/scripts/pkmn_center_nurse.pory"
	msgbox EggMoveTutor_Text_3
# 677 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EggMoveTutor_10

EggMoveTutor_14:
# 681 "data/scripts/pkmn_center_nurse.pory"
	msgbox EggMoveTutor_Text_4
# 682 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EggMoveTutor_13


freebp::
# 740 "data/scripts/pkmn_center_nurse.pory"
	GiveBP 5
	return


EventScript_FishermanSalesman::
# 744 "data/scripts/pkmn_center_nurse.pory"
	lockall
# 745 "data/scripts/pkmn_center_nurse.pory"
	msgbox EventScript_FishermanSalesman_Text_0
# 746 "data/scripts/pkmn_center_nurse.pory"
	checkmoney 500
# 747 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_FishermanSalesman_2
EventScript_FishermanSalesman_1:
# 751 "data/scripts/pkmn_center_nurse.pory"
	msgbox EventScript_FishermanSalesman_Text_2
# 752 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 8, 4
# 753 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq EventScript_FishermanSalesman_5
EventScript_FishermanSalesman_4:
# 756 "data/scripts/pkmn_center_nurse.pory"
	setvar VAR_0x8004, SCROLL_MULTI_FISH
# 757 "data/scripts/pkmn_center_nurse.pory"
	showmoneybox 0, 0
# 758 "data/scripts/pkmn_center_nurse.pory"
	special ShowScrollableMultichoice
# 759 "data/scripts/pkmn_center_nurse.pory"
	waitstate
# 760 "data/scripts/pkmn_center_nurse.pory"
	switch VAR_RESULT
# 762 "data/scripts/pkmn_center_nurse.pory"
	case 0, EventScript_FishermanSalesman_9
# 764 "data/scripts/pkmn_center_nurse.pory"
	case 1, EventScript_FishermanSalesman_10
# 766 "data/scripts/pkmn_center_nurse.pory"
	case 2, EventScript_FishermanSalesman_11
# 768 "data/scripts/pkmn_center_nurse.pory"
	case 3, EventScript_FishermanSalesman_12
# 770 "data/scripts/pkmn_center_nurse.pory"
	case 4, EventScript_FishermanSalesman_13
# 772 "data/scripts/pkmn_center_nurse.pory"
	case 5, EventScript_FishermanSalesman_14
# 774 "data/scripts/pkmn_center_nurse.pory"
	case 6, EventScript_FishermanSalesman_15
# 776 "data/scripts/pkmn_center_nurse.pory"
	case 7, EventScript_FishermanSalesman_16
# 778 "data/scripts/pkmn_center_nurse.pory"
	case 8, EventScript_FishermanSalesman_17
# 780 "data/scripts/pkmn_center_nurse.pory"
	case 9, EventScript_FishermanSalesman_18
# 782 "data/scripts/pkmn_center_nurse.pory"
	case 10, EventScript_FishermanSalesman_19
# 784 "data/scripts/pkmn_center_nurse.pory"
	case 11, EventScript_FishermanSalesman_20
# 786 "data/scripts/pkmn_center_nurse.pory"
	case 12, EventScript_FishermanSalesman_21
# 789 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 790 "data/scripts/pkmn_center_nurse.pory"
	goto End
EventScript_FishermanSalesman_7:
# 792 "data/scripts/pkmn_center_nurse.pory"
	goto End
	return

EventScript_FishermanSalesman_2:
# 748 "data/scripts/pkmn_center_nurse.pory"
	msgbox EventScript_FishermanSalesman_Text_1
# 749 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_FishermanSalesman_1

EventScript_FishermanSalesman_5:
# 754 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto EventScript_FishermanSalesman_4

EventScript_FishermanSalesman_9:
# 763 "data/scripts/pkmn_center_nurse.pory"
	call TryBuyMagikarp
	goto EventScript_FishermanSalesman_7

EventScript_FishermanSalesman_10:
# 765 "data/scripts/pkmn_center_nurse.pory"
	call TryBuyGoldeen
	goto EventScript_FishermanSalesman_7

EventScript_FishermanSalesman_11:
# 767 "data/scripts/pkmn_center_nurse.pory"
	call TryBuyRemoraid
	goto EventScript_FishermanSalesman_7

EventScript_FishermanSalesman_12:
# 769 "data/scripts/pkmn_center_nurse.pory"
	call TryBuyFeebas
	goto EventScript_FishermanSalesman_7

EventScript_FishermanSalesman_13:
# 771 "data/scripts/pkmn_center_nurse.pory"
	call TryBuyFinneon
	goto EventScript_FishermanSalesman_7

EventScript_FishermanSalesman_14:
# 773 "data/scripts/pkmn_center_nurse.pory"
	call TryBuyTynamo
	goto EventScript_FishermanSalesman_7

EventScript_FishermanSalesman_15:
# 775 "data/scripts/pkmn_center_nurse.pory"
	call TryBuyArrokuda
	goto EventScript_FishermanSalesman_7

EventScript_FishermanSalesman_16:
# 777 "data/scripts/pkmn_center_nurse.pory"
	call TryBuyBarboach
	goto EventScript_FishermanSalesman_7

EventScript_FishermanSalesman_17:
# 779 "data/scripts/pkmn_center_nurse.pory"
	call TryBuyChinchou
	goto EventScript_FishermanSalesman_7

EventScript_FishermanSalesman_18:
# 781 "data/scripts/pkmn_center_nurse.pory"
	call TryBuyCarvanha
	goto EventScript_FishermanSalesman_7

EventScript_FishermanSalesman_19:
# 783 "data/scripts/pkmn_center_nurse.pory"
	call TryBuyQwilfish
	goto EventScript_FishermanSalesman_7

EventScript_FishermanSalesman_20:
# 785 "data/scripts/pkmn_center_nurse.pory"
	call TryBuyBasculin
	goto EventScript_FishermanSalesman_7

EventScript_FishermanSalesman_21:
# 787 "data/scripts/pkmn_center_nurse.pory"
	call TryBuyCosmog
	goto EventScript_FishermanSalesman_7


TryBuyMagikarp::
# 796 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyMagikarp_Text_0
# 797 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 8, 4
# 798 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq TryBuyMagikarp_2
TryBuyMagikarp_1:
# 802 "data/scripts/pkmn_center_nurse.pory"
	removemoney 500
# 803 "data/scripts/pkmn_center_nurse.pory"
	updatemoneybox
# 804 "data/scripts/pkmn_center_nurse.pory"
	givemon SPECIES_MAGIKARP, 5, ITEM_NONE, ITEM_LURE_BALL
# 805 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TryBuyMagikarp_4
# 810 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TryBuyMagikarp_5
# 816 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyMagikarp_Text_2
# 817 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 818 "data/scripts/pkmn_center_nurse.pory"
	goto End
	return

TryBuyMagikarp_2:
# 799 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 800 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto TryBuyMagikarp_1

TryBuyMagikarp_4:
# 806 "data/scripts/pkmn_center_nurse.pory"
	playfanfare MUS_OBTAIN_ITEM
# 807 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyMagikarp_Text_1
# 808 "data/scripts/pkmn_center_nurse.pory"
	call NicknamePartyMon
	return

TryBuyMagikarp_5:
# 811 "data/scripts/pkmn_center_nurse.pory"
	playfanfare MUS_OBTAIN_ITEM
# 812 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyMagikarp_Text_1
# 813 "data/scripts/pkmn_center_nurse.pory"
	call NicknameBoxMon
	return


TryBuyGoldeen::
# 823 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyGoldeen_Text_0
# 824 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 8, 4
# 825 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq TryBuyGoldeen_2
TryBuyGoldeen_1:
# 829 "data/scripts/pkmn_center_nurse.pory"
	removemoney 500
# 830 "data/scripts/pkmn_center_nurse.pory"
	updatemoneybox
# 831 "data/scripts/pkmn_center_nurse.pory"
	givemon SPECIES_GOLDEEN, 5, ITEM_NONE, ITEM_LURE_BALL
# 832 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TryBuyGoldeen_4
# 837 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TryBuyGoldeen_5
# 843 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyMagikarp_Text_2
# 844 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 845 "data/scripts/pkmn_center_nurse.pory"
	goto End
	return

TryBuyGoldeen_2:
# 826 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 827 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto TryBuyGoldeen_1

TryBuyGoldeen_4:
# 833 "data/scripts/pkmn_center_nurse.pory"
	playfanfare MUS_OBTAIN_ITEM
# 834 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyGoldeen_Text_1
# 835 "data/scripts/pkmn_center_nurse.pory"
	call NicknamePartyMon
	return

TryBuyGoldeen_5:
# 838 "data/scripts/pkmn_center_nurse.pory"
	playfanfare MUS_OBTAIN_ITEM
# 839 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyGoldeen_Text_1
# 840 "data/scripts/pkmn_center_nurse.pory"
	call NicknameBoxMon
	return


TryBuyRemoraid::
# 850 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyRemoraid_Text_0
# 851 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 8, 4
# 852 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq TryBuyRemoraid_2
TryBuyRemoraid_1:
# 856 "data/scripts/pkmn_center_nurse.pory"
	removemoney 500
# 857 "data/scripts/pkmn_center_nurse.pory"
	updatemoneybox
# 858 "data/scripts/pkmn_center_nurse.pory"
	givemon SPECIES_REMORAID, 5, ITEM_NONE, ITEM_LURE_BALL
# 859 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TryBuyRemoraid_4
# 864 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TryBuyRemoraid_5
# 870 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyMagikarp_Text_2
# 871 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 872 "data/scripts/pkmn_center_nurse.pory"
	goto End
	return

TryBuyRemoraid_2:
# 853 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 854 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto TryBuyRemoraid_1

TryBuyRemoraid_4:
# 860 "data/scripts/pkmn_center_nurse.pory"
	playfanfare MUS_OBTAIN_ITEM
# 861 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyRemoraid_Text_1
# 862 "data/scripts/pkmn_center_nurse.pory"
	call NicknamePartyMon
	return

TryBuyRemoraid_5:
# 865 "data/scripts/pkmn_center_nurse.pory"
	playfanfare MUS_OBTAIN_ITEM
# 866 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyRemoraid_Text_1
# 867 "data/scripts/pkmn_center_nurse.pory"
	call NicknameBoxMon
	return


TryBuyFeebas::
# 877 "data/scripts/pkmn_center_nurse.pory"
	checkmoney 1000
# 878 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq TryBuyFeebas_2
TryBuyFeebas_1:
# 883 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyFeebas_Text_1
# 884 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 8, 4
# 885 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq TryBuyFeebas_5
TryBuyFeebas_4:
# 889 "data/scripts/pkmn_center_nurse.pory"
	removemoney 1000
# 890 "data/scripts/pkmn_center_nurse.pory"
	updatemoneybox
# 891 "data/scripts/pkmn_center_nurse.pory"
	givemon SPECIES_FEEBAS, 5, ITEM_NONE, ITEM_LURE_BALL
# 892 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TryBuyFeebas_7
# 897 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TryBuyFeebas_8
# 903 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyMagikarp_Text_2
# 904 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 905 "data/scripts/pkmn_center_nurse.pory"
	goto End
	return

TryBuyFeebas_2:
# 879 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyFeebas_Text_0
# 880 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 881 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto TryBuyFeebas_1

TryBuyFeebas_5:
# 886 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 887 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto TryBuyFeebas_4

TryBuyFeebas_7:
# 893 "data/scripts/pkmn_center_nurse.pory"
	playfanfare MUS_OBTAIN_ITEM
# 894 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyFeebas_Text_2
# 895 "data/scripts/pkmn_center_nurse.pory"
	call NicknamePartyMon
	return

TryBuyFeebas_8:
# 898 "data/scripts/pkmn_center_nurse.pory"
	playfanfare MUS_OBTAIN_ITEM
# 899 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyFeebas_Text_2
# 900 "data/scripts/pkmn_center_nurse.pory"
	call NicknameBoxMon
	return


TryBuyFinneon::
# 910 "data/scripts/pkmn_center_nurse.pory"
	checkmoney 1000
# 911 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq TryBuyFinneon_2
TryBuyFinneon_1:
# 916 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyFinneon_Text_1
# 917 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 8, 4
# 918 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq TryBuyFinneon_5
TryBuyFinneon_4:
# 922 "data/scripts/pkmn_center_nurse.pory"
	removemoney 1000
# 923 "data/scripts/pkmn_center_nurse.pory"
	updatemoneybox
# 924 "data/scripts/pkmn_center_nurse.pory"
	givemon SPECIES_FINNEON, 5, ITEM_NONE, ITEM_LURE_BALL
# 925 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TryBuyFinneon_7
# 930 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TryBuyFinneon_8
# 936 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyMagikarp_Text_2
# 937 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 938 "data/scripts/pkmn_center_nurse.pory"
	goto End
	return

TryBuyFinneon_2:
# 912 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyFinneon_Text_0
# 913 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 914 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto TryBuyFinneon_1

TryBuyFinneon_5:
# 919 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 920 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto TryBuyFinneon_4

TryBuyFinneon_7:
# 926 "data/scripts/pkmn_center_nurse.pory"
	playfanfare MUS_OBTAIN_ITEM
# 927 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyFinneon_Text_2
# 928 "data/scripts/pkmn_center_nurse.pory"
	call NicknamePartyMon
	return

TryBuyFinneon_8:
# 931 "data/scripts/pkmn_center_nurse.pory"
	playfanfare MUS_OBTAIN_ITEM
# 932 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyFinneon_Text_2
# 933 "data/scripts/pkmn_center_nurse.pory"
	call NicknameBoxMon
	return


TryBuyTynamo::
# 943 "data/scripts/pkmn_center_nurse.pory"
	checkmoney 1000
# 944 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq TryBuyTynamo_2
TryBuyTynamo_1:
# 949 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyTynamo_Text_1
# 950 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 8, 4
# 951 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq TryBuyTynamo_5
TryBuyTynamo_4:
# 955 "data/scripts/pkmn_center_nurse.pory"
	removemoney 1000
# 956 "data/scripts/pkmn_center_nurse.pory"
	updatemoneybox
# 957 "data/scripts/pkmn_center_nurse.pory"
	givemon SPECIES_TYNAMO, 5, ITEM_NONE, ITEM_LURE_BALL
# 958 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TryBuyTynamo_7
# 963 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TryBuyTynamo_8
# 969 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyMagikarp_Text_2
# 970 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 971 "data/scripts/pkmn_center_nurse.pory"
	goto End
	return

TryBuyTynamo_2:
# 945 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyTynamo_Text_0
# 946 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 947 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto TryBuyTynamo_1

TryBuyTynamo_5:
# 952 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 953 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto TryBuyTynamo_4

TryBuyTynamo_7:
# 959 "data/scripts/pkmn_center_nurse.pory"
	playfanfare MUS_OBTAIN_ITEM
# 960 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyTynamo_Text_2
# 961 "data/scripts/pkmn_center_nurse.pory"
	call NicknamePartyMon
	return

TryBuyTynamo_8:
# 964 "data/scripts/pkmn_center_nurse.pory"
	playfanfare MUS_OBTAIN_ITEM
# 965 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyTynamo_Text_2
# 966 "data/scripts/pkmn_center_nurse.pory"
	call NicknameBoxMon
	return


TryBuyArrokuda::
# 976 "data/scripts/pkmn_center_nurse.pory"
	checkmoney 1000
# 977 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq TryBuyArrokuda_2
TryBuyArrokuda_1:
# 982 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyArrokuda_Text_1
# 983 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 8, 4
# 984 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq TryBuyArrokuda_5
TryBuyArrokuda_4:
# 988 "data/scripts/pkmn_center_nurse.pory"
	removemoney 1000
# 989 "data/scripts/pkmn_center_nurse.pory"
	updatemoneybox
# 990 "data/scripts/pkmn_center_nurse.pory"
	givemon SPECIES_ARROKUDA, 5, ITEM_NONE, ITEM_LURE_BALL
# 991 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TryBuyArrokuda_7
# 996 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TryBuyArrokuda_8
# 1002 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyMagikarp_Text_2
# 1003 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 1004 "data/scripts/pkmn_center_nurse.pory"
	goto End
	return

TryBuyArrokuda_2:
# 978 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyArrokuda_Text_0
# 979 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 980 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto TryBuyArrokuda_1

TryBuyArrokuda_5:
# 985 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 986 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto TryBuyArrokuda_4

TryBuyArrokuda_7:
# 992 "data/scripts/pkmn_center_nurse.pory"
	playfanfare MUS_OBTAIN_ITEM
# 993 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyArrokuda_Text_2
# 994 "data/scripts/pkmn_center_nurse.pory"
	call NicknamePartyMon
	return

TryBuyArrokuda_8:
# 997 "data/scripts/pkmn_center_nurse.pory"
	playfanfare MUS_OBTAIN_ITEM
# 998 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyArrokuda_Text_2
# 999 "data/scripts/pkmn_center_nurse.pory"
	call NicknameBoxMon
	return


TryBuyBarboach::
# 1009 "data/scripts/pkmn_center_nurse.pory"
	checkmoney 1000
# 1010 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq TryBuyBarboach_2
TryBuyBarboach_1:
# 1015 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyBarboach_Text_1
# 1016 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 8, 4
# 1017 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq TryBuyBarboach_5
TryBuyBarboach_4:
# 1021 "data/scripts/pkmn_center_nurse.pory"
	removemoney 1000
# 1022 "data/scripts/pkmn_center_nurse.pory"
	updatemoneybox
# 1023 "data/scripts/pkmn_center_nurse.pory"
	givemon SPECIES_BARBOACH, 5, ITEM_NONE, ITEM_LURE_BALL
# 1024 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TryBuyBarboach_7
# 1029 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TryBuyBarboach_8
# 1035 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyMagikarp_Text_2
# 1036 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 1037 "data/scripts/pkmn_center_nurse.pory"
	goto End
	return

TryBuyBarboach_2:
# 1011 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyBarboach_Text_0
# 1012 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 1013 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto TryBuyBarboach_1

TryBuyBarboach_5:
# 1018 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 1019 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto TryBuyBarboach_4

TryBuyBarboach_7:
# 1025 "data/scripts/pkmn_center_nurse.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1026 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyBarboach_Text_2
# 1027 "data/scripts/pkmn_center_nurse.pory"
	call NicknamePartyMon
	return

TryBuyBarboach_8:
# 1030 "data/scripts/pkmn_center_nurse.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1031 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyBarboach_Text_2
# 1032 "data/scripts/pkmn_center_nurse.pory"
	call NicknameBoxMon
	return


TryBuyChinchou::
# 1042 "data/scripts/pkmn_center_nurse.pory"
	checkmoney 5000
# 1043 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq TryBuyChinchou_2
TryBuyChinchou_1:
# 1048 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyChinchou_Text_1
# 1049 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 8, 4
# 1050 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq TryBuyChinchou_5
TryBuyChinchou_4:
# 1054 "data/scripts/pkmn_center_nurse.pory"
	removemoney 5000
# 1055 "data/scripts/pkmn_center_nurse.pory"
	updatemoneybox
# 1056 "data/scripts/pkmn_center_nurse.pory"
	givemon SPECIES_CHINCHOU, 5, ITEM_NONE, ITEM_LURE_BALL
# 1057 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TryBuyChinchou_7
# 1062 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TryBuyChinchou_8
# 1068 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyMagikarp_Text_2
# 1069 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 1070 "data/scripts/pkmn_center_nurse.pory"
	goto End
	return

TryBuyChinchou_2:
# 1044 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyChinchou_Text_0
# 1045 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 1046 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto TryBuyChinchou_1

TryBuyChinchou_5:
# 1051 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 1052 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto TryBuyChinchou_4

TryBuyChinchou_7:
# 1058 "data/scripts/pkmn_center_nurse.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1059 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyChinchou_Text_2
# 1060 "data/scripts/pkmn_center_nurse.pory"
	call NicknamePartyMon
	return

TryBuyChinchou_8:
# 1063 "data/scripts/pkmn_center_nurse.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1064 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyChinchou_Text_2
# 1065 "data/scripts/pkmn_center_nurse.pory"
	call NicknameBoxMon
	return


TryBuyCarvanha::
# 1075 "data/scripts/pkmn_center_nurse.pory"
	checkmoney 5000
# 1076 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq TryBuyCarvanha_2
TryBuyCarvanha_1:
# 1081 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyCarvanha_Text_1
# 1082 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 8, 4
# 1083 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq TryBuyCarvanha_5
TryBuyCarvanha_4:
# 1087 "data/scripts/pkmn_center_nurse.pory"
	removemoney 5000
# 1088 "data/scripts/pkmn_center_nurse.pory"
	updatemoneybox
# 1089 "data/scripts/pkmn_center_nurse.pory"
	givemon SPECIES_CARVANHA, 5, ITEM_NONE, ITEM_LURE_BALL
# 1090 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TryBuyCarvanha_7
# 1095 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TryBuyCarvanha_8
# 1101 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyMagikarp_Text_2
# 1102 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 1103 "data/scripts/pkmn_center_nurse.pory"
	goto End
	return

TryBuyCarvanha_2:
# 1077 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyCarvanha_Text_0
# 1078 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 1079 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto TryBuyCarvanha_1

TryBuyCarvanha_5:
# 1084 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 1085 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto TryBuyCarvanha_4

TryBuyCarvanha_7:
# 1091 "data/scripts/pkmn_center_nurse.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1092 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyCarvanha_Text_2
# 1093 "data/scripts/pkmn_center_nurse.pory"
	call NicknamePartyMon
	return

TryBuyCarvanha_8:
# 1096 "data/scripts/pkmn_center_nurse.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1097 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyCarvanha_Text_2
# 1098 "data/scripts/pkmn_center_nurse.pory"
	call NicknameBoxMon
	return


TryBuyQwilfish::
# 1108 "data/scripts/pkmn_center_nurse.pory"
	checkmoney 10000
# 1109 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq TryBuyQwilfish_2
TryBuyQwilfish_1:
# 1114 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyQwilfish_Text_1
# 1115 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 8, 4
# 1116 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq TryBuyQwilfish_5
TryBuyQwilfish_4:
# 1120 "data/scripts/pkmn_center_nurse.pory"
	removemoney 10000
# 1121 "data/scripts/pkmn_center_nurse.pory"
	updatemoneybox
# 1122 "data/scripts/pkmn_center_nurse.pory"
	givemon SPECIES_QWILFISH_HISUI, 5, ITEM_NONE, ITEM_LURE_BALL
# 1123 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TryBuyQwilfish_7
# 1128 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TryBuyQwilfish_8
# 1134 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyMagikarp_Text_2
# 1135 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 1136 "data/scripts/pkmn_center_nurse.pory"
	goto End
	return

TryBuyQwilfish_2:
# 1110 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyQwilfish_Text_0
# 1111 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 1112 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto TryBuyQwilfish_1

TryBuyQwilfish_5:
# 1117 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 1118 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto TryBuyQwilfish_4

TryBuyQwilfish_7:
# 1124 "data/scripts/pkmn_center_nurse.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1125 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyQwilfish_Text_2
# 1126 "data/scripts/pkmn_center_nurse.pory"
	call NicknamePartyMon
	return

TryBuyQwilfish_8:
# 1129 "data/scripts/pkmn_center_nurse.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1130 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyQwilfish_Text_2
# 1131 "data/scripts/pkmn_center_nurse.pory"
	call NicknameBoxMon
	return


TryBuyBasculin::
# 1141 "data/scripts/pkmn_center_nurse.pory"
	checkmoney 10000
# 1142 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq TryBuyBasculin_2
TryBuyBasculin_1:
# 1147 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyBasculin_Text_1
# 1148 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 8, 4
# 1149 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq TryBuyBasculin_5
TryBuyBasculin_4:
# 1153 "data/scripts/pkmn_center_nurse.pory"
	removemoney 10000
# 1154 "data/scripts/pkmn_center_nurse.pory"
	updatemoneybox
# 1155 "data/scripts/pkmn_center_nurse.pory"
	givemon SPECIES_BASCULIN_WHITE_STRIPED, 5, ITEM_NONE, ITEM_LURE_BALL
# 1156 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TryBuyBasculin_7
# 1161 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TryBuyBasculin_8
# 1167 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyMagikarp_Text_2
# 1168 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 1169 "data/scripts/pkmn_center_nurse.pory"
	goto End
	return

TryBuyBasculin_2:
# 1143 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyBasculin_Text_0
# 1144 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 1145 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto TryBuyBasculin_1

TryBuyBasculin_5:
# 1150 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 1151 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto TryBuyBasculin_4

TryBuyBasculin_7:
# 1157 "data/scripts/pkmn_center_nurse.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1158 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyBasculin_Text_2
# 1159 "data/scripts/pkmn_center_nurse.pory"
	call NicknamePartyMon
	return

TryBuyBasculin_8:
# 1162 "data/scripts/pkmn_center_nurse.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1163 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyBasculin_Text_2
# 1164 "data/scripts/pkmn_center_nurse.pory"
	call NicknameBoxMon
	return


TryBuyCosmog::
# 1174 "data/scripts/pkmn_center_nurse.pory"
	checkmoney 50000
# 1175 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq TryBuyCosmog_2
TryBuyCosmog_1:
# 1180 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyCosmog_Text_1
# 1181 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 8, 4
# 1182 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq TryBuyCosmog_5
TryBuyCosmog_4:
# 1186 "data/scripts/pkmn_center_nurse.pory"
	removemoney 50000
# 1187 "data/scripts/pkmn_center_nurse.pory"
	updatemoneybox
# 1188 "data/scripts/pkmn_center_nurse.pory"
	givemon SPECIES_COSMOG, 5, ITEM_NONE, ITEM_LURE_BALL
# 1189 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TryBuyCosmog_7
# 1194 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TryBuyCosmog_8
# 1200 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyMagikarp_Text_2
# 1201 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 1202 "data/scripts/pkmn_center_nurse.pory"
	goto End
	return

TryBuyCosmog_2:
# 1176 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyCosmog_Text_0
# 1177 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 1178 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto TryBuyCosmog_1

TryBuyCosmog_5:
# 1183 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 1184 "data/scripts/pkmn_center_nurse.pory"
	goto End
	goto TryBuyCosmog_4

TryBuyCosmog_7:
# 1190 "data/scripts/pkmn_center_nurse.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1191 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyCosmog_Text_2
# 1192 "data/scripts/pkmn_center_nurse.pory"
	call NicknamePartyMon
	return

TryBuyCosmog_8:
# 1195 "data/scripts/pkmn_center_nurse.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1196 "data/scripts/pkmn_center_nurse.pory"
	msgbox TryBuyCosmog_Text_2
# 1197 "data/scripts/pkmn_center_nurse.pory"
	call NicknameBoxMon
	return


NicknamePartyMon::
# 1207 "data/scripts/pkmn_center_nurse.pory"
	msgbox NicknamePartyMon_Text_0
# 1208 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 8, 4
# 1209 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 1
	goto_if_eq NicknamePartyMon_2
NicknamePartyMon_1:
# 1213 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 1214 "data/scripts/pkmn_center_nurse.pory"
	goto End
	return

NicknamePartyMon_2:
# 1210 "data/scripts/pkmn_center_nurse.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 1211 "data/scripts/pkmn_center_nurse.pory"
	call Common_EventScript_GetGiftMonPartySlot
	goto NicknamePartyMon_1


NicknameBoxMon::
# 1218 "data/scripts/pkmn_center_nurse.pory"
	msgbox NicknamePartyMon_Text_0
# 1219 "data/scripts/pkmn_center_nurse.pory"
	yesnobox 8, 4
# 1220 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 1
	goto_if_eq NicknameBoxMon_2
NicknameBoxMon_1:
# 1223 "data/scripts/pkmn_center_nurse.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MAGIKARP
# 1224 "data/scripts/pkmn_center_nurse.pory"
	bufferspeciesname STR_VAR_2, VAR_TEMP_TRANSFERRED_SPECIES
# 1225 "data/scripts/pkmn_center_nurse.pory"
	call Common_EventScript_TransferredToPC
# 1226 "data/scripts/pkmn_center_nurse.pory"
	hidemoneybox
# 1227 "data/scripts/pkmn_center_nurse.pory"
	goto End
	return

NicknameBoxMon_2:
# 1221 "data/scripts/pkmn_center_nurse.pory"
	call Common_EventScript_NameReceivedBoxMon
	goto NicknameBoxMon_1


End::
# 1231 "data/scripts/pkmn_center_nurse.pory"
	waitmessage
# 1232 "data/scripts/pkmn_center_nurse.pory"
	releaseall
	return


EventScript_NatureMintNPC_Text_0:
# 131 "data/scripts/pkmn_center_nurse.pory"
	.string "Would you like to make a Nature Mint\n"
	.string "with a Blank Nature Mint?$"

EventScript_NatureMintNPC_Text_1:
# 138 "data/scripts/pkmn_center_nurse.pory"
	.string "You do not have any Blank Nature Mints.$"

EventScript_NatureMintNPC_Text_2:
# 141 "data/scripts/pkmn_center_nurse.pory"
	.string "Which stat would you like the mint to\n"
	.string "increase?$"

EventScript_NatureMintNPC_Text_3:
# 161 "data/scripts/pkmn_center_nurse.pory"
	.string "Which stat would you like the mint to\n"
	.string "decrease?$"

EventScript_NatureMintNPC_Text_4:
# 186 "data/scripts/pkmn_center_nurse.pory"
	.string "Are you sure you want to make a Neutral\n"
	.string "Nature Mint?$"

EventScript_NatureMintNPC_Text_5:
# 197 "data/scripts/pkmn_center_nurse.pory"
	.string "You would like to make a Lonely Nature\n"
	.string "Mint (+Atk -Def)?$"

EventScript_NatureMintNPC_Text_6:
# 205 "data/scripts/pkmn_center_nurse.pory"
	.string "You would like to make an Adamant\n"
	.string "Nature Mint (+Atk -SpA)?$"

EventScript_NatureMintNPC_Text_7:
# 213 "data/scripts/pkmn_center_nurse.pory"
	.string "You would like to make a Naughty Nature\n"
	.string "Mint (+Atk -SpD)?$"

EventScript_NatureMintNPC_Text_8:
# 221 "data/scripts/pkmn_center_nurse.pory"
	.string "You would like to make a Brave Nature\n"
	.string "Mint (+Atk -Spe)?$"

EventScript_NatureMintNPC_Text_9:
# 234 "data/scripts/pkmn_center_nurse.pory"
	.string "You would like to make a Bold Nature\n"
	.string "Mint (+Def -Atk)?$"

EventScript_NatureMintNPC_Text_10:
# 242 "data/scripts/pkmn_center_nurse.pory"
	.string "You would like to make an Impish Nature\n"
	.string "Mint (+Def -SpA)?$"

EventScript_NatureMintNPC_Text_11:
# 250 "data/scripts/pkmn_center_nurse.pory"
	.string "You would like to make a Lax Nature Mint\n"
	.string "(+Def -SpD)?$"

EventScript_NatureMintNPC_Text_12:
# 258 "data/scripts/pkmn_center_nurse.pory"
	.string "You would like to make a Relaxed Nature\n"
	.string "Mint (+Def -Spe)?$"

EventScript_NatureMintNPC_Text_13:
# 271 "data/scripts/pkmn_center_nurse.pory"
	.string "You would like to make a Modest Nature\n"
	.string "Mint (+SpA -Atk)?$"

EventScript_NatureMintNPC_Text_14:
# 279 "data/scripts/pkmn_center_nurse.pory"
	.string "You would like to make a Mild Nature\n"
	.string "Mint (+SpA -Def)?$"

EventScript_NatureMintNPC_Text_15:
# 287 "data/scripts/pkmn_center_nurse.pory"
	.string "You would like to make a Rash Nature\n"
	.string "Mint (+SpA -SpD)?$"

EventScript_NatureMintNPC_Text_16:
# 295 "data/scripts/pkmn_center_nurse.pory"
	.string "You would like to make a Quiet Nature\n"
	.string "Mint (+SpA -Spe)?$"

EventScript_NatureMintNPC_Text_17:
# 308 "data/scripts/pkmn_center_nurse.pory"
	.string "You would like to make a Calm Nature\n"
	.string "Mint (+SpD -Atk)?$"

EventScript_NatureMintNPC_Text_18:
# 316 "data/scripts/pkmn_center_nurse.pory"
	.string "You would like to make a Gentle Nature\n"
	.string "Mint (+SpD -Def)?$"

EventScript_NatureMintNPC_Text_19:
# 324 "data/scripts/pkmn_center_nurse.pory"
	.string "You would like to make a Careful Nature\n"
	.string "Mint (+SpD -SpA)?$"

EventScript_NatureMintNPC_Text_20:
# 332 "data/scripts/pkmn_center_nurse.pory"
	.string "You would like to make a Sassy Nature\n"
	.string "Mint (+SpD -Spe)?$"

EventScript_NatureMintNPC_Text_21:
# 345 "data/scripts/pkmn_center_nurse.pory"
	.string "You would like to make a Timid Nature\n"
	.string "Mint (+Spe -Atk)?$"

EventScript_NatureMintNPC_Text_22:
# 353 "data/scripts/pkmn_center_nurse.pory"
	.string "You would like to make a Hasty Nature\n"
	.string "Mint (+Spe -Def)?$"

EventScript_NatureMintNPC_Text_23:
# 361 "data/scripts/pkmn_center_nurse.pory"
	.string "You would like to make a Jolly Nature\n"
	.string "Mint (+Spe -SpA)?$"

EventScript_NatureMintNPC_Text_24:
# 369 "data/scripts/pkmn_center_nurse.pory"
	.string "You would like to make a Naive Nature\n"
	.string "Mint (+Spe -SpD)?$"

EventScript_PreDamageNPC_Text_0:
# 385 "data/scripts/pkmn_center_nurse.pory"
	.string "Would you like to Pre-Damage or\n"
	.string "Pre-Status one of your Pokémon?$"

EventScript_PreDamageNPC_Text_1:
# 392 "data/scripts/pkmn_center_nurse.pory"
	.string "A Pokémon Egg cannot be Pre-Damaged.$"

EventScript_PreDamageNPC_Text_2:
# 397 "data/scripts/pkmn_center_nurse.pory"
	.string "A Fainted Pokémon cannot be\n"
	.string "Pre-Damaged.$"

EventScript_PreDamageNPC_Text_3:
# 405 "data/scripts/pkmn_center_nurse.pory"
	.string "Set your {STR_VAR_1}'s HP to\n"
	.string "{STR_VAR_3}.$"

EventScript_PreDamageNPC_Text_4:
# 412 "data/scripts/pkmn_center_nurse.pory"
	.string "A Pokémon Egg cannot be Pre-Statused.$"

EventScript_PreDamageNPC_Text_5:
# 417 "data/scripts/pkmn_center_nurse.pory"
	.string "A Fainted Pokémon cannot be\n"
	.string "Pre-Statused.$"

EventScript_PreDamageNPC_Text_6:
# 420 "data/scripts/pkmn_center_nurse.pory"
	.string "Which Status would you like to give the\n"
	.string "Pokémon?$"

EventScript_PreDamageNPC_Text_7:
# 441 "data/scripts/pkmn_center_nurse.pory"
	.string "Steel-type Pokémon cannot be\n"
	.string "Poisoned.$"

EventScript_PreDamageNPC_Text_8:
# 449 "data/scripts/pkmn_center_nurse.pory"
	.string "Poison-type Pokémon cannot be\n"
	.string "Poisoned.$"

EventScript_PreDamageNPC_Text_9:
# 457 "data/scripts/pkmn_center_nurse.pory"
	.string "Inflicted your {STR_VAR_1} with\n"
	.string "Poison.$"

EventScript_PreDamageNPC_Text_10:
# 461 "data/scripts/pkmn_center_nurse.pory"
	.string "Electric-type Pokémon cannot be\n"
	.string "Paralyzed.$"

EventScript_PreDamageNPC_Text_11:
# 468 "data/scripts/pkmn_center_nurse.pory"
	.string "Inflicted your {STR_VAR_1} with\n"
	.string "Paralysis.$"

EventScript_PreDamageNPC_Text_12:
# 473 "data/scripts/pkmn_center_nurse.pory"
	.string "{STR_VAR_1}'s ability prevents it\n"
	.string "from being put to Sleep.$"

EventScript_PreDamageNPC_Text_13:
# 480 "data/scripts/pkmn_center_nurse.pory"
	.string "Inflicted your {STR_VAR_1} with\n"
	.string "Sleep.$"

EventScript_PreDamageNPC_Text_14:
# 484 "data/scripts/pkmn_center_nurse.pory"
	.string "Fire-type Pokémon cannot be Burned.$"

EventScript_PreDamageNPC_Text_15:
# 491 "data/scripts/pkmn_center_nurse.pory"
	.string "Inflicted your {STR_VAR_1} with\n"
	.string "Burn.$"

EventScript_PreDamageNPC_Text_16:
# 495 "data/scripts/pkmn_center_nurse.pory"
	.string "Ice-type Pokémon cannot be Frozen.$"

EventScript_PreDamageNPC_Text_17:
# 502 "data/scripts/pkmn_center_nurse.pory"
	.string "Inflicted your {STR_VAR_1} with\n"
	.string "Freeze.$"

EventScript_PreDamageNPC_Text_18:
# 508 "data/scripts/pkmn_center_nurse.pory"
	.string "Steel-type Pokémon cannot be Badly\n"
	.string "Poisoned.$"

EventScript_PreDamageNPC_Text_19:
# 516 "data/scripts/pkmn_center_nurse.pory"
	.string "Poison-type Pokémon cannot be Badly\n"
	.string "Poisoned.$"

EventScript_PreDamageNPC_Text_20:
# 524 "data/scripts/pkmn_center_nurse.pory"
	.string "Inflicted your {STR_VAR_1} with\n"
	.string "Toxic Poison.$"

EventScript_HyperTrainNPC_Text_0:
# 534 "data/scripts/pkmn_center_nurse.pory"
	.string "Would you like to Hyper Train one of\n"
	.string "your Pokémon?$"

EventScript_HyperTrainNPC_Text_1:
# 541 "data/scripts/pkmn_center_nurse.pory"
	.string "You do not have any Bottle Caps.$"

EventScript_HyperTrainNPC_Text_2:
# 548 "data/scripts/pkmn_center_nurse.pory"
	.string "A Pokémon Egg cannot be Hyper Trained.$"

EventScript_HyperTrainNPC_Text_3:
# 551 "data/scripts/pkmn_center_nurse.pory"
	.string "Which stat would you like to train?$"

EventScript_HyperTrainNPC_Text_4:
# 586 "data/scripts/pkmn_center_nurse.pory"
	.string "Your {STR_VAR_1}'s {STR_VAR_3}\n"
	.string "is already at it's maximum!$"

EventScript_HyperTrainNPC_Text_5:
# 606 "data/scripts/pkmn_center_nurse.pory"
	.string "Your {STR_VAR_1}'s {STR_VAR_3}\n"
	.string "has been hyper trained.$"

BPShopClerk_Text_0:
# 626 "data/scripts/pkmn_center_nurse.pory"
	.string "You would like to buy an Eviolite?$"

BPShopClerk_Text_1:
# 638 "data/scripts/pkmn_center_nurse.pory"
	.string "You don't have enough Battle Points.$"

BPShopClerk_Text_2:
# 643 "data/scripts/pkmn_center_nurse.pory"
	.string "You don't have bag space for this item.$"

BPShopClerk_Text_3:
# 651 "data/scripts/pkmn_center_nurse.pory"
	.string "Here is your Eviolite! Thank you very\n"
	.string "much.$"

EggMoveTutor_Text_0:
# 658 "data/scripts/pkmn_center_nurse.pory"
	.string "I can teach one of your Pokémon one of\n"
	.string "their egg moves in exchange for one\l"
	.string "Battle Point.$"

EggMoveTutor_Text_1:
# 661 "data/scripts/pkmn_center_nurse.pory"
	.string "You don't have any Battle Points. Come\n"
	.string "back with some.$"

EggMoveTutor_Text_2:
# 664 "data/scripts/pkmn_center_nurse.pory"
	.string "Would you like to do that?$"

EggMoveTutor_Text_3:
# 676 "data/scripts/pkmn_center_nurse.pory"
	.string "I can't teach a move to an Egg.$"

EggMoveTutor_Text_4:
# 681 "data/scripts/pkmn_center_nurse.pory"
	.string "This Pokémon does not have any egg\n"
	.string "moves.$"

EggMoveTutor_Text_5:
# 685 "data/scripts/pkmn_center_nurse.pory"
	.string "Which move would you like me to teach\n"
	.string "{STR_VAR_1}?$"

EventScript_FishermanSalesman_Text_0:
# 745 "data/scripts/pkmn_center_nurse.pory"
	.string "I am the master fisherman. I have\n"
	.string "travelled all throughout Hoenn and\l"
	.string "caught every type of fish there is.$"

EventScript_FishermanSalesman_Text_1:
# 748 "data/scripts/pkmn_center_nurse.pory"
	.string "You don't have enough money to buy any\n"
	.string "fish. Come back later with more money.$"

EventScript_FishermanSalesman_Text_2:
# 751 "data/scripts/pkmn_center_nurse.pory"
	.string "Would you like to buy one?$"

TryBuyMagikarp_Text_0:
# 796 "data/scripts/pkmn_center_nurse.pory"
	.string "You would like to buy Magikarp for\n"
	.string "¥500?$"

TryBuyMagikarp_Text_1:
# 807 "data/scripts/pkmn_center_nurse.pory"
	.string "Obtained Magikarp.$"

TryBuyMagikarp_Text_2:
# 816 "data/scripts/pkmn_center_nurse.pory"
	.string "You don't have any room in your boxes\n"
	.string "for a new Pokémon.$"

TryBuyGoldeen_Text_0:
# 823 "data/scripts/pkmn_center_nurse.pory"
	.string "You would like to buy Goldeen for ¥500?$"

TryBuyGoldeen_Text_1:
# 834 "data/scripts/pkmn_center_nurse.pory"
	.string "Obtained Goldeen.$"

TryBuyRemoraid_Text_0:
# 850 "data/scripts/pkmn_center_nurse.pory"
	.string "You would like to buy Remoraid for\n"
	.string "¥500?$"

TryBuyRemoraid_Text_1:
# 861 "data/scripts/pkmn_center_nurse.pory"
	.string "Obtained Remoraid.$"

TryBuyFeebas_Text_0:
# 879 "data/scripts/pkmn_center_nurse.pory"
	.string "You don't have enough money to buy\n"
	.string "Feebas. Come back later with more\l"
	.string "money.$"

TryBuyFeebas_Text_1:
# 883 "data/scripts/pkmn_center_nurse.pory"
	.string "You would like to buy Feebas for ¥1000?$"

TryBuyFeebas_Text_2:
# 894 "data/scripts/pkmn_center_nurse.pory"
	.string "Obtained Feebas.$"

TryBuyFinneon_Text_0:
# 912 "data/scripts/pkmn_center_nurse.pory"
	.string "You don't have enough money to buy\n"
	.string "Finneon. Come back later with more\l"
	.string "money.$"

TryBuyFinneon_Text_1:
# 916 "data/scripts/pkmn_center_nurse.pory"
	.string "You would like to buy Finneon for\n"
	.string "¥1000?$"

TryBuyFinneon_Text_2:
# 927 "data/scripts/pkmn_center_nurse.pory"
	.string "Obtained Finneon.$"

TryBuyTynamo_Text_0:
# 945 "data/scripts/pkmn_center_nurse.pory"
	.string "You don't have enough money to buy\n"
	.string "Tynamo. Come back later with more\l"
	.string "money.$"

TryBuyTynamo_Text_1:
# 949 "data/scripts/pkmn_center_nurse.pory"
	.string "You would like to buy Tynamo for ¥1000?$"

TryBuyTynamo_Text_2:
# 960 "data/scripts/pkmn_center_nurse.pory"
	.string "Obtained Tynamo.$"

TryBuyArrokuda_Text_0:
# 978 "data/scripts/pkmn_center_nurse.pory"
	.string "You don't have enough money to buy\n"
	.string "Arrokuda. Come back later with more\l"
	.string "money.$"

TryBuyArrokuda_Text_1:
# 982 "data/scripts/pkmn_center_nurse.pory"
	.string "You would like to buy Arrokuda for\n"
	.string "¥1000?$"

TryBuyArrokuda_Text_2:
# 993 "data/scripts/pkmn_center_nurse.pory"
	.string "Obtained Arrokuda.$"

TryBuyBarboach_Text_0:
# 1011 "data/scripts/pkmn_center_nurse.pory"
	.string "You don't have enough money to buy\n"
	.string "Barboach. Come back later with more\l"
	.string "money.$"

TryBuyBarboach_Text_1:
# 1015 "data/scripts/pkmn_center_nurse.pory"
	.string "You would like to buy Barboach for\n"
	.string "¥1000?$"

TryBuyBarboach_Text_2:
# 1026 "data/scripts/pkmn_center_nurse.pory"
	.string "Obtained Barboach.$"

TryBuyChinchou_Text_0:
# 1044 "data/scripts/pkmn_center_nurse.pory"
	.string "You don't have enough money to buy\n"
	.string "Chinchou. Come back later with more\l"
	.string "money.$"

TryBuyChinchou_Text_1:
# 1048 "data/scripts/pkmn_center_nurse.pory"
	.string "You would like to buy Chinchou for\n"
	.string "¥5000?$"

TryBuyChinchou_Text_2:
# 1059 "data/scripts/pkmn_center_nurse.pory"
	.string "Obtained Chinchou.$"

TryBuyCarvanha_Text_0:
# 1077 "data/scripts/pkmn_center_nurse.pory"
	.string "You don't have enough money to buy\n"
	.string "Carvanha. Come back later with more\l"
	.string "money.$"

TryBuyCarvanha_Text_1:
# 1081 "data/scripts/pkmn_center_nurse.pory"
	.string "You would like to buy Carvanha for\n"
	.string "¥5000?$"

TryBuyCarvanha_Text_2:
# 1092 "data/scripts/pkmn_center_nurse.pory"
	.string "Obtained Carvanha.$"

TryBuyQwilfish_Text_0:
# 1110 "data/scripts/pkmn_center_nurse.pory"
	.string "You don't have enough money to buy\n"
	.string "Qwilfish. Come back later with more\l"
	.string "money.$"

TryBuyQwilfish_Text_1:
# 1114 "data/scripts/pkmn_center_nurse.pory"
	.string "You would like to buy Qwilfish for\n"
	.string "¥10000?$"

TryBuyQwilfish_Text_2:
# 1125 "data/scripts/pkmn_center_nurse.pory"
	.string "Obtained Qwilfish.$"

TryBuyBasculin_Text_0:
# 1143 "data/scripts/pkmn_center_nurse.pory"
	.string "You don't have enough money to buy\n"
	.string "Basculin. Come back later with more\l"
	.string "money.$"

TryBuyBasculin_Text_1:
# 1147 "data/scripts/pkmn_center_nurse.pory"
	.string "You would like to buy Basculin for\n"
	.string "¥10000?$"

TryBuyBasculin_Text_2:
# 1158 "data/scripts/pkmn_center_nurse.pory"
	.string "Obtained Basculin.$"

TryBuyCosmog_Text_0:
# 1176 "data/scripts/pkmn_center_nurse.pory"
	.string "You don't have enough money to buy\n"
	.string "Cosmog. Come back later with more\l"
	.string "money.$"

TryBuyCosmog_Text_1:
# 1180 "data/scripts/pkmn_center_nurse.pory"
	.string "You would like to buy Cosmog for\n"
	.string "¥50000?$"

TryBuyCosmog_Text_2:
# 1191 "data/scripts/pkmn_center_nurse.pory"
	.string "Obtained Cosmog.$"

NicknamePartyMon_Text_0:
# 1207 "data/scripts/pkmn_center_nurse.pory"
	.string "Do you want to give it a nickame?$"
