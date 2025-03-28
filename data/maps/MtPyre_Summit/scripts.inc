# 1 "data/maps/MtPyre_Summit/scripts.pory"

# 2 "data/maps/MtPyre_Summit/scripts.pory"
.set LOCALID_ARCHIE, 9
# 3 "data/maps/MtPyre_Summit/scripts.pory"
.set LOCALID_OLD_LADY, 3
# 4 "data/maps/MtPyre_Summit/scripts.pory"
.set LOCALID_GRUNT_1, 4
# 5 "data/maps/MtPyre_Summit/scripts.pory"
.set LOCALID_GRUNT_2, 5
# 6 "data/maps/MtPyre_Summit/scripts.pory"
.set LOCALID_GRUNT_3, 6
# 7 "data/maps/MtPyre_Summit/scripts.pory"
.set LOCALID_GRUNT_4, 7
# 8 "data/maps/MtPyre_Summit/scripts.pory"
.set LOCALID_MAXIE, 8
# 9 "data/maps/MtPyre_Summit/scripts.pory"
.set LOCALID_MATT, 10
# 10 "data/maps/MtPyre_Summit/scripts.pory"
.set LOCALID_RIVAL, 11
# 11 "data/maps/MtPyre_Summit/scripts.pory"

# 12 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_MapScripts::
# 13 "data/maps/MtPyre_Summit/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_OnTransition
# 14 "data/maps/MtPyre_Summit/scripts.pory"
	.byte 0
# 15 "data/maps/MtPyre_Summit/scripts.pory"

# 16 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_OnTransition:
# 17 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_MT_PYRE_STATE, 2, MtPyre_Summit_EventScript_SetArchieMaxiePositions
# 18 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 19 "data/maps/MtPyre_Summit/scripts.pory"

# 20 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_SetArchieMaxiePositions::
# 21 "data/maps/MtPyre_Summit/scripts.pory"
	setobjectxyperm LOCALID_MAXIE, 23, 6
# 22 "data/maps/MtPyre_Summit/scripts.pory"
	setobjectxyperm LOCALID_ARCHIE, 22, 6
# 23 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 24 "data/maps/MtPyre_Summit/scripts.pory"

# 25 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_TeamAquaTrigger0::
# 26 "data/maps/MtPyre_Summit/scripts.pory"
	lockall
# 27 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_0x8008, 0
# 28 "data/maps/MtPyre_Summit/scripts.pory"
	goto MtPyre_Summit_EventScript_TeamAquaExits
# 29 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 30 "data/maps/MtPyre_Summit/scripts.pory"

# 31 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_TeamAquaTrigger1::
# 32 "data/maps/MtPyre_Summit/scripts.pory"
	lockall
# 33 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_0x8008, 1
# 34 "data/maps/MtPyre_Summit/scripts.pory"
	goto MtPyre_Summit_EventScript_TeamAquaExits
# 35 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 36 "data/maps/MtPyre_Summit/scripts.pory"

# 37 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_TeamAquaTrigger2::
# 38 "data/maps/MtPyre_Summit/scripts.pory"
	lockall
# 39 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_0x8008, 2
# 40 "data/maps/MtPyre_Summit/scripts.pory"
	goto MtPyre_Summit_EventScript_TeamAquaExits
# 41 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 42 "data/maps/MtPyre_Summit/scripts.pory"

# 43 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_TeamAquaExits::
# 44 "data/maps/MtPyre_Summit/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 45 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 46 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 47 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterDown
# 48 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 49 "data/maps/MtPyre_Summit/scripts.pory"
	delay 50
# 50 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieFacePlayer0
# 51 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieFacePlayer1
# 52 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieFacePlayer2
# 53 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo, MSGBOX_DEFAULT
# 54 "data/maps/MtPyre_Summit/scripts.pory"
	closemessage
# 55 "data/maps/MtPyre_Summit/scripts.pory"
	fadescreen FADE_TO_BLACK
# 56 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_ARCHIE
# 57 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_GRUNT_1
# 58 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_GRUNT_2
# 59 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_GRUNT_3
# 60 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_GRUNT_4
# 61 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_MATT
# 62 "data/maps/MtPyre_Summit/scripts.pory"
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
# 63 "data/maps/MtPyre_Summit/scripts.pory"
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
# 64 "data/maps/MtPyre_Summit/scripts.pory"
	fadedefaultbgm
# 65 "data/maps/MtPyre_Summit/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 66 "data/maps/MtPyre_Summit/scripts.pory"
	delay 20
# 67 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_MT_PYRE_STATE, 1
# 68 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_OldLadyApproachPlayer0
# 69 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_OldLadyApproachPlayer1
# 70 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_OldLadyApproachPlayer2
# 71 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis, MSGBOX_DEFAULT
# 72 "data/maps/MtPyre_Summit/scripts.pory"
	giveitem ITEM_MAGMA_EMBLEM
# 73 "data/maps/MtPyre_Summit/scripts.pory"
	setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
# 74 "data/maps/MtPyre_Summit/scripts.pory"
	setflag FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
# 75 "data/maps/MtPyre_Summit/scripts.pory"
	releaseall
# 76 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 77 "data/maps/MtPyre_Summit/scripts.pory"

# 78 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieFacePlayer0::
# 79 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer0
# 80 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 81 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 82 "data/maps/MtPyre_Summit/scripts.pory"

# 83 "data/maps/MtPyre_Summit/scripts.pory"
@ Archie is already facing player
# 84 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieFacePlayer1::
# 85 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 86 "data/maps/MtPyre_Summit/scripts.pory"

# 87 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieFacePlayer2::
# 88 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer2
# 89 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 90 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 91 "data/maps/MtPyre_Summit/scripts.pory"

# 92 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLadyApproachPlayer0::
# 93 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_RIVAL, MtPyre_Summit_Movement_RivalWalkToSide
# 94 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 95 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer0
# 96 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 97 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 98 "data/maps/MtPyre_Summit/scripts.pory"

# 99 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLadyApproachPlayer1::
# 100 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_RIVAL, MtPyre_Summit_Movement_RivalWalkToSide
# 101 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 102 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer1
# 103 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 104 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 105 "data/maps/MtPyre_Summit/scripts.pory"

# 106 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_RivalWalkToSide::
# 107 "data/maps/MtPyre_Summit/scripts.pory"
	walk_right
# 108 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_left
# 109 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 110 "data/maps/MtPyre_Summit/scripts.pory"

# 111 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLadyApproachPlayer2::
# 112 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_RIVAL, MtPyre_Summit_Movement_RivalWalkToSide
# 113 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 114 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer2
# 115 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 116 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 117 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 118 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 119 "data/maps/MtPyre_Summit/scripts.pory"

# 120 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_OldLadyApproachPlayer0:
# 121 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 122 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 123 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_down
# 124 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 125 "data/maps/MtPyre_Summit/scripts.pory"

# 126 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_OldLadyApproachPlayer1:
# 127 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 128 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 129 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_down
# 130 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 131 "data/maps/MtPyre_Summit/scripts.pory"

