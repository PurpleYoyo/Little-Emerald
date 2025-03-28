# 1 "data/maps/LavaridgeTown/scripts.pory"

# 2 "data/maps/LavaridgeTown/scripts.pory"
.set LOCALID_RIVAL_ON_BIKE, 7
# 3 "data/maps/LavaridgeTown/scripts.pory"
.set LOCALID_RIVAL, 8
# 4 "data/maps/LavaridgeTown/scripts.pory"
.set LOCALID_MEOWTH, 11
# 5 "data/maps/LavaridgeTown/scripts.pory"

# 6 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_MapScripts::
# 7 "data/maps/LavaridgeTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
# 8 "data/maps/LavaridgeTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_OnFrame
# 9 "data/maps/LavaridgeTown/scripts.pory"
	.byte 0
# 10 "data/maps/LavaridgeTown/scripts.pory"

# 11 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_OnTransition:
# 12 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_VISITED_LAVARIDGE_TOWN
# 13 "data/maps/LavaridgeTown/scripts.pory"
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, LavaridgeTown_EventScript_ClearLavaridgeWhiteOut
# 14 "data/maps/LavaridgeTown/scripts.pory"
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_ShowMtChimneyTrainers
# 15 "data/maps/LavaridgeTown/scripts.pory"
	call_if_set FLAG_DEFEATED_LAVARIDGE_GYM, EventScript_ShowBoomDude
# 16 "data/maps/LavaridgeTown/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 17 "data/maps/LavaridgeTown/scripts.pory"
	call Common_EventScript_SetupRivalOnBikeGfxId
# 18 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_CheckSetRivalPos
# 19 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_HideMapNamePopup
# 20 "data/maps/LavaridgeTown/scripts.pory"
	end
# 21 "data/maps/LavaridgeTown/scripts.pory"

# 22 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ClearLavaridgeWhiteOut::
# 23 "data/maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_WHITEOUT_TO_LAVARIDGE
# 24 "data/maps/LavaridgeTown/scripts.pory"
	return
# 25 "data/maps/LavaridgeTown/scripts.pory"

# 26 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_CheckSetRivalPos::
# 27 "data/maps/LavaridgeTown/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 28 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_0x8004, 9, LavaridgeTown_EventScript_SetRivalPos
# 29 "data/maps/LavaridgeTown/scripts.pory"
	return
# 30 "data/maps/LavaridgeTown/scripts.pory"

# 31 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_SetRivalPos::
# 32 "data/maps/LavaridgeTown/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 11, 9
# 33 "data/maps/LavaridgeTown/scripts.pory"
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 9, 8
# 34 "data/maps/LavaridgeTown/scripts.pory"
	setobjectmovementtype LOCALID_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_UP
# 35 "data/maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL
# 36 "data/maps/LavaridgeTown/scripts.pory"
	return
# 37 "data/maps/LavaridgeTown/scripts.pory"

# 38 "data/maps/LavaridgeTown/scripts.pory"
EventScript_ShowBoomDude::
# 39 "data/maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_HIDE_BOOMDUDE
# 40 "data/maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_HIDE_BOOM_DUDES_GEODUDE
# 41 "data/maps/LavaridgeTown/scripts.pory"
	return
# 42 "data/maps/LavaridgeTown/scripts.pory"

# 43 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ShowMtChimneyTrainers::
# 44 "data/maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
# 45 "data/maps/LavaridgeTown/scripts.pory"
	return
# 46 "data/maps/LavaridgeTown/scripts.pory"

# 47 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HideMapNamePopup::
# 48 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 49 "data/maps/LavaridgeTown/scripts.pory"
	return
# 50 "data/maps/LavaridgeTown/scripts.pory"

# 51 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_OnFrame:
# 52 "data/maps/LavaridgeTown/scripts.pory"
	map_script_2 VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_RivalGiveGoGoggles
# 53 "data/maps/LavaridgeTown/scripts.pory"
	.2byte 0
# 54 "data/maps/LavaridgeTown/scripts.pory"

# 55 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalGiveGoGoggles::
# 56 "data/maps/LavaridgeTown/scripts.pory"
	lockall
# 57 "data/maps/LavaridgeTown/scripts.pory"
	getplayerxy VAR_0x8008, VAR_0x8009
# 58 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalNoticePlayer
# 59 "data/maps/LavaridgeTown/scripts.pory"
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExitHerbShop
# 60 "data/maps/LavaridgeTown/scripts.pory"
	delay 20
