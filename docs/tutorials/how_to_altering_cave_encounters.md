# Altering Cave Encounter Tables

Altering Cave selects its land encounter table using `VAR_ENCOUNTER_TABLE`.
The variable is a zero-based offset from the table number:

- `0` selects `gAlteringCave1`, which remains the Zubat fallback table.
- Values `1` through `152` select `gAlteringCave2` through `gAlteringCave153`.
- Values outside this range fall back to `gAlteringCave1`.

Each special table contains one species at level 50. The first column in the
lists below is the exact value to assign to `VAR_ENCOUNTER_TABLE` for that
Pokemon. Set it before entering Altering Cave. For example, to select Articuno:

```asm
setvar VAR_ENCOUNTER_TABLE, 1
```

Set it to `0` to use the default Zubat table.

## In-Game Selector NPC

Call `AlteringCave_EventScript_SelectEncounter` from an NPC script to let the
player choose an encounter in-game. The selector lists Pokemon by region and
shows the highlighted Pokemon's icon. It includes a separate Paradox Pokemon
and Ultra Beast section, plus the default Zubat encounter.

```asm
MyNpc_EventScript_ChooseCaveEncounter::
	lock
	faceplayer
	call AlteringCave_EventScript_SelectEncounter
	release
	end
```

The selected value is saved to `VAR_ENCOUNTER_TABLE`.

Each non-default category is shown only when its corresponding flag is set.
All category flags are unset by default. Set the flags for the categories you
want the selector to offer:

| Category | Flag |
|---|---|
| Kanto | `FLAG_ALTERING_CAVE_REGION_KANTO` |
| Johto | `FLAG_ALTERING_CAVE_REGION_JOHTO` |
| Hoenn | `FLAG_ALTERING_CAVE_REGION_HOENN` |
| Sinnoh | `FLAG_ALTERING_CAVE_REGION_SINNOH` |
| Unova | `FLAG_ALTERING_CAVE_REGION_UNOVA` |
| Kalos | `FLAG_ALTERING_CAVE_REGION_KALOS` |
| Alola | `FLAG_ALTERING_CAVE_REGION_ALOLA` |
| Galar | `FLAG_ALTERING_CAVE_REGION_GALAR` |
| Hisui | `FLAG_ALTERING_CAVE_REGION_HISUI` |
| Paldea | `FLAG_ALTERING_CAVE_REGION_PALDEA` |
| Paradox Pokemon | `FLAG_ALTERING_CAVE_REGION_PARADOX` |
| Ultra Beasts | `FLAG_ALTERING_CAVE_REGION_ULTRA_BEASTS` |
| Unown Forms | `FLAG_ALTERING_CAVE_REGION_UNOWN` |

For example, set the Kanto and Unown options with:

```asm
setflag FLAG_ALTERING_CAVE_REGION_KANTO
setflag FLAG_ALTERING_CAVE_REGION_UNOWN
```

`DEFAULT (ZUBAT)` is always available, regardless of these flags.

## Legendary Pokemon