# 132 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_OldLadyApproachPlayer2:
# 133 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 134 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 135 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_down
# 136 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 137 "data/maps/MtPyre_Summit/scripts.pory"

# 138 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_ArchieFacePlayer0:
# 139 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 140 "data/maps/MtPyre_Summit/scripts.pory"
	walk_right
# 141 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 142 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_down
# 143 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 144 "data/maps/MtPyre_Summit/scripts.pory"

# 145 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_ArchieFacePlayer2:
# 146 "data/maps/MtPyre_Summit/scripts.pory"
	walk_right
# 147 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_down
# 148 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 149 "data/maps/MtPyre_Summit/scripts.pory"

# 150 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldMan::
# 151 "data/maps/MtPyre_Summit/scripts.pory"
	lock
# 152 "data/maps/MtPyre_Summit/scripts.pory"
	faceplayer
# 153 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, MtPyre_Summit_EventScript_OldManAfterRayquaza
# 154 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_WillYouHearOutMyTale, MSGBOX_YESNO
# 155 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManTale
# 156 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
# 157 "data/maps/MtPyre_Summit/scripts.pory"
	release
# 158 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 159 "data/maps/MtPyre_Summit/scripts.pory"

# 160 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldManAfterRayquaza::
# 161 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_HearTheNewLegendOfHoenn, MSGBOX_YESNO
# 162 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManNewTale
# 163 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
# 164 "data/maps/MtPyre_Summit/scripts.pory"
	release
# 165 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 166 "data/maps/MtPyre_Summit/scripts.pory"

# 167 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldManTale::
# 168 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_GroudonKyogreTale, MSGBOX_DEFAULT
# 169 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 170 "data/maps/MtPyre_Summit/scripts.pory"

# 171 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_DeclineOldManTale::
# 172 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_WellThatTooIsFine, MSGBOX_DEFAULT
# 173 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 174 "data/maps/MtPyre_Summit/scripts.pory"

# 175 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldManNewTale::
# 176 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_HoennTrioTale, MSGBOX_DEFAULT
# 177 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 178 "data/maps/MtPyre_Summit/scripts.pory"

# 179 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLady::
# 180 "data/maps/MtPyre_Summit/scripts.pory"
	lock
# 181 "data/maps/MtPyre_Summit/scripts.pory"
	faceplayer
# 182 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_set FLAG_RETURNED_RED_OR_BLUE_ORB, MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned
# 183 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_ge VAR_MT_PYRE_STATE, 3, MtPyre_Summit_EventScript_OldLadyOrbsReturned
# 184 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, MtPyre_Summit_EventScript_OldLadyLegendariesAwake
# 185 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_OrbsHaveBeenTaken, MSGBOX_DEFAULT
# 186 "data/maps/MtPyre_Summit/scripts.pory"
	release
# 187 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 188 "data/maps/MtPyre_Summit/scripts.pory"

# 189 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLadyOrbsReturned::
# 190 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs, MSGBOX_DEFAULT
# 191 "data/maps/MtPyre_Summit/scripts.pory"
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
# 192 "data/maps/MtPyre_Summit/scripts.pory"
	release
# 193 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 194 "data/maps/MtPyre_Summit/scripts.pory"

# 195 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLadyLegendariesAwake::
# 196 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_GroudonKyogreAwakened, MSGBOX_DEFAULT
# 197 "data/maps/MtPyre_Summit/scripts.pory"
	release
# 198 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 199 "data/maps/MtPyre_Summit/scripts.pory"

# 200 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned::
# 201 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_SuperAncientPokemonTaughtUs, MSGBOX_DEFAULT
# 202 "data/maps/MtPyre_Summit/scripts.pory"
	release
# 203 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 204 "data/maps/MtPyre_Summit/scripts.pory"

# 205 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieTrigger0::
# 206 "data/maps/MtPyre_Summit/scripts.pory"
	lockall
# 207 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_0x8008, 0
# 208 "data/maps/MtPyre_Summit/scripts.pory"
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
# 209 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 210 "data/maps/MtPyre_Summit/scripts.pory"

# 211 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieTrigger1::
# 212 "data/maps/MtPyre_Summit/scripts.pory"
	lockall
# 213 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_0x8008, 1
# 214 "data/maps/MtPyre_Summit/scripts.pory"
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
# 215 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 216 "data/maps/MtPyre_Summit/scripts.pory"

# 217 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieTrigger2::
# 218 "data/maps/MtPyre_Summit/scripts.pory"
	lockall
# 219 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_0x8008, 2
# 220 "data/maps/MtPyre_Summit/scripts.pory"
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
# 221 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 222 "data/maps/MtPyre_Summit/scripts.pory"

# 223 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs::
# 224 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 225 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 226 "data/maps/MtPyre_Summit/scripts.pory"
	delay 60
# 227 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieMaxieBeginExit0
# 228 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieMaxieBeginExit1
# 229 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieMaxieBeginExit2
# 230 "data/maps/MtPyre_Summit/scripts.pory"
	playse SE_PIN
# 231 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_ExclamationMark
# 232 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 233 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_Delay48
# 234 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 235 "data/maps/MtPyre_Summit/scripts.pory"
	delay 30
# 236 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachPlayer0
# 237 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachPlayer1
# 238 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachPlayer2
# 239 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_MaxieSilence, MSGBOX_DEFAULT
# 240 "data/maps/MtPyre_Summit/scripts.pory"
	closemessage
# 241 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachArchie0
# 242 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachArchie1
# 243 "data/maps/MtPyre_Summit/scripts.pory"
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachArchie2
# 244 "data/maps/MtPyre_Summit/scripts.pory"
	delay 30
# 245 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
# 246 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
# 247 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 248 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_ARCHIE
# 249 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_MAXIE
# 250 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_MT_PYRE_STATE, 3
# 251 "data/maps/MtPyre_Summit/scripts.pory"
	releaseall
# 252 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 253 "data/maps/MtPyre_Summit/scripts.pory"

# 254 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieBeginExit0::
# 255 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0
# 256 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
# 257 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
# 258 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 259 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 260 "data/maps/MtPyre_Summit/scripts.pory"

# 261 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieBeginExit1::
# 262 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1
# 263 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
# 264 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
# 265 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 266 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 267 "data/maps/MtPyre_Summit/scripts.pory"

# 268 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ArchieMaxieBeginExit2::
# 269 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2
# 270 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
# 271 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
# 272 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 273 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 274 "data/maps/MtPyre_Summit/scripts.pory"

# 275 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_MaxieApproachPlayer0::
# 276 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie0
# 277 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
# 278 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer0
# 279 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 280 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 281 "data/maps/MtPyre_Summit/scripts.pory"

# 282 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_MaxieApproachPlayer1::
# 283 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
# 284 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
# 285 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer1
# 286 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 287 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 288 "data/maps/MtPyre_Summit/scripts.pory"

# 289 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_MaxieApproachPlayer2::
# 290 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
# 291 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
# 292 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer2
# 293 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 294 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 295 "data/maps/MtPyre_Summit/scripts.pory"

