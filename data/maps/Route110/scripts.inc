# 1 "data/maps/Route110/scripts.pory"

# 2 "data/maps/Route110/scripts.pory"
.set LOCALID_CHALLENGE_BIKER, 21
# 3 "data/maps/Route110/scripts.pory"
.set LOCALID_RIVAL, 28
# 4 "data/maps/Route110/scripts.pory"
.set LOCALID_RIVAL_ON_BIKE, 29
# 5 "data/maps/Route110/scripts.pory"
.set LOCALID_BIRCH, 36
# 6 "data/maps/Route110/scripts.pory"
.set LOCALID_ANORITH, 37
# 7 "data/maps/Route110/scripts.pory"
.set LOCALID_AMAURA, 38
# 8 "data/maps/Route110/scripts.pory"

# 9 "data/maps/Route110/scripts.pory"
Route110_MapScripts::
# 10 "data/maps/Route110/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Route110_OnResume
# 11 "data/maps/Route110/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_OnTransition
# 12 "data/maps/Route110/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_OnFrame
# 13 "data/maps/Route110/scripts.pory"
	.byte 0
# 14 "data/maps/Route110/scripts.pory"

# 15 "data/maps/Route110/scripts.pory"
Route110_OnResume:
# 16 "data/maps/Route110/scripts.pory"
	special UpdateCyclingRoadState
# 17 "data/maps/Route110/scripts.pory"
	end
# 18 "data/maps/Route110/scripts.pory"

# 19 "data/maps/Route110/scripts.pory"
Route110_OnTransition:
# 20 "data/maps/Route110/scripts.pory"
	checkplayergender
# 21 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_RESULT, MALE, RemoveAnorith
# 22 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, RemoveAmaura
# 23 "data/maps/Route110/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 24 "data/maps/Route110/scripts.pory"
	call Common_EventScript_SetupRivalOnBikeGfxId
# 25 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_CYCLING_CHALLENGE_STATE, 1, Route110_EventScript_SaveCyclingMusic
# 26 "data/maps/Route110/scripts.pory"
	end
# 27 "data/maps/Route110/scripts.pory"

# 28 "data/maps/Route110/scripts.pory"
RemoveAmaura::
# 29 "data/maps/Route110/scripts.pory"
	removeobject LOCALID_AMAURA
# 30 "data/maps/Route110/scripts.pory"
	setflag FLAG_HIDE_RIVALS_AMAURA
# 31 "data/maps/Route110/scripts.pory"
	return
# 32 "data/maps/Route110/scripts.pory"

# 33 "data/maps/Route110/scripts.pory"
RemoveAnorith::
# 34 "data/maps/Route110/scripts.pory"
	removeobject LOCALID_ANORITH
# 35 "data/maps/Route110/scripts.pory"
	setflag FLAG_HIDE_RIVALS_ANORITH
# 36 "data/maps/Route110/scripts.pory"
	return
# 37 "data/maps/Route110/scripts.pory"

# 38 "data/maps/Route110/scripts.pory"
Route110_EventScript_SaveCyclingMusic::
# 39 "data/maps/Route110/scripts.pory"
	savebgm MUS_CYCLING
# 40 "data/maps/Route110/scripts.pory"
	return
# 41 "data/maps/Route110/scripts.pory"

# 42 "data/maps/Route110/scripts.pory"
Route110_OnFrame:
# 43 "data/maps/Route110/scripts.pory"
	map_script_2 VAR_CYCLING_CHALLENGE_STATE, 1, Route110_EventScript_BeginCylcingRoadChallenge
# 44 "data/maps/Route110/scripts.pory"
	.2byte 0
# 45 "data/maps/Route110/scripts.pory"

# 46 "data/maps/Route110/scripts.pory"
Route110_EventScript_BeginCylcingRoadChallenge::
# 47 "data/maps/Route110/scripts.pory"
	special Special_BeginCyclingRoadChallenge
# 48 "data/maps/Route110/scripts.pory"
	setvar VAR_CYCLING_CHALLENGE_STATE, 2
# 49 "data/maps/Route110/scripts.pory"
	return
# 50 "data/maps/Route110/scripts.pory"

# 51 "data/maps/Route110/scripts.pory"
Route110_EventScript_AquaGrunt1::
# 52 "data/maps/Route110/scripts.pory"
	lock
# 53 "data/maps/Route110/scripts.pory"
	faceplayer
# 54 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_WeCantTalkAboutAquaActivities, MSGBOX_DEFAULT
# 55 "data/maps/Route110/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 56 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 57 "data/maps/Route110/scripts.pory"
	release
# 58 "data/maps/Route110/scripts.pory"
	end
# 59 "data/maps/Route110/scripts.pory"

# 60 "data/maps/Route110/scripts.pory"
Route110_EventScript_AquaGrunt2::
# 61 "data/maps/Route110/scripts.pory"
	lock
# 62 "data/maps/Route110/scripts.pory"
	faceplayer
# 63 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_KickUpARuckus, MSGBOX_DEFAULT
# 64 "data/maps/Route110/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 65 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 66 "data/maps/Route110/scripts.pory"
	release
# 67 "data/maps/Route110/scripts.pory"
	end
# 68 "data/maps/Route110/scripts.pory"

# 69 "data/maps/Route110/scripts.pory"
Route110_EventScript_AquaGrunt3::
# 70 "data/maps/Route110/scripts.pory"
	lock
# 71 "data/maps/Route110/scripts.pory"
	faceplayer
# 72 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_MyFirstJobInAqua, MSGBOX_DEFAULT
# 73 "data/maps/Route110/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 74 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 75 "data/maps/Route110/scripts.pory"
	release
# 76 "data/maps/Route110/scripts.pory"
	end
# 77 "data/maps/Route110/scripts.pory"

# 78 "data/maps/Route110/scripts.pory"
Route110_EventScript_AquaGrunt4::
# 79 "data/maps/Route110/scripts.pory"
	lock
# 80 "data/maps/Route110/scripts.pory"
	faceplayer
# 81 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_AquaActionsBringSmiles, MSGBOX_DEFAULT
# 82 "data/maps/Route110/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 83 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 84 "data/maps/Route110/scripts.pory"
	release
# 85 "data/maps/Route110/scripts.pory"
	end
# 86 "data/maps/Route110/scripts.pory"

# 87 "data/maps/Route110/scripts.pory"
Route110_EventScript_Boy1::
# 88 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_RideBikeAtFullSpeed, MSGBOX_NPC
# 89 "data/maps/Route110/scripts.pory"
	end
# 90 "data/maps/Route110/scripts.pory"

# 91 "data/maps/Route110/scripts.pory"
Route110_EventScript_CyclingGirl1::
# 92 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_HairStreamsBehindMe, MSGBOX_NPC
# 93 "data/maps/Route110/scripts.pory"
	end
# 94 "data/maps/Route110/scripts.pory"

# 95 "data/maps/Route110/scripts.pory"
Route110_EventScript_CyclingGuy1::
# 96 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_YouGotBikeFromRydel, MSGBOX_NPC
# 97 "data/maps/Route110/scripts.pory"
	end
# 98 "data/maps/Route110/scripts.pory"

# 99 "data/maps/Route110/scripts.pory"
Route110_EventScript_OldMan::
# 100 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_TwoRoads, MSGBOX_NPC
# 101 "data/maps/Route110/scripts.pory"
	end
# 102 "data/maps/Route110/scripts.pory"

# 103 "data/maps/Route110/scripts.pory"
Route110_EventScript_OldWoman::
# 104 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_WalkOnTheLowRoad, MSGBOX_NPC
# 105 "data/maps/Route110/scripts.pory"
	end
# 106 "data/maps/Route110/scripts.pory"

# 107 "data/maps/Route110/scripts.pory"
Route110_EventScript_CyclingGuy2::
# 108 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_BikeTechniques, MSGBOX_NPC
# 109 "data/maps/Route110/scripts.pory"
	end
# 110 "data/maps/Route110/scripts.pory"

# 111 "data/maps/Route110/scripts.pory"
Route110_EventScript_Boy2::
# 112 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_WhichShouldIChoose, MSGBOX_NPC
# 113 "data/maps/Route110/scripts.pory"
	end
# 114 "data/maps/Route110/scripts.pory"

# 115 "data/maps/Route110/scripts.pory"
Route110_EventScript_SlateportCitySign::
# 116 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_SlateportCitySign, MSGBOX_SIGN
# 117 "data/maps/Route110/scripts.pory"
	end
# 118 "data/maps/Route110/scripts.pory"

# 119 "data/maps/Route110/scripts.pory"
Route110_EventScript_CyclingRoadSign::
# 120 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_CyclingRoadSign, MSGBOX_SIGN
# 121 "data/maps/Route110/scripts.pory"
	end
# 122 "data/maps/Route110/scripts.pory"

# 123 "data/maps/Route110/scripts.pory"
Route110_EventScript_VandalizedSign::
# 124 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_AquaWasHere, MSGBOX_SIGN
# 125 "data/maps/Route110/scripts.pory"
	end
# 126 "data/maps/Route110/scripts.pory"

# 127 "data/maps/Route110/scripts.pory"
Route110_EventScript_Route103Sign::
# 128 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_Route103Sign, MSGBOX_SIGN
# 129 "data/maps/Route110/scripts.pory"
	end
# 130 "data/maps/Route110/scripts.pory"

