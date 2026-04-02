# 1 "data/maps/DewfordTown_Gym/scripts.pory"

# 2 "data/maps/DewfordTown_Gym/scripts.pory"
.set LOCALID_PANCHAM, 9
# 3 "data/maps/DewfordTown_Gym/scripts.pory"

# 4 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_MapScripts::
# 5 "data/maps/DewfordTown_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_Gym_OnTransition
# 6 "data/maps/DewfordTown_Gym/scripts.pory"
	.byte 0
# 7 "data/maps/DewfordTown_Gym/scripts.pory"

# 8 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_OnTransition:
# 9 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 10 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 11 "data/maps/DewfordTown_Gym/scripts.pory"

# 12 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel::
# 13 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_defeated TRAINER_BRAWLY_1, DewfordTown_Gym_EventScript_SetLightsOn
# 14 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
# 15 "data/maps/DewfordTown_Gym/scripts.pory"
	copyvar VAR_0x8001, VAR_0x8000
# 16 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 0, DewfordTown_Gym_EventScript_SetFlashLevel7
# 17 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_SetFlashLevel6
# 18 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_SetFlashLevel5
# 19 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_SetFlashLevel4
# 20 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_SetFlashLevel3
# 21 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_SetFlashLevel2
# 22 "data/maps/DewfordTown_Gym/scripts.pory"
	goto DewfordTown_Gym_EventScript_SetFlashLevel1
# 23 "data/maps/DewfordTown_Gym/scripts.pory"

# 24 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetLightsOn::
# 25 "data/maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 0
# 26 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 27 "data/maps/DewfordTown_Gym/scripts.pory"

# 28 "data/maps/DewfordTown_Gym/scripts.pory"
@ Brightest
# 29 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel1::
# 30 "data/maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 1
# 31 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 32 "data/maps/DewfordTown_Gym/scripts.pory"

# 33 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel2::
# 34 "data/maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 2
# 35 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 36 "data/maps/DewfordTown_Gym/scripts.pory"

# 37 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel3::
# 38 "data/maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 3
# 39 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 40 "data/maps/DewfordTown_Gym/scripts.pory"

# 41 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel4::
# 42 "data/maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 4
# 43 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 44 "data/maps/DewfordTown_Gym/scripts.pory"

# 45 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel5::
# 46 "data/maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 5
# 47 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 48 "data/maps/DewfordTown_Gym/scripts.pory"

# 49 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel6::
# 50 "data/maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 6
# 51 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 52 "data/maps/DewfordTown_Gym/scripts.pory"

# 53 "data/maps/DewfordTown_Gym/scripts.pory"
@ Darkest
# 54 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel7::
# 55 "data/maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 7
# 56 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 57 "data/maps/DewfordTown_Gym/scripts.pory"

# 58 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_BrightenRoom::
# 59 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
# 60 "data/maps/DewfordTown_Gym/scripts.pory"
	nop1
# 61 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, VAR_0x8001, DewfordTown_Gym_EventScript_NoLightChange
# 62 "data/maps/DewfordTown_Gym/scripts.pory"
	copyvar VAR_0x8001, VAR_0x8000
# 63 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_AnimateFlash1Trainer
# 64 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_AnimateFlash2Trainers
# 65 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_AnimateFlash3Trainers
# 66 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_AnimateFlash4Trainers
# 67 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_AnimateFlash5Trainers
# 68 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 6, DewfordTown_Gym_EventScript_AnimateFlash6Trainers
# 69 "data/maps/DewfordTown_Gym/scripts.pory"

# 70 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_NoLightChange::
# 71 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 72 "data/maps/DewfordTown_Gym/scripts.pory"

# 73 "data/maps/DewfordTown_Gym/scripts.pory"
@ NOTE: A little confusingly, a larger animateflash param value is a smaller flash radius
# 74 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlash1Trainer::
# 75 "data/maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 76 "data/maps/DewfordTown_Gym/scripts.pory"
	animateflash 6
# 77 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 78 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 79 "data/maps/DewfordTown_Gym/scripts.pory"

# 80 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlash2Trainers::
# 81 "data/maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 82 "data/maps/DewfordTown_Gym/scripts.pory"
	animateflash 5
