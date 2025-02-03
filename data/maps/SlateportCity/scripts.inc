# 1 "data/maps/SlateportCity/scripts.pory"

# 2 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_FAT_MAN, 1
# 3 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_MAN_1, 2
# 4 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_RICH_BOY, 3
# 5 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_1, 5
# 6 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_COOK, 6
# 7 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_OLD_WOMAN, 7
# 8 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_GIRL, 8
# 9 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_TY, 9
# 10 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_GABBY, 10
# 11 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_CAPT_STERN, 11
# 12 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_2, 18
# 13 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_3, 19
# 14 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_4, 26
# 15 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_5, 27
# 16 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_6, 28
# 17 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_7, 29
# 18 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_8, 30
# 19 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_9, 31
# 20 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_GRUNT_11, 33
# 21 "data/maps/SlateportCity/scripts.pory"
.set LOCALID_SCOTT, 35
# 22 "data/maps/SlateportCity/scripts.pory"

# 23 "data/maps/SlateportCity/scripts.pory"
@ Note: LOCALID_SLATEPORT_ENERGY_GURU is a local id for this map used elsewhere. It's defined in event_objects.h
# 24 "data/maps/SlateportCity/scripts.pory"

# 25 "data/maps/SlateportCity/scripts.pory"
SlateportCity_MapScripts::
# 26 "data/maps/SlateportCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OnTransition
# 27 "data/maps/SlateportCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_OnFrame
# 28 "data/maps/SlateportCity/scripts.pory"
	.byte 0
# 29 "data/maps/SlateportCity/scripts.pory"

# 30 "data/maps/SlateportCity/scripts.pory"
SlateportCity_OnTransition:
# 31 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0
# 32 "data/maps/SlateportCity/scripts.pory"
	call SlateportCity_EventScript_EnterSlateport
# 33 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_MovePeopleForSternInterview
# 34 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_SetReadyForScottScene
# 35 "data/maps/SlateportCity/scripts.pory"
	end
# 36 "data/maps/SlateportCity/scripts.pory"

# 37 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_EnterSlateport::
# 38 "data/maps/SlateportCity/scripts.pory"
	setflag FLAG_VISITED_SLATEPORT_CITY
# 39 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_CONTEST_HALL_STATE, 0
# 40 "data/maps/SlateportCity/scripts.pory"
	setflag FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER
# 41 "data/maps/SlateportCity/scripts.pory"
	return
# 42 "data/maps/SlateportCity/scripts.pory"

# 43 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_MovePeopleForSternInterview::
# 44 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_CAPT_STERN, 28, 13
# 45 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_OLD_WOMAN, 25, 13
# 46 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_RICH_BOY, 25, 14
# 47 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_COOK, 27, 16
# 48 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_GIRL, 28, 16
# 49 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_FAT_MAN, 29, 16
# 50 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_MAN_1, 31, 14
# 51 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_CAPT_STERN, MOVEMENT_TYPE_FACE_DOWN
# 52 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_OLD_WOMAN, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
# 53 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_RICH_BOY, MOVEMENT_TYPE_FACE_UP_AND_RIGHT
# 54 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_COOK, MOVEMENT_TYPE_FACE_UP
# 55 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_GIRL, MOVEMENT_TYPE_FACE_UP
# 56 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_FAT_MAN, MOVEMENT_TYPE_FACE_UP
# 57 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_MAN_1, MOVEMENT_TYPE_FACE_LEFT
# 58 "data/maps/SlateportCity/scripts.pory"
	return
# 59 "data/maps/SlateportCity/scripts.pory"

# 60 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_SetReadyForScottScene::
# 61 "data/maps/SlateportCity/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 62 "data/maps/SlateportCity/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 63 "data/maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_0x8004, 30, SlateportCity_EventScript_MoveScottLeft
# 64 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SCOTT, 23, 27
# 65 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
# 66 "data/maps/SlateportCity/scripts.pory"
	return
# 67 "data/maps/SlateportCity/scripts.pory"

# 68 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_MoveScottLeft::
# 69 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SCOTT, 22, 27
# 70 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
# 71 "data/maps/SlateportCity/scripts.pory"
	return
# 72 "data/maps/SlateportCity/scripts.pory"

# 73 "data/maps/SlateportCity/scripts.pory"
SlateportCity_OnFrame:
# 74 "data/maps/SlateportCity/scripts.pory"
	map_script_2 VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_ScottScene
# 75 "data/maps/SlateportCity/scripts.pory"
	.2byte 0
# 76 "data/maps/SlateportCity/scripts.pory"

# 77 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ScottScene::
# 78 "data/maps/SlateportCity/scripts.pory"
	lockall
# 79 "data/maps/SlateportCity/scripts.pory"
	addobject LOCALID_SCOTT
# 80 "data/maps/SlateportCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerFaceScott
# 81 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottApproachPlayer
# 82 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 83 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_YouDroveTeamAquaAway, MSGBOX_DEFAULT
# 84 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 85 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterLeft
# 86 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 87 "data/maps/SlateportCity/scripts.pory"
	delay 60
# 88 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_MaybeThisTrainer, MSGBOX_DEFAULT
# 89 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterRight
# 90 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 91 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_LetsRegisterEachOther, MSGBOX_DEFAULT
# 92 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 93 "data/maps/SlateportCity/scripts.pory"
	delay 30
# 94 "data/maps/SlateportCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 95 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_RegisteredScott, MSGBOX_DEFAULT
# 96 "data/maps/SlateportCity/scripts.pory"
	waitfanfare
# 97 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 98 "data/maps/SlateportCity/scripts.pory"
	delay 30
# 99 "data/maps/SlateportCity/scripts.pory"
	setflag FLAG_ENABLE_SCOTT_MATCH_CALL
# 100 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou, MSGBOX_DEFAULT
# 101 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 102 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExit
# 103 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 104 "data/maps/SlateportCity/scripts.pory"
	removeobject LOCALID_SCOTT
# 105 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SCOTT, 10, 12
# 106 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_DOWN
# 107 "data/maps/SlateportCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 108 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 2
# 109 "data/maps/SlateportCity/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 110 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 111 "data/maps/SlateportCity/scripts.pory"
	end
# 112 "data/maps/SlateportCity/scripts.pory"

# 113 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_PlayerFaceScott:
# 114 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 115 "data/maps/SlateportCity/scripts.pory"
	delay_8
# 116 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_left
# 117 "data/maps/SlateportCity/scripts.pory"
	step_end
# 118 "data/maps/SlateportCity/scripts.pory"

# 119 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_ScottApproachPlayer:
# 120 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 121 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 122 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 123 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 124 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 125 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 126 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 127 "data/maps/SlateportCity/scripts.pory"
	step_end
# 128 "data/maps/SlateportCity/scripts.pory"

# 129 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_ScottExit:
# 130 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 131 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 132 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 133 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 134 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 135 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 136 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 137 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 138 "data/maps/SlateportCity/scripts.pory"
	step_end
# 139 "data/maps/SlateportCity/scripts.pory"

# 140 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_EnergyGuru::
# 141 "data/maps/SlateportCity/scripts.pory"
	lock
# 142 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 143 "data/maps/SlateportCity/scripts.pory"
	message SlateportCity_Text_EnergyGuruSellWhatYouNeed
# 144 "data/maps/SlateportCity/scripts.pory"
	waitmessage
# 145 "data/maps/SlateportCity/scripts.pory"
	pokemart SlateportCity_Pokemart_EnergyGuru
# 146 "data/maps/SlateportCity/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 147 "data/maps/SlateportCity/scripts.pory"
	release
# 148 "data/maps/SlateportCity/scripts.pory"
	end
# 149 "data/maps/SlateportCity/scripts.pory"

# 150 "data/maps/SlateportCity/scripts.pory"
	.align 2
# 151 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Pokemart_EnergyGuru:
# 152 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_PROTEIN
# 153 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_IRON
# 154 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_CARBOS
# 155 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_ZINC
# 156 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_CALCIUM
# 157 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_HP_UP
# 158 "data/maps/SlateportCity/scripts.pory"
	pokemartlistend
# 159 "data/maps/SlateportCity/scripts.pory"

# 160 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_EffortRibbonWoman::
# 161 "data/maps/SlateportCity/scripts.pory"
	lock
# 162 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 163 "data/maps/SlateportCity/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 164 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_OhYourPokemon, MSGBOX_DEFAULT
# 165 "data/maps/SlateportCity/scripts.pory"
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
# 166 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, SlateportCity_EventScript_MonHasEffortRibbon
# 167 "data/maps/SlateportCity/scripts.pory"
	specialvar VAR_RESULT, Special_AreLeadMonEVsMaxedOut
# 168 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_MonEVsNotMaxed
# 169 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_PleaseGiveItThisEffortRibbon, MSGBOX_DEFAULT
# 170 "data/maps/SlateportCity/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 171 "data/maps/SlateportCity/scripts.pory"
	message SlateportCity_Text_ReceivedEffortRibbon
# 172 "data/maps/SlateportCity/scripts.pory"
	waitfanfare
# 173 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_PutEffortRibbonOnMon, MSGBOX_DEFAULT
# 174 "data/maps/SlateportCity/scripts.pory"
	special GiveLeadMonEffortRibbon
# 175 "data/maps/SlateportCity/scripts.pory"
	release
# 176 "data/maps/SlateportCity/scripts.pory"
	end
# 177 "data/maps/SlateportCity/scripts.pory"

# 178 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_MonEVsNotMaxed::
# 179 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GoForItLittleHarder, MSGBOX_DEFAULT
# 180 "data/maps/SlateportCity/scripts.pory"
	release
# 181 "data/maps/SlateportCity/scripts.pory"
	end
# 182 "data/maps/SlateportCity/scripts.pory"

# 183 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_MonHasEffortRibbon::
# 184 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_EffortRibbonLooksGoodOnIt, MSGBOX_DEFAULT
# 185 "data/maps/SlateportCity/scripts.pory"
	release
# 186 "data/maps/SlateportCity/scripts.pory"
	end
# 187 "data/maps/SlateportCity/scripts.pory"

# 188 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Cook::
# 189 "data/maps/SlateportCity/scripts.pory"
	lock
# 190 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 191 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_CookSternInterview
# 192 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SeaweedFullOfLife, MSGBOX_DEFAULT
# 193 "data/maps/SlateportCity/scripts.pory"
	release
# 194 "data/maps/SlateportCity/scripts.pory"
	end
# 195 "data/maps/SlateportCity/scripts.pory"

# 196 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_CookSternInterview::
# 197 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_CaptainComeBackWithBigFish, MSGBOX_DEFAULT
# 198 "data/maps/SlateportCity/scripts.pory"
	release
# 199 "data/maps/SlateportCity/scripts.pory"
	end
# 200 "data/maps/SlateportCity/scripts.pory"

# 201 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_OldWoman::
# 202 "data/maps/SlateportCity/scripts.pory"
	lock
# 203 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 204 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_OldWomanSternInterview
# 205 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_HowTownIsBornAndGrows, MSGBOX_DEFAULT
# 206 "data/maps/SlateportCity/scripts.pory"
	release
# 207 "data/maps/SlateportCity/scripts.pory"
	end
