# 1 "data/maps/MtChimney/scripts.pory"

# 2 "data/maps/MtChimney/scripts.pory"
.set LOCALID_ARCHIE, 1
# 3 "data/maps/MtChimney/scripts.pory"
.set LOCALID_MAXIE, 2
# 4 "data/maps/MtChimney/scripts.pory"
.set LOCALID_TABITHA, 3
# 5 "data/maps/MtChimney/scripts.pory"
.set LOCALID_MAGMA_GRUNT_2, 22
# 6 "data/maps/MtChimney/scripts.pory"
.set LOCALID_MAGMA_GRUNT_1, 29
# 7 "data/maps/MtChimney/scripts.pory"
.set LOCALID_LITLEO, 31
# 8 "data/maps/MtChimney/scripts.pory"
.set LOCALID_SKIDDO, 32
# 9 "data/maps/MtChimney/scripts.pory"
.set LOCALID_GEODUDE, 33
# 10 "data/maps/MtChimney/scripts.pory"

# 11 "data/maps/MtChimney/scripts.pory"
MtChimney_MapScripts::
# 12 "data/maps/MtChimney/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_OnResume
# 13 "data/maps/MtChimney/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_OnTransition
# 14 "data/maps/MtChimney/scripts.pory"
	.byte 0
# 15 "data/maps/MtChimney/scripts.pory"

# 16 "data/maps/MtChimney/scripts.pory"
MtChimney_OnTransition:
# 17 "data/maps/MtChimney/scripts.pory"
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 1
# 18 "data/maps/MtChimney/scripts.pory"
	end
# 19 "data/maps/MtChimney/scripts.pory"

# 20 "data/maps/MtChimney/scripts.pory"
MtChimney_OnResume:
# 21 "data/maps/MtChimney/scripts.pory"
	setstepcallback STEP_CB_ASH
# 22 "data/maps/MtChimney/scripts.pory"
	end
# 23 "data/maps/MtChimney/scripts.pory"

# 24 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Archie::
# 25 "data/maps/MtChimney/scripts.pory"
	lock
# 26 "data/maps/MtChimney/scripts.pory"
	faceplayer
# 27 "data/maps/MtChimney/scripts.pory"
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
# 28 "data/maps/MtChimney/scripts.pory"
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
# 29 "data/maps/MtChimney/scripts.pory"
	closemessage
# 30 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_ARCHIE, Common_Movement_FaceOriginalDirection
# 31 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 32 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
# 33 "data/maps/MtChimney/scripts.pory"
	release
# 34 "data/maps/MtChimney/scripts.pory"
	end
# 35 "data/maps/MtChimney/scripts.pory"

# 36 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieGoStopTeamMagma::
# 37 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
# 38 "data/maps/MtChimney/scripts.pory"
	return
# 39 "data/maps/MtChimney/scripts.pory"

# 40 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieBusyFighting::
# 41 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
# 42 "data/maps/MtChimney/scripts.pory"
	return
# 43 "data/maps/MtChimney/scripts.pory"

# 44 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Maxie::
# 45 "data/maps/MtChimney/scripts.pory"
	lockall
# 46 "data/maps/MtChimney/scripts.pory"
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
# 47 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
# 48 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
# 49 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 50 "data/maps/MtChimney/scripts.pory"
	playse SE_PIN
# 51 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_ExclamationMark
# 52 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 53 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_Delay48
# 54 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 55 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
# 56 "data/maps/MtChimney/scripts.pory"
	playse SE_M_BATON_PASS
# 57 "data/maps/MtChimney/scripts.pory"
	waitse
# 58 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_LITLEO
# 59 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_MAXIES_LITLEO
# 60 "data/maps/MtChimney/scripts.pory"
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
# 61 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
# 62 "data/maps/MtChimney/scripts.pory"
	closemessage
# 63 "data/maps/MtChimney/scripts.pory"
	delay 30
# 64 "data/maps/MtChimney/scripts.pory"
	fadescreen FADE_TO_BLACK
# 65 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_MAXIE
# 66 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_MAGMA_GRUNT_1
# 67 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_TABITHA
# 68 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_MAGMA_GRUNT_2
# 69 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
# 70 "data/maps/MtChimney/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 71 "data/maps/MtChimney/scripts.pory"
	setobjectxyperm LOCALID_ARCHIE, 10, 12
# 72 "data/maps/MtChimney/scripts.pory"
	addobject LOCALID_ARCHIE
# 73 "data/maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieApproachPlayerEast
# 74 "data/maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieApproachPlayerNorth
# 75 "data/maps/MtChimney/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 76 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 77 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
# 78 "data/maps/MtChimney/scripts.pory"
	closemessage
# 79 "data/maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieExitEast
# 80 "data/maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieExitNorth
# 81 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_ARCHIE
# 82 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
# 83 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
# 84 "data/maps/MtChimney/scripts.pory"
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO
# 85 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
# 86 "data/maps/MtChimney/scripts.pory"
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
# 87 "data/maps/MtChimney/scripts.pory"
	releaseall
# 88 "data/maps/MtChimney/scripts.pory"
	end
# 89 "data/maps/MtChimney/scripts.pory"

# 90 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieApproachPlayerEast::
# 91 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
# 92 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 93 "data/maps/MtChimney/scripts.pory"
	return
# 94 "data/maps/MtChimney/scripts.pory"

# 95 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieApproachPlayerNorth::
# 96 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
# 97 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 98 "data/maps/MtChimney/scripts.pory"
	return
# 99 "data/maps/MtChimney/scripts.pory"

# 100 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieExitEast::
# 101 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieExitEast
# 102 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 103 "data/maps/MtChimney/scripts.pory"
	return
# 104 "data/maps/MtChimney/scripts.pory"

# 105 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieExitNorth::
# 106 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieExitNorth
# 107 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 108 "data/maps/MtChimney/scripts.pory"
	return
# 109 "data/maps/MtChimney/scripts.pory"

# 110 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_LavaCookieLady::
# 111 "data/maps/MtChimney/scripts.pory"
	lock
# 112 "data/maps/MtChimney/scripts.pory"
	faceplayer
# 113 "data/maps/MtChimney/scripts.pory"
	showmoneybox 0, 0
# 114 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
# 115 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_DeclineLavaCookie
# 116 "data/maps/MtChimney/scripts.pory"
	checkmoney 200
# 117 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_NotEnoughMoney
# 118 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
# 119 "data/maps/MtChimney/scripts.pory"
	checkitemspace ITEM_LAVA_COOKIE
# 120 "data/maps/MtChimney/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RemoveMoney
# 121 "data/maps/MtChimney/scripts.pory"
.if OW_SHOW_ITEM_DESCRIPTIONS == OW_ITEM_DESCRIPTIONS_OFF
# 122 "data/maps/MtChimney/scripts.pory"
	giveitem ITEM_LAVA_COOKIE
# 123 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
# 124 "data/maps/MtChimney/scripts.pory"
	hidemoneybox
# 125 "data/maps/MtChimney/scripts.pory"
	release
# 126 "data/maps/MtChimney/scripts.pory"
	end
# 127 "data/maps/MtChimney/scripts.pory"

# 128 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BagIsFull::
# 129 "data/maps/MtChimney/scripts.pory"
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
# 130 "data/maps/MtChimney/scripts.pory"
	hidemoneybox
# 131 "data/maps/MtChimney/scripts.pory"
	release
