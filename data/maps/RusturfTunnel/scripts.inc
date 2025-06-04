# 1 "data/maps/RusturfTunnel/scripts.pory"

# 2 "data/maps/RusturfTunnel/scripts.pory"
.equ LOCALID_WANDAS_BF, 1
# 3 "data/maps/RusturfTunnel/scripts.pory"
.set LOCALID_BRINEY, 5
# 4 "data/maps/RusturfTunnel/scripts.pory"
.set LOCALID_GRUNT, 6
# 5 "data/maps/RusturfTunnel/scripts.pory"
.set LOCALID_PEEKO, 7
# 6 "data/maps/RusturfTunnel/scripts.pory"
.equ LOCALID_WANDA, 10
# 7 "data/maps/RusturfTunnel/scripts.pory"

# 8 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_MapScripts::
# 9 "data/maps/RusturfTunnel/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RusturfTunnel_OnTransition
# 10 "data/maps/RusturfTunnel/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RusturfTunnel_OnFrame
# 11 "data/maps/RusturfTunnel/scripts.pory"
	.byte 0
# 12 "data/maps/RusturfTunnel/scripts.pory"

# 13 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_OnFrame:
# 14 "data/maps/RusturfTunnel/scripts.pory"
	map_script_2 VAR_RUSTURF_TUNNEL_STATE, 4, RusturfTunnel_EventScript_ClearTunnelScene
# 15 "data/maps/RusturfTunnel/scripts.pory"
	map_script_2 VAR_RUSTURF_TUNNEL_STATE, 5, RusturfTunnel_EventScript_ClearTunnelScene
# 16 "data/maps/RusturfTunnel/scripts.pory"
	.2byte 0
# 17 "data/maps/RusturfTunnel/scripts.pory"

# 18 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_OnTransition:
# 19 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_RUSTURF_TUNNEL_STATE, 2, RusturfTunnel_EventScript_SetAquaGruntAndPeekoPos
# 20 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_SANDBOX_MODE, 0, RusturfTunnel_HideAbilityChanger
# 21 "data/maps/RusturfTunnel/scripts.pory"
	end
# 22 "data/maps/RusturfTunnel/scripts.pory"

# 23 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_HideAbilityChanger:
# 24 "data/maps/RusturfTunnel/scripts.pory"
	setflag FLAG_HIDE_ABILITY_CHANGER
# 25 "data/maps/RusturfTunnel/scripts.pory"
	return
# 26 "data/maps/RusturfTunnel/scripts.pory"

# 27 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_SetAquaGruntAndPeekoPos::
# 28 "data/maps/RusturfTunnel/scripts.pory"
	setobjectxyperm LOCALID_PEEKO, 13, 4
# 29 "data/maps/RusturfTunnel/scripts.pory"
	setobjectxyperm LOCALID_GRUNT, 13, 5
# 30 "data/maps/RusturfTunnel/scripts.pory"
	return
# 31 "data/maps/RusturfTunnel/scripts.pory"

# 32 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_Wanda::
# 33 "data/maps/RusturfTunnel/scripts.pory"
	lock
# 34 "data/maps/RusturfTunnel/scripts.pory"
	faceplayer
# 35 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_BoyfriendOnOtherSideOfRock, MSGBOX_DEFAULT
# 36 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 37 "data/maps/RusturfTunnel/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 38 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 39 "data/maps/RusturfTunnel/scripts.pory"
	release
# 40 "data/maps/RusturfTunnel/scripts.pory"
	end
# 41 "data/maps/RusturfTunnel/scripts.pory"

# 42 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_WandasBoyfriend::
# 43 "data/maps/RusturfTunnel/scripts.pory"
	lock
# 44 "data/maps/RusturfTunnel/scripts.pory"
	faceplayer
# 45 "data/maps/RusturfTunnel/scripts.pory"
	goto_if_set FLAG_TEMP_1, RusturfTunnel_EventScript_AlreadySpokenTo
