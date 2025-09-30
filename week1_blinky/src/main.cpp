#include <Arduino.h>
const uint8_t LED_PIN = 2; // 宣告 LED_PIN 常數

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  Serial.println("ESP32 Blinky Ready");
}
void loop() {
  digitalWrite(LED_PIN, !digitalRead(LED_PIN));
  delay(500);
}
