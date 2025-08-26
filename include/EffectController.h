#ifndef EFFECT_CONTROLLER_H
#define EFFECT_CONTROLLER_H

#include <Arduino.h>
#include "EffectProviders.h"

void registerEffects(effect_t *effects, size_t effectsSize);
void setEffectTimeout(uint32_t timeout);
void playEffect(keepPlaying_t keep_playing);

#endif