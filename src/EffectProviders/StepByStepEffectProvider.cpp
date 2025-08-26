#include <SoftPWM.h>

#include "EffectProviders.h"

EffectStep_t *newEffectStep(uint8_t leds[], uint8_t ledsSize, uint8_t percent, EffectStep_t *parent = NULL)
{
    EffectStep_t *step = (EffectStep_t *)malloc(sizeof(EffectStep_t));

    step->leds = leds;
    step->ledsSize = ledsSize;
    step->percent = percent;
    step->next = NULL;

    if (parent)
        parent->next = step;

    return step;
}

MainEffectStep *newMainEffectStep()
{
    MainEffectStep_t *mainStep = (MainEffectStep_t *)malloc(sizeof(MainEffectStep_t));

    mainStep->first = NULL;
    mainStep->last = NULL;

    return mainStep;
}

void concatNextEffectStep(MainEffectStep *main, uint8_t leds[], uint8_t ledsSize, uint8_t percent)
{
    main->last = newEffectStep(leds, ledsSize, percent, main->last);
    if (!main->first)
        main->first = main->last;
}

void freeMemoryEffectStep(EffectStep *effectStep)
{
    if (effectStep->next)
        freeMemoryEffectStep(effectStep->next);

    free(effectStep);
}

void freeMemoryMainEffectStep(MainEffectStep *mainStep)
{
    if (mainStep->first)
        freeMemoryEffectStep(mainStep->first);

    free(mainStep);
}

void runStepByStepEffect(MainEffectStep *mainStep, uint32_t intevalDelay, keepPlaying_t keepPlaying)
{
    for (EffectStep_t *currentStep = mainStep->first; currentStep && keepPlaying(); currentStep = currentStep->next)
    {
        for (uint8_t i = 0; i < currentStep->ledsSize && keepPlaying(); i++)
            SoftPWMSetPercent(currentStep->leds[i], currentStep->percent);

        delay(intevalDelay);
    }
}