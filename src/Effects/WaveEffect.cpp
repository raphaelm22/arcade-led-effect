#include "Effects.h"

void waveEffect(keepPlaying_t keepPlaying)
{
    uint8_t led1[] = {LED1};
    uint8_t led2[] = {LED2};
    uint8_t led3[] = {LED3};
    uint8_t led4[] = {LED4};
    uint8_t led5[] = {LED5};
    uint8_t led6[] = {LED6};
    uint8_t led7[] = {LED7};
    uint8_t led8[] = {LED8};

    MainEffectStep *mainStep = newMainEffectStep();
    concatNextEffectStep(mainStep, led1, 1, 100);
    concatNextEffectStep(mainStep, led2, 1, 100);
    concatNextEffectStep(mainStep, led3, 1, 100);
    concatNextEffectStep(mainStep, led4, 1, 100);
    concatNextEffectStep(mainStep, led1, 1, 0);
    concatNextEffectStep(mainStep, led2, 1, 0);
    concatNextEffectStep(mainStep, led3, 1, 0);
    concatNextEffectStep(mainStep, led4, 1, 0);

    concatNextEffectStep(mainStep, led5, 1, 100);
    concatNextEffectStep(mainStep, led6, 1, 100);
    concatNextEffectStep(mainStep, led7, 1, 100);
    concatNextEffectStep(mainStep, led8, 1, 100);
    concatNextEffectStep(mainStep, led5, 1, 0);
    concatNextEffectStep(mainStep, led6, 1, 0);
    concatNextEffectStep(mainStep, led7, 1, 0);
    concatNextEffectStep(mainStep, led8, 1, 0);

    runStepByStepEffect(mainStep, 200, keepPlaying);

    freeMemoryMainEffectStep(mainStep);
}
