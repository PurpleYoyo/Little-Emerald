# 1 "data/maps/JaggedPass/scripts.pory"

# 2 "data/maps/JaggedPass/scripts.pory"
.set LOCALID_HIDEOUT_GUARD, 5
# 3 "data/maps/JaggedPass/scripts.pory"
.set LOCALID_AUTUMN, 6
# 4 "data/maps/JaggedPass/scripts.pory"
.set LOCALID_ETHAN, 2
# 5 "data/maps/JaggedPass/scripts.pory"

# 6 "data/maps/JaggedPass/scripts.pory"
JaggedPass_MapScripts::
# 7 "data/maps/JaggedPass/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, JaggedPass_OnResume
# 8 "data/maps/JaggedPass/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, JaggedPass_OnTransition
# 9 "data/maps/JaggedPass/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, JaggedPass_OnLoad
# 10 "data/maps/JaggedPass/scripts.pory"
	.byte 0
# 11 "data/maps/JaggedPass/scripts.pory"

# 12 "data/maps/JaggedPass/scripts.pory"
JaggedPass_OnResume:
# 13 "data/maps/JaggedPass/scripts.pory"
	setstepcallback STEP_CB_ASH
# 14 "data/maps/JaggedPass/scripts.pory"
	call_if_eq VAR_JAGGED_PASS_STATE, 0, JaggedPass_EventScript_CheckHasMagmaEmblem
# 15 "data/maps/JaggedPass/scripts.pory"
	end
# 16 "data/maps/JaggedPass/scripts.pory"

# 17 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_CheckHasMagmaEmblem::
# 18 "data/maps/JaggedPass/scripts.pory"
	checkitem ITEM_MAGMA_EMBLEM
# 19 "data/maps/JaggedPass/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_SetReadyToOpenHideout
# 20 "data/maps/JaggedPass/scripts.pory"
	return
# 21 "data/maps/JaggedPass/scripts.pory"

# 22 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_SetReadyToOpenHideout::
# 23 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_JAGGED_PASS_STATE, 1
# 24 "data/maps/JaggedPass/scripts.pory"
	return
# 25 "data/maps/JaggedPass/scripts.pory"

# 26 "data/maps/JaggedPass/scripts.pory"
JaggedPass_OnTransition:
# 27 "data/maps/JaggedPass/scripts.pory"
	call_if_eq VAR_JAGGED_PASS_ASH_WEATHER, 1, JaggedPass_EventScript_SetWeatherAsh
# 28 "data/maps/JaggedPass/scripts.pory"
	end
# 29 "data/maps/JaggedPass/scripts.pory"

# 30 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_SetWeatherAsh::
# 31 "data/maps/JaggedPass/scripts.pory"
	setweather WEATHER_VOLCANIC_ASH
# 32 "data/maps/JaggedPass/scripts.pory"
	doweather
# 33 "data/maps/JaggedPass/scripts.pory"
	return
# 34 "data/maps/JaggedPass/scripts.pory"

# 35 "data/maps/JaggedPass/scripts.pory"
JaggedPass_OnLoad:
# 36 "data/maps/JaggedPass/scripts.pory"
	goto_if_le VAR_JAGGED_PASS_STATE, 1, JaggedPass_EventScript_ConcealHideoutEntrance
# 37 "data/maps/JaggedPass/scripts.pory"
	end
# 38 "data/maps/JaggedPass/scripts.pory"

# 39 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_ConcealHideoutEntrance::
# 40 "data/maps/JaggedPass/scripts.pory"
	setmetatile 16, 17, METATILE_Lavaridge_RockWall, TRUE
# 41 "data/maps/JaggedPass/scripts.pory"
	setmetatile 16, 18, METATILE_Lavaridge_RockWall, TRUE
# 42 "data/maps/JaggedPass/scripts.pory"
	end
# 43 "data/maps/JaggedPass/scripts.pory"

# 44 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_OpenMagmaHideout::
# 45 "data/maps/JaggedPass/scripts.pory"
	lockall
# 46 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 47 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 48 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 49 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 50 "data/maps/JaggedPass/scripts.pory"
	special ShakeCamera
# 51 "data/maps/JaggedPass/scripts.pory"
	waitstate
# 52 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_BoulderShakingInResponseToEmblem, MSGBOX_DEFAULT
# 53 "data/maps/JaggedPass/scripts.pory"
	closemessage