# 296 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_MaxieApproachArchie0::
# 297 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
# 298 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie0
# 299 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 300 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
# 301 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 302 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 303 "data/maps/MtPyre_Summit/scripts.pory"

# 304 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_MaxieApproachArchie1::
# 305 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
# 306 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie1
# 307 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 308 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
# 309 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 310 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 311 "data/maps/MtPyre_Summit/scripts.pory"

# 312 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_MaxieApproachArchie2::
# 313 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
# 314 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie2
# 315 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 316 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
# 317 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 318 "data/maps/MtPyre_Summit/scripts.pory"
	return
# 319 "data/maps/MtPyre_Summit/scripts.pory"

# 320 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PlayerFaceMaxie0:
# 321 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 322 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 323 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_right
# 324 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 325 "data/maps/MtPyre_Summit/scripts.pory"

# 326 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PlayerFaceMaxie:
# 327 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 328 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 329 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_left
# 330 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 331 "data/maps/MtPyre_Summit/scripts.pory"

# 332 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_ArchieExit:
# 333 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 334 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 335 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 336 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 337 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 338 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 339 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 340 "data/maps/MtPyre_Summit/scripts.pory"

# 341 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieExit:
# 342 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 343 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 344 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 345 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 346 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 347 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 348 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 349 "data/maps/MtPyre_Summit/scripts.pory"

# 350 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0:
# 351 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 352 "data/maps/MtPyre_Summit/scripts.pory"
	delay_8
# 353 "data/maps/MtPyre_Summit/scripts.pory"
	walk_left
# 354 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_right
# 355 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 356 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_down
# 357 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 358 "data/maps/MtPyre_Summit/scripts.pory"

# 359 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1:
# 360 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 361 "data/maps/MtPyre_Summit/scripts.pory"
	delay_8
# 362 "data/maps/MtPyre_Summit/scripts.pory"
	walk_right
# 363 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_left
# 364 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 365 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_down
# 366 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 367 "data/maps/MtPyre_Summit/scripts.pory"

# 368 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2:
# 369 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 370 "data/maps/MtPyre_Summit/scripts.pory"
	delay_8
# 371 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_left
# 372 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 373 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_down
# 374 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 375 "data/maps/MtPyre_Summit/scripts.pory"

# 376 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieApproachPlayer0:
# 377 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 378 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 379 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 380 "data/maps/MtPyre_Summit/scripts.pory"
	walk_left
# 381 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 382 "data/maps/MtPyre_Summit/scripts.pory"

# 383 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieApproachPlayer1:
# 384 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 385 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 386 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 387 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_right
# 388 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 389 "data/maps/MtPyre_Summit/scripts.pory"

# 390 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieApproachPlayer2:
# 391 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 392 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 393 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 394 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_right
# 395 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 396 "data/maps/MtPyre_Summit/scripts.pory"

# 397 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_ArchieWatchMaxie:
# 398 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 399 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_up
# 400 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 401 "data/maps/MtPyre_Summit/scripts.pory"

# 402 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PlayerWatchMaxie:
# 403 "data/maps/MtPyre_Summit/scripts.pory"
	delay_16
# 404 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_down
# 405 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 406 "data/maps/MtPyre_Summit/scripts.pory"

# 407 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieApproachArchie0:
# 408 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 409 "data/maps/MtPyre_Summit/scripts.pory"
	walk_right
# 410 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 411 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 412 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_left
# 413 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 414 "data/maps/MtPyre_Summit/scripts.pory"

# 415 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieApproachArchie1:
# 416 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 417 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 418 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 419 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_left
# 420 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 421 "data/maps/MtPyre_Summit/scripts.pory"

# 422 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_MaxieApproachArchie2:
# 423 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 424 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 425 "data/maps/MtPyre_Summit/scripts.pory"
	walk_down
# 426 "data/maps/MtPyre_Summit/scripts.pory"
	walk_in_place_faster_left
# 427 "data/maps/MtPyre_Summit/scripts.pory"
	step_end
# 428 "data/maps/MtPyre_Summit/scripts.pory"

# 429 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_Grunt1::
# 430 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_1, MtPyre_Summit_Text_Grunt1Intro, MtPyre_Summit_Text_Grunt1Defeat
# 431 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
# 432 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 433 "data/maps/MtPyre_Summit/scripts.pory"

# 434 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_Grunt2::
# 435 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_2, MtPyre_Summit_Text_Grunt2Intro, MtPyre_Summit_Text_Grunt2Defeat
# 436 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
# 437 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 438 "data/maps/MtPyre_Summit/scripts.pory"

# 439 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_Grunt3::
# 440 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_3, MtPyre_Summit_Text_Grunt3Intro, MtPyre_Summit_Text_Grunt3Defeat
# 441 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
# 442 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 443 "data/maps/MtPyre_Summit/scripts.pory"

# 444 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_Grunt4::
# 445 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_4, MtPyre_Summit_Text_Grunt4Intro, MtPyre_Summit_Text_Grunt4Defeat
# 446 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
# 447 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 448 "data/maps/MtPyre_Summit/scripts.pory"

# 449 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_RivalPostBattle::
# 450 "data/maps/MtPyre_Summit/scripts.pory"
	lockall
# 451 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_RivalThanks, MSGBOX_DEFAULT
# 452 "data/maps/MtPyre_Summit/scripts.pory"
	releaseall
# 453 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 454 "data/maps/MtPyre_Summit/scripts.pory"

# 455 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_Rival::
# 456 "data/maps/MtPyre_Summit/scripts.pory"
	lockall
# 457 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_set FLAG_DEFEATED_MTPYRE_TAG, MtPyre_Summit_EventScript_RivalPostBattle
# 458 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_set FLAG_INTERACTED_WITH_RIVAL_MTPYRE, MtPyre_Summit_EventScript_ReadyForBattlePrompt
# 459 "data/maps/MtPyre_Summit/scripts.pory"
	setflag FLAG_INTERACTED_WITH_RIVAL_MTPYRE
# 460 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_RivalHelpMeFight, MSGBOX_DEFAULT
# 461 "data/maps/MtPyre_Summit/scripts.pory"
	closemessage
# 462 "data/maps/MtPyre_Summit/scripts.pory"
	delay 30
# 463 "data/maps/MtPyre_Summit/scripts.pory"
	releaseall
# 464 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 465 "data/maps/MtPyre_Summit/scripts.pory"

# 466 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ReadyForBattlePrompt::
# 467 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_RivalAreYouReadyToBattle, MSGBOX_YESNO
# 468 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_ChoosePartyForMultiBattle
# 469 "data/maps/MtPyre_Summit/scripts.pory"
	releaseall
# 470 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 471 "data/maps/MtPyre_Summit/scripts.pory"

# 472 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_ChoosePartyForMultiBattle::
# 473 "data/maps/MtPyre_Summit/scripts.pory"
	special SavePlayerParty
# 474 "data/maps/MtPyre_Summit/scripts.pory"
	fadescreen FADE_TO_BLACK
