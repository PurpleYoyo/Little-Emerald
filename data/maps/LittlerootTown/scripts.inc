# 1 "data/maps/LittlerootTown/scripts.pory"

# 2 "data/maps/LittlerootTown/scripts.pory"
.set LOCALID_TWIN, 1
# 3 "data/maps/LittlerootTown/scripts.pory"
.set LOCALID_MOM, 4
# 4 "data/maps/LittlerootTown/scripts.pory"
.set LOCALID_RIVAL, 7
# 5 "data/maps/LittlerootTown/scripts.pory"
.set LOCALID_BIRCH, 8
# 6 "data/maps/LittlerootTown/scripts.pory"

# 7 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_MapScripts::
# 8 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_OnTransition
# 9 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_OnFrame
# 10 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_OnWarp
# 11 "data/maps/LittlerootTown/scripts.pory"
	.byte 0
# 12 "data/maps/LittlerootTown/scripts.pory"

# 13 "data/maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_TOWN_STATE
# 14 "data/maps/LittlerootTown/scripts.pory"
	@ 1: Met Rival
# 15 "data/maps/LittlerootTown/scripts.pory"
	@ 2: Saving Birch
# 16 "data/maps/LittlerootTown/scripts.pory"
	@ 3: Received Pokedex
# 17 "data/maps/LittlerootTown/scripts.pory"
	@ 4: Received Running Shoes
# 18 "data/maps/LittlerootTown/scripts.pory"

# 19 "data/maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_INTRO_STATE
# 20 "data/maps/LittlerootTown/scripts.pory"
	@ 1: In truck male
# 21 "data/maps/LittlerootTown/scripts.pory"
	@ 2: In truck female
# 22 "data/maps/LittlerootTown/scripts.pory"
	@ 3: Entered house
# 23 "data/maps/LittlerootTown/scripts.pory"
	@ 4: Told to go set clock
# 24 "data/maps/LittlerootTown/scripts.pory"
	@ 5: Entered 2F to set clock
# 25 "data/maps/LittlerootTown/scripts.pory"
	@ 6: Set clock
# 26 "data/maps/LittlerootTown/scripts.pory"
	@ 7: Told to go meet rival
# 27 "data/maps/LittlerootTown/scripts.pory"

# 28 "data/maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_HOUSES_STATE_MAY
# 29 "data/maps/LittlerootTown/scripts.pory"
	@                    and VAR_LITTLEROOT_HOUSES_STATE_BRENDAN
# 30 "data/maps/LittlerootTown/scripts.pory"
	@ 1: On Truck (and is corresponding gender)
# 31 "data/maps/LittlerootTown/scripts.pory"
	@ 2: Met Rival's Mom (and is corresponding gender)
# 32 "data/maps/LittlerootTown/scripts.pory"
	@ 3: Entered Hall of Fame
# 33 "data/maps/LittlerootTown/scripts.pory"
	@ 4: Completed Lati TV / SS Ticket event
# 34 "data/maps/LittlerootTown/scripts.pory"
	@ 5: Exited house after above event
# 35 "data/maps/LittlerootTown/scripts.pory"

# 36 "data/maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_RIVAL_STATE
# 37 "data/maps/LittlerootTown/scripts.pory"
	@ 1: Never occurs
# 38 "data/maps/LittlerootTown/scripts.pory"
	@ 2: Entered Rival's bedroom
# 39 "data/maps/LittlerootTown/scripts.pory"
	@ 3: Met Rival
# 40 "data/maps/LittlerootTown/scripts.pory"
	@ 4: Received Pokedex
# 41 "data/maps/LittlerootTown/scripts.pory"

# 42 "data/maps/LittlerootTown/scripts.pory"

# 43 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_OnTransition:
# 44 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_VISITED_LITTLEROOT_TOWN
# 45 "data/maps/LittlerootTown/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 46 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 2, LittlerootTown_EventScript_MoveMomToMaysDoor
# 47 "data/maps/LittlerootTown/scripts.pory"
	call_if_unset FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_SetTwinPos
# 48 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_TOWN_STATE, 3, LittlerootTown_EventScript_SetMomStandingInFrontOfDoorPos
# 49 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_HOUSES_STATE_MAY, 4, LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent
# 50 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 4, LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent
# 51 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_OLDALE_RIVAL_STATE, 1, LittlerootTown_EventScript_MoveRivalFromOldale
# 52 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_RIVAL_STATE, 3, LittlerootTown_EventScript_SetRivalLeftForRoute103
# 53 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_HideMapNamePopup
# 54 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_EventScript_LeftLabAfterDexUpgrade
# 55 "data/maps/LittlerootTown/scripts.pory"
	end
# 56 "data/maps/LittlerootTown/scripts.pory"

# 57 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_LeftLabAfterDexUpgrade::
# 58 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3
# 59 "data/maps/LittlerootTown/scripts.pory"
	return
# 60 "data/maps/LittlerootTown/scripts.pory"

# 61 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_HideMapNamePopup::
# 62 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 63 "data/maps/LittlerootTown/scripts.pory"
	return
# 64 "data/maps/LittlerootTown/scripts.pory"

# 65 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalLeftForRoute103::
# 66 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_RIVAL_LEFT_FOR_ROUTE103
# 67 "data/maps/LittlerootTown/scripts.pory"
	return
# 68 "data/maps/LittlerootTown/scripts.pory"

# 69 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MoveRivalFromOldale::
# 70 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_OLDALE_RIVAL_STATE, 2
# 71 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
# 72 "data/maps/LittlerootTown/scripts.pory"
	return
# 73 "data/maps/LittlerootTown/scripts.pory"

# 74 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent::
# 75 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 5
# 76 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 5
# 77 "data/maps/LittlerootTown/scripts.pory"
	return
# 78 "data/maps/LittlerootTown/scripts.pory"

# 79 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MoveMomToMaysDoor::
# 80 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_MOM, 14, 8
# 81 "data/maps/LittlerootTown/scripts.pory"
	return
# 82 "data/maps/LittlerootTown/scripts.pory"

# 83 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetTwinPos::
# 84 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_EventScript_SetTwinGuardingRoutePos
# 85 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_TWIN, 10, 1
# 86 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype LOCALID_TWIN, MOVEMENT_TYPE_FACE_UP
# 87 "data/maps/LittlerootTown/scripts.pory"
	return
# 88 "data/maps/LittlerootTown/scripts.pory"

# 89 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetTwinGuardingRoutePos::
# 90 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_TWIN, 7, 2
# 91 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype LOCALID_TWIN, MOVEMENT_TYPE_FACE_DOWN
# 92 "data/maps/LittlerootTown/scripts.pory"
	return
# 93 "data/maps/LittlerootTown/scripts.pory"

# 94 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetMomStandingInFrontOfDoorPos::
# 95 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
# 96 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_DOWN
# 97 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 98 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetMomInFrontOfDoorMale
# 99 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_SetMomInFrontOfDoorFemale
# 100 "data/maps/LittlerootTown/scripts.pory"
	return
# 101 "data/maps/LittlerootTown/scripts.pory"

# 102 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetMomInFrontOfDoorMale::
# 103 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_MOM, 5, 9
# 104 "data/maps/LittlerootTown/scripts.pory"
	return
# 105 "data/maps/LittlerootTown/scripts.pory"

# 106 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetMomInFrontOfDoorFemale::
# 107 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_MOM, 14, 9
# 108 "data/maps/LittlerootTown/scripts.pory"
	return
# 109 "data/maps/LittlerootTown/scripts.pory"

# 110 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_OnFrame:
# 111 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 1, LittlerootTown_EventScript_StepOffTruckMale
# 112 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 2, LittlerootTown_EventScript_StepOffTruckFemale
# 113 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_BeginDexUpgradeScene
# 114 "data/maps/LittlerootTown/scripts.pory"
	.2byte 0
# 115 "data/maps/LittlerootTown/scripts.pory"

# 116 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_StepOffTruckMale::
# 117 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 118 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 5
# 119 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 8
# 120 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 121 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
# 122 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F, 8, 8
# 123 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 124 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 125 "data/maps/LittlerootTown/scripts.pory"
	end
# 126 "data/maps/LittlerootTown/scripts.pory"

# 127 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_StepOffTruckFemale::
# 128 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 129 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 14
# 130 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 8
# 131 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 132 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
# 133 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F, 2, 8
# 134 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 135 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 136 "data/maps/LittlerootTown/scripts.pory"
	end
# 137 "data/maps/LittlerootTown/scripts.pory"

# 138 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoInsideWithMom::
# 139 "data/maps/LittlerootTown/scripts.pory"
	delay 15
# 140 "data/maps/LittlerootTown/scripts.pory"
	playse SE_LEDGE
# 141 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerStepOffTruck
# 142 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 143 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 144 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 145 "data/maps/LittlerootTown/scripts.pory"
	addobject LOCALID_MOM
# 146 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitHouse
# 147 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 148 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 149 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 150 "data/maps/LittlerootTown/scripts.pory"
	delay 10
# 151 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerAtTruck
# 152 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 153 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_OurNewHomeLetsGoInside, MSGBOX_DEFAULT
# 154 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 155 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachDoor
# 156 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerApproachDoor
# 157 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 158 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 159 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 160 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomEnterHouse
# 161 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerEnterHouse
# 162 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 163 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
# 164 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 3
# 165 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
# 166 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 167 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 168 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
# 169 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 170 "data/maps/LittlerootTown/scripts.pory"
	return
