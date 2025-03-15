#include <Arduino.h>

/*

Shit that I need:

Setup line sensors
Setup front-facing distance sensors

Setup motors

*/

void setup() {

  Serial.begin(9600);

  // // Set up LED
  // pinMode(LED_BUILTIN, OUTPUT);

  // Front facing distance sensor
  pinMode(D1, INPUT);

  // Right distance sensor
  pinMode(D2, INPUT);
  
  // Left distance sensor
  pinMode(D3, INPUT);

  // Line sensors
  // Front right
  pinMode(A3, OUTPUT);
  
  // Front left
  pinMode(A4, OUTPUT);

  // Back
  pinMode(A5, OUTPUT);

  // Remote
  pinMode(D12, INPUT);

  // Being dumb
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
}

void loop() {
  // Get sensor data
  // bool frontFacingDistance = digitalRead(A0);
  // bool backLineSensor = digitalRead(A1);

  // Serial.printf("Front: %d Back: %d\n", frontFacingDistance, backLineSensor);


  int ir = digitalRead(D12);

  static bool hasRun = false;

  // Serial.println(ir);

  // Put sensor stuff into LEDs
  if(ir == 0 && !hasRun)
  {
    digitalWrite(A2, HIGH);
    digitalWrite(A1, LOW);
    digitalWrite(A0, LOW);
  } else if(ir == 1)
  {
    digitalWrite(A2, LOW);
    digitalWrite(A1, HIGH);
    digitalWrite(A0, LOW);
    hasRun = true;
  }
  if(ir == 0 && hasRun)
  {
    digitalWrite(A2, LOW);
    digitalWrite(A1, LOW);
    digitalWrite(A0, HIGH);
  }

  // // Blink dumbass
  // digitalWrite(LED_BUILTIN, HIGH);
  // delay(1000);
  // digitalWrite(LED_BUILTIN, LOW);
  // delay(1000);
}