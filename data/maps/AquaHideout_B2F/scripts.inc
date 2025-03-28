# 1 "data/maps/AquaHideout_B2F/scripts.pory"

# 2 "data/maps/AquaHideout_B2F/scripts.pory"
.set LOCALID_MATT, 1
# 3 "data/maps/AquaHideout_B2F/scripts.pory"
.set LOCALID_SUBMARINE, 4
# 4 "data/maps/AquaHideout_B2F/scripts.pory"
.set LOCALID_PORYGON, 7
# 5 "data/maps/AquaHideout_B2F/scripts.pory"

# 6 "data/maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_MapScripts::
# 7 "data/maps/AquaHideout_B2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B2F_OnTransition
# 8 "data/maps/AquaHideout_B2F/scripts.pory"
	.byte 0
# 9 "data/maps/AquaHideout_B2F/scripts.pory"

# 10 "data/maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_OnTransition:
# 11 "data/maps/AquaHideout_B2F/scripts.pory"
	call_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, AquaHideout_B2F_EventScript_PreventMattNoticing
# 12 "data/maps/AquaHideout_B2F/scripts.pory"
	end
# 13 "data/maps/AquaHideout_B2F/scripts.pory"

# 14 "data/maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_EventScript_PreventMattNoticing::
# 15 "data/maps/AquaHideout_B2F/scripts.pory"
	setvar VAR_TEMP_1, 1
# 16 "data/maps/AquaHideout_B2F/scripts.pory"
	return
# 17 "data/maps/AquaHideout_B2F/scripts.pory"

# 18 "data/maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_EventScript_MattNoticePlayer::
# 19 "data/maps/AquaHideout_B2F/scripts.pory"
	lockall
# 20 "data/maps/AquaHideout_B2F/scripts.pory"
	setvar VAR_0x8008, LOCALID_MATT
# 21 "data/maps/AquaHideout_B2F/scripts.pory"
	playse SE_PIN
# 22 "data/maps/AquaHideout_B2F/scripts.pory"
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 23 "data/maps/AquaHideout_B2F/scripts.pory"
	waitmovement 0
# 24 "data/maps/AquaHideout_B2F/scripts.pory"
	applymovement VAR_0x8008, Common_Movement_FacePlayer
# 25 "data/maps/AquaHideout_B2F/scripts.pory"
	waitmovement 0
# 26 "data/maps/AquaHideout_B2F/scripts.pory"
	setvar VAR_TEMP_1, 1
# 27 "data/maps/AquaHideout_B2F/scripts.pory"
	releaseall
# 28 "data/maps/AquaHideout_B2F/scripts.pory"
	end
# 29 "data/maps/AquaHideout_B2F/scripts.pory"

# 30 "data/maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_EventScript_Matt::
# 31 "data/maps/AquaHideout_B2F/scripts.pory"
	playse SE_M_BATON_PASS
# 32 "data/maps/AquaHideout_B2F/scripts.pory"
	waitse
# 33 "data/maps/AquaHideout_B2F/scripts.pory"
	removeobject LOCALID_PORYGON
# 34 "data/maps/AquaHideout_B2F/scripts.pory"
	setflag FLAG_HIDE_MATTS_PORYGON
# 35 "data/maps/AquaHideout_B2F/scripts.pory"
	call_if_unset FLAG_DEFEATED_FORTREE_GYM, AquaHideout_B2F_EventScript_Matt_PreWinona
# 36 "data/maps/AquaHideout_B2F/scripts.pory"
	call_if_set FLAG_DEFEATED_FORTREE_GYM, AquaHideout_B2F_EventScript_Matt_PostWinona
# 37 "data/maps/AquaHideout_B2F/scripts.pory"
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
# 38 "data/maps/AquaHideout_B2F/scripts.pory"
	release
# 39 "data/maps/AquaHideout_B2F/scripts.pory"
	end
# 40 "data/maps/AquaHideout_B2F/scripts.pory"

# 41 "data/maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_EventScript_Matt_PreWinona::
# 42 "data/maps/AquaHideout_B2F/scripts.pory"
	trainerbattle_single TRAINER_JUAN_4, AquaHideout_B2F_Text_MattIntro, AquaHideout_B2F_Text_MattDefeat, AquaHideout_B2F_EventScript_SubmarineEscape
# 43 "data/maps/AquaHideout_B2F/scripts.pory"
	return
# 44 "data/maps/AquaHideout_B2F/scripts.pory"

# 45 "data/maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_EventScript_Matt_PostWinona::
# 46 "data/maps/AquaHideout_B2F/scripts.pory"
	trainerbattle_single TRAINER_MATT, AquaHideout_B2F_Text_MattIntro, AquaHideout_B2F_Text_MattDefeat, AquaHideout_B2F_EventScript_SubmarineEscape