# 171 "data/maps/LittlerootTown/scripts.pory"

# 172 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitHouse:
# 173 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 174 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 175 "data/maps/LittlerootTown/scripts.pory"

# 176 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerAtTruck:
# 177 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 178 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_left
# 179 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 180 "data/maps/LittlerootTown/scripts.pory"

# 181 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachDoor:
# 182 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 183 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 184 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 185 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 186 "data/maps/LittlerootTown/scripts.pory"

# 187 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomEnterHouse:
# 188 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 189 "data/maps/LittlerootTown/scripts.pory"
	set_invisible
# 190 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 191 "data/maps/LittlerootTown/scripts.pory"

# 192 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerApproachDoor:
# 193 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 194 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 195 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 196 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 197 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 198 "data/maps/LittlerootTown/scripts.pory"

# 199 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerEnterHouse:
# 200 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 201 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 202 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 203 "data/maps/LittlerootTown/scripts.pory"

# 204 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerStepOffTruck:
# 205 "data/maps/LittlerootTown/scripts.pory"
	jump_right
# 206 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 207 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 208 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 209 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 210 "data/maps/LittlerootTown/scripts.pory"

# 211 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BeginDexUpgradeScene::
# 212 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 213 "data/maps/LittlerootTown/scripts.pory"
	playse SE_PIN
# 214 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_ExclamationMark
# 215 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 216 "data/maps/LittlerootTown/scripts.pory"
	delay 80
# 217 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BirchSomethingToShowYouAtLab, MSGBOX_DEFAULT
# 218 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 219 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
# 220 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
# 221 "data/maps/LittlerootTown/scripts.pory"
	delay 20
# 222 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 223 "data/maps/LittlerootTown/scripts.pory"
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
# 224 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 225 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 226 "data/maps/LittlerootTown/scripts.pory"
	end
# 227 "data/maps/LittlerootTown/scripts.pory"

# 228 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_OnWarp:
# 229 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade
# 230 "data/maps/LittlerootTown/scripts.pory"
	.2byte 0
# 231 "data/maps/LittlerootTown/scripts.pory"

# 232 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade::
# 233 "data/maps/LittlerootTown/scripts.pory"
	addobject LOCALID_BIRCH
# 234 "data/maps/LittlerootTown/scripts.pory"
	addobject LOCALID_RIVAL
# 235 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 236 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeMale
# 237 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeFemale
# 238 "data/maps/LittlerootTown/scripts.pory"
	end
# 239 "data/maps/LittlerootTown/scripts.pory"

# 240 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeMale::
# 241 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_RIVAL, 6, 10
# 242 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_BIRCH, 5, 10
# 243 "data/maps/LittlerootTown/scripts.pory"
	end
# 244 "data/maps/LittlerootTown/scripts.pory"

# 245 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeFemale::
# 246 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_RIVAL, 13, 10
# 247 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_BIRCH, 14, 10
# 248 "data/maps/LittlerootTown/scripts.pory"
	end
# 249 "data/maps/LittlerootTown/scripts.pory"

# 250 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_FatMan::
# 251 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanUsePCToStoreItems, MSGBOX_NPC
# 252 "data/maps/LittlerootTown/scripts.pory"
	end
# 253 "data/maps/LittlerootTown/scripts.pory"

# 254 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_Boy::
# 255 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BirchSpendsDaysInLab, MSGBOX_NPC
# 256 "data/maps/LittlerootTown/scripts.pory"
	end
# 257 "data/maps/LittlerootTown/scripts.pory"

# 258 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_Twin::
# 259 "data/maps/LittlerootTown/scripts.pory"
	lock
# 260 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 261 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_ADVENTURE_STARTED, LittlerootTown_EventScript_GoodLuck
# 262 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_YouSavedBirch
# 263 "data/maps/LittlerootTown/scripts.pory"
	goto_if_ne VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_EventScript_GoSaveBirch
# 264 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 265 "data/maps/LittlerootTown/scripts.pory"
	release
# 266 "data/maps/LittlerootTown/scripts.pory"
	end
# 267 "data/maps/LittlerootTown/scripts.pory"

# 268 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoSaveBirch::
# 269 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 270 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 271 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 272 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
# 273 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 274 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 275 "data/maps/LittlerootTown/scripts.pory"
	release
# 276 "data/maps/LittlerootTown/scripts.pory"
	end
# 277 "data/maps/LittlerootTown/scripts.pory"

# 278 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_YouSavedBirch::
# 279 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 280 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_YouSavedBirch, MSGBOX_DEFAULT
# 281 "data/maps/LittlerootTown/scripts.pory"
	release
# 282 "data/maps/LittlerootTown/scripts.pory"
	end
# 283 "data/maps/LittlerootTown/scripts.pory"

# 284 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoodLuck::
# 285 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_GoodLuckCatchingPokemon, MSGBOX_DEFAULT
# 286 "data/maps/LittlerootTown/scripts.pory"
	release
# 287 "data/maps/LittlerootTown/scripts.pory"
	end
# 288 "data/maps/LittlerootTown/scripts.pory"

# 289 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_NeedPokemonTriggerLeft::
# 290 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 291 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinApproachPlayerLeft
# 292 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 293 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 294 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinReturnLeft
# 295 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 296 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 297 "data/maps/LittlerootTown/scripts.pory"
	end
# 298 "data/maps/LittlerootTown/scripts.pory"

# 299 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_DangerousWithoutPokemon::
# 300 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 301 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 302 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinPushPlayerFromRoute
# 303 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PushPlayerBackFromRoute
# 304 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 305 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_DangerousIfYouDontHavePokemon, MSGBOX_DEFAULT
# 306 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 307 "data/maps/LittlerootTown/scripts.pory"
	return
# 308 "data/maps/LittlerootTown/scripts.pory"

# 309 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerLeft:
# 310 "data/maps/LittlerootTown/scripts.pory"
	face_right
# 311 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 312 "data/maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 313 "data/maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 314 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 315 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 316 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 317 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 318 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 319 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 320 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 321 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_left
# 322 "data/maps/LittlerootTown/scripts.pory"
	face_down
# 323 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 324 "data/maps/LittlerootTown/scripts.pory"

# 325 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinPushPlayerFromRoute:
# 326 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 327 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 328 "data/maps/LittlerootTown/scripts.pory"

# 329 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnLeft:
# 330 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 331 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 332 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 333 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 334 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 335 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 336 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 337 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 338 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_down
# 339 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 340 "data/maps/LittlerootTown/scripts.pory"

# 341 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PushPlayerBackFromRoute:
# 342 "data/maps/LittlerootTown/scripts.pory"
	lock_facing_direction
# 343 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 344 "data/maps/LittlerootTown/scripts.pory"
	unlock_facing_direction
# 345 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 346 "data/maps/LittlerootTown/scripts.pory"

# 347 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_NeedPokemonTriggerRight::
# 348 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 349 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinApproachPlayerRight
# 350 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 351 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 352 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinReturnRight
# 353 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 354 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 355 "data/maps/LittlerootTown/scripts.pory"
	end
# 356 "data/maps/LittlerootTown/scripts.pory"

# 357 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerRight:
# 358 "data/maps/LittlerootTown/scripts.pory"
	face_right
# 359 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 360 "data/maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 361 "data/maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 362 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 363 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 364 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 365 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 366 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 367 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 368 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 369 "data/maps/LittlerootTown/scripts.pory"
	face_down
# 370 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 371 "data/maps/LittlerootTown/scripts.pory"

# 372 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnRight:
# 373 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 374 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 375 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 376 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 377 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 378 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_down
# 379 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 380 "data/maps/LittlerootTown/scripts.pory"

# 381 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoSaveBirchTrigger::
# 382 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 383 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, Common_Movement_WalkInPlaceFasterRight
# 384 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 385 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 386 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 387 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 388 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 389 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 390 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
# 391 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 392 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 393 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 394 "data/maps/LittlerootTown/scripts.pory"
	end
# 395 "data/maps/LittlerootTown/scripts.pory"

# 396 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_TownSign::
# 397 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_TownSign, MSGBOX_SIGN
# 398 "data/maps/LittlerootTown/scripts.pory"
	end
# 399 "data/maps/LittlerootTown/scripts.pory"

# 400 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BirchsLabSign::
# 401 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsLab, MSGBOX_SIGN
# 402 "data/maps/LittlerootTown/scripts.pory"
	end
# 403 "data/maps/LittlerootTown/scripts.pory"

# 404 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BrendansHouseSign::
# 405 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 406 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 407 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_PlayersHouseSignMale
# 408 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_BirchsHouseSignFemale
# 409 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 410 "data/maps/LittlerootTown/scripts.pory"
	end
# 411 "data/maps/LittlerootTown/scripts.pory"

# 412 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_PlayersHouseSignMale::
# 413 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
# 414 "data/maps/LittlerootTown/scripts.pory"
	return
# 415 "data/maps/LittlerootTown/scripts.pory"

# 416 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BirchsHouseSignFemale::
# 417 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
# 418 "data/maps/LittlerootTown/scripts.pory"
	return
# 419 "data/maps/LittlerootTown/scripts.pory"

