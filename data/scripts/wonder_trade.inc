EventScript_WonderTrade::
	lock
	faceplayer
	msgbox WonderTrade_Text_Ask, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_WonderTrade_Cancel
EventScript_WonderTrade_SelectPokemon::
	msgbox WonderTrade_Text_SelectPokemon, MSGBOX_DEFAULT
	special ChooseMonForWonderTrade
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, EventScript_WonderTrade_Cancel
	goto_if_eq VAR_0x8005, FALSE, EventScript_WonderTrade_SelectPokemon

EventScript_WonderTrade_Confirm::
	msgbox WonderTrade_Text_Confirm, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_WonderTrade_SelectPokemon
	specialvar VAR_RESULT, WonderTradeSelectedMon
	goto_if_eq VAR_RESULT, WONDER_TRADE_SUCCESS, EventScript_WonderTrade_DoTrade
	goto_if_eq VAR_RESULT, WONDER_TRADE_INVALID_MON, EventScript_WonderTrade_InvalidPokemon
	msgbox WonderTrade_Text_NoEligiblePokemon, MSGBOX_DEFAULT
	release
	end

EventScript_WonderTrade_DoTrade::
	special DoWonderTradeScene
	special WonderTradeBufferSuccessText
	goto EventScript_WonderTrade_Success

EventScript_WonderTrade_Success::
	callnative UpdateFollowingPokemon
	msgbox WonderTrade_Text_Success, MSGBOX_DEFAULT
	release
	end

EventScript_WonderTrade_InvalidPokemon::
	msgbox WonderTrade_Text_InvalidPokemon, MSGBOX_DEFAULT
	release
	end

EventScript_WonderTrade_Cancel::
	msgbox WonderTrade_Text_Cancel, MSGBOX_DEFAULT
	release
	end

WonderTrade_Text_Ask:
	.string "Would you like to make a WONDER TRADE?$"

WonderTrade_Text_Confirm:
	.string "Do you want to initiate the trade?$"

WonderTrade_Text_SelectPokemon:
	.string "Which POKéMON would you like to trade?$"

WonderTrade_Text_Success:
	.string "{STR_VAR_1} was traded for {STR_VAR_2}!\p"
	.string "It was sent by {STR_VAR_3}.$"

WonderTrade_Text_InvalidPokemon:
	.string "That POKéMON can't be traded.\n"
	.string "Choose a different one.$"

WonderTrade_Text_NoEligiblePokemon:
	.string "No eligible POKéMON are configured\n"
	.string "for WONDER TRADE.$"

WonderTrade_Text_Cancel:
	.string "Maybe next time.$"
