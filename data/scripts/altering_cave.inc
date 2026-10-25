.macro altering_cave_push species:req
	dynmultipush AlteringCave_Text_\species, \species
.endm

.macro altering_cave_case species:req
	case \species, AlteringCave_EventScript_Select_\species
.endm

.macro altering_cave_entry species:req, table:req
AlteringCave_EventScript_Select_\species:
	setvar VAR_ENCOUNTER_TABLE, \table
	bufferspeciesname STR_VAR_1, \species
	msgbox AlteringCave_Text_EncounterSelected, MSGBOX_DEFAULT
	closemessage
	return
.endm

AlteringCave_EventScript_SelectEncounter::
AlteringCave_EventScript_SelectRegion:
	goto_if_set FLAG_ALTERING_CAVE_REGION_KANTO, AlteringCave_EventScript_ShowRegionMenu
	goto_if_set FLAG_ALTERING_CAVE_REGION_JOHTO, AlteringCave_EventScript_ShowRegionMenu
	goto_if_set FLAG_ALTERING_CAVE_REGION_HOENN, AlteringCave_EventScript_ShowRegionMenu
	goto_if_set FLAG_ALTERING_CAVE_REGION_SINNOH, AlteringCave_EventScript_ShowRegionMenu
	goto_if_set FLAG_ALTERING_CAVE_REGION_UNOVA, AlteringCave_EventScript_ShowRegionMenu
	goto_if_set FLAG_ALTERING_CAVE_REGION_KALOS, AlteringCave_EventScript_ShowRegionMenu
	goto_if_set FLAG_ALTERING_CAVE_REGION_ALOLA, AlteringCave_EventScript_ShowRegionMenu
	goto_if_set FLAG_ALTERING_CAVE_REGION_GALAR, AlteringCave_EventScript_ShowRegionMenu
	goto_if_set FLAG_ALTERING_CAVE_REGION_HISUI, AlteringCave_EventScript_ShowRegionMenu
	goto_if_set FLAG_ALTERING_CAVE_REGION_PALDEA, AlteringCave_EventScript_ShowRegionMenu
	goto_if_set FLAG_ALTERING_CAVE_REGION_PARADOX, AlteringCave_EventScript_ShowRegionMenu
	goto_if_set FLAG_ALTERING_CAVE_REGION_ULTRA_BEASTS, AlteringCave_EventScript_ShowRegionMenu
	goto_if_set FLAG_ALTERING_CAVE_REGION_UNOWN, AlteringCave_EventScript_ShowRegionMenu
	msgbox AlteringCave_Text_ExploreMore, MSGBOX_DEFAULT
	closemessage
	return

AlteringCave_EventScript_ShowRegionMenu:
	call_if_set FLAG_ALTERING_CAVE_REGION_KANTO, AlteringCave_EventScript_PushRegionKanto
	call_if_set FLAG_ALTERING_CAVE_REGION_JOHTO, AlteringCave_EventScript_PushRegionJohto
	call_if_set FLAG_ALTERING_CAVE_REGION_HOENN, AlteringCave_EventScript_PushRegionHoenn
	call_if_set FLAG_ALTERING_CAVE_REGION_SINNOH, AlteringCave_EventScript_PushRegionSinnoh
	call_if_set FLAG_ALTERING_CAVE_REGION_UNOVA, AlteringCave_EventScript_PushRegionUnova
	call_if_set FLAG_ALTERING_CAVE_REGION_KALOS, AlteringCave_EventScript_PushRegionKalos
	call_if_set FLAG_ALTERING_CAVE_REGION_ALOLA, AlteringCave_EventScript_PushRegionAlola
	call_if_set FLAG_ALTERING_CAVE_REGION_GALAR, AlteringCave_EventScript_PushRegionGalar
	call_if_set FLAG_ALTERING_CAVE_REGION_HISUI, AlteringCave_EventScript_PushRegionHisui
	call_if_set FLAG_ALTERING_CAVE_REGION_PALDEA, AlteringCave_EventScript_PushRegionPaldea
	call_if_set FLAG_ALTERING_CAVE_REGION_PARADOX, AlteringCave_EventScript_PushRegionParadox
	call_if_set FLAG_ALTERING_CAVE_REGION_ULTRA_BEASTS, AlteringCave_EventScript_PushRegionUltraBeasts
	call_if_set FLAG_ALTERING_CAVE_REGION_UNOWN, AlteringCave_EventScript_PushRegionUnown
	dynmultipush AlteringCave_Text_Default, 13
	dynmultistack 0, 0, FALSE, 8, 0, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, AlteringCave_EventScript_SelectKanto
	case 1, AlteringCave_EventScript_SelectJohto
	case 2, AlteringCave_EventScript_SelectHoenn
	case 3, AlteringCave_EventScript_SelectSinnoh
	case 4, AlteringCave_EventScript_SelectUnova
	case 5, AlteringCave_EventScript_SelectKalos
	case 6, AlteringCave_EventScript_SelectAlola
	case 7, AlteringCave_EventScript_SelectGalar
	case 8, AlteringCave_EventScript_SelectHisui
	case 9, AlteringCave_EventScript_SelectPaldea
	case 10, AlteringCave_EventScript_SelectParadox
	case 11, AlteringCave_EventScript_SelectUltraBeasts
	case 12, AlteringCave_EventScript_SelectUnownForms
	case 13, AlteringCave_EventScript_SelectDefault
	return

AlteringCave_EventScript_PushRegionKanto:
	dynmultipush AlteringCave_Text_Kanto, 0
	return

AlteringCave_EventScript_PushRegionJohto:
	dynmultipush AlteringCave_Text_Johto, 1
	return

AlteringCave_EventScript_PushRegionHoenn:
	dynmultipush AlteringCave_Text_Hoenn, 2
	return

AlteringCave_EventScript_PushRegionSinnoh:
	dynmultipush AlteringCave_Text_Sinnoh, 3
	return

AlteringCave_EventScript_PushRegionUnova:
	dynmultipush AlteringCave_Text_Unova, 4
	return

AlteringCave_EventScript_PushRegionKalos:
	dynmultipush AlteringCave_Text_Kalos, 5
	return

AlteringCave_EventScript_PushRegionAlola:
	dynmultipush AlteringCave_Text_Alola, 6
	return

AlteringCave_EventScript_PushRegionGalar:
	dynmultipush AlteringCave_Text_Galar, 7
	return

AlteringCave_EventScript_PushRegionHisui:
	dynmultipush AlteringCave_Text_Hisui, 8
	return

AlteringCave_EventScript_PushRegionPaldea:
	dynmultipush AlteringCave_Text_Paldea, 9
	return