# 420 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MaysHouseSign::
# 421 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 422 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 423 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_BirchsHouseSignMale
# 424 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_PlayersHouseSignFemale
# 425 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 426 "data/maps/LittlerootTown/scripts.pory"
	end
# 427 "data/maps/LittlerootTown/scripts.pory"

# 428 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BirchsHouseSignMale::
# 429 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
# 430 "data/maps/LittlerootTown/scripts.pory"
	return
# 431 "data/maps/LittlerootTown/scripts.pory"

# 432 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_PlayersHouseSignFemale::
# 433 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
# 434 "data/maps/LittlerootTown/scripts.pory"
	return
# 435 "data/maps/LittlerootTown/scripts.pory"

# 436 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger0::
# 437 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 438 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 0
# 439 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_MOM, 10, 9
# 440 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 441 "data/maps/LittlerootTown/scripts.pory"
	end
# 442 "data/maps/LittlerootTown/scripts.pory"

# 443 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger1::
# 444 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 445 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 1
# 446 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_MOM, 11, 9
# 447 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 448 "data/maps/LittlerootTown/scripts.pory"
	end
# 449 "data/maps/LittlerootTown/scripts.pory"

# 450 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger2::
# 451 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 452 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 2
# 453 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 454 "data/maps/LittlerootTown/scripts.pory"
	end
# 455 "data/maps/LittlerootTown/scripts.pory"

# 456 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger3::
# 457 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 458 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 3
# 459 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 460 "data/maps/LittlerootTown/scripts.pory"
	end
# 461 "data/maps/LittlerootTown/scripts.pory"

# 462 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger4::
# 463 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 464 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 4
# 465 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 466 "data/maps/LittlerootTown/scripts.pory"
	end
# 467 "data/maps/LittlerootTown/scripts.pory"

# 468 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger5::
# 469 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 470 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 5
# 471 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 472 "data/maps/LittlerootTown/scripts.pory"
	end
# 473 "data/maps/LittlerootTown/scripts.pory"

# 474 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger::
# 475 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 476 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_MomNoticePlayerMale
# 477 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_MomNoticePlayerFemale
# 478 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 479 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetHomeDoorCoordsMale
# 480 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
# 481 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_WaitPlayer, MSGBOX_DEFAULT
# 482 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 483 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 484 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_MomApproachPlayerMale
# 485 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_MomApproachPlayerFemale
# 486 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GiveRunningShoes
# 487 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 488 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_MomReturnHomeMale
# 489 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_MomReturnHomeFemale
# 490 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_SetReceivedRunningShoes
# 491 "data/maps/LittlerootTown/scripts.pory"
	end
# 492 "data/maps/LittlerootTown/scripts.pory"

# 493 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetHomeDoorCoordsMale::
# 494 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 5
# 495 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
# 496 "data/maps/LittlerootTown/scripts.pory"
	return
# 497 "data/maps/LittlerootTown/scripts.pory"

# 498 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetHomeDoorCoordsFemale::
# 499 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 14
# 500 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
# 501 "data/maps/LittlerootTown/scripts.pory"
	return
# 502 "data/maps/LittlerootTown/scripts.pory"

# 503 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomNoticePlayerMale::
# 504 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFasterRight
# 505 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 506 "data/maps/LittlerootTown/scripts.pory"
	return
# 507 "data/maps/LittlerootTown/scripts.pory"

# 508 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomNoticePlayerFemale::
# 509 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFasterLeft
# 510 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 511 "data/maps/LittlerootTown/scripts.pory"
	return
# 512 "data/maps/LittlerootTown/scripts.pory"

# 513 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale::
# 514 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomApproachPlayer0
# 515 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomApproachPlayer1
# 516 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomApproachPlayerMale2
# 517 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomApproachPlayerMale3
# 518 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomApproachPlayerMale4
# 519 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomApproachPlayerMale5
# 520 "data/maps/LittlerootTown/scripts.pory"
	return
# 521 "data/maps/LittlerootTown/scripts.pory"

# 522 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale::
# 523 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomApproachPlayer0
# 524 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomApproachPlayer1
# 525 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomApproachPlayerFemale2
# 526 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomApproachPlayerFemale3
# 527 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomApproachPlayerFemale4
# 528 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomApproachPlayerFemale5
# 529 "data/maps/LittlerootTown/scripts.pory"
	return
# 530 "data/maps/LittlerootTown/scripts.pory"

# 531 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayer0::
# 532 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 533 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 534 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayer0
# 535 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 536 "data/maps/LittlerootTown/scripts.pory"
	return
# 537 "data/maps/LittlerootTown/scripts.pory"

# 538 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayer1::
# 539 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 540 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 541 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayer1
# 542 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 543 "data/maps/LittlerootTown/scripts.pory"
	return
# 544 "data/maps/LittlerootTown/scripts.pory"

# 545 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale2::
# 546 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 547 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 548 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale2
# 549 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 550 "data/maps/LittlerootTown/scripts.pory"
	return
# 551 "data/maps/LittlerootTown/scripts.pory"

# 552 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale3::
# 553 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 554 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 555 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale3
# 556 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 557 "data/maps/LittlerootTown/scripts.pory"
	return
# 558 "data/maps/LittlerootTown/scripts.pory"

# 559 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale4::
# 560 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 561 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 562 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale4
# 563 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 564 "data/maps/LittlerootTown/scripts.pory"
	return
# 565 "data/maps/LittlerootTown/scripts.pory"

# 566 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale5::
# 567 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 568 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 569 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale5
# 570 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 571 "data/maps/LittlerootTown/scripts.pory"
	return
# 572 "data/maps/LittlerootTown/scripts.pory"

# 573 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale2::
# 574 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 575 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 576 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale2
# 577 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 578 "data/maps/LittlerootTown/scripts.pory"
	return
# 579 "data/maps/LittlerootTown/scripts.pory"

# 580 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale3::
# 581 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 582 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 583 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale3
# 584 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 585 "data/maps/LittlerootTown/scripts.pory"
	return
# 586 "data/maps/LittlerootTown/scripts.pory"

# 587 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale4::
# 588 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 589 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 590 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale4
# 591 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 592 "data/maps/LittlerootTown/scripts.pory"
	return
# 593 "data/maps/LittlerootTown/scripts.pory"

# 594 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale5::
# 595 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 596 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 597 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale5
# 598 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 599 "data/maps/LittlerootTown/scripts.pory"
	return
# 600 "data/maps/LittlerootTown/scripts.pory"

# 601 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale::
# 602 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomReturnHome0
# 603 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomReturnHome1
# 604 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomReturnHomeMale2
# 605 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomReturnHomeMale3
# 606 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomReturnHomeMale4
# 607 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomReturnHomeMale5
# 608 "data/maps/LittlerootTown/scripts.pory"
	return
# 609 "data/maps/LittlerootTown/scripts.pory"

# 610 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale::
# 611 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomReturnHome0
# 612 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomReturnHome1
# 613 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomReturnHomeFemale2
# 614 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomReturnHomeFemale3
# 615 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomReturnHomeFemale4
# 616 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomReturnHomeFemale5
# 617 "data/maps/LittlerootTown/scripts.pory"
	return
# 618 "data/maps/LittlerootTown/scripts.pory"

# 619 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHome0::
# 620 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHome0
# 621 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 622 "data/maps/LittlerootTown/scripts.pory"
	return
# 623 "data/maps/LittlerootTown/scripts.pory"

# 624 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHome1::
# 625 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHome1
# 626 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 627 "data/maps/LittlerootTown/scripts.pory"
	return
# 628 "data/maps/LittlerootTown/scripts.pory"

# 629 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale2::
# 630 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale2
# 631 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 632 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 633 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 634 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 635 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 636 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 637 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 638 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 639 "data/maps/LittlerootTown/scripts.pory"
	return
# 640 "data/maps/LittlerootTown/scripts.pory"

# 641 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale3::
# 642 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale3
# 643 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 644 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 645 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 646 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 647 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 648 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 649 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 650 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 651 "data/maps/LittlerootTown/scripts.pory"
	return
# 652 "data/maps/LittlerootTown/scripts.pory"

# 653 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale4::
# 654 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale4
# 655 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 656 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 657 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 658 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 659 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 660 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 661 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 662 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 663 "data/maps/LittlerootTown/scripts.pory"
	return
# 664 "data/maps/LittlerootTown/scripts.pory"

# 665 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale5::
# 666 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale5
# 667 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 668 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 669 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 670 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 671 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 672 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 673 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 674 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 675 "data/maps/LittlerootTown/scripts.pory"
	return
# 676 "data/maps/LittlerootTown/scripts.pory"

# 677 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale2::
# 678 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale2
# 679 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 680 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 681 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 682 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 683 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 684 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 685 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 686 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 687 "data/maps/LittlerootTown/scripts.pory"
	return
# 688 "data/maps/LittlerootTown/scripts.pory"

# 689 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale3::
# 690 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale3
# 691 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 692 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 693 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 694 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 695 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 696 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 697 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 698 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 699 "data/maps/LittlerootTown/scripts.pory"
	return
# 700 "data/maps/LittlerootTown/scripts.pory"

# 701 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale4::
# 702 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale4
# 703 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 704 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 705 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 706 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 707 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 708 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 709 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 710 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 711 "data/maps/LittlerootTown/scripts.pory"
	return
