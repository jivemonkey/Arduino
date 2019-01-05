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

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(12, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(7, OUTPUT);
  
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(11,OUTPUT);
}

int digits[] = {13,10,9,7};
byte numbers[] = {B10001000,//0
                  B11101011,//1
                  B10100100,//2
                  B10100001,//3
                  B11000011,//4
                  B10010001,//5
                  B10010000,//6
                  B10101011,//7
                  B10000000,//8
                  B10000011 //9
                 };
                   
int currentDigit = 0;
int fields[] = {5,6,7,9};
int currentNumber=0;

// the loop function runs over and over again forever
void loop() {
    for(int j=0;j<4;j++) {
      digitalWrite(digits[j], currentDigit == j);
    }
    currentNumber = fields[currentDigit];
    digitalWrite(1+1, level(currentNumber, 0));
    digitalWrite(2+1, level(currentNumber, 1));
    digitalWrite(3+1, currentDigit != 1);
    digitalWrite(4+1, level(currentNumber, 2));
    digitalWrite(5+1, level(currentNumber, 3));
    digitalWrite(7+1, level(currentNumber, 4));
    digitalWrite(10+1, level(currentNumber, 5));
    digitalWrite(11+1, level(currentNumber, 6));
  
  currentDigit = (currentDigit + 1) % 4;
  delay(5);
}

bool level(int current, int i) {
  return bitRead(numbers[currentNumber],i);
}

