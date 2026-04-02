# 1 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 2 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
.set LOCALID_MOVE_RELEARNER, 1
# 3 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 4 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.align 2
# 5 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FossilPokemart:
# 6 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_DOME_FOSSIL
# 7 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_HELIX_FOSSIL
# 8 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_ROOT_FOSSIL
# 9 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_CLAW_FOSSIL
# 10 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_ARMOR_FOSSIL
# 11 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_SKULL_FOSSIL
# 12 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_COVER_FOSSIL
# 13 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_PLUME_FOSSIL
# 14 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_JAW_FOSSIL
# 15 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_SAIL_FOSSIL
# 16 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	pokemartlistend
# 17 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 18 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_MapScripts::
# 19 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.byte 0
# 20 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 21 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_EventScript_MoveRelearner::
# 22 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	lockall
# 23 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	applymovement LOCALID_MOVE_RELEARNER, Common_Movement_FacePlayer
# 24 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	waitmovement 0
# 25 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_set FLAG_TEMP_1, FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
# 26 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor, MSGBOX_DEFAULT
# 27 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setflag FLAG_TEMP_1
# 28 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
# 29 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 30 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 31 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove::
# 32 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	checkitem ITEM_HEART_SCALE
# 33 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
# 34 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove, MSGBOX_YESNO
# 35 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	switch VAR_RESULT
# 36 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case NO, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
# 37 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
# 38 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 39 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 40 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon::
# 41 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon, MSGBOX_DEFAULT
# 42 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	special ChooseMonForMoveRelearner
# 43 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	waitstate
# 44 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
# 45 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	special IsSelectedMonEgg
# 46 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg
# 47 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_eq VAR_0x8005, 0, FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon
# 48 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMove
# 49 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 50 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 51 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_EventScript_ChooseMove::
# 52 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove, MSGBOX_DEFAULT
# 53 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	special TeachMoveRelearnerMove
# 54 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	waitstate
# 55 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_eq VAR_0x8004, 0, FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
# 56 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale, MSGBOX_DEFAULT
# 57 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	removeitem ITEM_HEART_SCALE
# 58 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
# 59 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 60 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 61 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon::
# 62 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
# 63 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
# 64 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 65 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 66 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg::
# 67 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg, MSGBOX_DEFAULT
# 68 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
# 69 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 70 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 71 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale::
# 72 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
# 73 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	releaseall
# 74 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 75 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 76 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor:
# 77 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "I'm the MOVE TUTOR.\p"
# 78 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "I know all the moves that POKéMON\n"
# 79 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "learn--every one of them--and I can\l"
# 80 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "teach POKéMON those moves.\p"
# 81 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "I can teach a move to a POKéMON\n"
# 82 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "of yours if you'd like.\p"
# 83 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "I'll do it for a HEART SCALE.\n"
# 84 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "I'm collecting those now.$"
# 85 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 86 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove:
# 87 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Oh! That's it! That's an honest to\n"
# 88 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "goodness HEART SCALE!\p"
# 89 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Let me guess, you want me to teach\n"
# 90 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "a move?$"
# 91 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 92 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon:
# 93 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Which POKéMON needs tutoring?$"
# 94 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 95 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove:
# 96 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Which move should I teach?$"
# 97 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 98 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon:
# 99 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Sorry…\p"
# 100 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "It doesn't appear as if I have any move\n"
# 101 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "I can teach that POKéMON.$"
# 102 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 103 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale:
# 104 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "{PLAYER} handed over one HEART SCALE\n"
# 105 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "in exchange.$"
# 106 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 107 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale:
# 108 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "If your POKéMON need to learn a move,\n"
# 109 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "come back with a HEART SCALE.$"
# 110 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 111 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg:
# 112 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Hunh? There isn't a single move that\n"
# 113 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "I can teach an EGG.$"
