# 1 "data/maps/MauvilleCity_Gym/scripts.pory"

# 2 "data/maps/MauvilleCity_Gym/scripts.pory"
.set LOCALID_MAGNEMITE, 8
# 3 "data/maps/MauvilleCity_Gym/scripts.pory"

# 4 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_MapScripts::
# 5 "data/maps/MauvilleCity_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, MauvilleCity_Gym_OnLoad
# 6 "data/maps/MauvilleCity_Gym/scripts.pory"
	.byte 0
# 7 "data/maps/MauvilleCity_Gym/scripts.pory"

# 8 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_OnLoad:
# 9 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_DeactivatePuzzle
# 10 "data/maps/MauvilleCity_Gym/scripts.pory"
	switch VAR_MAUVILLE_GYM_STATE
# 11 "data/maps/MauvilleCity_Gym/scripts.pory"
	case 0, MauvilleCity_Gym_EventScript_UpdateBarriers
# 12 "data/maps/MauvilleCity_Gym/scripts.pory"
	case 1, MauvilleCity_Gym_EventScript_Switch1Pressed
# 13 "data/maps/MauvilleCity_Gym/scripts.pory"
	case 2, MauvilleCity_Gym_EventScript_Switch2Pressed
# 14 "data/maps/MauvilleCity_Gym/scripts.pory"
	case 3, MauvilleCity_Gym_EventScript_Switch3Pressed
# 15 "data/maps/MauvilleCity_Gym/scripts.pory"
	case 4, MauvilleCity_Gym_EventScript_Switch4Pressed
# 16 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 17 "data/maps/MauvilleCity_Gym/scripts.pory"

# 18 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_UpdateBarriers::
# 19 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetAltBarriers
# 20 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 21 "data/maps/MauvilleCity_Gym/scripts.pory"

# 22 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_SetAltBarriers::
# 23 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 3, 11, METATILE_MauvilleGym_RedBeamV1_On, TRUE
# 24 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 3, 12, METATILE_MauvilleGym_RedBeamV2_On, TRUE
# 25 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 3, 13, METATILE_MauvilleGym_PoleTop_On, TRUE
# 26 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 4, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
# 27 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 5, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
# 28 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 4, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
# 29 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 5, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
# 30 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 7, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
# 31 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 8, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
# 32 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 7, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
# 33 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 8, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
# 34 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 4, 13, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
# 35 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 5, 13, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
# 36 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 4, 14, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
# 37 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 5, 14, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
# 38 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 1, 10, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
# 39 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 2, 10, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
# 40 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 1, 11, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
# 41 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 2, 11, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
# 42 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 6, 8, METATILE_MauvilleGym_PoleBottom_On, TRUE
# 43 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 6, 9, METATILE_MauvilleGym_FloorTile, FALSE
# 44 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 6, 10, METATILE_MauvilleGym_PoleTop_Off, FALSE
# 45 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 4, 6, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
# 46 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 5, 6, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
# 47 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 4, 7, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
# 48 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 5, 7, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
# 49 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 50 "data/maps/MauvilleCity_Gym/scripts.pory"

# 51 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Switch1Pressed::
# 52 "data/maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_0x8004, 0
# 53 "data/maps/MauvilleCity_Gym/scripts.pory"
	special MauvilleGymPressSwitch
# 54 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
# 55 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 56 "data/maps/MauvilleCity_Gym/scripts.pory"

# 57 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Switch2Pressed::
# 58 "data/maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_0x8004, 1
# 59 "data/maps/MauvilleCity_Gym/scripts.pory"
	special MauvilleGymPressSwitch
# 60 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
# 61 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 62 "data/maps/MauvilleCity_Gym/scripts.pory"

# 63 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Switch3Pressed::
# 64 "data/maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_0x8004, 2
# 65 "data/maps/MauvilleCity_Gym/scripts.pory"
	special MauvilleGymPressSwitch
