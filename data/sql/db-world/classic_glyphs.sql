-- Bind spell scripts to the abilities
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dru_faerie_fire_feral_glyph', 'spell_pal_hand_of_reckoning_glyph');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(16857, 'spell_dru_faerie_fire_feral_glyph'),  -- Faerie Fire (Feral)
(62124, 'spell_pal_hand_of_reckoning_glyph'); -- Hand of Reckoning