AlteringCave_EventScript_PushRegionParadox:
	dynmultipush AlteringCave_Text_ParadoxPokemon, 10
	return

AlteringCave_EventScript_PushRegionUltraBeasts:
	dynmultipush AlteringCave_Text_UltraBeasts, 11
	return

AlteringCave_EventScript_PushRegionUnown:
	dynmultipush AlteringCave_Text_UnownForms, 12
	return

AlteringCave_EventScript_SelectKanto:
	altering_cave_push SPECIES_ARTICUNO
	altering_cave_push SPECIES_ZAPDOS
	altering_cave_push SPECIES_MOLTRES
	altering_cave_push SPECIES_MEWTWO
	altering_cave_push SPECIES_MEW
	dynmultistack 0, 0, FALSE, 8, FALSE, 0, DYN_MULTICHOICE_CB_SHOW_PKMN
	goto AlteringCave_EventScript_DispatchSelection

AlteringCave_EventScript_SelectJohto:
	altering_cave_push SPECIES_RAIKOU
	altering_cave_push SPECIES_ENTEI
	altering_cave_push SPECIES_SUICUNE
	altering_cave_push SPECIES_LUGIA
	altering_cave_push SPECIES_HO_OH
	altering_cave_push SPECIES_CELEBI
	dynmultistack 0, 0, FALSE, 8, FALSE, 0, DYN_MULTICHOICE_CB_SHOW_PKMN
	goto AlteringCave_EventScript_DispatchSelection

AlteringCave_EventScript_SelectHoenn:
	altering_cave_push SPECIES_REGIROCK
	altering_cave_push SPECIES_REGICE
	altering_cave_push SPECIES_REGISTEEL
	altering_cave_push SPECIES_LATIAS
	altering_cave_push SPECIES_LATIOS
	altering_cave_push SPECIES_KYOGRE
	altering_cave_push SPECIES_GROUDON
	altering_cave_push SPECIES_RAYQUAZA
	altering_cave_push SPECIES_JIRACHI
	altering_cave_push SPECIES_DEOXYS
	dynmultistack 0, 0, FALSE, 8, FALSE, 0, DYN_MULTICHOICE_CB_SHOW_PKMN
	goto AlteringCave_EventScript_DispatchSelection

AlteringCave_EventScript_SelectSinnoh:
	altering_cave_push SPECIES_UXIE
	altering_cave_push SPECIES_MESPRIT
	altering_cave_push SPECIES_AZELF
	altering_cave_push SPECIES_DIALGA
	altering_cave_push SPECIES_PALKIA
	altering_cave_push SPECIES_HEATRAN
	altering_cave_push SPECIES_REGIGIGAS
	altering_cave_push SPECIES_GIRATINA
	altering_cave_push SPECIES_CRESSELIA
	altering_cave_push SPECIES_PHIONE
	altering_cave_push SPECIES_MANAPHY
	altering_cave_push SPECIES_DARKRAI
	altering_cave_push SPECIES_SHAYMIN
	altering_cave_push SPECIES_ARCEUS
	dynmultistack 0, 0, FALSE, 8, FALSE, 0, DYN_MULTICHOICE_CB_SHOW_PKMN
	goto AlteringCave_EventScript_DispatchSelection

AlteringCave_EventScript_SelectUnova:
	altering_cave_push SPECIES_COBALION
	altering_cave_push SPECIES_TERRAKION
	altering_cave_push SPECIES_VIRIZION
	altering_cave_push SPECIES_TORNADUS
	altering_cave_push SPECIES_THUNDURUS
	altering_cave_push SPECIES_LANDORUS
	altering_cave_push SPECIES_RESHIRAM
	altering_cave_push SPECIES_ZEKROM
	altering_cave_push SPECIES_KYUREM
	altering_cave_push SPECIES_VICTINI
	altering_cave_push SPECIES_KELDEO
	altering_cave_push SPECIES_MELOETTA
	altering_cave_push SPECIES_GENESECT
	dynmultistack 0, 0, FALSE, 8, FALSE, 0, DYN_MULTICHOICE_CB_SHOW_PKMN
	goto AlteringCave_EventScript_DispatchSelection

AlteringCave_EventScript_SelectKalos:
	altering_cave_push SPECIES_XERNEAS
	altering_cave_push SPECIES_YVELTAL
	altering_cave_push SPECIES_ZYGARDE
	altering_cave_push SPECIES_DIANCIE
	altering_cave_push SPECIES_HOOPA
	altering_cave_push SPECIES_VOLCANION
	dynmultistack 0, 0, FALSE, 8, FALSE, 0, DYN_MULTICHOICE_CB_SHOW_PKMN
	goto AlteringCave_EventScript_DispatchSelection

AlteringCave_EventScript_SelectAlola:
	altering_cave_push SPECIES_TAPU_KOKO
	altering_cave_push SPECIES_TAPU_LELE
	altering_cave_push SPECIES_TAPU_BULU
	altering_cave_push SPECIES_TAPU_FINI
	altering_cave_push SPECIES_COSMOG
	altering_cave_push SPECIES_COSMOEM
	altering_cave_push SPECIES_SOLGALEO
	altering_cave_push SPECIES_LUNALA
	altering_cave_push SPECIES_NECROZMA
	altering_cave_push SPECIES_MAGEARNA
	altering_cave_push SPECIES_MARSHADOW
	altering_cave_push SPECIES_ZERAORA
	altering_cave_push SPECIES_MELTAN
	altering_cave_push SPECIES_MELMETAL
	dynmultistack 0, 0, FALSE, 8, FALSE, 0, DYN_MULTICHOICE_CB_SHOW_PKMN
	goto AlteringCave_EventScript_DispatchSelection

AlteringCave_EventScript_SelectGalar:
	altering_cave_push SPECIES_ZACIAN
	altering_cave_push SPECIES_ZAMAZENTA
	altering_cave_push SPECIES_ETERNATUS
	altering_cave_push SPECIES_KUBFU
	altering_cave_push SPECIES_URSHIFU_SINGLE_STRIKE
	altering_cave_push SPECIES_URSHIFU_RAPID_STRIKE
	altering_cave_push SPECIES_REGIELEKI
	altering_cave_push SPECIES_REGIDRAGO
	altering_cave_push SPECIES_GLASTRIER
	altering_cave_push SPECIES_SPECTRIER
	altering_cave_push SPECIES_CALYREX
	altering_cave_push SPECIES_ZARUDE
	dynmultistack 0, 0, FALSE, 8, FALSE, 0, DYN_MULTICHOICE_CB_SHOW_PKMN
	goto AlteringCave_EventScript_DispatchSelection

