# 1 "data/maps/LilycoveCity/scripts.pory"

# 2 "data/maps/LilycoveCity/scripts.pory"
.set LOCALID_WOMAN_1, 19
# 3 "data/maps/LilycoveCity/scripts.pory"
.set LOCALID_MAN_1, 20
# 4 "data/maps/LilycoveCity/scripts.pory"
.set LOCALID_TYROGUE, 28
# 5 "data/maps/LilycoveCity/scripts.pory"
.set LOCALID_PICHU, 29
# 6 "data/maps/LilycoveCity/scripts.pory"

# 7 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_MapScripts::
# 8 "data/maps/LilycoveCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
# 9 "data/maps/LilycoveCity/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
# 10 "data/maps/LilycoveCity/scripts.pory"
	.byte 0
# 11 "data/maps/LilycoveCity/scripts.pory"

# 12 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_OnTransition:
# 13 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_DIFFICULTY, 0, RemovePichu
# 14 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_DIFFICULTY, 1, RemoveTyrogue
# 15 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_VISITED_LILYCOVE_CITY
# 16 "data/maps/LilycoveCity/scripts.pory"
	setvar VAR_CONTEST_HALL_STATE, 0
# 17 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
# 18 "data/maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
# 19 "data/maps/LilycoveCity/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 20 "data/maps/LilycoveCity/scripts.pory"
	end
# 21 "data/maps/LilycoveCity/scripts.pory"

# 22 "data/maps/LilycoveCity/scripts.pory"
RemoveTyrogue::
# 23 "data/maps/LilycoveCity/scripts.pory"
	removeobject LOCALID_TYROGUE
# 24 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_HIDE_RIVALS_TYROGUE
# 25 "data/maps/LilycoveCity/scripts.pory"
	return
# 26 "data/maps/LilycoveCity/scripts.pory"

# 27 "data/maps/LilycoveCity/scripts.pory"
RemovePichu::
# 28 "data/maps/LilycoveCity/scripts.pory"
	removeobject LOCALID_PICHU
# 29 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_HIDE_RIVALS_PICHU
# 30 "data/maps/LilycoveCity/scripts.pory"
	return
# 31 "data/maps/LilycoveCity/scripts.pory"

# 32 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_OnLoad:
# 33 "data/maps/LilycoveCity/scripts.pory"
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
# 34 "data/maps/LilycoveCity/scripts.pory"
	end
# 35 "data/maps/LilycoveCity/scripts.pory"

# 36 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_SetWailmerMetatiles::
# 37 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, TRUE
# 38 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, TRUE
# 39 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, TRUE
# 40 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, TRUE
# 41 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, TRUE
# 42 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, TRUE
# 43 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, TRUE
# 44 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, TRUE
# 45 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, TRUE
# 46 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, TRUE
# 47 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, TRUE
# 48 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, TRUE
# 49 "data/maps/LilycoveCity/scripts.pory"
	return
# 50 "data/maps/LilycoveCity/scripts.pory"

# 51 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BerryGentleman::
# 52 "data/maps/LilycoveCity/scripts.pory"
	lock
# 53 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 54 "data/maps/LilycoveCity/scripts.pory"
	dotimebasedevents
# 55 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
# 56 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
# 57 "data/maps/LilycoveCity/scripts.pory"
	random 10
# 58 "data/maps/LilycoveCity/scripts.pory"
	addvar VAR_RESULT, FIRST_BERRY_INDEX
# 59 "data/maps/LilycoveCity/scripts.pory"
	giveitem VAR_RESULT
# 60 "data/maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 61 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
# 62 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
# 63 "data/maps/LilycoveCity/scripts.pory"
	release
# 64 "data/maps/LilycoveCity/scripts.pory"
	end
# 65 "data/maps/LilycoveCity/scripts.pory"

# 66 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ReceivedBerry::
# 67 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
# 68 "data/maps/LilycoveCity/scripts.pory"
	release
# 69 "data/maps/LilycoveCity/scripts.pory"
	end
# 70 "data/maps/LilycoveCity/scripts.pory"

# 71 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Man3::
# 72 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
# 73 "data/maps/LilycoveCity/scripts.pory"
	end
# 74 "data/maps/LilycoveCity/scripts.pory"

# 75 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Girl::
# 76 "data/maps/LilycoveCity/scripts.pory"
	lock
# 77 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 78 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
# 79 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
# 80 "data/maps/LilycoveCity/scripts.pory"
	release
# 81 "data/maps/LilycoveCity/scripts.pory"
	end
# 82 "data/maps/LilycoveCity/scripts.pory"

# 83 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_GirlAquaGone::
# 84 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
# 85 "data/maps/LilycoveCity/scripts.pory"
	release
# 86 "data/maps/LilycoveCity/scripts.pory"
	end
# 87 "data/maps/LilycoveCity/scripts.pory"

# 88 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_RichBoy::
# 89 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
# 90 "data/maps/LilycoveCity/scripts.pory"
	end
# 91 "data/maps/LilycoveCity/scripts.pory"

# 92 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Sailor2::
# 93 "data/maps/LilycoveCity/scripts.pory"
	lock
# 94 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 95 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
# 96 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
# 97 "data/maps/LilycoveCity/scripts.pory"
	release
# 98 "data/maps/LilycoveCity/scripts.pory"
	end
# 99 "data/maps/LilycoveCity/scripts.pory"

# 100 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Sailor2AquaGone::
# 101 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
# 102 "data/maps/LilycoveCity/scripts.pory"
	release
# 103 "data/maps/LilycoveCity/scripts.pory"
	end
# 104 "data/maps/LilycoveCity/scripts.pory"

# 105 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Woman2::
# 106 "data/maps/LilycoveCity/scripts.pory"
	lock
# 107 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 108 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
# 109 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
# 110 "data/maps/LilycoveCity/scripts.pory"
	release
# 111 "data/maps/LilycoveCity/scripts.pory"
	end
# 112 "data/maps/LilycoveCity/scripts.pory"

# 113 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Woman2AquaGone::
# 114 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
# 115 "data/maps/LilycoveCity/scripts.pory"
	release
# 116 "data/maps/LilycoveCity/scripts.pory"
	end
# 117 "data/maps/LilycoveCity/scripts.pory"

# 118 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Man2::
# 119 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
# 120 "data/maps/LilycoveCity/scripts.pory"
	end
# 121 "data/maps/LilycoveCity/scripts.pory"

# 122 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertM1::
# 123 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
# 124 "data/maps/LilycoveCity/scripts.pory"
	end
# 125 "data/maps/LilycoveCity/scripts.pory"

# 126 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertF::
# 127 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
# 128 "data/maps/LilycoveCity/scripts.pory"
	end
# 129 "data/maps/LilycoveCity/scripts.pory"

# 130 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertM2::
# 131 "data/maps/LilycoveCity/scripts.pory"
	lock
# 132 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 133 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
# 134 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
# 135 "data/maps/LilycoveCity/scripts.pory"
	release
# 136 "data/maps/LilycoveCity/scripts.pory"
	end
# 137 "data/maps/LilycoveCity/scripts.pory"