# 47 "data/maps/AquaHideout_B2F/scripts.pory"
	return
# 48 "data/maps/AquaHideout_B2F/scripts.pory"

# 49 "data/maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_EventScript_SubmarineEscape::
# 50 "data/maps/AquaHideout_B2F/scripts.pory"
	setvar VAR_0x8008, LOCALID_MATT
# 51 "data/maps/AquaHideout_B2F/scripts.pory"
	setvar VAR_0x8009, LOCALID_SUBMARINE
# 52 "data/maps/AquaHideout_B2F/scripts.pory"
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
# 53 "data/maps/AquaHideout_B2F/scripts.pory"
	waitmovement 0
# 54 "data/maps/AquaHideout_B2F/scripts.pory"
	delay 20
# 55 "data/maps/AquaHideout_B2F/scripts.pory"
	applymovement VAR_0x8008, Common_Movement_FacePlayer
# 56 "data/maps/AquaHideout_B2F/scripts.pory"
	waitmovement 0
# 57 "data/maps/AquaHideout_B2F/scripts.pory"
	msgbox AquaHideout_B2F_Text_OurBossGotThroughHisPreparations, MSGBOX_DEFAULT
# 58 "data/maps/AquaHideout_B2F/scripts.pory"
	closemessage
# 59 "data/maps/AquaHideout_B2F/scripts.pory"
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
# 60 "data/maps/AquaHideout_B2F/scripts.pory"
	applymovement VAR_0x8009, AquaHideout_B2F_Movement_SumbarineDepartLeft
# 61 "data/maps/AquaHideout_B2F/scripts.pory"
	waitmovement 0
# 62 "data/maps/AquaHideout_B2F/scripts.pory"
	removeobject VAR_0x8009
# 63 "data/maps/AquaHideout_B2F/scripts.pory"
	delay 20
# 64 "data/maps/AquaHideout_B2F/scripts.pory"
	applymovement VAR_0x8008, Common_Movement_FacePlayer
# 65 "data/maps/AquaHideout_B2F/scripts.pory"
	waitmovement 0
# 66 "data/maps/AquaHideout_B2F/scripts.pory"
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
# 67 "data/maps/AquaHideout_B2F/scripts.pory"
	setflag FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE
# 68 "data/maps/AquaHideout_B2F/scripts.pory"
	setflag FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS
# 69 "data/maps/AquaHideout_B2F/scripts.pory"
	release
# 70 "data/maps/AquaHideout_B2F/scripts.pory"
	end
# 71 "data/maps/AquaHideout_B2F/scripts.pory"

# 72 "data/maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Movement_SumbarineDepartLeft:
# 73 "data/maps/AquaHideout_B2F/scripts.pory"
	walk_left
# 74 "data/maps/AquaHideout_B2F/scripts.pory"
	walk_left
# 75 "data/maps/AquaHideout_B2F/scripts.pory"
	walk_left
# 76 "data/maps/AquaHideout_B2F/scripts.pory"
	walk_left
# 77 "data/maps/AquaHideout_B2F/scripts.pory"
	step_end
# 78 "data/maps/AquaHideout_B2F/scripts.pory"

# 79 "data/maps/AquaHideout_B2F/scripts.pory"
@ Unused
# 80 "data/maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Movement_SumbarineDepartRight:
# 81 "data/maps/AquaHideout_B2F/scripts.pory"
	walk_right
# 82 "data/maps/AquaHideout_B2F/scripts.pory"
	walk_right
# 83 "data/maps/AquaHideout_B2F/scripts.pory"
	walk_right
# 84 "data/maps/AquaHideout_B2F/scripts.pory"
	walk_right
# 85 "data/maps/AquaHideout_B2F/scripts.pory"
	step_end
# 86 "data/maps/AquaHideout_B2F/scripts.pory"

# 87 "data/maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_EventScript_Grunt4::
# 88 "data/maps/AquaHideout_B2F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_4, AquaHideout_B2F_Text_Grunt4Intro, AquaHideout_B2F_Text_Grunt4Defeat, AquaHideout_B2F_EventScript_Grunt4Defeated
# 89 "data/maps/AquaHideout_B2F/scripts.pory"
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
# 90 "data/maps/AquaHideout_B2F/scripts.pory"
	end
# 91 "data/maps/AquaHideout_B2F/scripts.pory"

# 92 "data/maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_EventScript_Grunt4Defeated::
# 93 "data/maps/AquaHideout_B2F/scripts.pory"
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_DEFAULT
# 94 "data/maps/AquaHideout_B2F/scripts.pory"
	release
# 95 "data/maps/AquaHideout_B2F/scripts.pory"
	end
# 96 "data/maps/AquaHideout_B2F/scripts.pory"

