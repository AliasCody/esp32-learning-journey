// #include <Arduino.h>
// const uint8_t LED_PIN = 2; // 宣告 LED_PIN 常數

// void setup() {
//   pinMode(LED_PIN, OUTPUT);
//   Serial.begin(115200);
//   Serial.println("ESP32 Blinky Ready");
// }
// void loop() {
//   digitalWrite(LED_PIN, !digitalRead(LED_PIN));
//   delay(500);
// }


#include<Arduino.h>
const uint8_t LED_PIN = 2;

void setup(){
  pinMode(LED_PIN,OUTPUT);
  Serial.begin(115200);
  Serial.println("ESP32 LED Pattern Ready");
}

void loop(){
  // 快閃
  for(int i=0 ; i<3 ; i++){
    digitalWrite(LED_PIN,HIGH);
    delay(200);
    digitalWrite(LED_PIN,LOW);
    delay(200);
  }

  // 停 1 秒
  delay(1000);
}