# 46 "data/maps/RusturfTunnel/scripts.pory"
	setflag FLAG_TEMP_1
# 47 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_WhyCantTheyKeepDigging, MSGBOX_DEFAULT
# 48 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 49 "data/maps/RusturfTunnel/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 50 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 51 "data/maps/RusturfTunnel/scripts.pory"
	release
# 52 "data/maps/RusturfTunnel/scripts.pory"
	end
# 53 "data/maps/RusturfTunnel/scripts.pory"

# 54 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_AlreadySpokenTo::
# 55 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_ToGetToVerdanturf, MSGBOX_DEFAULT
# 56 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 57 "data/maps/RusturfTunnel/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 58 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 59 "data/maps/RusturfTunnel/scripts.pory"
	release
# 60 "data/maps/RusturfTunnel/scripts.pory"
	end
# 61 "data/maps/RusturfTunnel/scripts.pory"

# 62 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_ClearTunnelScene::
# 63 "data/maps/RusturfTunnel/scripts.pory"
	lockall
# 64 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RusturfTunnel_EventScript_FaceWandasBoyfriend1
# 65 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_FaceWandasBoyfriend2
# 66 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_FaceWandasBoyfriend3
# 67 "data/maps/RusturfTunnel/scripts.pory"
	call RusturfTunnel_EventScript_WandasBoyfriendNotice
# 68 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_YouShatteredBoulderTakeHM, MSGBOX_DEFAULT
# 69 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer
# 70 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer
# 71 "data/maps/RusturfTunnel/scripts.pory"
	giveitem ITEM_HM_STRENGTH
# 72 "data/maps/RusturfTunnel/scripts.pory"
	setflag FLAG_RECEIVED_HM_STRENGTH
# 73 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_ExplainStrength, MSGBOX_DEFAULT
# 74 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 75 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RusturfTunnel_EventScript_BoyfriendApproachWanda1
# 76 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_BoyfriendApproachWanda2
# 77 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_BoyfriendApproachWanda3
# 78 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_WandaReunion, MSGBOX_DEFAULT
# 79 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 80 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RusturfTunnel_EventScript_WandaAndBoyfriendExit1
# 81 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_WandaAndBoyfriendExit
# 82 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_WandaAndBoyfriendExit
# 83 "data/maps/RusturfTunnel/scripts.pory"
	call RusturfTunnel_EventScript_SetRusturfTunnelOpen
# 84 "data/maps/RusturfTunnel/scripts.pory"
	releaseall
# 85 "data/maps/RusturfTunnel/scripts.pory"
	end
# 86 "data/maps/RusturfTunnel/scripts.pory"

# 87 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_BoyfriendApproachWanda1::
# 88 "data/maps/RusturfTunnel/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend1
# 89 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda1
# 90 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 91 "data/maps/RusturfTunnel/scripts.pory"
	return
# 92 "data/maps/RusturfTunnel/scripts.pory"

# 93 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_BoyfriendApproachWanda2::
# 94 "data/maps/RusturfTunnel/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend
# 95 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda
# 96 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 97 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDA, Common_Movement_WalkInPlaceFasterDown
# 98 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 99 "data/maps/RusturfTunnel/scripts.pory"
	return
# 100 "data/maps/RusturfTunnel/scripts.pory"

# 101 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_BoyfriendApproachWanda3::
# 102 "data/maps/RusturfTunnel/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend
# 103 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda
# 104 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 105 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDA, Common_Movement_WalkInPlaceFasterDown
# 106 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 107 "data/maps/RusturfTunnel/scripts.pory"
	return
# 108 "data/maps/RusturfTunnel/scripts.pory"

# 109 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_FaceWandasBoyfriend1::
# 110 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, Common_Movement_WalkInPlaceFasterUp
# 111 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 112 "data/maps/RusturfTunnel/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 113 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 114 "data/maps/RusturfTunnel/scripts.pory"
	return
# 115 "data/maps/RusturfTunnel/scripts.pory"

