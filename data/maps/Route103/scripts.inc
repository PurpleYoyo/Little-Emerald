# 1 "data/maps/Route103/scripts.pory"

# 2 "data/maps/Route103/scripts.pory"
.set LOCALID_RIVAL, 2
# 3 "data/maps/Route103/scripts.pory"
.set LOCALID_SQUIRTLE, 21
# 4 "data/maps/Route103/scripts.pory"
.set LOCALID_SCORBUNNY, 22
# 5 "data/maps/Route103/scripts.pory"
.set LOCALID_SNIVY, 23
# 6 "data/maps/Route103/scripts.pory"

# 7 "data/maps/Route103/scripts.pory"
Route103_MapScripts::
# 8 "data/maps/Route103/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route103_OnTransition
# 9 "data/maps/Route103/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route103_OnLoad
# 10 "data/maps/Route103/scripts.pory"
	.byte 0
# 11 "data/maps/Route103/scripts.pory"

# 12 "data/maps/Route103/scripts.pory"
Route103_OnTransition:
# 13 "data/maps/Route103/scripts.pory"
	call_if_eq VAR_STARTER_MON, 0, RemoveStarters_Snivy
# 14 "data/maps/Route103/scripts.pory"
	call_if_eq VAR_STARTER_MON, 1, RemoveStarters_Scorbunny
# 15 "data/maps/Route103/scripts.pory"
	call_if_eq VAR_STARTER_MON, 2, RemoveStarters_Squirtle
# 16 "data/maps/Route103/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 17 "data/maps/Route103/scripts.pory"
	call ProfBirch_EventScript_UpdateLocation
# 18 "data/maps/Route103/scripts.pory"
	end
# 19 "data/maps/Route103/scripts.pory"

# 20 "data/maps/Route103/scripts.pory"
Route103_OnLoad:
# 21 "data/maps/Route103/scripts.pory"
	call Route103_EventScript_OpenAlteringCave
# 22 "data/maps/Route103/scripts.pory"
	end
# 23 "data/maps/Route103/scripts.pory"

# 24 "data/maps/Route103/scripts.pory"
RemoveStarters_Snivy::
# 25 "data/maps/Route103/scripts.pory"
	removeobject LOCALID_SNIVY
# 26 "data/maps/Route103/scripts.pory"
	removeobject LOCALID_SQUIRTLE
# 27 "data/maps/Route103/scripts.pory"
	setflag FLAG_HIDE_RIVALS_SNIVY
# 28 "data/maps/Route103/scripts.pory"
	setflag FLAG_HIDE_RIVALS_SQUIRTLE
# 29 "data/maps/Route103/scripts.pory"
	return
# 30 "data/maps/Route103/scripts.pory"

# 31 "data/maps/Route103/scripts.pory"
RemoveStarters_Scorbunny::
# 32 "data/maps/Route103/scripts.pory"
	removeobject LOCALID_SCORBUNNY
# 33 "data/maps/Route103/scripts.pory"
	removeobject LOCALID_SNIVY
# 34 "data/maps/Route103/scripts.pory"
	setflag FLAG_HIDE_RIVALS_SCORBUNNY
# 35 "data/maps/Route103/scripts.pory"
	setflag FLAG_HIDE_RIVALS_SNIVY
# 36 "data/maps/Route103/scripts.pory"
	return
# 37 "data/maps/Route103/scripts.pory"

# 38 "data/maps/Route103/scripts.pory"
RemoveStarters_Squirtle::
# 39 "data/maps/Route103/scripts.pory"
	removeobject LOCALID_SCORBUNNY
# 40 "data/maps/Route103/scripts.pory"
	removeobject LOCALID_SQUIRTLE
# 41 "data/maps/Route103/scripts.pory"
	setflag FLAG_HIDE_RIVALS_SCORBUNNY
# 42 "data/maps/Route103/scripts.pory"
	setflag FLAG_HIDE_RIVALS_SQUIRTLE
# 43 "data/maps/Route103/scripts.pory"
	return
# 44 "data/maps/Route103/scripts.pory"

# 45 "data/maps/Route103/scripts.pory"
Route103_EventScript_OpenAlteringCave::
# 46 "data/maps/Route103/scripts.pory"
	setmetatile 45, 5, METATILE_General_CaveEntrance_Top, TRUE
# 47 "data/maps/Route103/scripts.pory"
	setmetatile 45, 6, METATILE_General_CaveEntrance_Bottom, FALSE