# 83 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 84 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 85 "data/maps/DewfordTown_Gym/scripts.pory"

# 86 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlash3Trainers::
# 87 "data/maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 88 "data/maps/DewfordTown_Gym/scripts.pory"
	animateflash 4
# 89 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 90 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 91 "data/maps/DewfordTown_Gym/scripts.pory"

# 92 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlash4Trainers::
# 93 "data/maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 94 "data/maps/DewfordTown_Gym/scripts.pory"
	animateflash 3
# 95 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 96 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 97 "data/maps/DewfordTown_Gym/scripts.pory"

# 98 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlash5Trainers::
# 99 "data/maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 100 "data/maps/DewfordTown_Gym/scripts.pory"
	animateflash 2
# 101 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 102 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 103 "data/maps/DewfordTown_Gym/scripts.pory"

# 104 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlash6Trainers::
# 105 "data/maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 106 "data/maps/DewfordTown_Gym/scripts.pory"
	animateflash 1
# 107 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 108 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 109 "data/maps/DewfordTown_Gym/scripts.pory"

# 110 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlashFullBrightness::
# 111 "data/maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 112 "data/maps/DewfordTown_Gym/scripts.pory"
	animateflash 0
# 113 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 114 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 115 "data/maps/DewfordTown_Gym/scripts.pory"

# 116 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CountTrainersDefeated::
# 117 "data/maps/DewfordTown_Gym/scripts.pory"
	setvar VAR_0x8000, 0
# 118 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_TAKAO, DewfordTown_Gym_EventScript_CheckJocelyn
# 119 "data/maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_0x8000, 1
# 120 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CheckJocelyn::
# 121 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_JOCELYN, DewfordTown_Gym_EventScript_CheckLaura
# 122 "data/maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_0x8000, 1
# 123 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CheckLaura::
# 124 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_LAURA, DewfordTown_Gym_EventScript_CheckBrenden
# 125 "data/maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_0x8000, 1
# 126 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CheckBrenden::
# 127 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_BRENDEN, DewfordTown_Gym_EventScript_CheckCristian
# 128 "data/maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_0x8000, 1
# 129 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CheckCristian::
# 130 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_CRISTIAN, DewfordTown_Gym_EventScript_CheckLilith
# 131 "data/maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_0x8000, 1
# 132 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CheckLilith::
# 133 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_LILITH, DewfordTown_Gym_EventScript_StopCountingTrainers
# 134 "data/maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_0x8000, 1
# 135 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_StopCountingTrainers::
# 136 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 137 "data/maps/DewfordTown_Gym/scripts.pory"

# 138 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Brawly::
# 139 "data/maps/DewfordTown_Gym/scripts.pory"
	playse SE_M_BATON_PASS
# 140 "data/maps/DewfordTown_Gym/scripts.pory"
	waitse
# 141 "data/maps/DewfordTown_Gym/scripts.pory"
	removeobject LOCALID_PANCHAM
# 142 "data/maps/DewfordTown_Gym/scripts.pory"
	setflag FLAG_HIDE_BRAWLYS_PANCHAM
# 143 "data/maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyIntro, DewfordTown_Gym_Text_BrawlyDefeat, DewfordTown_Gym_EventScript_BrawlyDefeated, NO_MUSIC
# 144 "data/maps/DewfordTown_Gym/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 145 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Gym_EventScript_BrawlyRematch
# 146 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM_BULK_UP, DewfordTown_Gym_EventScript_GiveBulkUp2
# 147 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_BrawlyPostBattle, MSGBOX_DEFAULT
# 148 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 149 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 150 "data/maps/DewfordTown_Gym/scripts.pory"

# 151 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_BrawlyDefeated::
# 152 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_AnimateFlashFullBrightness
# 153 "data/maps/DewfordTown_Gym/scripts.pory"
	message DewfordTown_Gym_Text_ReceivedKnuckleBadge
# 154 "data/maps/DewfordTown_Gym/scripts.pory"
	waitmessage
# 155 "data/maps/DewfordTown_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 156 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
# 157 "data/maps/DewfordTown_Gym/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 158 "data/maps/DewfordTown_Gym/scripts.pory"
	setflag FLAG_BADGE02_GET
