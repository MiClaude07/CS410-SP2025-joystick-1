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

## Webpage - Manager

### Libraries

**three.js**: Framework used for WebGL graphics

### Class

**Manager**: Manager object to manage Webpage THREE.js scene. Returns init() and animate() functions.

### Functions

**init()**: Initilizes manager. Sets up THREE.js scene, camera, renderer, and controls.

**createStickPadMeshes()**: Creates stick pad meshes and adds them to the scene.

**createButtonMeshes()**: Creates button meshes and add them to the scene.

**laodController()**: Loads controller STL model and adds to the scene.

**animateSticks()**: Moves sticks based on user input.

**animate()**: Animates controller.

## Webpage - Controller

### Class

**Controller**: Manager object to manage webpage controller inputs. Returns init(), getLeftX(), getLeftY(), getRightX(), getRightY(), isButton1Pressed(), isButton2Pressed(), isButton3Pressed(), and isButton4Pressed() functions.

### Functions

**init()**: Initilizes controller manager. Adds event listeners.

**loop()**: While gamepad is connected: update webpage controller readings.

**getLeftX()**: Gets left joystick X reading.

**getLeftY()**: Gets left joystick XY reading.

**getRightX()**: Gets right joystick X reading.

**getRightY()**: Gets right joystick y reading.

**isButton1Pressed()**: Returns if button 1 is pressed.

**isButton2Pressed()**: Returns if button 2 is pressed.

**isButton3Pressed()**: Returns if button 3 is pressed.

**isButton4Pressed()**: Returns if button 1 is pressed.