# 116 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_FaceWandasBoyfriend2::
# 117 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_BoyfriendFaceRight
# 118 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 119 "data/maps/RusturfTunnel/scripts.pory"
	return
# 120 "data/maps/RusturfTunnel/scripts.pory"

# 121 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_FaceWandasBoyfriend3::
# 122 "data/maps/RusturfTunnel/scripts.pory"
	return
# 123 "data/maps/RusturfTunnel/scripts.pory"

# 124 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer::
# 125 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 126 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendApproachPlayer
# 127 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 128 "data/maps/RusturfTunnel/scripts.pory"
	return
# 129 "data/maps/RusturfTunnel/scripts.pory"

# 130 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_WandaAndBoyfriendExit1::
# 131 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDA, RusturfTunnel_Movement_WandaExit1
# 132 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendExit1
# 133 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 134 "data/maps/RusturfTunnel/scripts.pory"
	return
# 135 "data/maps/RusturfTunnel/scripts.pory"

# 136 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_WandaAndBoyfriendExit::
# 137 "data/maps/RusturfTunnel/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchWandaExit
# 138 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDA, RusturfTunnel_Movement_WandaExit
# 139 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendExit
# 140 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 141 "data/maps/RusturfTunnel/scripts.pory"
	return
# 142 "data/maps/RusturfTunnel/scripts.pory"

# 143 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_WandasBoyfriendNotice::
# 144 "data/maps/RusturfTunnel/scripts.pory"
	playse SE_PIN
# 145 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, Common_Movement_ExclamationMark
# 146 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 147 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, Common_Movement_Delay48
# 148 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 149 "data/maps/RusturfTunnel/scripts.pory"
	return
# 150 "data/maps/RusturfTunnel/scripts.pory"

# 151 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_WandaExit1:
# 152 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 153 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 154 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 155 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 156 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 157 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 158 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 159 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 160 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 161 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 162 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 163 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 164 "data/maps/RusturfTunnel/scripts.pory"

# 165 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_WandaExit:
# 166 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 167 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 168 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 169 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 170 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 171 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 172 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 173 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 174 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 175 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 176 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 177 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 178 "data/maps/RusturfTunnel/scripts.pory"

# 179 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PlayerWatchWandaExit:
# 180 "data/maps/RusturfTunnel/scripts.pory"
	delay_8
# 181 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_up
# 182 "data/maps/RusturfTunnel/scripts.pory"
	delay_16
# 183 "data/maps/RusturfTunnel/scripts.pory"
	delay_16
# 184 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_right
# 185 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 186 "data/maps/RusturfTunnel/scripts.pory"

# 187 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_Unused1:
# 188 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 189 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_right
# 190 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 191 "data/maps/RusturfTunnel/scripts.pory"

# 192 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_Unused2:
# 193 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 194 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_up
# 195 "data/maps/RusturfTunnel/scripts.pory"
	delay_8
# 196 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_right
# 197 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 198 "data/maps/RusturfTunnel/scripts.pory"

# 199 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_Unused3:
# 200 "data/maps/RusturfTunnel/scripts.pory"
	walk_up
# 201 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_down
# 202 "data/maps/RusturfTunnel/scripts.pory"
	delay_8
# 203 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_right
# 204 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 205 "data/maps/RusturfTunnel/scripts.pory"

# 206 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PlayerWatchBoyfriend1:
# 207 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 208 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_right
# 209 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 210 "data/maps/RusturfTunnel/scripts.pory"

# 211 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PlayerWatchBoyfriend:
# 212 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 213 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_left
# 214 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 215 "data/maps/RusturfTunnel/scripts.pory"

# 216 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BoyfriendFaceRight:
# 217 "data/maps/RusturfTunnel/scripts.pory"
	walk_up
# 218 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_right
# 219 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 220 "data/maps/RusturfTunnel/scripts.pory"

# 221 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_WandasBoyfriendExit1:
# 222 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 223 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 224 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 225 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 226 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 227 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 228 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 229 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 230 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 231 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 232 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 233 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 234 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 235 "data/maps/RusturfTunnel/scripts.pory"

