# 1 "data/maps/PetalburgWoods/scripts.pory"

# 2 "data/maps/PetalburgWoods/scripts.pory"
.set LOCALID_GRUNT, 3
# 3 "data/maps/PetalburgWoods/scripts.pory"
.set LOCALID_DEVON_EMPLOYEE, 4
# 4 "data/maps/PetalburgWoods/scripts.pory"
.set LOCALID_SPRITZEE, 14
# 5 "data/maps/PetalburgWoods/scripts.pory"

# 6 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_MapScripts::
# 7 "data/maps/PetalburgWoods/scripts.pory"
	.byte 0
# 8 "data/maps/PetalburgWoods/scripts.pory"

# 9 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherLeft::
# 10 "data/maps/PetalburgWoods/scripts.pory"
	lockall
# 11 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherIntro
# 12 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
# 13 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 14 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
# 15 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 16 "data/maps/PetalburgWoods/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 17 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
# 18 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 19 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
# 20 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 21 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
# 22 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 23 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
# 24 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 25 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
# 26 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 27 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
# 28 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 29 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
# 30 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 31 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
# 32 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 33 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
# 34 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
# 35 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
# 36 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 37 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
# 38 "data/maps/PetalburgWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
# 39 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
# 40 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 41 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
# 42 "data/maps/PetalburgWoods/scripts.pory"
	end
# 43 "data/maps/PetalburgWoods/scripts.pory"

# 44 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherRight::
# 45 "data/maps/PetalburgWoods/scripts.pory"
	lockall
# 46 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherIntro
# 47 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
# 48 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 49 "data/maps/PetalburgWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 50 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 51 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
# 52 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 53 "data/maps/PetalburgWoods/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 54 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
# 55 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 56 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
# 57 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 58 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
# 59 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 60 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
# 61 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 62 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
# 63 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 64 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
# 65 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 66 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
# 67 "data/maps/PetalburgWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 68 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 69 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
# 70 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
# 71 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
# 72 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 73 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
# 74 "data/maps/PetalburgWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
# 75 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
# 76 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 77 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
# 78 "data/maps/PetalburgWoods/scripts.pory"
	end
# 79 "data/maps/PetalburgWoods/scripts.pory"

# 80 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherIntro::
# 81 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
# 82 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 83 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
# 84 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 85 "data/maps/PetalburgWoods/scripts.pory"
	return
# 86 "data/maps/PetalburgWoods/scripts.pory"

# 87 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherPostBattle::
# 88 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
# 89 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 90 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaRunAway
# 91 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 92 "data/maps/PetalburgWoods/scripts.pory"
	removeobject LOCALID_GRUNT
# 93 "data/maps/PetalburgWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 94 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 95 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
# 96 "data/maps/PetalburgWoods/scripts.pory"
	giveitem ITEM_GREAT_BALL
# 97 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
# 98 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_DevonResearcherFinish
# 99 "data/maps/PetalburgWoods/scripts.pory"
	end
# 100 "data/maps/PetalburgWoods/scripts.pory"

# 101 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_BagFull::
# 102 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
# 103 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_DevonResearcherFinish
# 104 "data/maps/PetalburgWoods/scripts.pory"
	end
# 105 "data/maps/PetalburgWoods/scripts.pory"

# 106 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherFinish::
# 107 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
# 108 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
# 109 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 110 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
# 111 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 112 "data/maps/PetalburgWoods/scripts.pory"
	return
# 113 "data/maps/PetalburgWoods/scripts.pory"

# 114 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_RemoveDevonResearcher::
# 115 "data/maps/PetalburgWoods/scripts.pory"
	removeobject LOCALID_DEVON_EMPLOYEE
# 116 "data/maps/PetalburgWoods/scripts.pory"
	setvar VAR_PETALBURG_WOODS_STATE, 1
# 117 "data/maps/PetalburgWoods/scripts.pory"
	releaseall
# 118 "data/maps/PetalburgWoods/scripts.pory"
	end
# 119 "data/maps/PetalburgWoods/scripts.pory"

# 120 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherLookAround:
# 121 "data/maps/PetalburgWoods/scripts.pory"
	face_up
# 122 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 123 "data/maps/PetalburgWoods/scripts.pory"
	delay_4
