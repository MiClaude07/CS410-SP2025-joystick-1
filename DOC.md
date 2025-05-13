# Code Documentation

This document covers code maintence and conventions.

## Joystick Hardware / Arduino

(Diagram)

### Libraries

**driver/adc.h**: Library used by ESP32
**Arduino.h**: Standard Arduino Library
**BleGamepad.h**: External Library used to assist in inputting Gamepad commands to computer
**BleGamepadConfiguration.h**: External Library used to configure BleGamepad

### Functions

**void setup()**: Setup ESP32 microcontroller by mapping pin modes, starting serial, configuring BLE config, and initializing controller.

**void buttonRegister(int16_t analogInput, int8_t buttonMap)**: Registers button presses and releases with analog input from Arduino controller and mapped button for controller.

**void loop()**: Per loop if controller is connected: Translate joystick coords from analog readings to axes readings. Read button1, button2, button10, and button11. Send joystick and button data to controller.