# 131 "data/maps/Route110/scripts.pory"
Route110_EventScript_SeasideParkingSign::
# 132 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_SeasideParkingSign, MSGBOX_SIGN
# 133 "data/maps/Route110/scripts.pory"
	end
# 134 "data/maps/Route110/scripts.pory"

# 135 "data/maps/Route110/scripts.pory"
Route110_EventScript_MauvilleCitySign::
# 136 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_MauvilleCitySign, MSGBOX_SIGN
# 137 "data/maps/Route110/scripts.pory"
	end
# 138 "data/maps/Route110/scripts.pory"

# 139 "data/maps/Route110/scripts.pory"
Route110_EventScript_TrainerTipsPrlzSleep::
# 140 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_TrainerTipsPrlzSleep, MSGBOX_SIGN
# 141 "data/maps/Route110/scripts.pory"
	end
# 142 "data/maps/Route110/scripts.pory"

# 143 "data/maps/Route110/scripts.pory"
Route110_EventScript_TrainerTipsRegisterItems::
# 144 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_TrainerTipsRegisterItems, MSGBOX_SIGN
# 145 "data/maps/Route110/scripts.pory"
	end
# 146 "data/maps/Route110/scripts.pory"

# 147 "data/maps/Route110/scripts.pory"
Route110_EventScript_TrickHouseSign::
# 148 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_TrickHouseSign, MSGBOX_SIGN
# 149 "data/maps/Route110/scripts.pory"
	end
# 150 "data/maps/Route110/scripts.pory"

# 151 "data/maps/Route110/scripts.pory"
Route110_EventScript_CyclingRoadResultsSign::
# 152 "data/maps/Route110/scripts.pory"
	lockall
# 153 "data/maps/Route110/scripts.pory"
	specialvar VAR_RESULT, GetRecordedCyclingRoadResults
# 154 "data/maps/Route110/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route110_EventScript_NoRecordSet
# 155 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_BestRecord, MSGBOX_DEFAULT
# 156 "data/maps/Route110/scripts.pory"
	releaseall
# 157 "data/maps/Route110/scripts.pory"
	end
# 158 "data/maps/Route110/scripts.pory"

# 159 "data/maps/Route110/scripts.pory"
Route110_EventScript_NoRecordSet::
# 160 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_ThereIsNoRecord, MSGBOX_DEFAULT
# 161 "data/maps/Route110/scripts.pory"
	releaseall
# 162 "data/maps/Route110/scripts.pory"
	end
# 163 "data/maps/Route110/scripts.pory"

# 164 "data/maps/Route110/scripts.pory"
Route110_EventScript_ChallengeGuy::
# 165 "data/maps/Route110/scripts.pory"
	lock
# 166 "data/maps/Route110/scripts.pory"
	faceplayer
# 167 "data/maps/Route110/scripts.pory"
	specialvar VAR_RESULT, GetPlayerAvatarBike
# 168 "data/maps/Route110/scripts.pory"
	goto_if_eq VAR_RESULT, 1, Route110_EventScript_PlayerRidingAcroBike
# 169 "data/maps/Route110/scripts.pory"
	goto_if_eq VAR_CYCLING_CHALLENGE_STATE, 0, Route110_EventScript_PlayerNotRidingBike
# 170 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_AlwaysAimHigher, MSGBOX_DEFAULT
# 171 "data/maps/Route110/scripts.pory"
	release
# 172 "data/maps/Route110/scripts.pory"
	end
# 173 "data/maps/Route110/scripts.pory"

# 174 "data/maps/Route110/scripts.pory"
Route110_EventScript_PlayerNotRidingBike::
# 175 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_RatedForNumberOfCollisions, MSGBOX_DEFAULT
# 176 "data/maps/Route110/scripts.pory"
	release
# 177 "data/maps/Route110/scripts.pory"
	end
# 178 "data/maps/Route110/scripts.pory"

# 179 "data/maps/Route110/scripts.pory"
Route110_EventScript_PlayerRidingAcroBike::
# 180 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_AcroBikesDoNotQualify, MSGBOX_DEFAULT
# 181 "data/maps/Route110/scripts.pory"
	release
# 182 "data/maps/Route110/scripts.pory"
	end
# 183 "data/maps/Route110/scripts.pory"

# 184 "data/maps/Route110/scripts.pory"
Route110_EventScript_Edward::
# 185 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_EDWARD, Route110_Text_EdwardIntro, Route110_Text_EdwardDefeated
# 186 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_EdwardPostBattle, MSGBOX_AUTOCLOSE
# 187 "data/maps/Route110/scripts.pory"
	end
# 188 "data/maps/Route110/scripts.pory"

# 189 "data/maps/Route110/scripts.pory"
Route110_EventScript_Jaclyn::
# 190 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_JACLYN, Route110_Text_JaclynIntro, Route110_Text_JaclynDefeated
# 191 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_JaclynPostBattle, MSGBOX_AUTOCLOSE
# 192 "data/maps/Route110/scripts.pory"
	end
# 193 "data/maps/Route110/scripts.pory"

# 194 "data/maps/Route110/scripts.pory"
Route110_EventScript_Edwin::
# 195 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_EDWIN_1, Route110_Text_EdwinIntro, Route110_Text_EdwinDefeated, Route110_EventScript_EdwinRegisterMatchCallAfterBattle
# 196 "data/maps/Route110/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 197 "data/maps/Route110/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_EdwinRematch
# 198 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_EdwinPostBattle, MSGBOX_DEFAULT
# 199 "data/maps/Route110/scripts.pory"
	release
# 200 "data/maps/Route110/scripts.pory"
	end
# 201 "data/maps/Route110/scripts.pory"

# 202 "data/maps/Route110/scripts.pory"
Route110_EventScript_EdwinRegisterMatchCallAfterBattle::
# 203 "data/maps/Route110/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 204 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 205 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_EdwinRegister, MSGBOX_DEFAULT
# 206 "data/maps/Route110/scripts.pory"
	register_matchcall TRAINER_EDWIN_1
# 207 "data/maps/Route110/scripts.pory"
	release
# 208 "data/maps/Route110/scripts.pory"
	end
# 209 "data/maps/Route110/scripts.pory"

# 210 "data/maps/Route110/scripts.pory"
Route110_EventScript_EdwinRematch::
# 211 "data/maps/Route110/scripts.pory"
	trainerbattle_rematch TRAINER_EDWIN_1, Route110_Text_EdwinRematchIntro, Route110_Text_EdwinRematchDefeated
# 212 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_EdwinRematchPostBattle, MSGBOX_AUTOCLOSE
# 213 "data/maps/Route110/scripts.pory"
	end
# 214 "data/maps/Route110/scripts.pory"

# 215 "data/maps/Route110/scripts.pory"
Route110_EventScript_Dale::
# 216 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_DALE, Route110_Text_DaleIntro, Route110_Text_DaleDefeated
# 217 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_DalePostBattle, MSGBOX_AUTOCLOSE
# 218 "data/maps/Route110/scripts.pory"
	end
# 219 "data/maps/Route110/scripts.pory"

# 220 "data/maps/Route110/scripts.pory"
Route110_EventScript_Jacob::
# 221 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_JACOB, Route110_Text_JacobIntro, Route110_Text_JacobDefeated
# 222 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_JacobPostBattle, MSGBOX_AUTOCLOSE
# 223 "data/maps/Route110/scripts.pory"
	end
# 224 "data/maps/Route110/scripts.pory"

# 225 "data/maps/Route110/scripts.pory"
Route110_EventScript_Anthony::
# 226 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_ANTHONY, Route110_Text_AnthonyIntro, Route110_Text_AnthonyDefeated
# 227 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
# 228 "data/maps/Route110/scripts.pory"
	end
# 229 "data/maps/Route110/scripts.pory"

# 230 "data/maps/Route110/scripts.pory"
Route110_EventScript_Benjamin::
# 231 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_BENJAMIN_1, Route110_Text_BenjaminIntro, Route110_Text_BenjaminDefeated, Route110_EventScript_BenjaminRegisterMatchCallAfterBattle
# 232 "data/maps/Route110/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 233 "data/maps/Route110/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_BenjaminRematch
# 234 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_BenjaminPostBattle, MSGBOX_DEFAULT
# 235 "data/maps/Route110/scripts.pory"
	release
# 236 "data/maps/Route110/scripts.pory"
	end
# 237 "data/maps/Route110/scripts.pory"

# 238 "data/maps/Route110/scripts.pory"
Route110_EventScript_BenjaminRegisterMatchCallAfterBattle::
# 239 "data/maps/Route110/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 240 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 241 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_BenjaminRegister, MSGBOX_DEFAULT
# 242 "data/maps/Route110/scripts.pory"
	register_matchcall TRAINER_BENJAMIN_1
# 243 "data/maps/Route110/scripts.pory"
	release
# 244 "data/maps/Route110/scripts.pory"
	end
# 245 "data/maps/Route110/scripts.pory"

# 246 "data/maps/Route110/scripts.pory"
Route110_EventScript_BenjaminRematch::
# 247 "data/maps/Route110/scripts.pory"
	trainerbattle_rematch TRAINER_BENJAMIN_1, Route110_Text_BenjaminRematchIntro, Route110_Text_BenjaminRematchDefeated
# 248 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_BenjaminRematchPostBattle, MSGBOX_AUTOCLOSE
# 249 "data/maps/Route110/scripts.pory"
	end
# 250 "data/maps/Route110/scripts.pory"