# 132 "data/maps/MtChimney/scripts.pory"
	end
# 133 "data/maps/MtChimney/scripts.pory"
.else
# 134 "data/maps/MtChimney/scripts.pory"
	hidemoneybox
# 135 "data/maps/MtChimney/scripts.pory"
	giveitem ITEM_LAVA_COOKIE
# 136 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
# 137 "data/maps/MtChimney/scripts.pory"
	release
# 138 "data/maps/MtChimney/scripts.pory"
	end
# 139 "data/maps/MtChimney/scripts.pory"

# 140 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BagIsFull::
# 141 "data/maps/MtChimney/scripts.pory"
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
# 142 "data/maps/MtChimney/scripts.pory"
	release
# 143 "data/maps/MtChimney/scripts.pory"
	end
# 144 "data/maps/MtChimney/scripts.pory"
.endif @ OW_SHOW_ITEM_DESCRIPTIONS
# 145 "data/maps/MtChimney/scripts.pory"

# 146 "data/maps/MtChimney/scripts.pory"

# 147 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_RemoveMoney::
# 148 "data/maps/MtChimney/scripts.pory"
	removemoney 200
# 149 "data/maps/MtChimney/scripts.pory"
	updatemoneybox
# 150 "data/maps/MtChimney/scripts.pory"
	return
# 151 "data/maps/MtChimney/scripts.pory"

# 152 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_DeclineLavaCookie::
# 153 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
# 154 "data/maps/MtChimney/scripts.pory"
	hidemoneybox
# 155 "data/maps/MtChimney/scripts.pory"
	release
# 156 "data/maps/MtChimney/scripts.pory"
	end
# 157 "data/maps/MtChimney/scripts.pory"

# 158 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_NotEnoughMoney::
# 159 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
# 160 "data/maps/MtChimney/scripts.pory"
	hidemoneybox
# 161 "data/maps/MtChimney/scripts.pory"
	release
# 162 "data/maps/MtChimney/scripts.pory"
	end
# 163 "data/maps/MtChimney/scripts.pory"

# 164 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieApproachPlayerEast:
# 165 "data/maps/MtChimney/scripts.pory"
	walk_up
# 166 "data/maps/MtChimney/scripts.pory"
	walk_up
# 167 "data/maps/MtChimney/scripts.pory"
	walk_up
# 168 "data/maps/MtChimney/scripts.pory"
	walk_up
# 169 "data/maps/MtChimney/scripts.pory"
	walk_up
# 170 "data/maps/MtChimney/scripts.pory"
	walk_up
# 171 "data/maps/MtChimney/scripts.pory"
	walk_right
# 172 "data/maps/MtChimney/scripts.pory"
	step_end
# 173 "data/maps/MtChimney/scripts.pory"

# 174 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieExitEast:
# 175 "data/maps/MtChimney/scripts.pory"
	walk_left
# 176 "data/maps/MtChimney/scripts.pory"
	walk_down
# 177 "data/maps/MtChimney/scripts.pory"
	walk_down
# 178 "data/maps/MtChimney/scripts.pory"
	walk_down
# 179 "data/maps/MtChimney/scripts.pory"
	walk_down
# 180 "data/maps/MtChimney/scripts.pory"
	walk_down
# 181 "data/maps/MtChimney/scripts.pory"
	walk_down
# 182 "data/maps/MtChimney/scripts.pory"
	walk_down
# 183 "data/maps/MtChimney/scripts.pory"
	step_end
# 184 "data/maps/MtChimney/scripts.pory"

# 185 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieApproachPlayerNorth:
# 186 "data/maps/MtChimney/scripts.pory"
	walk_up
# 187 "data/maps/MtChimney/scripts.pory"
	walk_up
# 188 "data/maps/MtChimney/scripts.pory"
	walk_up
# 189 "data/maps/MtChimney/scripts.pory"
	walk_up
# 190 "data/maps/MtChimney/scripts.pory"
	walk_up
# 191 "data/maps/MtChimney/scripts.pory"
	walk_right
# 192 "data/maps/MtChimney/scripts.pory"
	walk_right
# 193 "data/maps/MtChimney/scripts.pory"
	step_end
# 194 "data/maps/MtChimney/scripts.pory"

# 195 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieExitNorth:
# 196 "data/maps/MtChimney/scripts.pory"
	walk_left
# 197 "data/maps/MtChimney/scripts.pory"
	walk_left
# 198 "data/maps/MtChimney/scripts.pory"
	walk_down
# 199 "data/maps/MtChimney/scripts.pory"
	walk_down
# 200 "data/maps/MtChimney/scripts.pory"
	walk_down
# 201 "data/maps/MtChimney/scripts.pory"
	walk_down
# 202 "data/maps/MtChimney/scripts.pory"
	walk_down
# 203 "data/maps/MtChimney/scripts.pory"
	walk_down
# 204 "data/maps/MtChimney/scripts.pory"
	walk_down
# 205 "data/maps/MtChimney/scripts.pory"
	step_end
# 206 "data/maps/MtChimney/scripts.pory"

# 207 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused1:
# 208 "data/maps/MtChimney/scripts.pory"
	walk_down
# 209 "data/maps/MtChimney/scripts.pory"
	walk_down
# 210 "data/maps/MtChimney/scripts.pory"
	walk_down
# 211 "data/maps/MtChimney/scripts.pory"
	walk_down
# 212 "data/maps/MtChimney/scripts.pory"
	walk_down
# 213 "data/maps/MtChimney/scripts.pory"
	walk_left
# 214 "data/maps/MtChimney/scripts.pory"
	walk_left
# 215 "data/maps/MtChimney/scripts.pory"
	walk_down
# 216 "data/maps/MtChimney/scripts.pory"
	walk_down
# 217 "data/maps/MtChimney/scripts.pory"
	walk_down
# 218 "data/maps/MtChimney/scripts.pory"
	walk_down
# 219 "data/maps/MtChimney/scripts.pory"
	walk_left
# 220 "data/maps/MtChimney/scripts.pory"
	walk_left
# 221 "data/maps/MtChimney/scripts.pory"
	walk_left
# 222 "data/maps/MtChimney/scripts.pory"
	walk_left
# 223 "data/maps/MtChimney/scripts.pory"
	walk_left
# 224 "data/maps/MtChimney/scripts.pory"
	walk_down
# 225 "data/maps/MtChimney/scripts.pory"
	step_end
# 226 "data/maps/MtChimney/scripts.pory"

# 227 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused2:
# 228 "data/maps/MtChimney/scripts.pory"
	walk_down
# 229 "data/maps/MtChimney/scripts.pory"
	walk_down
# 230 "data/maps/MtChimney/scripts.pory"
	walk_down
# 231 "data/maps/MtChimney/scripts.pory"
	walk_down
# 232 "data/maps/MtChimney/scripts.pory"
	walk_left
# 233 "data/maps/MtChimney/scripts.pory"
	walk_left
# 234 "data/maps/MtChimney/scripts.pory"
	walk_left
# 235 "data/maps/MtChimney/scripts.pory"
	walk_down
# 236 "data/maps/MtChimney/scripts.pory"
	step_end
# 237 "data/maps/MtChimney/scripts.pory"

# 238 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused3:
# 239 "data/maps/MtChimney/scripts.pory"
	walk_right
# 240 "data/maps/MtChimney/scripts.pory"
	walk_down
