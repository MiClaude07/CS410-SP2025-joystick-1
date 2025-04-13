#include <driver/adc.h>
#include <Arduino.h>

int JoyStick1_X = A3; // x
int JoyStick1_Y = A0; // y
int JoyStick1_Z = A6; // key
int JoyStick2_X = A4; // x
int JoyStick2_Y = A5; // y
int JoyStick2_Z = A7; // key
void setup()
{
  pinMode(JoyStick1_Z, INPUT_PULLUP);
  pinMode(JoyStick1_X, INPUT);
  pinMode(JoyStick1_Y, INPUT);
  pinMode(JoyStick2_Z, INPUT_PULLUP);
  pinMode(JoyStick2_X, INPUT);
  pinMode(JoyStick2_Y, INPUT);
  Serial.begin(9600); // 9600 bps
}
void loop()
{
  int x1, y1, z1, x2, y2, z2;
  x1 = analogRead(JoyStick1_X);
  y1 = analogRead(JoyStick1_Y);
  z1 = digitalRead(JoyStick1_Z);
  if (y1 > 2000)
  {
    Serial.print("Up ");
  }
  else if (y1 < 1800)
  {
    Serial.print("Down ");
  }
  if (x1 > 2000)
  {
    Serial.print("Forward ");
  }
  else if (x1 < 1800)
  {
    Serial.print("Back ");
  }
  if (z1 == 1)
  {
    Serial.println("Pressed 1\n");
  }
  else
  {
    Serial.println("Not Pressed 1\n");
  }

  x2 = analogRead(JoyStick2_X);
  y2 = analogRead(JoyStick2_Y);
  z2 = digitalRead(JoyStick2_Z);
  if (y2 > 2000)
  {
    Serial.print("Up ");
  }
  else if (y2 < 1800)
  {
    Serial.print("Down ");
  }
  if (x2 > 2000)
  {
    Serial.print("Forward ");
  }
  else if (x2 < 1800)
  {
    Serial.print("Back ");
  }
  if (z2 == 1)
  {
    Serial.println("Pressed 2\n_________________\n");
  }
  else
  {
    Serial.println("Not Pressed 2\n_________________\n");
  }
  delay(1000);
}
