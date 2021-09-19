#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

#include "Secrets.h"

Adafruit_MPU6050 mpu;

int onboardLED = 2;

const int SIZE_OF_ARRAY = 50;

// gyroscope settings
float gyro_X = 0;
float gyro_X_error = 0.01;
float Time_Now, Time_Previous, elapsedTime;

char json_output[2048];

// used for waiting
unsigned long start_time;
unsigned long current_time;
const int period = 0;

// decalre functions
void post_request();

void setup(){
  Serial.begin(9600);
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

  pinMode(onboardLED, OUTPUT);

  // Initialize the start time
  start_time = millis();
  Serial.println("Setup complete \n");
  delay(4000);
}

void loop(){

  StaticJsonDocument<2048> doc;
  JsonArray data = doc.createNestedArray("data");

  for (int i = 0; i < SIZE_OF_ARRAY; i++){

    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);

    Time_Previous = Time_Now;
    Time_Now = millis();
    elapsedTime = (Time_Now - Time_Previous)/1000;

    float angular_velocity = (g.gyro.x+2.15115175);
    if (abs(angular_velocity) > gyro_X_error){
      gyro_X += angular_velocity*elapsedTime;
    }

    Serial.print(angular_velocity);
    Serial.print("     ");
    Serial.println(gyro_X);
    //data.add(gyro_X);
    delay(5);
  }
  serializeJson(doc, json_output);
  
  //post_request();

}

void post_request(){
  // will only send data after a certain period
  // does not need to pause the program in order to wait

  current_time = millis();
  if (WiFi.status() == WL_CONNECTED && current_time - start_time >= period){
    
    digitalWrite(onboardLED, HIGH);

    // create a endpoint
    HTTPClient client;
    client.begin("https://form-check-hixwog3m7q-uc.a.run.app/");
    client.addHeader("Content-Type", "application/json");
    
    // Format the data correctly

    int httpCode = client.POST(String(json_output));  

    if (httpCode > 0){
      String payload = client.getString();

      Serial.println("StatusCode:" + String(httpCode));
      Serial.println(payload);
    }

    // reset the delay
    start_time = current_time;
    digitalWrite(onboardLED, LOW);

  }else if (current_time - start_time < period){
    Serial.println("Wating for next API call");
    delay(1000);

  }else{
    Serial.println("Connection Lost");
    delay(1000);
  }  
}