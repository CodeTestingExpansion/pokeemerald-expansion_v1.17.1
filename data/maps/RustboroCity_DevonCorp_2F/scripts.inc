RustboroCity_DevonCorp_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_2F_OnTransition
	.byte 0

RustboroCity_DevonCorp_2F_OnTransition:
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	end

RustboroCity_DevonCorp_2F_EventScript_SetFossilReady::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 2
	return

RustboroCity_DevonCorp_2F_EventScript_TalkToPokemonScientist::
	lock
	faceplayer
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	msgbox RustboroCity_DevonCorp_2F_Text_DeviceForTalkingToPokemon, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_BallScientist::
	lock
	faceplayer
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, RustboroCity_DevonCorp_2F_EventScript_DevelopedBalls
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopingNewBalls, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_DevelopedBalls::
	msgbox RustboroCity_DevonCorp_2F_Text_WeFinallyMadeNewBalls, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_PokenavScientist::
	lock
	faceplayer
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_DevonCorp_2F_EventScript_HasPokenav
	msgbox RustboroCity_DevonCorp_2F_Text_IMadePokenav, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_HasPokenav::
	msgbox RustboroCity_DevonCorp_2F_Text_WowThatsAPokenav, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_PokemonDreamsScientist::
	lock
	faceplayer
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	msgbox RustboroCity_DevonCorp_2F_Text_DeviceToVisualizePokemonDreams, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_FossilScientist::
	lock
	faceplayer
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 2, RustboroCity_DevonCorp_2F_EventScript_FossilMonReady
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_StillRegenerating
	goto_if_set FLAG_RECEIVED_REVIVED_FOSSIL_MON, RustboroCity_DevonCorp_2F_EventScript_AskToRegenerateAnotherFossil
	setvar VAR_TEMP_2, 0
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopDeviceToResurrectFossils, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_CheckAvailableFossils
	end

RustboroCity_DevonCorp_2F_EventScript_AskToRegenerateAnotherFossil::
	msgbox RustboroCity_DevonCorp_2F_Text_AskToRegenerateAnotherFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil
	setvar VAR_TEMP_2, 1

RustboroCity_DevonCorp_2F_EventScript_CheckAvailableFossils::
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeRootFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeClawFossil
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeHelixFossil
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeDomeFossil
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeOldAmber
	checkitem ITEM_SKULL_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeSkullFossil
	checkitem ITEM_ARMOR_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeArmorFossil
	checkitem ITEM_COVER_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeCoverFossil
	checkitem ITEM_PLUME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticePlumeFossil
	checkitem ITEM_JAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeJawFossil
	checkitem ITEM_SAIL_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeSailFossil
	checkitem ITEM_FOSSILIZED_BIRD
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeFossilizedBird
	checkitem ITEM_FOSSILIZED_FISH
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeFossilizedFish
	checkitem ITEM_FOSSILIZED_DRAKE
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeFossilizedDrake
	checkitem ITEM_FOSSILIZED_DINO
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeFossilizedDino
	goto_if_eq VAR_TEMP_2, 1, RustboroCity_DevonCorp_2F_EventScript_NoFossilsToRegenerate
	release
	end

RustboroCity_DevonCorp_2F_EventScript_NoFossilsToRegenerate::
	msgbox RustboroCity_DevonCorp_2F_Text_NoFossilsToRegenerate, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_NoticeRootFossil::
	setvar VAR_TEMP_1, 1
	goto RustboroCity_DevonCorp_2F_EventScript_NoticeFossil

RustboroCity_DevonCorp_2F_EventScript_NoticeClawFossil::
	setvar VAR_TEMP_1, 2
	goto RustboroCity_DevonCorp_2F_EventScript_NoticeFossil

RustboroCity_DevonCorp_2F_EventScript_NoticeHelixFossil::
	setvar VAR_TEMP_1, 3
	goto RustboroCity_DevonCorp_2F_EventScript_NoticeFossil

RustboroCity_DevonCorp_2F_EventScript_NoticeDomeFossil::
	setvar VAR_TEMP_1, 4
	goto RustboroCity_DevonCorp_2F_EventScript_NoticeFossil

RustboroCity_DevonCorp_2F_EventScript_NoticeOldAmber::
	setvar VAR_TEMP_1, 5
	goto RustboroCity_DevonCorp_2F_EventScript_NoticeFossil

RustboroCity_DevonCorp_2F_EventScript_NoticeSkullFossil::
	setvar VAR_TEMP_1, 6
	goto RustboroCity_DevonCorp_2F_EventScript_NoticeFossil

RustboroCity_DevonCorp_2F_EventScript_NoticeArmorFossil::
	setvar VAR_TEMP_1, 7
	goto RustboroCity_DevonCorp_2F_EventScript_NoticeFossil

RustboroCity_DevonCorp_2F_EventScript_NoticeCoverFossil::
	setvar VAR_TEMP_1, 8
	goto RustboroCity_DevonCorp_2F_EventScript_NoticeFossil