# 54 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8004, 1   @ vertical pan
# 55 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8005, 1   @ horizontal pan
# 56 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8006, 16  @ num shakes
# 57 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8007, 3   @ shake delay
# 58 "data/maps/JaggedPass/scripts.pory"
	special ShakeCamera
# 59 "data/maps/JaggedPass/scripts.pory"
	waitstate
# 60 "data/maps/JaggedPass/scripts.pory"
	playse SE_EFFECTIVE
# 61 "data/maps/JaggedPass/scripts.pory"
	setmetatile 16, 17, METATILE_Lavaridge_CaveEntrance_Top, TRUE
# 62 "data/maps/JaggedPass/scripts.pory"
	setmetatile 16, 18, METATILE_Lavaridge_CaveEntrance_Bottom, FALSE
# 63 "data/maps/JaggedPass/scripts.pory"
	special DrawWholeMapView
# 64 "data/maps/JaggedPass/scripts.pory"
	delay 30
# 65 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_JAGGED_PASS_STATE, 2
# 66 "data/maps/JaggedPass/scripts.pory"
	waitse
# 67 "data/maps/JaggedPass/scripts.pory"
	releaseall
# 68 "data/maps/JaggedPass/scripts.pory"
	end
# 69 "data/maps/JaggedPass/scripts.pory"

# 70 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_MagmaHideoutGuard::
# 71 "data/maps/JaggedPass/scripts.pory"
	lockall
# 72 "data/maps/JaggedPass/scripts.pory"
	goto_if_set FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS, JaggedPass_EventScript_GuardDefeated
# 73 "data/maps/JaggedPass/scripts.pory"
	waitse
# 74 "data/maps/JaggedPass/scripts.pory"
	playse SE_PIN
# 75 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_ExclamationMark
# 76 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 77 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_Delay48
# 78 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 79 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FacePlayer
# 80 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 81 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_GruntIntro, MSGBOX_DEFAULT
# 82 "data/maps/JaggedPass/scripts.pory"
	closemessage
# 83 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_JAGGED_PASS, JaggedPass_Text_GruntDefeat
# 84 "data/maps/JaggedPass/scripts.pory"
	setflag FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
# 85 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
# 86 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 87 "data/maps/JaggedPass/scripts.pory"
	releaseall
# 88 "data/maps/JaggedPass/scripts.pory"
	end
# 89 "data/maps/JaggedPass/scripts.pory"

# 90 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_GuardDefeated::
# 91 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FacePlayer
# 92 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 93 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_GoWhereverYouWant, MSGBOX_DEFAULT
# 94 "data/maps/JaggedPass/scripts.pory"
	closemessage
# 95 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
# 96 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 97 "data/maps/JaggedPass/scripts.pory"
	releaseall
# 98 "data/maps/JaggedPass/scripts.pory"
	end
# 99 "data/maps/JaggedPass/scripts.pory"

# 100 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Eric::
# 101 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_single TRAINER_ERIC, JaggedPass_Text_EricIntro, JaggedPass_Text_EricDefeat
# 102 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
# 103 "data/maps/JaggedPass/scripts.pory"
	end
# 104 "data/maps/JaggedPass/scripts.pory"

# 105 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Diana::
# 106 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_single TRAINER_DIANA_1, JaggedPass_Text_DianaIntro, JaggedPass_Text_DianaDefeat, JaggedPass_EventScript_RegisterDiana
# 107 "data/maps/JaggedPass/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 108 "data/maps/JaggedPass/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_DianaRematch
# 109 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_DEFAULT
# 110 "data/maps/JaggedPass/scripts.pory"
	release
# 111 "data/maps/JaggedPass/scripts.pory"
	end
# 112 "data/maps/JaggedPass/scripts.pory"

# 113 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_RegisterDiana::
# 114 "data/maps/JaggedPass/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 115 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_DianaRegister, MSGBOX_DEFAULT
# 116 "data/maps/JaggedPass/scripts.pory"
	register_matchcall TRAINER_DIANA_1
# 117 "data/maps/JaggedPass/scripts.pory"
	release
# 118 "data/maps/JaggedPass/scripts.pory"
	end
# 119 "data/maps/JaggedPass/scripts.pory"

# 120 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_DianaRematch::
# 121 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_rematch TRAINER_DIANA_1, JaggedPass_Text_DianaRematchIntro, JaggedPass_Text_DianaRematchDefeat
# 122 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_DianaPostRematch, MSGBOX_AUTOCLOSE
# 123 "data/maps/JaggedPass/scripts.pory"
	end
