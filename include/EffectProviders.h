#ifndef EFFECT_PROVIDER_H
#define EFFECT_PROVIDER_H

#include <Arduino.h>

typedef bool (*keepPlaying_t)();
typedef void (*effect_t)(keepPlaying_t);

void runBlinkSequenceEffect(uint8_t leds[], uint8_t size, keepPlaying_t keepPlaying);

typedef struct EffectStep
{
    uint8_t *leds;
    uint8_t ledsSize;
    uint8_t percent;
    struct EffectStep *next;
} EffectStep_t;

typedef struct MainEffectStep
{
    struct EffectStep *first;
    struct EffectStep *last;
} MainEffectStep_t;


MainEffectStep *newMainEffectStep();
void concatNextEffectStep(MainEffectStep *main, uint8_t leds[], uint8_t ledsSize, uint8_t percent);
void freeMemoryMainEffectStep(MainEffectStep *mainStep);
void runStepByStepEffect(MainEffectStep *mainStep, uint32_t intevalDelay, keepPlaying_t keepPlaying);


#endif