AlteringCave_EventScript_SelectHisui:
	altering_cave_push SPECIES_ENAMORUS
	dynmultistack 0, 0, FALSE, 8, FALSE, 0, DYN_MULTICHOICE_CB_SHOW_PKMN
	goto AlteringCave_EventScript_DispatchSelection

AlteringCave_EventScript_SelectPaldea:
	altering_cave_push SPECIES_WO_CHIEN
	altering_cave_push SPECIES_CHIEN_PAO
	altering_cave_push SPECIES_TING_LU
	altering_cave_push SPECIES_CHI_YU
	altering_cave_push SPECIES_KORAIDON
	altering_cave_push SPECIES_MIRAIDON
	altering_cave_push SPECIES_OKIDOGI
	altering_cave_push SPECIES_MUNKIDORI
	altering_cave_push SPECIES_FEZANDIPITI
	altering_cave_push SPECIES_OGERPON
	altering_cave_push SPECIES_TERAPAGOS
	altering_cave_push SPECIES_PECHARUNT
	dynmultistack 0, 0, FALSE, 8, FALSE, 0, DYN_MULTICHOICE_CB_SHOW_PKMN
	goto AlteringCave_EventScript_DispatchSelection

AlteringCave_EventScript_SelectParadox:
	altering_cave_push SPECIES_GREAT_TUSK
	altering_cave_push SPECIES_SCREAM_TAIL
	altering_cave_push SPECIES_BRUTE_BONNET
	altering_cave_push SPECIES_FLUTTER_MANE
	altering_cave_push SPECIES_SLITHER_WING
	altering_cave_push SPECIES_SANDY_SHOCKS
	altering_cave_push SPECIES_ROARING_MOON
	altering_cave_push SPECIES_WALKING_WAKE
	altering_cave_push SPECIES_GOUGING_FIRE
	altering_cave_push SPECIES_RAGING_BOLT
	altering_cave_push SPECIES_IRON_TREADS
	altering_cave_push SPECIES_IRON_BUNDLE
	altering_cave_push SPECIES_IRON_HANDS
	altering_cave_push SPECIES_IRON_JUGULIS
	altering_cave_push SPECIES_IRON_MOTH
	altering_cave_push SPECIES_IRON_THORNS
	altering_cave_push SPECIES_IRON_VALIANT
	altering_cave_push SPECIES_IRON_CROWN
	altering_cave_push SPECIES_IRON_BOULDER
	altering_cave_push SPECIES_IRON_LEAVES
	dynmultistack 0, 0, FALSE, 8, FALSE, 0, DYN_MULTICHOICE_CB_SHOW_PKMN
	goto AlteringCave_EventScript_DispatchSelection

AlteringCave_EventScript_SelectUltraBeasts:
	altering_cave_push SPECIES_NIHILEGO
	altering_cave_push SPECIES_BUZZWOLE
	altering_cave_push SPECIES_PHEROMOSA
	altering_cave_push SPECIES_XURKITREE
	altering_cave_push SPECIES_CELESTEELA
	altering_cave_push SPECIES_KARTANA
	altering_cave_push SPECIES_GUZZLORD
	altering_cave_push SPECIES_POIPOLE
	altering_cave_push SPECIES_NAGANADEL
	altering_cave_push SPECIES_STAKATAKA
	altering_cave_push SPECIES_BLACEPHALON
	dynmultistack 0, 0, FALSE, 8, FALSE, 0, DYN_MULTICHOICE_CB_SHOW_PKMN
	goto AlteringCave_EventScript_DispatchSelection

AlteringCave_EventScript_SelectUnownForms:
	altering_cave_push SPECIES_UNOWN
	altering_cave_push SPECIES_UNOWN_B
	altering_cave_push SPECIES_UNOWN_C
	altering_cave_push SPECIES_UNOWN_D
	altering_cave_push SPECIES_UNOWN_E
	altering_cave_push SPECIES_UNOWN_F
	altering_cave_push SPECIES_UNOWN_G
	altering_cave_push SPECIES_UNOWN_H
	altering_cave_push SPECIES_UNOWN_I
	altering_cave_push SPECIES_UNOWN_J
	altering_cave_push SPECIES_UNOWN_K
	altering_cave_push SPECIES_UNOWN_L
	altering_cave_push SPECIES_UNOWN_M
	altering_cave_push SPECIES_UNOWN_N
	altering_cave_push SPECIES_UNOWN_O
	altering_cave_push SPECIES_UNOWN_P
	altering_cave_push SPECIES_UNOWN_Q
	altering_cave_push SPECIES_UNOWN_R
	altering_cave_push SPECIES_UNOWN_S
	altering_cave_push SPECIES_UNOWN_T
	altering_cave_push SPECIES_UNOWN_U
	altering_cave_push SPECIES_UNOWN_V
	altering_cave_push SPECIES_UNOWN_W
	altering_cave_push SPECIES_UNOWN_X
	altering_cave_push SPECIES_UNOWN_Y
	altering_cave_push SPECIES_UNOWN_Z
	altering_cave_push SPECIES_UNOWN_EXCLAMATION
	altering_cave_push SPECIES_UNOWN_QUESTION
	dynmultistack 0, 0, FALSE, 8, FALSE, 0, DYN_MULTICHOICE_CB_SHOW_PKMN
	goto AlteringCave_EventScript_DispatchSelection