# 241 "data/maps/MtChimney/scripts.pory"
	walk_down
# 242 "data/maps/MtChimney/scripts.pory"
	walk_down
# 243 "data/maps/MtChimney/scripts.pory"
	walk_down
# 244 "data/maps/MtChimney/scripts.pory"
	walk_left
# 245 "data/maps/MtChimney/scripts.pory"
	walk_left
# 246 "data/maps/MtChimney/scripts.pory"
	walk_left
# 247 "data/maps/MtChimney/scripts.pory"
	walk_left
# 248 "data/maps/MtChimney/scripts.pory"
	walk_left
# 249 "data/maps/MtChimney/scripts.pory"
	walk_down
# 250 "data/maps/MtChimney/scripts.pory"
	walk_down
# 251 "data/maps/MtChimney/scripts.pory"
	walk_down
# 252 "data/maps/MtChimney/scripts.pory"
	walk_down
# 253 "data/maps/MtChimney/scripts.pory"
	step_end
# 254 "data/maps/MtChimney/scripts.pory"

# 255 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused4:
# 256 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 257 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 258 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 259 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 260 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 261 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 262 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 263 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 264 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 265 "data/maps/MtChimney/scripts.pory"
	walk_left
# 266 "data/maps/MtChimney/scripts.pory"
	walk_left
# 267 "data/maps/MtChimney/scripts.pory"
	walk_down
# 268 "data/maps/MtChimney/scripts.pory"
	walk_down
# 269 "data/maps/MtChimney/scripts.pory"
	walk_down
# 270 "data/maps/MtChimney/scripts.pory"
	walk_left
# 271 "data/maps/MtChimney/scripts.pory"
	walk_left
# 272 "data/maps/MtChimney/scripts.pory"
	walk_down
# 273 "data/maps/MtChimney/scripts.pory"
	walk_down
# 274 "data/maps/MtChimney/scripts.pory"
	walk_left
# 275 "data/maps/MtChimney/scripts.pory"
	walk_left
# 276 "data/maps/MtChimney/scripts.pory"
	walk_left
# 277 "data/maps/MtChimney/scripts.pory"
	walk_left
# 278 "data/maps/MtChimney/scripts.pory"
	walk_left
# 279 "data/maps/MtChimney/scripts.pory"
	walk_down
# 280 "data/maps/MtChimney/scripts.pory"
	step_end
# 281 "data/maps/MtChimney/scripts.pory"

# 282 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused5:
# 283 "data/maps/MtChimney/scripts.pory"
	delay_16
# 284 "data/maps/MtChimney/scripts.pory"
	delay_16
# 285 "data/maps/MtChimney/scripts.pory"
	delay_16
# 286 "data/maps/MtChimney/scripts.pory"
	walk_down
# 287 "data/maps/MtChimney/scripts.pory"
	walk_down
# 288 "data/maps/MtChimney/scripts.pory"
	walk_down
# 289 "data/maps/MtChimney/scripts.pory"
	walk_left
# 290 "data/maps/MtChimney/scripts.pory"
	walk_left
# 291 "data/maps/MtChimney/scripts.pory"
	walk_left
# 292 "data/maps/MtChimney/scripts.pory"
	walk_down
# 293 "data/maps/MtChimney/scripts.pory"
	step_end
# 294 "data/maps/MtChimney/scripts.pory"

# 295 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused6:
# 296 "data/maps/MtChimney/scripts.pory"
	delay_16
# 297 "data/maps/MtChimney/scripts.pory"
	walk_left
# 298 "data/maps/MtChimney/scripts.pory"
	walk_down
# 299 "data/maps/MtChimney/scripts.pory"
	walk_down
# 300 "data/maps/MtChimney/scripts.pory"
	walk_down
# 301 "data/maps/MtChimney/scripts.pory"
	walk_down
# 302 "data/maps/MtChimney/scripts.pory"
	walk_left
# 303 "data/maps/MtChimney/scripts.pory"
	walk_left
# 304 "data/maps/MtChimney/scripts.pory"
	walk_left
# 305 "data/maps/MtChimney/scripts.pory"
	walk_left
# 306 "data/maps/MtChimney/scripts.pory"
	walk_left
# 307 "data/maps/MtChimney/scripts.pory"
	walk_down
# 308 "data/maps/MtChimney/scripts.pory"
	walk_down
# 309 "data/maps/MtChimney/scripts.pory"
	walk_down
# 310 "data/maps/MtChimney/scripts.pory"
	walk_down
# 311 "data/maps/MtChimney/scripts.pory"
	step_end
# 312 "data/maps/MtChimney/scripts.pory"

# 313 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused7:
# 314 "data/maps/MtChimney/scripts.pory"
	delay_16
# 315 "data/maps/MtChimney/scripts.pory"
	walk_left
# 316 "data/maps/MtChimney/scripts.pory"
	walk_left
# 317 "data/maps/MtChimney/scripts.pory"
	walk_down
# 318 "data/maps/MtChimney/scripts.pory"
	walk_down
# 319 "data/maps/MtChimney/scripts.pory"
	walk_down
# 320 "data/maps/MtChimney/scripts.pory"
	walk_left
# 321 "data/maps/MtChimney/scripts.pory"
	walk_left
# 322 "data/maps/MtChimney/scripts.pory"
	walk_down
# 323 "data/maps/MtChimney/scripts.pory"
	walk_down
# 324 "data/maps/MtChimney/scripts.pory"
	walk_left
# 325 "data/maps/MtChimney/scripts.pory"
	walk_left
# 326 "data/maps/MtChimney/scripts.pory"
	walk_left
# 327 "data/maps/MtChimney/scripts.pory"
	walk_left
# 328 "data/maps/MtChimney/scripts.pory"
	walk_left
# 329 "data/maps/MtChimney/scripts.pory"
	walk_down
# 330 "data/maps/MtChimney/scripts.pory"
	step_end
# 331 "data/maps/MtChimney/scripts.pory"

# 332 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused8:
# 333 "data/maps/MtChimney/scripts.pory"
	delay_16
# 334 "data/maps/MtChimney/scripts.pory"
	walk_down
# 335 "data/maps/MtChimney/scripts.pory"
	walk_left
# 336 "data/maps/MtChimney/scripts.pory"
	walk_left
# 337 "data/maps/MtChimney/scripts.pory"
	walk_left
# 338 "data/maps/MtChimney/scripts.pory"
	walk_left
# 339 "data/maps/MtChimney/scripts.pory"
	walk_in_place_faster_down
# 340 "data/maps/MtChimney/scripts.pory"
	step_end
# 341 "data/maps/MtChimney/scripts.pory"

# 342 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused9:
# 343 "data/maps/MtChimney/scripts.pory"
	walk_down
# 344 "data/maps/MtChimney/scripts.pory"
	walk_down
# 345 "data/maps/MtChimney/scripts.pory"
	walk_down
# 346 "data/maps/MtChimney/scripts.pory"
	walk_down
# 347 "data/maps/MtChimney/scripts.pory"
	walk_left
# 348 "data/maps/MtChimney/scripts.pory"
	walk_left
# 349 "data/maps/MtChimney/scripts.pory"
	walk_left
# 350 "data/maps/MtChimney/scripts.pory"
	walk_left
# 351 "data/maps/MtChimney/scripts.pory"
	walk_left
# 352 "data/maps/MtChimney/scripts.pory"
	walk_down
# 353 "data/maps/MtChimney/scripts.pory"
	walk_down