# 48 "data/maps/Route103/scripts.pory"
	return
# 49 "data/maps/Route103/scripts.pory"

# 50 "data/maps/Route103/scripts.pory"
Route103_EventScript_Rival::
# 51 "data/maps/Route103/scripts.pory"
	lockall
# 52 "data/maps/Route103/scripts.pory"
	checkplayergender
# 53 "data/maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, Route103_EventScript_RivalMay
# 54 "data/maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, Route103_EventScript_RivalBrendan
# 55 "data/maps/Route103/scripts.pory"
	end
# 56 "data/maps/Route103/scripts.pory"

# 57 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalMay::
# 58 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MayRoute103Pokemon, MSGBOX_DEFAULT
# 59 "data/maps/Route103/scripts.pory"
	closemessage
# 60 "data/maps/Route103/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 61 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 62 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 63 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 64 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 65 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 66 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 67 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MayLetsBattle, MSGBOX_DEFAULT
# 68 "data/maps/Route103/scripts.pory"
	playse SE_M_BATON_PASS
# 69 "data/maps/Route103/scripts.pory"
	waitse
# 70 "data/maps/Route103/scripts.pory"
	removeobject LOCALID_SCORBUNNY
# 71 "data/maps/Route103/scripts.pory"
	removeobject LOCALID_SQUIRTLE
# 72 "data/maps/Route103/scripts.pory"
	removeobject LOCALID_SNIVY
# 73 "data/maps/Route103/scripts.pory"
	setflag FLAG_HIDE_RIVALS_SCORBUNNY
# 74 "data/maps/Route103/scripts.pory"
	setflag FLAG_HIDE_RIVALS_SNIVY
# 75 "data/maps/Route103/scripts.pory"
	setflag FLAG_HIDE_RIVALS_SQUIRTLE
# 76 "data/maps/Route103/scripts.pory"
	switch VAR_STARTER_MON
# 77 "data/maps/Route103/scripts.pory"
	case 0, Route103_EventScript_StartMayBattleTreecko
# 78 "data/maps/Route103/scripts.pory"
	case 1, Route103_EventScript_StartMayBattleTorchic
# 79 "data/maps/Route103/scripts.pory"
	case 2, Route103_EventScript_StartMayBattleMudkip
# 80 "data/maps/Route103/scripts.pory"
	end
# 81 "data/maps/Route103/scripts.pory"

# 82 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalBrendan::
# 83 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_BrendanRoute103Pokemon, MSGBOX_DEFAULT
# 84 "data/maps/Route103/scripts.pory"
	closemessage
# 85 "data/maps/Route103/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 86 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 87 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 88 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 89 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 90 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 91 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 92 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_BrendanLetsBattle, MSGBOX_DEFAULT
# 93 "data/maps/Route103/scripts.pory"
	playse SE_M_BATON_PASS
# 94 "data/maps/Route103/scripts.pory"
	waitse
# 95 "data/maps/Route103/scripts.pory"
	removeobject LOCALID_SCORBUNNY
# 96 "data/maps/Route103/scripts.pory"
	removeobject LOCALID_SQUIRTLE
# 97 "data/maps/Route103/scripts.pory"
	removeobject LOCALID_SNIVY
# 98 "data/maps/Route103/scripts.pory"
	setflag FLAG_HIDE_RIVALS_SCORBUNNY
# 99 "data/maps/Route103/scripts.pory"
	setflag FLAG_HIDE_RIVALS_SNIVY
# 100 "data/maps/Route103/scripts.pory"
	setflag FLAG_HIDE_RIVALS_SQUIRTLE
# 101 "data/maps/Route103/scripts.pory"
	switch VAR_STARTER_MON
# 102 "data/maps/Route103/scripts.pory"
	case 0, Route103_EventScript_StartBrendanBattleTreecko
# 103 "data/maps/Route103/scripts.pory"
	case 1, Route103_EventScript_StartBrendanBattleTorchic
# 104 "data/maps/Route103/scripts.pory"
	case 2, Route103_EventScript_StartBrendanBattleMudkip
# 105 "data/maps/Route103/scripts.pory"
	end
# 106 "data/maps/Route103/scripts.pory"

# 107 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartMayBattleTreecko::
# 108 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Route103_Text_MayDefeated
# 109 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterMayBattle
# 110 "data/maps/Route103/scripts.pory"
	end
