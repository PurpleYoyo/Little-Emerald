# 1 "data/maps/Route120/scripts.pory"

# 2 "data/maps/Route120/scripts.pory"
.set LOCALID_BRIDGE_KECLEON, 30
# 3 "data/maps/Route120/scripts.pory"
.set LOCALID_STEVEN, 31
# 4 "data/maps/Route120/scripts.pory"
.set LOCALID_BRIDGE_KECLEON_SHADOW, 36  @ They use a second object which is identical to Kecleon but has a reflection palette tag for the bridge shadow
# 5 "data/maps/Route120/scripts.pory"

# 6 "data/maps/Route120/scripts.pory"
Route120_MapScripts::
# 7 "data/maps/Route120/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Route120_OnResume
# 8 "data/maps/Route120/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route120_OnTransition
# 9 "data/maps/Route120/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route120_OnLoad
# 10 "data/maps/Route120/scripts.pory"
	.byte 0
# 11 "data/maps/Route120/scripts.pory"

# 12 "data/maps/Route120/scripts.pory"
Route120_OnResume:
# 13 "data/maps/Route120/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route120_EventScript_RemoveKecleonObject
# 14 "data/maps/Route120/scripts.pory"
	end
# 15 "data/maps/Route120/scripts.pory"

# 16 "data/maps/Route120/scripts.pory"
Route120_EventScript_RemoveKecleonObject::
# 17 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_0x8009, 0, Route120_EventScript_RemoveBridgeKecleon
# 18 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_0x8009, 1, Route120_EventScript_RemoveKecleon
# 19 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_0x8009, 2, Route120_EventScript_RemoveKecleon
# 20 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_0x8009, 3, Route120_EventScript_RemoveKecleon
# 21 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_0x8009, 4, Route120_EventScript_RemoveKecleon
# 22 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_0x8009, 5, Route120_EventScript_RemoveKecleon
# 23 "data/maps/Route120/scripts.pory"
	return
# 24 "data/maps/Route120/scripts.pory"

# 25 "data/maps/Route120/scripts.pory"
Route120_EventScript_RemoveBridgeKecleon::
# 26 "data/maps/Route120/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 27 "data/maps/Route120/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 28 "data/maps/Route120/scripts.pory"
	removeobject LOCALID_BRIDGE_KECLEON
# 29 "data/maps/Route120/scripts.pory"
	removeobject LOCALID_BRIDGE_KECLEON_SHADOW
# 30 "data/maps/Route120/scripts.pory"
	return
# 31 "data/maps/Route120/scripts.pory"

# 32 "data/maps/Route120/scripts.pory"
Route120_EventScript_RemoveKecleon::
# 33 "data/maps/Route120/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 34 "data/maps/Route120/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 35 "data/maps/Route120/scripts.pory"
	removeobject VAR_LAST_TALKED
# 36 "data/maps/Route120/scripts.pory"
	return
# 37 "data/maps/Route120/scripts.pory"

# 38 "data/maps/Route120/scripts.pory"
Route120_OnLoad:
# 39 "data/maps/Route120/scripts.pory"
	call_if_set FLAG_RECEIVED_DEVON_SCOPE, Route120_EventScript_SetBridgeClearMetatiles
# 40 "data/maps/Route120/scripts.pory"
	call_if_unset FLAG_RECEIVED_DEVON_SCOPE, Route120_EventScript_SetBridgeKecleonMovement
# 41 "data/maps/Route120/scripts.pory"
	end
# 42 "data/maps/Route120/scripts.pory"

# 43 "data/maps/Route120/scripts.pory"
Route120_EventScript_CloseAncientTomb::
# 44 "data/maps/Route120/scripts.pory"
	setmetatile 7, 54, METATILE_General_RockWall_RockBase, TRUE
# 45 "data/maps/Route120/scripts.pory"
	setmetatile 7, 55, METATILE_General_RockWall_SandBase, TRUE
# 46 "data/maps/Route120/scripts.pory"
	return
# 47 "data/maps/Route120/scripts.pory"

# 48 "data/maps/Route120/scripts.pory"
Route120_EventScript_SetBridgeClearMetatiles::
# 49 "data/maps/Route120/scripts.pory"
	setmetatile 13, 15, METATILE_Fortree_WoodBridge1_Top, FALSE
# 50 "data/maps/Route120/scripts.pory"
	setmetatile 12, 16, METATILE_Fortree_WoodBridge1_Bottom, FALSE
# 51 "data/maps/Route120/scripts.pory"
	setmetatile 12, 17, METATILE_General_ReflectiveWater, FALSE