# 475 "data/maps/MtPyre_Summit/scripts.pory"
	special ChooseHalfPartyForBattle
# 476 "data/maps/MtPyre_Summit/scripts.pory"
	waitstate
# 477 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_ne VAR_RESULT, 0, MtPyre_Summit_EventScript_DoRivalMultiBattle
# 478 "data/maps/MtPyre_Summit/scripts.pory"
	special LoadPlayerParty
# 479 "data/maps/MtPyre_Summit/scripts.pory"
	goto MtPyre_Summit_EventScript_ReadyForBattlePrompt
# 480 "data/maps/MtPyre_Summit/scripts.pory"

# 481 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_DoRivalMultiBattle::
# 482 "data/maps/MtPyre_Summit/scripts.pory"
	checkplayergender
# 483 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_eq VAR_RESULT, 1, MtPyre_Summit_EventScript_DoRivalMultiBattleBrendan
# 484 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_eq VAR_RESULT, 0, MtPyre_Summit_EventScript_DoRivalMultiBattleMay
# 485 "data/maps/MtPyre_Summit/scripts.pory"

# 486 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_DoRivalMultiBattleBrendan::
# 487 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_eq VAR_STARTER_MON, 0, MtPyre_Summit_EventScript_RivalMultiBattleBrendanSnivy
# 488 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_eq VAR_STARTER_MON, 1, MtPyre_Summit_EventScript_RivalMultiBattleBrendanScorbunny
# 489 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_eq VAR_STARTER_MON, 2, MtPyre_Summit_EventScript_RivalMultiBattleBrendanSquirtle
# 490 "data/maps/MtPyre_Summit/scripts.pory"

# 491 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_RivalMultiBattleBrendanSnivy::
# 492 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_unset FLAG_DEFEATED_FORTREE_GYM, MtPyre_Summit_EventScript_RivalMultiBattleBrendanSnivyPreWinona
# 493 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, MtPyre_Summit_EventScript_RivalMultiBattleBrendanSnivyPostWinona
# 494 "data/maps/MtPyre_Summit/scripts.pory"

# 495 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_RivalMultiBattleBrendanSnivyPreWinona::
# 496 "data/maps/MtPyre_Summit/scripts.pory"
	multi_2_vs_2 TRAINER_JUAN_3, MtPyre_Summit_Text_JustWantToExpandSea, TRAINER_JUAN_2, MtPyre_Summit_Text_MattDefeat, PARTNER_BRENDAN_SNIVY_PW
# 497 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_eq VAR_RESULT, 1, MtPyre_Summit_EventScript_DefeatedArchieMatt
# 498 "data/maps/MtPyre_Summit/scripts.pory"
	fadescreen FADE_TO_BLACK
# 499 "data/maps/MtPyre_Summit/scripts.pory"
	special SetCB2WhiteOut
# 500 "data/maps/MtPyre_Summit/scripts.pory"
	waitstate
# 501 "data/maps/MtPyre_Summit/scripts.pory"

# 502 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_RivalMultiBattleBrendanSnivyPostWinona::
# 503 "data/maps/MtPyre_Summit/scripts.pory"
	multi_2_vs_2 TRAINER_BRENDAN_PLACEHOLDER, MtPyre_Summit_Text_JustWantToExpandSea, TRAINER_LEAF, MtPyre_Summit_Text_MattDefeat, PARTNER_BRENDAN_SNIVY
# 504 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_eq VAR_RESULT, 1, MtPyre_Summit_EventScript_DefeatedArchieMatt
# 505 "data/maps/MtPyre_Summit/scripts.pory"
	fadescreen FADE_TO_BLACK
# 506 "data/maps/MtPyre_Summit/scripts.pory"
	special SetCB2WhiteOut
# 507 "data/maps/MtPyre_Summit/scripts.pory"
	waitstate
# 508 "data/maps/MtPyre_Summit/scripts.pory"

# 509 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_RivalMultiBattleBrendanScorbunny::
# 510 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_unset FLAG_DEFEATED_FORTREE_GYM, MtPyre_Summit_EventScript_RivalMultiBattleBrendanScorbunnyPreWinona
# 511 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, MtPyre_Summit_EventScript_RivalMultiBattleBrendanScorbunnyPostWinona
# 512 "data/maps/MtPyre_Summit/scripts.pory"

# 513 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_RivalMultiBattleBrendanScorbunnyPreWinona::
# 514 "data/maps/MtPyre_Summit/scripts.pory"
	multi_2_vs_2 TRAINER_JUAN_3, MtPyre_Summit_Text_JustWantToExpandSea, TRAINER_JUAN_2, MtPyre_Summit_Text_MattDefeat, PARTNER_BRENDAN_SCORBUNNY_PW
# 515 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_eq VAR_RESULT, 1, MtPyre_Summit_EventScript_DefeatedArchieMatt
# 516 "data/maps/MtPyre_Summit/scripts.pory"
	fadescreen FADE_TO_BLACK
# 517 "data/maps/MtPyre_Summit/scripts.pory"
	special SetCB2WhiteOut
# 518 "data/maps/MtPyre_Summit/scripts.pory"
	waitstate
# 519 "data/maps/MtPyre_Summit/scripts.pory"

# 520 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_RivalMultiBattleBrendanScorbunnyPostWinona::
# 521 "data/maps/MtPyre_Summit/scripts.pory"
	multi_2_vs_2 TRAINER_BRENDAN_PLACEHOLDER, MtPyre_Summit_Text_JustWantToExpandSea, TRAINER_LEAF, MtPyre_Summit_Text_MattDefeat, PARTNER_BRENDAN_SCORBUNNY
# 522 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_eq VAR_RESULT, 1, MtPyre_Summit_EventScript_DefeatedArchieMatt
# 523 "data/maps/MtPyre_Summit/scripts.pory"
	fadescreen FADE_TO_BLACK
# 524 "data/maps/MtPyre_Summit/scripts.pory"
	special SetCB2WhiteOut
# 525 "data/maps/MtPyre_Summit/scripts.pory"
	waitstate
# 526 "data/maps/MtPyre_Summit/scripts.pory"

# 527 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_RivalMultiBattleBrendanSquirtle::
# 528 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_unset FLAG_DEFEATED_FORTREE_GYM, MtPyre_Summit_EventScript_RivalMultiBattleBrendanSquirtlePreWinona
# 529 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, MtPyre_Summit_EventScript_RivalMultiBattleBrendanSquirtlePostWinona
# 530 "data/maps/MtPyre_Summit/scripts.pory"

# 531 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_RivalMultiBattleBrendanSquirtlePreWinona::
# 532 "data/maps/MtPyre_Summit/scripts.pory"
	multi_2_vs_2 TRAINER_JUAN_3, MtPyre_Summit_Text_JustWantToExpandSea, TRAINER_JUAN_2, MtPyre_Summit_Text_MattDefeat, PARTNER_BRENDAN_SQUIRTLE_PW
# 533 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_eq VAR_RESULT, 1, MtPyre_Summit_EventScript_DefeatedArchieMatt
# 534 "data/maps/MtPyre_Summit/scripts.pory"
	fadescreen FADE_TO_BLACK