# 712 "data/maps/LittlerootTown/scripts.pory"

# 713 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale5::
# 714 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale5
# 715 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 716 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 717 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 718 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 719 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 720 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 721 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 722 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 723 "data/maps/LittlerootTown/scripts.pory"
	return
# 724 "data/maps/LittlerootTown/scripts.pory"

# 725 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayer0:
# 726 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 727 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 728 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 729 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 730 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 731 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 732 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 733 "data/maps/LittlerootTown/scripts.pory"

# 734 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayer1:
# 735 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 736 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 737 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 738 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 739 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 740 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 741 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 742 "data/maps/LittlerootTown/scripts.pory"

# 743 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale2:
# 744 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 745 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 746 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 747 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 748 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 749 "data/maps/LittlerootTown/scripts.pory"

# 750 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale3:
# 751 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 752 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 753 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 754 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 755 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 756 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 757 "data/maps/LittlerootTown/scripts.pory"

# 758 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale4:
# 759 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 760 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 761 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 762 "data/maps/LittlerootTown/scripts.pory"

# 763 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale5:
# 764 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 765 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 766 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 767 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 768 "data/maps/LittlerootTown/scripts.pory"

# 769 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale2:
# 770 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 771 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 772 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 773 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 774 "data/maps/LittlerootTown/scripts.pory"

# 775 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale3:
# 776 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 777 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 778 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 779 "data/maps/LittlerootTown/scripts.pory"

# 780 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale4:
# 781 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 782 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 783 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 784 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 785 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 786 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 787 "data/maps/LittlerootTown/scripts.pory"

# 788 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale5:
# 789 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 790 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 791 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 792 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 793 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 794 "data/maps/LittlerootTown/scripts.pory"

# 795 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHome0:
# 796 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 797 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 798 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 799 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 800 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 801 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 802 "data/maps/LittlerootTown/scripts.pory"

# 803 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHome1:
# 804 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 805 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 806 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 807 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 808 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 809 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 810 "data/maps/LittlerootTown/scripts.pory"

# 811 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale2:
# 812 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 813 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 814 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 815 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 816 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 817 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 818 "data/maps/LittlerootTown/scripts.pory"

# 819 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale3:
# 820 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 821 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 822 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 823 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 824 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 825 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 826 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 827 "data/maps/LittlerootTown/scripts.pory"

# 828 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale4:
# 829 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 830 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 831 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 832 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 833 "data/maps/LittlerootTown/scripts.pory"

# 834 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale5:
# 835 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 836 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 837 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 838 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 839 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 840 "data/maps/LittlerootTown/scripts.pory"

# 841 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale2:
# 842 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 843 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 844 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 845 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 846 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 847 "data/maps/LittlerootTown/scripts.pory"

# 848 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale3:
# 849 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 850 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 851 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 852 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 853 "data/maps/LittlerootTown/scripts.pory"

# 854 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale4:
# 855 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 856 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 857 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 858 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 859 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 860 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 861 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 862 "data/maps/LittlerootTown/scripts.pory"

# 863 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale5:
# 864 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 865 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 866 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 867 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 868 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 869 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 870 "data/maps/LittlerootTown/scripts.pory"

# 871 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitThroughDoor:
# 872 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 873 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 874 "data/maps/LittlerootTown/scripts.pory"

# 875 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_Mom::
# 876 "data/maps/LittlerootTown/scripts.pory"
	lock
# 877 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 878 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 879 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetHomeDoorCoordsMale
# 880 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
# 881 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GiveRunningShoes
# 882 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFasterUp
# 883 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 884 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 885 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 886 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 887 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 888 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 889 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 890 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 891 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_SetReceivedRunningShoes
# 892 "data/maps/LittlerootTown/scripts.pory"
	end
# 893 "data/maps/LittlerootTown/scripts.pory"

# 894 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetReceivedRunningShoes::
# 895 "data/maps/LittlerootTown/scripts.pory"
	removeobject LOCALID_MOM
# 896 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 897 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
# 898 "data/maps/LittlerootTown/scripts.pory"
	release
# 899 "data/maps/LittlerootTown/scripts.pory"
	end
# 900 "data/maps/LittlerootTown/scripts.pory"

# 901 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoes::
# 902 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_WearTheseRunningShoes, MSGBOX_DEFAULT
# 903 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 904 "data/maps/LittlerootTown/scripts.pory"
	message LittlerootTown_Text_SwitchShoesWithRunningShoes
# 905 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 906 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_RECEIVED_RUNNING_SHOES
# 907 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ExplainRunningShoes, MSGBOX_DEFAULT
# 908 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ComeHomeIfAnythingHappens, MSGBOX_DEFAULT
# 909 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 910 "data/maps/LittlerootTown/scripts.pory"
	delay 30
# 911 "data/maps/LittlerootTown/scripts.pory"
	return
# 912 "data/maps/LittlerootTown/scripts.pory"

# 913 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_OurNewHomeLetsGoInside:
# 914 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: {PLAYER}, we're here, honey!\p"
# 915 "data/maps/LittlerootTown/scripts.pory"
	.string "It must be tiring riding with our things\n"
# 916 "data/maps/LittlerootTown/scripts.pory"
	.string "in the moving truck.\p"
# 917 "data/maps/LittlerootTown/scripts.pory"
	.string "Well, this is LITTLEROOT TOWN.\p"
# 918 "data/maps/LittlerootTown/scripts.pory"
	.string "How do you like it?\n"
# 919 "data/maps/LittlerootTown/scripts.pory"
	.string "This is our new home!\p"
# 920 "data/maps/LittlerootTown/scripts.pory"
	.string "It has a quaint feel, but it seems to be\n"
# 921 "data/maps/LittlerootTown/scripts.pory"
	.string "an easy place to live, don't you think?\p"
# 922 "data/maps/LittlerootTown/scripts.pory"
	.string "And, you get your own room, {PLAYER}!\n"
# 923 "data/maps/LittlerootTown/scripts.pory"
	.string "Let's go inside.$"
# 924 "data/maps/LittlerootTown/scripts.pory"

# 925 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_WaitPlayer:
# 926 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: Wait, {PLAYER}!$"
# 927 "data/maps/LittlerootTown/scripts.pory"

# 928 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_WearTheseRunningShoes:
# 929 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: {PLAYER}! {PLAYER}! Did you\n"
# 930 "data/maps/LittlerootTown/scripts.pory"
	.string "introduce yourself to PROF. BIRCH?\p"
# 931 "data/maps/LittlerootTown/scripts.pory"
	.string "Oh! What an adorable POKéMON!\n"
# 932 "data/maps/LittlerootTown/scripts.pory"
	.string "You got it from PROF. BIRCH. How nice!\p"
# 933 "data/maps/LittlerootTown/scripts.pory"
	.string "You're your father's child, all right.\n"
# 934 "data/maps/LittlerootTown/scripts.pory"
	.string "You look good together with POKéMON!\p"
# 935 "data/maps/LittlerootTown/scripts.pory"
	.string "Here, honey! If you're going out on an\n"
# 936 "data/maps/LittlerootTown/scripts.pory"
	.string "adventure, wear these RUNNING SHOES.\p"
# 937 "data/maps/LittlerootTown/scripts.pory"
	.string "They'll put a zip in your step!$"
# 938 "data/maps/LittlerootTown/scripts.pory"

# 939 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_SwitchShoesWithRunningShoes:
# 940 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} switched shoes with the\n"
# 941 "data/maps/LittlerootTown/scripts.pory"
	.string "RUNNING SHOES.$"
# 942 "data/maps/LittlerootTown/scripts.pory"

# 943 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ExplainRunningShoes:
# 944 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: {PLAYER}, those shoes came with\n"
# 945 "data/maps/LittlerootTown/scripts.pory"
	.string "instructions.\p"
# 946 "data/maps/LittlerootTown/scripts.pory"
	.string "“Press the B Button while wearing these\n"
# 947 "data/maps/LittlerootTown/scripts.pory"
	.string "RUNNING SHOES to run extra-fast!\p"
# 948 "data/maps/LittlerootTown/scripts.pory"
	.string "“Slip on these RUNNING SHOES and race\n"
# 949 "data/maps/LittlerootTown/scripts.pory"
	.string "in the great outdoors!”$"
# 950 "data/maps/LittlerootTown/scripts.pory"

# 951 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ComeHomeIfAnythingHappens:
# 952 "data/maps/LittlerootTown/scripts.pory"
	.string "… … … … … … … …\n"
# 953 "data/maps/LittlerootTown/scripts.pory"
	.string "… … … … … … … …\p"
# 954 "data/maps/LittlerootTown/scripts.pory"
	.string "To think that you have your very own\n"
# 955 "data/maps/LittlerootTown/scripts.pory"
	.string "POKéMON now…\l"
# 956 "data/maps/LittlerootTown/scripts.pory"
	.string "Your father will be overjoyed.\p"
# 957 "data/maps/LittlerootTown/scripts.pory"
	.string "…But please be careful.\n"
# 958 "data/maps/LittlerootTown/scripts.pory"
	.string "If anything happens, you can come home.\p"
# 959 "data/maps/LittlerootTown/scripts.pory"
	.string "Go on, go get them, honey!$"
# 960 "data/maps/LittlerootTown/scripts.pory"

