-- Classic Glyphs Module
-- Implements WotLK Classic 3.4.3 glyphs by repurposing existing 3.3.5a glyphs

-- Bind spell scripts to the abilities
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dru_faerie_fire_feral_glyph', 'spell_pal_hand_of_reckoning_glyph');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(16857, 'spell_dru_faerie_fire_feral_glyph'),  -- Faerie Fire (Feral)
(62124, 'spell_pal_hand_of_reckoning_glyph'); -- Hand of Reckoning

-- Update item names for server-side display (client will still show original names)
UPDATE `item_template` SET
    `name` = 'Glyph of Omen of Clarity',
    `description` = 'Your Omen of Clarity talent has a 100% chance to be triggered by successfully casting Faerie Fire (Feral). Does not trigger on players or player-controlled pets.'
WHERE `entry` = 40899;

UPDATE `item_template` SET
    `name` = 'Glyph of Reckoning',
    `description` = 'Your Hand of Reckoning spell no longer taunts the target and can deal damage to untauntable targets.'
WHERE `entry` = 45743;