# 124 "data/maps/JaggedPass/scripts.pory"

# 125 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Ethan::
# 126 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_single TRAINER_ETHAN_1, JaggedPass_Text_EthanIntro, JaggedPass_Text_EthanDefeat, JaggedPass_EventScript_RegisterEthan
# 127 "data/maps/JaggedPass/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 128 "data/maps/JaggedPass/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_EthanRematch
# 129 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_EthanPostBattle, MSGBOX_DEFAULT
# 130 "data/maps/JaggedPass/scripts.pory"
	release
# 131 "data/maps/JaggedPass/scripts.pory"
	end
# 132 "data/maps/JaggedPass/scripts.pory"

# 133 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_RegisterEthan::
# 134 "data/maps/JaggedPass/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 135 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_EthanRegister, MSGBOX_DEFAULT
# 136 "data/maps/JaggedPass/scripts.pory"
	register_matchcall TRAINER_ETHAN_1
# 137 "data/maps/JaggedPass/scripts.pory"
	release
# 138 "data/maps/JaggedPass/scripts.pory"
	end
# 139 "data/maps/JaggedPass/scripts.pory"

# 140 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_EthanRematch::
# 141 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_rematch TRAINER_ETHAN_1, JaggedPass_Text_EthanRematchIntro, JaggedPass_Text_EthanRematchDefeat
# 142 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_EthanPostRematch, MSGBOX_AUTOCLOSE
# 143 "data/maps/JaggedPass/scripts.pory"
	end
# 144 "data/maps/JaggedPass/scripts.pory"

# 145 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Julio::
# 146 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_single TRAINER_JULIO, JaggedPass_Text_JulioIntro, JaggedPass_Text_JulioDefeat
# 147 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
# 148 "data/maps/JaggedPass/scripts.pory"
	end
# 149 "data/maps/JaggedPass/scripts.pory"

# 150 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Autumn::
# 151 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_single TRAINER_AUTUMN, JaggedPass_Text_AutumnIntro, JaggedPass_Text_AutumnDefeat
# 152 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
# 153 "data/maps/JaggedPass/scripts.pory"
	end
# 154 "data/maps/JaggedPass/scripts.pory"

# 155 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EricIntro:
# 156 "data/maps/JaggedPass/scripts.pory"
	.string "MT. CHIMNEY's JAGGED PASS…\p"
# 157 "data/maps/JaggedPass/scripts.pory"
	.string "Now this is what I've always wanted\n"
# 158 "data/maps/JaggedPass/scripts.pory"
	.string "in a mountain.\p"
# 159 "data/maps/JaggedPass/scripts.pory"
	.string "This jagged bumpiness…\n"
# 160 "data/maps/JaggedPass/scripts.pory"
	.string "It rocks my soul!$"
# 161 "data/maps/JaggedPass/scripts.pory"

# 162 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EricDefeat:
# 163 "data/maps/JaggedPass/scripts.pory"
	.string "Losing left me bitter!$"
# 164 "data/maps/JaggedPass/scripts.pory"

# 165 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EricPostBattle:
# 166 "data/maps/JaggedPass/scripts.pory"
	.string "Yes, I did lose at POKéMON…\p"
# 167 "data/maps/JaggedPass/scripts.pory"
	.string "But, when it comes to the love of\n"
# 168 "data/maps/JaggedPass/scripts.pory"
	.string "the mountains, I have you beat!$"
# 169 "data/maps/JaggedPass/scripts.pory"

# 170 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaIntro:
# 171 "data/maps/JaggedPass/scripts.pory"
	.string "This place isn't your casual hike.\n"
# 172 "data/maps/JaggedPass/scripts.pory"
	.string "It's not suited for a picnic.$"
# 173 "data/maps/JaggedPass/scripts.pory"

# 174 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaDefeat:
# 175 "data/maps/JaggedPass/scripts.pory"
	.string "Ohhh, no!\n"
# 176 "data/maps/JaggedPass/scripts.pory"
	.string "The ground is too bumpy…$"
# 177 "data/maps/JaggedPass/scripts.pory"

# 178 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaPostBattle:
# 179 "data/maps/JaggedPass/scripts.pory"
	.string "Did you know?\p"
# 180 "data/maps/JaggedPass/scripts.pory"
	.string "Some people cleverly ride their\n"
# 181 "data/maps/JaggedPass/scripts.pory"
	.string "bicycles up this horribly bumpy pass.$"
