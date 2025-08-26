#include <Arduino.h>
#include <SoftPWM.h> //library: https://github.com/bhagman/SoftPWM
#if DEBUG
#include <avr8-stub.h>
#endif
#include "EffectController.h"
#include "Effects.h"

#define COUNT_OF(x) ((sizeof(x) / sizeof(0 [x])) / ((size_t)(!(sizeof(x) % sizeof(0 [x])))))

uint8_t BUTTON[] = {BT1, BT2, BT3, BT4, BT5, BT6, BT7, BT8};
uint8_t LED[] = {LED1, LED2, LED3, LED4, LED5, LED6, LED7, LED8};

#ifdef RELEASE
uint32_t EFFECT_TIMEOUT = 30L * 1000L;        //30seg
uint32_t EFFECT_FREE_TIME = 5L * 60L * 1000L; //5min
#else
uint32_t EFFECT_TIMEOUT = 10 * 1000; //10seg
uint32_t EFFECT_FREE_TIME = 5 * 1000; //5seg
#endif

void setup()
{
#if DEBUG
    debug_init();
#endif

    SoftPWMBegin();

    const uint16_t fadeIn = 0;
    const uint16_t fadeOut = 500;

    for (uint8_t i = 0; i < COUNT_OF(LED); i++)
    {
        pinMode(BUTTON[i], INPUT);
        
        SoftPWMSet(LED[i], 0);
        SoftPWMSetFadeTime(LED[i], fadeIn, fadeOut);
    }

    static effect_t effects[] = {
        &rotateEffect, &zigZagEffect, &snakePathEffect,
        &centerToEdgesEffect, &centerToEdgesEffectReverse,
        &increaseEffect, &interspersedEffect,
        &waveEffect, &againstHandEffect};

    registerEffects(effects, COUNT_OF(effects));
    setEffectTimeout(EFFECT_TIMEOUT);
}

bool performEffectButtonPressed()
{
    bool anyBtnIsPressed = false;
    for (uint8_t i = 0; i < COUNT_OF(BUTTON); i++)
    {
        bool isPressed = digitalRead(BUTTON[i]) == HIGH;

        SoftPWMSetPercent(LED[i], isPressed ? 100 : 0);

        anyBtnIsPressed = anyBtnIsPressed || isPressed;
    }
    return anyBtnIsPressed;
}

bool allButtonsAreReleased()
{
    for (uint8_t i = 0; i < COUNT_OF(BUTTON); i++)
    {
        if (digitalRead(BUTTON[i]) == HIGH)
            return false;
    }

    return true;
}

void loop()
{
    static uint32_t startedAt = millis();

    if (performEffectButtonPressed())
        startedAt = millis();


    if ((millis() - startedAt) > EFFECT_FREE_TIME)
    {
        playEffect(&allButtonsAreReleased);
        startedAt = millis();
    }
}