# 138 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertM2AquaGone::
# 139 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
# 140 "data/maps/LilycoveCity/scripts.pory"
	release
# 141 "data/maps/LilycoveCity/scripts.pory"
	end
# 142 "data/maps/LilycoveCity/scripts.pory"

# 143 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Sailor1::
# 144 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
# 145 "data/maps/LilycoveCity/scripts.pory"
	end
# 146 "data/maps/LilycoveCity/scripts.pory"

# 147 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_FatMan::
# 148 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
# 149 "data/maps/LilycoveCity/scripts.pory"
	end
# 150 "data/maps/LilycoveCity/scripts.pory"

# 151 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Man1::
# 152 "data/maps/LilycoveCity/scripts.pory"
	lockall
# 153 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
# 154 "data/maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_MAN_1, Common_Movement_FaceOriginalDirection
# 155 "data/maps/LilycoveCity/scripts.pory"
	end
# 156 "data/maps/LilycoveCity/scripts.pory"

# 157 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Woman1::
# 158 "data/maps/LilycoveCity/scripts.pory"
	lockall
# 159 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
# 160 "data/maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_WOMAN_1, Common_Movement_FaceOriginalDirection
# 161 "data/maps/LilycoveCity/scripts.pory"
	end
# 162 "data/maps/LilycoveCity/scripts.pory"

# 163 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_CitySign::
# 164 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
# 165 "data/maps/LilycoveCity/scripts.pory"
	end
# 166 "data/maps/LilycoveCity/scripts.pory"

# 167 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ContestHallSign::
# 168 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
# 169 "data/maps/LilycoveCity/scripts.pory"
	end
# 170 "data/maps/LilycoveCity/scripts.pory"

# 171 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MotelSign::
# 172 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
# 173 "data/maps/LilycoveCity/scripts.pory"
	end
# 174 "data/maps/LilycoveCity/scripts.pory"

# 175 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MuseumSign::
# 176 "data/maps/LilycoveCity/scripts.pory"
	lockall
# 177 "data/maps/LilycoveCity/scripts.pory"
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
# 178 "data/maps/LilycoveCity/scripts.pory"
	switch VAR_0x8004
# 179 "data/maps/LilycoveCity/scripts.pory"
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
# 180 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
# 181 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 182 "data/maps/LilycoveCity/scripts.pory"
	end
# 183 "data/maps/LilycoveCity/scripts.pory"

# 184 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MuseumSignNoPaintings::
# 185 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
# 186 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 187 "data/maps/LilycoveCity/scripts.pory"
	end
# 188 "data/maps/LilycoveCity/scripts.pory"

# 189 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_HarborSign::
# 190 "data/maps/LilycoveCity/scripts.pory"
	lockall
# 191 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
# 192 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
# 193 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 194 "data/maps/LilycoveCity/scripts.pory"
	end
# 195 "data/maps/LilycoveCity/scripts.pory"

# 196 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_HarborSignFerryReady::
# 197 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
# 198 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 199 "data/maps/LilycoveCity/scripts.pory"
	end
# 200 "data/maps/LilycoveCity/scripts.pory"

# 201 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_TrainerFanClubSign::
# 202 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
# 203 "data/maps/LilycoveCity/scripts.pory"
	end
# 204 "data/maps/LilycoveCity/scripts.pory"

# 205 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DepartmentStoreSign::
# 206 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
# 207 "data/maps/LilycoveCity/scripts.pory"
	end
# 208 "data/maps/LilycoveCity/scripts.pory"

# 209 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MoveDeletersHouseSign::
# 210 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
# 211 "data/maps/LilycoveCity/scripts.pory"
	end
# 212 "data/maps/LilycoveCity/scripts.pory"

# 213 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_WailmerTrainerGrunt::
# 214 "data/maps/LilycoveCity/scripts.pory"
	lockall
# 215 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
# 216 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
# 217 "data/maps/LilycoveCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 218 "data/maps/LilycoveCity/scripts.pory"
	waitmovement 0
# 219 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
# 220 "data/maps/LilycoveCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 221 "data/maps/LilycoveCity/scripts.pory"
	waitmovement 0
# 222 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_MET_WAILMER_TRAINER
# 223 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 224 "data/maps/LilycoveCity/scripts.pory"
	end
# 225 "data/maps/LilycoveCity/scripts.pory"

# 226 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MetWailmerTrainer::
# 227 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
# 228 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 229 "data/maps/LilycoveCity/scripts.pory"
	end
# 230 "data/maps/LilycoveCity/scripts.pory"

# 231 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt1::
# 232 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
# 233 "data/maps/LilycoveCity/scripts.pory"
	end
# 234 "data/maps/LilycoveCity/scripts.pory"

# 235 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt2::
# 236 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
# 237 "data/maps/LilycoveCity/scripts.pory"
	end
# 238 "data/maps/LilycoveCity/scripts.pory"

# 239 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt3::
# 240 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
# 241 "data/maps/LilycoveCity/scripts.pory"
	end
# 242 "data/maps/LilycoveCity/scripts.pory"

# 243 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt4::
# 244 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
# 245 "data/maps/LilycoveCity/scripts.pory"
	end
# 246 "data/maps/LilycoveCity/scripts.pory"

# 247 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Rival::
# 248 "data/maps/LilycoveCity/scripts.pory"
	lock
# 249 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 250 "data/maps/LilycoveCity/scripts.pory"
	checkplayergender
# 251 "data/maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LilycoveCity_EventScript_May
# 252 "data/maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LilycoveCity_EventScript_Brendan
# 253 "data/maps/LilycoveCity/scripts.pory"
	end
# 254 "data/maps/LilycoveCity/scripts.pory"

# 255 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_May::
# 256 "data/maps/LilycoveCity/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 257 "data/maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
# 258 "data/maps/LilycoveCity/scripts.pory"
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
# 259 "data/maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineMayBattle
# 260 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
# 261 "data/maps/LilycoveCity/scripts.pory"
	playse SE_M_BATON_PASS
# 262 "data/maps/LilycoveCity/scripts.pory"
	waitse
# 263 "data/maps/LilycoveCity/scripts.pory"
	removeobject LOCALID_TYROGUE
# 264 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_HIDE_RIVALS_TYROGUE
# 265 "data/maps/LilycoveCity/scripts.pory"
	removeobject LOCALID_PICHU
# 266 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_HIDE_RIVALS_PICHU
# 267 "data/maps/LilycoveCity/scripts.pory"
	switch VAR_STARTER_MON
# 268 "data/maps/LilycoveCity/scripts.pory"
	case 0, LilycoveCity_EventScript_BattleMayTreecko
# 269 "data/maps/LilycoveCity/scripts.pory"
	case 1, LilycoveCity_EventScript_BattleMayTorchic
# 270 "data/maps/LilycoveCity/scripts.pory"
	case 2, LilycoveCity_EventScript_BattleMayMudkip
# 271 "data/maps/LilycoveCity/scripts.pory"
	end
# 272 "data/maps/LilycoveCity/scripts.pory"

# 273 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayAskToBattleAgain::
# 274 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
# 275 "data/maps/LilycoveCity/scripts.pory"
	return
# 276 "data/maps/LilycoveCity/scripts.pory"