# 251 "data/maps/Route110/scripts.pory"
Route110_EventScript_Jasmine::
# 252 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_JASMINE, Route110_Text_JasmineIntro, Route110_Text_JasmineDefeated
# 253 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_JasminePostBattle, MSGBOX_AUTOCLOSE
# 254 "data/maps/Route110/scripts.pory"
	end
# 255 "data/maps/Route110/scripts.pory"

# 256 "data/maps/Route110/scripts.pory"
Route110_EventScript_Abigail::
# 257 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_ABIGAIL_1, Route110_Text_AbigailIntro, Route110_Text_AbigailDefeated, Route110_EventScript_AbigailRegisterMatchCallAfterBattle
# 258 "data/maps/Route110/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 259 "data/maps/Route110/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_AbigailRematch
# 260 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_AbigailPostBattle, MSGBOX_DEFAULT
# 261 "data/maps/Route110/scripts.pory"
	release
# 262 "data/maps/Route110/scripts.pory"
	end
# 263 "data/maps/Route110/scripts.pory"

# 264 "data/maps/Route110/scripts.pory"
Route110_EventScript_AbigailRegisterMatchCallAfterBattle::
# 265 "data/maps/Route110/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 266 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 267 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_AbigailRegister, MSGBOX_DEFAULT
# 268 "data/maps/Route110/scripts.pory"
	register_matchcall TRAINER_ABIGAIL_1
# 269 "data/maps/Route110/scripts.pory"
	release
# 270 "data/maps/Route110/scripts.pory"
	end
# 271 "data/maps/Route110/scripts.pory"

# 272 "data/maps/Route110/scripts.pory"
Route110_EventScript_AbigailRematch::
# 273 "data/maps/Route110/scripts.pory"
	trainerbattle_rematch TRAINER_ABIGAIL_1, Route110_Text_AbigailRematchIntro, Route110_Text_AbigailRematchDefeated
# 274 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_AbigailRematchPostBattle, MSGBOX_AUTOCLOSE
# 275 "data/maps/Route110/scripts.pory"
	end
# 276 "data/maps/Route110/scripts.pory"

# 277 "data/maps/Route110/scripts.pory"
Route110_EventScript_Isabel::
# 278 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_ISABEL_1, Route110_Text_IsabelIntro, Route110_Text_IsabelDefeated, Route110_EventScript_IsabelRegisterMatchCallAfterBattle
# 279 "data/maps/Route110/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 280 "data/maps/Route110/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_IsabelRematch
# 281 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_IsabelPostBattle, MSGBOX_DEFAULT
# 282 "data/maps/Route110/scripts.pory"
	release
# 283 "data/maps/Route110/scripts.pory"
	end
# 284 "data/maps/Route110/scripts.pory"

# 285 "data/maps/Route110/scripts.pory"
Route110_EventScript_IsabelRegisterMatchCallAfterBattle::
# 286 "data/maps/Route110/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 287 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 288 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_IsabelRegister, MSGBOX_DEFAULT
# 289 "data/maps/Route110/scripts.pory"
	register_matchcall TRAINER_ISABEL_1
# 290 "data/maps/Route110/scripts.pory"
	release
# 291 "data/maps/Route110/scripts.pory"
	end
# 292 "data/maps/Route110/scripts.pory"

# 293 "data/maps/Route110/scripts.pory"
Route110_EventScript_IsabelRematch::
# 294 "data/maps/Route110/scripts.pory"
	trainerbattle_rematch TRAINER_ISABEL_1, Route110_Text_IsabelRematchIntro, Route110_Text_IsabelRematchDefeated
# 295 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_IsabelRematchPostBattle, MSGBOX_AUTOCLOSE
# 296 "data/maps/Route110/scripts.pory"
	end
# 297 "data/maps/Route110/scripts.pory"

# 298 "data/maps/Route110/scripts.pory"
Route110_EventScript_Timmy::
# 299 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_TIMMY, Route110_Text_TimmyIntro, Route110_Text_TimmyDefeated
# 300 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_TimmyPostBattle, MSGBOX_AUTOCLOSE
# 301 "data/maps/Route110/scripts.pory"
	end
# 302 "data/maps/Route110/scripts.pory"

# 303 "data/maps/Route110/scripts.pory"
Route110_EventScript_Unused::
# 304 "data/maps/Route110/scripts.pory"
	end
# 305 "data/maps/Route110/scripts.pory"

# 306 "data/maps/Route110/scripts.pory"
Route110_EventScript_Kaleb::
# 307 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_KALEB, Route110_Text_KalebIntro, Route110_Text_KalebDefeated
# 308 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_KalebPostBattle, MSGBOX_AUTOCLOSE
# 309 "data/maps/Route110/scripts.pory"
	end
# 310 "data/maps/Route110/scripts.pory"

# 311 "data/maps/Route110/scripts.pory"
Route110_EventScript_Joseph::
# 312 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_JOSEPH, Route110_Text_JosephIntro, Route110_Text_JosephDefeated
# 313 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_JosephPostBattle, MSGBOX_AUTOCLOSE
# 314 "data/maps/Route110/scripts.pory"
	end
# 315 "data/maps/Route110/scripts.pory"

# 316 "data/maps/Route110/scripts.pory"
Route110_EventScript_Alyssa::
# 317 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_ALYSSA, Route110_Text_AlyssaIntro, Route110_Text_AlyssaDefeated
# 318 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_AlyssaPostBattle, MSGBOX_AUTOCLOSE
# 319 "data/maps/Route110/scripts.pory"
	end
# 320 "data/maps/Route110/scripts.pory"

# 321 "data/maps/Route110/scripts.pory"
Route110_EventScript_CyclingChallengeEnd::
# 322 "data/maps/Route110/scripts.pory"
	lockall
# 323 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_CHALLENGE_BIKER, Common_Movement_WalkInPlaceFasterRight
# 324 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 325 "data/maps/Route110/scripts.pory"
	call Route110_EventScript_CyclingChallengeResults
# 326 "data/maps/Route110/scripts.pory"
	releaseall
# 327 "data/maps/Route110/scripts.pory"
	end
# 328 "data/maps/Route110/scripts.pory"

# 329 "data/maps/Route110/scripts.pory"
Route110_EventScript_CyclingChallengeResults::
# 330 "data/maps/Route110/scripts.pory"
	special FinishCyclingRoadChallenge
# 331 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_CyclingChallengeResultSummary, MSGBOX_DEFAULT
# 332 "data/maps/Route110/scripts.pory"
	switch VAR_RESULT
# 333 "data/maps/Route110/scripts.pory"
	case 10, Route110_EventScript_ChallengeReactionBest
# 334 "data/maps/Route110/scripts.pory"
	case 9, Route110_EventScript_ChallengeReactionGood
# 335 "data/maps/Route110/scripts.pory"
	case 8, Route110_EventScript_ChallengeReactionGood
# 336 "data/maps/Route110/scripts.pory"
	case 7, Route110_EventScript_ChallengeReactionGood
# 337 "data/maps/Route110/scripts.pory"
	case 6, Route110_EventScript_ChallengeReactionOk
# 338 "data/maps/Route110/scripts.pory"
	case 5, Route110_EventScript_ChallengeReactionOk
# 339 "data/maps/Route110/scripts.pory"
	case 4, Route110_EventScript_ChallengeReactionOk
# 340 "data/maps/Route110/scripts.pory"
	case 3, Route110_EventScript_ChallengeReactionBad
# 341 "data/maps/Route110/scripts.pory"
	case 2, Route110_EventScript_ChallengeReactionBad
# 342 "data/maps/Route110/scripts.pory"
	case 1, Route110_EventScript_ChallengeReactionBad
# 343 "data/maps/Route110/scripts.pory"
	case 0, Route110_EventScript_ChallengeReactionWorst
# 344 "data/maps/Route110/scripts.pory"
	end
# 345 "data/maps/Route110/scripts.pory"

# 346 "data/maps/Route110/scripts.pory"
Route110_EventScript_ChallengeReactionBest::
# 347 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_ChallengeReactionBest, MSGBOX_DEFAULT
# 348 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_EndChallenge
# 349 "data/maps/Route110/scripts.pory"
	end
# 350 "data/maps/Route110/scripts.pory"

# 351 "data/maps/Route110/scripts.pory"
Route110_EventScript_ChallengeReactionGood::
# 352 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_ChallengeReactionGood, MSGBOX_DEFAULT
# 353 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_EndChallenge
# 354 "data/maps/Route110/scripts.pory"
	end
# 355 "data/maps/Route110/scripts.pory"

# 356 "data/maps/Route110/scripts.pory"
Route110_EventScript_ChallengeReactionOk::
# 357 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_ChallengeReactionOk, MSGBOX_DEFAULT
# 358 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_EndChallenge
# 359 "data/maps/Route110/scripts.pory"
	end
# 360 "data/maps/Route110/scripts.pory"

# 361 "data/maps/Route110/scripts.pory"
Route110_EventScript_ChallengeReactionBad::
# 362 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_ChallengeReactionBad, MSGBOX_DEFAULT
# 363 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_EndChallenge
# 364 "data/maps/Route110/scripts.pory"
	end
# 365 "data/maps/Route110/scripts.pory"

# 366 "data/maps/Route110/scripts.pory"
Route110_EventScript_ChallengeReactionWorst::
# 367 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_ChallengeReactionWorst, MSGBOX_DEFAULT
# 368 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_EndChallenge
# 369 "data/maps/Route110/scripts.pory"
	end
