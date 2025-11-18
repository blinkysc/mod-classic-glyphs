# ![logo](https://raw.githubusercontent.com/azerothcore/azerothcore.github.io/master/images/logo-github.png) AzerothCore

## Classic Glyphs Module

WotLK Classic 3.4.3 glyphs for 3.3.5a by repurposing existing glyphs.

## Glyphs

**Glyph of Omen of Clarity** (Item 40899 - Glyph of Growl repurposed)
- Faerie Fire (Feral) triggers Clearcasting
- Requires Omen of Clarity talent
- NPCs only, not players/pets

**Glyph of Reckoning** (Item 45743 - Glyph of Divine Storm repurposed)
- Hand of Reckoning doesn't taunt
- Damages untauntable targets

## Installation

1. Place module in `modules/mod-classic-glyphs/`
2. Rebuild AzerothCore
3. Restart worldserver (SQL auto-applies from `data/sql/db-world/`)

## Usage

```
.additem 40899  # Druid
.additem 45743  # Paladin
```

For druids: `.learn 16864` (Omen of Clarity talent required)

## Notes

- Client shows original glyph names (Growl/Divine Storm) - functionality is correct
- No client modifications required
- Server-side only implementation