# 61 "data/maps/LavaridgeTown/scripts.pory"
	checkplayergender
# 62 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_PlayMayMusic
# 63 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_PlayBrendanMusic
# 64 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer1
# 65 "data/maps/LavaridgeTown/scripts.pory"
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer2
# 66 "data/maps/LavaridgeTown/scripts.pory"
	checkplayergender
# 67 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_MayGiveGoGoggles
# 68 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_BrendanGiveGoGoggles
# 69 "data/maps/LavaridgeTown/scripts.pory"
	end
# 70 "data/maps/LavaridgeTown/scripts.pory"

# 71 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_MayGiveGoGoggles::
# 72 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_MayNiceBadgesTakeThis, MSGBOX_DEFAULT
# 73 "data/maps/LavaridgeTown/scripts.pory"
	giveitem ITEM_GO_GOGGLES
# 74 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_RECEIVED_GO_GOGGLES
# 75 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_MayExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
# 76 "data/maps/LavaridgeTown/scripts.pory"
	goto LavaridgeTown_EventScript_RivalExit
# 77 "data/maps/LavaridgeTown/scripts.pory"
	end
# 78 "data/maps/LavaridgeTown/scripts.pory"

# 79 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_BrendanGiveGoGoggles::
# 80 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_BrendanNiceBadgesTakeThis, MSGBOX_DEFAULT
# 81 "data/maps/LavaridgeTown/scripts.pory"
	giveitem ITEM_GO_GOGGLES
# 82 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_RECEIVED_GO_GOGGLES
# 83 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
# 84 "data/maps/LavaridgeTown/scripts.pory"
	goto LavaridgeTown_EventScript_RivalExit
# 85 "data/maps/LavaridgeTown/scripts.pory"
	end
# 86 "data/maps/LavaridgeTown/scripts.pory"

# 87 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalExit::
# 88 "data/maps/LavaridgeTown/scripts.pory"
	closemessage
# 89 "data/maps/LavaridgeTown/scripts.pory"
	removeobject LOCALID_RIVAL
# 90 "data/maps/LavaridgeTown/scripts.pory"
	addobject LOCALID_RIVAL_ON_BIKE
# 91 "data/maps/LavaridgeTown/scripts.pory"
	delay 30
# 92 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit1
# 93 "data/maps/LavaridgeTown/scripts.pory"
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit2
# 94 "data/maps/LavaridgeTown/scripts.pory"
	removeobject LOCALID_RIVAL_ON_BIKE
# 95 "data/maps/LavaridgeTown/scripts.pory"
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
# 96 "data/maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 97 "data/maps/LavaridgeTown/scripts.pory"
	savebgm MUS_DUMMY
# 98 "data/maps/LavaridgeTown/scripts.pory"
	fadedefaultbgm
# 99 "data/maps/LavaridgeTown/scripts.pory"
	releaseall
# 100 "data/maps/LavaridgeTown/scripts.pory"
	end
# 101 "data/maps/LavaridgeTown/scripts.pory"

# 102 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_PlayMayMusic::
# 103 "data/maps/LavaridgeTown/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 104 "data/maps/LavaridgeTown/scripts.pory"
	return
# 105 "data/maps/LavaridgeTown/scripts.pory"

# 106 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_PlayBrendanMusic::
# 107 "data/maps/LavaridgeTown/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 108 "data/maps/LavaridgeTown/scripts.pory"
	return
# 109 "data/maps/LavaridgeTown/scripts.pory"

# 110 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalNoticePlayer::
# 111 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterUp
# 112 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 113 "data/maps/LavaridgeTown/scripts.pory"
	playse SE_PIN
# 114 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 115 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 116 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 117 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 118 "data/maps/LavaridgeTown/scripts.pory"
	return
# 119 "data/maps/LavaridgeTown/scripts.pory"

# 120 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalExitHerbShop::
# 121 "data/maps/LavaridgeTown/scripts.pory"
	opendoor 12, 15
# 122 "data/maps/LavaridgeTown/scripts.pory"
	waitdooranim
# 123 "data/maps/LavaridgeTown/scripts.pory"
	addobject LOCALID_RIVAL
# 124 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalExitHerbShop
# 125 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 126 "data/maps/LavaridgeTown/scripts.pory"
	closedoor 12, 15