# 159 "data/maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_PETALBURG_GYM_STATE, 1
# 160 "data/maps/DewfordTown_Gym/scripts.pory"
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
# 161 "data/maps/DewfordTown_Gym/scripts.pory"
	setvar VAR_0x8008, 2
# 162 "data/maps/DewfordTown_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 163 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_GiveBulkUp
# 164 "data/maps/DewfordTown_Gym/scripts.pory"
	setvar VAR_GYM2_DEFEATED, 1
# 165 "data/maps/DewfordTown_Gym/scripts.pory"
	closemessage
# 166 "data/maps/DewfordTown_Gym/scripts.pory"
	delay 30
# 167 "data/maps/DewfordTown_Gym/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 168 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_RegisteredBrawly, MSGBOX_DEFAULT
# 169 "data/maps/DewfordTown_Gym/scripts.pory"
	waitfanfare
# 170 "data/maps/DewfordTown_Gym/scripts.pory"
	closemessage
# 171 "data/maps/DewfordTown_Gym/scripts.pory"
	delay 30
# 172 "data/maps/DewfordTown_Gym/scripts.pory"
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
# 173 "data/maps/DewfordTown_Gym/scripts.pory"
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
# 174 "data/maps/DewfordTown_Gym/scripts.pory"
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
# 175 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 176 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 177 "data/maps/DewfordTown_Gym/scripts.pory"

# 178 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_GiveBulkUp::
# 179 "data/maps/DewfordTown_Gym/scripts.pory"
	giveitem ITEM_TM_LOW_SWEEP
# 180 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
# 181 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
# 182 "data/maps/DewfordTown_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_BULK_UP
# 183 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox Gym_Text_AlsoTakeThese, MSGBOX_DEFAULT
# 184 "data/maps/DewfordTown_Gym/scripts.pory"
	giveitem ITEM_BLANK_MINT, 3
# 185 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 186 "data/maps/DewfordTown_Gym/scripts.pory"

# 187 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_GiveBulkUp2:
# 188 "data/maps/DewfordTown_Gym/scripts.pory"
	giveitem ITEM_TM_LOW_SWEEP
# 189 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
# 190 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
# 191 "data/maps/DewfordTown_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_BULK_UP
# 192 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox Gym_Text_AlsoTakeThese, MSGBOX_DEFAULT
# 193 "data/maps/DewfordTown_Gym/scripts.pory"
	giveitem ITEM_BLANK_MINT, 3
# 194 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 195 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 196 "data/maps/DewfordTown_Gym/scripts.pory"

# 197 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_BrawlyRematch::
# 198 "data/maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_rematch_double TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyPreRematch, DewfordTown_Gym_Text_BrawlyRematchDefeat, DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons
# 199 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_BrawlyPostRematch, MSGBOX_AUTOCLOSE
# 200 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 201 "data/maps/DewfordTown_Gym/scripts.pory"

# 202 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Takao::
# 203 "data/maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_TAKAO, DewfordTown_Gym_Text_TakaoIntro, DewfordTown_Gym_Text_TakaoDefeat, DewfordTown_Gym_EventScript_TakaoBrightenRoom
# 204 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
# 205 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 206 "data/maps/DewfordTown_Gym/scripts.pory"

# 207 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_TakaoBrightenRoom::
# 208 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_BrightenRoom
# 209 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 210 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 211 "data/maps/DewfordTown_Gym/scripts.pory"

# 212 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Jocelyn::
# 213 "data/maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_JOCELYN, DewfordTown_Gym_Text_JocelynIntro, DewfordTown_Gym_Text_JocelynDefeat, DewfordTown_Gym_EventScript_JocelynBrightenRoom
# 214 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
# 215 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 216 "data/maps/DewfordTown_Gym/scripts.pory"

# 217 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_JocelynBrightenRoom::
# 218 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_BrightenRoom
# 219 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 220 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 221 "data/maps/DewfordTown_Gym/scripts.pory"

# 222 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Laura::
# 223 "data/maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_LAURA, DewfordTown_Gym_Text_LauraIntro, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
# 224 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
# 225 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 226 "data/maps/DewfordTown_Gym/scripts.pory"

