# 1 "data/maps/MagmaHideout_4F/scripts.pory"

# 2 "data/maps/MagmaHideout_4F/scripts.pory"
.set LOCALID_GROUDON, 1
# 3 "data/maps/MagmaHideout_4F/scripts.pory"
.set LOCALID_GRUNT_1, 2
# 4 "data/maps/MagmaHideout_4F/scripts.pory"
.set LOCALID_GRUNT_2, 7
# 5 "data/maps/MagmaHideout_4F/scripts.pory"
.set LOCALID_GRUNT_3, 8
# 6 "data/maps/MagmaHideout_4F/scripts.pory"
.set LOCALID_TABITHA, 3
# 7 "data/maps/MagmaHideout_4F/scripts.pory"
.set LOCALID_MAXIE, 4
# 8 "data/maps/MagmaHideout_4F/scripts.pory"
.set LOCALID_GROUDON_SLEEPING, 5
# 9 "data/maps/MagmaHideout_4F/scripts.pory"
.set LOCALID_DRILBUR, 9
# 10 "data/maps/MagmaHideout_4F/scripts.pory"
.set LOCALID_NUMEL, 10
# 11 "data/maps/MagmaHideout_4F/scripts.pory"
.set LOCALID_TABITHA_2, 11
# 12 "data/maps/MagmaHideout_4F/scripts.pory"

# 13 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_MapScripts::
# 14 "data/maps/MagmaHideout_4F/scripts.pory"
	.byte 0
# 15 "data/maps/MagmaHideout_4F/scripts.pory"

# 16 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_EventScript_Maxie::
# 17 "data/maps/MagmaHideout_4F/scripts.pory"
	lockall
# 18 "data/maps/MagmaHideout_4F/scripts.pory"
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
# 19 "data/maps/MagmaHideout_4F/scripts.pory"
	msgbox MagmaHideout_4F_Text_MaxieAwakenGroudon, MSGBOX_DEFAULT
# 20 "data/maps/MagmaHideout_4F/scripts.pory"
	closemessage
# 21 "data/maps/MagmaHideout_4F/scripts.pory"
	delay 20
# 22 "data/maps/MagmaHideout_4F/scripts.pory"
	setvar VAR_RESULT, 1
# 23 "data/maps/MagmaHideout_4F/scripts.pory"
	playse SE_M_DETECT
# 24 "data/maps/MagmaHideout_4F/scripts.pory"
	dofieldeffectsparkle 18, 42, 0
# 25 "data/maps/MagmaHideout_4F/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 26 "data/maps/MagmaHideout_4F/scripts.pory"
	setvar VAR_RESULT, 1
# 27 "data/maps/MagmaHideout_4F/scripts.pory"
	playfanfare MUS_AWAKEN_LEGEND
# 28 "data/maps/MagmaHideout_4F/scripts.pory"
	playse SE_ORB
# 29 "data/maps/MagmaHideout_4F/scripts.pory"
	special DoOrbEffect
# 30 "data/maps/MagmaHideout_4F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 31 "data/maps/MagmaHideout_4F/scripts.pory"
	waitmovement 0
# 32 "data/maps/MagmaHideout_4F/scripts.pory"
	delay 150
# 33 "data/maps/MagmaHideout_4F/scripts.pory"
	removeobject LOCALID_GROUDON_SLEEPING
# 34 "data/maps/MagmaHideout_4F/scripts.pory"
	addobject LOCALID_GROUDON
# 35 "data/maps/MagmaHideout_4F/scripts.pory"
	waitstate
# 36 "data/maps/MagmaHideout_4F/scripts.pory"
	delay 60
# 37 "data/maps/MagmaHideout_4F/scripts.pory"
	applymovement LOCALID_GROUDON, MagmaHideout_4F_Movement_GroudonApproach
# 38 "data/maps/MagmaHideout_4F/scripts.pory"
	waitmovement 0
# 39 "data/maps/MagmaHideout_4F/scripts.pory"
	special FadeOutOrbEffect
# 40 "data/maps/MagmaHideout_4F/scripts.pory"
	waitstate