# 124 "data/maps/PetalburgWoods/scripts.pory"
	face_right
# 125 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 126 "data/maps/PetalburgWoods/scripts.pory"
	delay_8
# 127 "data/maps/PetalburgWoods/scripts.pory"
	face_left
# 128 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 129 "data/maps/PetalburgWoods/scripts.pory"
	delay_8
# 130 "data/maps/PetalburgWoods/scripts.pory"
	face_down
# 131 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 132 "data/maps/PetalburgWoods/scripts.pory"
	face_right
# 133 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 134 "data/maps/PetalburgWoods/scripts.pory"
	delay_8
# 135 "data/maps/PetalburgWoods/scripts.pory"
	face_up
# 136 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 137 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 138 "data/maps/PetalburgWoods/scripts.pory"

# 139 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherExitLeft:
# 140 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 141 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 142 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 143 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 144 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 145 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 146 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 147 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 148 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 149 "data/maps/PetalburgWoods/scripts.pory"

# 150 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
# 151 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 152 "data/maps/PetalburgWoods/scripts.pory"
	face_player
# 153 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 154 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 155 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 156 "data/maps/PetalburgWoods/scripts.pory"

# 157 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
# 158 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 159 "data/maps/PetalburgWoods/scripts.pory"
	face_player
# 160 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 161 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 162 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 163 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_right
# 164 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 165 "data/maps/PetalburgWoods/scripts.pory"

# 166 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherExitRight:
# 167 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_left
# 168 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 169 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 170 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 171 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 172 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 173 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 174 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 175 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 176 "data/maps/PetalburgWoods/scripts.pory"

# 177 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_WatchResearcherLeave:
# 178 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 179 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 180 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_up
# 181 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 182 "data/maps/PetalburgWoods/scripts.pory"

# 183 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
# 184 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 185 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 186 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 187 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_left
# 188 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_up
# 189 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 190 "data/maps/PetalburgWoods/scripts.pory"

# 191 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
# 192 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 193 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 194 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_up
# 195 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 196 "data/maps/PetalburgWoods/scripts.pory"

# 197 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherStartExit:
# 198 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_down
# 199 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 200 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 201 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 202 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 203 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 204 "data/maps/PetalburgWoods/scripts.pory"
	face_up
# 205 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 206 "data/maps/PetalburgWoods/scripts.pory"

# 207 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachResearcherLeft:
# 208 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 209 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 210 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 211 "data/maps/PetalburgWoods/scripts.pory"

# 212 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaBackOff:
# 213 "data/maps/PetalburgWoods/scripts.pory"
	lock_facing_direction
# 214 "data/maps/PetalburgWoods/scripts.pory"
	walk_up
# 215 "data/maps/PetalburgWoods/scripts.pory"
	unlock_facing_direction
# 216 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 217 "data/maps/PetalburgWoods/scripts.pory"

# 218 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaRunAway:
# 219 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 220 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 221 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 222 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 223 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 224 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 225 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 226 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 227 "data/maps/PetalburgWoods/scripts.pory"

# 228 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachResearcherRight:
# 229 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 230 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 231 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 232 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 233 "data/maps/PetalburgWoods/scripts.pory"

# 234 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaEntrance:
# 235 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 236 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 237 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 238 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 239 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 240 "data/maps/PetalburgWoods/scripts.pory"

# 241 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachPlayer:
# 242 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 243 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 244 "data/maps/PetalburgWoods/scripts.pory"

# 245 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Boy1::
# 246 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
# 247 "data/maps/PetalburgWoods/scripts.pory"
	end
# 248 "data/maps/PetalburgWoods/scripts.pory"

# 249 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Boy2::
# 250 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
# 251 "data/maps/PetalburgWoods/scripts.pory"
	end
# 252 "data/maps/PetalburgWoods/scripts.pory"

# 253 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Girl::
# 254 "data/maps/PetalburgWoods/scripts.pory"
	lock
# 255 "data/maps/PetalburgWoods/scripts.pory"
	faceplayer
# 256 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
# 257 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
# 258 "data/maps/PetalburgWoods/scripts.pory"
	giveitem ITEM_MIRACLE_SEED
