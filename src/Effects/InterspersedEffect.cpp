#include "Effects.h"

void interspersedEffect(keepPlaying_t keepPlaying)
{
    uint8_t step1[] = {LED1, LED3, LED5, LED7};
    uint8_t step2[] = {LED2, LED4, LED6, LED8};

    MainEffectStep *mainStep = newMainEffectStep();
    concatNextEffectStep(mainStep, step1, 4, 100);
    concatNextEffectStep(mainStep, step2, 4, 100);
    concatNextEffectStep(mainStep, step1, 4, 0);
    concatNextEffectStep(mainStep, step2, 4, 0);

    runStepByStepEffect(mainStep, 200, keepPlaying);

    freeMemoryMainEffectStep(mainStep);
}