# 370 "data/maps/Route110/scripts.pory"

# 371 "data/maps/Route110/scripts.pory"
Route110_EventScript_EndChallenge::
# 372 "data/maps/Route110/scripts.pory"
	setvar VAR_CYCLING_CHALLENGE_STATE, 3
# 373 "data/maps/Route110/scripts.pory"
	savebgm MUS_DUMMY
# 374 "data/maps/Route110/scripts.pory"
	fadedefaultbgm
# 375 "data/maps/Route110/scripts.pory"
	return
# 376 "data/maps/Route110/scripts.pory"

# 377 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalTrigger1::
# 378 "data/maps/Route110/scripts.pory"
	setvar VAR_0x8008, 1
# 379 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_RivalScene
# 380 "data/maps/Route110/scripts.pory"
	end
# 381 "data/maps/Route110/scripts.pory"

# 382 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalTrigger2::
# 383 "data/maps/Route110/scripts.pory"
	setvar VAR_0x8008, 2
# 384 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_RivalScene
# 385 "data/maps/Route110/scripts.pory"
	end
# 386 "data/maps/Route110/scripts.pory"

# 387 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalTrigger3::
# 388 "data/maps/Route110/scripts.pory"
	setvar VAR_0x8008, 3
# 389 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_RivalScene
# 390 "data/maps/Route110/scripts.pory"
	end
# 391 "data/maps/Route110/scripts.pory"

# 392 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalScene::
# 393 "data/maps/Route110/scripts.pory"
	lockall
# 394 "data/maps/Route110/scripts.pory"
	checkplayergender
# 395 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_RESULT, MALE, Route110_EventScript_PlayMayMusic
# 396 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, Route110_EventScript_PlayBrendanMusic
# 397 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 398 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 399 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 400 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 401 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 402 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 403 "data/maps/Route110/scripts.pory"
	delay 30
# 404 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 1, Route110_EventScript_RivalApproachPlayer1
# 405 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 2, Route110_EventScript_RivalApproachPlayer2
# 406 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 3, Route110_EventScript_RivalApproachPlayer3
# 407 "data/maps/Route110/scripts.pory"
	checkplayergender
# 408 "data/maps/Route110/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, Route110_EventScript_MayBattle
# 409 "data/maps/Route110/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, Route110_EventScript_BrendanBattle
# 410 "data/maps/Route110/scripts.pory"
	releaseall
# 411 "data/maps/Route110/scripts.pory"
	end
# 412 "data/maps/Route110/scripts.pory"

# 413 "data/maps/Route110/scripts.pory"
Route110_EventScript_PlayMayMusic::
# 414 "data/maps/Route110/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 415 "data/maps/Route110/scripts.pory"
	return
# 416 "data/maps/Route110/scripts.pory"

# 417 "data/maps/Route110/scripts.pory"
Route110_EventScript_PlayBrendanMusic::
# 418 "data/maps/Route110/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 419 "data/maps/Route110/scripts.pory"
	return
# 420 "data/maps/Route110/scripts.pory"

# 421 "data/maps/Route110/scripts.pory"
Route110_EventScript_MayBattle::
# 422 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_MayLetsBattle, MSGBOX_DEFAULT
# 423 "data/maps/Route110/scripts.pory"
	playse SE_M_BATON_PASS
# 424 "data/maps/Route110/scripts.pory"
	waitse
# 425 "data/maps/Route110/scripts.pory"
	removeobject LOCALID_AMAURA
# 426 "data/maps/Route110/scripts.pory"
	setflag FLAG_HIDE_RIVALS_AMAURA
# 427 "data/maps/Route110/scripts.pory"
	switch VAR_STARTER_MON
# 428 "data/maps/Route110/scripts.pory"
	case 0, Route110_EventScript_MayBattleTreecko
# 429 "data/maps/Route110/scripts.pory"
	case 1, Route110_EventScript_MayBattleTorchic
# 430 "data/maps/Route110/scripts.pory"
	case 2, Route110_EventScript_MayBattleMudkip
# 431 "data/maps/Route110/scripts.pory"
	end
# 432 "data/maps/Route110/scripts.pory"

# 433 "data/maps/Route110/scripts.pory"
Route110_EventScript_MayBattleTreecko::
# 434 "data/maps/Route110/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_TREECKO, Route110_Text_MayDefeated
# 435 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_MayDefeated
# 436 "data/maps/Route110/scripts.pory"
	end
# 437 "data/maps/Route110/scripts.pory"

# 438 "data/maps/Route110/scripts.pory"
Route110_EventScript_MayBattleTorchic::
# 439 "data/maps/Route110/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_TORCHIC, Route110_Text_MayDefeated
# 440 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_MayDefeated
# 441 "data/maps/Route110/scripts.pory"
	end
# 442 "data/maps/Route110/scripts.pory"

# 443 "data/maps/Route110/scripts.pory"
Route110_EventScript_MayBattleMudkip::
# 444 "data/maps/Route110/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_MUDKIP, Route110_Text_MayDefeated
# 445 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_MayDefeated
# 446 "data/maps/Route110/scripts.pory"
	end
# 447 "data/maps/Route110/scripts.pory"

# 448 "data/maps/Route110/scripts.pory"
Route110_EventScript_MayDefeated::
# 449 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_MayTakeThis, MSGBOX_DEFAULT
# 450 "data/maps/Route110/scripts.pory"
	call Route110_EventScript_GiveItemfinder
# 451 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_MayExplainItemfinder, MSGBOX_DEFAULT
# 452 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_RivalExit
# 453 "data/maps/Route110/scripts.pory"
	end
# 454 "data/maps/Route110/scripts.pory"

# 455 "data/maps/Route110/scripts.pory"
Route110_EventScript_BrendanBattle::
# 456 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_BrendanLetsBattle, MSGBOX_DEFAULT
# 457 "data/maps/Route110/scripts.pory"
	playse SE_M_BATON_PASS
# 458 "data/maps/Route110/scripts.pory"
	waitse
# 459 "data/maps/Route110/scripts.pory"
	removeobject LOCALID_ANORITH
# 460 "data/maps/Route110/scripts.pory"
	setflag FLAG_HIDE_RIVALS_ANORITH
# 461 "data/maps/Route110/scripts.pory"
	switch VAR_STARTER_MON
# 462 "data/maps/Route110/scripts.pory"
	case 0, Route110_EventScript_BrendanBattleTreecko
# 463 "data/maps/Route110/scripts.pory"
	case 1, Route110_EventScript_BrendanBattleTorchic
# 464 "data/maps/Route110/scripts.pory"
	case 2, Route110_EventScript_BrendanBattleMudkip
# 465 "data/maps/Route110/scripts.pory"
	end
# 466 "data/maps/Route110/scripts.pory"

# 467 "data/maps/Route110/scripts.pory"
Route110_EventScript_BrendanBattleTreecko::
# 468 "data/maps/Route110/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TREECKO, Route110_Text_BrendanDefeated
# 469 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_BrendanDefeated
# 470 "data/maps/Route110/scripts.pory"
	end
# 471 "data/maps/Route110/scripts.pory"

# 472 "data/maps/Route110/scripts.pory"
Route110_EventScript_BrendanBattleTorchic::
# 473 "data/maps/Route110/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TORCHIC, Route110_Text_BrendanDefeated
# 474 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_BrendanDefeated
# 475 "data/maps/Route110/scripts.pory"
	end
# 476 "data/maps/Route110/scripts.pory"

# 477 "data/maps/Route110/scripts.pory"
Route110_EventScript_BrendanBattleMudkip::
# 478 "data/maps/Route110/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_MUDKIP, Route110_Text_BrendanDefeated
# 479 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_BrendanDefeated
# 480 "data/maps/Route110/scripts.pory"
	end
# 481 "data/maps/Route110/scripts.pory"

# 482 "data/maps/Route110/scripts.pory"
Route110_EventScript_BrendanDefeated::
# 483 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_BrendanTakeThis, MSGBOX_DEFAULT
# 484 "data/maps/Route110/scripts.pory"
	call Route110_EventScript_GiveItemfinder
# 485 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_BrendanExplainItemfinder, MSGBOX_DEFAULT
# 486 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_RivalExit
# 487 "data/maps/Route110/scripts.pory"
	end
# 488 "data/maps/Route110/scripts.pory"

# 489 "data/maps/Route110/scripts.pory"
Route110_EventScript_GiveItemfinder::
# 490 "data/maps/Route110/scripts.pory"
	giveitem ITEM_DOWSING_MACHINE
# 491 "data/maps/Route110/scripts.pory"
	return
# 492 "data/maps/Route110/scripts.pory"

# 493 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalExit::
# 494 "data/maps/Route110/scripts.pory"
	closemessage
# 495 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 1, Route110_EventScript_MoveRival1
# 496 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 2, Route110_EventScript_MoveRival2
# 497 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 3, Route110_EventScript_MoveRival3
# 498 "data/maps/Route110/scripts.pory"
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_RIGHT
# 499 "data/maps/Route110/scripts.pory"
	setobjectmovementtype LOCALID_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_RIGHT
# 500 "data/maps/Route110/scripts.pory"
	removeobject LOCALID_RIVAL
# 501 "data/maps/Route110/scripts.pory"
	addobject LOCALID_RIVAL_ON_BIKE