AlteringCave_EventScript_DispatchSelection:
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq AlteringCave_EventScript_SelectRegion
	switch VAR_RESULT
	altering_cave_case SPECIES_ARTICUNO
	altering_cave_case SPECIES_ZAPDOS
	altering_cave_case SPECIES_MOLTRES
	altering_cave_case SPECIES_MEWTWO
	altering_cave_case SPECIES_RAIKOU
	altering_cave_case SPECIES_ENTEI
	altering_cave_case SPECIES_SUICUNE
	altering_cave_case SPECIES_LUGIA
	altering_cave_case SPECIES_HO_OH
	altering_cave_case SPECIES_REGIROCK
	altering_cave_case SPECIES_REGICE
	altering_cave_case SPECIES_REGISTEEL
	altering_cave_case SPECIES_LATIAS
	altering_cave_case SPECIES_LATIOS
	altering_cave_case SPECIES_KYOGRE
	altering_cave_case SPECIES_GROUDON
	altering_cave_case SPECIES_RAYQUAZA
	altering_cave_case SPECIES_UXIE
	altering_cave_case SPECIES_MESPRIT
	altering_cave_case SPECIES_AZELF
	altering_cave_case SPECIES_DIALGA
	altering_cave_case SPECIES_PALKIA
	altering_cave_case SPECIES_HEATRAN
	altering_cave_case SPECIES_REGIGIGAS
	altering_cave_case SPECIES_GIRATINA
	altering_cave_case SPECIES_CRESSELIA
	altering_cave_case SPECIES_COBALION
	altering_cave_case SPECIES_TERRAKION
	altering_cave_case SPECIES_VIRIZION
	altering_cave_case SPECIES_TORNADUS
	altering_cave_case SPECIES_THUNDURUS
	altering_cave_case SPECIES_LANDORUS
	altering_cave_case SPECIES_RESHIRAM
	altering_cave_case SPECIES_ZEKROM
	altering_cave_case SPECIES_KYUREM
	altering_cave_case SPECIES_XERNEAS
	altering_cave_case SPECIES_YVELTAL
	altering_cave_case SPECIES_ZYGARDE
	altering_cave_case SPECIES_TAPU_KOKO
	altering_cave_case SPECIES_TAPU_LELE
	altering_cave_case SPECIES_TAPU_BULU
	altering_cave_case SPECIES_TAPU_FINI
	altering_cave_case SPECIES_COSMOG
	altering_cave_case SPECIES_COSMOEM
	altering_cave_case SPECIES_SOLGALEO
	altering_cave_case SPECIES_LUNALA
	altering_cave_case SPECIES_NECROZMA
	altering_cave_case SPECIES_ZACIAN
	altering_cave_case SPECIES_ZAMAZENTA
	altering_cave_case SPECIES_ETERNATUS
	altering_cave_case SPECIES_KUBFU
	altering_cave_case SPECIES_URSHIFU_SINGLE_STRIKE
	altering_cave_case SPECIES_URSHIFU_RAPID_STRIKE
	altering_cave_case SPECIES_REGIELEKI
	altering_cave_case SPECIES_REGIDRAGO
	altering_cave_case SPECIES_GLASTRIER
	altering_cave_case SPECIES_SPECTRIER
	altering_cave_case SPECIES_CALYREX
	altering_cave_case SPECIES_ENAMORUS
	altering_cave_case SPECIES_WO_CHIEN
	altering_cave_case SPECIES_CHIEN_PAO
	altering_cave_case SPECIES_TING_LU
	altering_cave_case SPECIES_CHI_YU
	altering_cave_case SPECIES_KORAIDON
	altering_cave_case SPECIES_MIRAIDON
	altering_cave_case SPECIES_OKIDOGI
	altering_cave_case SPECIES_MUNKIDORI
	altering_cave_case SPECIES_FEZANDIPITI
	altering_cave_case SPECIES_OGERPON
	altering_cave_case SPECIES_TERAPAGOS
	altering_cave_case SPECIES_MEW
	altering_cave_case SPECIES_CELEBI
	altering_cave_case SPECIES_JIRACHI
	altering_cave_case SPECIES_DEOXYS
	altering_cave_case SPECIES_PHIONE
	altering_cave_case SPECIES_MANAPHY
	altering_cave_case SPECIES_DARKRAI
	altering_cave_case SPECIES_SHAYMIN
	altering_cave_case SPECIES_ARCEUS
	altering_cave_case SPECIES_VICTINI
	altering_cave_case SPECIES_KELDEO
	altering_cave_case SPECIES_MELOETTA
	altering_cave_case SPECIES_GENESECT
	altering_cave_case SPECIES_DIANCIE
	altering_cave_case SPECIES_HOOPA
	altering_cave_case SPECIES_VOLCANION
	altering_cave_case SPECIES_MAGEARNA
	altering_cave_case SPECIES_MARSHADOW
	altering_cave_case SPECIES_ZERAORA
	altering_cave_case SPECIES_MELTAN
	altering_cave_case SPECIES_MELMETAL
	altering_cave_case SPECIES_ZARUDE
	altering_cave_case SPECIES_PECHARUNT
	altering_cave_case SPECIES_GREAT_TUSK
	altering_cave_case SPECIES_SCREAM_TAIL
	altering_cave_case SPECIES_BRUTE_BONNET
	altering_cave_case SPECIES_FLUTTER_MANE
	altering_cave_case SPECIES_SLITHER_WING
	altering_cave_case SPECIES_SANDY_SHOCKS
	altering_cave_case SPECIES_ROARING_MOON
	altering_cave_case SPECIES_WALKING_WAKE
	altering_cave_case SPECIES_GOUGING_FIRE
	altering_cave_case SPECIES_RAGING_BOLT
	altering_cave_case SPECIES_IRON_TREADS
	altering_cave_case SPECIES_IRON_BUNDLE
	altering_cave_case SPECIES_IRON_HANDS
	altering_cave_case SPECIES_IRON_JUGULIS
	altering_cave_case SPECIES_IRON_MOTH
	altering_cave_case SPECIES_IRON_THORNS
	altering_cave_case SPECIES_IRON_VALIANT
	altering_cave_case SPECIES_IRON_CROWN
	altering_cave_case SPECIES_IRON_BOULDER
	altering_cave_case SPECIES_IRON_LEAVES
	altering_cave_case SPECIES_NIHILEGO
	altering_cave_case SPECIES_BUZZWOLE
	altering_cave_case SPECIES_PHEROMOSA
	altering_cave_case SPECIES_XURKITREE
	altering_cave_case SPECIES_CELESTEELA
	altering_cave_case SPECIES_KARTANA
	altering_cave_case SPECIES_GUZZLORD
	altering_cave_case SPECIES_POIPOLE
	altering_cave_case SPECIES_NAGANADEL
	altering_cave_case SPECIES_STAKATAKA
	altering_cave_case SPECIES_BLACEPHALON
	altering_cave_case SPECIES_UNOWN
	altering_cave_case SPECIES_UNOWN_B
	altering_cave_case SPECIES_UNOWN_C
	altering_cave_case SPECIES_UNOWN_D
	altering_cave_case SPECIES_UNOWN_E
	altering_cave_case SPECIES_UNOWN_F
	altering_cave_case SPECIES_UNOWN_G
	altering_cave_case SPECIES_UNOWN_H
	altering_cave_case SPECIES_UNOWN_I
	altering_cave_case SPECIES_UNOWN_J
	altering_cave_case SPECIES_UNOWN_K
	altering_cave_case SPECIES_UNOWN_L
	altering_cave_case SPECIES_UNOWN_M
	altering_cave_case SPECIES_UNOWN_N
	altering_cave_case SPECIES_UNOWN_O
	altering_cave_case SPECIES_UNOWN_P
	altering_cave_case SPECIES_UNOWN_Q
	altering_cave_case SPECIES_UNOWN_R
	altering_cave_case SPECIES_UNOWN_S
	altering_cave_case SPECIES_UNOWN_T
	altering_cave_case SPECIES_UNOWN_U
	altering_cave_case SPECIES_UNOWN_V
	altering_cave_case SPECIES_UNOWN_W
	altering_cave_case SPECIES_UNOWN_X
	altering_cave_case SPECIES_UNOWN_Y
	altering_cave_case SPECIES_UNOWN_Z
	altering_cave_case SPECIES_UNOWN_EXCLAMATION
	altering_cave_case SPECIES_UNOWN_QUESTION

