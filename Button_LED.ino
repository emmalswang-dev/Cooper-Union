#include "arduino_secrets.h"

/*
 */
int buttonState = 0;

void setup() {
  pinMode (6; OUTPUT);
  pinMode (11; INPUT);
}

void loop() {
  buttonState = digitalRead(11);
  if (buttonState == HIGH) {
    digitalWrite (6, LOW);
  } else {
    digitalWrite(6, HIGH);
  }
}
