# 1 "data/maps/FortreeCity_Gym/scripts.pory"

# 2 "data/maps/FortreeCity_Gym/scripts.pory"
.set LOCALID_DODUO, 9
# 3 "data/maps/FortreeCity_Gym/scripts.pory"

# 4 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_MapScripts::
# 5 "data/maps/FortreeCity_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_Gym_OnTransition
# 6 "data/maps/FortreeCity_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeCity_Gym_OnWarp
# 7 "data/maps/FortreeCity_Gym/scripts.pory"
	.byte 0
# 8 "data/maps/FortreeCity_Gym/scripts.pory"

# 9 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_OnTransition:
# 10 "data/maps/FortreeCity_Gym/scripts.pory"
	special RotatingGate_InitPuzzle
# 11 "data/maps/FortreeCity_Gym/scripts.pory"
	setflag FLAG_TEMP_HIDE_FOLLOWER @ Hide follower bc of rotating gates
# 12 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 13 "data/maps/FortreeCity_Gym/scripts.pory"

# 14 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_OnWarp:
# 15 "data/maps/FortreeCity_Gym/scripts.pory"
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, FortreeCity_Gym_EventScript_InitRotatingGates
# 16 "data/maps/FortreeCity_Gym/scripts.pory"
	.2byte 0
# 17 "data/maps/FortreeCity_Gym/scripts.pory"

# 18 "data/maps/FortreeCity_Gym/scripts.pory"
@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_3
# 19 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_InitRotatingGates::
# 20 "data/maps/FortreeCity_Gym/scripts.pory"
	special RotatingGate_InitPuzzleAndGraphics
# 21 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 22 "data/maps/FortreeCity_Gym/scripts.pory"

# 23 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_Winona::
# 24 "data/maps/FortreeCity_Gym/scripts.pory"
	playse SE_M_BATON_PASS
# 25 "data/maps/FortreeCity_Gym/scripts.pory"
	waitse
# 26 "data/maps/FortreeCity_Gym/scripts.pory"
	removeobject LOCALID_DODUO
# 27 "data/maps/FortreeCity_Gym/scripts.pory"
	setflag FLAG_HIDE_WINONAS_DODUO
# 28 "data/maps/FortreeCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaIntro, FortreeCity_Gym_Text_WinonaDefeat, FortreeCity_Gym_EventScript_WinonaDefeated, NO_MUSIC
# 29 "data/maps/FortreeCity_Gym/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 30 "data/maps/FortreeCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_Gym_EventScript_WinonaRematch
# 31 "data/maps/FortreeCity_Gym/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM_AERIAL_ACE, FortreeCity_Gym_EventScript_GiveAerialAce2
# 32 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_DEFAULT
# 33 "data/maps/FortreeCity_Gym/scripts.pory"
	release
# 34 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 35 "data/maps/FortreeCity_Gym/scripts.pory"

# 36 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_WinonaDefeated::
# 37 "data/maps/FortreeCity_Gym/scripts.pory"
	message FortreeCity_Gym_Text_ReceivedFeatherBadge
# 38 "data/maps/FortreeCity_Gym/scripts.pory"
	waitmessage
# 39 "data/maps/FortreeCity_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 40 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
# 41 "data/maps/FortreeCity_Gym/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 42 "data/maps/FortreeCity_Gym/scripts.pory"
	setflag FLAG_BADGE06_GET
# 43 "data/maps/FortreeCity_Gym/scripts.pory"
	setvar VAR_0x8008, 6
# 44 "data/maps/FortreeCity_Gym/scripts.pory"
	setvar VAR_GYM6_DEFEATED, 1
# 45 "data/maps/FortreeCity_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 46 "data/maps/FortreeCity_Gym/scripts.pory"
	call FortreeCity_Gym_EventScript_GiveAerialAce
# 47 "data/maps/FortreeCity_Gym/scripts.pory"
	closemessage
# 48 "data/maps/FortreeCity_Gym/scripts.pory"
	delay 30
# 49 "data/maps/FortreeCity_Gym/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 50 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_RegisteredWinona, MSGBOX_DEFAULT
# 51 "data/maps/FortreeCity_Gym/scripts.pory"
	waitfanfare
