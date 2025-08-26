#include "Effects.h"

void increaseEffect(keepPlaying_t keepPlaying)
{
    uint8_t led1[] = {LED1};
    uint8_t led2[] = {LED2};
    uint8_t led3[] = {LED3};
    uint8_t led4[] = {LED4};
    uint8_t led5[] = {LED5};
    uint8_t led6[] = {LED6};
    uint8_t led7[] = {LED7};
    uint8_t led8[] = {LED8};

    uint8_t allLed[] = {LED1, LED2, LED3, LED4, LED5, LED6, LED7, LED8};

    MainEffectStep *mainStep = newMainEffectStep();

    concatNextEffectStep(mainStep, led1, 1, 100);
    concatNextEffectStep(mainStep, led2, 1, 100);
    concatNextEffectStep(mainStep, led1, 1, 0);
    concatNextEffectStep(mainStep, led3, 1, 100);
    concatNextEffectStep(mainStep, led2, 1, 0);
    concatNextEffectStep(mainStep, led4, 1, 100);
    concatNextEffectStep(mainStep, led3, 1, 0);
    concatNextEffectStep(mainStep, led5, 1, 100);
    concatNextEffectStep(mainStep, led4, 1, 0);
    concatNextEffectStep(mainStep, led6, 1, 100);
    concatNextEffectStep(mainStep, led5, 1, 0);
    concatNextEffectStep(mainStep, led7, 1, 100);
    concatNextEffectStep(mainStep, led6, 1, 0);
    concatNextEffectStep(mainStep, led8, 1, 100);
    concatNextEffectStep(mainStep, led7, 1, 0);

    concatNextEffectStep(mainStep, led1, 1, 100);

    concatNextEffectStep(mainStep, led2, 1, 100);
    concatNextEffectStep(mainStep, led1, 1, 0);
    concatNextEffectStep(mainStep, led3, 1, 100);
    concatNextEffectStep(mainStep, led2, 1, 0);
    concatNextEffectStep(mainStep, led4, 1, 100);
    concatNextEffectStep(mainStep, led3, 1, 0);
    concatNextEffectStep(mainStep, led5, 1, 100);
    concatNextEffectStep(mainStep, led4, 1, 0);
    concatNextEffectStep(mainStep, led6, 1, 100);
    concatNextEffectStep(mainStep, led5, 1, 0);
    concatNextEffectStep(mainStep, led7, 1, 100);
    concatNextEffectStep(mainStep, led6, 1, 0);

    concatNextEffectStep(mainStep, led1, 1, 100);
    concatNextEffectStep(mainStep, led2, 1, 100);
    concatNextEffectStep(mainStep, led1, 1, 0);
    concatNextEffectStep(mainStep, led3, 1, 100);
    concatNextEffectStep(mainStep, led2, 1, 0);
    concatNextEffectStep(mainStep, led4, 1, 100);
    concatNextEffectStep(mainStep, led3, 1, 0);
    concatNextEffectStep(mainStep, led5, 1, 100);
    concatNextEffectStep(mainStep, led4, 1, 0);
    concatNextEffectStep(mainStep, led6, 1, 100);
    concatNextEffectStep(mainStep, led5, 1, 0);

    concatNextEffectStep(mainStep, led1, 1, 100);
    concatNextEffectStep(mainStep, led2, 1, 100);
    concatNextEffectStep(mainStep, led1, 1, 0);
    concatNextEffectStep(mainStep, led3, 1, 100);
    concatNextEffectStep(mainStep, led2, 1, 0);
    concatNextEffectStep(mainStep, led4, 1, 100);
    concatNextEffectStep(mainStep, led3, 1, 0);
    concatNextEffectStep(mainStep, led5, 1, 100);
    concatNextEffectStep(mainStep, led4, 1, 0);

    concatNextEffectStep(mainStep, led1, 1, 100);
    concatNextEffectStep(mainStep, led2, 1, 100);
    concatNextEffectStep(mainStep, led1, 1, 0);
    concatNextEffectStep(mainStep, led3, 1, 100);
    concatNextEffectStep(mainStep, led2, 1, 0);
    concatNextEffectStep(mainStep, led4, 1, 100);
    concatNextEffectStep(mainStep, led3, 1, 0);
    concatNextEffectStep(mainStep, led1, 1, 100);
    concatNextEffectStep(mainStep, led1, 1, 0);
    concatNextEffectStep(mainStep, led2, 1, 100);
    concatNextEffectStep(mainStep, led2, 1, 0);
    concatNextEffectStep(mainStep, led3, 1, 100);

    concatNextEffectStep(mainStep, led1, 1, 100);
    concatNextEffectStep(mainStep, led2, 1, 100);
    concatNextEffectStep(mainStep, led1, 1, 0);

    concatNextEffectStep(mainStep, led1, 1, 100);
    concatNextEffectStep(mainStep, allLed, 8, 0);

    runStepByStepEffect(mainStep, 100, keepPlaying);

    freeMemoryMainEffectStep(mainStep);
}