# 236 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_WandasBoyfriendExit:
# 237 "data/maps/RusturfTunnel/scripts.pory"
	walk_up
# 238 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 239 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 240 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 241 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 242 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 243 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 244 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 245 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 246 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 247 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 248 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 249 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 250 "data/maps/RusturfTunnel/scripts.pory"

# 251 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_WandasBoyfriendApproachPlayer:
# 252 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 253 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 254 "data/maps/RusturfTunnel/scripts.pory"

# 255 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BoyfriendApproachWanda1:
# 256 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fast_up
# 257 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fast_up
# 258 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_up
# 259 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_right
# 260 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 261 "data/maps/RusturfTunnel/scripts.pory"

# 262 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BoyfriendApproachWanda:
# 263 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fast_right
# 264 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fast_right
# 265 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_right
# 266 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_up
# 267 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 268 "data/maps/RusturfTunnel/scripts.pory"

# 269 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_TunnelBlockagePos1::
# 270 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_TEMP_1, 1
# 271 "data/maps/RusturfTunnel/scripts.pory"
	end
# 272 "data/maps/RusturfTunnel/scripts.pory"

# 273 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_TunnelBlockagePos2::
# 274 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_TEMP_1, 2
# 275 "data/maps/RusturfTunnel/scripts.pory"
	end
# 276 "data/maps/RusturfTunnel/scripts.pory"

# 277 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_TunnelBlockagePos3::
# 278 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_TEMP_1, 3
# 279 "data/maps/RusturfTunnel/scripts.pory"
	end
# 280 "data/maps/RusturfTunnel/scripts.pory"

# 281 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_AquaGruntBackUp::
# 282 "data/maps/RusturfTunnel/scripts.pory"
	lockall
# 283 "data/maps/RusturfTunnel/scripts.pory"
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
# 284 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_ComeAndGetSome, MSGBOX_DEFAULT
# 285 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 286 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_GRUNT, RusturfTunnel_Movement_GruntAndPeekoBackUp
# 287 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_PEEKO, RusturfTunnel_Movement_GruntAndPeekoBackUp
# 288 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 289 "data/maps/RusturfTunnel/scripts.pory"
	copyobjectxytoperm LOCALID_GRUNT
# 290 "data/maps/RusturfTunnel/scripts.pory"
	copyobjectxytoperm LOCALID_PEEKO
# 291 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_RUSTURF_TUNNEL_STATE, 3
# 292 "data/maps/RusturfTunnel/scripts.pory"
	releaseall
# 293 "data/maps/RusturfTunnel/scripts.pory"
	end
# 294 "data/maps/RusturfTunnel/scripts.pory"

# 295 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_GruntAndPeekoBackUp:
# 296 "data/maps/RusturfTunnel/scripts.pory"
	lock_facing_direction
# 297 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 298 "data/maps/RusturfTunnel/scripts.pory"
	unlock_facing_direction
# 299 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 300 "data/maps/RusturfTunnel/scripts.pory"

# 301 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_Peeko::
# 302 "data/maps/RusturfTunnel/scripts.pory"
	lock
# 303 "data/maps/RusturfTunnel/scripts.pory"
	faceplayer
# 304 "data/maps/RusturfTunnel/scripts.pory"
	waitse
# 305 "data/maps/RusturfTunnel/scripts.pory"
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
# 306 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_Peeko, MSGBOX_DEFAULT
# 307 "data/maps/RusturfTunnel/scripts.pory"
	waitmoncry
# 308 "data/maps/RusturfTunnel/scripts.pory"
	release
# 309 "data/maps/RusturfTunnel/scripts.pory"
	end
# 310 "data/maps/RusturfTunnel/scripts.pory"

# 311 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_Grunt::
# 312 "data/maps/RusturfTunnel/scripts.pory"
	lock
# 313 "data/maps/RusturfTunnel/scripts.pory"
	faceplayer
