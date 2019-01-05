
void setup() {
  // put your setup code here, to run once:
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(9, OUTPUT);

  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(10, HIGH);
  //digitalWrite(9, HIGH);
  analogWrite(9, 230);
}