# 127 "data/maps/LavaridgeTown/scripts.pory"
	waitdooranim
# 128 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterLeft
# 129 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 130 "data/maps/LavaridgeTown/scripts.pory"
	playse SE_PIN
# 131 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 132 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 133 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 134 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 135 "data/maps/LavaridgeTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 136 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 137 "data/maps/LavaridgeTown/scripts.pory"
	return
# 138 "data/maps/LavaridgeTown/scripts.pory"

# 139 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalApproachPlayer1::
# 140 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer1
# 141 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 142 "data/maps/LavaridgeTown/scripts.pory"
	return
# 143 "data/maps/LavaridgeTown/scripts.pory"

# 144 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalApproachPlayer2::
# 145 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer2
# 146 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 147 "data/maps/LavaridgeTown/scripts.pory"
	return
# 148 "data/maps/LavaridgeTown/scripts.pory"

# 149 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalExit1::
# 150 "data/maps/LavaridgeTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_Movement_PlayerWatchRivalExit
# 151 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit1
# 152 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 153 "data/maps/LavaridgeTown/scripts.pory"
	return
# 154 "data/maps/LavaridgeTown/scripts.pory"

# 155 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalExit2::
# 156 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit2
# 157 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 158 "data/maps/LavaridgeTown/scripts.pory"
	return
# 159 "data/maps/LavaridgeTown/scripts.pory"

# 160 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalExit2:
# 161 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 162 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 163 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 164 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 165 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 166 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 167 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 168 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 169 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 170 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 171 "data/maps/LavaridgeTown/scripts.pory"
	step_end
# 172 "data/maps/LavaridgeTown/scripts.pory"

# 173 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_PlayerWatchRivalExit:
# 174 "data/maps/LavaridgeTown/scripts.pory"
	delay_16
# 175 "data/maps/LavaridgeTown/scripts.pory"
	delay_8
# 176 "data/maps/LavaridgeTown/scripts.pory"
	walk_in_place_faster_right
# 177 "data/maps/LavaridgeTown/scripts.pory"
	step_end
# 178 "data/maps/LavaridgeTown/scripts.pory"

# 179 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalExit1:
# 180 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_down
# 181 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 182 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 183 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 184 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 185 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 186 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 187 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 188 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 189 "data/maps/LavaridgeTown/scripts.pory"
	step_end
# 190 "data/maps/LavaridgeTown/scripts.pory"

# 191 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalApproachPlayer2:
# 192 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 193 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 194 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 195 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 196 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 197 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 198 "data/maps/LavaridgeTown/scripts.pory"
	step_end
# 199 "data/maps/LavaridgeTown/scripts.pory"

# 200 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalApproachPlayer1:
# 201 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 202 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 203 "data/maps/LavaridgeTown/scripts.pory"
	walk_up
# 204 "data/maps/LavaridgeTown/scripts.pory"
	step_end
# 205 "data/maps/LavaridgeTown/scripts.pory"

# 206 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalExitHerbShop:
# 207 "data/maps/LavaridgeTown/scripts.pory"
	walk_down
# 208 "data/maps/LavaridgeTown/scripts.pory"
	step_end
# 209 "data/maps/LavaridgeTown/scripts.pory"

# 210 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HotSpringsTrigger::
# 211 "data/maps/LavaridgeTown/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 212 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, DIR_SOUTH, LavaridgeTown_EventScript_EnteredHotSprings
# 213 "data/maps/LavaridgeTown/scripts.pory"
	end
# 214 "data/maps/LavaridgeTown/scripts.pory"

# 215 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_EnteredHotSprings::
# 216 "data/maps/LavaridgeTown/scripts.pory"
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
# 217 "data/maps/LavaridgeTown/scripts.pory"
	end
# 218 "data/maps/LavaridgeTown/scripts.pory"

# 219 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ExpertM::
# 220 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HotSpringsNeverRunDry, MSGBOX_NPC
# 221 "data/maps/LavaridgeTown/scripts.pory"
	end
# 222 "data/maps/LavaridgeTown/scripts.pory"

# 223 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_OldMan::
# 224 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_PokemonNippedBackside, MSGBOX_SIGN
# 225 "data/maps/LavaridgeTown/scripts.pory"
	end
# 226 "data/maps/LavaridgeTown/scripts.pory"