# 111 "data/maps/Route103/scripts.pory"

# 112 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartMayBattleTorchic::
# 113 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TORCHIC, Route103_Text_MayDefeated
# 114 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterMayBattle
# 115 "data/maps/Route103/scripts.pory"
	end
# 116 "data/maps/Route103/scripts.pory"

# 117 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartMayBattleMudkip::
# 118 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_MUDKIP, Route103_Text_MayDefeated
# 119 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterMayBattle
# 120 "data/maps/Route103/scripts.pory"
	end
# 121 "data/maps/Route103/scripts.pory"

# 122 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartBrendanBattleTreecko::
# 123 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TREECKO, Route103_Text_BrendanDefeated
# 124 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterBrendanBattle
# 125 "data/maps/Route103/scripts.pory"
	end
# 126 "data/maps/Route103/scripts.pory"

# 127 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartBrendanBattleTorchic::
# 128 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TORCHIC, Route103_Text_BrendanDefeated
# 129 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterBrendanBattle
# 130 "data/maps/Route103/scripts.pory"
	end
# 131 "data/maps/Route103/scripts.pory"

# 132 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartBrendanBattleMudkip::
# 133 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_MUDKIP, Route103_Text_BrendanDefeated
# 134 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterBrendanBattle
# 135 "data/maps/Route103/scripts.pory"
	end
# 136 "data/maps/Route103/scripts.pory"

# 137 "data/maps/Route103/scripts.pory"
Route103_EventScript_AfterMayBattle::
# 138 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MayTimeToHeadBack, MSGBOX_DEFAULT
# 139 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalExit
# 140 "data/maps/Route103/scripts.pory"
	end
# 141 "data/maps/Route103/scripts.pory"

# 142 "data/maps/Route103/scripts.pory"
Route103_EventScript_AfterBrendanBattle::
# 143 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_BrendanTimeToHeadBack, MSGBOX_DEFAULT
# 144 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalExit
# 145 "data/maps/Route103/scripts.pory"
	end
# 146 "data/maps/Route103/scripts.pory"

# 147 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalExit::
# 148 "data/maps/Route103/scripts.pory"
	closemessage
# 149 "data/maps/Route103/scripts.pory"
	switch VAR_FACING
# 150 "data/maps/Route103/scripts.pory"
	case DIR_SOUTH, Route103_EventScript_RivalExitFacingSouth
# 151 "data/maps/Route103/scripts.pory"
	case DIR_NORTH, Route103_EventScript_RivalExitFacingNorth
# 152 "data/maps/Route103/scripts.pory"
	case DIR_WEST, Route103_EventScript_RivalExitFacingEastOrWest
# 153 "data/maps/Route103/scripts.pory"
	case DIR_EAST, Route103_EventScript_RivalExitFacingEastOrWest
# 154 "data/maps/Route103/scripts.pory"
	end
# 155 "data/maps/Route103/scripts.pory"

# 156 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingNorth::
# 157 "data/maps/Route103/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingNorth
# 158 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExitFacingNorth1
# 159 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 160 "data/maps/Route103/scripts.pory"
	playse SE_LEDGE
# 161 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExitFacingNorth2
# 162 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 163 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 164 "data/maps/Route103/scripts.pory"
	end
# 165 "data/maps/Route103/scripts.pory"

# 166 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingEastOrWest::
# 167 "data/maps/Route103/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingEastOrWest
# 168 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit1
# 169 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 170 "data/maps/Route103/scripts.pory"
	playse SE_LEDGE
# 171 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit2
# 172 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 173 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 174 "data/maps/Route103/scripts.pory"
	end
# 175 "data/maps/Route103/scripts.pory"

# 176 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingSouth::
# 177 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit1
# 178 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 179 "data/maps/Route103/scripts.pory"
	playse SE_LEDGE
# 180 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit2
# 181 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 182 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 183 "data/maps/Route103/scripts.pory"
	end
# 184 "data/maps/Route103/scripts.pory"

# 185 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalEnd::
# 186 "data/maps/Route103/scripts.pory"
	removeobject LOCALID_RIVAL
# 187 "data/maps/Route103/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 4
# 188 "data/maps/Route103/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
# 189 "data/maps/Route103/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE103
# 190 "data/maps/Route103/scripts.pory"
	setvar VAR_OLDALE_RIVAL_STATE, 1