# 227 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_LauraBrightenRoom::
# 228 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_BrightenRoom
# 229 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 230 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 231 "data/maps/DewfordTown_Gym/scripts.pory"

# 232 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Brenden::
# 233 "data/maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_BRENDEN, DewfordTown_Gym_Text_BrendenIntro, DewfordTown_Gym_Text_BrendenDefeat, DewfordTown_Gym_EventScript_BrendenBrightenRoom
# 234 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_BrendenPostBattle, MSGBOX_AUTOCLOSE
# 235 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 236 "data/maps/DewfordTown_Gym/scripts.pory"

# 237 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_BrendenBrightenRoom::
# 238 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_BrightenRoom
# 239 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 240 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 241 "data/maps/DewfordTown_Gym/scripts.pory"

# 242 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Cristian::
# 243 "data/maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_CRISTIAN, DewfordTown_Gym_Text_CristianIntro, DewfordTown_Gym_Text_CristianDefeat, DewfordTown_Gym_EventScript_CristianBrightenRoom
# 244 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
# 245 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 246 "data/maps/DewfordTown_Gym/scripts.pory"

# 247 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CristianBrightenRoom::
# 248 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_BrightenRoom
# 249 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 250 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 251 "data/maps/DewfordTown_Gym/scripts.pory"

# 252 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Lilith::
# 253 "data/maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_LILITH, DewfordTown_Gym_Text_LilithIntro, DewfordTown_Gym_Text_LilithDefeat, DewfordTown_Gym_EventScript_LilithBrightenRoom
# 254 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
# 255 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 256 "data/maps/DewfordTown_Gym/scripts.pory"

# 257 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_LilithBrightenRoom::
# 258 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_BrightenRoom
# 259 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 260 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 261 "data/maps/DewfordTown_Gym/scripts.pory"

# 262 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_GymGuide::
# 263 "data/maps/DewfordTown_Gym/scripts.pory"
	lock
# 264 "data/maps/DewfordTown_Gym/scripts.pory"
	faceplayer
# 265 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_DEWFORD_GYM, DewfordTown_Gym_EventScript_GymGuidePostVictory
# 266 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
# 267 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 268 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 269 "data/maps/DewfordTown_Gym/scripts.pory"

# 270 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_GymGuidePostVictory::
# 271 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
# 272 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 273 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 274 "data/maps/DewfordTown_Gym/scripts.pory"

# 275 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_LeftGymStatue::
# 276 "data/maps/DewfordTown_Gym/scripts.pory"
	lockall
# 277 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
# 278 "data/maps/DewfordTown_Gym/scripts.pory"
	goto DewfordTown_Gym_EventScript_GymStatue
# 279 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 280 "data/maps/DewfordTown_Gym/scripts.pory"

# 281 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_RightGymStatue::
# 282 "data/maps/DewfordTown_Gym/scripts.pory"
	lockall
# 283 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
# 284 "data/maps/DewfordTown_Gym/scripts.pory"
	goto DewfordTown_Gym_EventScript_GymStatue
# 285 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 286 "data/maps/DewfordTown_Gym/scripts.pory"

# 287 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_GymStatueCertified::
# 288 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 289 "data/maps/DewfordTown_Gym/scripts.pory"
	releaseall
# 290 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 291 "data/maps/DewfordTown_Gym/scripts.pory"

# 292 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_GymStatue::
# 293 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 294 "data/maps/DewfordTown_Gym/scripts.pory"
	releaseall
# 295 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 296 "data/maps/DewfordTown_Gym/scripts.pory"

# 297 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_GymGuideAdvice:
# 298 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Hey, how's it going, CHAMPION-\n"
# 299 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "bound {PLAYER}?\p"
# 300 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "DEWFORD's GYM LEADER BRAWLY commands\n"
# 301 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "FIGHTING-type POKéMON.\p"
# 302 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Going against him with NORMAL-type\n"
# 303 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "POKéMON is asking for trouble.\p"
# 304 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "FIGHTING POKéMON will lay a serious\n"
# 305 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "smack down on NORMAL POKéMON,\l"
# 306 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "so be careful!\p"
# 307 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "What's worse, the GYM is as dark as\n"
# 308 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "the ocean floor.\p"
# 309 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "But it will get brighter after defeating\n"
# 310 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "the TRAINERS in your way.\p"
# 311 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Hey, okay, go for it!$"
# 312 "data/maps/DewfordTown_Gym/scripts.pory"