AlteringCave_EventScript_SelectDefault:
	setvar VAR_ENCOUNTER_TABLE, 0
	msgbox AlteringCave_Text_DefaultSelected, MSGBOX_DEFAULT
	closemessage
	return

altering_cave_entry SPECIES_ARTICUNO, 1
altering_cave_entry SPECIES_ZAPDOS, 2
altering_cave_entry SPECIES_MOLTRES, 3
altering_cave_entry SPECIES_MEWTWO, 4
altering_cave_entry SPECIES_RAIKOU, 5
altering_cave_entry SPECIES_ENTEI, 6
altering_cave_entry SPECIES_SUICUNE, 7
altering_cave_entry SPECIES_LUGIA, 8
altering_cave_entry SPECIES_HO_OH, 9
altering_cave_entry SPECIES_REGIROCK, 10
altering_cave_entry SPECIES_REGICE, 11
altering_cave_entry SPECIES_REGISTEEL, 12
altering_cave_entry SPECIES_LATIAS, 13
altering_cave_entry SPECIES_LATIOS, 14
altering_cave_entry SPECIES_KYOGRE, 15
altering_cave_entry SPECIES_GROUDON, 16
altering_cave_entry SPECIES_RAYQUAZA, 17
altering_cave_entry SPECIES_UXIE, 18
altering_cave_entry SPECIES_MESPRIT, 19
altering_cave_entry SPECIES_AZELF, 20
altering_cave_entry SPECIES_DIALGA, 21
altering_cave_entry SPECIES_PALKIA, 22
altering_cave_entry SPECIES_HEATRAN, 23
altering_cave_entry SPECIES_REGIGIGAS, 24
altering_cave_entry SPECIES_GIRATINA, 25
altering_cave_entry SPECIES_CRESSELIA, 26
altering_cave_entry SPECIES_COBALION, 27
altering_cave_entry SPECIES_TERRAKION, 28
altering_cave_entry SPECIES_VIRIZION, 29
altering_cave_entry SPECIES_TORNADUS, 30
altering_cave_entry SPECIES_THUNDURUS, 31
altering_cave_entry SPECIES_LANDORUS, 32
altering_cave_entry SPECIES_RESHIRAM, 33
altering_cave_entry SPECIES_ZEKROM, 34
altering_cave_entry SPECIES_KYUREM, 35
altering_cave_entry SPECIES_XERNEAS, 36
altering_cave_entry SPECIES_YVELTAL, 37
altering_cave_entry SPECIES_ZYGARDE, 38
altering_cave_entry SPECIES_TAPU_KOKO, 39
altering_cave_entry SPECIES_TAPU_LELE, 40
altering_cave_entry SPECIES_TAPU_BULU, 41
altering_cave_entry SPECIES_TAPU_FINI, 42
altering_cave_entry SPECIES_COSMOG, 43
altering_cave_entry SPECIES_COSMOEM, 44
altering_cave_entry SPECIES_SOLGALEO, 45
altering_cave_entry SPECIES_LUNALA, 46
altering_cave_entry SPECIES_NECROZMA, 47
altering_cave_entry SPECIES_ZACIAN, 48
altering_cave_entry SPECIES_ZAMAZENTA, 49
altering_cave_entry SPECIES_ETERNATUS, 50
altering_cave_entry SPECIES_KUBFU, 51
altering_cave_entry SPECIES_URSHIFU_SINGLE_STRIKE, 52
altering_cave_entry SPECIES_REGIELEKI, 53
altering_cave_entry SPECIES_REGIDRAGO, 54
altering_cave_entry SPECIES_GLASTRIER, 55
altering_cave_entry SPECIES_SPECTRIER, 56
altering_cave_entry SPECIES_CALYREX, 57
altering_cave_entry SPECIES_ENAMORUS, 58
altering_cave_entry SPECIES_WO_CHIEN, 59
altering_cave_entry SPECIES_CHIEN_PAO, 60
altering_cave_entry SPECIES_TING_LU, 61
altering_cave_entry SPECIES_CHI_YU, 62
altering_cave_entry SPECIES_KORAIDON, 63
altering_cave_entry SPECIES_MIRAIDON, 64
altering_cave_entry SPECIES_OKIDOGI, 65
altering_cave_entry SPECIES_MUNKIDORI, 66
altering_cave_entry SPECIES_FEZANDIPITI, 67
altering_cave_entry SPECIES_OGERPON, 68
altering_cave_entry SPECIES_TERAPAGOS, 69
altering_cave_entry SPECIES_MEW, 70
altering_cave_entry SPECIES_CELEBI, 71
altering_cave_entry SPECIES_JIRACHI, 72
altering_cave_entry SPECIES_DEOXYS, 73
altering_cave_entry SPECIES_PHIONE, 74
altering_cave_entry SPECIES_MANAPHY, 75
altering_cave_entry SPECIES_DARKRAI, 76
altering_cave_entry SPECIES_SHAYMIN, 77
altering_cave_entry SPECIES_ARCEUS, 78
altering_cave_entry SPECIES_VICTINI, 79
altering_cave_entry SPECIES_KELDEO, 80
altering_cave_entry SPECIES_MELOETTA, 81
altering_cave_entry SPECIES_GENESECT, 82
altering_cave_entry SPECIES_DIANCIE, 83
altering_cave_entry SPECIES_HOOPA, 84
altering_cave_entry SPECIES_VOLCANION, 85
altering_cave_entry SPECIES_MAGEARNA, 86
altering_cave_entry SPECIES_MARSHADOW, 87
altering_cave_entry SPECIES_ZERAORA, 88
altering_cave_entry SPECIES_MELTAN, 89
altering_cave_entry SPECIES_MELMETAL, 90
altering_cave_entry SPECIES_ZARUDE, 91
altering_cave_entry SPECIES_PECHARUNT, 92
altering_cave_entry SPECIES_GREAT_TUSK, 93
altering_cave_entry SPECIES_SCREAM_TAIL, 94
altering_cave_entry SPECIES_BRUTE_BONNET, 95
altering_cave_entry SPECIES_FLUTTER_MANE, 96
altering_cave_entry SPECIES_SLITHER_WING, 97
altering_cave_entry SPECIES_SANDY_SHOCKS, 98
altering_cave_entry SPECIES_ROARING_MOON, 99
altering_cave_entry SPECIES_WALKING_WAKE, 100
altering_cave_entry SPECIES_GOUGING_FIRE, 101
altering_cave_entry SPECIES_RAGING_BOLT, 102
altering_cave_entry SPECIES_IRON_TREADS, 103
altering_cave_entry SPECIES_IRON_BUNDLE, 104
altering_cave_entry SPECIES_IRON_HANDS, 105
altering_cave_entry SPECIES_IRON_JUGULIS, 106
altering_cave_entry SPECIES_IRON_MOTH, 107
altering_cave_entry SPECIES_IRON_THORNS, 108
altering_cave_entry SPECIES_IRON_VALIANT, 109
altering_cave_entry SPECIES_IRON_CROWN, 110
altering_cave_entry SPECIES_IRON_BOULDER, 111
altering_cave_entry SPECIES_IRON_LEAVES, 112
altering_cave_entry SPECIES_NIHILEGO, 113
altering_cave_entry SPECIES_BUZZWOLE, 114
altering_cave_entry SPECIES_PHEROMOSA, 115
altering_cave_entry SPECIES_XURKITREE, 116
altering_cave_entry SPECIES_CELESTEELA, 117
altering_cave_entry SPECIES_KARTANA, 118
altering_cave_entry SPECIES_GUZZLORD, 119
altering_cave_entry SPECIES_POIPOLE, 120
altering_cave_entry SPECIES_NAGANADEL, 121
altering_cave_entry SPECIES_STAKATAKA, 122
altering_cave_entry SPECIES_BLACEPHALON, 123
altering_cave_entry SPECIES_URSHIFU_RAPID_STRIKE, 124
altering_cave_entry SPECIES_UNOWN, 125
altering_cave_entry SPECIES_UNOWN_B, 126
altering_cave_entry SPECIES_UNOWN_C, 127
altering_cave_entry SPECIES_UNOWN_D, 128
altering_cave_entry SPECIES_UNOWN_E, 129
altering_cave_entry SPECIES_UNOWN_F, 130
altering_cave_entry SPECIES_UNOWN_G, 131
altering_cave_entry SPECIES_UNOWN_H, 132
altering_cave_entry SPECIES_UNOWN_I, 133
altering_cave_entry SPECIES_UNOWN_J, 134
altering_cave_entry SPECIES_UNOWN_K, 135
altering_cave_entry SPECIES_UNOWN_L, 136
altering_cave_entry SPECIES_UNOWN_M, 137
altering_cave_entry SPECIES_UNOWN_N, 138
altering_cave_entry SPECIES_UNOWN_O, 139
altering_cave_entry SPECIES_UNOWN_P, 140
altering_cave_entry SPECIES_UNOWN_Q, 141
altering_cave_entry SPECIES_UNOWN_R, 142
altering_cave_entry SPECIES_UNOWN_S, 143
altering_cave_entry SPECIES_UNOWN_T, 144
altering_cave_entry SPECIES_UNOWN_U, 145
altering_cave_entry SPECIES_UNOWN_V, 146
altering_cave_entry SPECIES_UNOWN_W, 147
altering_cave_entry SPECIES_UNOWN_X, 148
altering_cave_entry SPECIES_UNOWN_Y, 149
altering_cave_entry SPECIES_UNOWN_Z, 150
altering_cave_entry SPECIES_UNOWN_EXCLAMATION, 151
altering_cave_entry SPECIES_UNOWN_QUESTION, 152

