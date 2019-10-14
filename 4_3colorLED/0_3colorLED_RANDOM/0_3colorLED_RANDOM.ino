#define RED 11
#define GREEN 10
#define BLUE 9
void setup() {
  randomSeed(analogRead(0));
  // 랜덤Seed 값을 랜덤하게 주기 위하여 사용, 플로팅 현상을 이용
}

void loop() {
  analogWrite(RED, random(255));
  analogWrite(GREEN, random(255));
  analogWrite(BLUE, random(255));
  delay(100);
}
