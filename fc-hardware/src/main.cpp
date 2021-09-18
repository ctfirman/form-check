#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

#include "Secrets.h"

Adafruit_MPU6050 mpu;

int onboardLED = 2;

void setup(){

  pinMode(onboardLED, OUTPUT);

  Serial.begin(9600);
  // Serial.begin(115200);
  delay(4000);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.println("Connecting to Wifi...");
  }

  Serial.println("Connected to Wifi");

  while (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    delay(1000);
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);

  Serial.println("Setup complete \n");
}

void loop(){
  digitalWrite(onboardLED, HIGH);
  Serial.println("This prints every few seconds");
  delay(500);
  digitalWrite(onboardLED, LOW);

  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  // Serial.print("Acceleration X: ");
  // Serial.print(a.acceleration.x);
  // Serial.print(", Y: ");
  // Serial.print(a.acceleration.y);
  // Serial.print(", Z: ");
  // Serial.print(a.acceleration.z);
  // Serial.println(" m/s^2");

  Serial.print("Rotation X: ");
  Serial.print(g.gyro.x);
  Serial.print(", Y: ");
  Serial.print(g.gyro.y);
  Serial.print(", Z: ");
  Serial.print(g.gyro.z);
  Serial.println(" rad/s");

  // Serial.print("Temperature: ");
  // Serial.print(temp.temperature);
  // Serial.println(" degC");

  Serial.println("");
  delay(500);

  // if (WiFi.status() == WL_CONNECTED){
    
  //   HTTPClient client;
  //   client.begin("https://reqres.in/api/users/2");
  //   int httpCode = client.GET();  

  //   if (httpCode > 0){
  //     String payload = client.getString();

  //     Serial.println("StatusCode:" + String(httpCode));
  //     Serial.println(payload);
  //   }

  // }else{
  //   Serial.println("Connection Lost");
  // }
  
}