# 535 "data/maps/MtPyre_Summit/scripts.pory"
	special SetCB2WhiteOut
# 536 "data/maps/MtPyre_Summit/scripts.pory"
	waitstate
# 537 "data/maps/MtPyre_Summit/scripts.pory"

# 538 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_RivalMultiBattleBrendanSquirtlePostWinona::
# 539 "data/maps/MtPyre_Summit/scripts.pory"
	multi_2_vs_2 TRAINER_BRENDAN_PLACEHOLDER, MtPyre_Summit_Text_JustWantToExpandSea, TRAINER_LEAF, MtPyre_Summit_Text_MattDefeat, PARTNER_BRENDAN_SQUIRTLE
# 540 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_eq VAR_RESULT, 1, MtPyre_Summit_EventScript_DefeatedArchieMatt
# 541 "data/maps/MtPyre_Summit/scripts.pory"
	fadescreen FADE_TO_BLACK
# 542 "data/maps/MtPyre_Summit/scripts.pory"
	special SetCB2WhiteOut
# 543 "data/maps/MtPyre_Summit/scripts.pory"
	waitstate
# 544 "data/maps/MtPyre_Summit/scripts.pory"

# 545 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_DoRivalMultiBattleMay::
# 546 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_eq VAR_STARTER_MON, 0, MtPyre_Summit_EventScript_RivalMultiBattleMaySnivy
# 547 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_eq VAR_STARTER_MON, 1, MtPyre_Summit_EventScript_RivalMultiBattleMayScorbunny
# 548 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_eq VAR_STARTER_MON, 2, MtPyre_Summit_EventScript_RivalMultiBattleMaySquirtle
# 549 "data/maps/MtPyre_Summit/scripts.pory"

# 550 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_RivalMultiBattleMaySnivy::
# 551 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_unset FLAG_DEFEATED_FORTREE_GYM, MtPyre_Summit_EventScript_RivalMultiBattleMaySnivyPreWinona
# 552 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, MtPyre_Summit_EventScript_RivalMultiBattleMaySnivyPostWinona
# 553 "data/maps/MtPyre_Summit/scripts.pory"

# 554 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_RivalMultiBattleMaySnivyPreWinona::
# 555 "data/maps/MtPyre_Summit/scripts.pory"
	multi_2_vs_2 TRAINER_JUAN_3, MtPyre_Summit_Text_JustWantToExpandSea, TRAINER_JUAN_2, MtPyre_Summit_Text_MattDefeat, PARTNER_MAY_SNIVY_PW
# 556 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_eq VAR_RESULT, 1, MtPyre_Summit_EventScript_DefeatedArchieMatt
# 557 "data/maps/MtPyre_Summit/scripts.pory"
	fadescreen FADE_TO_BLACK
# 558 "data/maps/MtPyre_Summit/scripts.pory"
	special SetCB2WhiteOut
# 559 "data/maps/MtPyre_Summit/scripts.pory"
	waitstate
# 560 "data/maps/MtPyre_Summit/scripts.pory"

# 561 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_RivalMultiBattleMaySnivyPostWinona::
# 562 "data/maps/MtPyre_Summit/scripts.pory"
	multi_2_vs_2 TRAINER_BRENDAN_PLACEHOLDER, MtPyre_Summit_Text_JustWantToExpandSea, TRAINER_LEAF, MtPyre_Summit_Text_MattDefeat, PARTNER_MAY_SNIVY
# 563 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_eq VAR_RESULT, 1, MtPyre_Summit_EventScript_DefeatedArchieMatt
# 564 "data/maps/MtPyre_Summit/scripts.pory"
	fadescreen FADE_TO_BLACK
# 565 "data/maps/MtPyre_Summit/scripts.pory"
	special SetCB2WhiteOut
# 566 "data/maps/MtPyre_Summit/scripts.pory"
	waitstate
# 567 "data/maps/MtPyre_Summit/scripts.pory"

# 568 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_RivalMultiBattleMayScorbunny::
# 569 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_unset FLAG_DEFEATED_FORTREE_GYM, MtPyre_Summit_EventScript_RivalMultiBattleMayScorbunnyPreWinona
# 570 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, MtPyre_Summit_EventScript_RivalMultiBattleMayScorbunnyPostWinona
# 571 "data/maps/MtPyre_Summit/scripts.pory"

# 572 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_RivalMultiBattleMayScorbunnyPreWinona::
# 573 "data/maps/MtPyre_Summit/scripts.pory"
	multi_2_vs_2 TRAINER_JUAN_3, MtPyre_Summit_Text_JustWantToExpandSea, TRAINER_JUAN_2, MtPyre_Summit_Text_MattDefeat, PARTNER_MAY_SCORBUNNY_PW
# 574 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_eq VAR_RESULT, 1, MtPyre_Summit_EventScript_DefeatedArchieMatt
# 575 "data/maps/MtPyre_Summit/scripts.pory"
	fadescreen FADE_TO_BLACK
# 576 "data/maps/MtPyre_Summit/scripts.pory"
	special SetCB2WhiteOut
# 577 "data/maps/MtPyre_Summit/scripts.pory"
	waitstate
# 578 "data/maps/MtPyre_Summit/scripts.pory"

# 579 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_RivalMultiBattleMayScorbunnyPostWinona::
# 580 "data/maps/MtPyre_Summit/scripts.pory"
	multi_2_vs_2 TRAINER_BRENDAN_PLACEHOLDER, MtPyre_Summit_Text_JustWantToExpandSea, TRAINER_LEAF, MtPyre_Summit_Text_MattDefeat, PARTNER_MAY_SCORBUNNY
# 581 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_eq VAR_RESULT, 1, MtPyre_Summit_EventScript_DefeatedArchieMatt
# 582 "data/maps/MtPyre_Summit/scripts.pory"
	fadescreen FADE_TO_BLACK
# 583 "data/maps/MtPyre_Summit/scripts.pory"
	special SetCB2WhiteOut
# 584 "data/maps/MtPyre_Summit/scripts.pory"
	waitstate
# 585 "data/maps/MtPyre_Summit/scripts.pory"

# 586 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_RivalMultiBattleMaySquirtle::
# 587 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_unset FLAG_DEFEATED_FORTREE_GYM, MtPyre_Summit_EventScript_RivalMultiBattleMaySquirtlePreWinona
# 588 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, MtPyre_Summit_EventScript_RivalMultiBattleMaySquirtlePostWinona
# 589 "data/maps/MtPyre_Summit/scripts.pory"

# 590 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_RivalMultiBattleMaySquirtlePreWinona::
# 591 "data/maps/MtPyre_Summit/scripts.pory"
	multi_2_vs_2 TRAINER_JUAN_3, MtPyre_Summit_Text_JustWantToExpandSea, TRAINER_JUAN_2, MtPyre_Summit_Text_MattDefeat, PARTNER_MAY_SQUIRTLE_PW
# 592 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_eq VAR_RESULT, 1, MtPyre_Summit_EventScript_DefeatedArchieMatt
# 593 "data/maps/MtPyre_Summit/scripts.pory"
	fadescreen FADE_TO_BLACK
