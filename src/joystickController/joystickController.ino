#include <driver/adc.h>
#include <Arduino.h>
#include <BleGamepad.h>
#include <BleGamepadConfiguration.h>

#define JOY_STICK_1_X 39 // x
#define JOY_STICK_1_Y 36 // y
#define JOY_STICK_1_Z 34 // key
#define JOY_STICK_2_X 32 // x
#define JOY_STICK_2_Y 35 // y
#define JOY_STICK_2_Z 33 // key

#define RIGHT_BUTTON 25
#define LEFT_BUTTON 27

#define ANALOG_MIN 0     // Min Analog Reading
#define ANALOG_MAX 0xFFF // Max Analog Reading
#define AXES_MIN 0       // Min Axes Reading
#define AXES_MAX 0x7FFF  // Max Axes Reading

BleGamepad bleGamepad;
/**
 * @brief Setup ESP32 microcontroller by mapping pin modes, starting serial, configuring BLE config, and initializing controller.
 *
 */
void setup()
{
  pinMode(JOY_STICK_1_Z, INPUT_PULLUP);
  pinMode(JOY_STICK_1_X, INPUT);
  pinMode(JOY_STICK_1_Y, INPUT);
  pinMode(JOY_STICK_2_Z, INPUT_PULLUP);
  pinMode(JOY_STICK_2_X, INPUT);
  pinMode(JOY_STICK_2_Y, INPUT);
  pinMode(RIGHT_BUTTON, INPUT_PULLUP);
  Serial.begin(9600); // 9600 bps
  Serial.println("Starting BLE");
  BleGamepadConfiguration config;
  bleGamepad.begin(&config);
}
/**
 * @brief Register button presses and releases
 *
 * @param analogInput - Analog input from Arduino controller
 * @param buttonMap - Corresponding button map
 */
void buttonRegister(int16_t analogInput, int8_t buttonMap)
{
  if (analogInput)
  {
    bleGamepad.press(buttonMap);
  }
  else
  {
    bleGamepad.release(buttonMap);
  }
}

/**
 * @brief Per loop if controller is connected: Translate joystick coords from analog readings to axes readings. Read button1, button2, button10, and button11. Send joystick and button data to controller.
 *
 */
void loop()
{
  if (bleGamepad.isConnected())
  {
    int16_t x1, y1, z1, x2, y2, z2, b1, b2;
    x1 = map(analogRead(JOY_STICK_1_X), ANALOG_MIN, ANALOG_MAX, AXES_MIN, AXES_MAX);
    y1 = map(analogRead(JOY_STICK_1_Y), ANALOG_MIN, ANALOG_MAX, AXES_MAX, AXES_MIN);
    z1 = digitalRead(JOY_STICK_1_Z);

    x2 = map(analogRead(JOY_STICK_2_X), ANALOG_MIN, ANALOG_MAX, AXES_MIN, AXES_MAX);
    y2 = map(analogRead(JOY_STICK_2_Y), ANALOG_MIN, ANALOG_MAX, AXES_MAX, AXES_MIN);
    z2 = digitalRead(JOY_STICK_2_Z);

    b2 = digitalRead(LEFT_BUTTON);
    b1 = digitalRead(RIGHT_BUTTON);

    bleGamepad.setLeftThumb(x2, y2);
    bleGamepad.setRightThumb(x1, y1);

    buttonRegister(z2, BUTTON_10);
    buttonRegister(z1, BUTTON_11);
    buttonRegister(!b1, BUTTON_1);
    buttonRegister(b2, BUTTON_2);
  }
  delay(10); // Short delay for Gamepad to register more consistent inputs
}