| `VAR_ENCOUNTER_TABLE` | Table | Pokemon |
|---:|---|---|
| 1 | `gAlteringCave2` | Articuno |
| 2 | `gAlteringCave3` | Zapdos |
| 3 | `gAlteringCave4` | Moltres |
| 4 | `gAlteringCave5` | Mewtwo |
| 5 | `gAlteringCave6` | Raikou |
| 6 | `gAlteringCave7` | Entei |
| 7 | `gAlteringCave8` | Suicune |
| 8 | `gAlteringCave9` | Lugia |
| 9 | `gAlteringCave10` | Ho-Oh |
| 10 | `gAlteringCave11` | Regirock |
| 11 | `gAlteringCave12` | Regice |
| 12 | `gAlteringCave13` | Registeel |
| 13 | `gAlteringCave14` | Latias |
| 14 | `gAlteringCave15` | Latios |
| 15 | `gAlteringCave16` | Kyogre |
| 16 | `gAlteringCave17` | Groudon |
| 17 | `gAlteringCave18` | Rayquaza |
| 18 | `gAlteringCave19` | Uxie |
| 19 | `gAlteringCave20` | Mesprit |
| 20 | `gAlteringCave21` | Azelf |
| 21 | `gAlteringCave22` | Dialga |
| 22 | `gAlteringCave23` | Palkia |
| 23 | `gAlteringCave24` | Heatran |
| 24 | `gAlteringCave25` | Regigigas |
| 25 | `gAlteringCave26` | Giratina |
| 26 | `gAlteringCave27` | Cresselia |
| 27 | `gAlteringCave28` | Cobalion |
| 28 | `gAlteringCave29` | Terrakion |
| 29 | `gAlteringCave30` | Virizion |
| 30 | `gAlteringCave31` | Tornadus |
| 31 | `gAlteringCave32` | Thundurus |
| 32 | `gAlteringCave33` | Landorus |
| 33 | `gAlteringCave34` | Reshiram |
| 34 | `gAlteringCave35` | Zekrom |
| 35 | `gAlteringCave36` | Kyurem |
| 36 | `gAlteringCave37` | Xerneas |
| 37 | `gAlteringCave38` | Yveltal |
| 38 | `gAlteringCave39` | Zygarde |
| 39 | `gAlteringCave40` | Tapu Koko |
| 40 | `gAlteringCave41` | Tapu Lele |
| 41 | `gAlteringCave42` | Tapu Bulu |
| 42 | `gAlteringCave43` | Tapu Fini |
| 43 | `gAlteringCave44` | Cosmog |
| 44 | `gAlteringCave45` | Cosmoem |
| 45 | `gAlteringCave46` | Solgaleo |
| 46 | `gAlteringCave47` | Lunala |
| 47 | `gAlteringCave48` | Necrozma |
| 48 | `gAlteringCave49` | Zacian |
| 49 | `gAlteringCave50` | Zamazenta |
| 50 | `gAlteringCave51` | Eternatus |
| 51 | `gAlteringCave52` | Kubfu |
| 52 | `gAlteringCave53` | Urshifu (Single Strike Style) |
| 53 | `gAlteringCave54` | Regieleki |
| 54 | `gAlteringCave55` | Regidrago |
| 55 | `gAlteringCave56` | Glastrier |
| 56 | `gAlteringCave57` | Spectrier |
| 57 | `gAlteringCave58` | Calyrex |
| 58 | `gAlteringCave59` | Enamorus |
| 59 | `gAlteringCave60` | Wo-Chien |
| 60 | `gAlteringCave61` | Chien-Pao |
| 61 | `gAlteringCave62` | Ting-Lu |
| 62 | `gAlteringCave63` | Chi-Yu |
| 63 | `gAlteringCave64` | Koraidon |
| 64 | `gAlteringCave65` | Miraidon |
| 65 | `gAlteringCave66` | Okidogi |
| 66 | `gAlteringCave67` | Munkidori |
| 67 | `gAlteringCave68` | Fezandipiti |
| 68 | `gAlteringCave69` | Ogerpon |
| 69 | `gAlteringCave70` | Terapagos |

## Mythical Pokemon

| `VAR_ENCOUNTER_TABLE` | Table | Pokemon |
|---:|---|---|
| 70 | `gAlteringCave71` | Mew |
| 71 | `gAlteringCave72` | Celebi |
| 72 | `gAlteringCave73` | Jirachi |
| 73 | `gAlteringCave74` | Deoxys |
| 74 | `gAlteringCave75` | Phione |
| 75 | `gAlteringCave76` | Manaphy |
| 76 | `gAlteringCave77` | Darkrai |
| 77 | `gAlteringCave78` | Shaymin |
| 78 | `gAlteringCave79` | Arceus |
| 79 | `gAlteringCave80` | Victini |
| 80 | `gAlteringCave81` | Keldeo |
| 81 | `gAlteringCave82` | Meloetta |
| 82 | `gAlteringCave83` | Genesect |
| 83 | `gAlteringCave84` | Diancie |
| 84 | `gAlteringCave85` | Hoopa |
| 85 | `gAlteringCave86` | Volcanion |
| 86 | `gAlteringCave87` | Magearna |
| 87 | `gAlteringCave88` | Marshadow |
| 88 | `gAlteringCave89` | Zeraora |
| 89 | `gAlteringCave90` | Meltan |
| 90 | `gAlteringCave91` | Melmetal |
| 91 | `gAlteringCave92` | Zarude |
| 92 | `gAlteringCave93` | Pecharunt |