# 314 "data/maps/RusturfTunnel/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 315 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_GruntIntro, MSGBOX_DEFAULT
# 316 "data/maps/RusturfTunnel/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_RUSTURF_TUNNEL, RusturfTunnel_Text_GruntDefeat
# 317 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_GruntTakePackage, MSGBOX_DEFAULT
# 318 "data/maps/RusturfTunnel/scripts.pory"
	giveitem ITEM_DEVON_PARTS
# 319 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 320 "data/maps/RusturfTunnel/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PushPlayerAsideForGrunt
# 321 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_GRUNT, RusturfTunnel_Movement_GruntEscape
# 322 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 323 "data/maps/RusturfTunnel/scripts.pory"
	removeobject LOCALID_GRUNT
# 324 "data/maps/RusturfTunnel/scripts.pory"
	delay 50
# 325 "data/maps/RusturfTunnel/scripts.pory"
	addobject LOCALID_BRINEY
# 326 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_BRINEY, RusturfTunnel_Movement_BrineyApproachPeeko1
# 327 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 328 "data/maps/RusturfTunnel/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerMoveAsideForBriney
# 329 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_BRINEY, RusturfTunnel_Movement_BrineyApproachPeeko2
# 330 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 331 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_PeekoGladToSeeYouSafe, MSGBOX_DEFAULT
# 332 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_BRINEY, Common_Movement_FacePlayer
# 333 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 334 "data/maps/RusturfTunnel/scripts.pory"
	message RusturfTunnel_Text_ThankYouLetsGoHomePeeko
# 335 "data/maps/RusturfTunnel/scripts.pory"
	waitmessage
# 336 "data/maps/RusturfTunnel/scripts.pory"
	waitse
# 337 "data/maps/RusturfTunnel/scripts.pory"
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
# 338 "data/maps/RusturfTunnel/scripts.pory"
	waitbuttonpress
# 339 "data/maps/RusturfTunnel/scripts.pory"
	waitmoncry
# 340 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 341 "data/maps/RusturfTunnel/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchBrineyExit
# 342 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_BRINEY, RusturfTunnel_Movement_BrineyExit
# 343 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_PEEKO, RusturfTunnel_Movement_PeekoExit
# 344 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 345 "data/maps/RusturfTunnel/scripts.pory"
	removeobject LOCALID_BRINEY
# 346 "data/maps/RusturfTunnel/scripts.pory"
	removeobject LOCALID_PEEKO
# 347 "data/maps/RusturfTunnel/scripts.pory"
	clearflag FLAG_DEVON_GOODS_STOLEN
# 348 "data/maps/RusturfTunnel/scripts.pory"
	setflag FLAG_RECOVERED_DEVON_GOODS
# 349 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 4
# 350 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_BRINEY_HOUSE_STATE, 1
# 351 "data/maps/RusturfTunnel/scripts.pory"
	setflag FLAG_HIDE_ROUTE_116_MR_BRINEY
# 352 "data/maps/RusturfTunnel/scripts.pory"
	release
# 353 "data/maps/RusturfTunnel/scripts.pory"
	end
# 354 "data/maps/RusturfTunnel/scripts.pory"

# 355 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PushPlayerAsideForGrunt:
# 356 "data/maps/RusturfTunnel/scripts.pory"
	face_down
# 357 "data/maps/RusturfTunnel/scripts.pory"
	lock_facing_direction
# 358 "data/maps/RusturfTunnel/scripts.pory"
	walk_up
# 359 "data/maps/RusturfTunnel/scripts.pory"
	unlock_facing_direction
# 360 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_left
# 361 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 362 "data/maps/RusturfTunnel/scripts.pory"

# 363 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PlayerMoveAsideForBriney:
# 364 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 365 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_up
# 366 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 367 "data/maps/RusturfTunnel/scripts.pory"

# 368 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_GruntEscape:
# 369 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 370 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 371 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 372 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 373 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 374 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 375 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 376 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 377 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 378 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 379 "data/maps/RusturfTunnel/scripts.pory"