# 41 "data/maps/MagmaHideout_4F/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 42 "data/maps/MagmaHideout_4F/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 43 "data/maps/MagmaHideout_4F/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 44 "data/maps/MagmaHideout_4F/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 45 "data/maps/MagmaHideout_4F/scripts.pory"
	special ShakeCamera
# 46 "data/maps/MagmaHideout_4F/scripts.pory"
	waitstate
# 47 "data/maps/MagmaHideout_4F/scripts.pory"
	applymovement LOCALID_GROUDON, MagmaHideout_4F_Movement_GroudonExit
# 48 "data/maps/MagmaHideout_4F/scripts.pory"
	waitmovement 0
# 49 "data/maps/MagmaHideout_4F/scripts.pory"
	removeobject LOCALID_GROUDON
# 50 "data/maps/MagmaHideout_4F/scripts.pory"
	delay 4
# 51 "data/maps/MagmaHideout_4F/scripts.pory"
	setvar VAR_0x8004, 2  @ vertical pan
# 52 "data/maps/MagmaHideout_4F/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 53 "data/maps/MagmaHideout_4F/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 54 "data/maps/MagmaHideout_4F/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 55 "data/maps/MagmaHideout_4F/scripts.pory"
	special ShakeCamera
# 56 "data/maps/MagmaHideout_4F/scripts.pory"
	waitstate
# 57 "data/maps/MagmaHideout_4F/scripts.pory"
	delay 30
# 58 "data/maps/MagmaHideout_4F/scripts.pory"
	applymovement LOCALID_MAXIE, MagmaHideout_4F_Movement_MaxieLookAround
# 59 "data/maps/MagmaHideout_4F/scripts.pory"
	waitmovement 0
# 60 "data/maps/MagmaHideout_4F/scripts.pory"
	msgbox MagmaHideout_4F_Text_MaxieGroudonWhatsWrong, MSGBOX_DEFAULT
# 61 "data/maps/MagmaHideout_4F/scripts.pory"
	closemessage
# 62 "data/maps/MagmaHideout_4F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 63 "data/maps/MagmaHideout_4F/scripts.pory"
	waitmovement 0
# 64 "data/maps/MagmaHideout_4F/scripts.pory"
	delay 30
# 65 "data/maps/MagmaHideout_4F/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
# 66 "data/maps/MagmaHideout_4F/scripts.pory"
	waitmovement 0
# 67 "data/maps/MagmaHideout_4F/scripts.pory"
	msgbox MagmaHideout_4F_Text_MaxieOhItWasYou, MSGBOX_DEFAULT
# 68 "data/maps/MagmaHideout_4F/scripts.pory"
	closemessage
# 69 "data/maps/MagmaHideout_4F/scripts.pory"
	playse SE_M_BATON_PASS
# 70 "data/maps/MagmaHideout_4F/scripts.pory"
	waitse
# 71 "data/maps/MagmaHideout_4F/scripts.pory"
	removeobject LOCALID_NUMEL
# 72 "data/maps/MagmaHideout_4F/scripts.pory"
	setflag FLAG_HIDE_MAXIES_NUMEL
# 73 "data/maps/MagmaHideout_4F/scripts.pory"
	call_if_unset FLAG_DEFEATED_FORTREE_GYM, MagmaHideout_4F_EventScript_Maxie_PreWinona
# 74 "data/maps/MagmaHideout_4F/scripts.pory"
	call_if_set FLAG_DEFEATED_FORTREE_GYM, MagmaHideout_4F_EventScript_Maxie_PostWinona
# 75 "data/maps/MagmaHideout_4F/scripts.pory"
	msgbox MagmaHideout_4F_Text_MaxieImGoingAfterGroudon, MSGBOX_DEFAULT
# 76 "data/maps/MagmaHideout_4F/scripts.pory"
	closemessage
# 77 "data/maps/MagmaHideout_4F/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
# 78 "data/maps/MagmaHideout_4F/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY
# 79 "data/maps/MagmaHideout_4F/scripts.pory"
	setvar VAR_SLATEPORT_CITY_STATE, 1