# 259 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 260 "data/maps/PetalburgWoods/scripts.pory"
	setflag FLAG_RECEIVED_MIRACLE_SEED
# 261 "data/maps/PetalburgWoods/scripts.pory"
	release
# 262 "data/maps/PetalburgWoods/scripts.pory"
	end
# 263 "data/maps/PetalburgWoods/scripts.pory"

# 264 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_ExplainMiracleSeed::
# 265 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
# 266 "data/maps/PetalburgWoods/scripts.pory"
	release
# 267 "data/maps/PetalburgWoods/scripts.pory"
	end
# 268 "data/maps/PetalburgWoods/scripts.pory"

# 269 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Sign1::
# 270 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
# 271 "data/maps/PetalburgWoods/scripts.pory"
	end
# 272 "data/maps/PetalburgWoods/scripts.pory"

# 273 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Sign2::
# 274 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
# 275 "data/maps/PetalburgWoods/scripts.pory"
	end
# 276 "data/maps/PetalburgWoods/scripts.pory"

# 277 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Lyle::
# 278 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
# 279 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
# 280 "data/maps/PetalburgWoods/scripts.pory"
	end
# 281 "data/maps/PetalburgWoods/scripts.pory"

# 282 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_James::
# 283 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
# 284 "data/maps/PetalburgWoods/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 285 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
# 286 "data/maps/PetalburgWoods/scripts.pory"
	setvar VAR_0x8004, TRAINER_JAMES_1
# 287 "data/maps/PetalburgWoods/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 288 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
# 289 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
# 290 "data/maps/PetalburgWoods/scripts.pory"
	release
# 291 "data/maps/PetalburgWoods/scripts.pory"
	end
# 292 "data/maps/PetalburgWoods/scripts.pory"

# 293 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_TryRegisterJames::
# 294 "data/maps/PetalburgWoods/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 295 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 296 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
# 297 "data/maps/PetalburgWoods/scripts.pory"
	release
# 298 "data/maps/PetalburgWoods/scripts.pory"
	end
# 299 "data/maps/PetalburgWoods/scripts.pory"

# 300 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_RegisterJames::
# 301 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
# 302 "data/maps/PetalburgWoods/scripts.pory"
	register_matchcall TRAINER_JAMES_1
# 303 "data/maps/PetalburgWoods/scripts.pory"
	release
# 304 "data/maps/PetalburgWoods/scripts.pory"
	end
# 305 "data/maps/PetalburgWoods/scripts.pory"

# 306 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_TryRegisterJames2::
# 307 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
# 308 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
# 309 "data/maps/PetalburgWoods/scripts.pory"
	release
# 310 "data/maps/PetalburgWoods/scripts.pory"
	end
# 311 "data/maps/PetalburgWoods/scripts.pory"

# 312 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_RegisterJames2::
# 313 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
# 314 "data/maps/PetalburgWoods/scripts.pory"
	register_matchcall TRAINER_JAMES_1
# 315 "data/maps/PetalburgWoods/scripts.pory"
	release
# 316 "data/maps/PetalburgWoods/scripts.pory"
	end
# 317 "data/maps/PetalburgWoods/scripts.pory"

# 318 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_JamesRematch::
# 319 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
# 320 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
# 321 "data/maps/PetalburgWoods/scripts.pory"
	end
# 322 "data/maps/PetalburgWoods/scripts.pory"

# 323 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_NotAOneToBeFound:
# 324 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hmmm…\n"
# 325 "data/maps/PetalburgWoods/scripts.pory"
	.string "Not a one to be found…$"
# 326 "data/maps/PetalburgWoods/scripts.pory"

# 327 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_HaveYouSeenShroomish:
# 328 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hello, have you seen any POKéMON\n"
# 329 "data/maps/PetalburgWoods/scripts.pory"
	.string "called SHROOMISH around here?\p"
# 330 "data/maps/PetalburgWoods/scripts.pory"
	.string "I really love that POKéMON.$"
# 331 "data/maps/PetalburgWoods/scripts.pory"

# 332 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IWasGoingToAmbushYou:
# 333 "data/maps/PetalburgWoods/scripts.pory"
	.string "I was going to ambush you, but you\n"
# 334 "data/maps/PetalburgWoods/scripts.pory"
	.string "had to dawdle in PETALBURG WOODS\l"