# 961 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_CanUsePCToStoreItems:
# 962 "data/maps/LittlerootTown/scripts.pory"
	.string "If you use a PC, you can store items\n"
# 963 "data/maps/LittlerootTown/scripts.pory"
	.string "and POKéMON.\p"
# 964 "data/maps/LittlerootTown/scripts.pory"
	.string "The power of science is staggering!$"
# 965 "data/maps/LittlerootTown/scripts.pory"

# 966 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_BirchSpendsDaysInLab:
# 967 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH spends days in his LAB\n"
# 968 "data/maps/LittlerootTown/scripts.pory"
	.string "studying, then he'll suddenly go out in\l"
# 969 "data/maps/LittlerootTown/scripts.pory"
	.string "the wild to do more research…\p"
# 970 "data/maps/LittlerootTown/scripts.pory"
	.string "When does PROF. BIRCH spend time\n"
# 971 "data/maps/LittlerootTown/scripts.pory"
	.string "at home?$"
# 972 "data/maps/LittlerootTown/scripts.pory"

# 973 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut:
# 974 "data/maps/LittlerootTown/scripts.pory"
	.string "Um, um, um!\p"
# 975 "data/maps/LittlerootTown/scripts.pory"
	.string "If you go outside and go in the grass,\n"
# 976 "data/maps/LittlerootTown/scripts.pory"
	.string "wild POKéMON will jump out!$"
# 977 "data/maps/LittlerootTown/scripts.pory"

# 978 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_DangerousIfYouDontHavePokemon:
# 979 "data/maps/LittlerootTown/scripts.pory"
	.string "It's dangerous if you don't have\n"
# 980 "data/maps/LittlerootTown/scripts.pory"
	.string "your own POKéMON.$"
# 981 "data/maps/LittlerootTown/scripts.pory"

# 982 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_CanYouGoSeeWhatsHappening:
# 983 "data/maps/LittlerootTown/scripts.pory"
	.string "Um, hi!\p"
# 984 "data/maps/LittlerootTown/scripts.pory"
	.string "There are scary POKéMON outside!\n"
# 985 "data/maps/LittlerootTown/scripts.pory"
	.string "I can hear their cries!\p"
# 986 "data/maps/LittlerootTown/scripts.pory"
	.string "I want to go see what's going on,\n"
# 987 "data/maps/LittlerootTown/scripts.pory"
	.string "but I don't have any POKéMON…\p"
# 988 "data/maps/LittlerootTown/scripts.pory"
	.string "Can you go see what's happening\n"
# 989 "data/maps/LittlerootTown/scripts.pory"
	.string "for me?$"
# 990 "data/maps/LittlerootTown/scripts.pory"

# 991 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_YouSavedBirch:
# 992 "data/maps/LittlerootTown/scripts.pory"
	.string "You saved PROF. BIRCH!\n"
# 993 "data/maps/LittlerootTown/scripts.pory"
	.string "I'm so glad!$"
# 994 "data/maps/LittlerootTown/scripts.pory"

# 995 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_GoodLuckCatchingPokemon:
# 996 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you going to catch POKéMON?\n"
# 997 "data/maps/LittlerootTown/scripts.pory"
	.string "Good luck!$"
# 998 "data/maps/LittlerootTown/scripts.pory"

# 999 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_TownSign:
# 1000 "data/maps/LittlerootTown/scripts.pory"
	.string "LITTLEROOT TOWN\n"
# 1001 "data/maps/LittlerootTown/scripts.pory"
	.string "“A town that can't be shaded any hue.”$"
# 1002 "data/maps/LittlerootTown/scripts.pory"

# 1003 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ProfBirchsLab:
# 1004 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH'S POKéMON LAB$"
# 1005 "data/maps/LittlerootTown/scripts.pory"

# 1006 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_PlayersHouse:
# 1007 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER}'s HOUSE$"
# 1008 "data/maps/LittlerootTown/scripts.pory"

# 1009 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ProfBirchsHouse:
# 1010 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH'S HOUSE$"
# 1011 "data/maps/LittlerootTown/scripts.pory"

# 1012 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_BirchSomethingToShowYouAtLab:
# 1013 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH: Well, well, {PLAYER}{KUN}!\n"
# 1014 "data/maps/LittlerootTown/scripts.pory"
	.string "That was good work out there!\p"
# 1015 "data/maps/LittlerootTown/scripts.pory"
	.string "I knew there was something special\n"
# 1016 "data/maps/LittlerootTown/scripts.pory"
	.string "about you when I first saw you,\l"
# 1017 "data/maps/LittlerootTown/scripts.pory"
	.string "but I never expected this.\p"
# 1018 "data/maps/LittlerootTown/scripts.pory"
	.string "Oh, yes. Do you still have the POKéDEX\n"
# 1019 "data/maps/LittlerootTown/scripts.pory"
	.string "I gave you?\p"
# 1020 "data/maps/LittlerootTown/scripts.pory"
	.string "I have something to show you.\n"
# 1021 "data/maps/LittlerootTown/scripts.pory"
	.string "Let's go to my LAB.$"
# 1022 "data/maps/LittlerootTown/scripts.pory"

# 1023 "data/maps/LittlerootTown/scripts.pory"
Miniboss_Text_ScaryGuy_Intro:
# 1024 "data/maps/LittlerootTown/scripts.pory"
	.string "Prepare to be scared!$"
# 1025 "data/maps/LittlerootTown/scripts.pory"

# 1026 "data/maps/LittlerootTown/scripts.pory"
Miniboss_Text_ScaryGuy_Defeat:
# 1027 "data/maps/LittlerootTown/scripts.pory"
	.string "Aw man...\n"
# 1028 "data/maps/LittlerootTown/scripts.pory"
	.string "I'm scared.$"
# 1029 "data/maps/LittlerootTown/scripts.pory"

# 1030 "data/maps/LittlerootTown/scripts.pory"
Miniboss_Text_Protector_Intro:
# 1031 "data/maps/LittlerootTown/scripts.pory"
	.string "You'll never break through my Pokémon!$"
# 1032 "data/maps/LittlerootTown/scripts.pory"

# 1033 "data/maps/LittlerootTown/scripts.pory"
Miniboss_Text_Protector_Defeat:
# 1034 "data/maps/LittlerootTown/scripts.pory"
	.string "Wow!\n"
# 1035 "data/maps/LittlerootTown/scripts.pory"
	.string "You're mean!$"
# 1036 "data/maps/LittlerootTown/scripts.pory"

# 1037 "data/maps/LittlerootTown/scripts.pory"
Miniboss_Text_ProtectorNeedTwoMons:
# 1038 "data/maps/LittlerootTown/scripts.pory"
	.string "You'll need at least two Pokémon\n"
# 1039 "data/maps/LittlerootTown/scripts.pory"
	.string "if you want to challenge me."
# 1040 "data/maps/LittlerootTown/scripts.pory"

# 1041 "data/maps/LittlerootTown/scripts.pory"
Miniboss_Text_SpeedyChap_Intro:
# 1042 "data/maps/LittlerootTown/scripts.pory"
	.string "I'll leave you in the dust!$"
# 1043 "data/maps/LittlerootTown/scripts.pory"

# 1044 "data/maps/LittlerootTown/scripts.pory"
Miniboss_Text_SpeedyChap_Defeat:
# 1045 "data/maps/LittlerootTown/scripts.pory"
	.string "Dang.\n"
# 1046 "data/maps/LittlerootTown/scripts.pory"
	.string "You're too fast...$"
# 1047 "data/maps/LittlerootTown/scripts.pory"

# 1048 "data/maps/LittlerootTown/scripts.pory"
Miniboss_Text_Collector_Intro:
# 1049 "data/maps/LittlerootTown/scripts.pory"
	.string "My Pokémon are all so cool!$"
# 1050 "data/maps/LittlerootTown/scripts.pory"

# 1051 "data/maps/LittlerootTown/scripts.pory"
Miniboss_Text_Collector_Defeat:
# 1052 "data/maps/LittlerootTown/scripts.pory"
	.string "I love seeing new Pokémon!$"
# 1053 "data/maps/LittlerootTown/scripts.pory"

# 1054 "data/maps/LittlerootTown/scripts.pory"
Miniboss_Text_BoomDude_Intro:
# 1055 "data/maps/LittlerootTown/scripts.pory"
	.string "BOOM!$"
# 1056 "data/maps/LittlerootTown/scripts.pory"

# 1057 "data/maps/LittlerootTown/scripts.pory"
Miniboss_Text_BoomDude_Defeat:
# 1058 "data/maps/LittlerootTown/scripts.pory"
	.string "Boom...$"
# 1059 "data/maps/LittlerootTown/scripts.pory"

# 1060 "data/maps/LittlerootTown/scripts.pory"
Miniboss_Text_CritMaster_Intro:
# 1061 "data/maps/LittlerootTown/scripts.pory"
	.string "Prepare to lose!$"
# 1062 "data/maps/LittlerootTown/scripts.pory"

# 1063 "data/maps/LittlerootTown/scripts.pory"
Miniboss_Text_CritMaster_Defeat:
# 1064 "data/maps/LittlerootTown/scripts.pory"
	.string "How?!\n"
# 1065 "data/maps/LittlerootTown/scripts.pory"
	.string "How did you win?$"
# 1066 "data/maps/LittlerootTown/scripts.pory"

