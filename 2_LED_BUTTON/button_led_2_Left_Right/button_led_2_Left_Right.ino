#define L_LED 12
#define R_LED 13
#define L_BUTTON 3
#define R_BUTTON 2
void setup() {
  // put your setup code here, to run once:
  pinMode(L_LED, OUTPUT);
  pinMode(R_LED, OUTPUT);
  pinMode(L_BUTTON,INPUT);
  pinMode(R_BUTTON,INPUT);
}

void loop() {
  if(digitalRead(L_BUTTON) == HIGH){
    digitalWrite(L_LED, HIGH);
  }else{
    digitalWrite(L_LED, LOW);
  }

  if(digitalRead(R_BUTTON) == HIGH){
    digitalWrite(R_LED, HIGH);
  }else{
    digitalWrite(R_LED, LOW);
  }
  
}