# 502 "data/maps/Route110/scripts.pory"
	delay 45
# 503 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 1, Route110_EventScript_RivalExit1
# 504 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 2, Route110_EventScript_RivalExit2
# 505 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 3, Route110_EventScript_RivalExit3
# 506 "data/maps/Route110/scripts.pory"
	removeobject LOCALID_RIVAL_ON_BIKE
# 507 "data/maps/Route110/scripts.pory"
	setvar VAR_ROUTE110_STATE, 1
# 508 "data/maps/Route110/scripts.pory"
	savebgm MUS_DUMMY
# 509 "data/maps/Route110/scripts.pory"
	fadedefaultbgm
# 510 "data/maps/Route110/scripts.pory"
	releaseall
# 511 "data/maps/Route110/scripts.pory"
	end
# 512 "data/maps/Route110/scripts.pory"

# 513 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalApproachPlayer1::
# 514 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL, Route110_Movement_RivalApproachPlayer1
# 515 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 516 "data/maps/Route110/scripts.pory"
	return
# 517 "data/maps/Route110/scripts.pory"

# 518 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalApproachPlayer2::
# 519 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL, Route110_Movement_RivalApproachPlayer2
# 520 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 521 "data/maps/Route110/scripts.pory"
	return
# 522 "data/maps/Route110/scripts.pory"

# 523 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalApproachPlayer3::
# 524 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL, Route110_Movement_RivalApproachPlayer3
# 525 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 526 "data/maps/Route110/scripts.pory"
	return
# 527 "data/maps/Route110/scripts.pory"

# 528 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalExit1::
# 529 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, Route110_Movement_RivalExit1
# 530 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 531 "data/maps/Route110/scripts.pory"
	return
# 532 "data/maps/Route110/scripts.pory"

# 533 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalExit2::
# 534 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, Route110_Movement_RivalExit2
# 535 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 536 "data/maps/Route110/scripts.pory"
	return
# 537 "data/maps/Route110/scripts.pory"

# 538 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalExit3::
# 539 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, Route110_Movement_RivalExit3
# 540 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 541 "data/maps/Route110/scripts.pory"
	return
# 542 "data/maps/Route110/scripts.pory"

# 543 "data/maps/Route110/scripts.pory"
Route110_EventScript_MoveRival1::
# 544 "data/maps/Route110/scripts.pory"
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 33, 55
# 545 "data/maps/Route110/scripts.pory"
	return
# 546 "data/maps/Route110/scripts.pory"

# 547 "data/maps/Route110/scripts.pory"
Route110_EventScript_MoveRival2::
# 548 "data/maps/Route110/scripts.pory"
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 34, 55
# 549 "data/maps/Route110/scripts.pory"
	return
# 550 "data/maps/Route110/scripts.pory"

# 551 "data/maps/Route110/scripts.pory"
Route110_EventScript_MoveRival3::
# 552 "data/maps/Route110/scripts.pory"
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 35, 55
# 553 "data/maps/Route110/scripts.pory"
	return
# 554 "data/maps/Route110/scripts.pory"

# 555 "data/maps/Route110/scripts.pory"
Route110_Movement_RivalApproachPlayer1:
# 556 "data/maps/Route110/scripts.pory"
	walk_down
# 557 "data/maps/Route110/scripts.pory"
	walk_left
# 558 "data/maps/Route110/scripts.pory"
	walk_in_place_faster_down
# 559 "data/maps/Route110/scripts.pory"
	step_end
# 560 "data/maps/Route110/scripts.pory"

# 561 "data/maps/Route110/scripts.pory"
Route110_Movement_RivalApproachPlayer2:
# 562 "data/maps/Route110/scripts.pory"
	walk_down
# 563 "data/maps/Route110/scripts.pory"
	step_end
# 564 "data/maps/Route110/scripts.pory"

# 565 "data/maps/Route110/scripts.pory"
Route110_Movement_RivalApproachPlayer3:
# 566 "data/maps/Route110/scripts.pory"
	walk_down
# 567 "data/maps/Route110/scripts.pory"
	walk_right
# 568 "data/maps/Route110/scripts.pory"
	walk_in_place_faster_down
# 569 "data/maps/Route110/scripts.pory"
	step_end
# 570 "data/maps/Route110/scripts.pory"

# 571 "data/maps/Route110/scripts.pory"
Route110_Movement_RivalExit1:
# 572 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 573 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 574 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 575 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 576 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 577 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 578 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 579 "data/maps/Route110/scripts.pory"
	step_end
# 580 "data/maps/Route110/scripts.pory"

# 581 "data/maps/Route110/scripts.pory"
Route110_Movement_RivalExit2:
# 582 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 583 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 584 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 585 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 586 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 587 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 588 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 589 "data/maps/Route110/scripts.pory"
	walk_fast_down
# 590 "data/maps/Route110/scripts.pory"
	step_end
# 591 "data/maps/Route110/scripts.pory"

# 592 "data/maps/Route110/scripts.pory"
Route110_Movement_RivalExit3:
# 593 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 594 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 595 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 596 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 597 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 598 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 599 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 600 "data/maps/Route110/scripts.pory"
	step_end
# 601 "data/maps/Route110/scripts.pory"

# 602 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchScene1::
# 603 "data/maps/Route110/scripts.pory"
	lockall
# 604 "data/maps/Route110/scripts.pory"
	setvar VAR_0x8008, 1
# 605 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_BirchScene
# 606 "data/maps/Route110/scripts.pory"

# 607 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchScene2::
# 608 "data/maps/Route110/scripts.pory"
	lockall
# 609 "data/maps/Route110/scripts.pory"
	setvar VAR_0x8008, 2
# 610 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_BirchScene
# 611 "data/maps/Route110/scripts.pory"

# 612 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchScene3::
# 613 "data/maps/Route110/scripts.pory"
	lockall
# 614 "data/maps/Route110/scripts.pory"
	setvar VAR_0x8008, 3
# 615 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_BirchScene
# 616 "data/maps/Route110/scripts.pory"

# 617 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchScene4::
# 618 "data/maps/Route110/scripts.pory"
	lockall
# 619 "data/maps/Route110/scripts.pory"
	setvar VAR_0x8008, 4
# 620 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_BirchScene
# 621 "data/maps/Route110/scripts.pory"

# 622 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchScene::
# 623 "data/maps/Route110/scripts.pory"
	addobject LOCALID_BIRCH
# 624 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchEntrance
# 625 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 626 "data/maps/Route110/scripts.pory"
	playse SE_PIN
# 627 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_ExclamationMark
# 628 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 629 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_Delay48
# 630 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 631 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 1, Route110_EventScript_BirchApproachPlayer1
# 632 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 2, Route110_EventScript_BirchApproachPlayer2
# 633 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 3, Route110_EventScript_BirchApproachPlayer3
# 634 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 4, Route110_EventScript_BirchApproachPlayer4
# 635 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_ImagineSeeingYouHere, MSGBOX_DEFAULT
# 636 "data/maps/Route110/scripts.pory"
	closemessage
# 637 "data/maps/Route110/scripts.pory"
	delay 20
# 638 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterLeft
# 639 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 640 "data/maps/Route110/scripts.pory"
	delay 10
# 641 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
# 642 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 643 "data/maps/Route110/scripts.pory"
	delay 20
# 644 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterDown
# 645 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 646 "data/maps/Route110/scripts.pory"
	delay 30
# 647 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_HeardYouInstallMatchCall, MSGBOX_DEFAULT
# 648 "data/maps/Route110/scripts.pory"
	closemessage
# 649 "data/maps/Route110/scripts.pory"
	delay 30
# 650 "data/maps/Route110/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 651 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_RegisteredBirchInPokenav, MSGBOX_DEFAULT
# 652 "data/maps/Route110/scripts.pory"
	waitfanfare
# 653 "data/maps/Route110/scripts.pory"
	closemessage
# 654 "data/maps/Route110/scripts.pory"
	delay 30
# 655 "data/maps/Route110/scripts.pory"
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
# 656 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_KeepAnEyeOutForRival, MSGBOX_DEFAULT
# 657 "data/maps/Route110/scripts.pory"
	closemessage
# 658 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 1, Route110_EventScript_BirchExit1
# 659 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 2, Route110_EventScript_BirchExit2
# 660 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 3, Route110_EventScript_BirchExit3
# 661 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 4, Route110_EventScript_BirchExit4
# 662 "data/maps/Route110/scripts.pory"
	removeobject LOCALID_BIRCH
# 663 "data/maps/Route110/scripts.pory"
	setvar VAR_REGISTER_BIRCH_STATE, 2
# 664 "data/maps/Route110/scripts.pory"
	releaseall
# 665 "data/maps/Route110/scripts.pory"
	end
# 666 "data/maps/Route110/scripts.pory"

# 667 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchApproachPlayer1::
# 668 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer1
# 669 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 670 "data/maps/Route110/scripts.pory"
	return
# 671 "data/maps/Route110/scripts.pory"

# 672 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchApproachPlayer2::
# 673 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer2
# 674 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 675 "data/maps/Route110/scripts.pory"
	return
# 676 "data/maps/Route110/scripts.pory"

# 677 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchApproachPlayer3::
# 678 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer3
# 679 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 680 "data/maps/Route110/scripts.pory"
	return
# 681 "data/maps/Route110/scripts.pory"

# 682 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchApproachPlayer4::
# 683 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer4
# 684 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 685 "data/maps/Route110/scripts.pory"
	return
