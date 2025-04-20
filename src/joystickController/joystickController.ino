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

#define ANALOG_MIN 0
#define ANALOG_MAX 0xFFF
#define AXES_MIN 0
#define AXES_MAX 0x7FFF

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
  x1 = map(analogRead(JoyStick1_X), ANALOG_MIN, ANALOG_MAX, AXES_MIN, AXES_MAX);
  y1 = map(analogRead(JoyStick1_Y), ANALOG_MIN, ANALOG_MAX, AXES_MAX, AXES_MIN); // For some strange reason, Y axes here is inverted
  z1 = digitalRead(JoyStick1_Z);

  x2 = map(analogRead(JoyStick2_X), ANALOG_MIN, ANALOG_MAX, AXES_MIN, AXES_MAX);
  y2 = map(analogRead(JoyStick2_Y), ANALOG_MIN, ANALOG_MAX, AXES_MIN, AXES_MAX);
  z2 = digitalRead(JoyStick2_Z);

  bleGamepad.setLeftThumb(x1, y1); 
  bleGamepad.setRightThumb(x2, y2);
  
}