# 227 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_Twin::
# 228 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_BatheInHotSpringsEveryDay, MSGBOX_NPC
# 229 "data/maps/LavaridgeTown/scripts.pory"
	end
# 230 "data/maps/LavaridgeTown/scripts.pory"

# 231 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HotSpringsOldWoman1::
# 232 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_IfPokemonInHotSprings, MSGBOX_NPC
# 233 "data/maps/LavaridgeTown/scripts.pory"
	end
# 234 "data/maps/LavaridgeTown/scripts.pory"

# 235 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HotSpringsOldWoman2::
# 236 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HotSpringsClaims, MSGBOX_NPC
# 237 "data/maps/LavaridgeTown/scripts.pory"
	end
# 238 "data/maps/LavaridgeTown/scripts.pory"

# 239 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ExpertF::
# 240 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_OhYouLikeHotSprings, MSGBOX_NPC
# 241 "data/maps/LavaridgeTown/scripts.pory"
	end
# 242 "data/maps/LavaridgeTown/scripts.pory"

# 243 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ReceivedEgg::
# 244 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
# 245 "data/maps/LavaridgeTown/scripts.pory"
	release
# 246 "data/maps/LavaridgeTown/scripts.pory"
	end
# 247 "data/maps/LavaridgeTown/scripts.pory"

# 248 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_NoRoomForEgg::
# 249 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
# 250 "data/maps/LavaridgeTown/scripts.pory"
	release
# 251 "data/maps/LavaridgeTown/scripts.pory"
	end
# 252 "data/maps/LavaridgeTown/scripts.pory"

# 253 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_DeclineEgg::
# 254 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
# 255 "data/maps/LavaridgeTown/scripts.pory"
	release
# 256 "data/maps/LavaridgeTown/scripts.pory"
	end
# 257 "data/maps/LavaridgeTown/scripts.pory"

# 258 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_TownSign::
# 259 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_TownSign, MSGBOX_SIGN
# 260 "data/maps/LavaridgeTown/scripts.pory"
	end
# 261 "data/maps/LavaridgeTown/scripts.pory"

# 262 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_GymSign::
# 263 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_GymSign, MSGBOX_SIGN
# 264 "data/maps/LavaridgeTown/scripts.pory"
	end
# 265 "data/maps/LavaridgeTown/scripts.pory"

# 266 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HerbShopSign::
# 267 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HerbShopSign, MSGBOX_SIGN
# 268 "data/maps/LavaridgeTown/scripts.pory"
	end
# 269 "data/maps/LavaridgeTown/scripts.pory"

# 270 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_MayNiceBadgesTakeThis:
# 271 "data/maps/LavaridgeTown/scripts.pory"
	.string "MAY: {PLAYER}{KUN}! Long time no see!\p"
# 272 "data/maps/LavaridgeTown/scripts.pory"
	.string "Oh? While I visited the hot springs,\n"
# 273 "data/maps/LavaridgeTown/scripts.pory"
	.string "you got the LAVARIDGE GYM BADGE.\p"
# 274 "data/maps/LavaridgeTown/scripts.pory"
	.string "You must have collected\n"
# 275 "data/maps/LavaridgeTown/scripts.pory"
	.string "good POKéMON…\l"
# 276 "data/maps/LavaridgeTown/scripts.pory"
	.string "No, I believe you raised some.\p"
# 277 "data/maps/LavaridgeTown/scripts.pory"
	.string "I guess it would be okay for you to\n"
# 278 "data/maps/LavaridgeTown/scripts.pory"
	.string "have this.$"
# 279 "data/maps/LavaridgeTown/scripts.pory"

# 280 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_MayExplainGoGogglesChallengeDad:
# 281 "data/maps/LavaridgeTown/scripts.pory"
	.string "MAY: With those GO-GOGGLES, you'll\n"
# 282 "data/maps/LavaridgeTown/scripts.pory"
	.string "have no trouble getting through the\l"
# 283 "data/maps/LavaridgeTown/scripts.pory"
	.string "desert near ROUTE 111.\p"
# 284 "data/maps/LavaridgeTown/scripts.pory"
	.string "But, wow, {PLAYER}{KUN}…\n"
# 285 "data/maps/LavaridgeTown/scripts.pory"
	.string "Challenging GYMS…\p"
# 286 "data/maps/LavaridgeTown/scripts.pory"
	.string "You're trying hard because you don't\n"
# 287 "data/maps/LavaridgeTown/scripts.pory"
	.string "want to lose to me, I bet!\p"