RustboroCity_DevonCorp_2F_EventScript_NoticePlumeFossil::
	setvar VAR_TEMP_1, 9
	goto RustboroCity_DevonCorp_2F_EventScript_NoticeFossil

RustboroCity_DevonCorp_2F_EventScript_NoticeJawFossil::
	setvar VAR_TEMP_1, 10
	goto RustboroCity_DevonCorp_2F_EventScript_NoticeFossil

RustboroCity_DevonCorp_2F_EventScript_NoticeSailFossil::
	setvar VAR_TEMP_1, 11
	goto RustboroCity_DevonCorp_2F_EventScript_NoticeFossil

RustboroCity_DevonCorp_2F_EventScript_NoticeFossilizedBird::
	setvar VAR_TEMP_1, 12
	goto RustboroCity_DevonCorp_2F_EventScript_NoticeFossil

RustboroCity_DevonCorp_2F_EventScript_NoticeFossilizedFish::
	setvar VAR_TEMP_1, 13
	goto RustboroCity_DevonCorp_2F_EventScript_NoticeFossil

RustboroCity_DevonCorp_2F_EventScript_NoticeFossilizedDrake::
	setvar VAR_TEMP_1, 14
	goto RustboroCity_DevonCorp_2F_EventScript_NoticeFossil

RustboroCity_DevonCorp_2F_EventScript_NoticeFossilizedDino::
	setvar VAR_TEMP_1, 15
	goto RustboroCity_DevonCorp_2F_EventScript_NoticeFossil

RustboroCity_DevonCorp_2F_EventScript_NoticeFossil::
	goto_if_eq VAR_TEMP_2, 1, RustboroCity_DevonCorp_2F_EventScript_ChooseAnotherFossil
	closemessage
	playse SE_PIN
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil
	msgbox RustboroCity_DevonCorp_2F_Text_TwoFossilsPickOne, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	end

RustboroCity_DevonCorp_2F_EventScript_ChooseAnotherFossil::
	msgbox RustboroCity_DevonCorp_2F_Text_TwoFossilsPickOne, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	end

RustboroCity_DevonCorp_2F_EventScript_VerifyFossil::
	goto_if_eq VAR_TEMP_1, 1, RustboroCity_DevonCorp_2F_EventScript_VerifyRootFossil
	goto_if_eq VAR_TEMP_1, 2, RustboroCity_DevonCorp_2F_EventScript_VerifyClawFossil
	goto_if_eq VAR_TEMP_1, 3, RustboroCity_DevonCorp_2F_EventScript_VerifyHelixFossil
	goto_if_eq VAR_TEMP_1, 4, RustboroCity_DevonCorp_2F_EventScript_VerifyDomeFossil
	goto_if_eq VAR_TEMP_1, 5, RustboroCity_DevonCorp_2F_EventScript_VerifyOldAmber
	goto_if_eq VAR_TEMP_1, 6, RustboroCity_DevonCorp_2F_EventScript_VerifySkullFossil
	goto_if_eq VAR_TEMP_1, 7, RustboroCity_DevonCorp_2F_EventScript_VerifyArmorFossil
	goto_if_eq VAR_TEMP_1, 8, RustboroCity_DevonCorp_2F_EventScript_VerifyCoverFossil
	goto_if_eq VAR_TEMP_1, 9, RustboroCity_DevonCorp_2F_EventScript_VerifyPlumeFossil
	goto_if_eq VAR_TEMP_1, 10, RustboroCity_DevonCorp_2F_EventScript_VerifyJawFossil
	goto_if_eq VAR_TEMP_1, 11, RustboroCity_DevonCorp_2F_EventScript_VerifySailFossil
	goto_if_eq VAR_TEMP_1, 12, RustboroCity_DevonCorp_2F_EventScript_VerifyFossilizedBird
	goto_if_eq VAR_TEMP_1, 13, RustboroCity_DevonCorp_2F_EventScript_VerifyFossilizedFish
	goto_if_eq VAR_TEMP_1, 14, RustboroCity_DevonCorp_2F_EventScript_VerifyFossilizedDrake
	goto_if_eq VAR_TEMP_1, 15, RustboroCity_DevonCorp_2F_EventScript_VerifyFossilizedDino
	end

RustboroCity_DevonCorp_2F_EventScript_VerifyRootFossil::
	checkitem ITEM_ROOT_FOSSIL
	goto RustboroCity_DevonCorp_2F_EventScript_CheckSelectedFossil
	end

RustboroCity_DevonCorp_2F_EventScript_VerifyClawFossil::
	checkitem ITEM_CLAW_FOSSIL
	goto RustboroCity_DevonCorp_2F_EventScript_CheckSelectedFossil
	end

RustboroCity_DevonCorp_2F_EventScript_VerifyHelixFossil::
	checkitem ITEM_HELIX_FOSSIL
	goto RustboroCity_DevonCorp_2F_EventScript_CheckSelectedFossil
	end