# 277 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayAskToBattle::
# 278 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
# 279 "data/maps/LilycoveCity/scripts.pory"
	return
# 280 "data/maps/LilycoveCity/scripts.pory"

# 281 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DeclineMayBattle::
# 282 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
# 283 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
# 284 "data/maps/LilycoveCity/scripts.pory"
	savebgm MUS_DUMMY
# 285 "data/maps/LilycoveCity/scripts.pory"
	fadedefaultbgm
# 286 "data/maps/LilycoveCity/scripts.pory"
	release
# 287 "data/maps/LilycoveCity/scripts.pory"
	end
# 288 "data/maps/LilycoveCity/scripts.pory"

# 289 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Brendan::
# 290 "data/maps/LilycoveCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 291 "data/maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
# 292 "data/maps/LilycoveCity/scripts.pory"
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
# 293 "data/maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineBrendanBattle
# 294 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
# 295 "data/maps/LilycoveCity/scripts.pory"
	playse SE_M_BATON_PASS
# 296 "data/maps/LilycoveCity/scripts.pory"
	waitse
# 297 "data/maps/LilycoveCity/scripts.pory"
	removeobject LOCALID_TYROGUE
# 298 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_HIDE_RIVALS_TYROGUE
# 299 "data/maps/LilycoveCity/scripts.pory"
	removeobject LOCALID_PICHU
# 300 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_HIDE_RIVALS_PICHU
# 301 "data/maps/LilycoveCity/scripts.pory"
	switch VAR_STARTER_MON
# 302 "data/maps/LilycoveCity/scripts.pory"
	case 0, LilycoveCity_EventScript_BattleBrendanTreecko
# 303 "data/maps/LilycoveCity/scripts.pory"
	case 1, LilycoveCity_EventScript_BattleBrendanTorchic
# 304 "data/maps/LilycoveCity/scripts.pory"
	case 2, LilycoveCity_EventScript_BattleBrendanMudkip
# 305 "data/maps/LilycoveCity/scripts.pory"
	end
# 306 "data/maps/LilycoveCity/scripts.pory"

# 307 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanAskToBattleAgain::
# 308 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
# 309 "data/maps/LilycoveCity/scripts.pory"
	return
# 310 "data/maps/LilycoveCity/scripts.pory"

# 311 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanAskToBattle::
# 312 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
# 313 "data/maps/LilycoveCity/scripts.pory"
	return
# 314 "data/maps/LilycoveCity/scripts.pory"

# 315 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DeclineBrendanBattle::
# 316 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
# 317 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
# 318 "data/maps/LilycoveCity/scripts.pory"
	savebgm MUS_DUMMY
# 319 "data/maps/LilycoveCity/scripts.pory"
	fadedefaultbgm
# 320 "data/maps/LilycoveCity/scripts.pory"
	release
# 321 "data/maps/LilycoveCity/scripts.pory"
	end
# 322 "data/maps/LilycoveCity/scripts.pory"

# 323 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleMayTreecko::
# 324 "data/maps/LilycoveCity/scripts.pory"
	goto_if_unset FLAG_DEFEATED_FORTREE_GYM, LilycoveCity_EventScript_BattleMayTreeckoPW
# 325 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO, LilycoveCity_Text_MayDefeat
# 326 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedMay
# 327 "data/maps/LilycoveCity/scripts.pory"
	end
# 328 "data/maps/LilycoveCity/scripts.pory"

# 329 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleMayTreeckoPW::
# 330 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO_PW, LilycoveCity_Text_MayDefeat
# 331 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedMay
# 332 "data/maps/LilycoveCity/scripts.pory"
	end
# 333 "data/maps/LilycoveCity/scripts.pory"

# 334 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleMayTorchic::
# 335 "data/maps/LilycoveCity/scripts.pory"
	goto_if_unset FLAG_DEFEATED_FORTREE_GYM, LilycoveCity_EventScript_BattleMayTorchicPW
# 336 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC, LilycoveCity_Text_MayDefeat
# 337 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedMay
# 338 "data/maps/LilycoveCity/scripts.pory"
	end
# 339 "data/maps/LilycoveCity/scripts.pory"

# 340 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleMayTorchicPW::
# 341 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC_PW, LilycoveCity_Text_MayDefeat
# 342 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedMay
# 343 "data/maps/LilycoveCity/scripts.pory"
	end
# 344 "data/maps/LilycoveCity/scripts.pory"

# 345 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleMayMudkip::
# 346 "data/maps/LilycoveCity/scripts.pory"
	goto_if_unset FLAG_DEFEATED_FORTREE_GYM, LilycoveCity_EventScript_BattleMayMudkipPW
# 347 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, LilycoveCity_Text_MayDefeat
# 348 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedMay
# 349 "data/maps/LilycoveCity/scripts.pory"
	end
# 350 "data/maps/LilycoveCity/scripts.pory"

# 351 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleMayMudkipPW::
# 352 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP_PW, LilycoveCity_Text_MayDefeat
# 353 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedMay
# 354 "data/maps/LilycoveCity/scripts.pory"
	end
# 355 "data/maps/LilycoveCity/scripts.pory"

# 356 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleBrendanTreecko::
# 357 "data/maps/LilycoveCity/scripts.pory"
	goto_if_unset FLAG_DEFEATED_FORTREE_GYM, LilycoveCity_EventScript_BattleBrendanTreeckoPW
# 358 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, LilycoveCity_Text_BrendanDefeat
# 359 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedBrendan
# 360 "data/maps/LilycoveCity/scripts.pory"
	end
# 361 "data/maps/LilycoveCity/scripts.pory"

# 362 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleBrendanTreeckoPW::
# 363 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO_PW, LilycoveCity_Text_BrendanDefeat
# 364 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedBrendan
# 365 "data/maps/LilycoveCity/scripts.pory"
	end
# 366 "data/maps/LilycoveCity/scripts.pory"

# 367 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleBrendanTorchic::
# 368 "data/maps/LilycoveCity/scripts.pory"
	goto_if_unset FLAG_DEFEATED_FORTREE_GYM, LilycoveCity_EventScript_BattleBrendanTorchicPW
# 369 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, LilycoveCity_Text_BrendanDefeat
# 370 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedBrendan
# 371 "data/maps/LilycoveCity/scripts.pory"
	end
# 372 "data/maps/LilycoveCity/scripts.pory"

# 373 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleBrendanTorchicPW::
# 374 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC_PW, LilycoveCity_Text_BrendanDefeat
# 375 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedBrendan
# 376 "data/maps/LilycoveCity/scripts.pory"
	end
# 377 "data/maps/LilycoveCity/scripts.pory"

# 378 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleBrendanMudkip::
# 379 "data/maps/LilycoveCity/scripts.pory"
	goto_if_unset FLAG_DEFEATED_FORTREE_GYM, LilycoveCity_EventScript_BattleBrendanMudkipPW
# 380 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, LilycoveCity_Text_BrendanDefeat
# 381 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedBrendan
# 382 "data/maps/LilycoveCity/scripts.pory"
	end
# 383 "data/maps/LilycoveCity/scripts.pory"

