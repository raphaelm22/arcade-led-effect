#include "Effects.h"

void snakePathEffect(keepPlaying_t keep_playing)
{
  uint8_t order[] = {
    LED1, LED8, LED2, LED7, LED6, LED3, LED4, LED5,
    LED6, LED3, LED2, LED7
  };
  runBlinkSequenceEffect(order, 12, keep_playing);
}