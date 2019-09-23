#define DELAY_TIME 500

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  digitalWrite(2, HIGH);
  delay(DELAY_TIME);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  delay(DELAY_TIME);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  delay(DELAY_TIME);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  delay(DELAY_TIME);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  delay(DELAY_TIME);
  digitalWrite(6, LOW);
}