# 335 "data/maps/PetalburgWoods/scripts.pory"
	.string "forever, didn't you?\p"
# 336 "data/maps/PetalburgWoods/scripts.pory"
	.string "I got sick of waiting, so here I am!$"
# 337 "data/maps/PetalburgWoods/scripts.pory"

# 338 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_HandOverThosePapers:
# 339 "data/maps/PetalburgWoods/scripts.pory"
	.string "You! DEVON RESEARCHER!\p"
# 340 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hand over those papers!$"
# 341 "data/maps/PetalburgWoods/scripts.pory"

# 342 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YouHaveToHelpMe:
# 343 "data/maps/PetalburgWoods/scripts.pory"
	.string "Aiyeeeh!\p"
# 344 "data/maps/PetalburgWoods/scripts.pory"
	.string "You're a POKéMON TRAINER, aren't you?\n"
# 345 "data/maps/PetalburgWoods/scripts.pory"
	.string "You've got to help me, please!$"
# 346 "data/maps/PetalburgWoods/scripts.pory"

# 347 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_NoOneCrossesTeamAqua:
# 348 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hunh? What do you think you're doing?\n"
# 349 "data/maps/PetalburgWoods/scripts.pory"
	.string "What, you're going to protect him?\p"
# 350 "data/maps/PetalburgWoods/scripts.pory"
	.string "No one who crosses TEAM AQUA\n"
# 351 "data/maps/PetalburgWoods/scripts.pory"
	.string "gets any mercy, not even a kid!\p"
# 352 "data/maps/PetalburgWoods/scripts.pory"
	.string "Come on and battle me!$"
# 353 "data/maps/PetalburgWoods/scripts.pory"

# 354 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YoureKiddingMe:
# 355 "data/maps/PetalburgWoods/scripts.pory"
	.string "You're kidding me! You're tough!$"
# 356 "data/maps/PetalburgWoods/scripts.pory"

# 357 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YouveGotSomeNerve:
# 358 "data/maps/PetalburgWoods/scripts.pory"
	.string "Grrr… You've got some nerve\n"
# 359 "data/maps/PetalburgWoods/scripts.pory"
	.string "meddling with TEAM AQUA!\l"
# 360 "data/maps/PetalburgWoods/scripts.pory"
	.string "Come on and battle me again!\p"
# 361 "data/maps/PetalburgWoods/scripts.pory"
	.string "I wish I could say that, but I'm out of\n"
# 362 "data/maps/PetalburgWoods/scripts.pory"
	.string "POKéMON…\p"
# 363 "data/maps/PetalburgWoods/scripts.pory"
	.string "And, hey, we of TEAM AQUA are also\n"
# 364 "data/maps/PetalburgWoods/scripts.pory"
	.string "after something in RUSTBORO.\p"
# 365 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'll let you go today!$"
# 366 "data/maps/PetalburgWoods/scripts.pory"

# 367 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ThatWasAwfullyClose:
# 368 "data/maps/PetalburgWoods/scripts.pory"
	.string "Whew…\n"
# 369 "data/maps/PetalburgWoods/scripts.pory"
	.string "That was awfully close!\p"
# 370 "data/maps/PetalburgWoods/scripts.pory"
	.string "Thanks to you, he didn't rob me of\n"
# 371 "data/maps/PetalburgWoods/scripts.pory"
	.string "these important papers.\p"
# 372 "data/maps/PetalburgWoods/scripts.pory"
	.string "I know, I'll give you a GREAT BALL as\n"
# 373 "data/maps/PetalburgWoods/scripts.pory"
	.string "my thanks!$"
# 374 "data/maps/PetalburgWoods/scripts.pory"

# 375 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
# 376 "data/maps/PetalburgWoods/scripts.pory"
	.string "Didn't that TEAM AQUA thug say\n"
# 377 "data/maps/PetalburgWoods/scripts.pory"
	.string "they were after something in\l"
# 378 "data/maps/PetalburgWoods/scripts.pory"
	.string "RUSTBORO, too?$"
# 379 "data/maps/PetalburgWoods/scripts.pory"

# 380 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ICantBeWastingTime:
# 381 "data/maps/PetalburgWoods/scripts.pory"
	.string "Uh-oh! It's a crisis!\n"
