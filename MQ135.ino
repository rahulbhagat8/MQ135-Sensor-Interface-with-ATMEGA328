#include "MQ135.h"
#define PIN_MQ135 A2
MQ135 mq135_sensor = MQ135(PIN_MQ135);
float temperature = 21.0; // assume current temperature. Recommended to measure with DHT22
float humidity = 25.0; // assume current humidity. Recommended to measure with DHT22
int printGraphNo = 2;
void setup() {
  Serial.begin(115200);
}
//wave form No-1= goes down, normal 165, in itchen 140
//2 normal 107 in kitchen 93
//3 goes up,normal 36 in kitchen 60+
void loop() {
  float rzero = mq135_sensor.getRZero();
  float correctedRZero = mq135_sensor.getCorrectedRZero(temperature, humidity);
  float resistance = mq135_sensor.getResistance();
  float ppm = mq135_sensor.getPPM();
  float correctedPPM = mq135_sensor.getCorrectedPPM(temperature, humidity);
//  if (printGraphNo == 1)
//    Serial.println(correctedRZero);
//  if (printGraphNo == 2)
//    Serial.println(resistance);
//  if (printGraphNo == 3)
//    Serial.println(correctedPPM);

    Serial.println(correctedRZero);
//    Serial.print(" ");
//    Serial.println(resistance);
    delay(10);

}