# 313 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_GymGuidePostVictory:
# 314 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Whoah! It's turned too bright in here!\p"
# 315 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Your future is bright, too!$"
# 316 "data/maps/DewfordTown_Gym/scripts.pory"

# 317 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_TakaoIntro:
# 318 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Might is right!\n"
# 319 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Come on!$"
# 320 "data/maps/DewfordTown_Gym/scripts.pory"

# 321 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_TakaoDefeat:
# 322 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Not enough power…$"
# 323 "data/maps/DewfordTown_Gym/scripts.pory"

# 324 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_TakaoPostBattle:
# 325 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Your skill overcame my strength!\n"
# 326 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Your technique is commendable!$"
# 327 "data/maps/DewfordTown_Gym/scripts.pory"

# 328 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_JocelynIntro:
# 329 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "There's no need for BRAWLY to be\n"
# 330 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "involved!\p"
# 331 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I'll crush you!$"
# 332 "data/maps/DewfordTown_Gym/scripts.pory"

# 333 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_JocelynDefeat:
# 334 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "But… How?\n"
# 335 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "How could I lose so easily?$"
# 336 "data/maps/DewfordTown_Gym/scripts.pory"

# 337 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_JocelynPostBattle:
# 338 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I'm not going to waste this loss.\n"
# 339 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I'll use it to motivate me to train!\p"
# 340 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "One day I'll become a GYM LEADER…\p"
# 341 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "No, I'll become the POKéMON LEAGUE\n"
# 342 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "CHAMPION!$"
# 343 "data/maps/DewfordTown_Gym/scripts.pory"

# 344 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_LauraIntro:
# 345 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Don't you dare brush me off!\n"
# 346 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "It's not my fault if you cry!$"
# 347 "data/maps/DewfordTown_Gym/scripts.pory"

# 348 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_LauraDefeat:
# 349 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Waaaaaaah!\n"
# 350 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I lost!$"
# 351 "data/maps/DewfordTown_Gym/scripts.pory"

# 352 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_LauraPostBattle:
# 353 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I battle in the dark to make my heart\n"
# 354 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "stronger.\p"
# 355 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "But because it's so dark, I can never\n"
# 356 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "see BRAWLY's face…$"
# 357 "data/maps/DewfordTown_Gym/scripts.pory"

# 358 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_LilithIntro:
# 359 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Ufufu…\n"
# 360 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Are you stumbling around in the dark?$"
# 361 "data/maps/DewfordTown_Gym/scripts.pory"

# 362 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_LilithDefeat:
# 363 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Oh, you…\n"
# 364 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I don't want to know you!$"
# 365 "data/maps/DewfordTown_Gym/scripts.pory"

# 366 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_LilithPostBattle:
# 367 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "You deserve to stay lost and end up\n"
# 368 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "back at the entrance again!$"
# 369 "data/maps/DewfordTown_Gym/scripts.pory"

# 370 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrendenIntro:
# 371 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I'll show you the gumption of\n"
# 372 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "a sailing man!$"
# 373 "data/maps/DewfordTown_Gym/scripts.pory"

# 374 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrendenDefeat:
# 375 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "How'd this happen?\n"
# 376 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "It's not like me to lose this way!$"
# 377 "data/maps/DewfordTown_Gym/scripts.pory"

# 378 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrendenPostBattle:
# 379 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Oh, aye! You're worthy of seeing\n"
# 380 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "our GYM LEADER.$"
# 381 "data/maps/DewfordTown_Gym/scripts.pory"

# 382 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_CristianIntro:
# 383 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "If you mean to pass, it has to be\n"
# 384 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "through me!$"
# 385 "data/maps/DewfordTown_Gym/scripts.pory"

# 386 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_CristianDefeat:
# 387 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Grrrrr!\n"
# 388 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Vastly overpowered!$"
# 389 "data/maps/DewfordTown_Gym/scripts.pory"