# 52 "data/maps/Route120/scripts.pory"
	setmetatile 13, 17, METATILE_General_ReflectiveWater, FALSE
# 53 "data/maps/Route120/scripts.pory"
	return
# 54 "data/maps/Route120/scripts.pory"

# 55 "data/maps/Route120/scripts.pory"
Route120_EventScript_SetBridgeKecleonMovement::
# 56 "data/maps/Route120/scripts.pory"
	setobjectmovementtype LOCALID_BRIDGE_KECLEON_SHADOW, MOVEMENT_TYPE_FACE_RIGHT
# 57 "data/maps/Route120/scripts.pory"
	return
# 58 "data/maps/Route120/scripts.pory"

# 59 "data/maps/Route120/scripts.pory"
Route120_OnTransition:
# 60 "data/maps/Route120/scripts.pory"
	call GabbyAndTy_EventScript_UpdateLocation
# 61 "data/maps/Route120/scripts.pory"
	call Route120_EventScript_SetWeather
# 62 "data/maps/Route120/scripts.pory"
	end
# 63 "data/maps/Route120/scripts.pory"

# 64 "data/maps/Route120/scripts.pory"
Route120_EventScript_SetWeather::
# 65 "data/maps/Route120/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 66 "data/maps/Route120/scripts.pory"
	goto_if_le VAR_TEMP_1, 14, Route120_EventScript_SetSunnyWeather
# 67 "data/maps/Route120/scripts.pory"
	goto_if_le VAR_TEMP_1, 60, Route120_EventScript_TrySetRainyWeather
# 68 "data/maps/Route120/scripts.pory"
	goto_if_ge VAR_TEMP_1, 61, Route120_EventScript_SetCloudyWeather
# 69 "data/maps/Route120/scripts.pory"
	return
# 70 "data/maps/Route120/scripts.pory"

# 71 "data/maps/Route120/scripts.pory"
Route120_EventScript_SetCloudyWeather::
# 72 "data/maps/Route120/scripts.pory"
	setweather WEATHER_SUNNY_CLOUDS
# 73 "data/maps/Route120/scripts.pory"
	return
# 74 "data/maps/Route120/scripts.pory"

# 75 "data/maps/Route120/scripts.pory"
Route120_EventScript_SetSunnyWeather::
# 76 "data/maps/Route120/scripts.pory"
	setweather WEATHER_SUNNY
# 77 "data/maps/Route120/scripts.pory"
	return
# 78 "data/maps/Route120/scripts.pory"

# 79 "data/maps/Route120/scripts.pory"
Route120_EventScript_TrySetRainyWeather::
# 80 "data/maps/Route120/scripts.pory"
	goto_if_le VAR_TEMP_0, 7, Route120_EventScript_SetRainyWeather
# 81 "data/maps/Route120/scripts.pory"
	goto_if_le VAR_TEMP_0, 19, Route120_EventScript_SetSunnyWeather
# 82 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_SetRainyWeather
# 83 "data/maps/Route120/scripts.pory"
	end
# 84 "data/maps/Route120/scripts.pory"

# 85 "data/maps/Route120/scripts.pory"
Route120_EventScript_SetRainyWeather::
# 86 "data/maps/Route120/scripts.pory"
	setweather WEATHER_RAIN
# 87 "data/maps/Route120/scripts.pory"
	return
# 88 "data/maps/Route120/scripts.pory"

# 89 "data/maps/Route120/scripts.pory"
Route120_EventScript_BerryBeauty::
# 90 "data/maps/Route120/scripts.pory"
	lock
# 91 "data/maps/Route120/scripts.pory"
	faceplayer
# 92 "data/maps/Route120/scripts.pory"
	dotimebasedevents
# 93 "data/maps/Route120/scripts.pory"
	goto_if_set FLAG_DAILY_ROUTE_120_RECEIVED_BERRY, Route120_EventScript_ReceivedBerry
# 94 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_BerriesExpressionOfLoveIsntIt, MSGBOX_YESNO
# 95 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_RESULT, YES, Route120_EventScript_BerryLove
# 96 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_RESULT, NO, Route120_EventScript_BerryNotLove
# 97 "data/maps/Route120/scripts.pory"
	specialvar VAR_RESULT, GetPlayerTrainerIdOnesDigit
# 98 "data/maps/Route120/scripts.pory"
	switch VAR_RESULT
# 99 "data/maps/Route120/scripts.pory"
	case 0, Route120_EventScript_GiveFigyBerry
# 100 "data/maps/Route120/scripts.pory"
	case 5, Route120_EventScript_GiveFigyBerry