# 686 "data/maps/Route110/scripts.pory"

# 687 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchExit1::
# 688 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit1
# 689 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 690 "data/maps/Route110/scripts.pory"
	return
# 691 "data/maps/Route110/scripts.pory"

# 692 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchExit2::
# 693 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit2
# 694 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 695 "data/maps/Route110/scripts.pory"
	return
# 696 "data/maps/Route110/scripts.pory"

# 697 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchExit3::
# 698 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit3
# 699 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 700 "data/maps/Route110/scripts.pory"
	return
# 701 "data/maps/Route110/scripts.pory"

# 702 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchExit4::
# 703 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit4
# 704 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 705 "data/maps/Route110/scripts.pory"
	return
# 706 "data/maps/Route110/scripts.pory"

# 707 "data/maps/Route110/scripts.pory"
Route110_Movement_BirchEntrance:
# 708 "data/maps/Route110/scripts.pory"
	walk_down
# 709 "data/maps/Route110/scripts.pory"
	walk_down
# 710 "data/maps/Route110/scripts.pory"
	walk_down
# 711 "data/maps/Route110/scripts.pory"
	step_end
# 712 "data/maps/Route110/scripts.pory"

# 713 "data/maps/Route110/scripts.pory"
Route110_Movement_BirchApproachPlayer1:
# 714 "data/maps/Route110/scripts.pory"
	walk_down
# 715 "data/maps/Route110/scripts.pory"
	walk_left
# 716 "data/maps/Route110/scripts.pory"
	walk_left
# 717 "data/maps/Route110/scripts.pory"
	walk_down
# 718 "data/maps/Route110/scripts.pory"
	step_end
# 719 "data/maps/Route110/scripts.pory"

# 720 "data/maps/Route110/scripts.pory"
Route110_Movement_BirchApproachPlayer2:
# 721 "data/maps/Route110/scripts.pory"
	walk_down
# 722 "data/maps/Route110/scripts.pory"
	walk_left
# 723 "data/maps/Route110/scripts.pory"
	walk_down
# 724 "data/maps/Route110/scripts.pory"
	step_end
# 725 "data/maps/Route110/scripts.pory"

# 726 "data/maps/Route110/scripts.pory"
Route110_Movement_BirchApproachPlayer3:
# 727 "data/maps/Route110/scripts.pory"
	walk_down
# 728 "data/maps/Route110/scripts.pory"
	walk_down
# 729 "data/maps/Route110/scripts.pory"
	step_end
# 730 "data/maps/Route110/scripts.pory"

# 731 "data/maps/Route110/scripts.pory"
Route110_Movement_BirchApproachPlayer4:
# 732 "data/maps/Route110/scripts.pory"
	walk_down
# 733 "data/maps/Route110/scripts.pory"
	walk_right
# 734 "data/maps/Route110/scripts.pory"
	walk_down
# 735 "data/maps/Route110/scripts.pory"
	step_end
# 736 "data/maps/Route110/scripts.pory"

# 737 "data/maps/Route110/scripts.pory"
Route110_Movement_BirchExit1:
# 738 "data/maps/Route110/scripts.pory"
	walk_up
# 739 "data/maps/Route110/scripts.pory"
	walk_up
# 740 "data/maps/Route110/scripts.pory"
	walk_right
# 741 "data/maps/Route110/scripts.pory"
	walk_up
# 742 "data/maps/Route110/scripts.pory"
	walk_up
# 743 "data/maps/Route110/scripts.pory"
	walk_up
# 744 "data/maps/Route110/scripts.pory"
	step_end
# 745 "data/maps/Route110/scripts.pory"

# 746 "data/maps/Route110/scripts.pory"
Route110_Movement_BirchExit2:
# 747 "data/maps/Route110/scripts.pory"
	walk_up
# 748 "data/maps/Route110/scripts.pory"
	walk_up
# 749 "data/maps/Route110/scripts.pory"
	walk_up
# 750 "data/maps/Route110/scripts.pory"
	walk_up
# 751 "data/maps/Route110/scripts.pory"
	walk_up
# 752 "data/maps/Route110/scripts.pory"
	step_end
# 753 "data/maps/Route110/scripts.pory"

# 754 "data/maps/Route110/scripts.pory"
Route110_Movement_BirchExit3:
# 755 "data/maps/Route110/scripts.pory"
	walk_up
# 756 "data/maps/Route110/scripts.pory"
	walk_up
# 757 "data/maps/Route110/scripts.pory"
	walk_up
# 758 "data/maps/Route110/scripts.pory"
	walk_up
# 759 "data/maps/Route110/scripts.pory"
	walk_up
# 760 "data/maps/Route110/scripts.pory"
	step_end
# 761 "data/maps/Route110/scripts.pory"

# 762 "data/maps/Route110/scripts.pory"
Route110_Movement_BirchExit4:
# 763 "data/maps/Route110/scripts.pory"
	walk_up
# 764 "data/maps/Route110/scripts.pory"
	walk_up
# 765 "data/maps/Route110/scripts.pory"
	walk_up
# 766 "data/maps/Route110/scripts.pory"
	walk_up
# 767 "data/maps/Route110/scripts.pory"
	walk_up
# 768 "data/maps/Route110/scripts.pory"
	step_end
# 769 "data/maps/Route110/scripts.pory"

# 770 "data/maps/Route110/scripts.pory"
Route110_Text_WeCantTalkAboutAquaActivities:
# 771 "data/maps/Route110/scripts.pory"
	.string "TEAM AQUA's activities…\n"
# 772 "data/maps/Route110/scripts.pory"
	.string "We can't talk about them yet.$"
# 773 "data/maps/Route110/scripts.pory"

# 774 "data/maps/Route110/scripts.pory"
Route110_Text_KickUpARuckus:
# 775 "data/maps/Route110/scripts.pory"
	.string "I want to get going to SLATEPORT and\n"
# 776 "data/maps/Route110/scripts.pory"
	.string "kick up a ruckus!$"
# 777 "data/maps/Route110/scripts.pory"

# 778 "data/maps/Route110/scripts.pory"
Route110_Text_MyFirstJobInAqua:
# 779 "data/maps/Route110/scripts.pory"
	.string "This is my first job after joining\n"
# 780 "data/maps/Route110/scripts.pory"
	.string "TEAM AQUA. It's a little scary.$"
# 781 "data/maps/Route110/scripts.pory"

# 782 "data/maps/Route110/scripts.pory"
Route110_Text_AquaActionsBringSmiles:
# 783 "data/maps/Route110/scripts.pory"
	.string "TEAM AQUA's actions should bring\n"
# 784 "data/maps/Route110/scripts.pory"
	.string "smiles to people's faces!$"
# 785 "data/maps/Route110/scripts.pory"

# 786 "data/maps/Route110/scripts.pory"
Route110_Text_MayLetsBattle:
# 787 "data/maps/Route110/scripts.pory"
	.string "MAY: Hi, {PLAYER}{KUN}, long time no see!\p"
# 788 "data/maps/Route110/scripts.pory"
	.string "While I was searching for other\n"
# 789 "data/maps/Route110/scripts.pory"
	.string "POKéMON, my POKéMON grew stronger.\p"
# 790 "data/maps/Route110/scripts.pory"
	.string "So…\n"
# 791 "data/maps/Route110/scripts.pory"
	.string "How about a little battle?$"
# 792 "data/maps/Route110/scripts.pory"

# 793 "data/maps/Route110/scripts.pory"
Route110_Text_MayDefeated:
# 794 "data/maps/Route110/scripts.pory"
	.string "Yikes!\n"
# 795 "data/maps/Route110/scripts.pory"
	.string "You're better than I expected!$"
# 796 "data/maps/Route110/scripts.pory"

# 797 "data/maps/Route110/scripts.pory"
Route110_Text_MayTakeThis:
# 798 "data/maps/Route110/scripts.pory"
	.string "MAY: {PLAYER}{KUN}, you've been busy\n"
# 799 "data/maps/Route110/scripts.pory"
	.string "training, too, haven't you?\p"
# 800 "data/maps/Route110/scripts.pory"
	.string "I think you deserve a reward!\n"
# 801 "data/maps/Route110/scripts.pory"
	.string "This is from me!$"
# 802 "data/maps/Route110/scripts.pory"

# 803 "data/maps/Route110/scripts.pory"
Route110_Text_MayExplainItemfinder:
# 804 "data/maps/Route110/scripts.pory"
	.string "MAY: That's an ITEMFINDER.\p"
# 805 "data/maps/Route110/scripts.pory"
	.string "Try it out. If there is an item that's\n"
# 806 "data/maps/Route110/scripts.pory"
	.string "not visible, it emits a sound.\p"
# 807 "data/maps/Route110/scripts.pory"
	.string "Okay, {PLAYER}{KUN}, let's meet again!\p"
# 808 "data/maps/Route110/scripts.pory"
	.string "I know it's a little silly coming from\n"
# 809 "data/maps/Route110/scripts.pory"
	.string "me, but I think you should train a lot\l"
# 810 "data/maps/Route110/scripts.pory"
	.string "harder for the next time.$"
# 811 "data/maps/Route110/scripts.pory"

# 812 "data/maps/Route110/scripts.pory"
Route110_Text_BrendanLetsBattle:
# 813 "data/maps/Route110/scripts.pory"
	.string "BRENDAN: Hey, {PLAYER}.\n"