# 354 "data/maps/MtChimney/scripts.pory"
	walk_down
# 355 "data/maps/MtChimney/scripts.pory"
	walk_down
# 356 "data/maps/MtChimney/scripts.pory"
	step_end
# 357 "data/maps/MtChimney/scripts.pory"

# 358 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused10:
# 359 "data/maps/MtChimney/scripts.pory"
	walk_down
# 360 "data/maps/MtChimney/scripts.pory"
	step_end
# 361 "data/maps/MtChimney/scripts.pory"

# 362 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused11:
# 363 "data/maps/MtChimney/scripts.pory"
	walk_down
# 364 "data/maps/MtChimney/scripts.pory"
	walk_down
# 365 "data/maps/MtChimney/scripts.pory"
	walk_down
# 366 "data/maps/MtChimney/scripts.pory"
	walk_down
# 367 "data/maps/MtChimney/scripts.pory"
	walk_down
# 368 "data/maps/MtChimney/scripts.pory"
	walk_down
# 369 "data/maps/MtChimney/scripts.pory"
	walk_down
# 370 "data/maps/MtChimney/scripts.pory"
	step_end
# 371 "data/maps/MtChimney/scripts.pory"

# 372 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused12:
# 373 "data/maps/MtChimney/scripts.pory"
	delay_16
# 374 "data/maps/MtChimney/scripts.pory"
	delay_16
# 375 "data/maps/MtChimney/scripts.pory"
	walk_in_place_faster_left
# 376 "data/maps/MtChimney/scripts.pory"
	delay_16
# 377 "data/maps/MtChimney/scripts.pory"
	walk_down
# 378 "data/maps/MtChimney/scripts.pory"
	walk_down
# 379 "data/maps/MtChimney/scripts.pory"
	walk_down
# 380 "data/maps/MtChimney/scripts.pory"
	walk_down
# 381 "data/maps/MtChimney/scripts.pory"
	walk_down
# 382 "data/maps/MtChimney/scripts.pory"
	step_end
# 383 "data/maps/MtChimney/scripts.pory"

# 384 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused13:
# 385 "data/maps/MtChimney/scripts.pory"
	delay_16
# 386 "data/maps/MtChimney/scripts.pory"
	delay_16
# 387 "data/maps/MtChimney/scripts.pory"
	delay_16
# 388 "data/maps/MtChimney/scripts.pory"
	delay_16
# 389 "data/maps/MtChimney/scripts.pory"
	delay_16
# 390 "data/maps/MtChimney/scripts.pory"
	delay_16
# 391 "data/maps/MtChimney/scripts.pory"
	walk_in_place_faster_left
# 392 "data/maps/MtChimney/scripts.pory"
	delay_16
# 393 "data/maps/MtChimney/scripts.pory"
	walk_down
# 394 "data/maps/MtChimney/scripts.pory"
	walk_down
# 395 "data/maps/MtChimney/scripts.pory"
	step_end
# 396 "data/maps/MtChimney/scripts.pory"

# 397 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused14:
# 398 "data/maps/MtChimney/scripts.pory"
	lock_facing_direction
# 399 "data/maps/MtChimney/scripts.pory"
	walk_fast_left
# 400 "data/maps/MtChimney/scripts.pory"
	unlock_facing_direction
# 401 "data/maps/MtChimney/scripts.pory"
	face_right
# 402 "data/maps/MtChimney/scripts.pory"
	step_end
# 403 "data/maps/MtChimney/scripts.pory"

# 404 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused15:
# 405 "data/maps/MtChimney/scripts.pory"
	walk_left
# 406 "data/maps/MtChimney/scripts.pory"
	walk_in_place_faster_right
# 407 "data/maps/MtChimney/scripts.pory"
	delay_16
# 408 "data/maps/MtChimney/scripts.pory"
	step_end
# 409 "data/maps/MtChimney/scripts.pory"

# 410 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyAquaGrunt1::
# 411 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
# 412 "data/maps/MtChimney/scripts.pory"
	end
# 413 "data/maps/MtChimney/scripts.pory"

# 414 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyAquaGrunt2::
# 415 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
# 416 "data/maps/MtChimney/scripts.pory"
	end
# 417 "data/maps/MtChimney/scripts.pory"

# 418 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyAquaGrunt3::
# 419 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
# 420 "data/maps/MtChimney/scripts.pory"
	end
# 421 "data/maps/MtChimney/scripts.pory"

# 422 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Tabitha::
# 423 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
# 424 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
# 425 "data/maps/MtChimney/scripts.pory"
	end
# 426 "data/maps/MtChimney/scripts.pory"

# 427 "data/maps/MtChimney/scripts.pory"
RemoveSkiddo::
# 428 "data/maps/MtChimney/scripts.pory"
	setvar VAR_MTCHIMNEY_SKIDDO, 1
# 429 "data/maps/MtChimney/scripts.pory"
	playse SE_M_BATON_PASS
# 430 "data/maps/MtChimney/scripts.pory"
	waitse
# 431 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_SKIDDO
# 432 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_COURTNEYS_SKIDDO
# 433 "data/maps/MtChimney/scripts.pory"
	end
# 434 "data/maps/MtChimney/scripts.pory"

# 435 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Grunt2::
# 436 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
# 437 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
# 438 "data/maps/MtChimney/scripts.pory"
	end
# 439 "data/maps/MtChimney/scripts.pory"

# 440 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt1::
# 441 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
# 442 "data/maps/MtChimney/scripts.pory"
	end
# 443 "data/maps/MtChimney/scripts.pory"

# 444 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt2::
# 445 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
# 446 "data/maps/MtChimney/scripts.pory"
	end
# 447 "data/maps/MtChimney/scripts.pory"

# 448 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt3::
# 449 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
# 450 "data/maps/MtChimney/scripts.pory"
	end
# 451 "data/maps/MtChimney/scripts.pory"

# 452 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt4::
# 453 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
# 454 "data/maps/MtChimney/scripts.pory"
	end
# 455 "data/maps/MtChimney/scripts.pory"

# 456 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt5::
# 457 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
# 458 "data/maps/MtChimney/scripts.pory"
	end
# 459 "data/maps/MtChimney/scripts.pory"

# 460 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt6::
# 461 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
# 462 "data/maps/MtChimney/scripts.pory"
	end
# 463 "data/maps/MtChimney/scripts.pory"

# 464 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_MagmaPoochyena::
# 465 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
# 466 "data/maps/MtChimney/scripts.pory"
	end
# 467 "data/maps/MtChimney/scripts.pory"

# 468 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_AquaPoochyena::
# 469 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
# 470 "data/maps/MtChimney/scripts.pory"
	end
# 471 "data/maps/MtChimney/scripts.pory"

# 472 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_MeteoriteMachine::
# 473 "data/maps/MtChimney/scripts.pory"
	lockall
# 474 "data/maps/MtChimney/scripts.pory"
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn
# 475 "data/maps/MtChimney/scripts.pory"
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff
# 476 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_RemoveTheMeteorite, MSGBOX_YESNO
# 477 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_LeaveMeteoriteAlone
# 478 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
# 479 "data/maps/MtChimney/scripts.pory"
	giveitem ITEM_METEORITE
# 480 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 481 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_RECEIVED_METEORITE
# 482 "data/maps/MtChimney/scripts.pory"
	releaseall
# 483 "data/maps/MtChimney/scripts.pory"
	end