AlteringCave_Text_SPECIES_ARTICUNO:
    .string "ARTICUNO$"
AlteringCave_Text_SPECIES_ZAPDOS:
    .string "ZAPDOS$"
AlteringCave_Text_SPECIES_MOLTRES:
    .string "MOLTRES$"
AlteringCave_Text_SPECIES_MEWTWO:
    .string "MEWTWO$"
AlteringCave_Text_SPECIES_RAIKOU:
    .string "RAIKOU$"
AlteringCave_Text_SPECIES_ENTEI:
    .string "ENTEI$"
AlteringCave_Text_SPECIES_SUICUNE:
    .string "SUICUNE$"
AlteringCave_Text_SPECIES_LUGIA:
    .string "LUGIA$"
AlteringCave_Text_SPECIES_HO_OH:
    .string "HO-OH$"
AlteringCave_Text_SPECIES_REGIROCK:
    .string "REGIROCK$"
AlteringCave_Text_SPECIES_REGICE:
    .string "REGICE$"
AlteringCave_Text_SPECIES_REGISTEEL:
    .string "REGISTEEL$"
AlteringCave_Text_SPECIES_LATIAS:
    .string "LATIAS$"
AlteringCave_Text_SPECIES_LATIOS:
    .string "LATIOS$"
AlteringCave_Text_SPECIES_KYOGRE:
    .string "KYOGRE$"
AlteringCave_Text_SPECIES_GROUDON:
    .string "GROUDON$"
AlteringCave_Text_SPECIES_RAYQUAZA:
    .string "RAYQUAZA$"
AlteringCave_Text_SPECIES_UXIE:
    .string "UXIE$"
AlteringCave_Text_SPECIES_MESPRIT:
    .string "MESPRIT$"
AlteringCave_Text_SPECIES_AZELF:
    .string "AZELF$"
AlteringCave_Text_SPECIES_DIALGA:
    .string "DIALGA$"
AlteringCave_Text_SPECIES_PALKIA:
    .string "PALKIA$"
AlteringCave_Text_SPECIES_HEATRAN:
    .string "HEATRAN$"
AlteringCave_Text_SPECIES_REGIGIGAS:
    .string "REGIGIGAS$"
AlteringCave_Text_SPECIES_GIRATINA:
    .string "GIRATINA$"
AlteringCave_Text_SPECIES_CRESSELIA:
    .string "CRESSELIA$"
AlteringCave_Text_SPECIES_COBALION:
    .string "COBALION$"
AlteringCave_Text_SPECIES_TERRAKION:
    .string "TERRAKION$"
AlteringCave_Text_SPECIES_VIRIZION:
    .string "VIRIZION$"
AlteringCave_Text_SPECIES_TORNADUS:
    .string "TORNADUS$"
AlteringCave_Text_SPECIES_THUNDURUS:
    .string "THUNDURUS$"