# 66 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
# 67 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 68 "data/maps/MauvilleCity_Gym/scripts.pory"

# 69 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Switch4Pressed::
# 70 "data/maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_0x8004, 3
# 71 "data/maps/MauvilleCity_Gym/scripts.pory"
	special MauvilleGymPressSwitch
# 72 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
# 73 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 74 "data/maps/MauvilleCity_Gym/scripts.pory"

# 75 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_DeactivatePuzzle::
# 76 "data/maps/MauvilleCity_Gym/scripts.pory"
	special MauvilleGymDeactivatePuzzle
# 77 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 78 "data/maps/MauvilleCity_Gym/scripts.pory"

# 79 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Wattson::
# 80 "data/maps/MauvilleCity_Gym/scripts.pory"
	playse SE_M_BATON_PASS
# 81 "data/maps/MauvilleCity_Gym/scripts.pory"
	waitse
# 82 "data/maps/MauvilleCity_Gym/scripts.pory"
	removeobject LOCALID_MAGNEMITE
# 83 "data/maps/MauvilleCity_Gym/scripts.pory"
	setflag FLAG_HIDE_WATTSONS_MAGNEMITE
# 84 "data/maps/MauvilleCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonIntro, MauvilleCity_Gym_Text_WattsonDefeat, MauvilleCity_Gym_EventScript_WattsonDefeated, NO_MUSIC
# 85 "data/maps/MauvilleCity_Gym/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 86 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_Gym_EventScript_WattsonRematch
# 87 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM_SHOCK_WAVE, MauvilleCity_Gym_EventScript_GiveShockWave2
# 88 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_Gym_EventScript_CompletedNewMauville
# 89 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_WattsonPostBattle, MSGBOX_DEFAULT
# 90 "data/maps/MauvilleCity_Gym/scripts.pory"
	release
# 91 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 92 "data/maps/MauvilleCity_Gym/scripts.pory"

# 93 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_WattsonDefeated::
# 94 "data/maps/MauvilleCity_Gym/scripts.pory"
	message MauvilleCity_Gym_Text_ReceivedDynamoBadge
# 95 "data/maps/MauvilleCity_Gym/scripts.pory"
	waitmessage
# 96 "data/maps/MauvilleCity_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 97 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis, MSGBOX_DEFAULT
# 98 "data/maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
# 99 "data/maps/MauvilleCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
# 100 "data/maps/MauvilleCity_Gym/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 101 "data/maps/MauvilleCity_Gym/scripts.pory"
	setflag FLAG_BADGE03_GET
# 102 "data/maps/MauvilleCity_Gym/scripts.pory"
	addvar VAR_PETALBURG_GYM_STATE, 1
# 103 "data/maps/MauvilleCity_Gym/scripts.pory"
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
# 104 "data/maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_0x8008, 3
# 105 "data/maps/MauvilleCity_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 106 "data/maps/MauvilleCity_Gym/scripts.pory"
	special MauvilleGymDeactivatePuzzle
# 107 "data/maps/MauvilleCity_Gym/scripts.pory"
	special DrawWholeMapView
# 108 "data/maps/MauvilleCity_Gym/scripts.pory"
	playse SE_UNLOCK
# 109 "data/maps/MauvilleCity_Gym/scripts.pory"
	call MauvilleCity_Gym_EventScript_GiveShockWave
# 110 "data/maps/MauvilleCity_Gym/scripts.pory"
	closemessage
# 111 "data/maps/MauvilleCity_Gym/scripts.pory"
	delay 30
# 112 "data/maps/MauvilleCity_Gym/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 113 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_RegisteredWattson, MSGBOX_DEFAULT
# 114 "data/maps/MauvilleCity_Gym/scripts.pory"
	waitfanfare
# 115 "data/maps/MauvilleCity_Gym/scripts.pory"
	closemessage
# 116 "data/maps/MauvilleCity_Gym/scripts.pory"
	delay 30