# 484 "data/maps/MtChimney/scripts.pory"

# 485 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_LeaveMeteoriteAlone::
# 486 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
# 487 "data/maps/MtChimney/scripts.pory"
	releaseall
# 488 "data/maps/MtChimney/scripts.pory"
	end
# 489 "data/maps/MtChimney/scripts.pory"

# 490 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_MachineOff::
# 491 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
# 492 "data/maps/MtChimney/scripts.pory"
	releaseall
# 493 "data/maps/MtChimney/scripts.pory"
	end
# 494 "data/maps/MtChimney/scripts.pory"

# 495 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_MachineOn::
# 496 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MetoriteFittedOnMachine, MSGBOX_DEFAULT
# 497 "data/maps/MtChimney/scripts.pory"
	releaseall
# 498 "data/maps/MtChimney/scripts.pory"
	end
# 499 "data/maps/MtChimney/scripts.pory"

# 500 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_RouteSign::
# 501 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
# 502 "data/maps/MtChimney/scripts.pory"
	end
# 503 "data/maps/MtChimney/scripts.pory"

# 504 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Shelby::
# 505 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
# 506 "data/maps/MtChimney/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 507 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RematchShelby
# 508 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
# 509 "data/maps/MtChimney/scripts.pory"
	release
# 510 "data/maps/MtChimney/scripts.pory"
	end
# 511 "data/maps/MtChimney/scripts.pory"

# 512 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_DefeatedShelby::
# 513 "data/maps/MtChimney/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 514 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 515 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
# 516 "data/maps/MtChimney/scripts.pory"
	register_matchcall TRAINER_SHELBY_1
# 517 "data/maps/MtChimney/scripts.pory"
	release
# 518 "data/maps/MtChimney/scripts.pory"
	end
# 519 "data/maps/MtChimney/scripts.pory"

# 520 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_RematchShelby::
# 521 "data/maps/MtChimney/scripts.pory"
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
# 522 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
# 523 "data/maps/MtChimney/scripts.pory"
	end
# 524 "data/maps/MtChimney/scripts.pory"

# 525 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Melissa::
# 526 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
# 527 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
# 528 "data/maps/MtChimney/scripts.pory"
	end
# 529 "data/maps/MtChimney/scripts.pory"

# 530 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Sheila::
# 531 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
# 532 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
# 533 "data/maps/MtChimney/scripts.pory"
	end
# 534 "data/maps/MtChimney/scripts.pory"

# 535 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Shirley::
# 536 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
# 537 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
# 538 "data/maps/MtChimney/scripts.pory"
	end
# 539 "data/maps/MtChimney/scripts.pory"

# 540 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Grunt1::
# 541 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
# 542 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
# 543 "data/maps/MtChimney/scripts.pory"
	end
# 544 "data/maps/MtChimney/scripts.pory"

# 545 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Sawyer::
# 546 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
# 547 "data/maps/MtChimney/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 548 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_SawyerRematch
# 549 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
# 550 "data/maps/MtChimney/scripts.pory"
	release
# 551 "data/maps/MtChimney/scripts.pory"
	end
# 552 "data/maps/MtChimney/scripts.pory"

# 553 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_SawyerDefeated::
# 554 "data/maps/MtChimney/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 555 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 556 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
# 557 "data/maps/MtChimney/scripts.pory"
	register_matchcall TRAINER_SAWYER_1
# 558 "data/maps/MtChimney/scripts.pory"
	release
# 559 "data/maps/MtChimney/scripts.pory"
	end
# 560 "data/maps/MtChimney/scripts.pory"

# 561 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_SawyerRematch::
# 562 "data/maps/MtChimney/scripts.pory"
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
# 563 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
# 564 "data/maps/MtChimney/scripts.pory"
	end
# 565 "data/maps/MtChimney/scripts.pory"

# 566 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MeteoriteWillActivateVolcano:
# 567 "data/maps/MtChimney/scripts.pory"
	.string "The power contained in the METEORITE…\p"
# 568 "data/maps/MtChimney/scripts.pory"
	.string "By amplifying its power with this\n"
# 569 "data/maps/MtChimney/scripts.pory"
	.string "machine, MT. CHIMNEY's volcanic\l"
# 570 "data/maps/MtChimney/scripts.pory"
	.string "activity will instantly intensify…\p"
# 571 "data/maps/MtChimney/scripts.pory"
	.string "Its energy will grow deep inside\n"
# 572 "data/maps/MtChimney/scripts.pory"
	.string "the crater and…\l"
# 573 "data/maps/MtChimney/scripts.pory"
	.string "Fufufu…$"
# 574 "data/maps/MtChimney/scripts.pory"

# 575 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MaxieIntro:
# 576 "data/maps/MtChimney/scripts.pory"
	.string "MAXIE: Hm?\n"
# 577 "data/maps/MtChimney/scripts.pory"
	.string "Who are you?\p"
# 578 "data/maps/MtChimney/scripts.pory"
	.string "… … … … … …\n"
# 579 "data/maps/MtChimney/scripts.pory"
	.string "… … … … … …\p"
# 580 "data/maps/MtChimney/scripts.pory"
	.string "I'd heard ARCHIE bemoaning a child\n"
# 581 "data/maps/MtChimney/scripts.pory"
	.string "who's been meddling in TEAM AQUA's\l"
# 582 "data/maps/MtChimney/scripts.pory"
	.string "affairs.\p"
# 583 "data/maps/MtChimney/scripts.pory"
	.string "It must be you he meant.\p"
# 584 "data/maps/MtChimney/scripts.pory"
	.string "Humph! So you're thinking of\n"
# 585 "data/maps/MtChimney/scripts.pory"
	.string "interfering with us, TEAM MAGMA?\p"
# 586 "data/maps/MtChimney/scripts.pory"
	.string "Now you listen.\n"
# 587 "data/maps/MtChimney/scripts.pory"
	.string "Long ago, living things used the\l"
# 588 "data/maps/MtChimney/scripts.pory"
	.string "land to live and grow.\p"
# 589 "data/maps/MtChimney/scripts.pory"
	.string "That is why land is all important!\n"
# 590 "data/maps/MtChimney/scripts.pory"
	.string "It is the cradle of all!\p"
# 591 "data/maps/MtChimney/scripts.pory"
	.string "That is why TEAM MAGMA is dedicated\n"
# 592 "data/maps/MtChimney/scripts.pory"
	.string "to the expansion of the land mass.\p"
# 593 "data/maps/MtChimney/scripts.pory"
	.string "It is for further advancement of\n"
# 594 "data/maps/MtChimney/scripts.pory"
	.string "humankind and POKéMON!\p"
# 595 "data/maps/MtChimney/scripts.pory"
	.string "And for that, we need the power of\n"
# 596 "data/maps/MtChimney/scripts.pory"
	.string "what sleeps within this mountain…\p"
# 597 "data/maps/MtChimney/scripts.pory"
	.string "Oh! There was no need for you to\n"
# 598 "data/maps/MtChimney/scripts.pory"
	.string "learn that much.\p"
# 599 "data/maps/MtChimney/scripts.pory"
	.string "But, no matter!\n"
# 600 "data/maps/MtChimney/scripts.pory"
	.string "I'll teach you the consequences of\l"
# 601 "data/maps/MtChimney/scripts.pory"
	.string "meddling in our grand design!$"
# 602 "data/maps/MtChimney/scripts.pory"