# 380 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BrineyApproachPeeko1:
# 381 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 382 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 383 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 384 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 385 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 386 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 387 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 388 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 389 "data/maps/RusturfTunnel/scripts.pory"

# 390 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BrineyExit:
# 391 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 392 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 393 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 394 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 395 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 396 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 397 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 398 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 399 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 400 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 401 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 402 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 403 "data/maps/RusturfTunnel/scripts.pory"

# 404 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PlayerWatchBrineyExit:
# 405 "data/maps/RusturfTunnel/scripts.pory"
	delay_16
# 406 "data/maps/RusturfTunnel/scripts.pory"
	delay_8
# 407 "data/maps/RusturfTunnel/scripts.pory"
	delay_4
# 408 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_left
# 409 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 410 "data/maps/RusturfTunnel/scripts.pory"

# 411 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BrineyApproachPeeko2:
# 412 "data/maps/RusturfTunnel/scripts.pory"
	delay_16
# 413 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 414 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 415 "data/maps/RusturfTunnel/scripts.pory"

# 416 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PeekoExit:
# 417 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 418 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 419 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 420 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 421 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 422 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 423 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 424 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 425 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 426 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 427 "data/maps/RusturfTunnel/scripts.pory"

# 428 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_Mike::
# 429 "data/maps/RusturfTunnel/scripts.pory"
	trainerbattle_single TRAINER_MIKE_2, RusturfTunnel_Text_MikeIntro, RusturfTunnel_Text_MikeDefeat
# 430 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_MikePostBattle, MSGBOX_AUTOCLOSE
# 431 "data/maps/RusturfTunnel/scripts.pory"
	end
# 432 "data/maps/RusturfTunnel/scripts.pory"

# 433 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_ComeAndGetSome:
# 434 "data/maps/RusturfTunnel/scripts.pory"
	.string "What, are you coming?\n"
# 435 "data/maps/RusturfTunnel/scripts.pory"
	.string "Come and get some, then!$"
# 436 "data/maps/RusturfTunnel/scripts.pory"

# 437 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_Peeko:
# 438 "data/maps/RusturfTunnel/scripts.pory"
	.string "PEEKO: Pii pihyoh!$"
# 439 "data/maps/RusturfTunnel/scripts.pory"

# 440 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_GruntIntro:
# 441 "data/maps/RusturfTunnel/scripts.pory"
	.string "Grah, keelhaul it all!\p"
# 442 "data/maps/RusturfTunnel/scripts.pory"
	.string "That hostage POKéMON turned out to\n"
# 443 "data/maps/RusturfTunnel/scripts.pory"
	.string "be worthless!\p"
# 444 "data/maps/RusturfTunnel/scripts.pory"
	.string "And to think I made a getaway…\n"
# 445 "data/maps/RusturfTunnel/scripts.pory"
	.string "In this tunnel to nowhere!\p"
# 446 "data/maps/RusturfTunnel/scripts.pory"
	.string "Hey! You!\n"
# 447 "data/maps/RusturfTunnel/scripts.pory"
	.string "So you want to battle me?$"
# 448 "data/maps/RusturfTunnel/scripts.pory"

# 449 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_GruntDefeat:
# 450 "data/maps/RusturfTunnel/scripts.pory"
	.string "Urrrggh! My career in crime comes to\n"
# 451 "data/maps/RusturfTunnel/scripts.pory"
	.string "a dead end!$"
# 452 "data/maps/RusturfTunnel/scripts.pory"

# 453 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_GruntTakePackage:
# 454 "data/maps/RusturfTunnel/scripts.pory"
	.string "This is plain not right…\p"
# 455 "data/maps/RusturfTunnel/scripts.pory"
	.string "The BOSS told me this would be a\n"
# 456 "data/maps/RusturfTunnel/scripts.pory"
	.string "slick-and-easy job to pull.\p"
# 457 "data/maps/RusturfTunnel/scripts.pory"
	.string "All I had to do was steal some package\n"