# 1067 "data/maps/LittlerootTown/scripts.pory"
Miniboss_Text_SlowFella_Intro:
# 1068 "data/maps/LittlerootTown/scripts.pory"
	.string "what$"
# 1069 "data/maps/LittlerootTown/scripts.pory"

# 1070 "data/maps/LittlerootTown/scripts.pory"
Miniboss_Text_SlowFella_Defeat:
# 1071 "data/maps/LittlerootTown/scripts.pory"
	.string "huh?$"
# 1072 "data/maps/LittlerootTown/scripts.pory"

# 1073 "data/maps/LittlerootTown/scripts.pory"
Miniboss_Text_Smasher_Intro:
# 1074 "data/maps/LittlerootTown/scripts.pory"
	.string "Check it out!$"
# 1075 "data/maps/LittlerootTown/scripts.pory"

# 1076 "data/maps/LittlerootTown/scripts.pory"
Miniboss_Text_Smasher_Defeat:
# 1077 "data/maps/LittlerootTown/scripts.pory"
	.string "Wasn't that so cool?$"
# 1078 "data/maps/LittlerootTown/scripts.pory"

# 1079 "data/maps/LittlerootTown/scripts.pory"
Miniboss_Text_Purkat_Intro:
# 1080 "data/maps/LittlerootTown/scripts.pory"
	.string "dw$"
# 1081 "data/maps/LittlerootTown/scripts.pory"

# 1082 "data/maps/LittlerootTown/scripts.pory"
Miniboss_Text_Purkat_Defeat:
# 1083 "data/maps/LittlerootTown/scripts.pory"
	.string "Nice job!$"

Miniboss_ScaryGuy::
# 1087 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 1088 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 1089 "data/maps/LittlerootTown/scripts.pory"
	msgbox Miniboss_ScaryGuy_Text_0
# 1090 "data/maps/LittlerootTown/scripts.pory"
	playse SE_M_BATON_PASS
# 1091 "data/maps/LittlerootTown/scripts.pory"
	waitse
# 1092 "data/maps/LittlerootTown/scripts.pory"
	removeobject LOCALID_GROWLITHE
# 1093 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_SCARY_GUYS_GROWLITHE
# 1094 "data/maps/LittlerootTown/scripts.pory"
	trainerbattle_single TRAINER_ROXANNE_2, Miniboss_Text_ScaryGuy_Intro, Miniboss_Text_ScaryGuy_Defeat, Miniboss_ScaryGuyDefeated
# 1095 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 1096 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	return


Miniboss_ScaryGuyDefeated::
# 1100 "data/maps/LittlerootTown/scripts.pory"
	msgbox Miniboss_ScaryGuyDefeated_Text_0
# 1101 "data/maps/LittlerootTown/scripts.pory"
	giveitem ITEM_ABILITY_CAPSULE
# 1102 "data/maps/LittlerootTown/scripts.pory"
	call_if_unset FLAG_DEFEATED_RUSTBORO_GYM, Miniboss_ScaryGuyBPReward
# 1103 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 1104 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	return


Miniboss_ScaryGuyBPReward::
# 1108 "data/maps/LittlerootTown/scripts.pory"
	GiveBP 15
# 1109 "data/maps/LittlerootTown/scripts.pory"
	msgbox Miniboss_ScaryGuyBPReward_Text_0
# 1110 "data/maps/LittlerootTown/scripts.pory"
	playse SE_ITEMFINDER
# 1111 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 1112 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	return


Miniboss_Protector::
# 1116 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 1117 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 1118 "data/maps/LittlerootTown/scripts.pory"
	msgbox Miniboss_Protector_Text_0
# 1119 "data/maps/LittlerootTown/scripts.pory"
	playse SE_M_BATON_PASS
# 1120 "data/maps/LittlerootTown/scripts.pory"
	waitse
# 1121 "data/maps/LittlerootTown/scripts.pory"
	removeobject LOCALID_SPRITZEE
# 1122 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_PROTECTORS_SPRITZEE
# 1123 "data/maps/LittlerootTown/scripts.pory"
	trainerbattle_double TRAINER_ROXANNE_3, Miniboss_Text_Protector_Intro, Miniboss_Text_Protector_Defeat, Miniboss_Text_ProtectorNeedTwoMons, Miniboss_ProtectorDefeated
# 1124 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 1125 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	return


Miniboss_ProtectorDefeated::
# 1129 "data/maps/LittlerootTown/scripts.pory"
	msgbox Miniboss_ProtectorDefeated_Text_0
# 1130 "data/maps/LittlerootTown/scripts.pory"
	giveitem ITEM_EVIOLITE
# 1131 "data/maps/LittlerootTown/scripts.pory"
	call_if_unset FLAG_DEFEATED_DEWFORD_GYM, Miniboss_ProtectorBPReward
# 1132 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 1133 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	return


Miniboss_ProtectorBPReward::
# 1137 "data/maps/LittlerootTown/scripts.pory"
	GiveBP 15
# 1138 "data/maps/LittlerootTown/scripts.pory"
	msgbox Miniboss_ProtectorBPReward_Text_0
# 1139 "data/maps/LittlerootTown/scripts.pory"
	playse SE_ITEMFINDER
# 1140 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 1141 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	return


Miniboss_SpeedyChap::
# 1145 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 1146 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 1147 "data/maps/LittlerootTown/scripts.pory"
	msgbox Miniboss_SpeedyChap_Text_0
# 1148 "data/maps/LittlerootTown/scripts.pory"
	playse SE_M_BATON_PASS
# 1149 "data/maps/LittlerootTown/scripts.pory"
	waitse
# 1150 "data/maps/LittlerootTown/scripts.pory"
	removeobject LOCALID_VOLTORB
# 1151 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_SPEEDY_KIDS_VOLTORB
# 1152 "data/maps/LittlerootTown/scripts.pory"
	trainerbattle_single TRAINER_ROXANNE_4, Miniboss_Text_SpeedyChap_Intro, Miniboss_Text_SpeedyChap_Defeat, Miniboss_SpeedyChapDefeated
# 1153 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 1154 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	return


Miniboss_SpeedyChapDefeated::
# 1158 "data/maps/LittlerootTown/scripts.pory"
	msgbox Miniboss_SpeedyChapDefeated_Text_0
# 1159 "data/maps/LittlerootTown/scripts.pory"
	giveitem ITEM_SALAC_BERRY
# 1160 "data/maps/LittlerootTown/scripts.pory"
	call_if_unset FLAG_DEFEATED_MAUVILLE_GYM, Miniboss_SpeedyChapBPReward
# 1161 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 1162 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	return


Miniboss_SpeedyChapBPReward::
# 1166 "data/maps/LittlerootTown/scripts.pory"
	GiveBP 25
# 1167 "data/maps/LittlerootTown/scripts.pory"
	msgbox Miniboss_SpeedyChapBPReward_Text_0
# 1168 "data/maps/LittlerootTown/scripts.pory"
	playse SE_ITEMFINDER
# 1169 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 1170 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	return


Miniboss_Collector::
# 1174 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 1175 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 1176 "data/maps/LittlerootTown/scripts.pory"
	msgbox Miniboss_Collector_Text_0
# 1177 "data/maps/LittlerootTown/scripts.pory"
	playse SE_M_BATON_PASS
# 1178 "data/maps/LittlerootTown/scripts.pory"
	waitse
# 1179 "data/maps/LittlerootTown/scripts.pory"
	removeobject LOCALID_MEOWTH
# 1180 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_COLLECTORS_MEOWTH
# 1181 "data/maps/LittlerootTown/scripts.pory"
	trainerbattle_single TRAINER_ROXANNE_5, Miniboss_Text_Collector_Intro, Miniboss_Text_Collector_Defeat, Miniboss_CollectorDefeated
# 1182 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 1183 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	return


Miniboss_CollectorDefeated::
# 1187 "data/maps/LittlerootTown/scripts.pory"
	msgbox Miniboss_CollectorDefeated_Text_0
# 1188 "data/maps/LittlerootTown/scripts.pory"
	givemon SPECIES_FROAKIE_SPECIAL, 5
# 1189 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_FROAKIE_SPECIAL
# 1190 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Miniboss_CollectorDefeated_2
# 1196 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq Miniboss_CollectorDefeated_3
# 1203 "data/maps/LittlerootTown/scripts.pory"
	msgbox Miniboss_CollectorDefeated_Text_2
Miniboss_CollectorDefeated_1:
# 1205 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 1206 "data/maps/LittlerootTown/scripts.pory"
	call_if_unset FLAG_DEFEATED_LAVARIDGE_GYM, Miniboss_CollectorBPReward
# 1207 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	return

Miniboss_CollectorDefeated_2:
# 1191 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1192 "data/maps/LittlerootTown/scripts.pory"
	msgbox Miniboss_CollectorDefeated_Text_1
# 1193 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_RECEIVED_SPECIAL_FROAKIE
# 1194 "data/maps/LittlerootTown/scripts.pory"
	call NicknamePartyMon
	goto Miniboss_CollectorDefeated_1

Miniboss_CollectorDefeated_3:
# 1197 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1198 "data/maps/LittlerootTown/scripts.pory"
	msgbox Miniboss_CollectorDefeated_Text_1
# 1199 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_RECEIVED_SPECIAL_FROAKIE
# 1200 "data/maps/LittlerootTown/scripts.pory"
	call NicknameBoxMon
	goto Miniboss_CollectorDefeated_1


