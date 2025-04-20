#include <driver/adc.h>
#include <Arduino.h>
#include <BleGamepad.h>
#include <BleGamepadConfiguration.h>

#define JoyStick1_X  A3 // x
#define JoyStick1_Y  A0 // y
#define JoyStick1_Z  A6 // key
#define JoyStick2_X  A4 // x
#define JoyStick2_Y  A5 // y
#define JoyStick2_Z  A7 // key

#define AXES_JOYSTICK_SCALAR 0x7FFF / 0xFFF

BleGamepad bleGamepad;
void setup()
{
  pinMode(JoyStick1_Z, INPUT_PULLUP);
  pinMode(JoyStick1_X, INPUT);
  pinMode(JoyStick1_Y, INPUT);
  pinMode(JoyStick2_Z, INPUT_PULLUP);
  pinMode(JoyStick2_X, INPUT);
  pinMode(JoyStick2_Y, INPUT);
  Serial.begin(9600); // 9600 bps
  Serial.println("Starting BLE");
  BleGamepadConfiguration config;
  config.setAutoReport(true);
  bleGamepad.begin(&config);
}
void loop()
{
  int16_t x1, y1, z1, x2, y2, z2;
  x1 = analogRead(JoyStick1_X) * AXES_JOYSTICK_SCALAR;
  y1 = analogRead(JoyStick1_Y) * AXES_JOYSTICK_SCALAR;
  z1 = digitalRead(JoyStick1_Z);

  x2 = analogRead(JoyStick2_X) * AXES_JOYSTICK_SCALAR;
  y2 = analogRead(JoyStick2_Y) * AXES_JOYSTICK_SCALAR;
  z2 = digitalRead(JoyStick2_Z);
  
  bleGamepad.setLeftThumb(x1, y1); // Temp fix: Y axes is inverted for some reason. Uses Two's compliment to correct
  bleGamepad.setRightThumb(x2, y2);
  
}
