# How to use the Wonder Trade script

Wonder Trade is a reusable event script. Attach `call EventScript_WonderTrade` to any NPC or other script trigger in a map's `scripts.inc`. Initiating the trade asks for confirmation; The received pokemon is a randomized Pokémon at the same level as the one offered.

Edit the tables near the top of `src/wonder_trade.c` to customize:

- The nine `sWonderTrade*Species` arrays list the starters for each region, from Kanto through Paldea. Wonder Trade chooses a region at random, then chooses one eligible pokémon from that region (listed in each array). Only species in the regional arrays are checked; Disabled, legendary, mythical, Paradox, Ultra Beast, and battle-only forms (such as Mega, Primal, Totem, and Gigantamax forms) are filtered out.
- `sWonderTradeItems`: the possible held items. Include `ITEM_NONE` to allow a Pokémon to arrive without an item (by default, if the pokemon has an item, it will allways be a random berry).
- `sWonderTradeOtNames`: male and female original-trainer name pools.

The returned Pokémon receives random IVs, nature, available ability (including a hidden ability), shiny status, trainer gender/name/ID, and held item. The random trainer ID is guaranteed not to equal the player's ID. Eggs cannot be offered. `EventScript_WonderTrade` is defined in `data/scripts/wonder_trade.inc`; the script helper is registered in `data/specials.inc`.