# 101 "data/maps/Route120/scripts.pory"
	case 1, Route120_EventScript_GiveWikiBerry
# 102 "data/maps/Route120/scripts.pory"
	case 6, Route120_EventScript_GiveWikiBerry
# 103 "data/maps/Route120/scripts.pory"
	case 2, Route120_EventScript_GiveMagoBerry
# 104 "data/maps/Route120/scripts.pory"
	case 7, Route120_EventScript_GiveMagoBerry
# 105 "data/maps/Route120/scripts.pory"
	case 3, Route120_EventScript_GiveAguavBerry
# 106 "data/maps/Route120/scripts.pory"
	case 8, Route120_EventScript_GiveAguavBerry
# 107 "data/maps/Route120/scripts.pory"
	case 4, Route120_EventScript_GiveIapapaBerry
# 108 "data/maps/Route120/scripts.pory"
	case 9, Route120_EventScript_GiveIapapaBerry
# 109 "data/maps/Route120/scripts.pory"
	end
# 110 "data/maps/Route120/scripts.pory"

# 111 "data/maps/Route120/scripts.pory"
Route120_EventScript_GiveFigyBerry::
# 112 "data/maps/Route120/scripts.pory"
	setvar VAR_0x8004, ITEM_FIGY_BERRY
# 113 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_GiveBerry
# 114 "data/maps/Route120/scripts.pory"
	end
# 115 "data/maps/Route120/scripts.pory"

# 116 "data/maps/Route120/scripts.pory"
Route120_EventScript_GiveWikiBerry::
# 117 "data/maps/Route120/scripts.pory"
	setvar VAR_0x8004, ITEM_WIKI_BERRY
# 118 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_GiveBerry
# 119 "data/maps/Route120/scripts.pory"
	end
# 120 "data/maps/Route120/scripts.pory"

# 121 "data/maps/Route120/scripts.pory"
Route120_EventScript_GiveMagoBerry::
# 122 "data/maps/Route120/scripts.pory"
	setvar VAR_0x8004, ITEM_MAGO_BERRY
# 123 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_GiveBerry
# 124 "data/maps/Route120/scripts.pory"
	end
# 125 "data/maps/Route120/scripts.pory"

# 126 "data/maps/Route120/scripts.pory"
Route120_EventScript_GiveAguavBerry::
# 127 "data/maps/Route120/scripts.pory"
	setvar VAR_0x8004, ITEM_AGUAV_BERRY
# 128 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_GiveBerry
# 129 "data/maps/Route120/scripts.pory"
	end
# 130 "data/maps/Route120/scripts.pory"

# 131 "data/maps/Route120/scripts.pory"
Route120_EventScript_GiveIapapaBerry::
# 132 "data/maps/Route120/scripts.pory"
	setvar VAR_0x8004, ITEM_IAPAPA_BERRY
# 133 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_GiveBerry
# 134 "data/maps/Route120/scripts.pory"
	end
# 135 "data/maps/Route120/scripts.pory"

# 136 "data/maps/Route120/scripts.pory"
Route120_EventScript_GiveBerry::
# 137 "data/maps/Route120/scripts.pory"
	giveitem VAR_0x8004
# 138 "data/maps/Route120/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 139 "data/maps/Route120/scripts.pory"
	setflag FLAG_DAILY_ROUTE_120_RECEIVED_BERRY
# 140 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_BerryIsRareRaiseItWithCare, MSGBOX_DEFAULT
# 141 "data/maps/Route120/scripts.pory"
	release
# 142 "data/maps/Route120/scripts.pory"
	end
# 143 "data/maps/Route120/scripts.pory"

# 144 "data/maps/Route120/scripts.pory"
Route120_EventScript_ReceivedBerry::
# 145 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_IllGetMoreBerriesFromBerryMaster, MSGBOX_DEFAULT
# 146 "data/maps/Route120/scripts.pory"
	release
# 147 "data/maps/Route120/scripts.pory"
	end
# 148 "data/maps/Route120/scripts.pory"

# 149 "data/maps/Route120/scripts.pory"
Route120_EventScript_BerryLove::
# 150 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_YesYouUnderstand, MSGBOX_DEFAULT
# 151 "data/maps/Route120/scripts.pory"
	return
# 152 "data/maps/Route120/scripts.pory"

# 153 "data/maps/Route120/scripts.pory"
Route120_EventScript_BerryNotLove::
# 154 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_MakeYourOwnImpressions, MSGBOX_DEFAULT
# 155 "data/maps/Route120/scripts.pory"
	return
# 156 "data/maps/Route120/scripts.pory"