# 288 "data/maps/LavaridgeTown/scripts.pory"
	.string "{PLAYER}{KUN}, I think I should challenge\n"
# 289 "data/maps/LavaridgeTown/scripts.pory"
	.string "your dad in PETALBURG GYM.\p"
# 290 "data/maps/LavaridgeTown/scripts.pory"
	.string "See you again!$"
# 291 "data/maps/LavaridgeTown/scripts.pory"

# 292 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_BrendanNiceBadgesTakeThis:
# 293 "data/maps/LavaridgeTown/scripts.pory"
	.string "BRENDAN: {PLAYER}, hey, it's been a while.\n"
# 294 "data/maps/LavaridgeTown/scripts.pory"
	.string "How's it going?\p"
# 295 "data/maps/LavaridgeTown/scripts.pory"
	.string "Hmm…\n"
# 296 "data/maps/LavaridgeTown/scripts.pory"
	.string "That's a decent collection of BADGES.\p"
# 297 "data/maps/LavaridgeTown/scripts.pory"
	.string "All right, then.\n"
# 298 "data/maps/LavaridgeTown/scripts.pory"
	.string "You may as well have this.$"
# 299 "data/maps/LavaridgeTown/scripts.pory"

# 300 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad:
# 301 "data/maps/LavaridgeTown/scripts.pory"
	.string "BRENDAN: Keep those with you if you're\n"
# 302 "data/maps/LavaridgeTown/scripts.pory"
	.string "planning on going into that desert near\l"
# 303 "data/maps/LavaridgeTown/scripts.pory"
	.string "ROUTE 111.\p"
# 304 "data/maps/LavaridgeTown/scripts.pory"
	.string "There should be some POKéMON that\n"
# 305 "data/maps/LavaridgeTown/scripts.pory"
	.string "are exclusively desert-dwellers.\l"
# 306 "data/maps/LavaridgeTown/scripts.pory"
	.string "You might look around for those.\p"
# 307 "data/maps/LavaridgeTown/scripts.pory"
	.string "As for me…\n"
# 308 "data/maps/LavaridgeTown/scripts.pory"
	.string "I'm considering challenging NORMAN,\l"
# 309 "data/maps/LavaridgeTown/scripts.pory"
	.string "the GYM LEADER of PETALBURG.\p"
# 310 "data/maps/LavaridgeTown/scripts.pory"
	.string "Unlike you, {PLAYER}, your dad looks like\n"
# 311 "data/maps/LavaridgeTown/scripts.pory"
	.string "he really is tough.\p"
# 312 "data/maps/LavaridgeTown/scripts.pory"
	.string "See you around!$"
# 313 "data/maps/LavaridgeTown/scripts.pory"

# 314 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HaveEggWillYouTakeIt:
# 315 "data/maps/LavaridgeTown/scripts.pory"
	.string "I have here an EGG.\p"
# 316 "data/maps/LavaridgeTown/scripts.pory"
	.string "I'd hoped to hatch it by covering it in\n"
# 317 "data/maps/LavaridgeTown/scripts.pory"
	.string "hot sand by the hot springs.\l"
# 318 "data/maps/LavaridgeTown/scripts.pory"
	.string "But that doesn't seem to be enough…\p"
# 319 "data/maps/LavaridgeTown/scripts.pory"
	.string "I've heard it would be best if it were\n"
# 320 "data/maps/LavaridgeTown/scripts.pory"
	.string "kept together with POKéMON and\l"
# 321 "data/maps/LavaridgeTown/scripts.pory"
	.string "carried about.\p"
# 322 "data/maps/LavaridgeTown/scripts.pory"
	.string "You are a TRAINER, yes?\n"
# 323 "data/maps/LavaridgeTown/scripts.pory"
	.string "And your POKéMON radiate vitality.\p"
# 324 "data/maps/LavaridgeTown/scripts.pory"
	.string "So, what say you?\n"
# 325 "data/maps/LavaridgeTown/scripts.pory"
	.string "Will you take this EGG to hatch?$"
# 326 "data/maps/LavaridgeTown/scripts.pory"

# 327 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg:
# 328 "data/maps/LavaridgeTown/scripts.pory"
	.string "Good! I hope you'll walk plenty with\n"
# 329 "data/maps/LavaridgeTown/scripts.pory"
	.string "this here EGG!$"