# 384 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleBrendanMudkipPW::
# 385 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP_PW, LilycoveCity_Text_BrendanDefeat
# 386 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedBrendan
# 387 "data/maps/LilycoveCity/scripts.pory"
	end
# 388 "data/maps/LilycoveCity/scripts.pory"

# 389 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DefeatedMay::
# 390 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
# 391 "data/maps/LilycoveCity/scripts.pory"
	setvar VAR_RESULT, FALSE
# 392 "data/maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
# 393 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_MayCollectBadges
# 394 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_MayPokemonLeague
# 395 "data/maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
# 396 "data/maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
# 397 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_RivalFlyAway
# 398 "data/maps/LilycoveCity/scripts.pory"
	end
# 399 "data/maps/LilycoveCity/scripts.pory"

# 400 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_CheckFinalBadge::
# 401 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
# 402 "data/maps/LilycoveCity/scripts.pory"
	return
# 403 "data/maps/LilycoveCity/scripts.pory"

# 404 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_HasFinalBadge::
# 405 "data/maps/LilycoveCity/scripts.pory"
	setvar VAR_RESULT, TRUE
# 406 "data/maps/LilycoveCity/scripts.pory"
	return
# 407 "data/maps/LilycoveCity/scripts.pory"

# 408 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayCollectBadges::
# 409 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
# 410 "data/maps/LilycoveCity/scripts.pory"
	return
# 411 "data/maps/LilycoveCity/scripts.pory"

# 412 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayPokemonLeague::
# 413 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
# 414 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
# 415 "data/maps/LilycoveCity/scripts.pory"
	return
# 416 "data/maps/LilycoveCity/scripts.pory"

# 417 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayBattleFrontier::
# 418 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
# 419 "data/maps/LilycoveCity/scripts.pory"
	return
# 420 "data/maps/LilycoveCity/scripts.pory"

# 421 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DefeatedBrendan::
# 422 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
# 423 "data/maps/LilycoveCity/scripts.pory"
	setvar VAR_RESULT, FALSE
# 424 "data/maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
# 425 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BrendanCollectBadges
# 426 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_BrendanPokemonLeague
# 427 "data/maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
# 428 "data/maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
# 429 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_RivalFlyAway
# 430 "data/maps/LilycoveCity/scripts.pory"
	end
# 431 "data/maps/LilycoveCity/scripts.pory"

# 432 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanCollectBadges::
# 433 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
# 434 "data/maps/LilycoveCity/scripts.pory"
	return
# 435 "data/maps/LilycoveCity/scripts.pory"

# 436 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanPokemonLeague::
# 437 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
# 438 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
# 439 "data/maps/LilycoveCity/scripts.pory"
	return
# 440 "data/maps/LilycoveCity/scripts.pory"

# 441 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanBattleFrontier::
# 442 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
# 443 "data/maps/LilycoveCity/scripts.pory"
	return
# 444 "data/maps/LilycoveCity/scripts.pory"

# 445 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_RivalFlyAway::
# 446 "data/maps/LilycoveCity/scripts.pory"
	closemessage
# 447 "data/maps/LilycoveCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
# 448 "data/maps/LilycoveCity/scripts.pory"
	waitmovement 0
# 449 "data/maps/LilycoveCity/scripts.pory"
	delay 50
# 450 "data/maps/LilycoveCity/scripts.pory"
	setfieldeffectargument 0, 1
# 451 "data/maps/LilycoveCity/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 452 "data/maps/LilycoveCity/scripts.pory"
	delay 15
# 453 "data/maps/LilycoveCity/scripts.pory"
	removeobject VAR_LAST_TALKED
# 454 "data/maps/LilycoveCity/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 455 "data/maps/LilycoveCity/scripts.pory"
	savebgm MUS_DUMMY
# 456 "data/maps/LilycoveCity/scripts.pory"
	fadedefaultbgm
# 457 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_MET_RIVAL_LILYCOVE
# 458 "data/maps/LilycoveCity/scripts.pory"
	release
# 459 "data/maps/LilycoveCity/scripts.pory"
	end
# 460 "data/maps/LilycoveCity/scripts.pory"

# 461 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_SchoolKidM::
# 462 "data/maps/LilycoveCity/scripts.pory"
	lock
# 463 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 464 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
# 465 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, YES, LilycoveCity_EventScript_KnowAboutBerryBlender
# 466 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DontKnowAboutBerryBlender
# 467 "data/maps/LilycoveCity/scripts.pory"
	release
# 468 "data/maps/LilycoveCity/scripts.pory"
	end
# 469 "data/maps/LilycoveCity/scripts.pory"

# 470 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_KnowAboutBerryBlender::
# 471 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
# 472 "data/maps/LilycoveCity/scripts.pory"
	return
# 473 "data/maps/LilycoveCity/scripts.pory"

# 474 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DontKnowAboutBerryBlender::
# 475 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
# 476 "data/maps/LilycoveCity/scripts.pory"
	return
# 477 "data/maps/LilycoveCity/scripts.pory"

# 478 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayShoppingLetsBattle:
# 479 "data/maps/LilycoveCity/scripts.pory"
	.string "MAY: Oh, hey?\n"
# 480 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, are you shopping, too?\p"
# 481 "data/maps/LilycoveCity/scripts.pory"
	.string "I bought a whole bunch of DOLLS and\n"
# 482 "data/maps/LilycoveCity/scripts.pory"
	.string "POSTERS.\p"
# 483 "data/maps/LilycoveCity/scripts.pory"
	.string "Of course, I've also caught a lot of\n"
# 484 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéMON, and I'm raising them\l"
# 485 "data/maps/LilycoveCity/scripts.pory"
	.string "properly, too.\p"
# 486 "data/maps/LilycoveCity/scripts.pory"
	.string "Actually, I'm more worried if you're\n"
# 487 "data/maps/LilycoveCity/scripts.pory"
	.string "raising POKéMON properly, {PLAYER}{KUN}.\p"
# 488 "data/maps/LilycoveCity/scripts.pory"
	.string "I'll battle with you, so you can show\n"
# 489 "data/maps/LilycoveCity/scripts.pory"
	.string "me your POKéMON, {PLAYER}{KUN}.$"
# 490 "data/maps/LilycoveCity/scripts.pory"

# 491 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayNotRaisingPokemon:
# 492 "data/maps/LilycoveCity/scripts.pory"
	.string "MAY: Oh, why? {PLAYER}{KUN}, haven't you\n"
# 493 "data/maps/LilycoveCity/scripts.pory"
	.string "been raising your POKéMON?\p"
# 494 "data/maps/LilycoveCity/scripts.pory"
	.string "That's not a very good showing as a\n"
# 495 "data/maps/LilycoveCity/scripts.pory"
	.string "TRAINER…$"
# 496 "data/maps/LilycoveCity/scripts.pory"

# 497 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayBattleMe:
# 498 "data/maps/LilycoveCity/scripts.pory"
	.string "MAY: Come on, battle with me, so I can\n"
# 499 "data/maps/LilycoveCity/scripts.pory"
	.string "check out your POKéMON!$"
# 500 "data/maps/LilycoveCity/scripts.pory"

