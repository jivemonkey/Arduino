int red = 30;
int green = 31;
int blue = 2;
int xAxis = A6;
int yAxis = A7;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  digitalWrite(red, HIGH);
  digitalWrite(green, HIGH);
  analogWrite(blue, 255);
}

void loop() {
  int val = getVal(analogRead(yAxis));
  
  if(val < 120) {
     analogWrite(blue, 0);
   } else {
     analogWrite(blue, 255);
   }
  
  int valX = analogRead(xAxis);
  if(valX == 0) {
    digitalWrite(red, LOW);
  } else if(valX > 1020) {
    digitalWrite(green, LOW);
  } else {
    reset();q
  }
  
  delay(100);
}

void reset() {
  digitalWrite(red, HIGH);
  digitalWrite(green, HIGH);
}

int getVal(int analogVal) {
  return 255 - (analogVal/5);
}