# 208 "data/maps/SlateportCity/scripts.pory"

# 209 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_OldWomanSternInterview::
# 210 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_CaptSternBeingInterviewed, MSGBOX_DEFAULT
# 211 "data/maps/SlateportCity/scripts.pory"
	release
# 212 "data/maps/SlateportCity/scripts.pory"
	end
# 213 "data/maps/SlateportCity/scripts.pory"

# 214 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Girl::
# 215 "data/maps/SlateportCity/scripts.pory"
	lock
# 216 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 217 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_GirlSternInterview
# 218 "data/maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_GirlSecretBase
# 219 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SlateportWonderfulPlace, MSGBOX_DEFAULT
# 220 "data/maps/SlateportCity/scripts.pory"
	release
# 221 "data/maps/SlateportCity/scripts.pory"
	end
# 222 "data/maps/SlateportCity/scripts.pory"

# 223 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_GirlSternInterview::
# 224 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_InterviewerSoCool, MSGBOX_DEFAULT
# 225 "data/maps/SlateportCity/scripts.pory"
	release
# 226 "data/maps/SlateportCity/scripts.pory"
	end
# 227 "data/maps/SlateportCity/scripts.pory"

# 228 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_GirlSecretBase::
# 229 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BuyBricksSoDecorWontGetDirty, MSGBOX_DEFAULT
# 230 "data/maps/SlateportCity/scripts.pory"
	release
# 231 "data/maps/SlateportCity/scripts.pory"
	end
# 232 "data/maps/SlateportCity/scripts.pory"

# 233 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_RichBoy::
# 234 "data/maps/SlateportCity/scripts.pory"
	lock
# 235 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 236 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_RichBoySternInterview
# 237 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GoingToCompeteInBattleTent, MSGBOX_DEFAULT
# 238 "data/maps/SlateportCity/scripts.pory"
	release
# 239 "data/maps/SlateportCity/scripts.pory"
	end
# 240 "data/maps/SlateportCity/scripts.pory"

# 241 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_RichBoySternInterview::
# 242 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternSaysDiscoveredSomething, MSGBOX_DEFAULT
# 243 "data/maps/SlateportCity/scripts.pory"
	release
# 244 "data/maps/SlateportCity/scripts.pory"
	end
# 245 "data/maps/SlateportCity/scripts.pory"

# 246 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_FatMan::
# 247 "data/maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_FatManSternInterview
# 248 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BushedHikingFromMauville, MSGBOX_NPC
# 249 "data/maps/SlateportCity/scripts.pory"
	end
# 250 "data/maps/SlateportCity/scripts.pory"

# 251 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_FatManSternInterview::
# 252 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_AmIOnTV, MSGBOX_SIGN
# 253 "data/maps/SlateportCity/scripts.pory"
	end
# 254 "data/maps/SlateportCity/scripts.pory"

# 255 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Man1::
# 256 "data/maps/SlateportCity/scripts.pory"
	lock
# 257 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 258 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_Man1SternInterview
# 259 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_EveryoneCallsHimCaptStern, MSGBOX_DEFAULT
# 260 "data/maps/SlateportCity/scripts.pory"
	release
# 261 "data/maps/SlateportCity/scripts.pory"
	end
# 262 "data/maps/SlateportCity/scripts.pory"

# 263 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Man1SternInterview::
# 264 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_CaptainsACelebrity, MSGBOX_DEFAULT
# 265 "data/maps/SlateportCity/scripts.pory"
	release
# 266 "data/maps/SlateportCity/scripts.pory"
	end
# 267 "data/maps/SlateportCity/scripts.pory"

# 268 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Woman1::
# 269 "data/maps/SlateportCity/scripts.pory"
	lock
# 270 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 271 "data/maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_EventScript_Woman1AquaGone
# 272 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WhatsLongLineOverThere, MSGBOX_DEFAULT
# 273 "data/maps/SlateportCity/scripts.pory"
	release
# 274 "data/maps/SlateportCity/scripts.pory"
	end
# 275 "data/maps/SlateportCity/scripts.pory"

# 276 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Woman1AquaGone::
# 277 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_VisitedMuseumOften, MSGBOX_DEFAULT
# 278 "data/maps/SlateportCity/scripts.pory"
	release
# 279 "data/maps/SlateportCity/scripts.pory"
	end
# 280 "data/maps/SlateportCity/scripts.pory"

# 281 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_BattleTentSign::
# 282 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BattleTentSign, MSGBOX_SIGN
# 283 "data/maps/SlateportCity/scripts.pory"
	end
# 284 "data/maps/SlateportCity/scripts.pory"

# 285 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_SternsShipyardSign::
# 286 "data/maps/SlateportCity/scripts.pory"
	lockall
# 287 "data/maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_SternsShipyardFerryComplete
# 288 "data/maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, SlateportCity_EventScript_SternsShipyardNearsCompletion
# 289 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternsShipyardWantedSign, MSGBOX_DEFAULT
# 290 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 291 "data/maps/SlateportCity/scripts.pory"
	end
# 292 "data/maps/SlateportCity/scripts.pory"

# 293 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_SternsShipyardNearsCompletion::
# 294 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternsShipyardNearsCompletion, MSGBOX_DEFAULT
# 295 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 296 "data/maps/SlateportCity/scripts.pory"
	end
# 297 "data/maps/SlateportCity/scripts.pory"

# 298 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_SternsShipyardFerryComplete::
# 299 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternsShipyardFerryComplete, MSGBOX_DEFAULT
# 300 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 301 "data/maps/SlateportCity/scripts.pory"
	end
# 302 "data/maps/SlateportCity/scripts.pory"

# 303 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_PokemonFanClubSign::
# 304 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_PokemonFanClubSign, MSGBOX_SIGN
# 305 "data/maps/SlateportCity/scripts.pory"
	end
# 306 "data/maps/SlateportCity/scripts.pory"

# 307 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_OceanicMuseumSign::
# 308 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_OceanicMuseumSign, MSGBOX_SIGN
# 309 "data/maps/SlateportCity/scripts.pory"
	end
# 310 "data/maps/SlateportCity/scripts.pory"

# 311 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_CitySign::
# 312 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_CitySign, MSGBOX_SIGN
# 313 "data/maps/SlateportCity/scripts.pory"
	end
# 314 "data/maps/SlateportCity/scripts.pory"

# 315 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_MarketSign::
# 316 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_MarketSign, MSGBOX_SIGN
# 317 "data/maps/SlateportCity/scripts.pory"
	end
# 318 "data/maps/SlateportCity/scripts.pory"

# 319 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_HarborSign::
# 320 "data/maps/SlateportCity/scripts.pory"
	lockall
# 321 "data/maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_HarborSignFerryComplete
# 322 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_HarborFerryUnderConstruction, MSGBOX_DEFAULT
# 323 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 324 "data/maps/SlateportCity/scripts.pory"
	end
# 325 "data/maps/SlateportCity/scripts.pory"

# 326 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_HarborSignFerryComplete::
# 327 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_HarborSign, MSGBOX_DEFAULT
# 328 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 329 "data/maps/SlateportCity/scripts.pory"
	end
# 330 "data/maps/SlateportCity/scripts.pory"

# 331 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_NameRatersHouseSign::
# 332 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_NameRatersHouseSign, MSGBOX_SIGN
# 333 "data/maps/SlateportCity/scripts.pory"
	end
# 334 "data/maps/SlateportCity/scripts.pory"

# 335 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Maniac::
# 336 "data/maps/SlateportCity/scripts.pory"
	lock
# 337 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 338 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_ManiacSternInterview
# 339 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
# 340 "data/maps/SlateportCity/scripts.pory"
	release
# 341 "data/maps/SlateportCity/scripts.pory"
	end
# 342 "data/maps/SlateportCity/scripts.pory"

# 343 "data/maps/SlateportCity/scripts.pory"
@ Unclear if the text here was meant to be different, but its not
# 344 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ManiacSternInterview::
# 345 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
# 346 "data/maps/SlateportCity/scripts.pory"
	release
# 347 "data/maps/SlateportCity/scripts.pory"
	end
# 348 "data/maps/SlateportCity/scripts.pory"

# 349 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Woman2::
# 350 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_CantChangeTradeMonName, MSGBOX_NPC
# 351 "data/maps/SlateportCity/scripts.pory"
	end
# 352 "data/maps/SlateportCity/scripts.pory"

# 353 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Sailor1::
# 354 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SeaIsSoWet, MSGBOX_NPC
# 355 "data/maps/SlateportCity/scripts.pory"
	end
# 356 "data/maps/SlateportCity/scripts.pory"

# 357 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Sailor2::
# 358 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SinkOldBoats, MSGBOX_NPC
# 359 "data/maps/SlateportCity/scripts.pory"
	end
# 360 "data/maps/SlateportCity/scripts.pory"

# 361 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_PokefanF::
# 362 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BuyTooMuch, MSGBOX_NPC
# 363 "data/maps/SlateportCity/scripts.pory"
	end
# 364 "data/maps/SlateportCity/scripts.pory"

# 365 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Man2::
# 366 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BattleTentBuiltRecently, MSGBOX_NPC
# 367 "data/maps/SlateportCity/scripts.pory"
	end
# 368 "data/maps/SlateportCity/scripts.pory"

# 369 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt1::
# 370 "data/maps/SlateportCity/scripts.pory"
	lock
# 371 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 372 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_QuitPushing, MSGBOX_DEFAULT
# 373 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 374 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_1, Common_Movement_FaceOriginalDirection
# 375 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 376 "data/maps/SlateportCity/scripts.pory"
	release
# 377 "data/maps/SlateportCity/scripts.pory"
	end
# 378 "data/maps/SlateportCity/scripts.pory"

# 379 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt2::
# 380 "data/maps/SlateportCity/scripts.pory"
	lock
# 381 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 382 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_AquaHasPolicy, MSGBOX_DEFAULT
# 383 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 384 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_2, Common_Movement_FaceOriginalDirection
# 385 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 386 "data/maps/SlateportCity/scripts.pory"
	release
# 387 "data/maps/SlateportCity/scripts.pory"
	end
# 388 "data/maps/SlateportCity/scripts.pory"

# 389 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt3::
# 390 "data/maps/SlateportCity/scripts.pory"
	lock
# 391 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 392 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BossIsBrilliant, MSGBOX_DEFAULT
# 393 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 394 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_3, Common_Movement_FaceOriginalDirection
# 395 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 396 "data/maps/SlateportCity/scripts.pory"
	release
# 397 "data/maps/SlateportCity/scripts.pory"
	end
# 398 "data/maps/SlateportCity/scripts.pory"

# 399 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt4::
# 400 "data/maps/SlateportCity/scripts.pory"
	lock
# 401 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 402 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WhatsNewSchemeIWonder, MSGBOX_DEFAULT
# 403 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 404 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_4, Common_Movement_FaceOriginalDirection
# 405 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 406 "data/maps/SlateportCity/scripts.pory"
	release
# 407 "data/maps/SlateportCity/scripts.pory"
	end
# 408 "data/maps/SlateportCity/scripts.pory"

# 409 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt5::
# 410 "data/maps/SlateportCity/scripts.pory"
	lock