# 52 "data/maps/FortreeCity_Gym/scripts.pory"
	closemessage
# 53 "data/maps/FortreeCity_Gym/scripts.pory"
	delay 30
# 54 "data/maps/FortreeCity_Gym/scripts.pory"
	setflag FLAG_ENABLE_WINONA_MATCH_CALL
# 55 "data/maps/FortreeCity_Gym/scripts.pory"
	setvar VAR_SCOTT_FORTREE_CALL_STEP_COUNTER, 0
# 56 "data/maps/FortreeCity_Gym/scripts.pory"
	setflag FLAG_SCOTT_CALL_FORTREE_GYM
# 57 "data/maps/FortreeCity_Gym/scripts.pory"
	release
# 58 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 59 "data/maps/FortreeCity_Gym/scripts.pory"

# 60 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_GiveAerialAce2::
# 61 "data/maps/FortreeCity_Gym/scripts.pory"
	giveitem ITEM_TM_AIR_SLASH
# 62 "data/maps/FortreeCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 63 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
# 64 "data/maps/FortreeCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
# 65 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox Gym_Text_AlsoTakeThese, MSGBOX_DEFAULT
# 66 "data/maps/FortreeCity_Gym/scripts.pory"
	giveitem ITEM_BLANK_MINT, 3
# 67 "data/maps/FortreeCity_Gym/scripts.pory"
	giveitem ITEM_BOTTLE_CAP, 3
# 68 "data/maps/FortreeCity_Gym/scripts.pory"
	release
# 69 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 70 "data/maps/FortreeCity_Gym/scripts.pory"

# 71 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_GiveAerialAce::
# 72 "data/maps/FortreeCity_Gym/scripts.pory"
	giveitem ITEM_TM_AIR_SLASH
# 73 "data/maps/FortreeCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
# 74 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
# 75 "data/maps/FortreeCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
# 76 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox Gym_Text_AlsoTakeThese, MSGBOX_DEFAULT
# 77 "data/maps/FortreeCity_Gym/scripts.pory"
	giveitem ITEM_BLANK_MINT, 3
# 78 "data/maps/FortreeCity_Gym/scripts.pory"
	giveitem ITEM_BOTTLE_CAP, 3
# 79 "data/maps/FortreeCity_Gym/scripts.pory"
	return
# 80 "data/maps/FortreeCity_Gym/scripts.pory"

# 81 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_WinonaRematch::
# 82 "data/maps/FortreeCity_Gym/scripts.pory"
	trainerbattle_rematch_double TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaPreRematch, FortreeCity_Gym_Text_WinonaRematchDefeat, FortreeCity_Gym_Text_WinonaRematchNeedTwoMons
# 83 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_WinonaPostRematch, MSGBOX_AUTOCLOSE
# 84 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 85 "data/maps/FortreeCity_Gym/scripts.pory"

# 86 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_Jared::
# 87 "data/maps/FortreeCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_JARED, FortreeCity_Gym_Text_JaredIntro, FortreeCity_Gym_Text_JaredDefeat
# 88 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
# 89 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 90 "data/maps/FortreeCity_Gym/scripts.pory"

# 91 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_Edwardo::
# 92 "data/maps/FortreeCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_EDWARDO, FortreeCity_Gym_Text_EdwardoIntro, FortreeCity_Gym_Text_EdwardoDefeat
# 93 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_EdwardoPostBattle, MSGBOX_AUTOCLOSE
# 94 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 95 "data/maps/FortreeCity_Gym/scripts.pory"

# 96 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_Flint::
# 97 "data/maps/FortreeCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_FLINT, FortreeCity_Gym_Text_FlintIntro, FortreeCity_Gym_Text_FlintDefeat
# 98 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
# 99 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 100 "data/maps/FortreeCity_Gym/scripts.pory"

# 101 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_Ashley::
# 102 "data/maps/FortreeCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_ASHLEY, FortreeCity_Gym_Text_AshleyIntro, FortreeCity_Gym_Text_AshleyDefeat
# 103 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_AshleyPostBattle, MSGBOX_AUTOCLOSE
# 104 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 105 "data/maps/FortreeCity_Gym/scripts.pory"