AlteringCave_Text_SPECIES_LANDORUS:
    .string "LANDORUS$"
AlteringCave_Text_SPECIES_RESHIRAM:
    .string "RESHIRAM$"
AlteringCave_Text_SPECIES_ZEKROM:
    .string "ZEKROM$"
AlteringCave_Text_SPECIES_KYUREM:
    .string "KYUREM$"
AlteringCave_Text_SPECIES_XERNEAS:
    .string "XERNEAS$"
AlteringCave_Text_SPECIES_YVELTAL:
    .string "YVELTAL$"
AlteringCave_Text_SPECIES_ZYGARDE:
    .string "ZYGARDE$"
AlteringCave_Text_SPECIES_TAPU_KOKO:
    .string "TAPU KOKO$"
AlteringCave_Text_SPECIES_TAPU_LELE:
    .string "TAPU LELE$"
AlteringCave_Text_SPECIES_TAPU_BULU:
    .string "TAPU BULU$"
AlteringCave_Text_SPECIES_TAPU_FINI:
    .string "TAPU FINI$"
AlteringCave_Text_SPECIES_COSMOG:
    .string "COSMOG$"
AlteringCave_Text_SPECIES_COSMOEM:
    .string "COSMOEM$"
AlteringCave_Text_SPECIES_SOLGALEO:
    .string "SOLGALEO$"
AlteringCave_Text_SPECIES_LUNALA:
    .string "LUNALA$"
AlteringCave_Text_SPECIES_NECROZMA:
    .string "NECROZMA$"
AlteringCave_Text_SPECIES_ZACIAN:
    .string "ZACIAN$"
AlteringCave_Text_SPECIES_ZAMAZENTA:
    .string "ZAMAZENTA$"
AlteringCave_Text_SPECIES_ETERNATUS:
    .string "ETERNATUS$"
AlteringCave_Text_SPECIES_KUBFU:
    .string "KUBFU$"
AlteringCave_Text_SPECIES_URSHIFU_SINGLE_STRIKE:
    .string "URSHIFU SINGLE STRIKE$"
AlteringCave_Text_SPECIES_URSHIFU_RAPID_STRIKE:
    .string "URSHIFU RAPID STRIKE$"
AlteringCave_Text_SPECIES_REGIELEKI:
    .string "REGIELEKI$"
AlteringCave_Text_SPECIES_REGIDRAGO:
    .string "REGIDRAGO$"
AlteringCave_Text_SPECIES_GLASTRIER:
    .string "GLASTRIER$"
AlteringCave_Text_SPECIES_SPECTRIER:
    .string "SPECTRIER$"
AlteringCave_Text_SPECIES_CALYREX:
    .string "CALYREX$"
AlteringCave_Text_SPECIES_ENAMORUS:
    .string "ENAMORUS$"
AlteringCave_Text_SPECIES_WO_CHIEN:
    .string "WO-CHIEN$"
AlteringCave_Text_SPECIES_CHIEN_PAO:
    .string "CHIEN-PAO$"
AlteringCave_Text_SPECIES_TING_LU:
    .string "TING-LU$"
AlteringCave_Text_SPECIES_CHI_YU:
    .string "CHI-YU$"
AlteringCave_Text_SPECIES_KORAIDON:
    .string "KORAIDON$"
AlteringCave_Text_SPECIES_MIRAIDON:
    .string "MIRAIDON$"
AlteringCave_Text_SPECIES_OKIDOGI:
    .string "OKIDOGI$"
AlteringCave_Text_SPECIES_MUNKIDORI:
    .string "MUNKIDORI$"
AlteringCave_Text_SPECIES_FEZANDIPITI:
    .string "FEZANDIPITI$"
AlteringCave_Text_SPECIES_OGERPON:
    .string "OGERPON$"
AlteringCave_Text_SPECIES_TERAPAGOS:
    .string "TERAPAGOS$"
AlteringCave_Text_SPECIES_MEW:
    .string "MEW$"
AlteringCave_Text_SPECIES_CELEBI:
    .string "CELEBI$"
AlteringCave_Text_SPECIES_JIRACHI:
    .string "JIRACHI$"
AlteringCave_Text_SPECIES_DEOXYS:
    .string "DEOXYS$"
AlteringCave_Text_SPECIES_PHIONE:
    .string "PHIONE$"
AlteringCave_Text_SPECIES_MANAPHY:
    .string "MANAPHY$"
AlteringCave_Text_SPECIES_DARKRAI:
    .string "DARKRAI$"
AlteringCave_Text_SPECIES_SHAYMIN:
    .string "SHAYMIN$"
AlteringCave_Text_SPECIES_ARCEUS:
    .string "ARCEUS$"
AlteringCave_Text_SPECIES_VICTINI:
    .string "VICTINI$"
AlteringCave_Text_SPECIES_KELDEO:
    .string "KELDEO$"
AlteringCave_Text_SPECIES_MELOETTA:
    .string "MELOETTA$"
AlteringCave_Text_SPECIES_GENESECT:
    .string "GENESECT$"
AlteringCave_Text_SPECIES_DIANCIE:
    .string "DIANCIE$"
AlteringCave_Text_SPECIES_HOOPA:
    .string "HOOPA$"
AlteringCave_Text_SPECIES_VOLCANION:
    .string "VOLCANION$"
AlteringCave_Text_SPECIES_MAGEARNA:
    .string "MAGEARNA$"
AlteringCave_Text_SPECIES_MARSHADOW:
    .string "MARSHADOW$"
AlteringCave_Text_SPECIES_ZERAORA:
    .string "ZERAORA$"
AlteringCave_Text_SPECIES_MELTAN:
    .string "MELTAN$"
AlteringCave_Text_SPECIES_MELMETAL:
    .string "MELMETAL$"
AlteringCave_Text_SPECIES_ZARUDE:
    .string "ZARUDE$"
AlteringCave_Text_SPECIES_PECHARUNT:
    .string "PECHARUNT$"
AlteringCave_Text_SPECIES_GREAT_TUSK:
    .string "GREAT TUSK$"
AlteringCave_Text_SPECIES_SCREAM_TAIL:
    .string "SCREAM TAIL$"
AlteringCave_Text_SPECIES_BRUTE_BONNET:
    .string "BRUTE BONNET$"
AlteringCave_Text_SPECIES_FLUTTER_MANE:
    .string "FLUTTER MANE$"
AlteringCave_Text_SPECIES_SLITHER_WING:
    .string "SLITHER WING$"
AlteringCave_Text_SPECIES_SANDY_SHOCKS:
    .string "SANDY SHOCKS$"