# 182 "data/maps/JaggedPass/scripts.pory"

# 183 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaRegister:
# 184 "data/maps/JaggedPass/scripts.pory"
	.string "Will you ever be back in this area?\n"
# 185 "data/maps/JaggedPass/scripts.pory"
	.string "If you do return, I'd like a rematch.$"
# 186 "data/maps/JaggedPass/scripts.pory"

# 187 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaRematchIntro:
# 188 "data/maps/JaggedPass/scripts.pory"
	.string "Picnics are fun wherever you go.\n"
# 189 "data/maps/JaggedPass/scripts.pory"
	.string "Just like POKéMON!$"
# 190 "data/maps/JaggedPass/scripts.pory"

# 191 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaRematchDefeat:
# 192 "data/maps/JaggedPass/scripts.pory"
	.string "I only lost because the ground is\n"
# 193 "data/maps/JaggedPass/scripts.pory"
	.string "too bumpy!$"
# 194 "data/maps/JaggedPass/scripts.pory"

# 195 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaPostRematch:
# 196 "data/maps/JaggedPass/scripts.pory"
	.string "I'll forget about losing and just\n"
# 197 "data/maps/JaggedPass/scripts.pory"
	.string "enjoy this bumpy hike.$"
# 198 "data/maps/JaggedPass/scripts.pory"

# 199 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanIntro:
# 200 "data/maps/JaggedPass/scripts.pory"
	.string "JAGGED PASS is hard to walk on.\n"
# 201 "data/maps/JaggedPass/scripts.pory"
	.string "It's a good place for training.$"
# 202 "data/maps/JaggedPass/scripts.pory"

# 203 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanDefeat:
# 204 "data/maps/JaggedPass/scripts.pory"
	.string "It was all over while we were still\n"
# 205 "data/maps/JaggedPass/scripts.pory"
	.string "trying to find a good footing…$"
# 206 "data/maps/JaggedPass/scripts.pory"

# 207 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanPostBattle:
# 208 "data/maps/JaggedPass/scripts.pory"
	.string "If I had an ACRO BIKE, I'd be able to\n"
# 209 "data/maps/JaggedPass/scripts.pory"
	.string "jump ledges.$"
# 210 "data/maps/JaggedPass/scripts.pory"

# 211 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanRegister:
# 212 "data/maps/JaggedPass/scripts.pory"
	.string "When I get more used to this bumpiness,\n"
# 213 "data/maps/JaggedPass/scripts.pory"
	.string "I'll be sure to win!\p"
# 214 "data/maps/JaggedPass/scripts.pory"
	.string "Can you register me in your POKéNAV?$"
# 215 "data/maps/JaggedPass/scripts.pory"

# 216 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanRematchIntro:
# 217 "data/maps/JaggedPass/scripts.pory"
	.string "I got used to this bumpiness.\n"
# 218 "data/maps/JaggedPass/scripts.pory"
	.string "I sing while I climb now.$"
# 219 "data/maps/JaggedPass/scripts.pory"

# 220 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanRematchDefeat:
# 221 "data/maps/JaggedPass/scripts.pory"
	.string "It's still not easy to battle on this\n"
# 222 "data/maps/JaggedPass/scripts.pory"
	.string "bumpy ground…$"
# 223 "data/maps/JaggedPass/scripts.pory"

# 224 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanPostRematch:
# 225 "data/maps/JaggedPass/scripts.pory"
	.string "I should get an ACRO BIKE from RYDEL\n"
# 226 "data/maps/JaggedPass/scripts.pory"
	.string "in MAUVILLE CITY…$"
# 227 "data/maps/JaggedPass/scripts.pory"

# 228 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_GruntIntro:
# 229 "data/maps/JaggedPass/scripts.pory"
	.string "Wah!\n"
# 230 "data/maps/JaggedPass/scripts.pory"
	.string "What are you doing here?\p"
# 231 "data/maps/JaggedPass/scripts.pory"
	.string "What am I doing in a place like this?\p"
# 232 "data/maps/JaggedPass/scripts.pory"
	.string "What business is it of yours?$"
# 233 "data/maps/JaggedPass/scripts.pory"

# 234 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_GruntDefeat:
# 235 "data/maps/JaggedPass/scripts.pory"
	.string "Urrrgh…\p"
# 236 "data/maps/JaggedPass/scripts.pory"
	.string "I should've ducked into our HIDEOUT\n"
