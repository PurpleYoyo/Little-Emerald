EventScript_UseSurf::
	checkpartymove MOVE_SURF
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_EndUseSurf
	setfieldeffectargument 0, VAR_RESULT
	lockall
	dofieldeffect FLDEFF_USE_SURF
EventScript_ReleaseUseSurf::
	releaseall
EventScript_EndUseSurf::
	end