# 157 "data/maps/Route120/scripts.pory"
Route120_EventScript_Steven::
# 158 "data/maps/Route120/scripts.pory"
	lock
# 159 "data/maps/Route120/scripts.pory"
	faceplayer
# 160 "data/maps/Route120/scripts.pory"
	goto_if_set FLAG_NOT_READY_FOR_BATTLE_ROUTE_120, Route120_EventScript_StevenAskReadyForBattle
# 161 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenGreeting, MSGBOX_YESNO
# 162 "data/maps/Route120/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route120_EventScript_StevenNotReady
# 163 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_StevenBattleKecleon
# 164 "data/maps/Route120/scripts.pory"
	end
# 165 "data/maps/Route120/scripts.pory"

# 166 "data/maps/Route120/scripts.pory"
Route120_EventScript_StevenNotReady::
# 167 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenIllWaitHere, MSGBOX_DEFAULT
# 168 "data/maps/Route120/scripts.pory"
	setflag FLAG_NOT_READY_FOR_BATTLE_ROUTE_120
# 169 "data/maps/Route120/scripts.pory"
	release
# 170 "data/maps/Route120/scripts.pory"
	end
# 171 "data/maps/Route120/scripts.pory"

# 172 "data/maps/Route120/scripts.pory"
Route120_EventScript_StevenAskReadyForBattle::
# 173 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenReadyForBattle, MSGBOX_YESNO
# 174 "data/maps/Route120/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route120_EventScript_StevenNotReady
# 175 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_StevenBattleKecleon
# 176 "data/maps/Route120/scripts.pory"
	end
# 177 "data/maps/Route120/scripts.pory"

# 178 "data/maps/Route120/scripts.pory"
Route120_EventScript_StevenBattleKecleon::
# 179 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenShowMeYourPower, MSGBOX_DEFAULT
# 180 "data/maps/Route120/scripts.pory"
	closemessage
# 181 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, Route120_EventScript_PlayerApproachKecleonNorth
# 182 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, Route120_EventScript_PlayerApproachKecleonWest
# 183 "data/maps/Route120/scripts.pory"
	applymovement LOCALID_STEVEN, Common_Movement_WalkInPlaceFasterLeft
# 184 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 185 "data/maps/Route120/scripts.pory"
	delay 20
# 186 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenUsedDevonScope, MSGBOX_DEFAULT
# 187 "data/maps/Route120/scripts.pory"
	closemessage
# 188 "data/maps/Route120/scripts.pory"
	applymovement LOCALID_BRIDGE_KECLEON, Common_Movement_WalkInPlaceFasterRight
# 189 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 190 "data/maps/Route120/scripts.pory"
	applymovement LOCALID_BRIDGE_KECLEON, Movement_KecleonAppears
# 191 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 192 "data/maps/Route120/scripts.pory"
	waitse
# 193 "data/maps/Route120/scripts.pory"
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
# 194 "data/maps/Route120/scripts.pory"
	delay 40
# 195 "data/maps/Route120/scripts.pory"
	waitmoncry
# 196 "data/maps/Route120/scripts.pory"
	setwildbattle SPECIES_KECLEON, 30
# 197 "data/maps/Route120/scripts.pory"
	setvar VAR_0x8009, 0
# 198 "data/maps/Route120/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 199 "data/maps/Route120/scripts.pory"
	dowildbattle
# 200 "data/maps/Route120/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 201 "data/maps/Route120/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 202 "data/maps/Route120/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route120_EventScript_RemoveBridgeKecleonPostBattle
# 203 "data/maps/Route120/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route120_EventScript_RemoveBridgeKecleonPostBattle
# 204 "data/maps/Route120/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route120_EventScript_RemoveBridgeKecleonPostBattle
# 205 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_StevenGiveDeconScope
# 206 "data/maps/Route120/scripts.pory"
	end
# 207 "data/maps/Route120/scripts.pory"

# 208 "data/maps/Route120/scripts.pory"
Route120_EventScript_RemoveBridgeKecleonPostBattle::
# 209 "data/maps/Route120/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 210 "data/maps/Route120/scripts.pory"
	removeobject LOCALID_BRIDGE_KECLEON
# 211 "data/maps/Route120/scripts.pory"
	removeobject LOCALID_BRIDGE_KECLEON_SHADOW
# 212 "data/maps/Route120/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 213 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_StevenGiveDeconScope
# 214 "data/maps/Route120/scripts.pory"
	end
# 215 "data/maps/Route120/scripts.pory"