# 117 "data/maps/MauvilleCity_Gym/scripts.pory"
	setflag FLAG_ENABLE_WATTSON_MATCH_CALL
# 118 "data/maps/MauvilleCity_Gym/scripts.pory"
	release
# 119 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 120 "data/maps/MauvilleCity_Gym/scripts.pory"

# 121 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_GiveShockWave2::
# 122 "data/maps/MauvilleCity_Gym/scripts.pory"
	giveitem ITEM_TM_VOLT_SWITCH
# 123 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 124 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
# 125 "data/maps/MauvilleCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
# 126 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox Gym_Text_AlsoTakeThese, MSGBOX_DEFAULT
# 127 "data/maps/MauvilleCity_Gym/scripts.pory"
	giveitem ITEM_BLANK_MINT, 3
# 128 "data/maps/MauvilleCity_Gym/scripts.pory"
	release
# 129 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 130 "data/maps/MauvilleCity_Gym/scripts.pory"

# 131 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_GiveShockWave::
# 132 "data/maps/MauvilleCity_Gym/scripts.pory"
	giveitem ITEM_TM_VOLT_SWITCH
# 133 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
# 134 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
# 135 "data/maps/MauvilleCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
# 136 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox Gym_Text_AlsoTakeThese, MSGBOX_DEFAULT
# 137 "data/maps/MauvilleCity_Gym/scripts.pory"
	giveitem ITEM_BLANK_MINT, 3
# 138 "data/maps/MauvilleCity_Gym/scripts.pory"
	return
# 139 "data/maps/MauvilleCity_Gym/scripts.pory"

# 140 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_CompletedNewMauville::
# 141 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor, MSGBOX_DEFAULT
# 142 "data/maps/MauvilleCity_Gym/scripts.pory"
	release
# 143 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 144 "data/maps/MauvilleCity_Gym/scripts.pory"

# 145 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_WattsonRematch::
# 146 "data/maps/MauvilleCity_Gym/scripts.pory"
	trainerbattle_rematch_double TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonPreRematch, MauvilleCity_Gym_Text_WattsonRematchDefeat, MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons
# 147 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_WattsonPostRematch, MSGBOX_AUTOCLOSE
# 148 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 149 "data/maps/MauvilleCity_Gym/scripts.pory"

# 150 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Switch1::
# 151 "data/maps/MauvilleCity_Gym/scripts.pory"
	lockall
# 152 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
# 153 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 1, MauvilleCity_Gym_EventScript_SwitchDoNothing
# 154 "data/maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_MAUVILLE_GYM_STATE, 1
# 155 "data/maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_0x8004, 0
# 156 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
# 157 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 158 "data/maps/MauvilleCity_Gym/scripts.pory"

# 159 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Switch2::
# 160 "data/maps/MauvilleCity_Gym/scripts.pory"
	lockall
# 161 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
# 162 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 2, MauvilleCity_Gym_EventScript_SwitchDoNothing
# 163 "data/maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_MAUVILLE_GYM_STATE, 2
# 164 "data/maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_0x8004, 1
# 165 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
# 166 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 167 "data/maps/MauvilleCity_Gym/scripts.pory"

# 168 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Switch3::
# 169 "data/maps/MauvilleCity_Gym/scripts.pory"
	lockall
# 170 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
# 171 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 3, MauvilleCity_Gym_EventScript_SwitchDoNothing
# 172 "data/maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_MAUVILLE_GYM_STATE, 3
# 173 "data/maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_0x8004, 2
# 174 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
# 175 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 176 "data/maps/MauvilleCity_Gym/scripts.pory"

# 177 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Switch4::
# 178 "data/maps/MauvilleCity_Gym/scripts.pory"
	lockall
# 179 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
# 180 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 4, MauvilleCity_Gym_EventScript_SwitchDoNothing
# 181 "data/maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_MAUVILLE_GYM_STATE, 4
# 182 "data/maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_0x8004, 3
# 183 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
# 184 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 185 "data/maps/MauvilleCity_Gym/scripts.pory"