# 814 "data/maps/Route110/scripts.pory"
	.string "So this is where you were.\l"
# 815 "data/maps/Route110/scripts.pory"
	.string "How's it going?\p"
# 816 "data/maps/Route110/scripts.pory"
	.string "Have you been raising your POKéMON?\n"
# 817 "data/maps/Route110/scripts.pory"
	.string "I'll check for you.$"
# 818 "data/maps/Route110/scripts.pory"

# 819 "data/maps/Route110/scripts.pory"
Route110_Text_BrendanDefeated:
# 820 "data/maps/Route110/scripts.pory"
	.string "Hmm…\n"
# 821 "data/maps/Route110/scripts.pory"
	.string "You're pretty good.$"
# 822 "data/maps/Route110/scripts.pory"

# 823 "data/maps/Route110/scripts.pory"
Route110_Text_BrendanTakeThis:
# 824 "data/maps/Route110/scripts.pory"
	.string "BRENDAN: {PLAYER}, you've trained\n"
# 825 "data/maps/Route110/scripts.pory"
	.string "without me noticing…\p"
# 826 "data/maps/Route110/scripts.pory"
	.string "Good enough!\n"
# 827 "data/maps/Route110/scripts.pory"
	.string "Here, take this.$"
# 828 "data/maps/Route110/scripts.pory"

# 829 "data/maps/Route110/scripts.pory"
Route110_Text_BrendanExplainItemfinder:
# 830 "data/maps/Route110/scripts.pory"
	.string "BRENDAN: That's an ITEMFINDER.\p"
# 831 "data/maps/Route110/scripts.pory"
	.string "Use it to root around for items that\n"
# 832 "data/maps/Route110/scripts.pory"
	.string "aren't visible.\p"
# 833 "data/maps/Route110/scripts.pory"
	.string "If it senses something, it emits\n"
# 834 "data/maps/Route110/scripts.pory"
	.string "a sound.\p"
# 835 "data/maps/Route110/scripts.pory"
	.string "Anyway, I'm off to look for new\n"
# 836 "data/maps/Route110/scripts.pory"
	.string "POKéMON.$"
# 837 "data/maps/Route110/scripts.pory"

# 838 "data/maps/Route110/scripts.pory"
Route110_Text_RideBikeAtFullSpeed:
# 839 "data/maps/Route110/scripts.pory"
	.string "Wouldn't it be great to ride a BIKE\n"
# 840 "data/maps/Route110/scripts.pory"
	.string "at full speed on CYCLING ROAD?$"
# 841 "data/maps/Route110/scripts.pory"

# 842 "data/maps/Route110/scripts.pory"
Route110_Text_HairStreamsBehindMe:
# 843 "data/maps/Route110/scripts.pory"
	.string "How do you like the way my raven-\n"
# 844 "data/maps/Route110/scripts.pory"
	.string "colored hair streams behind me?\p"
# 845 "data/maps/Route110/scripts.pory"
	.string "I grew my hair out just for that.$"
# 846 "data/maps/Route110/scripts.pory"

# 847 "data/maps/Route110/scripts.pory"
Route110_Text_YouGotBikeFromRydel:
# 848 "data/maps/Route110/scripts.pory"
	.string "Oh, hey, you got that BIKE from RYDEL!\p"
# 849 "data/maps/Route110/scripts.pory"
	.string "Oh, it's glaringly obvious.\n"
# 850 "data/maps/Route110/scripts.pory"
	.string "It says right on your bike…\p"
# 851 "data/maps/Route110/scripts.pory"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
# 852 "data/maps/Route110/scripts.pory"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
# 853 "data/maps/Route110/scripts.pory"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
# 854 "data/maps/Route110/scripts.pory"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
# 855 "data/maps/Route110/scripts.pory"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
# 856 "data/maps/Route110/scripts.pory"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
# 857 "data/maps/Route110/scripts.pory"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
# 858 "data/maps/Route110/scripts.pory"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
# 859 "data/maps/Route110/scripts.pory"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL…\n"
# 860 "data/maps/Route110/scripts.pory"
	.string "That name's everywhere.\p"
# 861 "data/maps/Route110/scripts.pory"
	.string "You should ride it around all over\n"
# 862 "data/maps/Route110/scripts.pory"
	.string "the place--it's good advertising!$"
# 863 "data/maps/Route110/scripts.pory"

# 864 "data/maps/Route110/scripts.pory"
Route110_Text_TwoRoads:
# 865 "data/maps/Route110/scripts.pory"
	.string "The two roads, one above, one below…\p"
# 866 "data/maps/Route110/scripts.pory"
	.string "A road each for people and POKéMON.\n"
# 867 "data/maps/Route110/scripts.pory"
	.string "Perhaps that is right and fair.$"
# 868 "data/maps/Route110/scripts.pory"

# 869 "data/maps/Route110/scripts.pory"
Route110_Text_WalkOnTheLowRoad:
# 870 "data/maps/Route110/scripts.pory"
	.string "I don't have a BIKE, so I'll take\n"
# 871 "data/maps/Route110/scripts.pory"
	.string "a leisurely walk on the low road.$"
# 872 "data/maps/Route110/scripts.pory"

# 873 "data/maps/Route110/scripts.pory"
Route110_Text_BikeTechniques:
# 874 "data/maps/Route110/scripts.pory"
	.string "Learning techniques will make BIKE\n"
# 875 "data/maps/Route110/scripts.pory"
	.string "riding even more fun.\p"
# 876 "data/maps/Route110/scripts.pory"
	.string "There are some places that you can\n"
# 877 "data/maps/Route110/scripts.pory"
	.string "reach only by using a BIKE technique.$"
# 878 "data/maps/Route110/scripts.pory"

# 879 "data/maps/Route110/scripts.pory"
Route110_Text_WhichShouldIChoose:
# 880 "data/maps/Route110/scripts.pory"
	.string "Which should I choose?\p"
# 881 "data/maps/Route110/scripts.pory"
	.string "Make a beeline for MAUVILLE on\n"
# 882 "data/maps/Route110/scripts.pory"
	.string "CYCLING ROAD, or take the low road\l"
# 883 "data/maps/Route110/scripts.pory"
	.string "and look for POKéMON?$"
# 884 "data/maps/Route110/scripts.pory"

# 885 "data/maps/Route110/scripts.pory"
Route110_Text_CyclingChallengeResultSummary:
# 886 "data/maps/Route110/scripts.pory"
	.string "Number of collisions:\n"
# 887 "data/maps/Route110/scripts.pory"
	.string "… … {STR_VAR_1}!\p"
# 888 "data/maps/Route110/scripts.pory"
	.string "Total time:\n"
# 889 "data/maps/Route110/scripts.pory"
	.string "… … {STR_VAR_2}!$"
# 890 "data/maps/Route110/scripts.pory"

# 891 "data/maps/Route110/scripts.pory"
Route110_Text_ChallengeReactionBest:
# 892 "data/maps/Route110/scripts.pory"
	.string "Bravo! Splendid showing!\p"
# 893 "data/maps/Route110/scripts.pory"
	.string "Your love of cycling comes from deep\n"
# 894 "data/maps/Route110/scripts.pory"
	.string "within your heart.\l"
# 895 "data/maps/Route110/scripts.pory"
	.string "You've shaken me to my very soul!$"
# 896 "data/maps/Route110/scripts.pory"

# 897 "data/maps/Route110/scripts.pory"
Route110_Text_ChallengeReactionGood:
# 898 "data/maps/Route110/scripts.pory"
	.string "Your technique is remarkable.\p"
# 899 "data/maps/Route110/scripts.pory"
	.string "I suggest you speed up a bit while\n"
# 900 "data/maps/Route110/scripts.pory"
	.string "still avoiding collisions.$"
# 901 "data/maps/Route110/scripts.pory"

# 902 "data/maps/Route110/scripts.pory"
Route110_Text_ChallengeReactionOk:
# 903 "data/maps/Route110/scripts.pory"
	.string "I would consider you a work in\n"
# 904 "data/maps/Route110/scripts.pory"
	.string "progress.\p"
# 905 "data/maps/Route110/scripts.pory"
	.string "Still, I hope you don't forget the\n"
# 906 "data/maps/Route110/scripts.pory"
	.string "sheer pleasure of cycling.$"
# 907 "data/maps/Route110/scripts.pory"

# 908 "data/maps/Route110/scripts.pory"
Route110_Text_ChallengeReactionBad:
# 909 "data/maps/Route110/scripts.pory"
	.string "My word… Your cycling skills border\n"
# 910 "data/maps/Route110/scripts.pory"
	.string "on terrifying.\p"
# 911 "data/maps/Route110/scripts.pory"
	.string "Most certainly, you need much more\n"
# 912 "data/maps/Route110/scripts.pory"
	.string "practice riding.$"
# 913 "data/maps/Route110/scripts.pory"

# 914 "data/maps/Route110/scripts.pory"
Route110_Text_ChallengeReactionWorst:
# 915 "data/maps/Route110/scripts.pory"
	.string "…I am aghast…\p"
# 916 "data/maps/Route110/scripts.pory"
	.string "You're perhaps not cut out for this\n"
# 917 "data/maps/Route110/scripts.pory"
	.string "unfortunate cycling business.\p"
# 918 "data/maps/Route110/scripts.pory"
	.string "You ought to give serious thought to\n"
# 919 "data/maps/Route110/scripts.pory"
	.string "returning that BIKE to RYDEL.$"