# 97 "data/maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_EventScript_Grunt6::
# 98 "data/maps/AquaHideout_B2F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_6, AquaHideout_B2F_Text_Grunt6Intro, AquaHideout_B2F_Text_Grunt6Defeat
# 99 "data/maps/AquaHideout_B2F/scripts.pory"
	msgbox AquaHideout_B2F_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
# 100 "data/maps/AquaHideout_B2F/scripts.pory"
	end
# 101 "data/maps/AquaHideout_B2F/scripts.pory"

# 102 "data/maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_EventScript_Grunt8::
# 103 "data/maps/AquaHideout_B2F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_8, AquaHideout_B2F_Text_Grunt8Intro, AquaHideout_B2F_Text_Grunt8Defeat
# 104 "data/maps/AquaHideout_B2F/scripts.pory"
	msgbox AquaHideout_B2F_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
# 105 "data/maps/AquaHideout_B2F/scripts.pory"
	end
# 106 "data/maps/AquaHideout_B2F/scripts.pory"

# 107 "data/maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_MattIntro:
# 108 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "Huhuhu…\p"
# 109 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "Got here already, did you?\n"
# 110 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "We underestimated you!\p"
# 111 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "But this is it!\p"
# 112 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "I'm a cut above the GRUNTS you've seen\n"
# 113 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "so far.\p"
# 114 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "I'm not stalling for time.\n"
# 115 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "I'm going to pulverize you!$"
# 116 "data/maps/AquaHideout_B2F/scripts.pory"

# 117 "data/maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_MattDefeat:
# 118 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "Huhuhu…\n"
# 119 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "So, I lost, too…$"
# 120 "data/maps/AquaHideout_B2F/scripts.pory"

# 121 "data/maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_OurBossGotThroughHisPreparations:
# 122 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "Huhuhu!\p"
# 123 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "While I was toying with you, our BOSS\n"
# 124 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "got through his preparations!$"
# 125 "data/maps/AquaHideout_B2F/scripts.pory"

# 126 "data/maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_MattPostBattle:
# 127 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "Huhuhu!\p"
# 128 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "Our BOSS has already gone on his way to\n"
# 129 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "some cave under the sea!\p"
# 130 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "If you're going to give chase, you'd\n"
# 131 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "better search the big, wide sea beyond\l"
# 132 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "LILYCOVE.\p"
# 133 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "But will you find it then?\n"
# 134 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "Hehehe!$"
# 135 "data/maps/AquaHideout_B2F/scripts.pory"

# 136 "data/maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_Grunt4Intro:
# 137 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "Wahahah, I grew weary of waiting!\n"
# 138 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "You owe me a battle, too!$"
# 139 "data/maps/AquaHideout_B2F/scripts.pory"

# 140 "data/maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_Grunt4Defeat:
# 141 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "Tired of waiting…\n"
# 142 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "Lost and dazed…$"
# 143 "data/maps/AquaHideout_B2F/scripts.pory"

# 144 "data/maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_Grunt4PostBattle:
# 145 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "BOSS…\n"
# 146 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "Is this good enough?$"
# 147 "data/maps/AquaHideout_B2F/scripts.pory"

# 148 "data/maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_Grunt6Intro:
# 149 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "Warp panels, the HIDEOUT's pride\n"
# 150 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "and joy!\p"
# 151 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "You're clueless about where you are,\n"
# 152 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "aren't you?\p"
# 153 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "Fluster and tire out the enemy, then\n"
# 154 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "lower the boom! That's our plan!$"
# 155 "data/maps/AquaHideout_B2F/scripts.pory"

# 156 "data/maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_Grunt6Defeat:
# 157 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "What's wrong with you?\n"
# 158 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "You're not tired at all!$"
# 159 "data/maps/AquaHideout_B2F/scripts.pory"

# 160 "data/maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_Grunt6PostBattle:
# 161 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "That reminds me… I can't remember\n"
# 162 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "where I put the MASTER BALL.\p"
# 163 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "If I fail to guard it, our BOSS will\n"
# 164 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "chew me out…$"
# 165 "data/maps/AquaHideout_B2F/scripts.pory"

# 166 "data/maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_Grunt8Intro:
# 167 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "When I joined TEAM AQUA, the first\n"
# 168 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "thing I had to learn was how these\l"
# 169 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "warp panels connected.$"
# 170 "data/maps/AquaHideout_B2F/scripts.pory"

# 171 "data/maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_Grunt8Defeat:
# 172 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "I was too occupied thinking about\n"
# 173 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "the warp panels…$"
# 174 "data/maps/AquaHideout_B2F/scripts.pory"

# 175 "data/maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_Grunt8PostBattle:
# 176 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "I'll have to learn about how I can\n"
# 177 "data/maps/AquaHideout_B2F/scripts.pory"
	.string "battle more effectively…$"