# 458 "data/maps/RusturfTunnel/scripts.pory"
	.string "from DEVON.\p"
# 459 "data/maps/RusturfTunnel/scripts.pory"
	.string "Tch!\n"
# 460 "data/maps/RusturfTunnel/scripts.pory"
	.string "You want it back that badly, take it!$"
# 461 "data/maps/RusturfTunnel/scripts.pory"

# 462 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_PeekoGladToSeeYouSafe:
# 463 "data/maps/RusturfTunnel/scripts.pory"
	.string "PEEKO!\n"
# 464 "data/maps/RusturfTunnel/scripts.pory"
	.string "Am I glad to see you're safe!$"
# 465 "data/maps/RusturfTunnel/scripts.pory"

# 466 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_ThankYouLetsGoHomePeeko:
# 467 "data/maps/RusturfTunnel/scripts.pory"
	.string "PEEKO owes her life to you!\p"
# 468 "data/maps/RusturfTunnel/scripts.pory"
	.string "They call me MR. BRINEY.\n"
# 469 "data/maps/RusturfTunnel/scripts.pory"
	.string "And, you are?\p"
# 470 "data/maps/RusturfTunnel/scripts.pory"
	.string "… … … … … … … …\n"
# 471 "data/maps/RusturfTunnel/scripts.pory"
	.string "… … … … … … … …\p"
# 472 "data/maps/RusturfTunnel/scripts.pory"
	.string "Ah, so you are {PLAYER}{KUN}!\n"
# 473 "data/maps/RusturfTunnel/scripts.pory"
	.string "I sincerely thank you!\p"
# 474 "data/maps/RusturfTunnel/scripts.pory"
	.string "Now, if there's anything that troubles\n"
# 475 "data/maps/RusturfTunnel/scripts.pory"
	.string "you, don't hesitate to tell me!\p"
# 476 "data/maps/RusturfTunnel/scripts.pory"
	.string "You can usually find me in my cottage\n"
# 477 "data/maps/RusturfTunnel/scripts.pory"
	.string "by the sea near PETALBURG WOODS.\p"
# 478 "data/maps/RusturfTunnel/scripts.pory"
	.string "Come, PEEKO, we should make our way\n"
# 479 "data/maps/RusturfTunnel/scripts.pory"
	.string "home.\p"
# 480 "data/maps/RusturfTunnel/scripts.pory"
	.string "PEEKO: Pihyoh!$"
# 481 "data/maps/RusturfTunnel/scripts.pory"

# 482 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_WhyCantTheyKeepDigging:
# 483 "data/maps/RusturfTunnel/scripts.pory"
	.string "… …\p"
# 484 "data/maps/RusturfTunnel/scripts.pory"
	.string "Why can't they keep digging?\n"
# 485 "data/maps/RusturfTunnel/scripts.pory"
	.string "Is the bedrock too hard?\p"
# 486 "data/maps/RusturfTunnel/scripts.pory"
	.string "My beloved awaits me in VERDANTURF\n"
# 487 "data/maps/RusturfTunnel/scripts.pory"
	.string "TOWN just beyond here…\p"
# 488 "data/maps/RusturfTunnel/scripts.pory"
	.string "If RUSTBORO and VERDANTURF were\n"
# 489 "data/maps/RusturfTunnel/scripts.pory"
	.string "joined by this tunnel, I could visit\l"
# 490 "data/maps/RusturfTunnel/scripts.pory"
	.string "her every day…\p"
# 491 "data/maps/RusturfTunnel/scripts.pory"
	.string "But this…\n"
# 492 "data/maps/RusturfTunnel/scripts.pory"
	.string "What am I to do?$"
# 493 "data/maps/RusturfTunnel/scripts.pory"

# 494 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_ToGetToVerdanturf:
# 495 "data/maps/RusturfTunnel/scripts.pory"
	.string "To get from RUSTBORO to VERDANTURF,\n"
# 496 "data/maps/RusturfTunnel/scripts.pory"
	.string "you need to go to DEWFORD, then pass\l"