# 501 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayWontBeBeaten:
# 502 "data/maps/LilycoveCity/scripts.pory"
	.string "MAY: The POKéMON I raised won't be\n"
# 503 "data/maps/LilycoveCity/scripts.pory"
	.string "beaten by your POKéMON, {PLAYER}{KUN}!$"
# 504 "data/maps/LilycoveCity/scripts.pory"

# 505 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayDefeat:
# 506 "data/maps/LilycoveCity/scripts.pory"
	.string "… … … … … … … …\p"
# 507 "data/maps/LilycoveCity/scripts.pory"
	.string "I remember the battle I had with you,\n"
# 508 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, on ROUTE 103.\p"
# 509 "data/maps/LilycoveCity/scripts.pory"
	.string "That battle helped you become this\n"
# 510 "data/maps/LilycoveCity/scripts.pory"
	.string "strong, {PLAYER}{KUN}, didn't it?$"
# 511 "data/maps/LilycoveCity/scripts.pory"

# 512 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayGoingBackToLittleroot:
# 513 "data/maps/LilycoveCity/scripts.pory"
	.string "MAY: I'm thinking of going back to\n"
# 514 "data/maps/LilycoveCity/scripts.pory"
	.string "LITTLEROOT soon.\p"
# 515 "data/maps/LilycoveCity/scripts.pory"
	.string "I've caught a decent group of POKéMON,\n"
# 516 "data/maps/LilycoveCity/scripts.pory"
	.string "and my POKéDEX is coming along, so\l"
# 517 "data/maps/LilycoveCity/scripts.pory"
	.string "I'm going home to show my dad.$"
# 518 "data/maps/LilycoveCity/scripts.pory"

# 519 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayYouGoingToCollectBadges:
# 520 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, what are you going to do?\p"
# 521 "data/maps/LilycoveCity/scripts.pory"
	.string "Collect all the GYM BADGES and take\n"
# 522 "data/maps/LilycoveCity/scripts.pory"
	.string "the POKéMON LEAGUE challenge?\p"
# 523 "data/maps/LilycoveCity/scripts.pory"
	.string "Well, while you're collecting BADGES,\n"
# 524 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, I'm going to work on my\l"
# 525 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéDEX. I'll complete it before you!\p"
# 526 "data/maps/LilycoveCity/scripts.pory"
	.string "See you!$"
# 527 "data/maps/LilycoveCity/scripts.pory"

# 528 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayYouGoingToPokemonLeague:
# 529 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, what are you going to do?\p"
# 530 "data/maps/LilycoveCity/scripts.pory"
	.string "Are you taking the POKéMON LEAGUE\n"
# 531 "data/maps/LilycoveCity/scripts.pory"
	.string "challenge?\p"
# 532 "data/maps/LilycoveCity/scripts.pory"
	.string "Or, are you going to complete your\n"
# 533 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéDEX?\p"
# 534 "data/maps/LilycoveCity/scripts.pory"
	.string "I might've lost to you in battling,\n"
# 535 "data/maps/LilycoveCity/scripts.pory"
	.string "but I'll finish my POKéDEX before you!\p"
# 536 "data/maps/LilycoveCity/scripts.pory"
	.string "See you!$"
# 537 "data/maps/LilycoveCity/scripts.pory"

# 538 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayYouGoingToBattleFrontier:
# 539 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, what are you going to do?\p"
# 540 "data/maps/LilycoveCity/scripts.pory"
	.string "Are you taking the BATTLE FRONTIER\n"
# 541 "data/maps/LilycoveCity/scripts.pory"
	.string "challenge?\p"
# 542 "data/maps/LilycoveCity/scripts.pory"
	.string "Or, are you going to complete your\n"
# 543 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéDEX?\p"
# 544 "data/maps/LilycoveCity/scripts.pory"
	.string "I might've lost to you in battling,\n"
# 545 "data/maps/LilycoveCity/scripts.pory"
	.string "but I'll finish my POKéDEX before you!\p"
# 546 "data/maps/LilycoveCity/scripts.pory"
	.string "See you!$"
# 547 "data/maps/LilycoveCity/scripts.pory"

# 548 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanShoppingLetsBattle:
# 549 "data/maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Oh, hey, it's {PLAYER}.\p"
# 550 "data/maps/LilycoveCity/scripts.pory"
	.string "I'm running an errand for my dad.\n"
# 551 "data/maps/LilycoveCity/scripts.pory"
	.string "No, I'm not buying any DOLLS.\p"
# 552 "data/maps/LilycoveCity/scripts.pory"
	.string "Anyways, it's been a while.\p"
# 553 "data/maps/LilycoveCity/scripts.pory"
	.string "Want to have a battle to see who's been\n"
# 554 "data/maps/LilycoveCity/scripts.pory"
	.string "raising POKéMON better?$"
# 555 "data/maps/LilycoveCity/scripts.pory"

# 556 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanNoConfidence:
# 557 "data/maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Oh, what's the matter?\n"
# 558 "data/maps/LilycoveCity/scripts.pory"
	.string "Don't have the confidence?$"
# 559 "data/maps/LilycoveCity/scripts.pory"

# 560 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanBattleMe:
# 561 "data/maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Want to battle to see who's\n"
# 562 "data/maps/LilycoveCity/scripts.pory"
	.string "been raising POKéMON better?$"
# 563 "data/maps/LilycoveCity/scripts.pory"

# 564 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanWontBeBeaten:
# 565 "data/maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Aww, but you know I'm not\n"
# 566 "data/maps/LilycoveCity/scripts.pory"
	.string "going to lose to no {PLAYER}.$"
# 567 "data/maps/LilycoveCity/scripts.pory"

# 568 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanDefeat:
# 569 "data/maps/LilycoveCity/scripts.pory"
	.string "Humph…\n"
# 570 "data/maps/LilycoveCity/scripts.pory"
	.string "You've done a lot of raising.\p"
# 571 "data/maps/LilycoveCity/scripts.pory"
	.string "That stings a bit--I had a head start\n"
# 572 "data/maps/LilycoveCity/scripts.pory"
	.string "on you as a TRAINER…$"
# 573 "data/maps/LilycoveCity/scripts.pory"

# 574 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanGoingBackToLittleroot:
# 575 "data/maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: I…\n"
# 576 "data/maps/LilycoveCity/scripts.pory"
	.string "I plan on going home to LITTLEROOT.\p"
# 577 "data/maps/LilycoveCity/scripts.pory"
	.string "You know I'm helping out my dad on his\n"
# 578 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéDEX. It's coming together pretty\l"
# 579 "data/maps/LilycoveCity/scripts.pory"
	.string "decently, so I should go show him.$"
# 580 "data/maps/LilycoveCity/scripts.pory"

# 581 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanYouGoingToCollectBadges:
# 582 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}, what are you going to do?\p"
# 583 "data/maps/LilycoveCity/scripts.pory"
	.string "Collect all the GYM BADGES and take\n"
# 584 "data/maps/LilycoveCity/scripts.pory"
	.string "the POKéMON LEAGUE challenge?\p"
# 585 "data/maps/LilycoveCity/scripts.pory"
	.string "Maybe I'll do that, too…\p"