# 106 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_Humberto::
# 107 "data/maps/FortreeCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_HUMBERTO, FortreeCity_Gym_Text_HumbertoIntro, FortreeCity_Gym_Text_HumbertoDefeat
# 108 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_HumbertoPostBattle, MSGBOX_AUTOCLOSE
# 109 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 110 "data/maps/FortreeCity_Gym/scripts.pory"

# 111 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_Darius::
# 112 "data/maps/FortreeCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_DARIUS, FortreeCity_Gym_Text_DariusIntro, FortreeCity_Gym_Text_DariusDefeat
# 113 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
# 114 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 115 "data/maps/FortreeCity_Gym/scripts.pory"

# 116 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_GymGuide::
# 117 "data/maps/FortreeCity_Gym/scripts.pory"
	lock
# 118 "data/maps/FortreeCity_Gym/scripts.pory"
	faceplayer
# 119 "data/maps/FortreeCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, FortreeCity_Gym_EventScript_GymGuidePostVictory
# 120 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
# 121 "data/maps/FortreeCity_Gym/scripts.pory"
	release
# 122 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 123 "data/maps/FortreeCity_Gym/scripts.pory"

# 124 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_GymGuidePostVictory::
# 125 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
# 126 "data/maps/FortreeCity_Gym/scripts.pory"
	release
# 127 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 128 "data/maps/FortreeCity_Gym/scripts.pory"

# 129 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_LeftGymStatue::
# 130 "data/maps/FortreeCity_Gym/scripts.pory"
	lockall
# 131 "data/maps/FortreeCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
# 132 "data/maps/FortreeCity_Gym/scripts.pory"
	goto FortreeCity_Gym_EventScript_GymStatue
# 133 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 134 "data/maps/FortreeCity_Gym/scripts.pory"

# 135 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_RightGymStatue::
# 136 "data/maps/FortreeCity_Gym/scripts.pory"
	lockall
# 137 "data/maps/FortreeCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
# 138 "data/maps/FortreeCity_Gym/scripts.pory"
	goto FortreeCity_Gym_EventScript_GymStatue
# 139 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 140 "data/maps/FortreeCity_Gym/scripts.pory"

# 141 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_GymStatueCertified::
# 142 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 143 "data/maps/FortreeCity_Gym/scripts.pory"
	releaseall
# 144 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 145 "data/maps/FortreeCity_Gym/scripts.pory"

# 146 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_GymStatue::
# 147 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 148 "data/maps/FortreeCity_Gym/scripts.pory"
	releaseall
# 149 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 150 "data/maps/FortreeCity_Gym/scripts.pory"

# 151 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_GymGuideAdvice:
# 152 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Yo, how's it going, CHAMPION-\n"
# 153 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "bound {PLAYER}?\p"
# 154 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "FORTREE GYM LEADER WINONA is\n"
# 155 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "a master of FLYING-type POKéMON.\p"
# 156 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "She's waiting at the back of this GYM,\n"
# 157 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "behind the rotating doors.\p"
# 158 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "She's waiting for new challengers\n"
# 159 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "who are trying to take wing!\p"
# 160 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Okay, go for it!$"
# 161 "data/maps/FortreeCity_Gym/scripts.pory"

# 162 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_GymGuidePostVictory:
# 163 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "You did it!\n"
# 164 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "You've achieved liftoff!$"
# 165 "data/maps/FortreeCity_Gym/scripts.pory"

# 166 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_JaredIntro:
# 167 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Behold the elegant battle style of\n"
# 168 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "BIRD POKéMON!$"
# 169 "data/maps/FortreeCity_Gym/scripts.pory"

# 170 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_JaredDefeat:
# 171 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "You…\n"
# 172 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "You're strong…$"
# 173 "data/maps/FortreeCity_Gym/scripts.pory"

# 174 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_JaredPostBattle:
# 175 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "A TRAINER has to be smart to keep\n"
# 176 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "up with unexpected turns of events.\p"
# 177 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Do you have the smarts to get to\n"
# 178 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "our LEADER?$"
# 179 "data/maps/FortreeCity_Gym/scripts.pory"