# 80 "data/maps/MagmaHideout_4F/scripts.pory"
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
# 81 "data/maps/MagmaHideout_4F/scripts.pory"
	setvar VAR_SLATEPORT_HARBOR_STATE, 1
# 82 "data/maps/MagmaHideout_4F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 83 "data/maps/MagmaHideout_4F/scripts.pory"
	removeobject LOCALID_MAXIE
# 84 "data/maps/MagmaHideout_4F/scripts.pory"
	removeobject LOCALID_GRUNT_1
# 85 "data/maps/MagmaHideout_4F/scripts.pory"
	removeobject LOCALID_GRUNT_2
# 86 "data/maps/MagmaHideout_4F/scripts.pory"
	removeobject LOCALID_GRUNT_3
# 87 "data/maps/MagmaHideout_4F/scripts.pory"
	removeobject LOCALID_TABITHA_2
# 88 "data/maps/MagmaHideout_4F/scripts.pory"
	setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
# 89 "data/maps/MagmaHideout_4F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 90 "data/maps/MagmaHideout_4F/scripts.pory"
	releaseall
# 91 "data/maps/MagmaHideout_4F/scripts.pory"
	end
# 92 "data/maps/MagmaHideout_4F/scripts.pory"

# 93 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Movement_GroudonApproach:
# 94 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 95 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 96 "data/maps/MagmaHideout_4F/scripts.pory"
	walk_slow_down
# 97 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 98 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 99 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 100 "data/maps/MagmaHideout_4F/scripts.pory"
	walk_slow_down
# 101 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 102 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 103 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 104 "data/maps/MagmaHideout_4F/scripts.pory"
	step_end
# 105 "data/maps/MagmaHideout_4F/scripts.pory"

# 106 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Movement_GroudonExit:
# 107 "data/maps/MagmaHideout_4F/scripts.pory"
	slide_up
# 108 "data/maps/MagmaHideout_4F/scripts.pory"
	slide_up
# 109 "data/maps/MagmaHideout_4F/scripts.pory"
	step_end
# 110 "data/maps/MagmaHideout_4F/scripts.pory"

# 111 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Movement_MaxieLookAround:
# 112 "data/maps/MagmaHideout_4F/scripts.pory"
	face_left
# 113 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 114 "data/maps/MagmaHideout_4F/scripts.pory"
	face_right
# 115 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 116 "data/maps/MagmaHideout_4F/scripts.pory"
	face_left
# 117 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 118 "data/maps/MagmaHideout_4F/scripts.pory"
	face_right
# 119 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 120 "data/maps/MagmaHideout_4F/scripts.pory"
	face_up
# 121 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 122 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 123 "data/maps/MagmaHideout_4F/scripts.pory"
	step_end
# 124 "data/maps/MagmaHideout_4F/scripts.pory"

# 125 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_EventScript_Grunt11::
# 126 "data/maps/MagmaHideout_4F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_11, MagmaHideout_4F_Text_Grunt11Intro, MagmaHideout_4F_Text_Grunt11Defeat
# 127 "data/maps/MagmaHideout_4F/scripts.pory"
	msgbox MagmaHideout_4F_Text_Grunt11PostBattle, MSGBOX_AUTOCLOSE
# 128 "data/maps/MagmaHideout_4F/scripts.pory"
	end
# 129 "data/maps/MagmaHideout_4F/scripts.pory"

# 130 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_EventScript_Grunt12::
# 131 "data/maps/MagmaHideout_4F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_12, MagmaHideout_4F_Text_Grunt12Intro, MagmaHideout_4F_Text_Grunt12Defeat
# 132 "data/maps/MagmaHideout_4F/scripts.pory"
	msgbox MagmaHideout_4F_Text_Grunt12PostBattle, MSGBOX_AUTOCLOSE
# 133 "data/maps/MagmaHideout_4F/scripts.pory"
	end
# 134 "data/maps/MagmaHideout_4F/scripts.pory"