# 411 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 412 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ShouldTakeItAll, MSGBOX_DEFAULT
# 413 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 414 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_5, Common_Movement_FaceOriginalDirection
# 415 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 416 "data/maps/SlateportCity/scripts.pory"
	release
# 417 "data/maps/SlateportCity/scripts.pory"
	end
# 418 "data/maps/SlateportCity/scripts.pory"

# 419 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt6::
# 420 "data/maps/SlateportCity/scripts.pory"
	lock
# 421 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 422 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_DontButtIn, MSGBOX_DEFAULT
# 423 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 424 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_6, Common_Movement_FaceOriginalDirection
# 425 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 426 "data/maps/SlateportCity/scripts.pory"
	release
# 427 "data/maps/SlateportCity/scripts.pory"
	end
# 428 "data/maps/SlateportCity/scripts.pory"

# 429 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt7::
# 430 "data/maps/SlateportCity/scripts.pory"
	lock
# 431 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 432 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_RemindsMeOfLongLineForGames, MSGBOX_DEFAULT
# 433 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 434 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_7, Common_Movement_FaceOriginalDirection
# 435 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 436 "data/maps/SlateportCity/scripts.pory"
	release
# 437 "data/maps/SlateportCity/scripts.pory"
	end
# 438 "data/maps/SlateportCity/scripts.pory"

# 439 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt8::
# 440 "data/maps/SlateportCity/scripts.pory"
	lock
# 441 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 442 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WhyAreWeLiningUp, MSGBOX_DEFAULT
# 443 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 444 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_8, Common_Movement_FaceOriginalDirection
# 445 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 446 "data/maps/SlateportCity/scripts.pory"
	release
# 447 "data/maps/SlateportCity/scripts.pory"
	end
# 448 "data/maps/SlateportCity/scripts.pory"

# 449 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt9::
# 450 "data/maps/SlateportCity/scripts.pory"
	lock
# 451 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 452 "data/maps/SlateportCity/scripts.pory"
	playse SE_PIN
# 453 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, Common_Movement_ExclamationMark
# 454 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 455 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, Common_Movement_Delay48
# 456 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 457 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WhatDoYouWant, MSGBOX_DEFAULT
# 458 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 459 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
# 460 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 461 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
# 462 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 463 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, Common_Movement_FacePlayer
# 464 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 465 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_IllReadSignForYou, MSGBOX_DEFAULT
# 466 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 467 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
# 468 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 469 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
# 470 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 471 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SaysSomethingLikeSeaIsEndless, MSGBOX_DEFAULT
# 472 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 473 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, Common_Movement_FacePlayer
# 474 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 475 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
# 476 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 477 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
# 478 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 479 "data/maps/SlateportCity/scripts.pory"
	release
# 480 "data/maps/SlateportCity/scripts.pory"
	end
# 481 "data/maps/SlateportCity/scripts.pory"

# 482 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_DelayAquaGrunt:
# 483 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 484 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 485 "data/maps/SlateportCity/scripts.pory"
	step_end
# 486 "data/maps/SlateportCity/scripts.pory"

# 487 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt10::
# 488 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ShouldveBroughtMyGameBoy, MSGBOX_SIGN
# 489 "data/maps/SlateportCity/scripts.pory"
	end
# 490 "data/maps/SlateportCity/scripts.pory"

# 491 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt11::
# 492 "data/maps/SlateportCity/scripts.pory"
	lock
# 493 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 494 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_HotSpringsAfterOperation, MSGBOX_DEFAULT
# 495 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 496 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GRUNT_11, Common_Movement_FaceOriginalDirection
# 497 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 498 "data/maps/SlateportCity/scripts.pory"
	release
# 499 "data/maps/SlateportCity/scripts.pory"
	end
# 500 "data/maps/SlateportCity/scripts.pory"

# 501 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_DollClerk::
# 502 "data/maps/SlateportCity/scripts.pory"
	lock
# 503 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 504 "data/maps/SlateportCity/scripts.pory"
	message gText_HowMayIServeYou
# 505 "data/maps/SlateportCity/scripts.pory"
	waitmessage
# 506 "data/maps/SlateportCity/scripts.pory"
	pokemartdecoration SlateportCity_PokemartDecor_Dolls
# 507 "data/maps/SlateportCity/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 508 "data/maps/SlateportCity/scripts.pory"
	release
# 509 "data/maps/SlateportCity/scripts.pory"
	end
# 510 "data/maps/SlateportCity/scripts.pory"

# 511 "data/maps/SlateportCity/scripts.pory"
	.align 2
# 512 "data/maps/SlateportCity/scripts.pory"
SlateportCity_PokemartDecor_Dolls:
# 513 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_AZURILL_DOLL
# 514 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_MARILL_DOLL
# 515 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_SKITTY_DOLL
# 516 "data/maps/SlateportCity/scripts.pory"
	pokemartlistend
# 517 "data/maps/SlateportCity/scripts.pory"

# 518 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ComeBackWithSecretPower::
# 519 "data/maps/SlateportCity/scripts.pory"
	msgbox gText_ComeBackWithSecretPower, MSGBOX_DEFAULT
# 520 "data/maps/SlateportCity/scripts.pory"
	release
# 521 "data/maps/SlateportCity/scripts.pory"
	end
# 522 "data/maps/SlateportCity/scripts.pory"

# 523 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_DecorClerk::
# 524 "data/maps/SlateportCity/scripts.pory"
	lock
# 525 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 526 "data/maps/SlateportCity/scripts.pory"
	goto_if_unset FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_ComeBackWithSecretPower
# 527 "data/maps/SlateportCity/scripts.pory"
	message gText_HowMayIServeYou
# 528 "data/maps/SlateportCity/scripts.pory"
	waitmessage
# 529 "data/maps/SlateportCity/scripts.pory"
	pokemartdecoration SlateportCity_PokemartDecor
# 530 "data/maps/SlateportCity/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 531 "data/maps/SlateportCity/scripts.pory"
	release
# 532 "data/maps/SlateportCity/scripts.pory"
	end
# 533 "data/maps/SlateportCity/scripts.pory"

# 534 "data/maps/SlateportCity/scripts.pory"
	.align 2
# 535 "data/maps/SlateportCity/scripts.pory"
SlateportCity_PokemartDecor:
# 536 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_RED_BRICK
# 537 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_BLUE_BRICK
# 538 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_YELLOW_BRICK
# 539 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_RED_BALLOON
# 540 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_BLUE_BALLOON
# 541 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_YELLOW_BALLOON
# 542 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_C_LOW_NOTE_MAT
# 543 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_D_NOTE_MAT
# 544 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_E_NOTE_MAT
# 545 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_F_NOTE_MAT
# 546 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_G_NOTE_MAT
# 547 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_A_NOTE_MAT
# 548 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_B_NOTE_MAT
# 549 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_C_HIGH_NOTE_MAT
# 550 "data/maps/SlateportCity/scripts.pory"
	pokemartlistend
# 551 "data/maps/SlateportCity/scripts.pory"

# 552 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_PowerTMClerk::
# 553 "data/maps/SlateportCity/scripts.pory"
	lock
# 554 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 555 "data/maps/SlateportCity/scripts.pory"
	message gText_HowMayIServeYou
# 556 "data/maps/SlateportCity/scripts.pory"
	waitmessage
# 557 "data/maps/SlateportCity/scripts.pory"
	pokemart SlateportCity_Pokemart_PowerTMs
# 558 "data/maps/SlateportCity/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 559 "data/maps/SlateportCity/scripts.pory"
	release
# 560 "data/maps/SlateportCity/scripts.pory"
	end
# 561 "data/maps/SlateportCity/scripts.pory"

# 562 "data/maps/SlateportCity/scripts.pory"
	.align 2
# 563 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Pokemart_PowerTMs:
# 564 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_TM_HIDDEN_POWER
# 565 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_TM_POWER_GEM
# 566 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_TM_BRICK_BREAK
# 567 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_TM_FIRE_FANG
# 568 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_TM_THUNDER_FANG
# 569 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_TM_ICE_FANG
# 570 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_TM_PSYCHIC_FANGS
# 571 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_TM_ZEN_HEADBUTT
# 572 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_TM_SHADOW_CLAW
# 573 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_TM_BODY_SLAM
# 574 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_TM_LASH_OUT
# 575 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_TM_SEED_BOMB
# 576 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_TM_DAZZLING_GLEAM
# 577 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_TM_POISON_JAB
# 578 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_TM_ROCK_SLIDE
# 579 "data/maps/SlateportCity/scripts.pory"
	pokemartlistend
# 580 "data/maps/SlateportCity/scripts.pory"

# 581 "data/maps/SlateportCity/scripts.pory"
@ Scene with Capt Sterns interview and Team Aqua announcing plans to steal Submarine
# 582 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_CaptStern::
# 583 "data/maps/SlateportCity/scripts.pory"
	lockall
# 584 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternMoveAheadWithExploration, MSGBOX_DEFAULT
# 585 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GabbyWonderfulThanksForInterview, MSGBOX_DEFAULT
# 586 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 587 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GABBY, Common_Movement_WalkInPlaceFasterRight
# 588 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 589 "data/maps/SlateportCity/scripts.pory"
	delay 10
# 590 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_TY, Common_Movement_WalkInPlaceFasterDown
# 591 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 592 "data/maps/SlateportCity/scripts.pory"
	delay 25
# 593 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_CAPT_STERN, SlateportCity_Movement_SternWatchGabbyAndTyExit
# 594 "data/maps/SlateportCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerFaceStern
# 595 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_GABBY, SlateportCity_Movement_GabbyExit
# 596 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_TY, SlateportCity_Movement_TyExit
# 597 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 598 "data/maps/SlateportCity/scripts.pory"
	removeobject LOCALID_GABBY
# 599 "data/maps/SlateportCity/scripts.pory"
	removeobject LOCALID_TY
# 600 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternWhewFirstInterview, MSGBOX_DEFAULT
# 601 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
# 602 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 603 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_OhPlayerWeMadeDiscovery, MSGBOX_DEFAULT
# 604 "data/maps/SlateportCity/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 605 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_AquaWillAssumeControlOfSubmarine, MSGBOX_DEFAULT
# 606 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_COOK, Common_Movement_WalkInPlaceFasterLeft
# 607 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_FAT_MAN, Common_Movement_WalkInPlaceFasterLeft
# 608 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_OLD_WOMAN, SlateportCity_Movement_OldWomanConcern
# 609 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_RICH_BOY, Common_Movement_QuestionMark
# 610 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_MAN_1, SlateportCity_Movement_ManConcern
# 611 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 612 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterDown
# 613 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 614 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternWhatWasAllThat, MSGBOX_DEFAULT
# 615 "data/maps/SlateportCity/scripts.pory"
	playse SE_PIN
# 616 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_CAPT_STERN, Common_Movement_ExclamationMark
# 617 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 618 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_CAPT_STERN, Common_Movement_Delay48
# 619 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 620 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
# 621 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 622 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_FromHarborTryingToTakeSub, MSGBOX_DEFAULT
# 623 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
# 624 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 625 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_CAPT_STERN, SlateportCity_Movement_SternEnterHarbor
# 626 "data/maps/SlateportCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerEnterHarbor
# 627 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 628 "data/maps/SlateportCity/scripts.pory"
	removeobject LOCALID_CAPT_STERN