# 594 "data/maps/MtPyre_Summit/scripts.pory"
	special SetCB2WhiteOut
# 595 "data/maps/MtPyre_Summit/scripts.pory"
	waitstate
# 596 "data/maps/MtPyre_Summit/scripts.pory"

# 597 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_RivalMultiBattleMaySquirtlePostWinona::
# 598 "data/maps/MtPyre_Summit/scripts.pory"
	multi_2_vs_2 TRAINER_BRENDAN_PLACEHOLDER, MtPyre_Summit_Text_JustWantToExpandSea, TRAINER_LEAF, MtPyre_Summit_Text_MattDefeat, PARTNER_MAY_SQUIRTLE
# 599 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_eq VAR_RESULT, 1, MtPyre_Summit_EventScript_DefeatedArchieMatt
# 600 "data/maps/MtPyre_Summit/scripts.pory"
	fadescreen FADE_TO_BLACK
# 601 "data/maps/MtPyre_Summit/scripts.pory"
	special SetCB2WhiteOut
# 602 "data/maps/MtPyre_Summit/scripts.pory"
	waitstate
# 603 "data/maps/MtPyre_Summit/scripts.pory"

# 604 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_DefeatedArchieMatt::
# 605 "data/maps/MtPyre_Summit/scripts.pory"
	setflag FLAG_DEFEATED_MTPYRE_TAG
# 606 "data/maps/MtPyre_Summit/scripts.pory"
	call MtPyre_Summit_EventScript_TeamAquaTrigger0
# 607 "data/maps/MtPyre_Summit/scripts.pory"

# 608 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_Archie::
# 609 "data/maps/MtPyre_Summit/scripts.pory"
	lockall
# 610 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_ArchieDontInterfere, MSGBOX_DEFAULT
# 611 "data/maps/MtPyre_Summit/scripts.pory"
	releaseall
# 612 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 613 "data/maps/MtPyre_Summit/scripts.pory"

# 614 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_EventScript_Matt::
# 615 "data/maps/MtPyre_Summit/scripts.pory"
	lockall
# 616 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_WellTakeCareOfYou, MSGBOX_DEFAULT
# 617 "data/maps/MtPyre_Summit/scripts.pory"
	releaseall
# 618 "data/maps/MtPyre_Summit/scripts.pory"
	end
# 619 "data/maps/MtPyre_Summit/scripts.pory"

# 620 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_WellTakeCareOfYou:
# 621 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Huhuhu!\p"
# 622 "data/maps/MtPyre_Summit/scripts.pory"
	.string "If you're going to mess with us,\n"
# 623 "data/maps/MtPyre_Summit/scripts.pory"
	.string "we'll take care of you at the same time!$"
# 624 "data/maps/MtPyre_Summit/scripts.pory"

# 625 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_ArchieDontInterfere:
# 626 "data/maps/MtPyre_Summit/scripts.pory"
	.string "ARCHIE: Clear out of the way!\n"
# 627 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Don't you dare interfere!$"
# 628 "data/maps/MtPyre_Summit/scripts.pory"

# 629 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_JustWantToExpandSea:
# 630 "data/maps/MtPyre_Summit/scripts.pory"
	.string "All I want…\n"
# 631 "data/maps/MtPyre_Summit/scripts.pory"
	.string "I just want to expand the sea…$"
# 632 "data/maps/MtPyre_Summit/scripts.pory"

# 633 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_MattDefeat:
# 634 "data/maps/MtPyre_Summit/scripts.pory"
	.string "I'm with our leader…$"
# 635 "data/maps/MtPyre_Summit/scripts.pory"

# 636 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_RivalAreYouReadyToBattle:
# 637 "data/maps/MtPyre_Summit/scripts.pory"
	.string "{RIVAL}: {PLAYER}{KUN}!\n"
# 638 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Let's go into battle together!\p"
# 639 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Are you ready?$"
# 640 "data/maps/MtPyre_Summit/scripts.pory"

# 641 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_RivalHelpMeFight:
# 642 "data/maps/MtPyre_Summit/scripts.pory"
	.string "{PLAYER}{KUN}! Just in time.\n"
# 643 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Help me fight these\p"
# 644 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Team Aqua people!$"
# 645 "data/maps/MtPyre_Summit/scripts.pory"

# 646 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_RivalThanks:
# 647 "data/maps/MtPyre_Summit/scripts.pory"
	.string "We did it!\n"
# 648 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Thanks for your help,\p"
# 649 "data/maps/MtPyre_Summit/scripts.pory"
	.string "{PLAYER}{KUN}.$"
# 650 "data/maps/MtPyre_Summit/scripts.pory"

# 651 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt1Intro:
# 652 "data/maps/MtPyre_Summit/scripts.pory"
	.string "No! Those TEAM MAGMA goons got\n"
# 653 "data/maps/MtPyre_Summit/scripts.pory"
	.string "here ahead of us!\p"
# 654 "data/maps/MtPyre_Summit/scripts.pory"
	.string "We can't fall behind!$"
# 655 "data/maps/MtPyre_Summit/scripts.pory"

# 656 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt1Defeat:
# 657 "data/maps/MtPyre_Summit/scripts.pory"
	.string "I thought you were one of the MAGMAS\n"
# 658 "data/maps/MtPyre_Summit/scripts.pory"
	.string "who happened to come back…$"
# 659 "data/maps/MtPyre_Summit/scripts.pory"

# 660 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt1PostBattle:
# 661 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Yeah, so you are strong…\n"
# 662 "data/maps/MtPyre_Summit/scripts.pory"
	.string "But there're a lot of us!$"
# 663 "data/maps/MtPyre_Summit/scripts.pory"

# 664 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt2Intro:
# 665 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Hah!\n"
# 666 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Too bad for you!\p"
# 667 "data/maps/MtPyre_Summit/scripts.pory"
	.string "If you came earlier, you only would've\n"
# 668 "data/maps/MtPyre_Summit/scripts.pory"
	.string "had to battle the wimpy TEAM MAGMA.\p"
# 669 "data/maps/MtPyre_Summit/scripts.pory"
	.string "But since you arrived now, you have\n"
# 670 "data/maps/MtPyre_Summit/scripts.pory"
	.string "to take on us toughies!$"
# 671 "data/maps/MtPyre_Summit/scripts.pory"

# 672 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt2Defeat:
# 673 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Urgh… I should've let you take on\n"
# 674 "data/maps/MtPyre_Summit/scripts.pory"
	.string "TEAM MAGMA first…$"
# 675 "data/maps/MtPyre_Summit/scripts.pory"

# 676 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt2PostBattle:
# 677 "data/maps/MtPyre_Summit/scripts.pory"
	.string "You don't know anything!\n"
# 678 "data/maps/MtPyre_Summit/scripts.pory"
	.string "So why are you messing with us?$"
# 679 "data/maps/MtPyre_Summit/scripts.pory"

# 680 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt3Intro:
# 681 "data/maps/MtPyre_Summit/scripts.pory"
	.string "You…\n"