# 191 "data/maps/Route103/scripts.pory"
	clearflag FLAG_HIDE_OLDALE_TOWN_RIVAL
# 192 "data/maps/Route103/scripts.pory"
	savebgm MUS_DUMMY
# 193 "data/maps/Route103/scripts.pory"
	fadedefaultbgm
# 194 "data/maps/Route103/scripts.pory"
	releaseall
# 195 "data/maps/Route103/scripts.pory"
	end
# 196 "data/maps/Route103/scripts.pory"

# 197 "data/maps/Route103/scripts.pory"
Route103_Movement_RivalExitFacingNorth1:
# 198 "data/maps/Route103/scripts.pory"
	walk_left
# 199 "data/maps/Route103/scripts.pory"
	walk_down
# 200 "data/maps/Route103/scripts.pory"
	step_end
# 201 "data/maps/Route103/scripts.pory"

# 202 "data/maps/Route103/scripts.pory"
Route103_Movement_RivalExitFacingNorth2:
# 203 "data/maps/Route103/scripts.pory"
	jump_2_down
# 204 "data/maps/Route103/scripts.pory"
	delay_16
# 205 "data/maps/Route103/scripts.pory"
	walk_down
# 206 "data/maps/Route103/scripts.pory"
	walk_down
# 207 "data/maps/Route103/scripts.pory"
	walk_down
# 208 "data/maps/Route103/scripts.pory"
	walk_down
# 209 "data/maps/Route103/scripts.pory"
	step_end
# 210 "data/maps/Route103/scripts.pory"

# 211 "data/maps/Route103/scripts.pory"
Route103_Movement_WatchRivalExitFacingNorth:
# 212 "data/maps/Route103/scripts.pory"
	delay_16
# 213 "data/maps/Route103/scripts.pory"
	delay_4
# 214 "data/maps/Route103/scripts.pory"
	walk_in_place_faster_left
# 215 "data/maps/Route103/scripts.pory"
	delay_16
# 216 "data/maps/Route103/scripts.pory"
	walk_in_place_faster_down
# 217 "data/maps/Route103/scripts.pory"
	step_end
# 218 "data/maps/Route103/scripts.pory"

# 219 "data/maps/Route103/scripts.pory"
Route103_Movement_RivalExit1:
# 220 "data/maps/Route103/scripts.pory"
	walk_down
# 221 "data/maps/Route103/scripts.pory"
	step_end
# 222 "data/maps/Route103/scripts.pory"

# 223 "data/maps/Route103/scripts.pory"
Route103_Movement_RivalExit2:
# 224 "data/maps/Route103/scripts.pory"
	jump_2_down
# 225 "data/maps/Route103/scripts.pory"
	delay_16
# 226 "data/maps/Route103/scripts.pory"
	walk_down
# 227 "data/maps/Route103/scripts.pory"
	walk_down
# 228 "data/maps/Route103/scripts.pory"
	walk_down
# 229 "data/maps/Route103/scripts.pory"
	step_end
# 230 "data/maps/Route103/scripts.pory"

# 231 "data/maps/Route103/scripts.pory"
Route103_Movement_WatchRivalExitFacingEastOrWest:
# 232 "data/maps/Route103/scripts.pory"
	delay_16
# 233 "data/maps/Route103/scripts.pory"
	walk_in_place_faster_down
# 234 "data/maps/Route103/scripts.pory"
	step_end
# 235 "data/maps/Route103/scripts.pory"

# 236 "data/maps/Route103/scripts.pory"
Route103_EventScript_Boy::
# 237 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_ShouldHaveBroughtPotion, MSGBOX_NPC
# 238 "data/maps/Route103/scripts.pory"
	end
# 239 "data/maps/Route103/scripts.pory"

# 240 "data/maps/Route103/scripts.pory"
Route103_EventScript_Man::
# 241 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_ShortcutToOldale, MSGBOX_NPC
# 242 "data/maps/Route103/scripts.pory"
	end
# 243 "data/maps/Route103/scripts.pory"

# 244 "data/maps/Route103/scripts.pory"
Route103_EventScript_RouteSign::
# 245 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_RouteSign, MSGBOX_SIGN
# 246 "data/maps/Route103/scripts.pory"
	end
# 247 "data/maps/Route103/scripts.pory"