# 390 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_CristianPostBattle:
# 391 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "You win!\n"
# 392 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Go after that BADGE!$"
# 393 "data/maps/DewfordTown_Gym/scripts.pory"

# 394 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyIntro:
# 395 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I'm BRAWLY!\n"
# 396 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "DEWFORD's GYM LEADER!\p"
# 397 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I've been churned in the rough waves\n"
# 398 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "of these parts, and I've grown tough\l"
# 399 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "in the pitch-black cave!\p"
# 400 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "So you wanted to challenge me?\n"
# 401 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Let me see what you're made of!$"
# 402 "data/maps/DewfordTown_Gym/scripts.pory"

# 403 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyDefeat:
# 404 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Whoah, wow! You made a much bigger\n"
# 405 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "splash than I expected!\p"
# 406 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "You swamped me!\p"
# 407 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Okay, you've got me.\n"
# 408 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Take this GYM BADGE!$"
# 409 "data/maps/DewfordTown_Gym/scripts.pory"

# 410 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_ReceivedKnuckleBadge:
# 411 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "{PLAYER} received the KNUCKLE BADGE\n"
# 412 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "from BRAWLY.$"
# 413 "data/maps/DewfordTown_Gym/scripts.pory"

# 414 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis:
# 415 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "The KNUCKLE BADGE makes all POKéMON\n"
# 416 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "up to Level 30, even those you get in\l"
# 417 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "trades, obey without question.\p"
# 418 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "And, you'll be able to use the HM move\n"
# 419 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "FLASH outside of battle.\p"
# 420 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "If you'd like, use this TECHNICAL\n"
# 421 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "MACHINE, too.$"
# 422 "data/maps/DewfordTown_Gym/scripts.pory"

# 423 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_ExplainBulkUp:
# 424 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "That TM49 contains LOW SWEEP.\p"
# 425 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "It's an attack that lowers the\n"
# 426 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "target's SPEED.\p"
# 427 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "… … … … … …$"
# 428 "data/maps/DewfordTown_Gym/scripts.pory"

# 429 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_RegisteredBrawly:
# 430 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Registered GYM LEADER BRAWLY\n"
# 431 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "in the POKéNAV.$"
# 432 "data/maps/DewfordTown_Gym/scripts.pory"

# 433 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyPostBattle:
# 434 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I can see your talent becoming a giant\n"
# 435 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "wave to cause a storm of astonishment\l"
# 436 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "among TRAINERS one day!$"
# 437 "data/maps/DewfordTown_Gym/scripts.pory"

# 438 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_GymStatue:
# 439 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "DEWFORD TOWN POKéMON GYM$"
# 440 "data/maps/DewfordTown_Gym/scripts.pory"

# 441 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_GymStatueCertified:
# 442 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "DEWFORD TOWN POKéMON GYM\p"
# 443 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "BRAWLY'S CERTIFIED TRAINERS:\n"
# 444 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "{PLAYER}$"
# 445 "data/maps/DewfordTown_Gym/scripts.pory"

# 446 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyPreRematch:
# 447 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "BRAWLY: A wave may draw back, but it\n"
# 448 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "always returns to the shore.\p"
# 449 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "A giant wave of a talent like you…\n"
# 450 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I knew you would return!\p"
# 451 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Show me how much higher\n"
# 452 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "you've gone!$"
# 453 "data/maps/DewfordTown_Gym/scripts.pory"

# 454 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyRematchDefeat:
# 455 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Wow!\n"
# 456 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Swamped again!$"
# 457 "data/maps/DewfordTown_Gym/scripts.pory"

# 458 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyPostRematch:
# 459 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "BRAWLY: Battling is vast and it's deep.\n"
# 460 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "You can't see the bottom.\l"
# 461 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "It's just like the sea of HOENN!$"
# 462 "data/maps/DewfordTown_Gym/scripts.pory"

# 463 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons:
# 464 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "BRAWLY: A wave may draw back, but it\n"
# 465 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "always returns to the shore.\p"
# 466 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "A giant wave of a talent like you…\n"
# 467 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I knew you would return!\p"
# 468 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Oh? You only have one POKéMON\n"
# 469 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "that can battle.\p"
# 470 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I'm sorry, but I'd like you to come back\n"
# 471 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "with at least two POKéMON.$"
