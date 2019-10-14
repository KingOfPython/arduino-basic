void setup() {
  Serial.begin(9600);
}

void loop() {
  for(int i=1; i<10; i++){
    for(int j=1; j<10; j++){
      Serial.print(i);
      Serial.print(" X ");
      Serial.print(j);
      Serial.print(" = ");
      Serial.println(i*j);
      delay(500);  // 0.5sec
    }
  }
}