# 248 "data/maps/Route103/scripts.pory"
Route103_EventScript_Daisy::
# 249 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_DAISY, Route103_Text_DaisyIntro, Route103_Text_DaisyDefeated
# 250 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_DaisyPostBattle, MSGBOX_AUTOCLOSE
# 251 "data/maps/Route103/scripts.pory"
	end
# 252 "data/maps/Route103/scripts.pory"

# 253 "data/maps/Route103/scripts.pory"
Route103_EventScript_Amy::
# 254 "data/maps/Route103/scripts.pory"
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyIntro, Route103_Text_AmyDefeated, Route103_Text_AmyNotEnoughPokemon, Route102_EventScript_AmyRegisterMatchCallAfterBattle
# 255 "data/maps/Route103/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 256 "data/maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_AmyRematch
# 257 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyPostBattle, MSGBOX_AUTOCLOSE
# 258 "data/maps/Route103/scripts.pory"
	end
# 259 "data/maps/Route103/scripts.pory"

# 260 "data/maps/Route103/scripts.pory"
Route102_EventScript_AmyRegisterMatchCallAfterBattle::
# 261 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
# 262 "data/maps/Route103/scripts.pory"
	register_matchcall TRAINER_AMY_AND_LIV_1
# 263 "data/maps/Route103/scripts.pory"
	release
# 264 "data/maps/Route103/scripts.pory"
	end
# 265 "data/maps/Route103/scripts.pory"

# 266 "data/maps/Route103/scripts.pory"
Route102_EventScript_AmyRematch::
# 267 "data/maps/Route103/scripts.pory"
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyRematchIntro, Route103_Text_AmyRematchDefeated, Route103_Text_AmyRematchNotEnoughPokemon
# 268 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyRematchPostBattle, MSGBOX_AUTOCLOSE
# 269 "data/maps/Route103/scripts.pory"
	end
# 270 "data/maps/Route103/scripts.pory"

# 271 "data/maps/Route103/scripts.pory"
Route103_EventScript_Liv::
# 272 "data/maps/Route103/scripts.pory"
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivIntro, Route103_Text_LivDefeated, Route103_Text_LivNotEnoughPokemon, Route102_EventScript_LivRegisterMatchCallAfterBattle
# 273 "data/maps/Route103/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 274 "data/maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_LivRematch
# 275 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_LivPostBattle, MSGBOX_AUTOCLOSE
# 276 "data/maps/Route103/scripts.pory"
	end
# 277 "data/maps/Route103/scripts.pory"

# 278 "data/maps/Route103/scripts.pory"
Route102_EventScript_LivRegisterMatchCallAfterBattle::
# 279 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
# 280 "data/maps/Route103/scripts.pory"
	register_matchcall TRAINER_AMY_AND_LIV_1
# 281 "data/maps/Route103/scripts.pory"
	release
# 282 "data/maps/Route103/scripts.pory"
	end
# 283 "data/maps/Route103/scripts.pory"

# 284 "data/maps/Route103/scripts.pory"
Route102_EventScript_LivRematch::
# 285 "data/maps/Route103/scripts.pory"
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivRematchIntro, Route103_Text_LivRematchDefeated, Route103_Text_LivRematchNotEnoughPokemon
# 286 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_LivRematchPostBattle, MSGBOX_AUTOCLOSE
# 287 "data/maps/Route103/scripts.pory"
	end
# 288 "data/maps/Route103/scripts.pory"

# 289 "data/maps/Route103/scripts.pory"
Route103_EventScript_Andrew::
# 290 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_ANDREW, Route103_Text_AndrewIntro, Route103_Text_AndrewDefeated
# 291 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_AndrewPostBattle, MSGBOX_AUTOCLOSE
# 292 "data/maps/Route103/scripts.pory"
	end
# 293 "data/maps/Route103/scripts.pory"

# 294 "data/maps/Route103/scripts.pory"
Route103_EventScript_Miguel::
# 295 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_MIGUEL_1, Route103_Text_MiguelIntro, Route103_Text_MiguelDefeated, Route102_EventScript_MiguelRegisterMatchCallAfterBattle
# 296 "data/maps/Route103/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 297 "data/maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route103_EventScript_MiguelRematch
# 298 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelPostBattle, MSGBOX_DEFAULT
# 299 "data/maps/Route103/scripts.pory"
	release
# 300 "data/maps/Route103/scripts.pory"
	end
# 301 "data/maps/Route103/scripts.pory"

