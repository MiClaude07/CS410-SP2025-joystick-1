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
void loop()
{
  if (bleGamepad.isConnected())
  {
    int16_t x1, y1, z1, x2, y2, z2, b1, b2;
    x1 = map(analogRead(JOY_STICK_1_X), ANALOG_MIN, ANALOG_MAX, AXES_MIN, AXES_MAX);
    y1 = map(analogRead(JOY_STICK_1_Y), ANALOG_MIN, ANALOG_MAX, AXES_MAX, AXES_MIN); // For some strange reason, Y axes here is inverted
    z1 = digitalRead(JOY_STICK_1_Z);

    x2 = map(analogRead(JOY_STICK_2_X), ANALOG_MIN, ANALOG_MAX, AXES_MIN, AXES_MAX);
    y2 = map(analogRead(JOY_STICK_2_Y), ANALOG_MIN, ANALOG_MAX, AXES_MAX, AXES_MIN);
    z2 = digitalRead(JOY_STICK_2_Z);

    b1 = digitalRead(LEFT_BUTTON);
    b2 = digitalRead(RIGHT_BUTTON);

    bleGamepad.setLeftThumb(x1, y1);
    bleGamepad.setRightThumb(x2, y2);

    if (z1)
    {
      bleGamepad.press(BUTTON_10);
    }
    else
    {
      bleGamepad.release(BUTTON_10);
    }
    if (z2)
    {
      bleGamepad.press(BUTTON_11);
    }
    else
    {
      bleGamepad.release(BUTTON_11);
    }
    if (b1)
    {
      bleGamepad.press(BUTTON_1);
    }
    else
    {
      bleGamepad.release(BUTTON_1);
    }
    if (!b2)
    {
      bleGamepad.press(BUTTON_2);
    }
    else
    {
      bleGamepad.release(BUTTON_2);
    }
  }
  delay(10); // Short delay for Gamepad to register more consistent inputs
}