TryGiveSpecialFroakie::
# 1211 "data/maps/LittlerootTown/scripts.pory"
	msgbox Miniboss_CollectorDefeated_Text_0
# 1212 "data/maps/LittlerootTown/scripts.pory"
	givemon SPECIES_FROAKIE_SPECIAL, 5
# 1213 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_FROAKIE_SPECIAL
# 1214 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq TryGiveSpecialFroakie_1
# 1220 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq TryGiveSpecialFroakie_2
# 1227 "data/maps/LittlerootTown/scripts.pory"
	msgbox Miniboss_CollectorDefeated_Text_2
	return

TryGiveSpecialFroakie_1:
# 1215 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1216 "data/maps/LittlerootTown/scripts.pory"
	msgbox Miniboss_CollectorDefeated_Text_1
# 1217 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_RECEIVED_SPECIAL_FROAKIE
# 1218 "data/maps/LittlerootTown/scripts.pory"
	call NicknamePartyMon
	return

TryGiveSpecialFroakie_2:
# 1221 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1222 "data/maps/LittlerootTown/scripts.pory"
	msgbox Miniboss_CollectorDefeated_Text_1
# 1223 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_RECEIVED_SPECIAL_FROAKIE
# 1224 "data/maps/LittlerootTown/scripts.pory"
	call NicknameBoxMon
	return


Miniboss_CollectorBPReward::
# 1232 "data/maps/LittlerootTown/scripts.pory"
	GiveBP 25
# 1233 "data/maps/LittlerootTown/scripts.pory"
	msgbox Miniboss_CollectorBPReward_Text_0
# 1234 "data/maps/LittlerootTown/scripts.pory"
	playse SE_ITEMFINDER
# 1235 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 1236 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	return


Miniboss_BoomDude::
# 1240 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 1241 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 1242 "data/maps/LittlerootTown/scripts.pory"
	checkpartydamp
# 1243 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Miniboss_BoomDude_2
Miniboss_BoomDude_1:
# 1247 "data/maps/LittlerootTown/scripts.pory"
	msgbox Miniboss_BoomDude_Text_1
# 1248 "data/maps/LittlerootTown/scripts.pory"
	playse SE_M_BATON_PASS
# 1249 "data/maps/LittlerootTown/scripts.pory"
	waitse
# 1250 "data/maps/LittlerootTown/scripts.pory"
	removeobject LOCALID_GEODUDE
# 1251 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_BOOM_DUDES_GEODUDE
# 1252 "data/maps/LittlerootTown/scripts.pory"
	trainerbattle_single TRAINER_BRAWLY_5, Miniboss_Text_BoomDude_Intro, Miniboss_Text_BoomDude_Defeat, Miniboss_BoomDudeDefeated
# 1253 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 1254 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	return

Miniboss_BoomDude_2:
# 1244 "data/maps/LittlerootTown/scripts.pory"
	msgbox Miniboss_BoomDude_Text_0
# 1245 "data/maps/LittlerootTown/scripts.pory"
	goto End
	goto Miniboss_BoomDude_1


Miniboss_BoomDudeDefeated::
# 1258 "data/maps/LittlerootTown/scripts.pory"
	msgbox Miniboss_BoomDudeDefeated_Text_0
# 1259 "data/maps/LittlerootTown/scripts.pory"
	giveitem ITEM_ABILITY_PATCH
# 1260 "data/maps/LittlerootTown/scripts.pory"
	call_if_unset FLAG_DEFEATED_PETALBURG_GYM, Miniboss_BoomDudeBPReward
# 1261 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 1262 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	return


Miniboss_BoomDudeBPReward::
# 1266 "data/maps/LittlerootTown/scripts.pory"
	GiveBP 30
# 1267 "data/maps/LittlerootTown/scripts.pory"
	msgbox Miniboss_BoomDudeBPReward_Text_0
# 1268 "data/maps/LittlerootTown/scripts.pory"
	playse SE_ITEMFINDER
# 1269 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 1270 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	return


Miniboss_CritMaster::
# 1274 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 1275 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 1276 "data/maps/LittlerootTown/scripts.pory"
	msgbox Miniboss_CritMaster_Text_0
# 1277 "data/maps/LittlerootTown/scripts.pory"
	playse SE_M_BATON_PASS
# 1278 "data/maps/LittlerootTown/scripts.pory"
	waitse
# 1279 "data/maps/LittlerootTown/scripts.pory"
	removeobject LOCALID_SPRIGATITO
# 1280 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_CRITTERS_SPRIGATITO
# 1281 "data/maps/LittlerootTown/scripts.pory"
	trainerbattle_double TRAINER_WATTSON_2, Miniboss_Text_CritMaster_Intro, Miniboss_Text_CritMaster_Defeat, Miniboss_Text_ProtectorNeedTwoMons, Miniboss_CritMasterDefeated
# 1282 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 1283 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	return


Miniboss_CritMasterDefeated::
# 1287 "data/maps/LittlerootTown/scripts.pory"
	msgbox Miniboss_CritMasterDefeated_Text_0
# 1288 "data/maps/LittlerootTown/scripts.pory"
	giveitem ITEM_SCOPE_LENS
# 1289 "data/maps/LittlerootTown/scripts.pory"
	call_if_unset FLAG_DEFEATED_FORTREE_GYM, Miniboss_CritMasterBPReward
# 1290 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 1291 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	return


Miniboss_CritMasterBPReward::
# 1295 "data/maps/LittlerootTown/scripts.pory"
	GiveBP 30
# 1296 "data/maps/LittlerootTown/scripts.pory"
	msgbox Miniboss_CritMasterBPReward_Text_0
# 1297 "data/maps/LittlerootTown/scripts.pory"
	playse SE_ITEMFINDER
# 1298 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 1299 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	return


Miniboss_SlowFella::
# 1303 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 1304 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 1305 "data/maps/LittlerootTown/scripts.pory"
	checkpartytrickroom
# 1306 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Miniboss_SlowFella_2
Miniboss_SlowFella_1:
# 1310 "data/maps/LittlerootTown/scripts.pory"
	msgbox Miniboss_BoomDude_Text_1
# 1311 "data/maps/LittlerootTown/scripts.pory"
	playse SE_M_BATON_PASS
# 1312 "data/maps/LittlerootTown/scripts.pory"
	waitse
# 1313 "data/maps/LittlerootTown/scripts.pory"
	removeobject LOCALID_GRIMER
# 1314 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_SLOW_FELLAS_GRIMER
# 1315 "data/maps/LittlerootTown/scripts.pory"
	trainerbattle_single TRAINER_WATTSON_3, Miniboss_Text_SlowFella_Intro, Miniboss_Text_SlowFella_Defeat, Miniboss_SlowFellaDefeated
# 1316 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 1317 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	return

Miniboss_SlowFella_2:
# 1307 "data/maps/LittlerootTown/scripts.pory"
	msgbox Miniboss_SlowFella_Text_0
# 1308 "data/maps/LittlerootTown/scripts.pory"
	goto End
	goto Miniboss_SlowFella_1


Miniboss_SlowFellaDefeated::
# 1321 "data/maps/LittlerootTown/scripts.pory"
	msgbox Miniboss_SlowFellaDefeated_Text_0
# 1322 "data/maps/LittlerootTown/scripts.pory"
	giveitem ITEM_IRON_BALL
# 1323 "data/maps/LittlerootTown/scripts.pory"
	call_if_unset FLAG_DEFEATED_MOSSDEEP_GYM, Miniboss_SlowFellaBPReward
# 1324 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 1325 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	return


Miniboss_SlowFellaBPReward::
# 1329 "data/maps/LittlerootTown/scripts.pory"
	GiveBP 40
# 1330 "data/maps/LittlerootTown/scripts.pory"
	msgbox Miniboss_SlowFellaBPReward_Text_0
# 1331 "data/maps/LittlerootTown/scripts.pory"
	playse SE_ITEMFINDER
# 1332 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 1333 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	return


Miniboss_Smasher::
# 1337 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 1338 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 1339 "data/maps/LittlerootTown/scripts.pory"
	playse SE_M_BATON_PASS
# 1340 "data/maps/LittlerootTown/scripts.pory"
	waitse
# 1341 "data/maps/LittlerootTown/scripts.pory"
	removeobject LOCALID_TURTWIG
# 1342 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_SMASHERS_TURTWIG
# 1343 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_DEFEATED_SMASHER, EventScript_ShellSmashTutor
# 1344 "data/maps/LittlerootTown/scripts.pory"
	msgbox Miniboss_Smasher_Text_0
# 1345 "data/maps/LittlerootTown/scripts.pory"
	trainerbattle_single TRAINER_WATTSON_4, Miniboss_Text_Smasher_Intro, Miniboss_Text_Smasher_Defeat, Miniboss_SmasherDefeated
# 1346 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 1347 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	return


Miniboss_SmasherDefeated::
# 1351 "data/maps/LittlerootTown/scripts.pory"
	msgbox Miniboss_SmasherDefeated_Text_0
# 1352 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_DEFEATED_SMASHER
# 1353 "data/maps/LittlerootTown/scripts.pory"
	call_if_unset FLAG_DEFEATED_SOOTOPOLIS_GYM, Miniboss_SmasherBPReward
# 1354 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 1355 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	return


