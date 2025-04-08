#include <Keyboard.h>

// set pin numbers
const int buttonPin = 4; // the number of the pushbutton pin
const int ledPin = 5;    // the number of the LED pin

// variable for storing the pushbutton status
int buttonState = 0;
int lastButtonState = 0;

void setup() {
  Serial.begin(115200);
  // initialize the pushbutton pin as an input
  pinMode(buttonPin, INPUT_PULLUP); // use internal pull-up resistor
  // initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);

  // start keyboard emulation
  Keyboard.begin();
}

void loop() {
  // read the state of the pushbutton value
  buttonState = digitalRead(buttonPin);

  // detect button press (transition from HIGH to LOW since using INPUT_PULLUP)
  if (lastButtonState == HIGH && buttonState == LOW) {
    // turn LED on
    digitalWrite(ledPin, HIGH);

    // send spacebar key press
    Keyboard.press(' ');
    delay(100); // short delay to register the press
    Keyboard.release(' ');
  }
  else if (buttonState == HIGH) {
    // turn LED off
    digitalWrite(ledPin, LOW);
  }

  lastButtonState = buttonState;
}