# 920 "data/maps/Route110/scripts.pory"

# 921 "data/maps/Route110/scripts.pory"
Route110_Text_RatedForNumberOfCollisions:
# 922 "data/maps/Route110/scripts.pory"
	.string "This is CYCLING ROAD.\p"
# 923 "data/maps/Route110/scripts.pory"
	.string "If you were to ride from MAUVILLE to\n"
# 924 "data/maps/Route110/scripts.pory"
	.string "SLATEPORT on a MACH BIKE, you would\l"
# 925 "data/maps/Route110/scripts.pory"
	.string "be rated for the number of collisions\l"
# 926 "data/maps/Route110/scripts.pory"
	.string "and your total time.$"
# 927 "data/maps/Route110/scripts.pory"

# 928 "data/maps/Route110/scripts.pory"
Route110_Text_AlwaysAimHigher:
# 929 "data/maps/Route110/scripts.pory"
	.string "Regardless of the results, I count on\n"
# 930 "data/maps/Route110/scripts.pory"
	.string "seeing more challenges from you.\l"
# 931 "data/maps/Route110/scripts.pory"
	.string "Always aim higher!$"
# 932 "data/maps/Route110/scripts.pory"

# 933 "data/maps/Route110/scripts.pory"
Route110_Text_AcroBikesDoNotQualify:
# 934 "data/maps/Route110/scripts.pory"
	.string "On this CYCLING ROAD, those riding\n"
# 935 "data/maps/Route110/scripts.pory"
	.string "MACH BIKES are rated for their number\l"
# 936 "data/maps/Route110/scripts.pory"
	.string "of collisions and their total times.\p"
# 937 "data/maps/Route110/scripts.pory"
	.string "ACRO BIKES do not qualify for rating.\n"
# 938 "data/maps/Route110/scripts.pory"
	.string "They are easy to turn, so it's not fair.$"
# 939 "data/maps/Route110/scripts.pory"

# 940 "data/maps/Route110/scripts.pory"
Route110_Text_SlateportCitySign:
# 941 "data/maps/Route110/scripts.pory"
	.string "ROUTE 110\n"
# 942 "data/maps/Route110/scripts.pory"
	.string "{DOWN_ARROW} SLATEPORT CITY$"
# 943 "data/maps/Route110/scripts.pory"

# 944 "data/maps/Route110/scripts.pory"
Route110_Text_CyclingRoadSign:
# 945 "data/maps/Route110/scripts.pory"
	.string "SEASIDE CYCLING ROAD$"
# 946 "data/maps/Route110/scripts.pory"

# 947 "data/maps/Route110/scripts.pory"
Route110_Text_AquaWasHere:
# 948 "data/maps/Route110/scripts.pory"
	.string "“TEAM AQUA was here!”\p"
# 949 "data/maps/Route110/scripts.pory"
	.string "Someone painted that onto this sign,\n"
# 950 "data/maps/Route110/scripts.pory"
	.string "but then someone else painted over it.\p"
# 951 "data/maps/Route110/scripts.pory"
	.string "“TEAM MAGMA rules!” is what it\n"
# 952 "data/maps/Route110/scripts.pory"
	.string "says now.$"
# 953 "data/maps/Route110/scripts.pory"

# 954 "data/maps/Route110/scripts.pory"
Route110_Text_Route103Sign:
# 955 "data/maps/Route110/scripts.pory"
	.string "ROUTE 110\n"
# 956 "data/maps/Route110/scripts.pory"
	.string "{LEFT_ARROW} ROUTE 103$"
# 957 "data/maps/Route110/scripts.pory"

# 958 "data/maps/Route110/scripts.pory"
Route110_Text_SeasideParkingSign:
# 959 "data/maps/Route110/scripts.pory"
	.string "SEASIDE PARKING$"
# 960 "data/maps/Route110/scripts.pory"

# 961 "data/maps/Route110/scripts.pory"
Route110_Text_MauvilleCitySign:
# 962 "data/maps/Route110/scripts.pory"
	.string "ROUTE 110\n"
# 963 "data/maps/Route110/scripts.pory"
	.string "{UP_ARROW} MAUVILLE CITY$"
# 964 "data/maps/Route110/scripts.pory"

# 965 "data/maps/Route110/scripts.pory"
Route110_Text_TrainerTipsPrlzSleep:
# 966 "data/maps/Route110/scripts.pory"
	.string "TRAINER TIPS\p"
# 967 "data/maps/Route110/scripts.pory"
	.string "The foe can be made helpless by\n"
# 968 "data/maps/Route110/scripts.pory"
	.string "paralyzing it or causing it to sleep.\p"
# 969 "data/maps/Route110/scripts.pory"
	.string "It is an important technique for\n"
# 970 "data/maps/Route110/scripts.pory"
	.string "POKéMON battles.$"
# 971 "data/maps/Route110/scripts.pory"

# 972 "data/maps/Route110/scripts.pory"
Route110_Text_TrainerTipsRegisterItems:
# 973 "data/maps/Route110/scripts.pory"
	.string "TRAINER TIPS\p"
# 974 "data/maps/Route110/scripts.pory"
	.string "The items in the BAG can be reorganized\n"
# 975 "data/maps/Route110/scripts.pory"
	.string "by pressing SELECT.$"
# 976 "data/maps/Route110/scripts.pory"

# 977 "data/maps/Route110/scripts.pory"
Route110_Text_TrickHouseSign:
# 978 "data/maps/Route110/scripts.pory"
	.string "“Three steps {RIGHT_ARROW} and two steps {UP_ARROW}\n"
# 979 "data/maps/Route110/scripts.pory"
	.string "to reach the wondrous TRICK HOUSE.”$"
# 980 "data/maps/Route110/scripts.pory"

# 981 "data/maps/Route110/scripts.pory"
Route110_Text_BestRecord:
# 982 "data/maps/Route110/scripts.pory"
	.string "THE BEST RECORD TO DATE…\p"
# 983 "data/maps/Route110/scripts.pory"
	.string "No. of collisions: {STR_VAR_1}\p"
# 984 "data/maps/Route110/scripts.pory"
	.string "Elapsed time: {STR_VAR_2}$"
# 985 "data/maps/Route110/scripts.pory"

# 986 "data/maps/Route110/scripts.pory"
Route110_Text_ThereIsNoRecord:
# 987 "data/maps/Route110/scripts.pory"
	.string "THE BEST RECORD TO DATE…\p"
# 988 "data/maps/Route110/scripts.pory"
	.string "No one seems to have taken the\n"
# 989 "data/maps/Route110/scripts.pory"
	.string "challenge. There is no record…$"
# 990 "data/maps/Route110/scripts.pory"

# 991 "data/maps/Route110/scripts.pory"
Route110_Text_ImagineSeeingYouHere:
# 992 "data/maps/Route110/scripts.pory"
	.string "PROF. BIRCH: Oh, {PLAYER}{KUN}!\n"
# 993 "data/maps/Route110/scripts.pory"
	.string "Imagine seeing you here!\p"
# 994 "data/maps/Route110/scripts.pory"
	.string "And where might my {RIVAL} be?$"
# 995 "data/maps/Route110/scripts.pory"

# 996 "data/maps/Route110/scripts.pory"
Route110_Text_HeardYouInstallMatchCall:
# 997 "data/maps/Route110/scripts.pory"
	.string "Oh, I see!\n"
# 998 "data/maps/Route110/scripts.pory"
	.string "You two are running separately.\l"
# 999 "data/maps/Route110/scripts.pory"
	.string "Well, that's fine.\p"
# 1000 "data/maps/Route110/scripts.pory"
	.string "Oh, yes, I heard that your POKéNAV\n"
# 1001 "data/maps/Route110/scripts.pory"
	.string "had the MATCH CALL system installed.\p"
# 1002 "data/maps/Route110/scripts.pory"
	.string "Well, then, I should register you in\n"
# 1003 "data/maps/Route110/scripts.pory"
	.string "my POKéNAV as well.\p"
# 1004 "data/maps/Route110/scripts.pory"
	.string "That way, even when we're apart,\n"
# 1005 "data/maps/Route110/scripts.pory"
	.string "I can rate your POKéDEX anytime.\p"
# 1006 "data/maps/Route110/scripts.pory"
	.string "… … … … … …$"
# 1007 "data/maps/Route110/scripts.pory"

# 1008 "data/maps/Route110/scripts.pory"
Route110_Text_RegisteredBirchInPokenav:
# 1009 "data/maps/Route110/scripts.pory"
	.string "Registered PROF. BIRCH\n"
# 1010 "data/maps/Route110/scripts.pory"
	.string "in the POKéNAV.$"
# 1011 "data/maps/Route110/scripts.pory"

# 1012 "data/maps/Route110/scripts.pory"
Route110_Text_KeepAnEyeOutForRival:
# 1013 "data/maps/Route110/scripts.pory"
	.string "PROF. BIRCH: {PLAYER}{KUN}…\p"
# 1014 "data/maps/Route110/scripts.pory"
	.string "Please keep an eye out for my {RIVAL}.\n"
# 1015 "data/maps/Route110/scripts.pory"
	.string "… … … … … …\p"
# 1016 "data/maps/Route110/scripts.pory"
	.string "Well, I had better get going.\n"
# 1017 "data/maps/Route110/scripts.pory"
	.string "See you again, {PLAYER}{KUN}!$"