RustboroCity_DevonCorp_2F_EventScript_VerifyDomeFossil::
	checkitem ITEM_DOME_FOSSIL
	goto RustboroCity_DevonCorp_2F_EventScript_CheckSelectedFossil
	end

RustboroCity_DevonCorp_2F_EventScript_VerifyOldAmber::
	checkitem ITEM_OLD_AMBER
	goto RustboroCity_DevonCorp_2F_EventScript_CheckSelectedFossil
	end

RustboroCity_DevonCorp_2F_EventScript_VerifySkullFossil::
	checkitem ITEM_SKULL_FOSSIL
	goto RustboroCity_DevonCorp_2F_EventScript_CheckSelectedFossil
	end

RustboroCity_DevonCorp_2F_EventScript_VerifyArmorFossil::
	checkitem ITEM_ARMOR_FOSSIL
	goto RustboroCity_DevonCorp_2F_EventScript_CheckSelectedFossil
	end

RustboroCity_DevonCorp_2F_EventScript_VerifyCoverFossil::
	checkitem ITEM_COVER_FOSSIL
	goto RustboroCity_DevonCorp_2F_EventScript_CheckSelectedFossil
	end

RustboroCity_DevonCorp_2F_EventScript_VerifyPlumeFossil::
	checkitem ITEM_PLUME_FOSSIL
	goto RustboroCity_DevonCorp_2F_EventScript_CheckSelectedFossil
	end

RustboroCity_DevonCorp_2F_EventScript_VerifyJawFossil::
	checkitem ITEM_JAW_FOSSIL
	goto RustboroCity_DevonCorp_2F_EventScript_CheckSelectedFossil
	end

RustboroCity_DevonCorp_2F_EventScript_VerifySailFossil::
	checkitem ITEM_SAIL_FOSSIL
	goto RustboroCity_DevonCorp_2F_EventScript_CheckSelectedFossil
	end

RustboroCity_DevonCorp_2F_EventScript_VerifyFossilizedBird::
	checkitem ITEM_FOSSILIZED_BIRD
	goto RustboroCity_DevonCorp_2F_EventScript_CheckSelectedFossil
	end

RustboroCity_DevonCorp_2F_EventScript_VerifyFossilizedFish::
	checkitem ITEM_FOSSILIZED_FISH
	goto RustboroCity_DevonCorp_2F_EventScript_CheckSelectedFossil
	end

RustboroCity_DevonCorp_2F_EventScript_VerifyFossilizedDrake::
	checkitem ITEM_FOSSILIZED_DRAKE
	goto RustboroCity_DevonCorp_2F_EventScript_CheckSelectedFossil
	end

RustboroCity_DevonCorp_2F_EventScript_VerifyFossilizedDino::
	checkitem ITEM_FOSSILIZED_DINO
	goto RustboroCity_DevonCorp_2F_EventScript_CheckSelectedFossil
	end

RustboroCity_DevonCorp_2F_EventScript_CheckSelectedFossil::
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_GiveFossil
	msgbox RustboroCity_DevonCorp_2F_Text_DontHaveSelectedFossil, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	end

RustboroCity_DevonCorp_2F_EventScript_GiveFossil::
	goto_if_eq VAR_TEMP_1, 1, RustboroCity_DevonCorp_2F_EventScript_GiveRootFossil
	goto_if_eq VAR_TEMP_1, 2, RustboroCity_DevonCorp_2F_EventScript_GiveClawFossil
	goto_if_eq VAR_TEMP_1, 3, RustboroCity_DevonCorp_2F_EventScript_GiveHelixFossil
	goto_if_eq VAR_TEMP_1, 4, RustboroCity_DevonCorp_2F_EventScript_GiveDomeFossil
	goto_if_eq VAR_TEMP_1, 5, RustboroCity_DevonCorp_2F_EventScript_GiveOldAmber
	goto_if_eq VAR_TEMP_1, 6, RustboroCity_DevonCorp_2F_EventScript_GiveSkullFossil
	goto_if_eq VAR_TEMP_1, 7, RustboroCity_DevonCorp_2F_EventScript_GiveArmorFossil
	goto_if_eq VAR_TEMP_1, 8, RustboroCity_DevonCorp_2F_EventScript_GiveCoverFossil
	goto_if_eq VAR_TEMP_1, 9, RustboroCity_DevonCorp_2F_EventScript_GivePlumeFossil
	goto_if_eq VAR_TEMP_1, 10, RustboroCity_DevonCorp_2F_EventScript_GiveJawFossil
	goto_if_eq VAR_TEMP_1, 11, RustboroCity_DevonCorp_2F_EventScript_GiveSailFossil
	goto_if_eq VAR_TEMP_1, 12, RustboroCity_DevonCorp_2F_EventScript_GiveFossilizedBird
	goto_if_eq VAR_TEMP_1, 13, RustboroCity_DevonCorp_2F_EventScript_GiveFossilizedFish
	goto_if_eq VAR_TEMP_1, 14, RustboroCity_DevonCorp_2F_EventScript_GiveFossilizedDrake
	goto_if_eq VAR_TEMP_1, 15, RustboroCity_DevonCorp_2F_EventScript_GiveFossilizedDino
	end

