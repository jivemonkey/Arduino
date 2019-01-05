/**
 * Blink
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include "Arduino.h"

int rightForwardPin = 2;
int rightBackwardPin = 3;
int rightSpeedPin = 2;

int leftForwardPin = 4;
int leftBackwardPin = 5;
int leftSpeedPin = 3;

void setup() {
  pinMode(rightForwardPin, OUTPUT);
  pinMode(rightBackwardPin, OUTPUT);
  pinMode(rightSpeedPin, OUTPUT);
}

void loop() {
  digitalWrite(rightForwardPin, HIGH);
  digitalWrite(rightBackwardPin, LOW);
  analogWrite(rightSpeedPin, 100);
  delay(3000);
  digitalWrite(rightForwardPin, LOW);
  digitalWrite(rightBackwardPin, HIGH);
  delay(3000);
}