# 216 "data/maps/Route120/scripts.pory"
Route120_EventScript_StevenGiveDeconScope::
# 217 "data/maps/Route120/scripts.pory"
	applymovement LOCALID_STEVEN, Common_Movement_WalkInPlaceFasterDown
# 218 "data/maps/Route120/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 219 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 220 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenGiveDevonScope, MSGBOX_DEFAULT
# 221 "data/maps/Route120/scripts.pory"
	giveitem ITEM_DEVON_SCOPE
# 222 "data/maps/Route120/scripts.pory"
	setflag FLAG_RECEIVED_DEVON_SCOPE
# 223 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenGoodbye, MSGBOX_DEFAULT
# 224 "data/maps/Route120/scripts.pory"
	closemessage
# 225 "data/maps/Route120/scripts.pory"
	applymovement LOCALID_STEVEN, Common_Movement_WalkInPlaceFasterDown
# 226 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 227 "data/maps/Route120/scripts.pory"
	delay 50
# 228 "data/maps/Route120/scripts.pory"
	setfieldeffectargument 0, 1
# 229 "data/maps/Route120/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 230 "data/maps/Route120/scripts.pory"
	delay 15
# 231 "data/maps/Route120/scripts.pory"
	removeobject LOCALID_STEVEN
# 232 "data/maps/Route120/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 233 "data/maps/Route120/scripts.pory"
	setmetatile 13, 15, METATILE_Fortree_WoodBridge1_Top, FALSE
# 234 "data/maps/Route120/scripts.pory"
	setmetatile 12, 16, METATILE_Fortree_WoodBridge1_Bottom, FALSE
# 235 "data/maps/Route120/scripts.pory"
	setmetatile 12, 17, METATILE_General_ReflectiveWater, FALSE
# 236 "data/maps/Route120/scripts.pory"
	setmetatile 13, 17, METATILE_General_ReflectiveWater, FALSE
# 237 "data/maps/Route120/scripts.pory"
	special DrawWholeMapView
# 238 "data/maps/Route120/scripts.pory"
	release
# 239 "data/maps/Route120/scripts.pory"
	end
# 240 "data/maps/Route120/scripts.pory"

# 241 "data/maps/Route120/scripts.pory"
Route120_EventScript_PlayerApproachKecleonNorth::
# 242 "data/maps/Route120/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 243 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 244 "data/maps/Route120/scripts.pory"
	return
# 245 "data/maps/Route120/scripts.pory"

# 246 "data/maps/Route120/scripts.pory"
Route120_EventScript_PlayerApproachKecleonWest::
# 247 "data/maps/Route120/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route120_Movement_ApproachKecleonWest
# 248 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 249 "data/maps/Route120/scripts.pory"
	return
# 250 "data/maps/Route120/scripts.pory"

# 251 "data/maps/Route120/scripts.pory"
Route120_Movement_ApproachKecleonWest:
# 252 "data/maps/Route120/scripts.pory"
	walk_down
# 253 "data/maps/Route120/scripts.pory"
	walk_left
# 254 "data/maps/Route120/scripts.pory"
	step_end
# 255 "data/maps/Route120/scripts.pory"

# 256 "data/maps/Route120/scripts.pory"
Route120_EventScript_BridgeKecleon::
# 257 "data/maps/Route120/scripts.pory"
	msgbox Kecleon_Text_SomethingUnseeable, MSGBOX_NPC
# 258 "data/maps/Route120/scripts.pory"
	end
# 259 "data/maps/Route120/scripts.pory"

# 260 "data/maps/Route120/scripts.pory"
Route120_EventScript_RouteSignFortree::
# 261 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_RouteSignFortree, MSGBOX_SIGN
# 262 "data/maps/Route120/scripts.pory"
	end
# 263 "data/maps/Route120/scripts.pory"

# 264 "data/maps/Route120/scripts.pory"
Route120_EventScript_RouteSign121::
# 265 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_RouteSign121, MSGBOX_SIGN
# 266 "data/maps/Route120/scripts.pory"
	end
# 267 "data/maps/Route120/scripts.pory"

# 268 "data/maps/Route120/scripts.pory"
Route120_EventScript_Colin::
# 269 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_COLIN, Route120_Text_ColinIntro, Route120_Text_ColinDefeat
# 270 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_ColinPostBattle, MSGBOX_AUTOCLOSE
# 271 "data/maps/Route120/scripts.pory"
	end
# 272 "data/maps/Route120/scripts.pory"