# 586 "data/maps/LilycoveCity/scripts.pory"
	.string "Well, anyway, hang in there!$"
# 587 "data/maps/LilycoveCity/scripts.pory"

# 588 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanYouGoingToPokemonLeague:
# 589 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}, what are you going to do?\p"
# 590 "data/maps/LilycoveCity/scripts.pory"
	.string "Since you're that strong, are you\n"
# 591 "data/maps/LilycoveCity/scripts.pory"
	.string "taking the POKéMON LEAGUE challenge?\p"
# 592 "data/maps/LilycoveCity/scripts.pory"
	.string "Heh, even me--if I trained my POKéMON\n"
# 593 "data/maps/LilycoveCity/scripts.pory"
	.string "a bit more, I should be stronger than\l"
# 594 "data/maps/LilycoveCity/scripts.pory"
	.string "you, {PLAYER}.\p"
# 595 "data/maps/LilycoveCity/scripts.pory"
	.string "Well, anyway, hang in there!$"
# 596 "data/maps/LilycoveCity/scripts.pory"

# 597 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanYouGoingToBattleFrontier:
# 598 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}, what are you going to do?\p"
# 599 "data/maps/LilycoveCity/scripts.pory"
	.string "Are you taking the BATTLE FRONTIER\n"
# 600 "data/maps/LilycoveCity/scripts.pory"
	.string "challenge?\p"
# 601 "data/maps/LilycoveCity/scripts.pory"
	.string "Or, are you going to complete your\n"
# 602 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéDEX?\p"
# 603 "data/maps/LilycoveCity/scripts.pory"
	.string "Since you're that strong, you should\n"
# 604 "data/maps/LilycoveCity/scripts.pory"
	.string "consider the BATTLE FRONTIER.\p"
# 605 "data/maps/LilycoveCity/scripts.pory"
	.string "Heh, if I train my POKéMON a bit more,\n"
# 606 "data/maps/LilycoveCity/scripts.pory"
	.string "I'll get stronger than you, {PLAYER}.\p"
# 607 "data/maps/LilycoveCity/scripts.pory"
	.string "Maybe I should go to the BATTLE\n"
# 608 "data/maps/LilycoveCity/scripts.pory"
	.string "FRONTIER.\p"
# 609 "data/maps/LilycoveCity/scripts.pory"
	.string "Well, anyway, hang in there!$"
# 610 "data/maps/LilycoveCity/scripts.pory"

# 611 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MovedLootIntoHideoutToday:
# 612 "data/maps/LilycoveCity/scripts.pory"
	.string "Fufufu…\p"
# 613 "data/maps/LilycoveCity/scripts.pory"
	.string "We moved more loot into our secret\n"
# 614 "data/maps/LilycoveCity/scripts.pory"
	.string "HIDEOUT today…\p"
# 615 "data/maps/LilycoveCity/scripts.pory"
	.string "Wh-who are you?!\n"
# 616 "data/maps/LilycoveCity/scripts.pory"
	.string "I was just talking to myself!$"
# 617 "data/maps/LilycoveCity/scripts.pory"

# 618 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ChanceToDoBigThings:
# 619 "data/maps/LilycoveCity/scripts.pory"
	.string "I'm just a GRUNT, so I don't know what\n"
# 620 "data/maps/LilycoveCity/scripts.pory"
	.string "the BOSS is thinking…\p"
# 621 "data/maps/LilycoveCity/scripts.pory"
	.string "But being on TEAM AQUA, I know I'll get\n"
# 622 "data/maps/LilycoveCity/scripts.pory"
	.string "the chance to do big things!\p"
# 623 "data/maps/LilycoveCity/scripts.pory"
	.string "Wh-who are you?!\n"
# 624 "data/maps/LilycoveCity/scripts.pory"
	.string "I was just talking to myself!$"
# 625 "data/maps/LilycoveCity/scripts.pory"

# 626 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_DontGoNearCaveInCove:
# 627 "data/maps/LilycoveCity/scripts.pory"
	.string "Hey, you!\p"
# 628 "data/maps/LilycoveCity/scripts.pory"
	.string "Don't go near the cave in the cove!\p"
# 629 "data/maps/LilycoveCity/scripts.pory"
	.string "Why? You don't need a reason why!\n"
# 630 "data/maps/LilycoveCity/scripts.pory"
	.string "I'm an adult, so you just listen to me!$"
# 631 "data/maps/LilycoveCity/scripts.pory"

# 632 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_IfWorldBecomesOurs:
# 633 "data/maps/LilycoveCity/scripts.pory"
	.string "If this whole wide world becomes ours,\n"
# 634 "data/maps/LilycoveCity/scripts.pory"
	.string "TEAM AQUA's, it will be a happier\l"
# 635 "data/maps/LilycoveCity/scripts.pory"
	.string "place for POKéMON, too.$"
# 636 "data/maps/LilycoveCity/scripts.pory"

# 637 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_WailmerLeapOutOfWater:
# 638 "data/maps/LilycoveCity/scripts.pory"
	.string "There! WAILMER!\n"
# 639 "data/maps/LilycoveCity/scripts.pory"
	.string "Leap out of the water now!$"
# 640 "data/maps/LilycoveCity/scripts.pory"

# 641 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_GetLostMessingUpTraining:
# 642 "data/maps/LilycoveCity/scripts.pory"
	.string "Hunh? What do you want?\p"
# 643 "data/maps/LilycoveCity/scripts.pory"
	.string "You're messing up our training,\n"
# 644 "data/maps/LilycoveCity/scripts.pory"
	.string "so can you, like, get lost?$"
# 645 "data/maps/LilycoveCity/scripts.pory"

# 646 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ContestHallInTown:
# 647 "data/maps/LilycoveCity/scripts.pory"
	.string "There's a POKéMON CONTEST HALL\n"
# 648 "data/maps/LilycoveCity/scripts.pory"
	.string "right in this here town. \p"
# 649 "data/maps/LilycoveCity/scripts.pory"
	.string "That means well-raised POKéMON will\n"
# 650 "data/maps/LilycoveCity/scripts.pory"
	.string "come from all over the country.\p"
# 651 "data/maps/LilycoveCity/scripts.pory"
	.string "My heart swells with excitement!$"
# 652 "data/maps/LilycoveCity/scripts.pory"

# 653 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_StrangeCaveInCove:
# 654 "data/maps/LilycoveCity/scripts.pory"
	.string "Have you seen that strange cave in\n"
# 655 "data/maps/LilycoveCity/scripts.pory"
	.string "the cove at the edge of town?$"
# 656 "data/maps/LilycoveCity/scripts.pory"

# 657 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_GoingToMoveDeleterForHMs:
# 658 "data/maps/LilycoveCity/scripts.pory"
	.string "I'm going to teach my POKéMON some new\n"
# 659 "data/maps/LilycoveCity/scripts.pory"
	.string "moves for entering a CONTEST.\p"
# 660 "data/maps/LilycoveCity/scripts.pory"
	.string "So, I'm going to see the MOVE DELETER\n"
# 661 "data/maps/LilycoveCity/scripts.pory"
	.string "and make it forget HM moves.$"
# 662 "data/maps/LilycoveCity/scripts.pory"