# 330 "data/maps/LavaridgeTown/scripts.pory"

# 331 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_ReceivedTheEgg:
# 332 "data/maps/LavaridgeTown/scripts.pory"
	.string "{PLAYER} received the EGG.$"
# 333 "data/maps/LavaridgeTown/scripts.pory"

# 334 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_NoRoomForThisEgg:
# 335 "data/maps/LavaridgeTown/scripts.pory"
	.string "Oh? You've too many POKéMON.\n"
# 336 "data/maps/LavaridgeTown/scripts.pory"
	.string "There's no room for this EGG…$"
# 337 "data/maps/LavaridgeTown/scripts.pory"

# 338 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_AsYouWishThen:
# 339 "data/maps/LavaridgeTown/scripts.pory"
	.string "As you wish, then…\p"
# 340 "data/maps/LavaridgeTown/scripts.pory"
	.string "If you have a change of heart about\n"
# 341 "data/maps/LavaridgeTown/scripts.pory"
	.string "hatching this EGG, I will be here.$"
# 342 "data/maps/LavaridgeTown/scripts.pory"

# 343 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare:
# 344 "data/maps/LavaridgeTown/scripts.pory"
	.string "Every so often, an EGG will be found at\n"
# 345 "data/maps/LavaridgeTown/scripts.pory"
	.string "the POKéMON DAY CARE.\p"
# 346 "data/maps/LavaridgeTown/scripts.pory"
	.string "Or at least that's how the rumor goes.$"
# 347 "data/maps/LavaridgeTown/scripts.pory"

# 348 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HotSpringsNeverRunDry:
# 349 "data/maps/LavaridgeTown/scripts.pory"
	.string "We draw as much hot water as we need,\n"
# 350 "data/maps/LavaridgeTown/scripts.pory"
	.string "and yet the hot springs never run dry.\p"
# 351 "data/maps/LavaridgeTown/scripts.pory"
	.string "Isn't it magical?\p"
# 352 "data/maps/LavaridgeTown/scripts.pory"
	.string "These hot springs appear near active\n"
# 353 "data/maps/LavaridgeTown/scripts.pory"
	.string "volcanoes. Veins of water under the\l"
# 354 "data/maps/LavaridgeTown/scripts.pory"
	.string "ground are heated by magma to well up\l"
# 355 "data/maps/LavaridgeTown/scripts.pory"
	.string "as hot springs.$"
# 356 "data/maps/LavaridgeTown/scripts.pory"

# 357 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_PokemonNippedBackside:
# 358 "data/maps/LavaridgeTown/scripts.pory"
	.string "Being buried in this hot sand is…\n"
# 359 "data/maps/LavaridgeTown/scripts.pory"
	.string "Sigh…\p"
# 360 "data/maps/LavaridgeTown/scripts.pory"
	.string "So warm and heavenly…\p"
# 361 "data/maps/LavaridgeTown/scripts.pory"
	.string "Eh? Gyaah! Ouch!\p"
# 362 "data/maps/LavaridgeTown/scripts.pory"
	.string "A POKéMON nipped my backside!$"
# 363 "data/maps/LavaridgeTown/scripts.pory"

# 364 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_OhYouLikeHotSprings:
# 365 "data/maps/LavaridgeTown/scripts.pory"
	.string "Oh, you like hot springs, do you?\p"
# 366 "data/maps/LavaridgeTown/scripts.pory"
	.string "That's surprising for one as young\n"
# 367 "data/maps/LavaridgeTown/scripts.pory"
	.string "as you.$"
# 368 "data/maps/LavaridgeTown/scripts.pory"

# 369 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_BatheInHotSpringsEveryDay:
# 370 "data/maps/LavaridgeTown/scripts.pory"
	.string "I bathe in the hot springs every day.\p"
# 371 "data/maps/LavaridgeTown/scripts.pory"
	.string "I want to become a beautiful and strong\n"
# 372 "data/maps/LavaridgeTown/scripts.pory"
	.string "GYM LEADER like FLANNERY.$"
# 373 "data/maps/LavaridgeTown/scripts.pory"

# 374 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_IfPokemonInHotSprings:
# 375 "data/maps/LavaridgeTown/scripts.pory"
	.string "If people put POKéMON in hot springs,\n"
# 376 "data/maps/LavaridgeTown/scripts.pory"
	.string "it might be seriously strange.\p"