# 273 "data/maps/Route120/scripts.pory"
Route120_EventScript_Robert::
# 274 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_ROBERT_1, Route120_Text_RobertIntro, Route120_Text_RobertDefeat, Route120_EventScript_RegisterRobert
# 275 "data/maps/Route120/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 276 "data/maps/Route120/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route120_EventScript_RematchRobert
# 277 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_RobertPostBattle, MSGBOX_DEFAULT
# 278 "data/maps/Route120/scripts.pory"
	release
# 279 "data/maps/Route120/scripts.pory"
	end
# 280 "data/maps/Route120/scripts.pory"

# 281 "data/maps/Route120/scripts.pory"
Route120_EventScript_RegisterRobert::
# 282 "data/maps/Route120/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 283 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 284 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_RobertRegister, MSGBOX_DEFAULT
# 285 "data/maps/Route120/scripts.pory"
	register_matchcall TRAINER_ROBERT_1
# 286 "data/maps/Route120/scripts.pory"
	release
# 287 "data/maps/Route120/scripts.pory"
	end
# 288 "data/maps/Route120/scripts.pory"

# 289 "data/maps/Route120/scripts.pory"
Route120_EventScript_RematchRobert::
# 290 "data/maps/Route120/scripts.pory"
	trainerbattle_rematch TRAINER_ROBERT_1, Route120_Text_RobertRematchIntro, Route120_Text_RobertRematchDefeat
# 291 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_RobertPostRematch, MSGBOX_AUTOCLOSE
# 292 "data/maps/Route120/scripts.pory"
	end
# 293 "data/maps/Route120/scripts.pory"

# 294 "data/maps/Route120/scripts.pory"
Route120_EventScript_Lorenzo::
# 295 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_LORENZO, Route120_Text_LorenzoIntro, Route120_Text_LorenzoDefeat
# 296 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_LorenzoPostBattle, MSGBOX_AUTOCLOSE
# 297 "data/maps/Route120/scripts.pory"
	end
# 298 "data/maps/Route120/scripts.pory"

# 299 "data/maps/Route120/scripts.pory"
Route120_EventScript_Jenna::
# 300 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_JENNA, Route120_Text_JennaIntro, Route120_Text_JennaDefeat
# 301 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_JennaPostBattle, MSGBOX_AUTOCLOSE
# 302 "data/maps/Route120/scripts.pory"
	end
# 303 "data/maps/Route120/scripts.pory"

# 304 "data/maps/Route120/scripts.pory"
Route120_EventScript_Jeffrey::
# 305 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_JEFFREY_1, Route120_Text_JeffreyIntro, Route120_Text_JeffreyDefeat, Route120_EventScript_RegisterJeffrey
# 306 "data/maps/Route120/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 307 "data/maps/Route120/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route120_EventScript_RematchJeffrey
# 308 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_JeffreyPostBattle, MSGBOX_DEFAULT
# 309 "data/maps/Route120/scripts.pory"
	release
# 310 "data/maps/Route120/scripts.pory"
	end
# 311 "data/maps/Route120/scripts.pory"

# 312 "data/maps/Route120/scripts.pory"
Route120_EventScript_RegisterJeffrey::
# 313 "data/maps/Route120/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 314 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 315 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_JeffreyRegister, MSGBOX_DEFAULT
# 316 "data/maps/Route120/scripts.pory"
	register_matchcall TRAINER_JEFFREY_1
# 317 "data/maps/Route120/scripts.pory"
	release
# 318 "data/maps/Route120/scripts.pory"
	end
# 319 "data/maps/Route120/scripts.pory"

# 320 "data/maps/Route120/scripts.pory"
Route120_EventScript_RematchJeffrey::
# 321 "data/maps/Route120/scripts.pory"
	trainerbattle_rematch TRAINER_JEFFREY_1, Route120_Text_JeffreyRematchIntro, Route120_Text_JeffreyRematchDefeat
# 322 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_JeffreyPostRematch, MSGBOX_AUTOCLOSE
# 323 "data/maps/Route120/scripts.pory"
	end
# 324 "data/maps/Route120/scripts.pory"

# 325 "data/maps/Route120/scripts.pory"
Route120_EventScript_Jennifer::
# 326 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_JENNIFER, Route120_Text_JenniferIntro, Route120_Text_JenniferDefeat
# 327 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_JenniferPostBattle, MSGBOX_AUTOCLOSE
# 328 "data/maps/Route120/scripts.pory"
	end
# 329 "data/maps/Route120/scripts.pory"

# 330 "data/maps/Route120/scripts.pory"
Route120_EventScript_Chip::
# 331 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_CHIP, Route120_Text_ChipIntro, Route120_Text_ChipDefeat
# 332 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_ChipPostBattle, MSGBOX_AUTOCLOSE
# 333 "data/maps/Route120/scripts.pory"
	end