# 302 "data/maps/Route103/scripts.pory"
Route102_EventScript_MiguelRegisterMatchCallAfterBattle::
# 303 "data/maps/Route103/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 304 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 305 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelRegister, MSGBOX_DEFAULT
# 306 "data/maps/Route103/scripts.pory"
	register_matchcall TRAINER_MIGUEL_1
# 307 "data/maps/Route103/scripts.pory"
	release
# 308 "data/maps/Route103/scripts.pory"
	end
# 309 "data/maps/Route103/scripts.pory"

# 310 "data/maps/Route103/scripts.pory"
Route103_EventScript_MiguelRematch::
# 311 "data/maps/Route103/scripts.pory"
	trainerbattle_rematch TRAINER_MIGUEL_1, Route103_Text_MiguelRematchIntro, Route103_Text_MiguelRematchDefeated
# 312 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelRematchPostBattle, MSGBOX_AUTOCLOSE
# 313 "data/maps/Route103/scripts.pory"
	end
# 314 "data/maps/Route103/scripts.pory"

# 315 "data/maps/Route103/scripts.pory"
Route103_EventScript_Marcos::
# 316 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_MARCOS, Route103_Text_MarcosIntro, Route103_Text_MarcosDefeated
# 317 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
# 318 "data/maps/Route103/scripts.pory"
	end
# 319 "data/maps/Route103/scripts.pory"

# 320 "data/maps/Route103/scripts.pory"
Route103_EventScript_Rhett::
# 321 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_RHETT, Route103_Text_RhettIntro, Route103_Text_RhettDefeated
# 322 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_RhettPostBattle, MSGBOX_AUTOCLOSE
# 323 "data/maps/Route103/scripts.pory"
	end
# 324 "data/maps/Route103/scripts.pory"

# 325 "data/maps/Route103/scripts.pory"
Route103_EventScript_Pete::
# 326 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_PETE, Route103_Text_PeteIntro, Route103_Text_PeteDefeated
# 327 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_PetePostBattle, MSGBOX_AUTOCLOSE
# 328 "data/maps/Route103/scripts.pory"
	end
# 329 "data/maps/Route103/scripts.pory"

# 330 "data/maps/Route103/scripts.pory"
Route103_EventScript_Isabelle::
# 331 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_ISABELLE, Route103_Text_IsabelleIntro, Route103_Text_IsabelleDefeated
# 332 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_IsabellePostBattle, MSGBOX_AUTOCLOSE
# 333 "data/maps/Route103/scripts.pory"
	end
# 334 "data/maps/Route103/scripts.pory"

# 335 "data/maps/Route103/scripts.pory"
Route103_Text_MayRoute103Pokemon:
# 336 "data/maps/Route103/scripts.pory"
	.string "MAY: Let's see… The POKéMON found\n"
# 337 "data/maps/Route103/scripts.pory"
	.string "on ROUTE 103 include…$"
# 338 "data/maps/Route103/scripts.pory"

# 339 "data/maps/Route103/scripts.pory"
Route103_Text_MayLetsBattle:
# 340 "data/maps/Route103/scripts.pory"
	.string "Oh, hi, {PLAYER}{KUN}!\p"
# 341 "data/maps/Route103/scripts.pory"
	.string "…Oh, I see, my dad gave you\n"
# 342 "data/maps/Route103/scripts.pory"
	.string "a POKéMON as a gift.\p"
# 343 "data/maps/Route103/scripts.pory"
	.string "Since we're here, let's have a quick\n"
# 344 "data/maps/Route103/scripts.pory"
	.string "battle!\p"
# 345 "data/maps/Route103/scripts.pory"
	.string "I'll give you a taste of what being\n"
# 346 "data/maps/Route103/scripts.pory"
	.string "a TRAINER is like.$"
# 347 "data/maps/Route103/scripts.pory"

# 348 "data/maps/Route103/scripts.pory"
Route103_Text_MayDefeated:
# 349 "data/maps/Route103/scripts.pory"
	.string "Wow! That's great!\n"
# 350 "data/maps/Route103/scripts.pory"
	.string "{PLAYER}{KUN}, you're pretty good!$"
# 351 "data/maps/Route103/scripts.pory"

# 352 "data/maps/Route103/scripts.pory"
Route103_Text_MayTimeToHeadBack:
# 353 "data/maps/Route103/scripts.pory"
	.string "MAY: I think I know why my dad has\n"