AlteringCave_Text_SPECIES_ROARING_MOON:
    .string "ROARING MOON$"
AlteringCave_Text_SPECIES_WALKING_WAKE:
    .string "WALKING WAKE$"
AlteringCave_Text_SPECIES_GOUGING_FIRE:
    .string "GOUGING FIRE$"
AlteringCave_Text_SPECIES_RAGING_BOLT:
    .string "RAGING BOLT$"
AlteringCave_Text_SPECIES_IRON_TREADS:
    .string "IRON TREADS$"
AlteringCave_Text_SPECIES_IRON_BUNDLE:
    .string "IRON BUNDLE$"
AlteringCave_Text_SPECIES_IRON_HANDS:
    .string "IRON HANDS$"
AlteringCave_Text_SPECIES_IRON_JUGULIS:
    .string "IRON JUGULIS$"
AlteringCave_Text_SPECIES_IRON_MOTH:
    .string "IRON MOTH$"
AlteringCave_Text_SPECIES_IRON_THORNS:
    .string "IRON THORNS$"
AlteringCave_Text_SPECIES_IRON_VALIANT:
    .string "IRON VALIANT$"
AlteringCave_Text_SPECIES_IRON_CROWN:
    .string "IRON CROWN$"
AlteringCave_Text_SPECIES_IRON_BOULDER:
    .string "IRON BOULDER$"
AlteringCave_Text_SPECIES_IRON_LEAVES:
    .string "IRON LEAVES$"
AlteringCave_Text_SPECIES_NIHILEGO:
    .string "NIHILEGO$"
AlteringCave_Text_SPECIES_BUZZWOLE:
    .string "BUZZWOLE$"
AlteringCave_Text_SPECIES_PHEROMOSA:
    .string "PHEROMOSA$"
AlteringCave_Text_SPECIES_XURKITREE:
    .string "XURKITREE$"
AlteringCave_Text_SPECIES_CELESTEELA:
    .string "CELESTEELA$"
AlteringCave_Text_SPECIES_KARTANA:
    .string "KARTANA$"
AlteringCave_Text_SPECIES_GUZZLORD:
    .string "GUZZLORD$"
AlteringCave_Text_SPECIES_POIPOLE:
    .string "POIPOLE$"
AlteringCave_Text_SPECIES_NAGANADEL:
    .string "NAGANADEL$"
AlteringCave_Text_SPECIES_STAKATAKA:
    .string "STAKATAKA$"
AlteringCave_Text_SPECIES_BLACEPHALON:
    .string "BLACEPHALON$"
AlteringCave_Text_SPECIES_UNOWN:
    .string "UNOWN A$"
AlteringCave_Text_SPECIES_UNOWN_B:
    .string "UNOWN B$"
AlteringCave_Text_SPECIES_UNOWN_C:
    .string "UNOWN C$"
AlteringCave_Text_SPECIES_UNOWN_D:
    .string "UNOWN D$"
AlteringCave_Text_SPECIES_UNOWN_E:
    .string "UNOWN E$"
AlteringCave_Text_SPECIES_UNOWN_F:
    .string "UNOWN F$"
AlteringCave_Text_SPECIES_UNOWN_G:
    .string "UNOWN G$"
AlteringCave_Text_SPECIES_UNOWN_H:
    .string "UNOWN H$"
AlteringCave_Text_SPECIES_UNOWN_I:
    .string "UNOWN I$"
AlteringCave_Text_SPECIES_UNOWN_J:
    .string "UNOWN J$"
AlteringCave_Text_SPECIES_UNOWN_K:
    .string "UNOWN K$"
AlteringCave_Text_SPECIES_UNOWN_L:
    .string "UNOWN L$"
AlteringCave_Text_SPECIES_UNOWN_M:
    .string "UNOWN M$"
AlteringCave_Text_SPECIES_UNOWN_N:
    .string "UNOWN N$"
AlteringCave_Text_SPECIES_UNOWN_O:
    .string "UNOWN O$"
AlteringCave_Text_SPECIES_UNOWN_P:
    .string "UNOWN P$"
AlteringCave_Text_SPECIES_UNOWN_Q:
    .string "UNOWN Q$"
AlteringCave_Text_SPECIES_UNOWN_R:
    .string "UNOWN R$"
AlteringCave_Text_SPECIES_UNOWN_S:
    .string "UNOWN S$"
AlteringCave_Text_SPECIES_UNOWN_T:
    .string "UNOWN T$"
AlteringCave_Text_SPECIES_UNOWN_U:
    .string "UNOWN U$"
AlteringCave_Text_SPECIES_UNOWN_V:
    .string "UNOWN V$"
AlteringCave_Text_SPECIES_UNOWN_W:
    .string "UNOWN W$"
AlteringCave_Text_SPECIES_UNOWN_X:
    .string "UNOWN X$"
AlteringCave_Text_SPECIES_UNOWN_Y:
    .string "UNOWN Y$"
AlteringCave_Text_SPECIES_UNOWN_Z:
    .string "UNOWN Z$"
AlteringCave_Text_SPECIES_UNOWN_EXCLAMATION:
    .string "UNOWN !$"
AlteringCave_Text_SPECIES_UNOWN_QUESTION:
    .string "UNOWN ?$"
AlteringCave_Text_Kanto:
	.string "KANTO$"
AlteringCave_Text_Johto:
	.string "JOHTO$"
AlteringCave_Text_Hoenn:
	.string "HOENN$"
AlteringCave_Text_Sinnoh:
	.string "SINNOH$"
AlteringCave_Text_Unova:
	.string "UNOVA$"
AlteringCave_Text_Kalos:
	.string "KALOS$"
AlteringCave_Text_Alola:
	.string "ALOLA$"
AlteringCave_Text_Galar:
	.string "GALAR$"
AlteringCave_Text_Hisui:
	.string "HISUI$"
AlteringCave_Text_Paldea:
	.string "PALDEA$"
AlteringCave_Text_ParadoxPokemon:
	.string "PARADOX POKEMON$"
AlteringCave_Text_UltraBeasts:
	.string "ULTRA BEASTS$"
AlteringCave_Text_UnownForms:
	.string "UNOWN FORMS$"
AlteringCave_Text_Default:
	.string "DEFAULT$"
AlteringCave_Text_EncounterSelected:
	.string "The cave's wild POKEMON are now\n"
	.string "{STR_VAR_1}!$"
AlteringCave_Text_ExploreMore:
	.string "Explore the World a bit more.$"
AlteringCave_Text_DefaultSelected:
	.string "The Cave has been set to normal.$"

.purgem altering_cave_push
.purgem altering_cave_case
.purgem altering_cave_entry