# 135 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_EventScript_Grunt13::
# 136 "data/maps/MagmaHideout_4F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_13, MagmaHideout_4F_Text_Grunt13Intro, MagmaHideout_4F_Text_Grunt13Defeat
# 137 "data/maps/MagmaHideout_4F/scripts.pory"
	msgbox MagmaHideout_4F_Text_Grunt13PostBattle, MSGBOX_AUTOCLOSE
# 138 "data/maps/MagmaHideout_4F/scripts.pory"
	end
# 139 "data/maps/MagmaHideout_4F/scripts.pory"

# 140 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_EventScript_Tabitha::
# 141 "data/maps/MagmaHideout_4F/scripts.pory"
	trainerbattle_single TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaIntro, MagmaHideout_4F_Text_TabithaDefeat
# 142 "data/maps/MagmaHideout_4F/scripts.pory"
	msgbox MagmaHideout_4F_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
# 143 "data/maps/MagmaHideout_4F/scripts.pory"
	end
# 144 "data/maps/MagmaHideout_4F/scripts.pory"

# 145 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_Grunt11Intro:
# 146 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "I want to see GROUDON, too, but they\n"
# 147 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "won't let me see even its tail…\p"
# 148 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "It's got me feeling really frustrated.\p"
# 149 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Oh, no!\n"
# 150 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "I blabbed about GROUDON!$"
# 151 "data/maps/MagmaHideout_4F/scripts.pory"

# 152 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_Grunt11Defeat:
# 153 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "I guess it's impossible to win if one\n"
# 154 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "doesn't have a calm mind…$"
# 155 "data/maps/MagmaHideout_4F/scripts.pory"

# 156 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_Grunt11PostBattle:
# 157 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "I wonder if GROUDON even has a tail?$"
# 158 "data/maps/MagmaHideout_4F/scripts.pory"

# 159 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_Grunt12Intro:
# 160 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Fuhahaha!\n"
# 161 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Soon! Very soon!\l"
# 162 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Our grand objective will be achieved!$"
# 163 "data/maps/MagmaHideout_4F/scripts.pory"

# 164 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_Grunt12Defeat:
# 165 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Grrr…\n"
# 166 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "I've come so far, but now this?$"
# 167 "data/maps/MagmaHideout_4F/scripts.pory"

# 168 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_Grunt12PostBattle:
# 169 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "MAXIE, sir!\n"
# 170 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "An intruder is headed your way!$"
# 171 "data/maps/MagmaHideout_4F/scripts.pory"

# 172 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_Grunt13Intro:
# 173 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "You're not finished yet!\n"
# 174 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "You're not getting by me easily!$"
# 175 "data/maps/MagmaHideout_4F/scripts.pory"

# 176 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_Grunt13Defeat:
# 177 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Was I that easy to knock down?$"
# 178 "data/maps/MagmaHideout_4F/scripts.pory"

# 179 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_Grunt13PostBattle:
# 180 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "C-come on, one more match…$"
# 181 "data/maps/MagmaHideout_4F/scripts.pory"

# 182 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_TabithaIntro:
# 183 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Hehehe!\n"
# 184 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "You made it this far, so I'll tell you!\p"
# 185 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "That's right!\n"
# 186 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Up ahead, GROUDON is sleeping!\p"
# 187 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "MAXIE went to GROUDON just seconds\n"
# 188 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "ago!\p"
# 189 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "It's going to awaken real soon!\n"
# 190 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Hehe! Hehehe!$"
# 191 "data/maps/MagmaHideout_4F/scripts.pory"

# 192 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_TabithaDefeat:
# 193 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Taken down again…\n"
# 194 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Hehe…$"
# 195 "data/maps/MagmaHideout_4F/scripts.pory"

# 196 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_TabithaPostBattle:
# 197 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "…And while you wasted time with me,\n"
# 198 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "MAXIE should have awakened GROUDON…$"
# 199 "data/maps/MagmaHideout_4F/scripts.pory"

# 200 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_MaxieAwakenGroudon:
# 201 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "MAXIE: GROUDON…\p"
# 202 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Nothing could awaken you from your\n"
# 203 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "sleep bathed in magma…\p"
# 204 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "This BLUE ORB is what you sought.\n"
# 205 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Wasn't it?\p"
# 206 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "I have brought you the BLUE ORB.\n"
# 207 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Let its shine awaken you!\p"
# 208 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "And show me…\n"
# 209 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Show me the full extent of your power!$"
# 210 "data/maps/MagmaHideout_4F/scripts.pory"

