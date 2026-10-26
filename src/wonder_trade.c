#include "global.h"
#include "event_data.h"
#include "pokemon.h"
#include "random.h"
#include "random_mon_generation.h"
#include "script.h"
#include "string_util.h"
#include "trade.h"
#include "wonder_trade.h"
#include "constants/items.h"
#include "constants/pokemon.h"
#include "constants/random_mon_generation.h"
#include "constants/species.h"
#include "constants/wonder_trade.h"

static const enum Item sWonderTradeItems[] =
{
    ITEM_NONE,
    ITEM_CHERI_BERRY,
    ITEM_CHESTO_BERRY,
    ITEM_PECHA_BERRY,
    ITEM_RAWST_BERRY,
    ITEM_ASPEAR_BERRY,
    ITEM_LEPPA_BERRY,
    ITEM_ORAN_BERRY,
    ITEM_PERSIM_BERRY,
    ITEM_LUM_BERRY,
    ITEM_SITRUS_BERRY,
    ITEM_FIGY_BERRY,
    ITEM_WIKI_BERRY,
    ITEM_MAGO_BERRY,
    ITEM_AGUAV_BERRY,
    ITEM_IAPAPA_BERRY,
    ITEM_RAZZ_BERRY,
    ITEM_BLUK_BERRY,
    ITEM_NANAB_BERRY,
    ITEM_WEPEAR_BERRY,
    ITEM_PINAP_BERRY,
    ITEM_POMEG_BERRY,
    ITEM_KELPSY_BERRY,
    ITEM_QUALOT_BERRY,
    ITEM_HONDEW_BERRY,
    ITEM_GREPA_BERRY,
    ITEM_TAMATO_BERRY,
    ITEM_CORNN_BERRY,
    ITEM_MAGOST_BERRY,
    ITEM_RABUTA_BERRY,
    ITEM_NOMEL_BERRY,
    ITEM_SPELON_BERRY,
    ITEM_PAMTRE_BERRY,
    ITEM_WATMEL_BERRY,
    ITEM_DURIN_BERRY,
    ITEM_BELUE_BERRY,
    ITEM_CHILAN_BERRY,
    ITEM_OCCA_BERRY,
    ITEM_PASSHO_BERRY,
    ITEM_WACAN_BERRY,
    ITEM_RINDO_BERRY,
    ITEM_YACHE_BERRY,
    ITEM_CHOPLE_BERRY,
    ITEM_KEBIA_BERRY,
    ITEM_SHUCA_BERRY,
    ITEM_COBA_BERRY,
    ITEM_PAYAPA_BERRY,
    ITEM_TANGA_BERRY,
    ITEM_CHARTI_BERRY,
    ITEM_KASIB_BERRY,
    ITEM_HABAN_BERRY,
    ITEM_COLBUR_BERRY,
    ITEM_BABIRI_BERRY,
    ITEM_ROSELI_BERRY,
    ITEM_LIECHI_BERRY,
    ITEM_GANLON_BERRY,
    ITEM_SALAC_BERRY,
    ITEM_PETAYA_BERRY,
    ITEM_APICOT_BERRY,
    ITEM_LANSAT_BERRY,
    ITEM_STARF_BERRY,
    ITEM_ENIGMA_BERRY,
    ITEM_MICLE_BERRY,
    ITEM_CUSTAP_BERRY,
    ITEM_JABOCA_BERRY,
    ITEM_ROWAP_BERRY,
    ITEM_KEE_BERRY,
    ITEM_MARANGA_BERRY,
    ITEM_ENIGMA_BERRY_E_READER,
};

static const u8 sWonderTradeMaleOtNames[][TRAINER_NAME_LENGTH + 1] =
{
    _("ASH"),
    _("RED"),
    _("BLUE"),
    _("GARY"),
    _("GOLD"),
    _("ETHAN"),
    _("SILVER"),
    _("BRENDAN"),
    _("LUCAS"),
    _("HILBERT"),
    _("NATE"),
    _("CALEM"),
    _("ELIO"),
    _("CHASE"),
    _("VICTOR"),
    _("REI"),
    _("FLORIAN"),
    _("PAXTON"),
    _("WALLY"),
    _("BARRY"),
    _("CHEREN"),
    _("N"),
    _("HUGH"),
    _("HOP"),
    _("BEDE"),
    _("AVERY"),
    _("ARVEN"),
    _("KIERAN"),
    _("URBAIN"),
    _("WES"),
    _("NATE"),
    _("WILLEM"),
};

static const u8 sWonderTradeFemaleOtNames[][TRAINER_NAME_LENGTH + 1] =
{
    _("LEAF"),
    _("KRIS"),
    _("LYRA"),
    _("MAY"),
    _("DAWN"),
    _("HILDA"),
    _("SERENA"),
    _("SELENE"),
    _("ELAINE"),
    _("GLORIA"),
    _("AKARI"),
    _("JULIANA"),
    _("HARMONY"),
    _("BIANCA"),
    _("SHAUNA"),
    _("MARNIE"),
    _("NEMONA"),
    _("CARMINE"),
    _("TAUNIE"),
    _("CINDY"),
    _("BECCA"),
};