# 186 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_PressFloorSwitch::
# 187 "data/maps/MauvilleCity_Gym/scripts.pory"
	special MauvilleGymSetDefaultBarriers
# 188 "data/maps/MauvilleCity_Gym/scripts.pory"
	special MauvilleGymPressSwitch
# 189 "data/maps/MauvilleCity_Gym/scripts.pory"
	special DrawWholeMapView
# 190 "data/maps/MauvilleCity_Gym/scripts.pory"
	playse SE_UNLOCK
# 191 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_ClearBarriersAltState
# 192 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_unset FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetBarriersAltState
# 193 "data/maps/MauvilleCity_Gym/scripts.pory"
	releaseall
# 194 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 195 "data/maps/MauvilleCity_Gym/scripts.pory"

# 196 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_SwitchDoNothing::
# 197 "data/maps/MauvilleCity_Gym/scripts.pory"
	releaseall
# 198 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 199 "data/maps/MauvilleCity_Gym/scripts.pory"

# 200 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_SetBarriersAltState::
# 201 "data/maps/MauvilleCity_Gym/scripts.pory"
	setflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
# 202 "data/maps/MauvilleCity_Gym/scripts.pory"
	releaseall
# 203 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 204 "data/maps/MauvilleCity_Gym/scripts.pory"

# 205 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_ClearBarriersAltState::
# 206 "data/maps/MauvilleCity_Gym/scripts.pory"
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
# 207 "data/maps/MauvilleCity_Gym/scripts.pory"
	releaseall
# 208 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 209 "data/maps/MauvilleCity_Gym/scripts.pory"

# 210 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Kirk::
# 211 "data/maps/MauvilleCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_KIRK, MauvilleCity_Gym_Text_KirkIntro, MauvilleCity_Gym_Text_KirkDefeat
# 212 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
# 213 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 214 "data/maps/MauvilleCity_Gym/scripts.pory"

# 215 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Shawn::
# 216 "data/maps/MauvilleCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_SHAWN, MauvilleCity_Gym_Text_ShawnIntro, MauvilleCity_Gym_Text_ShawnDefeat
# 217 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
# 218 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 219 "data/maps/MauvilleCity_Gym/scripts.pory"

# 220 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Ben::
# 221 "data/maps/MauvilleCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_BEN, MauvilleCity_Gym_Text_BenIntro, MauvilleCity_Gym_Text_BenDefeat
# 222 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_BenPostBattle, MSGBOX_AUTOCLOSE
# 223 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 224 "data/maps/MauvilleCity_Gym/scripts.pory"

# 225 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Vivian::
# 226 "data/maps/MauvilleCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_VIVIAN, MauvilleCity_Gym_Text_VivianIntro, MauvilleCity_Gym_Text_VivianDefeat
# 227 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_VivianPostBattle, MSGBOX_AUTOCLOSE
# 228 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 229 "data/maps/MauvilleCity_Gym/scripts.pory"

# 230 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Angelo::
# 231 "data/maps/MauvilleCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_ANGELO, MauvilleCity_Gym_Text_AngeloIntro, MauvilleCity_Gym_Text_AngeloDefeat
# 232 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_AngeloPostBattle, MSGBOX_AUTOCLOSE
# 233 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 234 "data/maps/MauvilleCity_Gym/scripts.pory"

# 235 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_GymGuide::
# 236 "data/maps/MauvilleCity_Gym/scripts.pory"
	lock
# 237 "data/maps/MauvilleCity_Gym/scripts.pory"
	faceplayer
# 238 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_GymGuidePostVictory
# 239 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
# 240 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_unset FLAG_RECEIVED_MEGA_RING, MauvilleCity_Gym_EventScript_GiveMegaRing
# 241 "data/maps/MauvilleCity_Gym/scripts.pory"
	release
