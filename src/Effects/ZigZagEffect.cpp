#include "Effects.h"

void zigZagEffect(keepPlaying_t keep_playing)
{
  uint8_t order[] = {LED1, LED7, LED3, LED5, LED4, LED6, LED2, LED8};
  runBlinkSequenceEffect(order, 8, keep_playing);
}