# 629 "data/maps/SlateportCity/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
# 630 "data/maps/SlateportCity/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW
# 631 "data/maps/SlateportCity/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT
# 632 "data/maps/SlateportCity/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE
# 633 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_SLATEPORT_CITY_STATE, 2
# 634 "data/maps/SlateportCity/scripts.pory"
	warp MAP_SLATEPORT_CITY_HARBOR, 11, 14
# 635 "data/maps/SlateportCity/scripts.pory"
	waitstate
# 636 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 637 "data/maps/SlateportCity/scripts.pory"
	end
# 638 "data/maps/SlateportCity/scripts.pory"

# 639 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_OldWomanConcern:
# 640 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 641 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 642 "data/maps/SlateportCity/scripts.pory"
	emote_question_mark
# 643 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_right
# 644 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 645 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 646 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_left
# 647 "data/maps/SlateportCity/scripts.pory"
	step_end
# 648 "data/maps/SlateportCity/scripts.pory"

# 649 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_ManConcern:
# 650 "data/maps/SlateportCity/scripts.pory"
	emote_question_mark
# 651 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_up
# 652 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 653 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_down
# 654 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 655 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 656 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_left
# 657 "data/maps/SlateportCity/scripts.pory"
	step_end
# 658 "data/maps/SlateportCity/scripts.pory"

# 659 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_GabbyExit:
# 660 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 661 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 662 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 663 "data/maps/SlateportCity/scripts.pory"
	walk_down
# 664 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 665 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 666 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 667 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 668 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 669 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 670 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 671 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 672 "data/maps/SlateportCity/scripts.pory"
	step_end
# 673 "data/maps/SlateportCity/scripts.pory"

# 674 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_TyExit:
# 675 "data/maps/SlateportCity/scripts.pory"
	walk_down
# 676 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 677 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 678 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 679 "data/maps/SlateportCity/scripts.pory"
	walk_down
# 680 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 681 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 682 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 683 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 684 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 685 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 686 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 687 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 688 "data/maps/SlateportCity/scripts.pory"
	step_end
# 689 "data/maps/SlateportCity/scripts.pory"

# 690 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_Unused:
# 691 "data/maps/SlateportCity/scripts.pory"
	walk_down
# 692 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_up
# 693 "data/maps/SlateportCity/scripts.pory"
	step_end
# 694 "data/maps/SlateportCity/scripts.pory"

# 695 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_SternEnterHarbor:
# 696 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 697 "data/maps/SlateportCity/scripts.pory"
	walk_up
# 698 "data/maps/SlateportCity/scripts.pory"
	walk_up
# 699 "data/maps/SlateportCity/scripts.pory"
	set_invisible
# 700 "data/maps/SlateportCity/scripts.pory"
	step_end
# 701 "data/maps/SlateportCity/scripts.pory"

# 702 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_SternWatchGabbyAndTyExit:
# 703 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 704 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 705 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 706 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 707 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 708 "data/maps/SlateportCity/scripts.pory"
	walk_down
# 709 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 710 "data/maps/SlateportCity/scripts.pory"
	step_end
# 711 "data/maps/SlateportCity/scripts.pory"

# 712 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_PlayerEnterHarbor:
# 713 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_right
# 714 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 715 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 716 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 717 "data/maps/SlateportCity/scripts.pory"
	walk_up
# 718 "data/maps/SlateportCity/scripts.pory"
	step_end
# 719 "data/maps/SlateportCity/scripts.pory"

# 720 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_PlayerFaceStern:
# 721 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 722 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 723 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 724 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 725 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 726 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 727 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 728 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_down
# 729 "data/maps/SlateportCity/scripts.pory"
	step_end
# 730 "data/maps/SlateportCity/scripts.pory"

# 731 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Ty::
# 732 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BigSmileForCamera, MSGBOX_SIGN
# 733 "data/maps/SlateportCity/scripts.pory"
	end
# 734 "data/maps/SlateportCity/scripts.pory"

# 735 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Gabby::
# 736 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_MostInvaluableExperience, MSGBOX_SIGN
# 737 "data/maps/SlateportCity/scripts.pory"
	end
# 738 "data/maps/SlateportCity/scripts.pory"

# 739 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Man3::
# 740 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WonderIfLighthouseStartlesPokemon, MSGBOX_NPC
# 741 "data/maps/SlateportCity/scripts.pory"
	end
# 742 "data/maps/SlateportCity/scripts.pory"

# 743 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_BerryPowderClerk::
# 744 "data/maps/SlateportCity/scripts.pory"
	lock
# 745 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 746 "data/maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_POWDER_JAR, SlateportCity_EventScript_ReceivedPowderJar
# 747 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ExplainBerries, MSGBOX_DEFAULT
# 748 "data/maps/SlateportCity/scripts.pory"
	giveitem ITEM_POWDER_JAR
# 749 "data/maps/SlateportCity/scripts.pory"
	setflag FLAG_RECEIVED_POWDER_JAR
# 750 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
# 751 "data/maps/SlateportCity/scripts.pory"
	release
# 752 "data/maps/SlateportCity/scripts.pory"
	end
# 753 "data/maps/SlateportCity/scripts.pory"

# 754 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ReceivedPowderJar::
# 755 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8004, 1
# 756 "data/maps/SlateportCity/scripts.pory"
	specialvar VAR_RESULT, HasEnoughBerryPowder
# 757 "data/maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_ExplainBerryPowder
# 758 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BroughtMeSomeBerryPowder, MSGBOX_DEFAULT
# 759 "data/maps/SlateportCity/scripts.pory"
	special DisplayBerryPowderVendorMenu
# 760 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_ChooseBerryPowderItem
# 761 "data/maps/SlateportCity/scripts.pory"
	end
# 762 "data/maps/SlateportCity/scripts.pory"

# 763 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ExplainBerryPowder::
# 764 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
# 765 "data/maps/SlateportCity/scripts.pory"
	release
# 766 "data/maps/SlateportCity/scripts.pory"
	end
# 767 "data/maps/SlateportCity/scripts.pory"

# 768 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ChooseBerryPowderItem::
# 769 "data/maps/SlateportCity/scripts.pory"
	message SlateportCity_Text_ExchangeWhatWithIt
# 770 "data/maps/SlateportCity/scripts.pory"
	waitmessage
# 771 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
# 772 "data/maps/SlateportCity/scripts.pory"
	special ShowScrollableMultichoice
# 773 "data/maps/SlateportCity/scripts.pory"
	waitstate
# 774 "data/maps/SlateportCity/scripts.pory"
	switch VAR_RESULT
# 775 "data/maps/SlateportCity/scripts.pory"
	case 0, SlateportCity_EventScript_EnergyPowder
# 776 "data/maps/SlateportCity/scripts.pory"
	case 1, SlateportCity_EventScript_EnergyRoot
# 777 "data/maps/SlateportCity/scripts.pory"
	case 2, SlateportCity_EventScript_HealPowder
# 778 "data/maps/SlateportCity/scripts.pory"
	case 3, SlateportCity_EventScript_RevivalHerb
# 779 "data/maps/SlateportCity/scripts.pory"
	case 4, SlateportCity_EventScript_Protein
# 780 "data/maps/SlateportCity/scripts.pory"
	case 5, SlateportCity_EventScript_Iron
# 781 "data/maps/SlateportCity/scripts.pory"
	case 6, SlateportCity_EventScript_Carbos
# 782 "data/maps/SlateportCity/scripts.pory"
	case 7, SlateportCity_EventScript_Calcium
# 783 "data/maps/SlateportCity/scripts.pory"
	case 8, SlateportCity_EventScript_Zinc
# 784 "data/maps/SlateportCity/scripts.pory"
	case 9, SlateportCity_EventScript_HPUp
# 785 "data/maps/SlateportCity/scripts.pory"
	case 10, SlateportCity_EventScript_PPUp
# 786 "data/maps/SlateportCity/scripts.pory"
	case 11, SlateportCity_EventScript_CancelPowderItemSelect
# 787 "data/maps/SlateportCity/scripts.pory"
	case MULTI_B_PRESSED, SlateportCity_EventScript_CancelPowderItemSelect
# 788 "data/maps/SlateportCity/scripts.pory"
	end
# 789 "data/maps/SlateportCity/scripts.pory"

# 790 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_EnergyPowder::
# 791 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_ENERGY_POWDER
# 792 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
# 793 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 50
# 794 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 795 "data/maps/SlateportCity/scripts.pory"
	end
# 796 "data/maps/SlateportCity/scripts.pory"

# 797 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_EnergyRoot::
# 798 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_ENERGY_ROOT
# 799 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
# 800 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 80
# 801 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 802 "data/maps/SlateportCity/scripts.pory"
	end
# 803 "data/maps/SlateportCity/scripts.pory"

# 804 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_HealPowder::
# 805 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_HEAL_POWDER
# 806 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_HEAL_POWDER
# 807 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 50
# 808 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 809 "data/maps/SlateportCity/scripts.pory"
	end
# 810 "data/maps/SlateportCity/scripts.pory"

# 811 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_RevivalHerb::
# 812 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_REVIVAL_HERB
# 813 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
# 814 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 300
# 815 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 816 "data/maps/SlateportCity/scripts.pory"
	end
# 817 "data/maps/SlateportCity/scripts.pory"

# 818 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Protein::
# 819 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_PROTEIN
# 820 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_PROTEIN
# 821 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 822 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 823 "data/maps/SlateportCity/scripts.pory"
	end
# 824 "data/maps/SlateportCity/scripts.pory"

# 825 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Iron::
# 826 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_IRON
# 827 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_IRON
# 828 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 829 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 830 "data/maps/SlateportCity/scripts.pory"
	end
# 831 "data/maps/SlateportCity/scripts.pory"

# 832 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Carbos::
# 833 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_CARBOS
# 834 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_CARBOS
# 835 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 836 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 837 "data/maps/SlateportCity/scripts.pory"
	end
# 838 "data/maps/SlateportCity/scripts.pory"

# 839 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Calcium::
# 840 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_CALCIUM
# 841 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_CALCIUM
# 842 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 843 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 844 "data/maps/SlateportCity/scripts.pory"
	end
# 845 "data/maps/SlateportCity/scripts.pory"

# 846 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Zinc::
# 847 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_ZINC
# 848 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_ZINC
# 849 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 850 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 851 "data/maps/SlateportCity/scripts.pory"
	end
# 852 "data/maps/SlateportCity/scripts.pory"

# 853 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_HPUp::
# 854 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_HP_UP
# 855 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_HP_UP
# 856 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 857 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 858 "data/maps/SlateportCity/scripts.pory"
	end
# 859 "data/maps/SlateportCity/scripts.pory"

# 860 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_PPUp::
# 861 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_PP_UP
# 862 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_PP_UP
# 863 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 3000
# 864 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 865 "data/maps/SlateportCity/scripts.pory"
	end
# 866 "data/maps/SlateportCity/scripts.pory"

# 867 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_CancelPowderItemSelect::
# 868 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ComeBackToTradeBerryPowder, MSGBOX_DEFAULT
# 869 "data/maps/SlateportCity/scripts.pory"
	special RemoveBerryPowderVendorMenu
