int piezoPin = 8;
int sensorPin = 0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  int readADC = analogRead(A0);

  Serial.print("ReadADC : ");
  Serial.println(readADC);

  float voltage = (readADC/1023.0)*5.0;
  Serial.print("V  : ");
  Serial.println(voltage);
  
  float temperatureC = (voltage * 100) - 50  ;
  Serial.print("Temp : ");
  Serial.println(temperatureC);

  if(temperatureC >= 20.0)
  {
   tone(piezoPin,500);
  }
  else{
    noTone(piezoPin);
  }
  
  
  delay(1000);
  // ADC 는 0~1023 값을 줌. 10bit
  // pwm 은 0에서 255 사이로 값을 출력 가능.
}