RustboroCity_DevonCorp_2F_EventScript_GiveRootFossil::
	bufferitemname STR_VAR_1, ITEM_ROOT_FOSSIL
	removeitem ITEM_ROOT_FOSSIL
	goto RustboroCity_DevonCorp_2F_EventScript_CompleteGivingFossil
	end

RustboroCity_DevonCorp_2F_EventScript_GiveClawFossil::
	bufferitemname STR_VAR_1, ITEM_CLAW_FOSSIL
	removeitem ITEM_CLAW_FOSSIL
	goto RustboroCity_DevonCorp_2F_EventScript_CompleteGivingFossil
	end

RustboroCity_DevonCorp_2F_EventScript_GiveHelixFossil::
	bufferitemname STR_VAR_1, ITEM_HELIX_FOSSIL
	removeitem ITEM_HELIX_FOSSIL
	goto RustboroCity_DevonCorp_2F_EventScript_CompleteGivingFossil
	end

RustboroCity_DevonCorp_2F_EventScript_GiveDomeFossil::
	bufferitemname STR_VAR_1, ITEM_DOME_FOSSIL
	removeitem ITEM_DOME_FOSSIL
	goto RustboroCity_DevonCorp_2F_EventScript_CompleteGivingFossil
	end

RustboroCity_DevonCorp_2F_EventScript_GiveOldAmber::
	bufferitemname STR_VAR_1, ITEM_OLD_AMBER
	removeitem ITEM_OLD_AMBER
	goto RustboroCity_DevonCorp_2F_EventScript_CompleteGivingFossil
	end

RustboroCity_DevonCorp_2F_EventScript_GiveSkullFossil::
	bufferitemname STR_VAR_1, ITEM_SKULL_FOSSIL
	removeitem ITEM_SKULL_FOSSIL
	goto RustboroCity_DevonCorp_2F_EventScript_CompleteGivingFossil
	end

RustboroCity_DevonCorp_2F_EventScript_GiveArmorFossil::
	bufferitemname STR_VAR_1, ITEM_ARMOR_FOSSIL
	removeitem ITEM_ARMOR_FOSSIL
	goto RustboroCity_DevonCorp_2F_EventScript_CompleteGivingFossil
	end

RustboroCity_DevonCorp_2F_EventScript_GiveCoverFossil::
	bufferitemname STR_VAR_1, ITEM_COVER_FOSSIL
	removeitem ITEM_COVER_FOSSIL
	goto RustboroCity_DevonCorp_2F_EventScript_CompleteGivingFossil
	end

RustboroCity_DevonCorp_2F_EventScript_GivePlumeFossil::
	bufferitemname STR_VAR_1, ITEM_PLUME_FOSSIL
	removeitem ITEM_PLUME_FOSSIL
	goto RustboroCity_DevonCorp_2F_EventScript_CompleteGivingFossil
	end

RustboroCity_DevonCorp_2F_EventScript_GiveJawFossil::
	bufferitemname STR_VAR_1, ITEM_JAW_FOSSIL
	removeitem ITEM_JAW_FOSSIL
	goto RustboroCity_DevonCorp_2F_EventScript_CompleteGivingFossil
	end

RustboroCity_DevonCorp_2F_EventScript_GiveSailFossil::
	bufferitemname STR_VAR_1, ITEM_SAIL_FOSSIL
	removeitem ITEM_SAIL_FOSSIL
	goto RustboroCity_DevonCorp_2F_EventScript_CompleteGivingFossil
	end

RustboroCity_DevonCorp_2F_EventScript_GiveFossilizedBird::
	bufferitemname STR_VAR_1, ITEM_FOSSILIZED_BIRD
	removeitem ITEM_FOSSILIZED_BIRD
	goto RustboroCity_DevonCorp_2F_EventScript_CompleteGivingFossil
	end

RustboroCity_DevonCorp_2F_EventScript_GiveFossilizedFish::
	bufferitemname STR_VAR_1, ITEM_FOSSILIZED_FISH
	removeitem ITEM_FOSSILIZED_FISH
	goto RustboroCity_DevonCorp_2F_EventScript_CompleteGivingFossil
	end

RustboroCity_DevonCorp_2F_EventScript_GiveFossilizedDrake::
	bufferitemname STR_VAR_1, ITEM_FOSSILIZED_DRAKE
	removeitem ITEM_FOSSILIZED_DRAKE
	goto RustboroCity_DevonCorp_2F_EventScript_CompleteGivingFossil
	end