# 870 "data/maps/SlateportCity/scripts.pory"
	release
# 871 "data/maps/SlateportCity/scripts.pory"
	end
# 872 "data/maps/SlateportCity/scripts.pory"

# 873 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_TryBuyBerryPowderItem::
# 874 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ExchangeBerryPowderForItem, MSGBOX_YESNO
# 875 "data/maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SlateportCity_EventScript_ChooseBerryPowderItem
# 876 "data/maps/SlateportCity/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8009
# 877 "data/maps/SlateportCity/scripts.pory"
	specialvar VAR_RESULT, HasEnoughBerryPowder
# 878 "data/maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NotEnoughBerryPowder
# 879 "data/maps/SlateportCity/scripts.pory"
	giveitem VAR_0x8008
# 880 "data/maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NoRoomForBerryPowderItem
# 881 "data/maps/SlateportCity/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8009
# 882 "data/maps/SlateportCity/scripts.pory"
	special TakeBerryPowder
# 883 "data/maps/SlateportCity/scripts.pory"
	special PrintPlayerBerryPowderAmount
# 884 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_FineBerryPowderTradeSomethingElse, MSGBOX_YESNO
# 885 "data/maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SlateportCity_EventScript_ChooseBerryPowderItem
# 886 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WhenYouGetMoreBringItToMe, MSGBOX_DEFAULT
# 887 "data/maps/SlateportCity/scripts.pory"
	special RemoveBerryPowderVendorMenu
# 888 "data/maps/SlateportCity/scripts.pory"
	release
# 889 "data/maps/SlateportCity/scripts.pory"
	end
# 890 "data/maps/SlateportCity/scripts.pory"

# 891 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_NoRoomForBerryPowderItem::
# 892 "data/maps/SlateportCity/scripts.pory"
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
# 893 "data/maps/SlateportCity/scripts.pory"
	special RemoveBerryPowderVendorMenu
# 894 "data/maps/SlateportCity/scripts.pory"
	release
# 895 "data/maps/SlateportCity/scripts.pory"
	end
# 896 "data/maps/SlateportCity/scripts.pory"

# 897 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_NotEnoughBerryPowder::
# 898 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_DontHaveEnoughBerryPowder, MSGBOX_DEFAULT
# 899 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_ChooseBerryPowderItem
# 900 "data/maps/SlateportCity/scripts.pory"
	end
# 901 "data/maps/SlateportCity/scripts.pory"

# 902 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ScottBattleTentScene::
# 903 "data/maps/SlateportCity/scripts.pory"
	lockall
# 904 "data/maps/SlateportCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 905 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 906 "data/maps/SlateportCity/scripts.pory"
	opendoor 10, 12
# 907 "data/maps/SlateportCity/scripts.pory"
	waitdooranim
# 908 "data/maps/SlateportCity/scripts.pory"
	addobject LOCALID_SCOTT
# 909 "data/maps/SlateportCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PushPlayerDown
# 910 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExitBattleTent
# 911 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 912 "data/maps/SlateportCity/scripts.pory"
	closedoor 10, 12
# 913 "data/maps/SlateportCity/scripts.pory"
	waitdooranim
# 914 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_TakingBattleTentChallenge, MSGBOX_DEFAULT
# 915 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 916 "data/maps/SlateportCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerWatchScottExit
# 917 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExitAfterBattleTent
# 918 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 919 "data/maps/SlateportCity/scripts.pory"
	removeobject LOCALID_SCOTT
# 920 "data/maps/SlateportCity/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 921 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
# 922 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 923 "data/maps/SlateportCity/scripts.pory"
	end
# 924 "data/maps/SlateportCity/scripts.pory"

# 925 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_PushPlayerDown:
# 926 "data/maps/SlateportCity/scripts.pory"
	lock_facing_direction
# 927 "data/maps/SlateportCity/scripts.pory"
	walk_down
# 928 "data/maps/SlateportCity/scripts.pory"
	unlock_facing_direction
# 929 "data/maps/SlateportCity/scripts.pory"
	step_end
# 930 "data/maps/SlateportCity/scripts.pory"

# 931 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_PlayerWatchScottExit:
# 932 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 933 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_right
# 934 "data/maps/SlateportCity/scripts.pory"
	step_end
# 935 "data/maps/SlateportCity/scripts.pory"

# 936 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_ScottExitBattleTent:
# 937 "data/maps/SlateportCity/scripts.pory"
	delay_8
# 938 "data/maps/SlateportCity/scripts.pory"
	walk_down
# 939 "data/maps/SlateportCity/scripts.pory"
	step_end
# 940 "data/maps/SlateportCity/scripts.pory"

# 941 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_ScottExitAfterBattleTent:
# 942 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 943 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 944 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 945 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 946 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 947 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 948 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 949 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 950 "data/maps/SlateportCity/scripts.pory"
	step_end
# 951 "data/maps/SlateportCity/scripts.pory"

# 952 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_BerryCrushRankingsSign::
# 953 "data/maps/SlateportCity/scripts.pory"
	lockall
# 954 "data/maps/SlateportCity/scripts.pory"
	special ShowBerryCrushRankings
# 955 "data/maps/SlateportCity/scripts.pory"
	waitstate
# 956 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 957 "data/maps/SlateportCity/scripts.pory"
	end
# 958 "data/maps/SlateportCity/scripts.pory"

# 959 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_EnergyGuruSellWhatYouNeed:
# 960 "data/maps/SlateportCity/scripts.pory"
	.string "I'm the ENERGY GURU! I'll go for it and\n"
# 961 "data/maps/SlateportCity/scripts.pory"
	.string "sell you what you need!$"
# 962 "data/maps/SlateportCity/scripts.pory"

# 963 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_OhYourPokemon:
# 964 "data/maps/SlateportCity/scripts.pory"
	.string "Oh?\n"
# 965 "data/maps/SlateportCity/scripts.pory"
	.string "Your {STR_VAR_1}…$"
# 966 "data/maps/SlateportCity/scripts.pory"

# 967 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_PleaseGiveItThisEffortRibbon:
# 968 "data/maps/SlateportCity/scripts.pory"
	.string "Went for it stupendously!\p"
# 969 "data/maps/SlateportCity/scripts.pory"
	.string "As its reward, please give it this\n"
# 970 "data/maps/SlateportCity/scripts.pory"
	.string "EFFORT RIBBON.$"
# 971 "data/maps/SlateportCity/scripts.pory"

# 972 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ReceivedEffortRibbon:
# 973 "data/maps/SlateportCity/scripts.pory"
	.string "{PLAYER} received the EFFORT RIBBON.$"
# 974 "data/maps/SlateportCity/scripts.pory"

# 975 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_PutEffortRibbonOnMon:
# 976 "data/maps/SlateportCity/scripts.pory"
	.string "{PLAYER} put the EFFORT RIBBON\n"
# 977 "data/maps/SlateportCity/scripts.pory"
	.string "on {STR_VAR_1}.$"
# 978 "data/maps/SlateportCity/scripts.pory"

# 979 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_GoForItLittleHarder:
# 980 "data/maps/SlateportCity/scripts.pory"
	.string "You have to go for it a little harder.\p"
# 981 "data/maps/SlateportCity/scripts.pory"
	.string "If you do, I'll give your POKéMON\n"
# 982 "data/maps/SlateportCity/scripts.pory"
	.string "something nice.$"
# 983 "data/maps/SlateportCity/scripts.pory"

# 984 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_EffortRibbonLooksGoodOnIt:
# 985 "data/maps/SlateportCity/scripts.pory"
	.string "Oh! Your {STR_VAR_1}, that EFFORT\n"
# 986 "data/maps/SlateportCity/scripts.pory"
	.string "RIBBON looks good on it!$"
# 987 "data/maps/SlateportCity/scripts.pory"

# 988 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_WonderIfLighthouseStartlesPokemon:
# 989 "data/maps/SlateportCity/scripts.pory"
	.string "The light of the lighthouse reaches\n"
# 990 "data/maps/SlateportCity/scripts.pory"
	.string "dozens of miles away.\p"
# 991 "data/maps/SlateportCity/scripts.pory"
	.string "I wonder if it doesn't startle POKéMON\n"
# 992 "data/maps/SlateportCity/scripts.pory"
	.string "in the sea.$"
# 993 "data/maps/SlateportCity/scripts.pory"

# 994 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SeaweedFullOfLife:
# 995 "data/maps/SlateportCity/scripts.pory"
	.string "Ooh, look at this!\p"
# 996 "data/maps/SlateportCity/scripts.pory"
	.string "The seaweed you can get around these\n"
# 997 "data/maps/SlateportCity/scripts.pory"
	.string "parts is fresh and full of life.\p"
# 998 "data/maps/SlateportCity/scripts.pory"
	.string "Why, it looks like it can even rear up\n"
# 999 "data/maps/SlateportCity/scripts.pory"
	.string "and attack!$"
# 1000 "data/maps/SlateportCity/scripts.pory"

# 1001 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_HowTownIsBornAndGrows:
# 1002 "data/maps/SlateportCity/scripts.pory"
	.string "Where the water is clean, the fruits\n"
# 1003 "data/maps/SlateportCity/scripts.pory"
	.string "of bountiful harvest gather.\p"
# 1004 "data/maps/SlateportCity/scripts.pory"
	.string "And where people gather, a market\n"
# 1005 "data/maps/SlateportCity/scripts.pory"
	.string "soon starts.\p"
# 1006 "data/maps/SlateportCity/scripts.pory"
	.string "That is how a town is born and grows.$"
# 1007 "data/maps/SlateportCity/scripts.pory"

# 1008 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SlateportWonderfulPlace:
# 1009 "data/maps/SlateportCity/scripts.pory"
	.string "Shopping where you can breathe the\n"
# 1010 "data/maps/SlateportCity/scripts.pory"
	.string "scent of the ocean…\p"
# 1011 "data/maps/SlateportCity/scripts.pory"
	.string "SLATEPORT is such a wonderful place!$"
# 1012 "data/maps/SlateportCity/scripts.pory"

# 1013 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BuyBricksSoDecorWontGetDirty:
# 1014 "data/maps/SlateportCity/scripts.pory"
	.string "If you put DOLLS or CUSHIONS on\n"
# 1015 "data/maps/SlateportCity/scripts.pory"
	.string "the floor, they'll get dirty.\p"
# 1016 "data/maps/SlateportCity/scripts.pory"
	.string "I'm going to buy some BRICKS so my\n"
# 1017 "data/maps/SlateportCity/scripts.pory"
	.string "DOLLS and CUSHIONS won't get dirty\l"
# 1018 "data/maps/SlateportCity/scripts.pory"
	.string "when I leave them out.$"
# 1019 "data/maps/SlateportCity/scripts.pory"

# 1020 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_GoingToCompeteInBattleTent:
# 1021 "data/maps/SlateportCity/scripts.pory"
	.string "Wroooar! I'm going to compete in\n"
# 1022 "data/maps/SlateportCity/scripts.pory"
	.string "the BATTLE TENT, too!\p"
# 1023 "data/maps/SlateportCity/scripts.pory"
	.string "But before that, I need to catch\n"
