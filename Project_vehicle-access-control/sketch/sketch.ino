#include <NewPing.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

Servo servo;

const byte servoPin = 7;
const byte sonicTrig = 5; 
const byte sonicEcho = 6;
const byte gPin = 8;
const byte rPin = 9;
int m_distance=0; //거리
boolean state = false; //차단막 제어
unsigned long timeVal=0;

int spaces = 5;   // 주차 자리
int inByte = 0;   // 입력


LiquidCrystal_I2C lcd(0x27,16,2);

NewPing sonar(6, 5, 200); // (Trig, Echo. 거리제한)

void setup() {
  
  Serial.begin(9600);
  
  pinMode(gPin, OUTPUT);
  pinMode(rPin, OUTPUT);  

  servo.attach(servoPin); 
  servo.write(90);


  lcd.init();
  lcd.backlight();
  lcd.print("Parking Area");
  lcd.setCursor(0,1);
  lcd.print("empty:");
  
  digitalWrite(rPin, HIGH);
}

void loop() {  
  lcd.setCursor(7,1);
  lcd.print(spaces);
  delay(50);            
  m_distance=sonar.ping_cm();  //초음파센서로 거리계산함수  
  //Serial.println(m_distance);
  if(m_distance>1 && m_distance<20 && spaces > 0){  
    Serial.println("동작");
    if(state==false){
      servo.write(0);
      delay(2000); 
      state=true;          
      digitalWrite(rPin, LOW);
      digitalWrite(gPin, HIGH);      
      spaces--;
    }
    timeVal=millis();
  }  
  if(state==true){
    if(millis()-timeVal>=3000){
      servo.write(90);
      state=false;
      digitalWrite(gPin, LOW);
      digitalWrite(rPin, HIGH);
    }    
  }

   // 출차 0
  if (Serial.available())
  {
    inByte = Serial.read();
    if(inByte == 1){
      Serial.write("출차되었습니다.");
      spaces++;
    }
    else if(inByte == 0){
      Serial.write("000000");
    }
  }
}