RustboroCity_DevonCorp_2F_EventScript_GiveFossilizedDino::
	bufferitemname STR_VAR_1, ITEM_FOSSILIZED_DINO
	removeitem ITEM_FOSSILIZED_DINO
	goto RustboroCity_DevonCorp_2F_EventScript_CompleteGivingFossil
	end

RustboroCity_DevonCorp_2F_EventScript_CompleteGivingFossil::
	msgbox RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	copyvar VAR_WHICH_FOSSIL_REVIVED, VAR_TEMP_1
	release
	end

RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil::
	msgbox RustboroCity_DevonCorp_2F_Text_OhIsThatSo, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_StillRegenerating::
	msgbox RustboroCity_DevonCorp_2F_Text_FossilRegeneratorTakesTime, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_FossilMonReady::
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 1, RustboroCity_DevonCorp_2F_EventScript_SetReadyLileep
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 2, RustboroCity_DevonCorp_2F_EventScript_SetReadyAnorith
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 3, RustboroCity_DevonCorp_2F_EventScript_SetReadyOmanyte
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 4, RustboroCity_DevonCorp_2F_EventScript_SetReadyKabuto
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 5, RustboroCity_DevonCorp_2F_EventScript_SetReadyAerodactyl
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 6, RustboroCity_DevonCorp_2F_EventScript_SetReadyCranidos
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 7, RustboroCity_DevonCorp_2F_EventScript_SetReadyShieldon
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 8, RustboroCity_DevonCorp_2F_EventScript_SetReadyTirtouga
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 9, RustboroCity_DevonCorp_2F_EventScript_SetReadyArchen
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 10, RustboroCity_DevonCorp_2F_EventScript_SetReadyTyrunt
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 11, RustboroCity_DevonCorp_2F_EventScript_SetReadyAmaura
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 12, RustboroCity_DevonCorp_2F_EventScript_SetReadyArctozolt
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 13, RustboroCity_DevonCorp_2F_EventScript_SetReadyArctovish
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 14, RustboroCity_DevonCorp_2F_EventScript_SetReadyDracovish
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 15, RustboroCity_DevonCorp_2F_EventScript_SetReadyDracozolt
	end

RustboroCity_DevonCorp_2F_EventScript_SetReadyLileep::
	setvar VAR_TEMP_1, SPECIES_LILEEP
	goto RustboroCity_DevonCorp_2F_EventScript_ReadyFossilMon
	end

RustboroCity_DevonCorp_2F_EventScript_SetReadyAnorith::
	setvar VAR_TEMP_1, SPECIES_ANORITH
	goto RustboroCity_DevonCorp_2F_EventScript_ReadyFossilMon
	end

RustboroCity_DevonCorp_2F_EventScript_SetReadyOmanyte::
	setvar VAR_TEMP_1, SPECIES_OMANYTE
	goto RustboroCity_DevonCorp_2F_EventScript_ReadyFossilMon
	end

RustboroCity_DevonCorp_2F_EventScript_SetReadyKabuto::
	setvar VAR_TEMP_1, SPECIES_KABUTO
	goto RustboroCity_DevonCorp_2F_EventScript_ReadyFossilMon
	end

RustboroCity_DevonCorp_2F_EventScript_SetReadyAerodactyl::
	setvar VAR_TEMP_1, SPECIES_AERODACTYL
	goto RustboroCity_DevonCorp_2F_EventScript_ReadyFossilMon
	end

RustboroCity_DevonCorp_2F_EventScript_SetReadyCranidos::
	setvar VAR_TEMP_1, SPECIES_CRANIDOS
	goto RustboroCity_DevonCorp_2F_EventScript_ReadyFossilMon
	end

RustboroCity_DevonCorp_2F_EventScript_SetReadyShieldon::
	setvar VAR_TEMP_1, SPECIES_SHIELDON
	goto RustboroCity_DevonCorp_2F_EventScript_ReadyFossilMon
	end

RustboroCity_DevonCorp_2F_EventScript_SetReadyTirtouga::
	setvar VAR_TEMP_1, SPECIES_TIRTOUGA
	goto RustboroCity_DevonCorp_2F_EventScript_ReadyFossilMon
	end

RustboroCity_DevonCorp_2F_EventScript_SetReadyArchen::
	setvar VAR_TEMP_1, SPECIES_ARCHEN
	goto RustboroCity_DevonCorp_2F_EventScript_ReadyFossilMon
	end

RustboroCity_DevonCorp_2F_EventScript_SetReadyTyrunt::
	setvar VAR_TEMP_1, SPECIES_TYRUNT
	goto RustboroCity_DevonCorp_2F_EventScript_ReadyFossilMon
	end

RustboroCity_DevonCorp_2F_EventScript_SetReadyAmaura::
	setvar VAR_TEMP_1, SPECIES_AMAURA
	goto RustboroCity_DevonCorp_2F_EventScript_ReadyFossilMon
	end