# 1024 "data/maps/SlateportCity/scripts.pory"
	.string "some POKéMON!$"
# 1025 "data/maps/SlateportCity/scripts.pory"

# 1026 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BushedHikingFromMauville:
# 1027 "data/maps/SlateportCity/scripts.pory"
	.string "Whew… I'm just bushed…\p"
# 1028 "data/maps/SlateportCity/scripts.pory"
	.string "I hiked over from MAUVILLE CITY.\n"
# 1029 "data/maps/SlateportCity/scripts.pory"
	.string "But, boy, this city's huge.\p"
# 1030 "data/maps/SlateportCity/scripts.pory"
	.string "If I'd known this, I would've ridden\n"
# 1031 "data/maps/SlateportCity/scripts.pory"
	.string "my BIKE here.$"
# 1032 "data/maps/SlateportCity/scripts.pory"

# 1033 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_EveryoneCallsHimCaptStern:
# 1034 "data/maps/SlateportCity/scripts.pory"
	.string "STERN, the fellow who built the\n"
# 1035 "data/maps/SlateportCity/scripts.pory"
	.string "MUSEUM, also happens to be the leader\l"
# 1036 "data/maps/SlateportCity/scripts.pory"
	.string "of an undersea exploration team.\p"
# 1037 "data/maps/SlateportCity/scripts.pory"
	.string "So, everyone calls him CAPT. STERN.$"
# 1038 "data/maps/SlateportCity/scripts.pory"

# 1039 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_WhatsLongLineOverThere:
# 1040 "data/maps/SlateportCity/scripts.pory"
	.string "What is that over there?\n"
# 1041 "data/maps/SlateportCity/scripts.pory"
	.string "That long line…$"
# 1042 "data/maps/SlateportCity/scripts.pory"

# 1043 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_VisitedMuseumOften:
# 1044 "data/maps/SlateportCity/scripts.pory"
	.string "When I was a child, I visited\n"
# 1045 "data/maps/SlateportCity/scripts.pory"
	.string "the MUSEUM often.\p"
# 1046 "data/maps/SlateportCity/scripts.pory"
	.string "I used to dream about the mysteries of\n"
# 1047 "data/maps/SlateportCity/scripts.pory"
	.string "the sea after seeing the exhibits.$"
# 1048 "data/maps/SlateportCity/scripts.pory"

# 1049 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_QuitPushing:
# 1050 "data/maps/SlateportCity/scripts.pory"
	.string "Hey, there! Quit pushing!\n"
# 1051 "data/maps/SlateportCity/scripts.pory"
	.string "This is the line, can't you see?$"
# 1052 "data/maps/SlateportCity/scripts.pory"

# 1053 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_AquaHasPolicy:
# 1054 "data/maps/SlateportCity/scripts.pory"
	.string "TEAM AQUA has a policy of\n"
# 1055 "data/maps/SlateportCity/scripts.pory"
	.string "assembling and dispersing at\l"
# 1056 "data/maps/SlateportCity/scripts.pory"
	.string "the operation site.$"
# 1057 "data/maps/SlateportCity/scripts.pory"

# 1058 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BossIsBrilliant:
# 1059 "data/maps/SlateportCity/scripts.pory"
	.string "Our BOSS is brilliant.\p"
# 1060 "data/maps/SlateportCity/scripts.pory"
	.string "What would he want to do with\n"
# 1061 "data/maps/SlateportCity/scripts.pory"
	.string "a MUSEUM now?$"
# 1062 "data/maps/SlateportCity/scripts.pory"

# 1063 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_WhatsNewSchemeIWonder:
# 1064 "data/maps/SlateportCity/scripts.pory"
	.string "What's the new scheme, I wonder?\p"
# 1065 "data/maps/SlateportCity/scripts.pory"
	.string "Our BOSS is scary when he's mad, so\n"
# 1066 "data/maps/SlateportCity/scripts.pory"
	.string "I'd better not screw things up…$"
# 1067 "data/maps/SlateportCity/scripts.pory"

# 1068 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ShouldTakeItAll:
# 1069 "data/maps/SlateportCity/scripts.pory"
	.string "If there's something we need in\n"
# 1070 "data/maps/SlateportCity/scripts.pory"
	.string "the MUSEUM, we should take it all!$"
# 1071 "data/maps/SlateportCity/scripts.pory"

# 1072 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_DontButtIn:
# 1073 "data/maps/SlateportCity/scripts.pory"
	.string "Hey, you there!\n"
# 1074 "data/maps/SlateportCity/scripts.pory"
	.string "Don't butt in!$"
# 1075 "data/maps/SlateportCity/scripts.pory"

# 1076 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_RemindsMeOfLongLineForGames:
# 1077 "data/maps/SlateportCity/scripts.pory"
	.string "A long line, huh?\p"
# 1078 "data/maps/SlateportCity/scripts.pory"
	.string "It reminds me of the times I lined up to\n"
# 1079 "data/maps/SlateportCity/scripts.pory"
	.string "buy smash-hit games…$"
# 1080 "data/maps/SlateportCity/scripts.pory"

# 1081 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_WhyAreWeLiningUp:
# 1082 "data/maps/SlateportCity/scripts.pory"
	.string "Why are we even lining up and paying?\n"
# 1083 "data/maps/SlateportCity/scripts.pory"
	.string "We should just march in!$"
# 1084 "data/maps/SlateportCity/scripts.pory"

# 1085 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_WhatDoYouWant:
# 1086 "data/maps/SlateportCity/scripts.pory"
	.string "What?\n"
# 1087 "data/maps/SlateportCity/scripts.pory"
	.string "What do you want?$"
# 1088 "data/maps/SlateportCity/scripts.pory"

# 1089 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_IllReadSignForYou:
# 1090 "data/maps/SlateportCity/scripts.pory"
	.string "You want to read this sign?\n"
# 1091 "data/maps/SlateportCity/scripts.pory"
	.string "I'll read it for you!$"
# 1092 "data/maps/SlateportCity/scripts.pory"

# 1093 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SaysSomethingLikeSeaIsEndless:
# 1094 "data/maps/SlateportCity/scripts.pory"
	.string "Let's see…\p"
# 1095 "data/maps/SlateportCity/scripts.pory"
	.string "Um… I think it says something like\n"
# 1096 "data/maps/SlateportCity/scripts.pory"
	.string "“the life in the sea is endless.”\p"
# 1097 "data/maps/SlateportCity/scripts.pory"
	.string "Yup, I'm pretty sure that's what\n"
# 1098 "data/maps/SlateportCity/scripts.pory"
	.string "it says.$"
# 1099 "data/maps/SlateportCity/scripts.pory"

# 1100 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ShouldveBroughtMyGameBoy:
# 1101 "data/maps/SlateportCity/scripts.pory"
	.string "Grumble…\p"
# 1102 "data/maps/SlateportCity/scripts.pory"
	.string "I should've brought my Game Boy\n"
# 1103 "data/maps/SlateportCity/scripts.pory"
	.string "Advance so I wouldn't get bored in line…\p"
# 1104 "data/maps/SlateportCity/scripts.pory"
	.string "Grumble…$"
# 1105 "data/maps/SlateportCity/scripts.pory"

# 1106 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_HotSpringsAfterOperation:
# 1107 "data/maps/SlateportCity/scripts.pory"
	.string "When this operation's over, I'll take\n"
# 1108 "data/maps/SlateportCity/scripts.pory"
	.string "you to a hot spring spa!\p"
# 1109 "data/maps/SlateportCity/scripts.pory"
	.string "That's what our leader said.\n"
# 1110 "data/maps/SlateportCity/scripts.pory"
	.string "I can't wait!$"
# 1111 "data/maps/SlateportCity/scripts.pory"

# 1112 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SeaIsSoWet:
# 1113 "data/maps/SlateportCity/scripts.pory"
	.string "The sea is just so vast…\p"
# 1114 "data/maps/SlateportCity/scripts.pory"
	.string "Could the sea have been made by\n"
# 1115 "data/maps/SlateportCity/scripts.pory"
	.string "the tears shed by POKéMON?$"
# 1116 "data/maps/SlateportCity/scripts.pory"

# 1117 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SinkOldBoats:
# 1118 "data/maps/SlateportCity/scripts.pory"
	.string "Do you know what they do with old\n"
# 1119 "data/maps/SlateportCity/scripts.pory"
	.string "ships that become too creaky to sail?\p"
# 1120 "data/maps/SlateportCity/scripts.pory"
	.string "They sink them in the sea so they\n"
# 1121 "data/maps/SlateportCity/scripts.pory"
	.string "become habitats for POKéMON.$"
# 1122 "data/maps/SlateportCity/scripts.pory"

# 1123 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BuyTooMuch:
# 1124 "data/maps/SlateportCity/scripts.pory"
	.string "Whenever I visit here, I get carried\n"
# 1125 "data/maps/SlateportCity/scripts.pory"
	.string "away and buy too much.$"
# 1126 "data/maps/SlateportCity/scripts.pory"

# 1127 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_GetNameRaterToHelpYou:
# 1128 "data/maps/SlateportCity/scripts.pory"
	.string "If you want to change your POKéMON's\n"
# 1129 "data/maps/SlateportCity/scripts.pory"
	.string "nickname, you'll have to get the NAME\l"
# 1130 "data/maps/SlateportCity/scripts.pory"
	.string "RATER to help you.$"
# 1131 "data/maps/SlateportCity/scripts.pory"

# 1132 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_CantChangeTradeMonName:
# 1133 "data/maps/SlateportCity/scripts.pory"
	.string "Any POKéMON you get in a trade,\n"
# 1134 "data/maps/SlateportCity/scripts.pory"
	.string "you can't change its nickname.\p"
# 1135 "data/maps/SlateportCity/scripts.pory"
	.string "The original TRAINER's love for that\n"
# 1136 "data/maps/SlateportCity/scripts.pory"
	.string "POKéMON is in the nickname.$"
# 1137 "data/maps/SlateportCity/scripts.pory"

# 1138 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BattleTentBuiltRecently:
# 1139 "data/maps/SlateportCity/scripts.pory"
	.string "Recently, a BATTLE TENT was built\n"
# 1140 "data/maps/SlateportCity/scripts.pory"
	.string "in SLATEPORT.\p"
# 1141 "data/maps/SlateportCity/scripts.pory"
	.string "GYMS are fun, but the BATTLE TENT's\n"
# 1142 "data/maps/SlateportCity/scripts.pory"
	.string "awesome in its own way.\p"
# 1143 "data/maps/SlateportCity/scripts.pory"
	.string "You should go find tough POKéMON\n"
# 1144 "data/maps/SlateportCity/scripts.pory"
	.string "for the BATTLE TENT!$"
# 1145 "data/maps/SlateportCity/scripts.pory"

# 1146 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_CaptSternBeingInterviewed:
# 1147 "data/maps/SlateportCity/scripts.pory"
	.string "I was hoping that it was a famous star\n"
# 1148 "data/maps/SlateportCity/scripts.pory"
	.string "so I could get an autograph.\p"
# 1149 "data/maps/SlateportCity/scripts.pory"
	.string "But who's that being interviewed?\n"