## Paradox Pokemon

| `VAR_ENCOUNTER_TABLE` | Table | Pokemon |
|---:|---|---|
| 93 | `gAlteringCave94` | Great Tusk |
| 94 | `gAlteringCave95` | Scream Tail |
| 95 | `gAlteringCave96` | Brute Bonnet |
| 96 | `gAlteringCave97` | Flutter Mane |
| 97 | `gAlteringCave98` | Slither Wing |
| 98 | `gAlteringCave99` | Sandy Shocks |
| 99 | `gAlteringCave100` | Roaring Moon |
| 100 | `gAlteringCave101` | Walking Wake |
| 101 | `gAlteringCave102` | Gouging Fire |
| 102 | `gAlteringCave103` | Raging Bolt |
| 103 | `gAlteringCave104` | Iron Treads |
| 104 | `gAlteringCave105` | Iron Bundle |
| 105 | `gAlteringCave106` | Iron Hands |
| 106 | `gAlteringCave107` | Iron Jugulis |
| 107 | `gAlteringCave108` | Iron Moth |
| 108 | `gAlteringCave109` | Iron Thorns |
| 109 | `gAlteringCave110` | Iron Valiant |
| 110 | `gAlteringCave111` | Iron Crown |
| 111 | `gAlteringCave112` | Iron Boulder |
| 112 | `gAlteringCave113` | Iron Leaves |

## Ultra Beasts

| `VAR_ENCOUNTER_TABLE` | Table | Pokemon |
|---:|---|---|
| 113 | `gAlteringCave114` | Nihilego |
| 114 | `gAlteringCave115` | Buzzwole |
| 115 | `gAlteringCave116` | Pheromosa |
| 116 | `gAlteringCave117` | Xurkitree |
| 117 | `gAlteringCave118` | Celesteela |
| 118 | `gAlteringCave119` | Kartana |
| 119 | `gAlteringCave120` | Guzzlord |
| 120 | `gAlteringCave121` | Poipole |
| 121 | `gAlteringCave122` | Naganadel |
| 122 | `gAlteringCave123` | Stakataka |
| 123 | `gAlteringCave124` | Blacephalon |
| 124 | `gAlteringCave125` | Urshifu (Rapid Strike Style) |

## Unown Forms

| `VAR_ENCOUNTER_TABLE` | Table | Pokemon |
|---:|---|---|
| 125 | `gAlteringCave126` | Unown A |
| 126 | `gAlteringCave127` | Unown B |
| 127 | `gAlteringCave128` | Unown C |
| 128 | `gAlteringCave129` | Unown D |
| 129 | `gAlteringCave130` | Unown E |
| 130 | `gAlteringCave131` | Unown F |
| 131 | `gAlteringCave132` | Unown G |
| 132 | `gAlteringCave133` | Unown H |
| 133 | `gAlteringCave134` | Unown I |
| 134 | `gAlteringCave135` | Unown J |
| 135 | `gAlteringCave136` | Unown K |
| 136 | `gAlteringCave137` | Unown L |
| 137 | `gAlteringCave138` | Unown M |
| 138 | `gAlteringCave139` | Unown N |
| 139 | `gAlteringCave140` | Unown O |
| 140 | `gAlteringCave141` | Unown P |
| 141 | `gAlteringCave142` | Unown Q |
| 142 | `gAlteringCave143` | Unown R |
| 143 | `gAlteringCave144` | Unown S |
| 144 | `gAlteringCave145` | Unown T |
| 145 | `gAlteringCave146` | Unown U |
| 146 | `gAlteringCave147` | Unown V |
| 147 | `gAlteringCave148` | Unown W |
| 148 | `gAlteringCave149` | Unown X |
| 149 | `gAlteringCave150` | Unown Y |
| 150 | `gAlteringCave151` | Unown Z |
| 151 | `gAlteringCave152` | Unown ! |
| 152 | `gAlteringCave153` | Unown ? |