# 354 "data/maps/Route103/scripts.pory"
	.string "an eye out for you now.\p"
# 355 "data/maps/Route103/scripts.pory"
	.string "I mean, you just got that POKéMON,\n"
# 356 "data/maps/Route103/scripts.pory"
	.string "but it already likes you.\p"
# 357 "data/maps/Route103/scripts.pory"
	.string "You might be able to befriend any\n"
# 358 "data/maps/Route103/scripts.pory"
	.string "kind of POKéMON easily.\p"
# 359 "data/maps/Route103/scripts.pory"
	.string "Well, it's time to head back to\n"
# 360 "data/maps/Route103/scripts.pory"
	.string "the LAB.$"
# 361 "data/maps/Route103/scripts.pory"

# 362 "data/maps/Route103/scripts.pory"
Route103_Text_BrendanRoute103Pokemon:
# 363 "data/maps/Route103/scripts.pory"
	.string "BRENDAN: Okay, so it's this one and\n"
# 364 "data/maps/Route103/scripts.pory"
	.string "that one that live on ROUTE 103…$"
# 365 "data/maps/Route103/scripts.pory"

# 366 "data/maps/Route103/scripts.pory"
Route103_Text_BrendanLetsBattle:
# 367 "data/maps/Route103/scripts.pory"
	.string "Hey, it's {PLAYER}!\p"
# 368 "data/maps/Route103/scripts.pory"
	.string "…Oh, yeah, Dad gave you a POKéMON.\p"
# 369 "data/maps/Route103/scripts.pory"
	.string "Since we're here, how about a little\n"
# 370 "data/maps/Route103/scripts.pory"
	.string "battle?\p"
# 371 "data/maps/Route103/scripts.pory"
	.string "I'll teach you what being a TRAINER's\n"
# 372 "data/maps/Route103/scripts.pory"
	.string "about!$"
# 373 "data/maps/Route103/scripts.pory"

# 374 "data/maps/Route103/scripts.pory"
Route103_Text_BrendanDefeated:
# 375 "data/maps/Route103/scripts.pory"
	.string "Huh, {PLAYER}, you're not too shabby.$"
# 376 "data/maps/Route103/scripts.pory"

# 377 "data/maps/Route103/scripts.pory"
Route103_Text_BrendanTimeToHeadBack:
# 378 "data/maps/Route103/scripts.pory"
	.string "BRENDAN: I think I get it.\n"
# 379 "data/maps/Route103/scripts.pory"
	.string "I think I know why my dad has his eye\l"
# 380 "data/maps/Route103/scripts.pory"
	.string "out for you now.\p"
# 381 "data/maps/Route103/scripts.pory"
	.string "Look, your POKéMON already likes you,\n"
# 382 "data/maps/Route103/scripts.pory"
	.string "even though you just got it.\p"
# 383 "data/maps/Route103/scripts.pory"
	.string "{PLAYER}, I get the feeling that you\n"
# 384 "data/maps/Route103/scripts.pory"
	.string "could befriend any POKéMON with ease.\p"
# 385 "data/maps/Route103/scripts.pory"
	.string "We should head back to the LAB.$"
# 386 "data/maps/Route103/scripts.pory"

# 387 "data/maps/Route103/scripts.pory"
Route103_Text_ShouldHaveBroughtPotion:
# 388 "data/maps/Route103/scripts.pory"
	.string "My POKéMON is staggeringly tired…\n"
# 389 "data/maps/Route103/scripts.pory"
	.string "I should have brought a POTION…$"
# 390 "data/maps/Route103/scripts.pory"

# 391 "data/maps/Route103/scripts.pory"
Route103_Text_ShortcutToOldale:
# 392 "data/maps/Route103/scripts.pory"
	.string "If you cross the sea from here,\n"
# 393 "data/maps/Route103/scripts.pory"
	.string "it'll be a shortcut to OLDALE TOWN.\p"
# 394 "data/maps/Route103/scripts.pory"
	.string "Fufufu, that's useful, isn't it?$"
# 395 "data/maps/Route103/scripts.pory"

# 396 "data/maps/Route103/scripts.pory"
Route103_Text_RouteSign:
# 397 "data/maps/Route103/scripts.pory"
	.string "ROUTE 103\n"
# 398 "data/maps/Route103/scripts.pory"
	.string "{DOWN_ARROW} OLDALE TOWN$"
