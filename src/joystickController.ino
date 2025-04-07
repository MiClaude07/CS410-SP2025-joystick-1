#include <driver/adc.h>
#include <Arduino.h>

int JoyStick_X = T0; //x
int JoyStick_Y = T3; //y
int JoyStick_Z = T2; //key
  void setup() 
{
  pinMode(JoyStick_Z, INPUT_PULLUP); 
  pinMode(JoyStick_X, INPUT); 
  pinMode(JoyStick_Y, INPUT); 
  Serial.begin(9600); // 9600 bps
}
void loop() 
{
  int x,y,z;
  x=analogRead(JoyStick_X);
  y=analogRead(JoyStick_Y);
  z=digitalRead(JoyStick_Z);
  // Serial.print(x);
  // Serial.print(",");
  // Serial.print(y);
  // Serial.print(",");
  // Serial.println(z);
  if (y > 2000) {
    Serial.print("Up ");
  } else if (y < 1800){
    Serial.print("Down ");
  }
  if (x > 2000) {
    Serial.print("Forward ");
  } else if(x < 1800) {
    Serial.print("Back ");
  }
  if (z == 1) {
    Serial.println("Pressed");
  } else {
    Serial.println("Not Pressed");
  }
  delay(100);
}