# 1150 "data/maps/SlateportCity/scripts.pory"
	.string "Isn't that CAPT. STERN?$"
# 1151 "data/maps/SlateportCity/scripts.pory"

# 1152 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_InterviewerSoCool:
# 1153 "data/maps/SlateportCity/scripts.pory"
	.string "That lady interviewer is so cool\n"
# 1154 "data/maps/SlateportCity/scripts.pory"
	.string "and pretty.\p"
# 1155 "data/maps/SlateportCity/scripts.pory"
	.string "When I grow up, I'm going to be\n"
# 1156 "data/maps/SlateportCity/scripts.pory"
	.string "an international journalist!$"
# 1157 "data/maps/SlateportCity/scripts.pory"

# 1158 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternSaysDiscoveredSomething:
# 1159 "data/maps/SlateportCity/scripts.pory"
	.string "CAPT. STERN says they discovered\n"
# 1160 "data/maps/SlateportCity/scripts.pory"
	.string "something at the bottom of the sea.\p"
# 1161 "data/maps/SlateportCity/scripts.pory"
	.string "I wonder what it is?\n"
# 1162 "data/maps/SlateportCity/scripts.pory"
	.string "What could it be?$"
# 1163 "data/maps/SlateportCity/scripts.pory"

# 1164 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_CaptainComeBackWithBigFish:
# 1165 "data/maps/SlateportCity/scripts.pory"
	.string "What's going on here?\p"
# 1166 "data/maps/SlateportCity/scripts.pory"
	.string "Did the good CAPTAIN come back with\n"
# 1167 "data/maps/SlateportCity/scripts.pory"
	.string "a big fish from the ocean floor?$"
# 1168 "data/maps/SlateportCity/scripts.pory"

# 1169 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_AmIOnTV:
# 1170 "data/maps/SlateportCity/scripts.pory"
	.string "Hey! Are you watching?\n"
# 1171 "data/maps/SlateportCity/scripts.pory"
	.string "Am I on TV?$"
# 1172 "data/maps/SlateportCity/scripts.pory"

# 1173 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_CaptainsACelebrity:
# 1174 "data/maps/SlateportCity/scripts.pory"
	.string "A TV interview! Here!\n"
# 1175 "data/maps/SlateportCity/scripts.pory"
	.string "The CAPTAIN's a celebrity!$"
# 1176 "data/maps/SlateportCity/scripts.pory"

# 1177 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BigSmileForCamera:
# 1178 "data/maps/SlateportCity/scripts.pory"
	.string "TY: Okay, CAPT. STERN, a big smile\n"
# 1179 "data/maps/SlateportCity/scripts.pory"
	.string "for the camera!$"
# 1180 "data/maps/SlateportCity/scripts.pory"

# 1181 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_MostInvaluableExperience:
# 1182 "data/maps/SlateportCity/scripts.pory"
	.string "GABBY: I see, I see. You've had a most\n"
# 1183 "data/maps/SlateportCity/scripts.pory"
	.string "invaluable experience…$"
# 1184 "data/maps/SlateportCity/scripts.pory"

# 1185 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternMoveAheadWithExploration:
# 1186 "data/maps/SlateportCity/scripts.pory"
	.string "CAPT. STERN: Yes, indeed. We intend to\n"
# 1187 "data/maps/SlateportCity/scripts.pory"
	.string "move ahead with our exploration.$"
# 1188 "data/maps/SlateportCity/scripts.pory"

# 1189 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_GabbyWonderfulThanksForInterview:
# 1190 "data/maps/SlateportCity/scripts.pory"
	.string "GABBY: That's wonderful, CAPT. STERN!\n"
# 1191 "data/maps/SlateportCity/scripts.pory"
	.string "Thank you for taking the time from\l"
# 1192 "data/maps/SlateportCity/scripts.pory"
	.string "your busy schedule to talk to us.\p"
# 1193 "data/maps/SlateportCity/scripts.pory"
	.string "We hope we can interview you again\n"
# 1194 "data/maps/SlateportCity/scripts.pory"
	.string "with news of more discoveries!$"
# 1195 "data/maps/SlateportCity/scripts.pory"

# 1196 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternWhewFirstInterview:
# 1197 "data/maps/SlateportCity/scripts.pory"
	.string "CAPT. STERN: Whew…\p"
# 1198 "data/maps/SlateportCity/scripts.pory"
	.string "That was my first time to be filmed for\n"
# 1199 "data/maps/SlateportCity/scripts.pory"
	.string "TV. That was nerve-wracking.$"
# 1200 "data/maps/SlateportCity/scripts.pory"

# 1201 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_OhPlayerWeMadeDiscovery:
# 1202 "data/maps/SlateportCity/scripts.pory"
	.string "Oh! {PLAYER}{KUN}!\n"
# 1203 "data/maps/SlateportCity/scripts.pory"
	.string "You're looking great!\p"
# 1204 "data/maps/SlateportCity/scripts.pory"
	.string "We made a huge discovery on our last\n"
# 1205 "data/maps/SlateportCity/scripts.pory"
	.string "seafloor exploration.\p"
# 1206 "data/maps/SlateportCity/scripts.pory"
	.string "We found an underwater cavern on\n"
# 1207 "data/maps/SlateportCity/scripts.pory"
	.string "ROUTE 128.\p"
# 1208 "data/maps/SlateportCity/scripts.pory"
	.string "We think it's the habitat of a POKéMON\n"
# 1209 "data/maps/SlateportCity/scripts.pory"
	.string "that's said to have been long extinct.$"
# 1210 "data/maps/SlateportCity/scripts.pory"

# 1211 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_AquaWillAssumeControlOfSubmarine:
# 1212 "data/maps/SlateportCity/scripts.pory"
	.string "Fufufu…\n"
# 1213 "data/maps/SlateportCity/scripts.pory"
	.string "CAPT. STERN, I presume.\p"
# 1214 "data/maps/SlateportCity/scripts.pory"
	.string "We of TEAM AQUA will assume\n"
# 1215 "data/maps/SlateportCity/scripts.pory"
	.string "control of your submarine!\p"
# 1216 "data/maps/SlateportCity/scripts.pory"
	.string "Your objections are meaningless!\n"
# 1217 "data/maps/SlateportCity/scripts.pory"
	.string "We expect your total cooperation!\p"
# 1218 "data/maps/SlateportCity/scripts.pory"
	.string "Fufufu…\n"
# 1219 "data/maps/SlateportCity/scripts.pory"
	.string "Just watch and learn what TEAM\l"
# 1220 "data/maps/SlateportCity/scripts.pory"
	.string "AQUA has planned!$"
# 1221 "data/maps/SlateportCity/scripts.pory"

# 1222 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternWhatWasAllThat:
# 1223 "data/maps/SlateportCity/scripts.pory"
	.string "CAPT. STERN: What was that all about?\p"
# 1224 "data/maps/SlateportCity/scripts.pory"
	.string "It sounded like someone using\n"
# 1225 "data/maps/SlateportCity/scripts.pory"
	.string "a megaphone…\p"
# 1226 "data/maps/SlateportCity/scripts.pory"
	.string "Where did it come from?$"
# 1227 "data/maps/SlateportCity/scripts.pory"

# 1228 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_FromHarborTryingToTakeSub:
# 1229 "data/maps/SlateportCity/scripts.pory"
	.string "It's from the HARBOR!\p"
# 1230 "data/maps/SlateportCity/scripts.pory"
	.string "The submarine!\n"
# 1231 "data/maps/SlateportCity/scripts.pory"
	.string "They're trying to take it!$"
# 1232 "data/maps/SlateportCity/scripts.pory"

# 1233 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_PleaseComeWithMe:
# 1234 "data/maps/SlateportCity/scripts.pory"
	.string "{PLAYER}{KUN}!\n"
# 1235 "data/maps/SlateportCity/scripts.pory"
	.string "Please, come with me!$"
# 1236 "data/maps/SlateportCity/scripts.pory"

# 1237 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BattleTentSign:
# 1238 "data/maps/SlateportCity/scripts.pory"
	.string "BATTLE TENT SLATEPORT SITE\n"
# 1239 "data/maps/SlateportCity/scripts.pory"
	.string "“Find it! The ultimate POKéMON!”$"
# 1240 "data/maps/SlateportCity/scripts.pory"

# 1241 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternsShipyardWantedSign:
# 1242 "data/maps/SlateportCity/scripts.pory"
	.string "STERN'S SHIPYARD\p"
# 1243 "data/maps/SlateportCity/scripts.pory"
	.string "“Wanted: A sailor capable of sailing\n"
# 1244 "data/maps/SlateportCity/scripts.pory"
	.string "in all currents.”$"
# 1245 "data/maps/SlateportCity/scripts.pory"

# 1246 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternsShipyardNearsCompletion:
# 1247 "data/maps/SlateportCity/scripts.pory"
	.string "STERN'S SHIPYARD\p"
# 1248 "data/maps/SlateportCity/scripts.pory"
	.string "“The ferry S.S. TIDAL nears\n"
# 1249 "data/maps/SlateportCity/scripts.pory"
	.string "completion for serving the ports of\l"
# 1250 "data/maps/SlateportCity/scripts.pory"
	.string "SLATEPORT and LILYCOVE.”$"
# 1251 "data/maps/SlateportCity/scripts.pory"

# 1252 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternsShipyardFerryComplete:
# 1253 "data/maps/SlateportCity/scripts.pory"
	.string "STERN'S SHIPYARD\p"
# 1254 "data/maps/SlateportCity/scripts.pory"
	.string "“Boarding of the SLATEPORT-LILYCOVE\n"
# 1255 "data/maps/SlateportCity/scripts.pory"
	.string "ferry S.S. TIDAL is handled at the\l"
# 1256 "data/maps/SlateportCity/scripts.pory"
	.string "HARBOR.”$"
# 1257 "data/maps/SlateportCity/scripts.pory"

# 1258 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_PokemonFanClubSign:
# 1259 "data/maps/SlateportCity/scripts.pory"
	.string "POKéMON FAN CLUB\n"
# 1260 "data/maps/SlateportCity/scripts.pory"
	.string "“Calling all fans of POKéMON!”$"
# 1261 "data/maps/SlateportCity/scripts.pory"

# 1262 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_OceanicMuseumSign:
# 1263 "data/maps/SlateportCity/scripts.pory"
	.string "“The endless sea sustains\n"
# 1264 "data/maps/SlateportCity/scripts.pory"
	.string "all life.”\p"
# 1265 "data/maps/SlateportCity/scripts.pory"
	.string "OCEANIC MUSEUM$"
# 1266 "data/maps/SlateportCity/scripts.pory"

# 1267 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_CitySign:
# 1268 "data/maps/SlateportCity/scripts.pory"
	.string "SLATEPORT CITY\p"
# 1269 "data/maps/SlateportCity/scripts.pory"
	.string "“The port where people and POKéMON\n"
# 1270 "data/maps/SlateportCity/scripts.pory"
	.string "cross paths.”$"
# 1271 "data/maps/SlateportCity/scripts.pory"

# 1272 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_MarketSign:
# 1273 "data/maps/SlateportCity/scripts.pory"
	.string "SLATEPORT MARKET\n"