# 242 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 243 "data/maps/MauvilleCity_Gym/scripts.pory"

# 244 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_GiveMegaRing::
# 245 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_GiveMegaRing, MSGBOX_DEFAULT
# 246 "data/maps/MauvilleCity_Gym/scripts.pory"
	giveitem ITEM_MEGA_RING
# 247 "data/maps/MauvilleCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_MEGA_RING
# 248 "data/maps/MauvilleCity_Gym/scripts.pory"
	release
# 249 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 250 "data/maps/MauvilleCity_Gym/scripts.pory"

# 251 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_GiveMegaRingPostGym::
# 252 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_GiveMegaRingPostGym, MSGBOX_DEFAULT
# 253 "data/maps/MauvilleCity_Gym/scripts.pory"
	giveitem ITEM_MEGA_RING
# 254 "data/maps/MauvilleCity_Gym/scripts.pory"
	release
# 255 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 256 "data/maps/MauvilleCity_Gym/scripts.pory"

# 257 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_GymGuidePostVictory::
# 258 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
# 259 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_unset FLAG_RECEIVED_MEGA_RING, MauvilleCity_Gym_EventScript_GiveMegaRingPostGym
# 260 "data/maps/MauvilleCity_Gym/scripts.pory"
	release
# 261 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 262 "data/maps/MauvilleCity_Gym/scripts.pory"

# 263 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_LeftGymStatue::
# 264 "data/maps/MauvilleCity_Gym/scripts.pory"
	lockall
# 265 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
# 266 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_GymStatue
# 267 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 268 "data/maps/MauvilleCity_Gym/scripts.pory"

# 269 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_RightGymStatue::
# 270 "data/maps/MauvilleCity_Gym/scripts.pory"
	lockall
# 271 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
# 272 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_GymStatue
# 273 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 274 "data/maps/MauvilleCity_Gym/scripts.pory"

# 275 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_GymStatueCertified::
# 276 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 277 "data/maps/MauvilleCity_Gym/scripts.pory"
	releaseall
# 278 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 279 "data/maps/MauvilleCity_Gym/scripts.pory"

# 280 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_GymStatue::
# 281 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 282 "data/maps/MauvilleCity_Gym/scripts.pory"
	releaseall
# 283 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 284 "data/maps/MauvilleCity_Gym/scripts.pory"

# 285 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_GymGuideAdvice:
# 286 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Hey, how's it going, CHAMPION-\n"
# 287 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "bound {PLAYER}?\p"
# 288 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "WATTSON, the LEADER of MAUVILLE\n"
# 289 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "GYM, uses ELECTRIC-type POKéMON.\p"
# 290 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "If you challenge him with WATER-type\n"
# 291 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "POKéMON, he'll zap them! Bzzt!\p"
# 292 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "And, he's put in switch-controlled\n"
# 293 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "doors all over his GYM! Eccentric!\p"
# 294 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Hey, go for it!$"
# 295 "data/maps/MauvilleCity_Gym/scripts.pory"

# 296 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_GymGuidePostVictory:
# 297 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Whoa, you're electrifying!\n"
# 298 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "You've powered the door open!$"
# 299 "data/maps/MauvilleCity_Gym/scripts.pory"

# 300 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_KirkIntro:
# 301 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "My electric soul, it'll shatter your\n"
# 302 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "dreams whole, whoa-yeahah!$"
# 303 "data/maps/MauvilleCity_Gym/scripts.pory"

# 304 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_KirkDefeat:
# 305 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "That was plugged in, amped up,\n"
# 306 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "over-driven electric, man!$"
# 307 "data/maps/MauvilleCity_Gym/scripts.pory"

# 308 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_KirkPostBattle:
# 309 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "POKéMON and rock, it's all about heart,\n"
# 310 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "whoa-yeah!$"
# 311 "data/maps/MauvilleCity_Gym/scripts.pory"