# 682 "data/maps/MtPyre_Summit/scripts.pory"
	.string "We saw you at MT. CHIMNEY.\p"
# 683 "data/maps/MtPyre_Summit/scripts.pory"
	.string "You don't belong to either TEAM,\n"
# 684 "data/maps/MtPyre_Summit/scripts.pory"
	.string "so why would you be here?$"
# 685 "data/maps/MtPyre_Summit/scripts.pory"

# 686 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt3Defeat:
# 687 "data/maps/MtPyre_Summit/scripts.pory"
	.string "If you're going to mess with anyone,\n"
# 688 "data/maps/MtPyre_Summit/scripts.pory"
	.string "let it be TEAM MAGMA…$"
# 689 "data/maps/MtPyre_Summit/scripts.pory"

# 690 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt3PostBattle:
# 691 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Heh, it doesn't matter!\n"
# 692 "data/maps/MtPyre_Summit/scripts.pory"
	.string "We bought ourselves some time!\p"
# 693 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The BOSS should have snatched what\n"
# 694 "data/maps/MtPyre_Summit/scripts.pory"
	.string "he was after!$"
# 695 "data/maps/MtPyre_Summit/scripts.pory"

# 696 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt4Intro:
# 697 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Oh, I know!\n"
# 698 "data/maps/MtPyre_Summit/scripts.pory"
	.string "You tried to join TEAM MAGMA,\l"
# 699 "data/maps/MtPyre_Summit/scripts.pory"
	.string "but they wouldn't have you!\p"
# 700 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Well, don't think that we'll let you\n"
# 701 "data/maps/MtPyre_Summit/scripts.pory"
	.string "join our TEAM AQUA!$"
# 702 "data/maps/MtPyre_Summit/scripts.pory"

# 703 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt4Defeat:
# 704 "data/maps/MtPyre_Summit/scripts.pory"
	.string "If you want to join TEAM AQUA that\n"
# 705 "data/maps/MtPyre_Summit/scripts.pory"
	.string "badly, we can consider it…$"
# 706 "data/maps/MtPyre_Summit/scripts.pory"

# 707 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_Grunt4PostBattle:
# 708 "data/maps/MtPyre_Summit/scripts.pory"
	.string "We have a great combination going\n"
# 709 "data/maps/MtPyre_Summit/scripts.pory"
	.string "with us members and our leader.$"
# 710 "data/maps/MtPyre_Summit/scripts.pory"

# 711 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo:
# 712 "data/maps/MtPyre_Summit/scripts.pory"
	.string "ARCHIE: TEAM MAGMA's MAXIE got ahead\n"
# 713 "data/maps/MtPyre_Summit/scripts.pory"
	.string "of us, but we also got what we wanted.\p"
# 714 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The RED ORB preserved at MT. PYRE…\n"
# 715 "data/maps/MtPyre_Summit/scripts.pory"
	.string "I, ARCHIE, now have it in my possession!\p"
# 716 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Fufufu… Now we can bring our ultimate\n"
# 717 "data/maps/MtPyre_Summit/scripts.pory"
	.string "objective to fruition!\p"
# 718 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Okay, TEAM!\n"
# 719 "data/maps/MtPyre_Summit/scripts.pory"
	.string "We're pulling out!$"
# 720 "data/maps/MtPyre_Summit/scripts.pory"

# 721 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis:
# 722 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Oh, no…\n"
# 723 "data/maps/MtPyre_Summit/scripts.pory"
	.string "This cannot happen…\p"
# 724 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Not only the BLUE ORB, but even\n"
# 725 "data/maps/MtPyre_Summit/scripts.pory"
	.string "the RED ORB has been taken…\p"
# 726 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The BLUE ORB and RED ORB must never\n"
# 727 "data/maps/MtPyre_Summit/scripts.pory"
	.string "be separated. They belong together.\p"
# 728 "data/maps/MtPyre_Summit/scripts.pory"
	.string "What are those men trying to do with\n"
# 729 "data/maps/MtPyre_Summit/scripts.pory"
	.string "the two ORBS?\p"
# 730 "data/maps/MtPyre_Summit/scripts.pory"
	.string "… … … … … …\n"
# 731 "data/maps/MtPyre_Summit/scripts.pory"
	.string "… … … … … …\p"
# 732 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Oh, yes. Was it TEAM MAGMA who came\n"
# 733 "data/maps/MtPyre_Summit/scripts.pory"
	.string "and took the BLUE ORB first?\p"
# 734 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Well, in their haste, they left this\n"
# 735 "data/maps/MtPyre_Summit/scripts.pory"
	.string "behind.\p"
# 736 "data/maps/MtPyre_Summit/scripts.pory"
	.string "I couldn't imagine what exactly it\n"
# 737 "data/maps/MtPyre_Summit/scripts.pory"
	.string "could be.\p"
# 738 "data/maps/MtPyre_Summit/scripts.pory"
	.string "I would like you to have it.\n"
# 739 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Perhaps it will be useful in some way.$"
# 740 "data/maps/MtPyre_Summit/scripts.pory"

# 741 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_OrbsHaveBeenTaken:
# 742 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The BLUE ORB and RED ORB taken by\n"
# 743 "data/maps/MtPyre_Summit/scripts.pory"
	.string "those sinister men…\p"
# 744 "data/maps/MtPyre_Summit/scripts.pory"
	.string "They must never be apart…\n"
# 745 "data/maps/MtPyre_Summit/scripts.pory"
	.string "I fear something terrible will happen…$"
# 746 "data/maps/MtPyre_Summit/scripts.pory"

# 747 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_GroudonKyogreAwakened:
# 748 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Oh, my goodness…\p"
# 749 "data/maps/MtPyre_Summit/scripts.pory"
	.string "You say that both GROUDON and KYOGRE\n"
# 750 "data/maps/MtPyre_Summit/scripts.pory"
	.string "have been awakened?\p"
# 751 "data/maps/MtPyre_Summit/scripts.pory"
	.string "It is said that the BLUE ORB and\n"
# 752 "data/maps/MtPyre_Summit/scripts.pory"
	.string "the RED ORB quelled the rage of\l"
# 753 "data/maps/MtPyre_Summit/scripts.pory"
	.string "the two POKéMON…\p"
# 754 "data/maps/MtPyre_Summit/scripts.pory"
	.string "It is also said that the true owner\n"
# 755 "data/maps/MtPyre_Summit/scripts.pory"
	.string "of the ORBS still exists.\p"
# 756 "data/maps/MtPyre_Summit/scripts.pory"
	.string "However, no one knows who, or what\n"
# 757 "data/maps/MtPyre_Summit/scripts.pory"
	.string "exactly, the ORBS belong to.\p"
# 758 "data/maps/MtPyre_Summit/scripts.pory"
	.string "It could be a human, or perhaps\n"
# 759 "data/maps/MtPyre_Summit/scripts.pory"
	.string "a POKéMON, but no one knows.$"
# 760 "data/maps/MtPyre_Summit/scripts.pory"