Miniboss_SmasherBPReward::
# 1359 "data/maps/LittlerootTown/scripts.pory"
	GiveBP 45
# 1360 "data/maps/LittlerootTown/scripts.pory"
	msgbox Miniboss_SmasherBPReward_Text_0
# 1361 "data/maps/LittlerootTown/scripts.pory"
	playse SE_ITEMFINDER
# 1362 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 1363 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	return


Miniboss_Purkat::
# 1367 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 1368 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 1369 "data/maps/LittlerootTown/scripts.pory"
	playse SE_M_BATON_PASS
# 1370 "data/maps/LittlerootTown/scripts.pory"
	waitse
# 1371 "data/maps/LittlerootTown/scripts.pory"
	removeobject LOCALID_HONEDGE
# 1372 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_PURKATS_HONEDGE
# 1373 "data/maps/LittlerootTown/scripts.pory"
	msgbox Miniboss_Purkat_Text_0
# 1374 "data/maps/LittlerootTown/scripts.pory"
	trainerbattle_single TRAINER_WATTSON_5, Miniboss_Text_Purkat_Intro, Miniboss_Text_Purkat_Defeat, Miniboss_PurkatDefeated
# 1375 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 1376 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	return


Miniboss_PurkatDefeated::
# 1380 "data/maps/LittlerootTown/scripts.pory"
	msgbox Miniboss_PurkatDefeated_Text_0
# 1381 "data/maps/LittlerootTown/scripts.pory"
	giveitem ITEM_BLANK_MINT, 5
# 1382 "data/maps/LittlerootTown/scripts.pory"
	giveitem ITEM_RARE_CANDY, 5
# 1383 "data/maps/LittlerootTown/scripts.pory"
	call_if_unset FLAG_DEFEATED_ELITE_4_SIDNEY, Miniboss_PurkatBPReward
# 1384 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 1385 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	return


Miniboss_PurkatBPReward::
# 1389 "data/maps/LittlerootTown/scripts.pory"
	GiveBP 50
# 1390 "data/maps/LittlerootTown/scripts.pory"
	msgbox Miniboss_PurkatBPReward_Text_0
# 1391 "data/maps/LittlerootTown/scripts.pory"
	playse SE_ITEMFINDER
# 1392 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 1393 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	return


Miniboss_ScaryGuy_Text_0:
# 1089 "data/maps/LittlerootTown/scripts.pory"
	.string "The best way to defeat your enemy is to\n"
	.string "scare them, so I only use Pokémon with\l"
	.string "Intimidate!$"

Miniboss_ScaryGuyDefeated_Text_0:
# 1100 "data/maps/LittlerootTown/scripts.pory"
	.string "Here's an Ability Capsule for defeating\n"
	.string "me. In case your Growlithe has Flash\l"
	.string "Fire, yknow?$"

Miniboss_ScaryGuyBPReward_Text_0:
# 1109 "data/maps/LittlerootTown/scripts.pory"
	.string "And here's 15 Battle Points for\n"
	.string "defeating me before Roxanne. Spend\l"
	.string "them wisely.$"

Miniboss_Protector_Text_0:
# 1118 "data/maps/LittlerootTown/scripts.pory"
	.string "I hate when my Pokémon take too much\n"
	.string "damage, so I'll do whatever I can to\l"
	.string "reduce it!$"

Miniboss_ProtectorDefeated_Text_0:
# 1129 "data/maps/LittlerootTown/scripts.pory"
	.string "Here's an Eviolite for defeating me.\n"
	.string "It'll increase your Pokémon's defenses.$"

Miniboss_ProtectorBPReward_Text_0:
# 1138 "data/maps/LittlerootTown/scripts.pory"
	.string "And here's 15 Battle Points for\n"
	.string "defeating me before Brawly. Spend them\l"
	.string "wisely.$"

Miniboss_SpeedyChap_Text_0:
# 1147 "data/maps/LittlerootTown/scripts.pory"
	.string "Hahaha! I'm so fast! You can't catch me!$"

Miniboss_SpeedyChapDefeated_Text_0:
# 1158 "data/maps/LittlerootTown/scripts.pory"
	.string "Here's a Salac Berry for defeating me.\n"
	.string "It'll raise Speed in a pinch.$"

Miniboss_SpeedyChapBPReward_Text_0:
# 1167 "data/maps/LittlerootTown/scripts.pory"
	.string "And here's 25 Battle Points for\n"
	.string "defeating me before Wattson. Spend\l"
	.string "them wisely.$"

Miniboss_Collector_Text_0:
# 1176 "data/maps/LittlerootTown/scripts.pory"
	.string "I like collecting Pokémon with forms. Do\n"
	.string "you have any? Let me see!$"

Miniboss_CollectorDefeated_Text_0:
# 1187 "data/maps/LittlerootTown/scripts.pory"
	.string "Here's a Special Froakie for defeating\n"
	.string "me. It has a very unique ability. So\l"
	.string "cool!$"

Miniboss_CollectorDefeated_Text_1:
# 1192 "data/maps/LittlerootTown/scripts.pory"
	.string "Obtained a special Froakie.$"

Miniboss_CollectorDefeated_Text_2:
# 1203 "data/maps/LittlerootTown/scripts.pory"
	.string "You don't have any room in your boxes\n"
	.string "for a new Pokémon. Come back with some\l"
	.string "extra room.$"

Miniboss_CollectorBPReward_Text_0:
# 1233 "data/maps/LittlerootTown/scripts.pory"
	.string "And here's 25 Battle Points for\n"
	.string "defeating me before Flannery. Spend\l"
	.string "them wisely.$"

Miniboss_BoomDude_Text_0:
# 1244 "data/maps/LittlerootTown/scripts.pory"
	.string "Oho ho, tryna pull one over on me huh? I\n"
	.string "won't battle you if you have a Pokémon\l"
	.string "with the ability Damp.$"

Miniboss_BoomDude_Text_1:
# 1247 "data/maps/LittlerootTown/scripts.pory"
	.string "...................................................$"

Miniboss_BoomDudeDefeated_Text_0:
# 1258 "data/maps/LittlerootTown/scripts.pory"
	.string "Here's an Ability Patch for defeating\n"
	.string "me. Maybe use it to get Damp or\l"
	.string "something. Always be aware of\l"
	.string "explosions.$"

Miniboss_BoomDudeBPReward_Text_0:
# 1267 "data/maps/LittlerootTown/scripts.pory"
	.string "And here's 30 Battle Points for\n"
	.string "defeating me before Norman. Spend them\l"
	.string "wisely.$"

Miniboss_CritMaster_Text_0:
# 1276 "data/maps/LittlerootTown/scripts.pory"
	.string "I have cheated the system. I have a\n"
	.string "guaranteed chance to crit every time.\l"
	.string "There's no way your Pokémon can\l"
	.string "withstand me!$"

Miniboss_CritMasterDefeated_Text_0:
# 1287 "data/maps/LittlerootTown/scripts.pory"
	.string "Here's a Scope Lens for defeating me.\n"
	.string "Now you're one step closer to the\l"
	.string "guaranteed crit...$"

Miniboss_CritMasterBPReward_Text_0:
# 1296 "data/maps/LittlerootTown/scripts.pory"
	.string "And here's 30 Battle Points for\n"
	.string "defeating me before Winona. Spend them\l"
	.string "wisely.$"

Miniboss_SlowFella_Text_0:
# 1307 "data/maps/LittlerootTown/scripts.pory"
	.string "...................................................no trick\n"
	.string "room$"

Miniboss_SlowFellaDefeated_Text_0:
# 1321 "data/maps/LittlerootTown/scripts.pory"
	.string "Oh, didn't see you there. Well, here's an\n"
	.string "Iron Ball for defeating me, I guess. No\l"
	.string "need to speed through life.$"

Miniboss_SlowFellaBPReward_Text_0:
# 1330 "data/maps/LittlerootTown/scripts.pory"
	.string "And here's 40 Battle Points for\n"
	.string "defeating me before Tate & Liza. Spend\l"
	.string "them wisely or whatever.$"

Miniboss_Smasher_Text_0:
# 1344 "data/maps/LittlerootTown/scripts.pory"
	.string "Check out this sick move I just found!$"

Miniboss_SmasherDefeated_Text_0:
# 1351 "data/maps/LittlerootTown/scripts.pory"
	.string "For defeating me, I will teach the move\n"
	.string "Shell Smash to any of your Pokémon for\l"
	.string "me. It's a really cool move, check it out!$"

Miniboss_SmasherBPReward_Text_0:
# 1360 "data/maps/LittlerootTown/scripts.pory"
	.string "And here's 45 Battle Points for\n"
	.string "defeating me before Juan. Spend them\l"
	.string "wisely.$"

Miniboss_Purkat_Text_0:
# 1373 "data/maps/LittlerootTown/scripts.pory"
	.string "Hey! I hope you're enjoying my hack!\n"
	.string "Prepare to die!$"

Miniboss_PurkatDefeated_Text_0:
# 1380 "data/maps/LittlerootTown/scripts.pory"
	.string "Here's some Blank Nature Mints and Rare\n"
	.string "Candies for defeating me.$"

Miniboss_PurkatBPReward_Text_0:
# 1390 "data/maps/LittlerootTown/scripts.pory"
	.string "And here's 50 Battle Points for\n"
	.string "defeating me before the taking on the\l"
	.string "Pokémon League. Spend them wisely.$"
