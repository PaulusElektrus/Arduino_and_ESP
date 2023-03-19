#include <Arduino.h>

bool toggle;
String incomingString;

void setup() {
  
  pinMode(12, OUTPUT);
  toggle = false;

  Serial.begin(115200);
}

void loop() {

  if (Serial.available() > 0){
    // read the incoming string from the ESP
    incomingString = Serial.readString();
    
    // If the incoming string from the Arduino equals "change" then we toggle the LED
    if (incomingString.equals("change")){
      digitalWrite(12, toggle);  // Turn the LED off or on
      toggle = !toggle;                     
    }
  }
  delay(50);
}