# 211 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_MaxieGroudonWhatsWrong:
# 212 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "MAXIE: GROUDON!\n"
# 213 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "What's wrong?\p"
# 214 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Wasn't the BLUE ORB the key?\p"
# 215 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "GROUDON!\n"
# 216 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Where have you gone…$"
# 217 "data/maps/MagmaHideout_4F/scripts.pory"

# 218 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_MaxieOhItWasYou:
# 219 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "MAXIE: Oh, so it was you?\p"
# 220 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "I've seen you poking around uninvited\n"
# 221 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "here and there…\p"
# 222 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "I get it now!\n"
# 223 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "You must have pulled a cheap stunt!$"
# 224 "data/maps/MagmaHideout_4F/scripts.pory"

# 225 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_MaxieDefeat:
# 226 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "What makes you so adept at handling\n"
# 227 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "POKéMON?$"
# 228 "data/maps/MagmaHideout_4F/scripts.pory"

# 229 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_MaxieImGoingAfterGroudon:
# 230 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "MAXIE: There has to be some reason\n"
# 231 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "why GROUDON fled…\p"
# 232 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "That's what you're trying to say,\n"
# 233 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "aren't you?\p"
# 234 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "… … … … … …\n"
# 235 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "… … … … … …\p"
# 236 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Humph…\n"
# 237 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "You think I didn't know that?\p"
# 238 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "With GROUDON gone, there is no longer\n"
# 239 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "any need for this blasted volcano.\p"
# 240 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "I am going after GROUDON, so this\n"
# 241 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "is where we part!$"

Tabitha::
# 245 "data/maps/MagmaHideout_4F/scripts.pory"
	playse SE_M_BATON_PASS
# 246 "data/maps/MagmaHideout_4F/scripts.pory"
	waitse
# 247 "data/maps/MagmaHideout_4F/scripts.pory"
	removeobject LOCALID_DRILBUR
# 248 "data/maps/MagmaHideout_4F/scripts.pory"
	setflag FLAG_HIDE_TABITHAS_DRILBUR
# 249 "data/maps/MagmaHideout_4F/scripts.pory"
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, Tabitha_2
# 254 "data/maps/MagmaHideout_4F/scripts.pory"
	trainerbattle_single TRAINER_WINONA_2, MagmaHideout_4F_Text_TabithaIntro, MagmaHideout_4F_Text_TabithaDefeat
# 255 "data/maps/MagmaHideout_4F/scripts.pory"
	msgbox MagmaHideout_4F_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
Tabitha_1:
# 257 "data/maps/MagmaHideout_4F/scripts.pory"
	setflag FLAG_HIDE_TABITHA
# 258 "data/maps/MagmaHideout_4F/scripts.pory"
	removeobject LOCALID_TABITHA
	return

Tabitha_2:
# 250 "data/maps/MagmaHideout_4F/scripts.pory"
	trainerbattle_single TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaIntro, MagmaHideout_4F_Text_TabithaDefeat
# 251 "data/maps/MagmaHideout_4F/scripts.pory"
	msgbox MagmaHideout_4F_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	goto Tabitha_1


MagmaHideout_4F_EventScript_Maxie_PreWinona::
# 262 "data/maps/MagmaHideout_4F/scripts.pory"
	trainerbattle_no_intro TRAINER_WINONA_3, MagmaHideout_4F_Text_MaxieDefeat
	return


MagmaHideout_4F_EventScript_Maxie_PostWinona::
# 267 "data/maps/MagmaHideout_4F/scripts.pory"
	trainerbattle_no_intro TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat
	return


TabithaPostBattle::
# 272 "data/maps/MagmaHideout_4F/scripts.pory"
	faceplayer
# 273 "data/maps/MagmaHideout_4F/scripts.pory"
	msgbox MagmaHideout_4F_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	return

