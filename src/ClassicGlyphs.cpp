#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Player.h"
#include "Pet.h"

enum ClassicGlyphSpells
{
    SPELL_FAERIE_FIRE_FERAL         = 16857,
    SPELL_OMEN_OF_CLARITY           = 16864,
    SPELL_CLEARCASTING              = 16870,
    SPELL_GLYPH_OF_GROWL            = 54812,
    SPELL_HAND_OF_RECKONING         = 62124,
    SPELL_GLYPH_OF_DIVINE_STORM     = 63220
};

// Glyph of Growl (repurposed): Faerie Fire (Feral) triggers Clearcasting
class spell_dru_faerie_fire_feral_glyph : public SpellScript
{
    PrepareSpellScript(spell_dru_faerie_fire_feral_glyph);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({
            SPELL_GLYPH_OF_GROWL,
            SPELL_OMEN_OF_CLARITY,
            SPELL_CLEARCASTING
        });
    }

    void HandleAfterHit()
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();

        if (!caster || !target || !caster->HasAura(SPELL_GLYPH_OF_GROWL) || !caster->HasAura(SPELL_OMEN_OF_CLARITY))
            return;

        if (target->GetTypeId() == TYPEID_PLAYER)
            return;

        if (target->GetTypeId() == TYPEID_UNIT)
            if (Creature* creature = target->ToCreature())
                if (creature->IsPet() && creature->GetOwner() && creature->GetOwner()->GetTypeId() == TYPEID_PLAYER)
                    return;

        caster->CastSpell(caster, SPELL_CLEARCASTING, true);
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_dru_faerie_fire_feral_glyph::HandleAfterHit);
    }
};

// Glyph of Divine Storm (repurposed): Hand of Reckoning doesn't taunt, always damages
class spell_pal_hand_of_reckoning_glyph : public SpellScript
{
    PrepareSpellScript(spell_pal_hand_of_reckoning_glyph);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_GLYPH_OF_DIVINE_STORM, 67485 });
    }

    void HandleHit()
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();

        if (!caster || !target || !caster->HasAura(SPELL_GLYPH_OF_DIVINE_STORM))
            return;

        PreventHitDefaultEffect(EFFECT_0);
        PreventHitDefaultEffect(EFFECT_1);
        caster->CastSpell(target, 67485, true);
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_pal_hand_of_reckoning_glyph::HandleHit);
    }
};

void Addmod_classic_glyphsScripts()
{
    RegisterSpellScript(spell_dru_faerie_fire_feral_glyph);
    RegisterSpellScript(spell_pal_hand_of_reckoning_glyph);
}
