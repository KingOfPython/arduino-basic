void setup() {

}

void loop() {
  analogWrite(9, map(analogRead(A0), 0, 1023, 0, 255)); // map 특정 범위에 속하는 값을 다른 범위의 값으로 변환해줌

  // ADC 는 0~1023 값을 줌. 10bit
  // pwm 은 0에서 255 사이로 값을 출력 가능.
}