# 377 "data/maps/LavaridgeTown/scripts.pory"
	.string "Why, it might be an electric bath, or\n"
# 378 "data/maps/LavaridgeTown/scripts.pory"
	.string "a bubble bath, or even a lava bath…$"
# 379 "data/maps/LavaridgeTown/scripts.pory"

# 380 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HotSpringsClaims:
# 381 "data/maps/LavaridgeTown/scripts.pory"
	.string "They're claiming that these hot springs\n"
# 382 "data/maps/LavaridgeTown/scripts.pory"
	.string "are good for calming nervous tension,\l"
# 383 "data/maps/LavaridgeTown/scripts.pory"
	.string "relieving aching muscles, solving\l"
# 384 "data/maps/LavaridgeTown/scripts.pory"
	.string "romantic problems, and attracting\l"
# 385 "data/maps/LavaridgeTown/scripts.pory"
	.string "money…$"
# 386 "data/maps/LavaridgeTown/scripts.pory"

# 387 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_TownSign:
# 388 "data/maps/LavaridgeTown/scripts.pory"
	.string "LAVARIDGE TOWN\p"
# 389 "data/maps/LavaridgeTown/scripts.pory"
	.string "“POKéMON CENTER HOT SPRINGS\n"
# 390 "data/maps/LavaridgeTown/scripts.pory"
	.string "An excellent place for relaxing!”$"
# 391 "data/maps/LavaridgeTown/scripts.pory"

# 392 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_GymSign:
# 393 "data/maps/LavaridgeTown/scripts.pory"
	.string "LAVARIDGE TOWN POKéMON GYM\n"
# 394 "data/maps/LavaridgeTown/scripts.pory"
	.string "LEADER: FLANNERY\l"
# 395 "data/maps/LavaridgeTown/scripts.pory"
	.string "“One with a fiery passion that burns!”$"
# 396 "data/maps/LavaridgeTown/scripts.pory"

# 397 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HerbShopSign:
# 398 "data/maps/LavaridgeTown/scripts.pory"
	.string "POKéMON HERB SHOP\n"
# 399 "data/maps/LavaridgeTown/scripts.pory"
	.string "“Bitter taste--better cure!”$"

LavaridgeTown_EventScript_EggWoman::
# 404 "data/maps/LavaridgeTown/scripts.pory"
	lock
# 405 "data/maps/LavaridgeTown/scripts.pory"
	faceplayer
# 406 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_ReceivedEgg
# 407 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
# 408 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_EventScript_DeclineEgg
# 409 "data/maps/LavaridgeTown/scripts.pory"
	getpartysize
# 410 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, PARTY_SIZE, LavaridgeTown_EventScript_NoRoomForEgg
# 411 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
# 412 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
# 413 "data/maps/LavaridgeTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 414 "data/maps/LavaridgeTown/scripts.pory"
	message LavaridgeTown_Text_ReceivedTheEgg
# 415 "data/maps/LavaridgeTown/scripts.pory"
	waitfanfare
# 416 "data/maps/LavaridgeTown/scripts.pory"
	random 19
# 417 "data/maps/LavaridgeTown/scripts.pory"
	switch VAR_RESULT
# 418 "data/maps/LavaridgeTown/scripts.pory"
	case 0, LavaridgeTown_EventScript_EggWoman_3
# 420 "data/maps/LavaridgeTown/scripts.pory"
	case 1, LavaridgeTown_EventScript_EggWoman_4
# 422 "data/maps/LavaridgeTown/scripts.pory"
	case 2, LavaridgeTown_EventScript_EggWoman_5
# 424 "data/maps/LavaridgeTown/scripts.pory"
	case 3, LavaridgeTown_EventScript_EggWoman_6
# 426 "data/maps/LavaridgeTown/scripts.pory"
	case 4, LavaridgeTown_EventScript_EggWoman_7
# 428 "data/maps/LavaridgeTown/scripts.pory"
	case 5, LavaridgeTown_EventScript_EggWoman_8
# 430 "data/maps/LavaridgeTown/scripts.pory"
	case 6, LavaridgeTown_EventScript_EggWoman_9
# 432 "data/maps/LavaridgeTown/scripts.pory"
	case 7, LavaridgeTown_EventScript_EggWoman_10
# 434 "data/maps/LavaridgeTown/scripts.pory"
	case 8, LavaridgeTown_EventScript_EggWoman_11
