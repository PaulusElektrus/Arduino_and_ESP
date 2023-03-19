#include <Arduino.h>

const int buttonPin =  4;
int buttonState = 0;

void setup() {

  pinMode(buttonPin, INPUT);
  pinMode(12, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    // Send a message to the Arduino
    Serial.write("change");
    // Flash the built in LED to confirm that button push was registered
    digitalWrite(12, HIGH);   // turn the LED on
    delay(500);
    digitalWrite(12, LOW);    // turn the LED off
    delay(250);
    
  }
  else {
    delay(25);
  }
}