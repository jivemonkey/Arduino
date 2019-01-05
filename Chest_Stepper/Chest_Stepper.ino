/*
 * Microstepping demo
 *
 * This requires that M0, M1 be connected in addition to STEP,DIR
 *
 * Copyright (C)2015 Laurentiu Badea
 *
 * This file may be redistributed under the terms of the MIT license.
 * A copy of this license has been included with this distribution in the file LICENSE.
 */
#include <Arduino.h>
#include <Stepper.h>

#define D0 16
#define D1 5 // I2C Bus SCL (clock)
#define D2 4 // I2C Bus SDA (data)
#define D3 0
#define D4 2 // Same as "LED_BUILTIN", but inverted logic
#define D5 14 // SPI Bus SCK (clock)
#define D6 12 // SPI Bus MISO 
#define D7 13 // SPI Bus MOSI
#define D8 15 // SPI Bus SS (CS)
#define D9 3 // RX0 (Serial console)
#define D10 1 // TX0 (Serial console)

// Motor steps per revolution. Most steppers are 200 steps or 1.8 degrees/step
#define MOTOR_STEPS 200

// All the wires needed for full functionality
#define DIR 3
#define STEP 4
#define ENB 5
#define M0 6
#define M1 7
#define M2 8

void setup() {
    /*
     * Set target motor RPM.
     * These motors can do up to about 200rpm.
     * Too high will result in a high pitched whine and the motor does not move.
     */
    stepper.setRPM(1);  
    stepper.setMicrostep(32); // make sure we are in full speed mode
}

void loop() {
    /*
     * Moving motor at full speed is simple:
     */
    //stepper.rotate(-180);
    stepper.rotate(360);
}
