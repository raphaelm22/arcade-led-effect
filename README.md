# Arcade LED Effect Controller

An Arduino-based LED effects controller designed for arcade-style applications. This project provides various visual LED patterns and effects controlled by buttons, perfect for arcade cabinets, game controllers, or interactive displays.

## Features

- **8 LED Control**: Manages 8 individual LEDs with PWM fade effects
- **8 Button Inputs**: Responsive button interface for triggering effects
- **Multiple Visual Effects**: 9 different LED animation patterns

### Demo Videos

Check out the project in action: https://www.youtube.com/watch?v=rCO8ps2iSug

![Arcade led](./docs/arcade-led-control.gif)

## Hardware Requirements

- **Microcontroller**: Arduino Pro Mini (16MHz, ATmega328P) or compatible
- **LEDs**: 8 LEDs (connected to pins A3, A2, A1, A0, 13, 12, 11, 10)
- **Buttons**: 8 momentary push buttons (connected to pins 2-9)
- **Power Supply**: 5V DC power supply
- **Resistors**: Current-limiting resistors for LEDs (typically 220-330Ω)
- **Pull-up Resistors**: For button inputs (if not using internal pull-ups)

## Pin Configuration

### LED Connections
- LED1: Pin A3
- LED2: Pin A2  
- LED3: Pin A1
- LED4: Pin A0
- LED5: Pin 13
- LED6: Pin 12
- LED7: Pin 11
- LED8: Pin 10

### Button Connections
- Button1: Pin 2
- Button2: Pin 3
- Button3: Pin 4
- Button4: Pin 5
- Button5: Pin 6
- Button6: Pin 7
- Button7: Pin 8
- Button8: Pin 9

## Available Effects

1. **Rotate Effect**: LEDs light up in sequence creating a rotating pattern
2. **ZigZag Effect**: Creates a zigzag lighting pattern
3. **Snake Path Effect**: Simulates a snake-like movement pattern
4. **Center to Edges Effect**: Lights spread from center to edges
5. **Center to Edges Reverse**: Lights move from edges to center
6. **Increase Effect**: Gradual increase in LED activation
7. **Interspersed Effect**: Alternating LED patterns
8. **Wave Effect**: Creates wave-like motion across LEDs
9. **Against Hand Effect**: Custom directional lighting pattern

## Software Requirements

- **PlatformIO**: Development platform
- **Arduino Framework**: Core Arduino libraries
- **SoftPWM Library**: For smooth PWM control (bhagman/SoftPWM@^1.0.1)

## Configuration

### Timing Configuration
You can modify timeout values in `src/main.cpp`:

```cpp
// Release mode
uint32_t EFFECT_TIMEOUT = 30L * 1000L;        // 30 seconds
uint32_t EFFECT_FREE_TIME = 5L * 60L * 1000L; // 5 minutes

// Development mode  
uint32_t EFFECT_TIMEOUT = 10 * 1000;  // 10 seconds
uint32_t EFFECT_FREE_TIME = 5 * 1000; // 5 seconds
```

### Adding New Effects
1. Create a new effect file in `src/Effects/`
2. Implement your effect function following the existing pattern
3. Add the effect to the effects array in `src/main.cpp`

