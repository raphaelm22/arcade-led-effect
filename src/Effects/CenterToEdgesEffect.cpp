#include "Effects.h"

void centerToEdgesEffect(bool reverse, keepPlaying_t keepPlaying)
{
    uint8_t center[] = {LED2, LED3, LED6, LED7};
    uint8_t edges[] = {LED1, LED4, LED5, LED8};

    uint8_t *step1 = !reverse ? center : edges;
    uint8_t *step2 = !reverse ? edges : center;

    MainEffectStep *mainStep = newMainEffectStep();
    concatNextEffectStep(mainStep, step1, 4, 100);
    concatNextEffectStep(mainStep, step2, 4, 100);
    concatNextEffectStep(mainStep, step1, 4, 0);
    concatNextEffectStep(mainStep, step2, 4, 0);

    runStepByStepEffect(mainStep, 200, keepPlaying);

    freeMemoryMainEffectStep(mainStep);
}

void centerToEdgesEffect(keepPlaying_t keepPlaying)
{
    centerToEdgesEffect(false, keepPlaying);
}

void centerToEdgesEffectReverse(keepPlaying_t keepPlaying)
{
    centerToEdgesEffect(true, keepPlaying);
}