# 603 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MaxieDefeat:
# 604 "data/maps/MtChimney/scripts.pory"
	.string "What?!\p"
# 605 "data/maps/MtChimney/scripts.pory"
	.string "I, MAXIE, was caught off guard?!$"
# 606 "data/maps/MtChimney/scripts.pory"

# 607 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MaxieYouHaventSeenLastOfMagma:
# 608 "data/maps/MtChimney/scripts.pory"
	.string "MAXIE: But, enough.\n"
# 609 "data/maps/MtChimney/scripts.pory"
	.string "I will back off this time.\p"
# 610 "data/maps/MtChimney/scripts.pory"
	.string "But don't think that this is the last\n"
# 611 "data/maps/MtChimney/scripts.pory"
	.string "you've seen of TEAM MAGMA.\p"
# 612 "data/maps/MtChimney/scripts.pory"
	.string "Fufufu…\p"
# 613 "data/maps/MtChimney/scripts.pory"
	.string "Even without the METEORITE, if we\n"
# 614 "data/maps/MtChimney/scripts.pory"
	.string "obtain that ORB… Fufufu…$"
# 615 "data/maps/MtChimney/scripts.pory"

# 616 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_TabithaIntro:
# 617 "data/maps/MtChimney/scripts.pory"
	.string "Ahahahaha!\p"
# 618 "data/maps/MtChimney/scripts.pory"
	.string "I knew you would come.\p"
# 619 "data/maps/MtChimney/scripts.pory"
	.string "Too bad, though. It's all over now\n"
# 620 "data/maps/MtChimney/scripts.pory"
	.string "I've already delivered the METEORITE\l"
# 621 "data/maps/MtChimney/scripts.pory"
	.string "from METEOR FALLS to the BOSS!$"
# 622 "data/maps/MtChimney/scripts.pory"

# 623 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_TabithaDefeat:
# 624 "data/maps/MtChimney/scripts.pory"
	.string "Ahahahaha!\p"
# 625 "data/maps/MtChimney/scripts.pory"
	.string "You're disgustingly strong!$"
# 626 "data/maps/MtChimney/scripts.pory"

# 627 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_TabithaPostBattle:
# 628 "data/maps/MtChimney/scripts.pory"
	.string "BOSS, hurry!\n"
# 629 "data/maps/MtChimney/scripts.pory"
	.string "Give it the METEORITE's energy!\p"
# 630 "data/maps/MtChimney/scripts.pory"
	.string "Ahahahaha!$"
# 631 "data/maps/MtChimney/scripts.pory"

# 632 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt2Intro:
# 633 "data/maps/MtChimney/scripts.pory"
	.string "We of TEAM MAGMA are working hard for\n"
# 634 "data/maps/MtChimney/scripts.pory"
	.string "everyone's sake.\p"
# 635 "data/maps/MtChimney/scripts.pory"
	.string "Like, if that thing's power made more\n"
# 636 "data/maps/MtChimney/scripts.pory"
	.string "land, there'd be more places to live.\p"
# 637 "data/maps/MtChimney/scripts.pory"
	.string "Everyone'd be happy!$"
# 638 "data/maps/MtChimney/scripts.pory"

# 639 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt2Defeat:
# 640 "data/maps/MtChimney/scripts.pory"
	.string "Hunh?\n"
# 641 "data/maps/MtChimney/scripts.pory"
	.string "What do you mean I lost?$"
# 642 "data/maps/MtChimney/scripts.pory"

# 643 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt2PostBattle:
# 644 "data/maps/MtChimney/scripts.pory"
	.string "Our BOSS says, “It will make everyone\n"
# 645 "data/maps/MtChimney/scripts.pory"
	.string "happy.”\p"
# 646 "data/maps/MtChimney/scripts.pory"
	.string "But why does everyone keep getting\n"
# 647 "data/maps/MtChimney/scripts.pory"
	.string "in our way?$"
# 648 "data/maps/MtChimney/scripts.pory"

# 649 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt1Intro:
# 650 "data/maps/MtChimney/scripts.pory"
	.string "If there were more land, I'd be able\n"
# 651 "data/maps/MtChimney/scripts.pory"
	.string "to get a big house of my own!\p"
# 652 "data/maps/MtChimney/scripts.pory"
	.string "I'm going to build it on hardened lava!$"
# 653 "data/maps/MtChimney/scripts.pory"

# 654 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt1Defeat:
# 655 "data/maps/MtChimney/scripts.pory"
	.string "My dream of a big house…$"
# 656 "data/maps/MtChimney/scripts.pory"

# 657 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt1PostBattle:
# 658 "data/maps/MtChimney/scripts.pory"
	.string "A kid like you, you ought to be\n"
# 659 "data/maps/MtChimney/scripts.pory"
	.string "splashing about in the waves!$"
# 660 "data/maps/MtChimney/scripts.pory"

# 661 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_TeamAquaAlwaysMessingWithPlans:
# 662 "data/maps/MtChimney/scripts.pory"
	.string "That annoying TEAM AQUA…\n"
# 663 "data/maps/MtChimney/scripts.pory"
	.string "They always mess with our plans!$"
# 664 "data/maps/MtChimney/scripts.pory"

# 665 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MeteoritesPackAmazingPower:
# 666 "data/maps/MtChimney/scripts.pory"
	.string "METEORITES pack amazing power!$"
# 667 "data/maps/MtChimney/scripts.pory"

# 668 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_YouBetterNotMessWithUs:
# 669 "data/maps/MtChimney/scripts.pory"
	.string "You'd better not mess with us!\p"
# 670 "data/maps/MtChimney/scripts.pory"
	.string "We're trying to awaken that thing\n"
# 671 "data/maps/MtChimney/scripts.pory"
	.string "for the benefit of everyone!$"
# 672 "data/maps/MtChimney/scripts.pory"

# 673 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_AquasNameSimilar:
# 674 "data/maps/MtChimney/scripts.pory"
	.string "We're TEAM MAGMA!\p"
# 675 "data/maps/MtChimney/scripts.pory"
	.string "They're TEAM AQUA!\p"
# 676 "data/maps/MtChimney/scripts.pory"
	.string "It totally annoys me that they'd\n"
# 677 "data/maps/MtChimney/scripts.pory"
	.string "use a name like ours!$"
# 678 "data/maps/MtChimney/scripts.pory"

# 679 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_DouseThemInFire:
# 680 "data/maps/MtChimney/scripts.pory"
	.string "Yeah!\n"
# 681 "data/maps/MtChimney/scripts.pory"
	.string "Douse them in fire!$"
# 682 "data/maps/MtChimney/scripts.pory"

# 683 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_KeepMakingMoreLand:
# 684 "data/maps/MtChimney/scripts.pory"
	.string "We're going to keep making more land!$"
# 685 "data/maps/MtChimney/scripts.pory"

# 686 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Bufoh:
# 687 "data/maps/MtChimney/scripts.pory"
	.string "Bufoh!$"
# 688 "data/maps/MtChimney/scripts.pory"

# 689 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ArchieGoStopTeamMagma:
# 690 "data/maps/MtChimney/scripts.pory"
	.string "ARCHIE: Grr, {PLAYER}!\n"
# 691 "data/maps/MtChimney/scripts.pory"
	.string "I should've guessed you'd show up!\p"
# 692 "data/maps/MtChimney/scripts.pory"
	.string "See for yourself what the fanatics\n"
# 693 "data/maps/MtChimney/scripts.pory"
	.string "of TEAM MAGMA are up to!\p"