RustboroCity_DevonCorp_2F_EventScript_SetReadyArctozolt::
	setvar VAR_TEMP_1, SPECIES_ARCTOZOLT
	goto RustboroCity_DevonCorp_2F_EventScript_ReadyFossilMon
	end

RustboroCity_DevonCorp_2F_EventScript_SetReadyArctovish::
	setvar VAR_TEMP_1, SPECIES_ARCTOVISH
	goto RustboroCity_DevonCorp_2F_EventScript_ReadyFossilMon
	end

RustboroCity_DevonCorp_2F_EventScript_SetReadyDracovish::
	setvar VAR_TEMP_1, SPECIES_DRACOVISH
	goto RustboroCity_DevonCorp_2F_EventScript_ReadyFossilMon
	end

RustboroCity_DevonCorp_2F_EventScript_SetReadyDracozolt::
	setvar VAR_TEMP_1, SPECIES_DRACOZOLT
	goto RustboroCity_DevonCorp_2F_EventScript_ReadyFossilMon
	end

RustboroCity_DevonCorp_2F_EventScript_ReadyFossilMon::
	bufferspeciesname STR_VAR_2, VAR_TEMP_1
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	copyvar VAR_TEMP_TRANSFERRED_SPECIES, VAR_TEMP_1
	givemon VAR_TEMP_1, 1
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RustboroCity_DevonCorp_2F_EventScript_ReceiveFossilMonParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RustboroCity_DevonCorp_2F_EventScript_ReceiveFossilMonPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveFossilMonParty::
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedFossilMonFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_FinishReceivingFossilMon
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingFossilMon
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveFossilMonPC::
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedFossilMonFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_TransferFossilMonToPC
	call Common_EventScript_NameReceivedBoxMon
	goto RustboroCity_DevonCorp_2F_EventScript_TransferFossilMonToPC
	end

RustboroCity_DevonCorp_2F_EventScript_TransferFossilMonToPC::
	call Common_EventScript_TransferredToPC
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingFossilMon
	end

RustboroCity_DevonCorp_2F_EventScript_ReceivedFossilMonFanfare::
	bufferspeciesname STR_VAR_2, VAR_TEMP_1
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	return

RustboroCity_DevonCorp_2F_EventScript_FinishReceivingFossilMon::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	release
	end

RustboroCity_DevonCorp_2F_EventScript_ChooseFossil::
	multichoice 17, 0, MULTI_FOSSIL, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_DevonCorp_2F_EventScript_ChooseKantoFossil
	case 1, RustboroCity_DevonCorp_2F_EventScript_ChooseHoennFossil
	case 2, RustboroCity_DevonCorp_2F_EventScript_ChooseSinnohFossil
	case 3, RustboroCity_DevonCorp_2F_EventScript_ChooseUnovaFossil
	case 4, RustboroCity_DevonCorp_2F_EventScript_ChooseKalosFossil
	case 5, RustboroCity_DevonCorp_2F_EventScript_ChooseGalarFossil
	case MULTI_B_PRESSED, RustboroCity_DevonCorp_2F_EventScript_CancelRegionFossilSelect
	end

RustboroCity_DevonCorp_2F_EventScript_ChooseKantoFossil::
	multichoice 17, 0, MULTI_FOSSIL_KANTO, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_DevonCorp_2F_EventScript_SelectHelixFossil
	case 1, RustboroCity_DevonCorp_2F_EventScript_SelectDomeFossil
	case 2, RustboroCity_DevonCorp_2F_EventScript_SelectOldAmber
	case 3, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	case MULTI_B_PRESSED, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	end

RustboroCity_DevonCorp_2F_EventScript_ChooseHoennFossil::
	multichoice 17, 0, MULTI_FOSSIL_HOENN, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_DevonCorp_2F_EventScript_ChooseClawFossil
	case 1, RustboroCity_DevonCorp_2F_EventScript_ChooseRootFossil
	case 2, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	case MULTI_B_PRESSED, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	end

RustboroCity_DevonCorp_2F_EventScript_ChooseSinnohFossil::
	multichoice 17, 0, MULTI_FOSSIL_SINNOH, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_DevonCorp_2F_EventScript_SelectSkullFossil
	case 1, RustboroCity_DevonCorp_2F_EventScript_SelectArmorFossil
	case 2, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	case MULTI_B_PRESSED, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	end

RustboroCity_DevonCorp_2F_EventScript_ChooseUnovaFossil::
	multichoice 17, 0, MULTI_FOSSIL_UNOVA, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_DevonCorp_2F_EventScript_SelectCoverFossil
	case 1, RustboroCity_DevonCorp_2F_EventScript_SelectPlumeFossil
	case 2, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	case MULTI_B_PRESSED, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	end

