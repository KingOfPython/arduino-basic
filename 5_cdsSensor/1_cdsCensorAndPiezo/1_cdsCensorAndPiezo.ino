void setup() {
  Serial.begin(9600);
  
}

void loop() {
  // tone(pin, frequency, duration)
  //  pin: tone을 발생시킬 핀
  //  frequency: tone의 주파수 (Hz 단위) - unsigned int
  // duration (옵션) : tone 의 지속 시간 (밀리초 단위) - unsigned long
    tone(8, map(analogRead(A0), 0, 1023, 31, 4978),20); // map 특정 범위에 속하는 값을 다른 범위의 값으로 변환해줌
//  tone(8, 1000 ,map(analogRead(A0), 150, 900, 0, 1000));
  Serial.print("ADC : ");
  Serial.println(analogRead(A0));

//  delay(900);

  // ADC 는 0~1023 값을 줌. 10bit
  // pwm 은 0에서 255 사이로 값을 출력 가능.
}