# 694 "data/maps/MtChimney/scripts.pory"
	.string "They're trying to inject the stolen\n"
# 695 "data/maps/MtChimney/scripts.pory"
	.string "METEORITE's power into the volcano!\p"
# 696 "data/maps/MtChimney/scripts.pory"
	.string "Doing something like that will cause\n"
# 697 "data/maps/MtChimney/scripts.pory"
	.string "the volcano's eruption!$"
# 698 "data/maps/MtChimney/scripts.pory"

# 699 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ArchieIHaveMyHandsFull:
# 700 "data/maps/MtChimney/scripts.pory"
	.string "ARCHIE: Grrr…\p"
# 701 "data/maps/MtChimney/scripts.pory"
	.string "I want to stop that MAXIE,\n"
# 702 "data/maps/MtChimney/scripts.pory"
	.string "but I can't!\p"
# 703 "data/maps/MtChimney/scripts.pory"
	.string "Not when I have my hands full battling\n"
# 704 "data/maps/MtChimney/scripts.pory"
	.string "three opponents at once!$"
# 705 "data/maps/MtChimney/scripts.pory"

# 706 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ArchieThankYou:
# 707 "data/maps/MtChimney/scripts.pory"
	.string "ARCHIE: {PLAYER}!\n"
# 708 "data/maps/MtChimney/scripts.pory"
	.string "Thank you!\p"
# 709 "data/maps/MtChimney/scripts.pory"
	.string "With your help, we thwarted TEAM\n"
# 710 "data/maps/MtChimney/scripts.pory"
	.string "MAGMA's destructive plan!\p"
# 711 "data/maps/MtChimney/scripts.pory"
	.string "But… You…\n"
# 712 "data/maps/MtChimney/scripts.pory"
	.string "Whose side are you on?\p"
# 713 "data/maps/MtChimney/scripts.pory"
	.string "Ah, it doesn't matter.\p"
# 714 "data/maps/MtChimney/scripts.pory"
	.string "We will remain vigilant and keep up\n"
# 715 "data/maps/MtChimney/scripts.pory"
	.string "our pursuit of TEAM MAGMA.\p"
# 716 "data/maps/MtChimney/scripts.pory"
	.string "{PLAYER}, we shall meet again!$"
# 717 "data/maps/MtChimney/scripts.pory"

# 718 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MagmaOutnumbersUs:
# 719 "data/maps/MtChimney/scripts.pory"
	.string "Darn… TEAM MAGMA outnumbers us!\n"
# 720 "data/maps/MtChimney/scripts.pory"
	.string "We can't keep up with them!$"
# 721 "data/maps/MtChimney/scripts.pory"

# 722 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_LessHabitatForWaterPokemon:
# 723 "data/maps/MtChimney/scripts.pory"
	.string "If they expand the land, there'll be\n"
# 724 "data/maps/MtChimney/scripts.pory"
	.string "less habitats for WATER POKéMON!$"
# 725 "data/maps/MtChimney/scripts.pory"

# 726 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MagmasNameSimilar:
# 727 "data/maps/MtChimney/scripts.pory"
	.string "We're TEAM AQUA!\p"
# 728 "data/maps/MtChimney/scripts.pory"
	.string "They're TEAM MAGMA!\p"
# 729 "data/maps/MtChimney/scripts.pory"
	.string "It burns me up that they'd use such\n"
# 730 "data/maps/MtChimney/scripts.pory"
	.string "a confusing name!$"
# 731 "data/maps/MtChimney/scripts.pory"

# 732 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Bushaa:
# 733 "data/maps/MtChimney/scripts.pory"
	.string "Bushaa!$"
# 734 "data/maps/MtChimney/scripts.pory"

# 735 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_LavaCookiesJust200:
# 736 "data/maps/MtChimney/scripts.pory"
	.string "LAVA COOKIES are MT. CHIMNEY's local\n"
# 737 "data/maps/MtChimney/scripts.pory"
	.string "specialty.\p"
# 738 "data/maps/MtChimney/scripts.pory"
	.string "Try one. It's just ¥200.$"
# 739 "data/maps/MtChimney/scripts.pory"

# 740 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ThankYouDear:
# 741 "data/maps/MtChimney/scripts.pory"
	.string "Thank you, dear!$"
# 742 "data/maps/MtChimney/scripts.pory"

# 743 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_YouveNotGotTheMoney:
# 744 "data/maps/MtChimney/scripts.pory"
	.string "Oh, dear. You can't buy a thing if\n"
# 745 "data/maps/MtChimney/scripts.pory"
	.string "you've not got the money.$"
# 746 "data/maps/MtChimney/scripts.pory"

# 747 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_OhFineThen:
# 748 "data/maps/MtChimney/scripts.pory"
	.string "Oh, fine then.$"
# 749 "data/maps/MtChimney/scripts.pory"

# 750 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MetoriteFittedOnMachine:
# 751 "data/maps/MtChimney/scripts.pory"
	.string "A METEORITE is fitted on a mysterious\n"
# 752 "data/maps/MtChimney/scripts.pory"
	.string "machine…\p"
# 753 "data/maps/MtChimney/scripts.pory"
	.string "The machine seems to be storing\n"
# 754 "data/maps/MtChimney/scripts.pory"
	.string "energy in the METEORITE.$"
# 755 "data/maps/MtChimney/scripts.pory"

# 756 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_RemoveTheMeteorite:
# 757 "data/maps/MtChimney/scripts.pory"
	.string "A METEORITE is fitted on a mysterious\n"
# 758 "data/maps/MtChimney/scripts.pory"
	.string "machine…\p"
# 759 "data/maps/MtChimney/scripts.pory"
	.string "Do you want to remove the METEORITE?$"
# 760 "data/maps/MtChimney/scripts.pory"

# 761 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_PlayerRemovedMeteorite:
# 762 "data/maps/MtChimney/scripts.pory"
	.string "{PLAYER} removed the METEORITE from\n"
# 763 "data/maps/MtChimney/scripts.pory"
	.string "the mysterious machine.$"
# 764 "data/maps/MtChimney/scripts.pory"

# 765 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_PlayerLeftMeteorite:
# 766 "data/maps/MtChimney/scripts.pory"
	.string "{PLAYER} left the METEORITE where\n"
# 767 "data/maps/MtChimney/scripts.pory"
	.string "it was.$"
# 768 "data/maps/MtChimney/scripts.pory"

# 769 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MachineMakesNoResponse:
# 770 "data/maps/MtChimney/scripts.pory"
	.string "This mysterious machine…\n"
# 771 "data/maps/MtChimney/scripts.pory"
	.string "It makes no response whatsoever.$"
# 772 "data/maps/MtChimney/scripts.pory"

# 773 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_RouteSign:
# 774 "data/maps/MtChimney/scripts.pory"
	.string "{DOWN_ARROW} JAGGED PATH\n"
# 775 "data/maps/MtChimney/scripts.pory"
	.string "LAVARIDGE TOWN AHEAD$"
# 776 "data/maps/MtChimney/scripts.pory"

# 777 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyIntro:
# 778 "data/maps/MtChimney/scripts.pory"
	.string "I've been to the hot springs and\n"
# 779 "data/maps/MtChimney/scripts.pory"
	.string "refreshed my tired bones.\l"
# 780 "data/maps/MtChimney/scripts.pory"
	.string "Right now I'm feeling strong!$"
