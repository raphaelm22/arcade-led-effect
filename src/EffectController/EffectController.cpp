#include <stdio.h>
#include "EffectController.h"

bool _running = false;
uint32_t _timeout = 0;
effect_t *_effects;
size_t _effectsSize = 0;
effect_t *_shuffledEffect = NULL;

void shuffleEffects()
{
    memcpy(_shuffledEffect, _effects, (_effectsSize + 1) * sizeof(effect_t));

    for (size_t i = 0; i < _effectsSize - 2; i++)
    {
        size_t r = random(i, _effectsSize - 1);
        effect_t swap = _shuffledEffect[r];
        _shuffledEffect[r] = _shuffledEffect[i];
        _shuffledEffect[i] = swap;
    }

    _shuffledEffect[_effectsSize] = NULL;
}

void registerEffects(effect_t *effects, size_t effectsSize)
{
    _effects = (effect_t *)malloc(effectsSize * sizeof(effect_t));

    memcpy(_effects, effects, effectsSize * sizeof(effect_t));
    _effectsSize = effectsSize;

    _shuffledEffect = (effect_t *)malloc((effectsSize + 1) * sizeof(effect_t));
    shuffleEffects();
}

void setEffectTimeout(uint32_t timeout)
{
    _timeout = timeout;
}

bool verifyTimeout(bool reset)
{
    if (_timeout == 0)
        return false;

    static uint32_t startedAt;
    if (reset)
        startedAt = millis();

    return (millis() - startedAt) >= _timeout;
}

void playEffect(keepPlaying_t keep_playing)
{
    bool resetTimeout = true;

    effect_t effect = *_shuffledEffect;

    while (keep_playing() && !verifyTimeout(resetTimeout))
    {
        effect(keep_playing);
        resetTimeout = false;
    }

    _shuffledEffect++;

    if (!(*_shuffledEffect))
    {
        _shuffledEffect = &_shuffledEffect[-1 * _effectsSize];
        shuffleEffects();
    }
}
