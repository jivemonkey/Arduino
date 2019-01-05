  /*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO 
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino model, check
  the Technical Specs of your board  at https://www.arduino.cc/en/Main/Products
  
  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
  
  modified 2 Sep 2016
  by Arturo Guadalupi
  
  modified 8 Sep 2016
  by Colby Newman
*/
int val = 0;
int state = LOW;
int sensor = 2;
int LED = LED_BUILTIN;
int BUZZER = 3;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  val = digitalRead(sensor);   // read sensor value
  if (val == HIGH) {           // check if the sensor is HIGH
    digitalWrite(LED, HIGH);   // turn LED ON
    delay(100);                // delay 100 milliseconds 
    
    if (state == LOW) {
      Serial.println("Motion detected!"); 
      state = HIGH;       // update variable state to HIGH
    }
  } 
  else {
      digitalWrite(LED, LOW); // turn LED OFF
      delay(200);             // delay 200 milliseconds 
      
      if (state == HIGH){
        Serial.println("Motion stopped!");
        state = LOW;       // update variable state to LOW
    }
  }
//  isOn = digitalRead(6);
//
//  if(isOn) {
//    digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
//    tone(3, 500);
//    delay(1000);                      // wait for a second
//    digitalWrite(2, LOW);    // turn the LED off by making the voltage LOW
//    noTone(3);
//    delay(1000);
//  }
//  isOn = LOW;
}