# 312 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_ShawnIntro:
# 313 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "I trained under WATTSON!\n"
# 314 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "There ain't no way I'll lose easily!$"
# 315 "data/maps/MauvilleCity_Gym/scripts.pory"

# 316 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_ShawnDefeat:
# 317 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Unplugged and turned off…$"
# 318 "data/maps/MauvilleCity_Gym/scripts.pory"

# 319 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_ShawnPostBattle:
# 320 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "WATTSON, our GYM LEADER, has been\n"
# 321 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "around for a long, long time.\p"
# 322 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "He was battling even before your\n"
# 323 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "daddy was born, that tough coot.$"
# 324 "data/maps/MauvilleCity_Gym/scripts.pory"

# 325 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_BenIntro:
# 326 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "This GYM's got puzzles!\n"
# 327 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Isn't it fun?$"
# 328 "data/maps/MauvilleCity_Gym/scripts.pory"

# 329 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_BenDefeat:
# 330 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "It's no fun to lose…$"
# 331 "data/maps/MauvilleCity_Gym/scripts.pory"

# 332 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_BenPostBattle:
# 333 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "WATTSON says he likes setting up\n"
# 334 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "little traps with switches.$"
# 335 "data/maps/MauvilleCity_Gym/scripts.pory"

# 336 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_VivianIntro:
# 337 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "With my charm and my POKéMON's moves,\n"
# 338 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "you'll be shocked!$"
# 339 "data/maps/MauvilleCity_Gym/scripts.pory"

# 340 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_VivianDefeat:
# 341 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "I'm shocked by your power!$"
# 342 "data/maps/MauvilleCity_Gym/scripts.pory"

# 343 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_VivianPostBattle:
# 344 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "I've heard that MAUVILLE was founded\n"
# 345 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "by WATTSON.\p"
# 346 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "He was a TRAINER long before we\n"
# 347 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "became TRAINERS.\l"
# 348 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "He must know all sorts of things!$"
# 349 "data/maps/MauvilleCity_Gym/scripts.pory"

# 350 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_AngeloIntro:
# 351 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "I love shiny things!$"
# 352 "data/maps/MauvilleCity_Gym/scripts.pory"

# 353 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_AngeloDefeat:
# 354 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Oh…\n"
# 355 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "My eyes are frazzled…$"
# 356 "data/maps/MauvilleCity_Gym/scripts.pory"

# 357 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_AngeloPostBattle:
# 358 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "MAUVILLE GYM's WATTSON has a shiny\n"
# 359 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "forehead. It makes me happy!$"
# 360 "data/maps/MauvilleCity_Gym/scripts.pory"

# 361 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_WattsonIntro:
# 362 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "I've given up on my plans to convert\n"
# 363 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "the city, I have.\p"
# 364 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "And so, I put my time into making\n"
# 365 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "door traps in my GYM.\p"
# 366 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Oh? Now, what are you doing here?\p"
# 367 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "What's that? You say you've gotten\n"
# 368 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "past all my rigged doors?\p"
# 369 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Wahahahah!\n"
# 370 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Now, that is amusing!\p"
# 371 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Then, I, WATTSON, the LEADER of\n"
# 372 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "MAUVILLE GYM, shall electrify you!$"
# 373 "data/maps/MauvilleCity_Gym/scripts.pory"

# 374 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_WattsonDefeat:
# 375 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Wahahahah!\n"
# 376 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Fine, I lost!\p"
# 377 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "You ended up giving me a thrill!\n"
# 378 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Take this BADGE!$"
# 379 "data/maps/MauvilleCity_Gym/scripts.pory"

# 380 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_ReceivedDynamoBadge:
# 381 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "{PLAYER} received the DYNAMO BADGE\n"
# 382 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "from WATTSON.$"
# 383 "data/maps/MauvilleCity_Gym/scripts.pory"