# 382 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't be wasting time!$"
# 383 "data/maps/PetalburgWoods/scripts.pory"

# 384 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YoureLoadedWithItems:
# 385 "data/maps/PetalburgWoods/scripts.pory"
	.string "You're loaded with items.\n"
# 386 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't give you this GREAT BALL.$"
# 387 "data/maps/PetalburgWoods/scripts.pory"

# 388 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_GoBugPokemonTeam:
# 389 "data/maps/PetalburgWoods/scripts.pory"
	.string "I caught a whole bunch of POKéMON!\p"
# 390 "data/maps/PetalburgWoods/scripts.pory"
	.string "Go, go, go!\n"
# 391 "data/maps/PetalburgWoods/scripts.pory"
	.string "My BUG POKéMON team!$"
# 392 "data/maps/PetalburgWoods/scripts.pory"

# 393 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ICouldntWin:
# 394 "data/maps/PetalburgWoods/scripts.pory"
	.string "I have all these POKéMON,\n"
# 395 "data/maps/PetalburgWoods/scripts.pory"
	.string "but I couldn't win…$"
# 396 "data/maps/PetalburgWoods/scripts.pory"

# 397 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ImOutOfPokeBalls:
# 398 "data/maps/PetalburgWoods/scripts.pory"
	.string "I caught a bunch of POKéMON.\n"
# 399 "data/maps/PetalburgWoods/scripts.pory"
	.string "Now I'm out of POKé BALLS.$"
# 400 "data/maps/PetalburgWoods/scripts.pory"

# 401 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
# 402 "data/maps/PetalburgWoods/scripts.pory"
	.string "If you take BUG POKéMON to school,\n"
# 403 "data/maps/PetalburgWoods/scripts.pory"
	.string "you get to be instantly popular!$"
# 404 "data/maps/PetalburgWoods/scripts.pory"

# 405 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_CantBePopularIfILose:
# 406 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't be popular if I lose.$"
# 407 "data/maps/PetalburgWoods/scripts.pory"

# 408 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_PeopleRespectYou:
# 409 "data/maps/PetalburgWoods/scripts.pory"
	.string "If you have a big BUG POKéMON,\n"
# 410 "data/maps/PetalburgWoods/scripts.pory"
	.string "people respect you for it.$"
# 411 "data/maps/PetalburgWoods/scripts.pory"

# 412 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IWantRematch1:
# 413 "data/maps/PetalburgWoods/scripts.pory"
	.string "I want a rematch when my BUG\n"
# 414 "data/maps/PetalburgWoods/scripts.pory"
	.string "POKéMON grow up!\p"
# 415 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'm registering you in my POKéNAV!$"
# 416 "data/maps/PetalburgWoods/scripts.pory"

# 417 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IWantRematch2:
# 418 "data/maps/PetalburgWoods/scripts.pory"
	.string "I want a rematch when my BUG \n"
# 419 "data/maps/PetalburgWoods/scripts.pory"
	.string "POKéMON grow up!\p"
# 420 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'm registering you in my POKéNAV!$"
# 421 "data/maps/PetalburgWoods/scripts.pory"

# 422 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_MyPokemonHaveGrown:
# 423 "data/maps/PetalburgWoods/scripts.pory"
	.string "My BUG POKéMON have grown.\n"
# 424 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'll be popular again.$"
# 425 "data/maps/PetalburgWoods/scripts.pory"

# 426 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_CantBePopularIfLose:
# 427 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't be popular if I lose.$"
# 428 "data/maps/PetalburgWoods/scripts.pory"

# 429 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IveBeenTrainingHard:
# 430 "data/maps/PetalburgWoods/scripts.pory"
	.string "You get to be popular if you have\n"
# 431 "data/maps/PetalburgWoods/scripts.pory"
	.string "strong POKéMON, right?\l"
# 432 "data/maps/PetalburgWoods/scripts.pory"
	.string "So, I've been training hard.$"
# 433 "data/maps/PetalburgWoods/scripts.pory"

# 434 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_StayOutOfTallGrass:
# 435 "data/maps/PetalburgWoods/scripts.pory"
	.string "Yo, there!\n"
