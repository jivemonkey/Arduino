#include <Arduino.h>

int motion_sensor_pin = 7;
int led_pin = 6;
int pir_val;

void setup() {
  // put your setup code here, to run once:
  pinMode(motion_sensor_pin, INPUT);
  pinMode(led_pin, OUTPUT);
  digitalWrite(led_pin, LOW);
  Serial.begin(57600);
  
  Serial.println("Goodnight moon!");
}

void loop() {
  // put your main code here, to run repeatedly:
  pir_val = digitalRead(motion_sensor_pin);
  digitalWrite(led_pin, pir_val);  
  Serial.println(pir_val);
  delay(1000);
}
