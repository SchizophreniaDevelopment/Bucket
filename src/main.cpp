#include <Arduino.h>


void setup() {
  // Set up LED
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Blink dumbass
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}