# 180 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_EdwardoIntro:
# 181 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "The lovers of BIRD POKéMON aspire\n"
# 182 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "to join this GYM.\p"
# 183 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "As a member of the FORTREE GYM,\n"
# 184 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "I'm not allowed to lose!$"
# 185 "data/maps/FortreeCity_Gym/scripts.pory"

# 186 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_EdwardoDefeat:
# 187 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "It was too much of a load for me\n"
# 188 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "to bear…$"
# 189 "data/maps/FortreeCity_Gym/scripts.pory"

# 190 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_EdwardoPostBattle:
# 191 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "The world is huge, and there are\n"
# 192 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "countless tough TRAINERS.\p"
# 193 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "I'm going to keep training and make\n"
# 194 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "myself even stronger.$"
# 195 "data/maps/FortreeCity_Gym/scripts.pory"

# 196 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_FlintIntro:
# 197 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "There's no need for WINONA, our GYM\n"
# 198 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "LEADER, to deal with you!\p"
# 199 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "I'm plenty good enough for you!$"
# 200 "data/maps/FortreeCity_Gym/scripts.pory"

# 201 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_FlintDefeat:
# 202 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "WINONA, I…\n"
# 203 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "I lost!$"
# 204 "data/maps/FortreeCity_Gym/scripts.pory"

# 205 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_FlintPostBattle:
# 206 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "WINONA is cute and she's strong.\n"
# 207 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "She's the ultimate LEADER!\p"
# 208 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Blush…$"
# 209 "data/maps/FortreeCity_Gym/scripts.pory"

# 210 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_AshleyIntro:
# 211 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "WINONA taught me personally!\n"
# 212 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "You can't beat me easily!$"
# 213 "data/maps/FortreeCity_Gym/scripts.pory"

# 214 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_AshleyDefeat:
# 215 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "I was beaten…$"
# 216 "data/maps/FortreeCity_Gym/scripts.pory"

# 217 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_AshleyPostBattle:
# 218 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Thanks to WINONA, the people of\n"
# 219 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "FORTREE can live without fear.$"
# 220 "data/maps/FortreeCity_Gym/scripts.pory"

# 221 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_HumbertoIntro:
# 222 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "When WINONA takes to battle, her face\n"
# 223 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "shines with beautiful determination…\p"
# 224 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "I'm not letting you witness that\n"
# 225 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "lovely sight!$"
# 226 "data/maps/FortreeCity_Gym/scripts.pory"

# 227 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_HumbertoDefeat:
# 228 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Urk!\n"
# 229 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "I couldn't stop you.$"
# 230 "data/maps/FortreeCity_Gym/scripts.pory"

# 231 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_HumbertoPostBattle:
# 232 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "You'd better watch it!\n"
# 233 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Don't get distracted staring at WINONA\l"
# 234 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "or you'll go crashing down in a heap!$"
# 235 "data/maps/FortreeCity_Gym/scripts.pory"

# 236 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_DariusIntro:
# 237 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "You'd better know that there are all\n"
# 238 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "sorts of FLYING-type POKéMON.\p"
# 239 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "You do know that, right?$"
# 240 "data/maps/FortreeCity_Gym/scripts.pory"

# 241 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_DariusDefeat:
# 242 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "You seem to know your stuff!$"
# 243 "data/maps/FortreeCity_Gym/scripts.pory"

# 244 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_DariusPostBattle:
# 245 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Sure, you beat me all right.\n"
# 246 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "But you'd better watch it! Our LEADER\l"
# 247 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "WINONA's POKéMON are all business.$"
# 248 "data/maps/FortreeCity_Gym/scripts.pory"

# 249 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_WinonaIntro:
# 250 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "I am WINONA. I am the LEADER of\n"
# 251 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "the FORTREE POKéMON GYM.\p"
# 252 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "I have become one with BIRD POKéMON\n"
# 253 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "and have soared the skies…\p"
# 254 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "However grueling the battle, we have\n"
# 255 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "triumphed with grace…\p"
# 256 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Witness the elegant choreography\n"
# 257 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "of BIRD POKéMON and I!$"
# 258 "data/maps/FortreeCity_Gym/scripts.pory"