# 436 "data/maps/PetalburgWoods/scripts.pory"
	.string "Your POKéMON doing okay?\p"
# 437 "data/maps/PetalburgWoods/scripts.pory"
	.string "If your POKéMON are weak and you want\n"
# 438 "data/maps/PetalburgWoods/scripts.pory"
	.string "to avoid battles, you should stay out\l"
# 439 "data/maps/PetalburgWoods/scripts.pory"
	.string "of tall grass.$"
# 440 "data/maps/PetalburgWoods/scripts.pory"

# 441 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_HiddenItemsExplanation:
# 442 "data/maps/PetalburgWoods/scripts.pory"
	.string "Sometimes, there are things on the\n"
# 443 "data/maps/PetalburgWoods/scripts.pory"
	.string "ground even if you can't see them.\p"
# 444 "data/maps/PetalburgWoods/scripts.pory"
	.string "That's why I always check where I'm\n"
# 445 "data/maps/PetalburgWoods/scripts.pory"
	.string "walking.$"
# 446 "data/maps/PetalburgWoods/scripts.pory"

# 447 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TryUsingThisItem:
# 448 "data/maps/PetalburgWoods/scripts.pory"
	.string "Oh, neat!\n"
# 449 "data/maps/PetalburgWoods/scripts.pory"
	.string "That's the BADGE from RUSTBORO GYM!\p"
# 450 "data/maps/PetalburgWoods/scripts.pory"
	.string "You must be a TRAINER.\n"
# 451 "data/maps/PetalburgWoods/scripts.pory"
	.string "You should try using this item.$"
# 452 "data/maps/PetalburgWoods/scripts.pory"

# 453 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_MiracleSeedExplanation:
# 454 "data/maps/PetalburgWoods/scripts.pory"
	.string "It's a MIRACLE SEED.\n"
# 455 "data/maps/PetalburgWoods/scripts.pory"
	.string "If a POKéMON holds that item, its\l"
# 456 "data/maps/PetalburgWoods/scripts.pory"
	.string "GRASS-type moves become stronger.\p"
# 457 "data/maps/PetalburgWoods/scripts.pory"
	.string "Besides MIRACLE SEED, I think there are\n"
# 458 "data/maps/PetalburgWoods/scripts.pory"
	.string "other convenient items for POKéMON\l"
# 459 "data/maps/PetalburgWoods/scripts.pory"
	.string "to hold.$"
# 460 "data/maps/PetalburgWoods/scripts.pory"

# 461 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TrainerTipsExperience:
# 462 "data/maps/PetalburgWoods/scripts.pory"
	.string "TRAINER TIPS\p"
# 463 "data/maps/PetalburgWoods/scripts.pory"
	.string "Any POKéMON that appears even once\n"
# 464 "data/maps/PetalburgWoods/scripts.pory"
	.string "in a battle is awarded EXP Points.\p"
# 465 "data/maps/PetalburgWoods/scripts.pory"
	.string "To raise a weak POKéMON, put it at the\n"
# 466 "data/maps/PetalburgWoods/scripts.pory"
	.string "left of the team list.\p"
# 467 "data/maps/PetalburgWoods/scripts.pory"
	.string "As soon as a battle starts, switch it\n"
# 468 "data/maps/PetalburgWoods/scripts.pory"
	.string "out. It will earn EXP Points without\l"
# 469 "data/maps/PetalburgWoods/scripts.pory"
	.string "being exposed to any harm.$"
# 470 "data/maps/PetalburgWoods/scripts.pory"

# 471 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TrainerTipsPP:
# 472 "data/maps/PetalburgWoods/scripts.pory"
	.string "TRAINER TIPS\p"
# 473 "data/maps/PetalburgWoods/scripts.pory"
	.string "In addition to Hit Points (HP), POKéMON\n"
# 474 "data/maps/PetalburgWoods/scripts.pory"
	.string "have Power Points (PP) that are used to\l"
# 475 "data/maps/PetalburgWoods/scripts.pory"
	.string "make moves during battle.\p"
# 476 "data/maps/PetalburgWoods/scripts.pory"
	.string "If a POKéMON runs out of PP, it must be\n"
# 477 "data/maps/PetalburgWoods/scripts.pory"
	.string "taken to a POKéMON CENTER.$"