# 1274 "data/maps/SlateportCity/scripts.pory"
	.string "“Unique items found nowhere else!”$"
# 1275 "data/maps/SlateportCity/scripts.pory"

# 1276 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_HarborFerryUnderConstruction:
# 1277 "data/maps/SlateportCity/scripts.pory"
	.string "SLATEPORT HARBOR\p"
# 1278 "data/maps/SlateportCity/scripts.pory"
	.string "“The ferry S.S. TIDAL is under\n"
# 1279 "data/maps/SlateportCity/scripts.pory"
	.string "construction in the SHIPYARD.\p"
# 1280 "data/maps/SlateportCity/scripts.pory"
	.string "“Service is scheduled to begin\n"
# 1281 "data/maps/SlateportCity/scripts.pory"
	.string "shortly.”$"
# 1282 "data/maps/SlateportCity/scripts.pory"

# 1283 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_HarborSign:
# 1284 "data/maps/SlateportCity/scripts.pory"
	.string "SLATEPORT HARBOR\p"
# 1285 "data/maps/SlateportCity/scripts.pory"
	.string "“Enjoy a delightful cruise on\n"
# 1286 "data/maps/SlateportCity/scripts.pory"
	.string "the ferry S.S. TIDAL.”$"
# 1287 "data/maps/SlateportCity/scripts.pory"

# 1288 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_NameRatersHouseSign:
# 1289 "data/maps/SlateportCity/scripts.pory"
	.string "NAME RATER'S HOUSE\n"
# 1290 "data/maps/SlateportCity/scripts.pory"
	.string "“POKéMON nicknames rated.”$"
# 1291 "data/maps/SlateportCity/scripts.pory"

# 1292 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ExplainBerries:
# 1293 "data/maps/SlateportCity/scripts.pory"
	.string "If a wild POKéMON gets hurt, it heals\n"
# 1294 "data/maps/SlateportCity/scripts.pory"
	.string "itself by chewing on BERRIES.\p"
# 1295 "data/maps/SlateportCity/scripts.pory"
	.string "Did you know that?\p"
# 1296 "data/maps/SlateportCity/scripts.pory"
	.string "Somebody saw that and got the idea\n"
# 1297 "data/maps/SlateportCity/scripts.pory"
	.string "of making medicine from BERRIES.\p"
# 1298 "data/maps/SlateportCity/scripts.pory"
	.string "Did you know that?\p"
# 1299 "data/maps/SlateportCity/scripts.pory"
	.string "To turn BERRIES into medicine,\n"
# 1300 "data/maps/SlateportCity/scripts.pory"
	.string "they must be crushed into powder.\p"
# 1301 "data/maps/SlateportCity/scripts.pory"
	.string "Did you know that?\p"
# 1302 "data/maps/SlateportCity/scripts.pory"
	.string "You seem to have an interest\n"
# 1303 "data/maps/SlateportCity/scripts.pory"
	.string "in BERRIES!\p"
# 1304 "data/maps/SlateportCity/scripts.pory"
	.string "I've got something good for someone\n"
# 1305 "data/maps/SlateportCity/scripts.pory"
	.string "like you.$"
# 1306 "data/maps/SlateportCity/scripts.pory"

# 1307 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ExplainBerryPowder:
# 1308 "data/maps/SlateportCity/scripts.pory"
	.string "I recently had machines installed at\n"
# 1309 "data/maps/SlateportCity/scripts.pory"
	.string "POKéMON CENTERS for crushing BERRIES.\p"
# 1310 "data/maps/SlateportCity/scripts.pory"
	.string "The BERRY CRUSH machines are at\n"
# 1311 "data/maps/SlateportCity/scripts.pory"
	.string "the DIRECT CORNER upstairs.\p"
# 1312 "data/maps/SlateportCity/scripts.pory"
	.string "Did you know?\p"
# 1313 "data/maps/SlateportCity/scripts.pory"
	.string "Could you make BERRY POWDER for\n"
# 1314 "data/maps/SlateportCity/scripts.pory"
	.string "me using those machines?\p"
# 1315 "data/maps/SlateportCity/scripts.pory"
	.string "I can make you all sorts of medicine\n"
# 1316 "data/maps/SlateportCity/scripts.pory"
	.string "if you bring me lots of BERRY POWDER.$"
# 1317 "data/maps/SlateportCity/scripts.pory"

# 1318 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BroughtMeSomeBerryPowder:
# 1319 "data/maps/SlateportCity/scripts.pory"
	.string "Have you brought me some\n"
# 1320 "data/maps/SlateportCity/scripts.pory"
	.string "BERRY POWDER?$"
# 1321 "data/maps/SlateportCity/scripts.pory"

# 1322 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ExchangeWhatWithIt:
# 1323 "data/maps/SlateportCity/scripts.pory"
	.string "What would you like to exchange\n"
# 1324 "data/maps/SlateportCity/scripts.pory"
	.string "it with?$"
# 1325 "data/maps/SlateportCity/scripts.pory"

# 1326 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ExchangeBerryPowderForItem:
# 1327 "data/maps/SlateportCity/scripts.pory"
	.string "Okay, you want to exchange your\n"
# 1328 "data/maps/SlateportCity/scripts.pory"
	.string "BERRY POWDER for one {STR_VAR_1}?$"
# 1329 "data/maps/SlateportCity/scripts.pory"

# 1330 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_DontHaveEnoughBerryPowder:
# 1331 "data/maps/SlateportCity/scripts.pory"
	.string "Oh, dear. You don't have enough\n"
# 1332 "data/maps/SlateportCity/scripts.pory"
	.string "BERRY POWDER.$"
# 1333 "data/maps/SlateportCity/scripts.pory"

# 1334 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_FineBerryPowderTradeSomethingElse:
# 1335 "data/maps/SlateportCity/scripts.pory"
	.string "This is fine BERRY POWDER.\n"
# 1336 "data/maps/SlateportCity/scripts.pory"
	.string "It will make excellent medicine.\p"
# 1337 "data/maps/SlateportCity/scripts.pory"
	.string "Would you like to trade more of your\n"
# 1338 "data/maps/SlateportCity/scripts.pory"
	.string "BERRY POWDER for something else?$"
# 1339 "data/maps/SlateportCity/scripts.pory"

# 1340 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_WhenYouGetMoreBringItToMe:
# 1341 "data/maps/SlateportCity/scripts.pory"
	.string "Okay! When you get some more\n"
# 1342 "data/maps/SlateportCity/scripts.pory"
	.string "BERRY POWDER, bring it to me, please!$"
# 1343 "data/maps/SlateportCity/scripts.pory"

# 1344 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ComeBackToTradeBerryPowder:
# 1345 "data/maps/SlateportCity/scripts.pory"
	.string "Come back if you'd like to trade your\n"
# 1346 "data/maps/SlateportCity/scripts.pory"
	.string "BERRY POWDER for some medicine.\p"
# 1347 "data/maps/SlateportCity/scripts.pory"
	.string "I'm always running a bazaar here.\p"
# 1348 "data/maps/SlateportCity/scripts.pory"
	.string "Did you know?$"
# 1349 "data/maps/SlateportCity/scripts.pory"

# 1350 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_YouDroveTeamAquaAway:
# 1351 "data/maps/SlateportCity/scripts.pory"
	.string "SCOTT: Huh?\n"
# 1352 "data/maps/SlateportCity/scripts.pory"
	.string "I'm sure I met you somewhere before.\p"
# 1353 "data/maps/SlateportCity/scripts.pory"
	.string "Have I introduced myself to you?\n"
# 1354 "data/maps/SlateportCity/scripts.pory"
	.string "If not, my name's SCOTT.\p"
# 1355 "data/maps/SlateportCity/scripts.pory"
	.string "I just saw TEAM AQUA run away from\n"
# 1356 "data/maps/SlateportCity/scripts.pory"
	.string "here like they were stung.\p"
# 1357 "data/maps/SlateportCity/scripts.pory"
	.string "Let me guess--you drove them away?$"
# 1358 "data/maps/SlateportCity/scripts.pory"

# 1359 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_MaybeThisTrainer:
# 1360 "data/maps/SlateportCity/scripts.pory"
	.string "SCOTT: Hmm…\n"
# 1361 "data/maps/SlateportCity/scripts.pory"
	.string "Maybe, just maybe, this TRAINER…$"
# 1362 "data/maps/SlateportCity/scripts.pory"

# 1363 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_LetsRegisterEachOther:
# 1364 "data/maps/SlateportCity/scripts.pory"
	.string "SCOTT: All right! I think you're going\n"
# 1365 "data/maps/SlateportCity/scripts.pory"
	.string "to become a good friend.\p"
# 1366 "data/maps/SlateportCity/scripts.pory"
	.string "So, let's register each other in our\n"
# 1367 "data/maps/SlateportCity/scripts.pory"
	.string "POKéNAVS.\p"
# 1368 "data/maps/SlateportCity/scripts.pory"
	.string "… … … … … …$"
# 1369 "data/maps/SlateportCity/scripts.pory"

# 1370 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_RegisteredScott:
# 1371 "data/maps/SlateportCity/scripts.pory"
	.string "Registered this SCOTT person\n"
# 1372 "data/maps/SlateportCity/scripts.pory"
	.string "in the POKéNAV.$"
# 1373 "data/maps/SlateportCity/scripts.pory"

# 1374 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou:
# 1375 "data/maps/SlateportCity/scripts.pory"
	.string "SCOTT: What I'd like to do is tag along\n"
# 1376 "data/maps/SlateportCity/scripts.pory"
	.string "with you, but I do want to keep an eye\l"
# 1377 "data/maps/SlateportCity/scripts.pory"
	.string "on the talents of other people, too.\p"
# 1378 "data/maps/SlateportCity/scripts.pory"
	.string "So, I'll be off to roam other towns\n"
# 1379 "data/maps/SlateportCity/scripts.pory"
	.string "a bit more.\p"
# 1380 "data/maps/SlateportCity/scripts.pory"
	.string "Be seeing you, {PLAYER}{KUN}!$"
# 1381 "data/maps/SlateportCity/scripts.pory"

# 1382 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_TakingBattleTentChallenge:
# 1383 "data/maps/SlateportCity/scripts.pory"
	.string "SCOTT: Oh, hey!\n"
# 1384 "data/maps/SlateportCity/scripts.pory"
	.string "If it isn't {PLAYER}{KUN}!\p"
# 1385 "data/maps/SlateportCity/scripts.pory"
	.string "{PLAYER}{KUN}, let me guess--you're going\n"
# 1386 "data/maps/SlateportCity/scripts.pory"
	.string "to take the BATTLE TENT challenge?\p"
# 1387 "data/maps/SlateportCity/scripts.pory"
	.string "Yeah! That's a good idea!\n"
# 1388 "data/maps/SlateportCity/scripts.pory"
	.string "That's a really great idea!\p"
# 1389 "data/maps/SlateportCity/scripts.pory"
	.string "After all, a tough TRAINER is\n"
# 1390 "data/maps/SlateportCity/scripts.pory"
	.string "the perfect fit for the BATTLE TENT!\p"
# 1391 "data/maps/SlateportCity/scripts.pory"
	.string "Give it your best effort!$"