# 237 "data/maps/JaggedPass/scripts.pory"
	.string "right away…$"
# 238 "data/maps/JaggedPass/scripts.pory"

# 239 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_GoWhereverYouWant:
# 240 "data/maps/JaggedPass/scripts.pory"
	.string "Okay, oh-kay!\n"
# 241 "data/maps/JaggedPass/scripts.pory"
	.string "I admit it--you're strong!\p"
# 242 "data/maps/JaggedPass/scripts.pory"
	.string "Don't worry about me.\n"
# 243 "data/maps/JaggedPass/scripts.pory"
	.string "Go wherever you want!$"
# 244 "data/maps/JaggedPass/scripts.pory"

# 245 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_BoulderShakingInResponseToEmblem:
# 246 "data/maps/JaggedPass/scripts.pory"
	.string "Oh! This boulder is shaking in response\n"
# 247 "data/maps/JaggedPass/scripts.pory"
	.string "to the MAGMA EMBLEM!$"
# 248 "data/maps/JaggedPass/scripts.pory"

# 249 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_JulioIntro:
# 250 "data/maps/JaggedPass/scripts.pory"
	.string "Aiyeeh! It's awfully scary to shoot\n"
# 251 "data/maps/JaggedPass/scripts.pory"
	.string "down the mountain in one go!$"
# 252 "data/maps/JaggedPass/scripts.pory"

# 253 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_JulioDefeat:
# 254 "data/maps/JaggedPass/scripts.pory"
	.string "I feel like I'm falling apart…$"
# 255 "data/maps/JaggedPass/scripts.pory"

# 256 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_JulioPostBattle:
# 257 "data/maps/JaggedPass/scripts.pory"
	.string "My bicycle bounced around so much,\n"
# 258 "data/maps/JaggedPass/scripts.pory"
	.string "my rear end's sore…$"
# 259 "data/maps/JaggedPass/scripts.pory"

# 260 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_AutumnIntro:
# 261 "data/maps/JaggedPass/scripts.pory"
	.string "I climb this hill every day.\n"
# 262 "data/maps/JaggedPass/scripts.pory"
	.string "I have confidence in my strength!$"
# 263 "data/maps/JaggedPass/scripts.pory"

# 264 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_AutumnDefeat:
# 265 "data/maps/JaggedPass/scripts.pory"
	.string "Hmm…\n"
# 266 "data/maps/JaggedPass/scripts.pory"
	.string "What went wrong?$"
# 267 "data/maps/JaggedPass/scripts.pory"

# 268 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_AutumnPostBattle:
# 269 "data/maps/JaggedPass/scripts.pory"
	.string "What is that odd rock protrusion\n"
# 270 "data/maps/JaggedPass/scripts.pory"
	.string "a little up the hill from here?$"

JaggedPass_B2B_Right::
# 275 "data/maps/JaggedPass/scripts.pory"
	lockall
# 276 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_ETHAN, Common_Movement_ExclamationMark
# 277 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 278 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_ETHAN, Common_Movement_Delay48
# 279 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 280 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_no_intro TRAINER_ETHAN_1, JaggedPass_Text_EthanDefeat
# 281 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_AUTUMN, Common_Movement_ExclamationMark
# 282 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 283 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_AUTUMN, Common_Movement_Delay48
# 284 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 285 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_AUTUMN, Movement_RightOne
# 286 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 287 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_no_intro TRAINER_AUTUMN, JaggedPass_Text_AutumnDefeat
# 288 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_JAGGED_PASS_B2B, 1
# 289 "data/maps/JaggedPass/scripts.pory"
	releaseall
	return


JaggedPass_B2B_Left::
# 293 "data/maps/JaggedPass/scripts.pory"
	lockall
# 294 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_ETHAN, Common_Movement_ExclamationMark
# 295 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 296 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_ETHAN, Common_Movement_Delay48
# 297 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 298 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_ETHAN, Movement_LeftOne
# 299 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 300 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_no_intro TRAINER_ETHAN_1, JaggedPass_Text_EthanDefeat
# 301 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_AUTUMN, Common_Movement_ExclamationMark
# 302 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 303 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_AUTUMN, Common_Movement_Delay48
# 304 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 305 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_no_intro TRAINER_AUTUMN, JaggedPass_Text_AutumnDefeat
# 306 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_JAGGED_PASS_B2B, 1
# 307 "data/maps/JaggedPass/scripts.pory"
	releaseall
	return

