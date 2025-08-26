#include "Effects.h"

void againstHandEffect(keepPlaying_t keepPlaying)
{
    uint8_t step1[] = {LED1, LED5};
    uint8_t step2[] = {LED2, LED6};
    uint8_t step3[] = {LED3, LED7};
    uint8_t step4[] = {LED4, LED8};

    MainEffectStep *mainStep = newMainEffectStep();
    concatNextEffectStep(mainStep, step1, 2, 100);
    concatNextEffectStep(mainStep, step2, 2, 100);
    concatNextEffectStep(mainStep, step3, 2, 100);
    concatNextEffectStep(mainStep, step4, 2, 100);
    concatNextEffectStep(mainStep, step1, 2, 0);
    concatNextEffectStep(mainStep, step2, 2, 0);
    concatNextEffectStep(mainStep, step3, 2, 0);
    concatNextEffectStep(mainStep, step4, 2, 0);

    concatNextEffectStep(mainStep, step4, 2, 100);
    concatNextEffectStep(mainStep, step3, 2, 100);
    concatNextEffectStep(mainStep, step2, 2, 100);
    concatNextEffectStep(mainStep, step1, 2, 100);
    concatNextEffectStep(mainStep, step4, 2, 0);
    concatNextEffectStep(mainStep, step3, 2, 0);
    concatNextEffectStep(mainStep, step2, 2, 0);
    concatNextEffectStep(mainStep, step1, 2, 0);

    runStepByStepEffect(mainStep, 200, keepPlaying);

    freeMemoryMainEffectStep(mainStep);
}
