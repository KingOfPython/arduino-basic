int soundSensor = A0;     // 사운드 센서 핀
int led[6] = {8, 9, 10, 11};
int threshold = 500; // 소리 크기 기준
int count = 0;      // 박수를 몇 번 쳤는지 카운트

void setup() {               
  Serial.begin(9600); // 시리얼모니터 출력
  pinMode(soundSensor, INPUT);  // 사운드 센서 입력으로 설정  
  for(int i=0; i<6; i++)      // LED 핀 출력으로 설정
    pinMode(led[i], OUTPUT);    
}

void loop() {     
  if( analogRead(soundSensor) >= threshold){    // 감지된 소리의 크기가 500 이상일 때
    for(int i=0; i<4; i++){ // 4개의 led 제어
      if(i == count % 4)        // 카운트 된 박수 개수로 led 제어 
        digitalWrite(led[i], HIGH);   
      else 
        digitalWrite(led[i], LOW);
    }
    Serial.println(String("Count : ")+count);
    count++;
    delay(200);     // 박수 중복 입력이 안되게 200ms 딜레이
  } 
  else       // 감지된 소리의 크기가 500 이하일 때 
    delay(1);
}