RustboroCity_DevonCorp_2F_EventScript_ChooseKalosFossil::
	multichoice 17, 0, MULTI_FOSSIL_KALOS, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_DevonCorp_2F_EventScript_SelectJawFossil
	case 1, RustboroCity_DevonCorp_2F_EventScript_SelectSailFossil
	case 2, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	case MULTI_B_PRESSED, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	end

RustboroCity_DevonCorp_2F_EventScript_ChooseGalarFossil::
	multichoice 17, 0, MULTI_FOSSIL_GALAR, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_DevonCorp_2F_EventScript_SelectFossilizedBird
	case 1, RustboroCity_DevonCorp_2F_EventScript_SelectFossilizedFish
	case 2, RustboroCity_DevonCorp_2F_EventScript_SelectFossilizedDrake
	case 3, RustboroCity_DevonCorp_2F_EventScript_SelectFossilizedDino
	case 4, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	case MULTI_B_PRESSED, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	end

RustboroCity_DevonCorp_2F_EventScript_ChooseClawFossil::
	setvar VAR_TEMP_1, 2
	goto RustboroCity_DevonCorp_2F_EventScript_VerifyFossil
	end

RustboroCity_DevonCorp_2F_EventScript_ChooseRootFossil::
	setvar VAR_TEMP_1, 1
	goto RustboroCity_DevonCorp_2F_EventScript_VerifyFossil
	end

RustboroCity_DevonCorp_2F_EventScript_SelectHelixFossil::
	setvar VAR_TEMP_1, 3
	goto RustboroCity_DevonCorp_2F_EventScript_VerifyFossil
	end

RustboroCity_DevonCorp_2F_EventScript_SelectDomeFossil::
	setvar VAR_TEMP_1, 4
	goto RustboroCity_DevonCorp_2F_EventScript_VerifyFossil
	end

RustboroCity_DevonCorp_2F_EventScript_SelectOldAmber::
	setvar VAR_TEMP_1, 5
	goto RustboroCity_DevonCorp_2F_EventScript_VerifyFossil
	end

RustboroCity_DevonCorp_2F_EventScript_SelectSkullFossil::
	setvar VAR_TEMP_1, 6
	goto RustboroCity_DevonCorp_2F_EventScript_VerifyFossil
	end

RustboroCity_DevonCorp_2F_EventScript_SelectArmorFossil::
	setvar VAR_TEMP_1, 7
	goto RustboroCity_DevonCorp_2F_EventScript_VerifyFossil
	end

RustboroCity_DevonCorp_2F_EventScript_SelectCoverFossil::
	setvar VAR_TEMP_1, 8
	goto RustboroCity_DevonCorp_2F_EventScript_VerifyFossil
	end

RustboroCity_DevonCorp_2F_EventScript_SelectPlumeFossil::
	setvar VAR_TEMP_1, 9
	goto RustboroCity_DevonCorp_2F_EventScript_VerifyFossil
	end

RustboroCity_DevonCorp_2F_EventScript_SelectJawFossil::
	setvar VAR_TEMP_1, 10
	goto RustboroCity_DevonCorp_2F_EventScript_VerifyFossil
	end

RustboroCity_DevonCorp_2F_EventScript_SelectSailFossil::
	setvar VAR_TEMP_1, 11
	goto RustboroCity_DevonCorp_2F_EventScript_VerifyFossil
	end

RustboroCity_DevonCorp_2F_EventScript_SelectFossilizedBird::
	setvar VAR_TEMP_1, 12
	goto RustboroCity_DevonCorp_2F_EventScript_VerifyFossil
	end

RustboroCity_DevonCorp_2F_EventScript_SelectFossilizedFish::
	setvar VAR_TEMP_1, 13
	goto RustboroCity_DevonCorp_2F_EventScript_VerifyFossil
	end

RustboroCity_DevonCorp_2F_EventScript_SelectFossilizedDrake::
	setvar VAR_TEMP_1, 14
	goto RustboroCity_DevonCorp_2F_EventScript_VerifyFossil
	end

RustboroCity_DevonCorp_2F_EventScript_SelectFossilizedDino::
	setvar VAR_TEMP_1, 15
	goto RustboroCity_DevonCorp_2F_EventScript_VerifyFossil
	end

RustboroCity_DevonCorp_2F_EventScript_CancelRegionFossilSelect::
	msgbox RustboroCity_DevonCorp_2F_Text_CancelRegionFossilSelect, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_MatchCallScientist::
	lock
	faceplayer
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	goto_if_ge VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_DevonCorp_2F_EventScript_WorkOnNext
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopNewPokenavFeature, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_WorkOnNext::
	msgbox RustboroCity_DevonCorp_2F_Text_WhatToWorkOnNext, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_Text_DeviceForTalkingToPokemon:
	.string "We're developing a device for talking\n"
	.string "with POKéMON.\p"
	.string "But we haven't had much success…$"

RustboroCity_DevonCorp_2F_Text_DevelopingNewBalls:
	.string "I'm developing new kinds of\n"
	.string "POKé BALLS…\p"
	.string "But I haven't made much headway…$"