# 497 "data/maps/RusturfTunnel/scripts.pory"
	.string "through SLATEPORT and MAUVILLE…$"
# 498 "data/maps/RusturfTunnel/scripts.pory"

# 499 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_YouShatteredBoulderTakeHM:
# 500 "data/maps/RusturfTunnel/scripts.pory"
	.string "Wow! You shattered that boulder\n"
# 501 "data/maps/RusturfTunnel/scripts.pory"
	.string "blocking the way.\p"
# 502 "data/maps/RusturfTunnel/scripts.pory"
	.string "To show you how much I appreciate it,\n"
# 503 "data/maps/RusturfTunnel/scripts.pory"
	.string "I'd like you to have this HM.$"
# 504 "data/maps/RusturfTunnel/scripts.pory"

# 505 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_ExplainStrength:
# 506 "data/maps/RusturfTunnel/scripts.pory"
	.string "That HM contains STRENGTH.\p"
# 507 "data/maps/RusturfTunnel/scripts.pory"
	.string "If a muscular POKéMON were to learn\n"
# 508 "data/maps/RusturfTunnel/scripts.pory"
	.string "that, it would be able to move even\l"
# 509 "data/maps/RusturfTunnel/scripts.pory"
	.string "large boulders.$"
# 510 "data/maps/RusturfTunnel/scripts.pory"

# 511 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_WandaReunion:
# 512 "data/maps/RusturfTunnel/scripts.pory"
	.string "WANDA!\n"
# 513 "data/maps/RusturfTunnel/scripts.pory"
	.string "Now I can see you anytime!\p"
# 514 "data/maps/RusturfTunnel/scripts.pory"
	.string "WANDA: That's…wonderful.\p"
# 515 "data/maps/RusturfTunnel/scripts.pory"
	.string "Please, take some rest at my home.$"
# 516 "data/maps/RusturfTunnel/scripts.pory"

# 517 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_BoyfriendOnOtherSideOfRock:
# 518 "data/maps/RusturfTunnel/scripts.pory"
	.string "On the other side of this rock…\n"
# 519 "data/maps/RusturfTunnel/scripts.pory"
	.string "My boyfriend is there.\p"
# 520 "data/maps/RusturfTunnel/scripts.pory"
	.string "He… He's not just digging the tunnel\n"
# 521 "data/maps/RusturfTunnel/scripts.pory"
	.string "to come see me.\p"
# 522 "data/maps/RusturfTunnel/scripts.pory"
	.string "He works his hands raw and rough\n"
# 523 "data/maps/RusturfTunnel/scripts.pory"
	.string "for the benefit of everyone.$"
# 524 "data/maps/RusturfTunnel/scripts.pory"

# 525 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_MikeIntro:
# 526 "data/maps/RusturfTunnel/scripts.pory"
	.string "What do you call a wild man up in the\n"
# 527 "data/maps/RusturfTunnel/scripts.pory"
	.string "mountains? A mountain man, right?\p"
# 528 "data/maps/RusturfTunnel/scripts.pory"
	.string "So why don't they call a POKéMON in\n"
# 529 "data/maps/RusturfTunnel/scripts.pory"
	.string "the mountains a mountain POKéMON?$"
# 530 "data/maps/RusturfTunnel/scripts.pory"

# 531 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_MikeDefeat:
# 532 "data/maps/RusturfTunnel/scripts.pory"
	.string "My POKéMON…\n"
# 533 "data/maps/RusturfTunnel/scripts.pory"
	.string "Ran out of power…$"
# 534 "data/maps/RusturfTunnel/scripts.pory"

# 535 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_MikePostBattle:
# 536 "data/maps/RusturfTunnel/scripts.pory"
	.string "They halted development here to\n"
# 537 "data/maps/RusturfTunnel/scripts.pory"
	.string "protect POKéMON, right?\l"
# 538 "data/maps/RusturfTunnel/scripts.pory"
	.string "There's a feel-good story!$"