# 334 "data/maps/Route120/scripts.pory"

# 335 "data/maps/Route120/scripts.pory"
Route120_EventScript_Clarissa::
# 336 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_CLARISSA, Route120_Text_ClarissaIntro, Route120_Text_ClarissaDefeat
# 337 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_ClarissaPostBattle, MSGBOX_AUTOCLOSE
# 338 "data/maps/Route120/scripts.pory"
	end
# 339 "data/maps/Route120/scripts.pory"

# 340 "data/maps/Route120/scripts.pory"
Route120_EventScript_Angelica::
# 341 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_ANGELICA, Route120_Text_AngelicaIntro, Route120_Text_AngelicaDefeat
# 342 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_AngelicaPostBattle, MSGBOX_AUTOCLOSE
# 343 "data/maps/Route120/scripts.pory"
	end
# 344 "data/maps/Route120/scripts.pory"

# 345 "data/maps/Route120/scripts.pory"
Route120_EventScript_Keigo::
# 346 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_KEIGO, Route120_Text_KeigoIntro, Route120_Text_KeigoDefeat
# 347 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_KeigoPostBattle, MSGBOX_AUTOCLOSE
# 348 "data/maps/Route120/scripts.pory"
	end
# 349 "data/maps/Route120/scripts.pory"

# 350 "data/maps/Route120/scripts.pory"
Route120_EventScript_Riley::
# 351 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_RILEY, Route120_Text_RileyIntro, Route120_Text_RileyDefeat
# 352 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_RileyPostBattle, MSGBOX_AUTOCLOSE
# 353 "data/maps/Route120/scripts.pory"
	end
# 354 "data/maps/Route120/scripts.pory"

# 355 "data/maps/Route120/scripts.pory"
Route120_EventScript_Leonel::
# 356 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_LEONEL, Route120_Text_LeonelIntro, Route120_Text_LeonelDefeat
# 357 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_LeonelPostBattle, MSGBOX_AUTOCLOSE
# 358 "data/maps/Route120/scripts.pory"
	end
# 359 "data/maps/Route120/scripts.pory"

# 360 "data/maps/Route120/scripts.pory"
Route120_EventScript_Callie::
# 361 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_CALLIE, Route120_Text_CallieIntro, Route120_Text_CallieDefeat
# 362 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_CalliePostBattle, MSGBOX_AUTOCLOSE
# 363 "data/maps/Route120/scripts.pory"
	end
# 364 "data/maps/Route120/scripts.pory"

# 365 "data/maps/Route120/scripts.pory"
Route120_Text_StevenGreeting:
# 366 "data/maps/Route120/scripts.pory"
	.string "STEVEN: Hm? {PLAYER}{KUN}, hi.\n"
# 367 "data/maps/Route120/scripts.pory"
	.string "It's been a while.\p"
# 368 "data/maps/Route120/scripts.pory"
	.string "There's something here that you can't\n"
# 369 "data/maps/Route120/scripts.pory"
	.string "see, right?\p"
# 370 "data/maps/Route120/scripts.pory"
	.string "Now, if I were to use this device on\n"
# 371 "data/maps/Route120/scripts.pory"
	.string "the invisible obstacle…\p"
# 372 "data/maps/Route120/scripts.pory"
	.string "No, no. Rather than describing it,\n"
# 373 "data/maps/Route120/scripts.pory"
	.string "I should just show you.\l"
# 374 "data/maps/Route120/scripts.pory"
	.string "That would be more fun.\p"
# 375 "data/maps/Route120/scripts.pory"
	.string "{PLAYER}{KUN}, are your POKéMON ready for\n"
# 376 "data/maps/Route120/scripts.pory"
	.string "battle?$"
# 377 "data/maps/Route120/scripts.pory"

# 378 "data/maps/Route120/scripts.pory"
Route120_Text_StevenIllWaitHere:
# 379 "data/maps/Route120/scripts.pory"
	.string "STEVEN: No?\p"
# 380 "data/maps/Route120/scripts.pory"
	.string "I'll wait here, so you can get ready.$"
# 381 "data/maps/Route120/scripts.pory"

# 382 "data/maps/Route120/scripts.pory"
Route120_Text_StevenReadyForBattle:
# 383 "data/maps/Route120/scripts.pory"
	.string "STEVEN: {PLAYER}{KUN}, are your POKéMON\n"
# 384 "data/maps/Route120/scripts.pory"
	.string "ready for battle?$"
# 385 "data/maps/Route120/scripts.pory"