# 259 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_WinonaDefeat:
# 260 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Never before have I seen a TRAINER\n"
# 261 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "command POKéMON with more grace\l"
# 262 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "than I…\p"
# 263 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "In recognition of your prowess,\n"
# 264 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "I present to you this GYM BADGE.$"
# 265 "data/maps/FortreeCity_Gym/scripts.pory"

# 266 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_ReceivedFeatherBadge:
# 267 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "{PLAYER} received the FEATHER BADGE\n"
# 268 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "from WINONA.$"
# 269 "data/maps/FortreeCity_Gym/scripts.pory"

# 270 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis:
# 271 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "With the FEATHER BADGE, all POKéMON up\n"
# 272 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "to LV 70, even those received through\l"
# 273 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "trades, will obey your every command.\p"
# 274 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "You will also be able to use\n"
# 275 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "the HM move FLY outside of battle.\p"
# 276 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "And this…\n"
# 277 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "This is a gift from me.$"
# 278 "data/maps/FortreeCity_Gym/scripts.pory"

# 279 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_ExplainAerialAce:
# 280 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "TM40 contains AIR SLASH.\p"
# 281 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Its an attack with a blade\n"
# 282 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "of air that may cause flinching.\p"
# 283 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "… … … … … …$"
# 284 "data/maps/FortreeCity_Gym/scripts.pory"

# 285 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_RegisteredWinona:
# 286 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Registered GYM LEADER WINONA\n"
# 287 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "in the POKéNAV.$"
# 288 "data/maps/FortreeCity_Gym/scripts.pory"

# 289 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_WinonaPostBattle:
# 290 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Though I fell to you, I will remain\n"
# 291 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "devoted to BIRD POKéMON.$"
# 292 "data/maps/FortreeCity_Gym/scripts.pory"

# 293 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_GymStatue:
# 294 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "FORTREE CITY POKéMON GYM$"
# 295 "data/maps/FortreeCity_Gym/scripts.pory"

# 296 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_GymStatueCertified:
# 297 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "FORTREE CITY POKéMON GYM\p"
# 298 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "WINONA'S CERTIFIED TRAINERS:\n"
# 299 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "{PLAYER}$"
# 300 "data/maps/FortreeCity_Gym/scripts.pory"

# 301 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_WinonaPreRematch:
# 302 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "WINONA: We humans can never escape\n"
# 303 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "gravity's pull on the ground.\p"
# 304 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "But by striving for excellence,\n"
# 305 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "we have the power to soar!\p"
# 306 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "You have scaled the pinnacle as\n"
# 307 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "the reigning CHAMPION.\p"
# 308 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Please, allow me to see your power\n"
# 309 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "at full flight!$"
# 310 "data/maps/FortreeCity_Gym/scripts.pory"

# 311 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_WinonaRematchDefeat:
# 312 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "I failed to reach your height again…$"
# 313 "data/maps/FortreeCity_Gym/scripts.pory"

# 314 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_WinonaPostRematch:
# 315 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "WINONA: Even though I have lost,\n"
# 316 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "the wings of my heart remain unbroken.\p"
# 317 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "I can rise and soar again and\n"
# 318 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "yet again.\p"
# 319 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "I am convinced of it!$"
# 320 "data/maps/FortreeCity_Gym/scripts.pory"

# 321 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_WinonaRematchNeedTwoMons:
# 322 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "WINONA: We humans can never escape\n"
# 323 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "gravity's pull on the ground.\p"
# 324 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "But by striving for excellence,\n"
# 325 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "we have the power to soar!\p"
# 326 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "You have scaled the pinnacle as\n"
# 327 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "the reigning CHAMPION.\p"
# 328 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Please, allow me to see your power\n"
# 329 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "at full flight!\p"
# 330 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Oh, no… Do you have but one\n"
# 331 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "POKéMON with you?\p"
# 332 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Please return with two POKéMON\n"
# 333 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "at the very least.$"