# 781 "data/maps/MtChimney/scripts.pory"

# 782 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyDefeat:
# 783 "data/maps/MtChimney/scripts.pory"
	.string "Oh, my goodness.\n"
# 784 "data/maps/MtChimney/scripts.pory"
	.string "Now, aren't you something!$"
# 785 "data/maps/MtChimney/scripts.pory"

# 786 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyPostBattle:
# 787 "data/maps/MtChimney/scripts.pory"
	.string "Well, well, I've lost. I can't call\n"
# 788 "data/maps/MtChimney/scripts.pory"
	.string "myself an EXPERT now, can I?$"
# 789 "data/maps/MtChimney/scripts.pory"

# 790 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyRegister:
# 791 "data/maps/MtChimney/scripts.pory"
	.string "Thank you, child. It was fun, as if\n"
# 792 "data/maps/MtChimney/scripts.pory"
	.string "I were battling my own grandchild.\p"
# 793 "data/maps/MtChimney/scripts.pory"
	.string "Please, come see me again for\n"
# 794 "data/maps/MtChimney/scripts.pory"
	.string "a rematch.$"
# 795 "data/maps/MtChimney/scripts.pory"

# 796 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyRematchIntro:
# 797 "data/maps/MtChimney/scripts.pory"
	.string "If you can mesh your heart with those\n"
# 798 "data/maps/MtChimney/scripts.pory"
	.string "of your POKéMON, why, you should be\l"
# 799 "data/maps/MtChimney/scripts.pory"
	.string "able to achieve great things.$"
# 800 "data/maps/MtChimney/scripts.pory"

# 801 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyRematchDefeat:
# 802 "data/maps/MtChimney/scripts.pory"
	.string "Oh, my goodness.\n"
# 803 "data/maps/MtChimney/scripts.pory"
	.string "Now, aren't you something!$"
# 804 "data/maps/MtChimney/scripts.pory"

# 805 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyPostRematch:
# 806 "data/maps/MtChimney/scripts.pory"
	.string "Perhaps your heart has become one\n"
# 807 "data/maps/MtChimney/scripts.pory"
	.string "with the hearts of your POKéMON.$"
# 808 "data/maps/MtChimney/scripts.pory"

# 809 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MelissaIntro:
# 810 "data/maps/MtChimney/scripts.pory"
	.string "I've got the fire in me, baby.\n"
# 811 "data/maps/MtChimney/scripts.pory"
	.string "I can't stand it! I have to battle!$"
# 812 "data/maps/MtChimney/scripts.pory"

# 813 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MelissaDefeat:
# 814 "data/maps/MtChimney/scripts.pory"
	.string "Ooh, that was a scorching-hot match!$"
# 815 "data/maps/MtChimney/scripts.pory"

# 816 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MelissaPostBattle:
# 817 "data/maps/MtChimney/scripts.pory"
	.string "The heat of MT. CHIMNEY warms\n"
# 818 "data/maps/MtChimney/scripts.pory"
	.string "me up, baby!$"
# 819 "data/maps/MtChimney/scripts.pory"

# 820 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SheilaIntro:
# 821 "data/maps/MtChimney/scripts.pory"
	.string "I've finally made it to MT. CHIMNEY.\n"
# 822 "data/maps/MtChimney/scripts.pory"
	.string "I want to make my POKéMON battle!$"
# 823 "data/maps/MtChimney/scripts.pory"

# 824 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SheilaDefeat:
# 825 "data/maps/MtChimney/scripts.pory"
	.string "The way you battle…\n"
# 826 "data/maps/MtChimney/scripts.pory"
	.string "It's like a MT. CHIMNEY eruption!$"
# 827 "data/maps/MtChimney/scripts.pory"

# 828 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SheilaPostBattle:
# 829 "data/maps/MtChimney/scripts.pory"
	.string "Like I said, I've finally made it to\n"
# 830 "data/maps/MtChimney/scripts.pory"
	.string "MT. CHIMNEY. It would be a shame if\l"
# 831 "data/maps/MtChimney/scripts.pory"
	.string "I only do a little sightseeing…\p"
# 832 "data/maps/MtChimney/scripts.pory"
	.string "I want to get in some battles and buy\n"
# 833 "data/maps/MtChimney/scripts.pory"
	.string "COOKIES as souvenirs.$"
# 834 "data/maps/MtChimney/scripts.pory"

# 835 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShirleyIntro:
# 836 "data/maps/MtChimney/scripts.pory"
	.string "Since I bathed in the hot springs,\n"
# 837 "data/maps/MtChimney/scripts.pory"
	.string "I've been feeling great!\l"
# 838 "data/maps/MtChimney/scripts.pory"
	.string "I'm sure I'm going to win!$"
# 839 "data/maps/MtChimney/scripts.pory"

# 840 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShirleyDefeat:
# 841 "data/maps/MtChimney/scripts.pory"
	.string "Yowch!\n"
# 842 "data/maps/MtChimney/scripts.pory"
	.string "I'm getting a chill out of the water.$"
# 843 "data/maps/MtChimney/scripts.pory"

# 844 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShirleyPostBattle:
# 845 "data/maps/MtChimney/scripts.pory"
	.string "I'll have to take another dip in the\n"
# 846 "data/maps/MtChimney/scripts.pory"
	.string "hot springs. Want to join me?\p"
# 847 "data/maps/MtChimney/scripts.pory"
	.string "Just joking!$"
# 848 "data/maps/MtChimney/scripts.pory"

# 849 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerIntro:
# 850 "data/maps/MtChimney/scripts.pory"
	.string "This is one fine mountain! Plenty of\n"
# 851 "data/maps/MtChimney/scripts.pory"
	.string "hot people around for company!$"
# 852 "data/maps/MtChimney/scripts.pory"

# 853 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerDefeat:
# 854 "data/maps/MtChimney/scripts.pory"
	.string "Oh, you're a real firebrand, too!$"
# 855 "data/maps/MtChimney/scripts.pory"

# 856 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerPostBattle:
# 857 "data/maps/MtChimney/scripts.pory"
	.string "I think I need a dip in LAVARIDGE\n"
# 858 "data/maps/MtChimney/scripts.pory"
	.string "HOT SPRING with the locals!$"
# 859 "data/maps/MtChimney/scripts.pory"

# 860 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerRegister:
# 861 "data/maps/MtChimney/scripts.pory"
	.string "I like little fireballs like you.\n"
# 862 "data/maps/MtChimney/scripts.pory"
	.string "Let me register you in my POKéNAV.$"
# 863 "data/maps/MtChimney/scripts.pory"

# 864 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerRematchIntro:
# 865 "data/maps/MtChimney/scripts.pory"
	.string "I'm happily surrounded by hot people\n"
# 866 "data/maps/MtChimney/scripts.pory"
	.string "around these parts. I won't lose!$"
# 867 "data/maps/MtChimney/scripts.pory"

# 868 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerRematchDefeat:
# 869 "data/maps/MtChimney/scripts.pory"
	.string "Gosh, you're still the same\n"
# 870 "data/maps/MtChimney/scripts.pory"
	.string "firebrand as before!$"
# 871 "data/maps/MtChimney/scripts.pory"

# 872 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerPostRematch:
# 873 "data/maps/MtChimney/scripts.pory"
	.string "Actually, it really is hot here.\n"
# 874 "data/maps/MtChimney/scripts.pory"
	.string "I'm overdressed for these parts.$"
