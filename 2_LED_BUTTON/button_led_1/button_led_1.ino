#define LED 12
#define BUTTON 7
void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON,INPUT);
}

void loop() {
  if(digitalRead(BUTTON) == LOW){
    digitalWrite(LED, HIGH);
  }else
  {
    digitalWrite(LED, LOW);
  }
}
