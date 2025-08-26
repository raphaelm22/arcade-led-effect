#include <SoftPWM.h>

#include "EffectProviders.h"

void runBlinkSequenceEffect(uint8_t leds[], uint8_t size, keepPlaying_t keepPlaying)
{
  for (uint8_t i = 0; i < size && keepPlaying(); i++)
  {
    SoftPWMSetPercent(leds[i], 100);
    delay(200);
    SoftPWMSetPercent(leds[i], 0);
  }
}