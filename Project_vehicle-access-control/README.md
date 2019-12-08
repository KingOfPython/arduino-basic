# 주차장 출입 시스템

### 1. 사용 센서 및 엑츄에이터의 역할
 **초음파 센서, 서보모터, 1602LCD, 3색 LED**
 1. 초음파 센서 : 차량을 감지
 2. 서보 모터 : 차단기 제어
 3. 3색 LED : 통행 가능시 - 초록불 등화, 통행 불가시 - 빨간불 등화

### 2. 시나리오
 1. 초음파 센서에 차량이 감지
   - 너무 가깝거나, 너무 멀게 감지 될 경우 오작동으로 간주
 2. 1602 LCD에 주차 정보 표시 (남은 좌석, 만차시 입장 불가)
 3. 주차 가능시, 차단기 문이 열리며, 3색 LED 초록불 등화
 4. 초음파 센서에 차량 감지가 멈출경우, 3초 후 차단기 동작 및 3색 LED 빨간불 등화

### 3. 사용 라이브러리
 1. Servo (https://www.arduino.cc/en/reference/servo)
  - 서보 모터 제어를 위해 사용
 2. LiquidCrystal_I2C (https://www.arduino.cc/en/Reference/LiquidCrystal)
  - I2C 모듈이 장착된 1602LCD 를 제어 하기위해 사용
 3. NewPing (https://playground.arduino.cc/Code/NewPing/)
  * NewPing -> 기존 pulseIn에 비해, 사용이 편리 (주의. ATmega 내부의 Time2 를 사용하기 때문에 tone 함수와 충돌)
  - pulseIn을 이용할 경우, 돌아오는 초음파를 기다리는데 딜레이가 있어, 전체 코드가 수행되는데, 지연이 됨 (다수의 초음파 센서 연결 시, 문제 발생)
  - pulseIn에 비해, 튀는 값 발생 (http://bit.ly/341ULVA) 

### 4. 1page 제안서
![텀프로젝트_1page_계획서_초안_191202](https://user-images.githubusercontent.com/33712754/70391778-3f33fe80-1a1c-11ea-8b8e-23bccde4282c.png)