# 663 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ImFromKanto:
# 664 "data/maps/LilycoveCity/scripts.pory"
	.string "I came from KANTO.\p"
# 665 "data/maps/LilycoveCity/scripts.pory"
	.string "The HOENN region is beautiful with\n"
# 666 "data/maps/LilycoveCity/scripts.pory"
	.string "all its water and verdant nature.\p"
# 667 "data/maps/LilycoveCity/scripts.pory"
	.string "Hunh? Wait a second…\p"
# 668 "data/maps/LilycoveCity/scripts.pory"
	.string "Could there be rare POKéMON that live\n"
# 669 "data/maps/LilycoveCity/scripts.pory"
	.string "only in this area?$"
# 670 "data/maps/LilycoveCity/scripts.pory"

# 671 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TeamAquaBeenTrainingWailmer:
# 672 "data/maps/LilycoveCity/scripts.pory"
	.string "TEAM AQUA's been training their\n"
# 673 "data/maps/LilycoveCity/scripts.pory"
	.string "WAILMER in the cove.\p"
# 674 "data/maps/LilycoveCity/scripts.pory"
	.string "We SAILORS can't get our boats out\n"
# 675 "data/maps/LilycoveCity/scripts.pory"
	.string "to sea with them in the way!$"
# 676 "data/maps/LilycoveCity/scripts.pory"

# 677 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SomeonePuntedTeamAquaOut:
# 678 "data/maps/LilycoveCity/scripts.pory"
	.string "Ahoy, did you know?\p"
# 679 "data/maps/LilycoveCity/scripts.pory"
	.string "Someone punted TEAM AQUA out of\n"
# 680 "data/maps/LilycoveCity/scripts.pory"
	.string "the way for us!\p"
# 681 "data/maps/LilycoveCity/scripts.pory"
	.string "That got the WAILMER out of the cove,\n"
# 682 "data/maps/LilycoveCity/scripts.pory"
	.string "so we can get our boats out again.$"
# 683 "data/maps/LilycoveCity/scripts.pory"

# 684 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SomeoneStoleMyPokemon:
# 685 "data/maps/LilycoveCity/scripts.pory"
	.string "I was taking a relaxing snooze at the\n"
# 686 "data/maps/LilycoveCity/scripts.pory"
	.string "seaside inn to the sound of waves…\p"
# 687 "data/maps/LilycoveCity/scripts.pory"
	.string "When someone stole my POKéMON!\p"
# 688 "data/maps/LilycoveCity/scripts.pory"
	.string "Who's the abductor?\n"
# 689 "data/maps/LilycoveCity/scripts.pory"
	.string "TEAM AQUA? Is it TEAM AQUA?$"
# 690 "data/maps/LilycoveCity/scripts.pory"

# 691 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MissingPokemonCameBack:
# 692 "data/maps/LilycoveCity/scripts.pory"
	.string "My missing POKéMON…\n"
# 693 "data/maps/LilycoveCity/scripts.pory"
	.string "It came back without me noticing!$"
# 694 "data/maps/LilycoveCity/scripts.pory"

# 695 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ImArtDealer:
# 696 "data/maps/LilycoveCity/scripts.pory"
	.string "I'm an ART DEALER.\p"
# 697 "data/maps/LilycoveCity/scripts.pory"
	.string "I am a buyer and seller of fine art,\n"
# 698 "data/maps/LilycoveCity/scripts.pory"
	.string "especially paintings.\p"
# 699 "data/maps/LilycoveCity/scripts.pory"
	.string "I've heard that the MUSEUM here has\n"
# 700 "data/maps/LilycoveCity/scripts.pory"
	.string "magnificent works on exhibit…$"
# 701 "data/maps/LilycoveCity/scripts.pory"

# 702 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SeaRemainsForeverYoung:
# 703 "data/maps/LilycoveCity/scripts.pory"
	.string "Even as we grow old and wrinkled,\n"
# 704 "data/maps/LilycoveCity/scripts.pory"
	.string "the sea remains forever young with\l"
# 705 "data/maps/LilycoveCity/scripts.pory"
	.string "the vivid brilliance of life…\p"
# 706 "data/maps/LilycoveCity/scripts.pory"
	.string "Fwohoho fwohohohoho…$"
# 707 "data/maps/LilycoveCity/scripts.pory"

# 708 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SixtyYearsAgoHusbandProposed:
# 709 "data/maps/LilycoveCity/scripts.pory"
	.string "It was sixty years ago that my husband\n"
# 710 "data/maps/LilycoveCity/scripts.pory"
	.string "proposed to me here.\l"
# 711 "data/maps/LilycoveCity/scripts.pory"
	.string "The sea remains as beautiful as ever.\p"
# 712 "data/maps/LilycoveCity/scripts.pory"
	.string "Mufufufu mufufufufufu…$"
# 713 "data/maps/LilycoveCity/scripts.pory"

# 714 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TeamAquaRenovatedCavern:
# 715 "data/maps/LilycoveCity/scripts.pory"
	.string "Hm, you know of the peculiar cavern\n"
# 716 "data/maps/LilycoveCity/scripts.pory"
	.string "in this cove?\p"
# 717 "data/maps/LilycoveCity/scripts.pory"
	.string "That had been a natural formation,\n"
# 718 "data/maps/LilycoveCity/scripts.pory"
	.string "but then that TEAM AQUA lot came\l"
# 719 "data/maps/LilycoveCity/scripts.pory"
	.string "along and made their renovations.\p"
# 720 "data/maps/LilycoveCity/scripts.pory"
	.string "They call themselves\n"
# 721 "data/maps/LilycoveCity/scripts.pory"
	.string "the “nature-loving TEAM AQUA”!\p"
# 722 "data/maps/LilycoveCity/scripts.pory"
	.string "But what they do and what they say\n"
# 723 "data/maps/LilycoveCity/scripts.pory"
	.string "don't match at all!$"
# 724 "data/maps/LilycoveCity/scripts.pory"

# 725 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TeamAquaLotGoneForGood:
# 726 "data/maps/LilycoveCity/scripts.pory"
	.string "That cave in the cove…\p"
# 727 "data/maps/LilycoveCity/scripts.pory"
	.string "I didn't notice it right away,\n"
# 728 "data/maps/LilycoveCity/scripts.pory"
	.string "but it's completely empty now.\p"
# 729 "data/maps/LilycoveCity/scripts.pory"
	.string "That TEAM AQUA lot, they must\n"
# 730 "data/maps/LilycoveCity/scripts.pory"
	.string "have gone away for good.$"
# 731 "data/maps/LilycoveCity/scripts.pory"

# 732 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_CitySign:
# 733 "data/maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE CITY\p"
# 734 "data/maps/LilycoveCity/scripts.pory"
	.string "“Where the land ends and the\n"
# 735 "data/maps/LilycoveCity/scripts.pory"
	.string "sea begins.”$"
# 736 "data/maps/LilycoveCity/scripts.pory"

# 737 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ContestHallSign:
# 738 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéMON CONTEST HALL\n"
# 739 "data/maps/LilycoveCity/scripts.pory"
	.string "“The gathering place for TRAINERS!”$"
# 740 "data/maps/LilycoveCity/scripts.pory"