RustboroCity_DevonCorp_2F_Text_WeFinallyMadeNewBalls:
	.string "We finally made new kinds of\n"
	.string "POKé BALLS!\p"
	.string "The REPEAT BALL makes it easier to\n"
	.string "catch POKéMON you've caught before.\p"
	.string "The TIMER BALL gets better at catching\n"
	.string "POKéMON the longer a battle runs.\p"
	.string "Both are proudly developed by\n"
	.string "the DEVON CORPORATION.\p"
	.string "Please give them a try!$"

RustboroCity_DevonCorp_2F_Text_IMadePokenav:
	.string "I made the POKéNAV!\p"
	.string "As an engineer, I feel blessed to have\n"
	.string "made something so great!$"

RustboroCity_DevonCorp_2F_Text_WowThatsAPokenav:
	.string "Oh, wow!\n"
	.string "That's a POKéNAV!\p"
	.string "It came about as a result of our\n"
	.string "PRESIDENT's desire to learn about\l"
	.string "the feelings of POKéMON.\p"
	.string "Would you like me to describe its\n"
	.string "features in detail?\p"
	.string "No, no. I think you'll find out just by\n"
	.string "trying the POKéNAV out.$"

RustboroCity_DevonCorp_2F_Text_DeviceToVisualizePokemonDreams:
	.string "I'm trying to develop a device that\n"
	.string "visually reproduces the dreams of\l"
	.string "POKéMON…\p"
	.string "But it's not going well.$"

RustboroCity_DevonCorp_2F_Text_DevelopDeviceToResurrectFossils:
	.string "I've been trying to develop a device\n"
	.string "that resurrects POKéMON from fossils…\p"
	.string "And, it's working!$"

RustboroCity_DevonCorp_2F_Text_AskToRegenerateAnotherFossil:
	.string "Hi! You want to regenerate another\n"
	.string "fossil?$"

RustboroCity_DevonCorp_2F_Text_NoFossilsToRegenerate:
	.string "You don't have any fossils for me to\n"
	.string "regenerate.$"

RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife:
	.string "Wait! That thing you have there…\n"
	.string "Is that a POKéMON fossil?\p"
	.string "Would you like to bring that POKéMON\n"
	.string "back to life?\p"
	.string "I can with my newly developed\n"
	.string "FOSSIL REGENERATOR.$"

RustboroCity_DevonCorp_2F_Text_OhIsThatSo:
	.string "Oh, is that so?\p"
	.string "DEVON's technological expertise\n"
	.string "is outstanding, I tell you.$"

RustboroCity_DevonCorp_2F_Text_TwoFossilsPickOne:
	.string "Oh, now that's a surprise!\n"
	.string "You have a POKéMON fossil!\p"
	.string "Unfortunately, my machine can only\n"
	.string "regenerate one POKéMON at a time.\p"
	.string "Which fossil would you like me to\n"
	.string "regenerate?$"

RustboroCity_DevonCorp_2F_Text_CancelRegionFossilSelect:
	.string "Not now? Maybe later then.$"

RustboroCity_DevonCorp_2F_Text_DontHaveSelectedFossil:
	.string "You don't have that fossil.$"

RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher:
	.string "Excellent!\n"
	.string "Let's do this right away.\p"
	.string "{PLAYER} handed the {STR_VAR_1} to\n"
	.string "the DEVON RESEARCHER.$"

RustboroCity_DevonCorp_2F_Text_FossilRegeneratorTakesTime:
	.string "The FOSSIL REGENERATOR, which I made,\n"
	.string "is incredible.\p"
	.string "But it has one drawback--it takes\n"
	.string "a long time to work.\p"
	.string "So, uh… How about you go for a stroll\n"
	.string "and look around for a while?$"

RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife:
	.string "Thanks for waiting!\p"
	.string "Your fossilized POKéMON has been\n"
	.string "brought back to life!\p"
	.string "The fossil was an ancient POKéMON.\n"
	.string "{STR_VAR_2}, it was!$"

RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher:
	.string "{PLAYER} received {STR_VAR_2} from\n"
	.string "the DEVON RESEARCHER.$"

@ Unused
RustboroCity_DevonCorp_2F_Text_TooManyPokemon:
	.string "Uh-oh, you've got too many POKéMON.\n"
	.string "You have no room for this one.$"

RustboroCity_DevonCorp_2F_Text_DevelopNewPokenavFeature:
	.string "I'm trying to develop a new feature\n"
	.string "for the POKéNAV…\p"
	.string "But it's not going well.$"

RustboroCity_DevonCorp_2F_Text_WhatToWorkOnNext:
	.string "Well, now what shall I work on\n"
	.string "developing next?\p"
	.string "Our company allows us to make our\n"
	.string "inspirations into reality.\p"
	.string "One couldn't ask for a better\n"
	.string "environment as an engineer.$"