# 386 "data/maps/Route120/scripts.pory"
Route120_Text_StevenShowMeYourPower:
# 387 "data/maps/Route120/scripts.pory"
	.string "STEVEN: {PLAYER}{KUN}, show me your true\n"
# 388 "data/maps/Route120/scripts.pory"
	.string "power as a TRAINER!$"
# 389 "data/maps/Route120/scripts.pory"

# 390 "data/maps/Route120/scripts.pory"
Route120_Text_StevenUsedDevonScope:
# 391 "data/maps/Route120/scripts.pory"
	.string "STEVEN used the DEVON SCOPE.\p"
# 392 "data/maps/Route120/scripts.pory"
	.string "An invisible POKéMON became completely\n"
# 393 "data/maps/Route120/scripts.pory"
	.string "visible!\p"
# 394 "data/maps/Route120/scripts.pory"
	.string "The startled POKéMON attacked!$"
# 395 "data/maps/Route120/scripts.pory"

# 396 "data/maps/Route120/scripts.pory"
Route120_Text_StevenGiveDevonScope:
# 397 "data/maps/Route120/scripts.pory"
	.string "STEVEN: I see…\n"
# 398 "data/maps/Route120/scripts.pory"
	.string "Your battle style is intriguing.\p"
# 399 "data/maps/Route120/scripts.pory"
	.string "Your POKéMON have obviously grown\n"
# 400 "data/maps/Route120/scripts.pory"
	.string "since I first met you in DEWFORD.\p"
# 401 "data/maps/Route120/scripts.pory"
	.string "I'd like you to have this\n"
# 402 "data/maps/Route120/scripts.pory"
	.string "DEVON SCOPE.\p"
# 403 "data/maps/Route120/scripts.pory"
	.string "Who knows, there may be other\n"
# 404 "data/maps/Route120/scripts.pory"
	.string "concealed POKéMON.$"
# 405 "data/maps/Route120/scripts.pory"

# 406 "data/maps/Route120/scripts.pory"
Route120_Text_StevenGoodbye:
# 407 "data/maps/Route120/scripts.pory"
	.string "STEVEN: {PLAYER}{KUN}.\p"
# 408 "data/maps/Route120/scripts.pory"
	.string "I enjoy seeing POKéMON and TRAINERS\n"
# 409 "data/maps/Route120/scripts.pory"
	.string "who strive together.\p"
# 410 "data/maps/Route120/scripts.pory"
	.string "I think you're doing great.\p"
# 411 "data/maps/Route120/scripts.pory"
	.string "Well, let's meet again somewhere.$"
# 412 "data/maps/Route120/scripts.pory"

# 413 "data/maps/Route120/scripts.pory"
Kecleon_Text_SomethingUnseeable:
# 414 "data/maps/Route120/scripts.pory"
	.string "Something unseeable is in the way.$"
# 415 "data/maps/Route120/scripts.pory"

# 416 "data/maps/Route120/scripts.pory"
Kecleon_Text_WantToUseDevonScope:
# 417 "data/maps/Route120/scripts.pory"
	.string "Something unseeable is in the way.\p"
# 418 "data/maps/Route120/scripts.pory"
	.string "Want to use the DEVON SCOPE?$"
# 419 "data/maps/Route120/scripts.pory"

# 420 "data/maps/Route120/scripts.pory"
Kecleon_Text_UseDevonScopeMonAttacked:
# 421 "data/maps/Route120/scripts.pory"
	.string "{PLAYER} used the DEVON SCOPE.\p"
# 422 "data/maps/Route120/scripts.pory"
	.string "An invisible POKéMON became completely\n"
# 423 "data/maps/Route120/scripts.pory"
	.string "visible!\p"
# 424 "data/maps/Route120/scripts.pory"
	.string "The startled POKéMON attacked!$"
# 425 "data/maps/Route120/scripts.pory"

# 426 "data/maps/Route120/scripts.pory"
Route120_Text_RouteSignFortree:
# 427 "data/maps/Route120/scripts.pory"
	.string "ROUTE 120\n"
# 428 "data/maps/Route120/scripts.pory"
	.string "{LEFT_ARROW} FORTREE CITY$"
# 429 "data/maps/Route120/scripts.pory"

# 430 "data/maps/Route120/scripts.pory"
Route120_Text_RouteSign121:
# 431 "data/maps/Route120/scripts.pory"
	.string "{RIGHT_ARROW} ROUTE 121\n"
# 432 "data/maps/Route120/scripts.pory"
	.string "{LEFT_ARROW} ROUTE 120$"