# 384 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis:
# 385 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "With the DYNAMO BADGE, POKéMON can\n"
# 386 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "use ROCK SMASH out of battle.\p"
# 387 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "And, it will make your POKéMON a little\n"
# 388 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "bit faster, too.\p"
# 389 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Hmm…\n"
# 390 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "You should take this, too!$"
# 391 "data/maps/MauvilleCity_Gym/scripts.pory"

# 392 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_ExplainShockWave:
# 393 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "That TM80 there contains VOLT SWITCH.\p"
# 394 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "It's an attack that does damage\n"
# 395 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "and switched out the user!\p"
# 396 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "… … … … … …$"
# 397 "data/maps/MauvilleCity_Gym/scripts.pory"

# 398 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_RegisteredWattson:
# 399 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Registered GYM LEADER WATTSON\n"
# 400 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "in the POKéNAV.$"
# 401 "data/maps/MauvilleCity_Gym/scripts.pory"

# 402 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_WattsonPostBattle:
# 403 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "I swell with optimism, seeing a promising\n"
# 404 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "young TRAINER like you!$"
# 405 "data/maps/MauvilleCity_Gym/scripts.pory"

# 406 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor:
# 407 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Wahahahah!\n"
# 408 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Go forth and endeavor, youngster!$"
# 409 "data/maps/MauvilleCity_Gym/scripts.pory"

# 410 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_GymStatue:
# 411 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "MAUVILLE CITY POKéMON GYM$"
# 412 "data/maps/MauvilleCity_Gym/scripts.pory"

# 413 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_GymStatueCertified:
# 414 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "MAUVILLE CITY POKéMON GYM\p"
# 415 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "WATTSON'S CERTIFIED TRAINERS:\n"
# 416 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "{PLAYER}$"
# 417 "data/maps/MauvilleCity_Gym/scripts.pory"

# 418 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_WattsonPreRematch:
# 419 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "WATTSON: Ah-ha! Here at last!\n"
# 420 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "I know what you want.\l"
# 421 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "You want to battle my POKéMON!\p"
# 422 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Wahahahaha!\p"
# 423 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "I'll make sparks fly from you!\n"
# 424 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Don't say I didn't warn you!$"
# 425 "data/maps/MauvilleCity_Gym/scripts.pory"

# 426 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_WattsonRematchDefeat:
# 427 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Oof…\n"
# 428 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Our batteries ran dry…$"
# 429 "data/maps/MauvilleCity_Gym/scripts.pory"

# 430 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_WattsonPostRematch:
# 431 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "WATTSON: We'll have to recharge our\n"
# 432 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "batteries again.\p"
# 433 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "When we're fully charged up, we'll\n"
# 434 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "gladly accept your challenge.\p"
# 435 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "So, come back again sometime,\n"
# 436 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "won't you?$"
# 437 "data/maps/MauvilleCity_Gym/scripts.pory"

# 438 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons:
# 439 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "WATTSON: Ah-ha! Here at last!\n"
# 440 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "I know what you want.\l"
# 441 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "You want to battle my POKéMON!\p"
# 442 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Wahahahaha!\p"
# 443 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Oops! Wait!\n"
# 444 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "You've only one POKéMON with you!\p"
# 445 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Come see me with two or more\n"
# 446 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "POKéMON, all right?$"
# 447 "data/maps/MauvilleCity_Gym/scripts.pory"

# 448 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_GiveMegaRing:
# 449 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Oh, by the way, Wattson and all\n"
# 450 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "subsequent gym leaders will use Mega\p"
# 451 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Pokémon, so take this to even the\n"
# 452 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "playing field!$"
# 453 "data/maps/MauvilleCity_Gym/scripts.pory"

# 454 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_GiveMegaRingPostGym:
# 455 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Oh, by the way, as you've seen,\n"
# 456 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Wattson and all sybsequent gym\p"
# 457 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "leaders will use Mega Pokémon, so\n"
# 458 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "take this to even the playing field!$"
