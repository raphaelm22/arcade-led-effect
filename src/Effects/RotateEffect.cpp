#include "Effects.h"

void rotateEffect(keepPlaying_t keep_playing)
{
    uint8_t order[] = {LED1, LED2, LED3, LED4, LED5, LED6, LED7, LED8};
    runBlinkSequenceEffect(order, 8, keep_playing);
}