# 741 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MotelSign:
# 742 "data/maps/LilycoveCity/scripts.pory"
	.string "COVE LILY MOTEL\p"
# 743 "data/maps/LilycoveCity/scripts.pory"
	.string "“Remember us as COVE LILY of\n"
# 744 "data/maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE.”$"
# 745 "data/maps/LilycoveCity/scripts.pory"

# 746 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MuseumSign:
# 747 "data/maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE MUSEUM\p"
# 748 "data/maps/LilycoveCity/scripts.pory"
	.string "“POKéMON Masterpiece Collection\n"
# 749 "data/maps/LilycoveCity/scripts.pory"
	.string "on exhibit!”$"
# 750 "data/maps/LilycoveCity/scripts.pory"

# 751 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MuseumSignPlayersExhibit:
# 752 "data/maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE MUSEUM\p"
# 753 "data/maps/LilycoveCity/scripts.pory"
	.string "“{PLAYER}'s POKéMON Collection\n"
# 754 "data/maps/LilycoveCity/scripts.pory"
	.string "on exhibit!”$"
# 755 "data/maps/LilycoveCity/scripts.pory"

# 756 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HarborSignUnderConstruction:
# 757 "data/maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE CITY HARBOR\p"
# 758 "data/maps/LilycoveCity/scripts.pory"
	.string "“The ferry S.S. TIDAL is under\n"
# 759 "data/maps/LilycoveCity/scripts.pory"
	.string "construction in SLATEPORT CITY.\p"
# 760 "data/maps/LilycoveCity/scripts.pory"
	.string "“Service is scheduled to begin\n"
# 761 "data/maps/LilycoveCity/scripts.pory"
	.string "shortly.”$"
# 762 "data/maps/LilycoveCity/scripts.pory"

# 763 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HarborSign:
# 764 "data/maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE CITY HARBOR\p"
# 765 "data/maps/LilycoveCity/scripts.pory"
	.string "“Enjoy a delightful cruise on\n"
# 766 "data/maps/LilycoveCity/scripts.pory"
	.string "the ferry S.S. TIDAL.”$"
# 767 "data/maps/LilycoveCity/scripts.pory"

# 768 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TrainerFanClubSign:
# 769 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéMON TRAINER FAN CLUB\p"
# 770 "data/maps/LilycoveCity/scripts.pory"
	.string "The names of TRAINERS are scribbled\n"
# 771 "data/maps/LilycoveCity/scripts.pory"
	.string "all over the sign…$"
# 772 "data/maps/LilycoveCity/scripts.pory"

# 773 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_DepartmentStoreSign:
# 774 "data/maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE DEPARTMENT STORE\p"
# 775 "data/maps/LilycoveCity/scripts.pory"
	.string "“Overflowing with great merchandise\n"
# 776 "data/maps/LilycoveCity/scripts.pory"
	.string "and excitement!\p"
# 777 "data/maps/LilycoveCity/scripts.pory"
	.string "“A great place to find that something\n"
# 778 "data/maps/LilycoveCity/scripts.pory"
	.string "you need!”$"
# 779 "data/maps/LilycoveCity/scripts.pory"

# 780 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MoveDeletersHouseSign:
# 781 "data/maps/LilycoveCity/scripts.pory"
	.string "MOVE DELETER'S HOUSE\p"
# 782 "data/maps/LilycoveCity/scripts.pory"
	.string "“Unwanted POKéMON moves deleted.”$"
# 783 "data/maps/LilycoveCity/scripts.pory"

# 784 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_DoYouKnowAboutBerryBlender:
# 785 "data/maps/LilycoveCity/scripts.pory"
	.string "Do you know about the machine\n"
# 786 "data/maps/LilycoveCity/scripts.pory"
	.string "BERRY BLENDER?$"
# 787 "data/maps/LilycoveCity/scripts.pory"

# 788 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_FasterSpinBetterPokeblocks:
# 789 "data/maps/LilycoveCity/scripts.pory"
	.string "People have to work together to get it\n"
# 790 "data/maps/LilycoveCity/scripts.pory"
	.string "to spin faster.\p"
# 791 "data/maps/LilycoveCity/scripts.pory"
	.string "The faster you can make it spin, the\n"
# 792 "data/maps/LilycoveCity/scripts.pory"
	.string "better {POKEBLOCK}S you can get, I've heard.$"
# 793 "data/maps/LilycoveCity/scripts.pory"

# 794 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ExplainBerryBlender:
# 795 "data/maps/LilycoveCity/scripts.pory"
	.string "It's used for making a kind of candy\n"
# 796 "data/maps/LilycoveCity/scripts.pory"
	.string "called a {POKEBLOCK}.\p"
# 797 "data/maps/LilycoveCity/scripts.pory"
	.string "If you give a good {POKEBLOCK} to a POKéMON,\n"
# 798 "data/maps/LilycoveCity/scripts.pory"
	.string "its condition will improve by a lot.$"
# 799 "data/maps/LilycoveCity/scripts.pory"

# 800 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HeardTowerCalledSkyPillar:
# 801 "data/maps/LilycoveCity/scripts.pory"
	.string "I heard there's a tower somewhere out\n"
# 802 "data/maps/LilycoveCity/scripts.pory"
	.string "on the sea routes.\p"
# 803 "data/maps/LilycoveCity/scripts.pory"
	.string "It's called the SKY PILLAR, I hear.$"
# 804 "data/maps/LilycoveCity/scripts.pory"

# 805 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SawTallTowerOnRoute131:
# 806 "data/maps/LilycoveCity/scripts.pory"
	.string "I saw this tall tower somewhere\n"
# 807 "data/maps/LilycoveCity/scripts.pory"
	.string "around ROUTE 131.\p"
# 808 "data/maps/LilycoveCity/scripts.pory"
	.string "Could that possibly be…?$"
# 809 "data/maps/LilycoveCity/scripts.pory"

# 810 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_JustArrivedAndSawRarePokemon:
# 811 "data/maps/LilycoveCity/scripts.pory"
	.string "We just arrived here on our\n"
# 812 "data/maps/LilycoveCity/scripts.pory"
	.string "honeymoon vacation.\p"
# 813 "data/maps/LilycoveCity/scripts.pory"
	.string "We happened to see a DRAGON-type\n"
# 814 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéMON flying way up in the sky.\p"
# 815 "data/maps/LilycoveCity/scripts.pory"
	.string "Do cool POKéMON like that live in\n"
# 816 "data/maps/LilycoveCity/scripts.pory"
	.string "the HOENN region?$"
# 817 "data/maps/LilycoveCity/scripts.pory"

# 818 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HoneymoonVowToSeeRarePokemon:
# 819 "data/maps/LilycoveCity/scripts.pory"
	.string "On our honeymoon, we vowed to see as\n"
# 820 "data/maps/LilycoveCity/scripts.pory"
	.string "many rare POKéMON as we can.\p"
# 821 "data/maps/LilycoveCity/scripts.pory"
	.string "So we were delighted to see a rare\n"
# 822 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéMON as soon as we arrived.\p"
# 823 "data/maps/LilycoveCity/scripts.pory"
	.string "I mean, we are totally happy!$"