# 436 "data/maps/LavaridgeTown/scripts.pory"
	case 9, LavaridgeTown_EventScript_EggWoman_12
# 438 "data/maps/LavaridgeTown/scripts.pory"
	case 10, LavaridgeTown_EventScript_EggWoman_13
# 440 "data/maps/LavaridgeTown/scripts.pory"
	case 11, LavaridgeTown_EventScript_EggWoman_14
# 442 "data/maps/LavaridgeTown/scripts.pory"
	case 12, LavaridgeTown_EventScript_EggWoman_15
# 444 "data/maps/LavaridgeTown/scripts.pory"
	case 13, LavaridgeTown_EventScript_EggWoman_16
# 446 "data/maps/LavaridgeTown/scripts.pory"
	case 14, LavaridgeTown_EventScript_EggWoman_17
# 448 "data/maps/LavaridgeTown/scripts.pory"
	case 15, LavaridgeTown_EventScript_EggWoman_18
# 450 "data/maps/LavaridgeTown/scripts.pory"
	case 16, LavaridgeTown_EventScript_EggWoman_19
# 452 "data/maps/LavaridgeTown/scripts.pory"
	case 17, LavaridgeTown_EventScript_EggWoman_20
# 454 "data/maps/LavaridgeTown/scripts.pory"
	case 18, LavaridgeTown_EventScript_EggWoman_21
LavaridgeTown_EventScript_EggWoman_1:
# 457 "data/maps/LavaridgeTown/scripts.pory"
	release
	return

LavaridgeTown_EventScript_EggWoman_3:
# 419 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_PICHU
	goto LavaridgeTown_EventScript_EggWoman_1

LavaridgeTown_EventScript_EggWoman_4:
# 421 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_CLEFFA
	goto LavaridgeTown_EventScript_EggWoman_1

LavaridgeTown_EventScript_EggWoman_5:
# 423 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_IGGLYBUFF
	goto LavaridgeTown_EventScript_EggWoman_1

LavaridgeTown_EventScript_EggWoman_6:
# 425 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_TOGEPI
	goto LavaridgeTown_EventScript_EggWoman_1

LavaridgeTown_EventScript_EggWoman_7:
# 427 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_TYROGUE
	goto LavaridgeTown_EventScript_EggWoman_1

LavaridgeTown_EventScript_EggWoman_8:
# 429 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_SMOOCHUM
	goto LavaridgeTown_EventScript_EggWoman_1

LavaridgeTown_EventScript_EggWoman_9:
# 431 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_ELEKID
	goto LavaridgeTown_EventScript_EggWoman_1

LavaridgeTown_EventScript_EggWoman_10:
# 433 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_MAGBY
	goto LavaridgeTown_EventScript_EggWoman_1

LavaridgeTown_EventScript_EggWoman_11:
# 435 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_AZURILL
	goto LavaridgeTown_EventScript_EggWoman_1

LavaridgeTown_EventScript_EggWoman_12:
# 437 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_WYNAUT
	goto LavaridgeTown_EventScript_EggWoman_1

LavaridgeTown_EventScript_EggWoman_13:
# 439 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_BUDEW
	goto LavaridgeTown_EventScript_EggWoman_1

LavaridgeTown_EventScript_EggWoman_14:
# 441 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_CHINGLING
	goto LavaridgeTown_EventScript_EggWoman_1

LavaridgeTown_EventScript_EggWoman_15:
# 443 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_BONSLY
	goto LavaridgeTown_EventScript_EggWoman_1

LavaridgeTown_EventScript_EggWoman_16:
# 445 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_MIME_JR
	goto LavaridgeTown_EventScript_EggWoman_1

LavaridgeTown_EventScript_EggWoman_17:
# 447 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_HAPPINY
	goto LavaridgeTown_EventScript_EggWoman_1

LavaridgeTown_EventScript_EggWoman_18:
# 449 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_MUNCHLAX
	goto LavaridgeTown_EventScript_EggWoman_1

LavaridgeTown_EventScript_EggWoman_19:
# 451 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_RIOLU
	goto LavaridgeTown_EventScript_EggWoman_1

LavaridgeTown_EventScript_EggWoman_20:
# 453 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_MANTYKE
	goto LavaridgeTown_EventScript_EggWoman_1

LavaridgeTown_EventScript_EggWoman_21:
# 455 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_TOXEL
	goto LavaridgeTown_EventScript_EggWoman_1