static enum Species GetRandomWonderTradeSpecies(void)
{
    const struct FilterFuncArgs filterFuncArgs = {0};
    return GetRandomSpecies(SPECIES_GENERATOR_NO_SUPERMONS, &filterFuncArgs);
}

static u8 GetRandomWonderTradeAbilityNum(enum Species species)
{
    u8 abilitySlots[NUM_ABILITY_SLOTS];
    u8 abilityCount = 0;

    for (u8 i = 0; i < NUM_ABILITY_SLOTS; i++)
    {
        if (GetSpeciesAbility(species, i) != ABILITY_NONE)
            abilitySlots[abilityCount++] = i;
    }

    if (abilityCount == 0)
        return 0;

    return abilitySlots[RandomUniform(RNG_NONE, 0, abilityCount - 1)];
}

static u32 GetRandomWonderTradeOtId(void)
{
    u32 otId;

    do
    {
        otId = Random32();
    } while ((u16)otId == (u16)READ_OTID_FROM_SAVE);

    return otId;
}

u32 WonderTradeSelectedMon(void)
{
    u16 selectedSlot = gSpecialVar_0x8004;
    struct Pokemon receivedMon;
    enum Species receivedSpecies;
    u8 level;
    u8 abilityNum;
    u8 otGender;
    u8 heldItem[2];
    u8 otName[TRAINER_NAME_LENGTH + 1];
    u32 otId;

    if (selectedSlot >= PARTY_SIZE || selectedSlot >= gPartiesCount[B_TRAINER_PLAYER])
        return WONDER_TRADE_INVALID_MON;

    struct Pokemon *offeredMon = &gParties[B_TRAINER_PLAYER][selectedSlot];
    enum Species offeredSpecies = GetMonData(offeredMon, MON_DATA_SPECIES_OR_EGG);
    if (offeredSpecies == SPECIES_NONE || offeredSpecies == SPECIES_EGG)
        return WONDER_TRADE_INVALID_MON;

    receivedSpecies = GetRandomWonderTradeSpecies();
    if (receivedSpecies == SPECIES_NONE)
        return WONDER_TRADE_NO_ELIGIBLE_SPECIES;

    level = GetMonData(offeredMon, MON_DATA_LEVEL);
    abilityNum = GetRandomWonderTradeAbilityNum(receivedSpecies);

    otGender = RandomUniform(RNG_NONE, 0, GENDER_COUNT - 1);
    if (otGender == MALE)
        StringCopy(otName, sWonderTradeMaleOtNames[RandomUniform(RNG_NONE, 0, ARRAY_COUNT(sWonderTradeMaleOtNames) - 1)]);
    else
        StringCopy(otName, sWonderTradeFemaleOtNames[RandomUniform(RNG_NONE, 0, ARRAY_COUNT(sWonderTradeFemaleOtNames) - 1)]);
    otId = GetRandomWonderTradeOtId();

    u32 personality = GetMonPersonality(receivedSpecies, MON_GENDER_RANDOM, NATURE_RANDOM, RANDOM_UNOWN_LETTER);
    CreateMonWithIVs(&receivedMon, receivedSpecies, level, personality, OTID_STRUCT_PRESET(otId), USE_RANDOM_IVS);
    GiveMonInitialMoveset(&receivedMon);
    SetMonData(&receivedMon, MON_DATA_ABILITY_NUM, &abilityNum);
    SetMonData(&receivedMon, MON_DATA_OT_NAME, otName);
    SetMonData(&receivedMon, MON_DATA_OT_GENDER, &otGender);

    enum Item item = sWonderTradeItems[RandomUniform(RNG_NONE, 0, ARRAY_COUNT(sWonderTradeItems) - 1)];
    heldItem[0] = item;
    heldItem[1] = item >> 8;
    SetMonData(&receivedMon, MON_DATA_HELD_ITEM, heldItem);

    GetMonData(offeredMon, MON_DATA_NICKNAME, gStringVar1);
    StringCopy(gStringVar2, GetSpeciesName(receivedSpecies));
    StringCopy(gStringVar3, otName);
    gParties[B_TRAINER_OPPONENT_A][0] = receivedMon;

    return WONDER_TRADE_SUCCESS;
}

void WonderTradeBufferSuccessText(void)
{
    struct Pokemon *tradedMon = &gParties[B_TRAINER_OPPONENT_A][0];
    struct Pokemon *receivedMon = &gParties[B_TRAINER_PLAYER][gSelectedTradeMonPositions[TRADE_PLAYER]];

    GetMonData(tradedMon, MON_DATA_NICKNAME, gStringVar1);
    StringCopy(gStringVar2, GetSpeciesName(GetMonData(receivedMon, MON_DATA_SPECIES)));
    GetMonData(receivedMon, MON_DATA_OT_NAME, gStringVar3);
}