# 761 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs:
# 762 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The two men who took the ORBS came\n"
# 763 "data/maps/MtPyre_Summit/scripts.pory"
	.string "back to return them on their own.\p"
# 764 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Those men…\n"
# 765 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Perhaps they are not so evil after all…$"
# 766 "data/maps/MtPyre_Summit/scripts.pory"

# 767 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_SuperAncientPokemonTaughtUs:
# 768 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The embodiments of the land, sea,\n"
# 769 "data/maps/MtPyre_Summit/scripts.pory"
	.string "and the sky…\p"
# 770 "data/maps/MtPyre_Summit/scripts.pory"
	.string "That is said to be the identities of\n"
# 771 "data/maps/MtPyre_Summit/scripts.pory"
	.string "the super-ancient POKéMON…\p"
# 772 "data/maps/MtPyre_Summit/scripts.pory"
	.string "In the same way that we humans and\n"
# 773 "data/maps/MtPyre_Summit/scripts.pory"
	.string "POKéMON have life, our world, too,\l"
# 774 "data/maps/MtPyre_Summit/scripts.pory"
	.string "is alive…\p"
# 775 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The super-ancient POKéMON have\n"
# 776 "data/maps/MtPyre_Summit/scripts.pory"
	.string "taught us that…$"
# 777 "data/maps/MtPyre_Summit/scripts.pory"

# 778 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_WillYouHearOutMyTale:
# 779 "data/maps/MtPyre_Summit/scripts.pory"
	.string "MT. PYRE is where we calm the spirits\n"
# 780 "data/maps/MtPyre_Summit/scripts.pory"
	.string "of POKéMON that have passed on…\p"
# 781 "data/maps/MtPyre_Summit/scripts.pory"
	.string "This is a high place where one can\n"
# 782 "data/maps/MtPyre_Summit/scripts.pory"
	.string "see all of HOENN…\p"
# 783 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The disembodied spirits of POKéMON\n"
# 784 "data/maps/MtPyre_Summit/scripts.pory"
	.string "must find solace here…\p"
# 785 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Is it coincidence that you are here…\p"
# 786 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Will you hear out my tale? A tale long\n"
# 787 "data/maps/MtPyre_Summit/scripts.pory"
	.string "told in the HOENN region?$"
# 788 "data/maps/MtPyre_Summit/scripts.pory"

# 789 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_GroudonKyogreTale:
# 790 "data/maps/MtPyre_Summit/scripts.pory"
	.string "It happened long, long ago…\p"
# 791 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The world was wracked by a ferocious\n"
# 792 "data/maps/MtPyre_Summit/scripts.pory"
	.string "clash between the POKéMON of the land\l"
# 793 "data/maps/MtPyre_Summit/scripts.pory"
	.string "and the POKéMON of the sea…\p"
# 794 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The POKéMON of the land raised\n"
# 795 "data/maps/MtPyre_Summit/scripts.pory"
	.string "mountains and created continents…\p"
# 796 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The POKéMON of the sea raised huge\n"
# 797 "data/maps/MtPyre_Summit/scripts.pory"
	.string "waves and carved out oceans…\p"
# 798 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Their fierce duel raged without end.\p"
# 799 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The world was engulfed in massive\n"
# 800 "data/maps/MtPyre_Summit/scripts.pory"
	.string "infernos and vicious storms.\p"
# 801 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The BLUE ORB and the RED ORB brought\n"
# 802 "data/maps/MtPyre_Summit/scripts.pory"
	.string "an end to the calamity.\p"
# 803 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Light poured from the two ORBS and\n"
# 804 "data/maps/MtPyre_Summit/scripts.pory"
	.string "becalmed the enraged adversaries.\p"
# 805 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The pair, made docile, dove deep into\n"
# 806 "data/maps/MtPyre_Summit/scripts.pory"
	.string "the sea where eventually they\l"
# 807 "data/maps/MtPyre_Summit/scripts.pory"
	.string "disappeared…$"
# 808 "data/maps/MtPyre_Summit/scripts.pory"

# 809 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_WellThatTooIsFine:
# 810 "data/maps/MtPyre_Summit/scripts.pory"
	.string "I see…\n"
# 811 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Well, that, too, is fine…$"
# 812 "data/maps/MtPyre_Summit/scripts.pory"

# 813 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_MaxieSilence:
# 814 "data/maps/MtPyre_Summit/scripts.pory"
	.string "MAXIE: {PLAYER}…\p"
# 815 "data/maps/MtPyre_Summit/scripts.pory"
	.string "… … … … … …\n"
# 816 "data/maps/MtPyre_Summit/scripts.pory"
	.string "… … … … … …$"
# 817 "data/maps/MtPyre_Summit/scripts.pory"

# 818 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_HearTheNewLegendOfHoenn:
# 819 "data/maps/MtPyre_Summit/scripts.pory"
	.string "It is my role to pass on the legends\n"
# 820 "data/maps/MtPyre_Summit/scripts.pory"
	.string "of HOENN to future generations.\p"
# 821 "data/maps/MtPyre_Summit/scripts.pory"
	.string "And the crisis that just ended in\n"
# 822 "data/maps/MtPyre_Summit/scripts.pory"
	.string "SOOTOPOLIS rewrote a legend…\p"
# 823 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Have you the time to hear the new\n"
# 824 "data/maps/MtPyre_Summit/scripts.pory"
	.string "legend of HOENN?$"
# 825 "data/maps/MtPyre_Summit/scripts.pory"

# 826 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Text_HoennTrioTale:
# 827 "data/maps/MtPyre_Summit/scripts.pory"
	.string "It happened long, long ago…\p"
# 828 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The world was wracked by a ferocious\n"
# 829 "data/maps/MtPyre_Summit/scripts.pory"
	.string "clash between the POKéMON of the land\l"
# 830 "data/maps/MtPyre_Summit/scripts.pory"
	.string "and the POKéMON of the sea…\p"
# 831 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The POKéMON of the land raised\n"
# 832 "data/maps/MtPyre_Summit/scripts.pory"
	.string "mountains and created continents…\p"
# 833 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The POKéMON of the sea raised huge\n"
# 834 "data/maps/MtPyre_Summit/scripts.pory"
	.string "waves and carved out oceans…\p"
# 835 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Their fierce duel raged without end.\p"
# 836 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The world was engulfed in massive\n"
# 837 "data/maps/MtPyre_Summit/scripts.pory"
	.string "fires and vicious storms.\p"
# 838 "data/maps/MtPyre_Summit/scripts.pory"
	.string "It was then that the POKéMON of\n"
# 839 "data/maps/MtPyre_Summit/scripts.pory"
	.string "the sky descended from a storm.\p"
# 840 "data/maps/MtPyre_Summit/scripts.pory"
	.string "The POKéMON, shining a vivid green,\n"
# 841 "data/maps/MtPyre_Summit/scripts.pory"
	.string "becalmed the two enraged POKéMON.\p"
# 842 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Then, its duty done, the green POKéMON\n"
# 843 "data/maps/MtPyre_Summit/scripts.pory"
	.string "flew off into the wild blue yonder…$"
