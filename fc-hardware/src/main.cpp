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
int greenLED = 14;

// gyroscope settings
float gyro_X = 0;
float gyro_X_error = 0.025;
float Time_Now, Time_Previous, elapsedTime;

// JSON settings
const int SIZE_OF_ARRAY = 1000;
char json_output[2048];

// used for waiting
// unsigned long start_time;
// unsigned long current_time;
// const int period = 0;

TaskHandle_t Task1, Task2;
SemaphoreHandle_t baton;

void gather_data(){
  digitalWrite(greenLED, HIGH);

  StaticJsonDocument<2048> doc;
  JsonArray data = doc.createNestedArray("data");

  // store the 
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

    // used for debuging
    // Serial.print(angular_velocity);
    // Serial.print("     ");
    // Serial.println(180*gyro_X);

    if (i%10 == 0){
      data.add(180*gyro_X);
      Serial.print(angular_velocity);
      Serial.print("     ");
      Serial.println(180*gyro_X);
    }
    delay(10);
  }
  serializeJson(doc, json_output);
}

void post_request(){
  // will only send data after a certain period
  // does not need to pause the program in order to wait
  // NO LONGER NEED THIS
  // current_time = millis();
  // if (WiFi.status() == WL_CONNECTED && current_time - start_time >= period){
    

  if (WiFi.status() == WL_CONNECTED){
    
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

    digitalWrite(onboardLED, LOW);

    // reset the delay
    // start_time = current_time;

  // }else if (current_time - start_time < period){
  //   Serial.println("Wating for next API call");
  //   delay(1000);

  }else{
    Serial.println("Connection Lost");
    delay(1000);
  }  
}

void readGyro( void * parameter )
{
  for (;;) {
    xSemaphoreTake( baton, portMAX_DELAY );
    gather_data();
    xSemaphoreGive( baton );
    delay(50);
    Serial.println("Task 1 done ");
  }
}

void sendPost( void * parameter )
{
  for (;;) {
    xSemaphoreTake( baton, portMAX_DELAY );
    xSemaphoreGive( baton );
    post_request();
    delay(50);
    Serial.println("                            Task 2 done ");
  }
}

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);

  // from Secrets.h
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
  pinMode(greenLED, OUTPUT);

  // Initialize the start time
  // start_time = millis();
  Serial.println("Setup complete \n");
  delay(2000);

  baton = xSemaphoreCreateMutex();

  /*
  Task function,
  Name of task,
  Stack Size of task,
  Parameter of task,
  Priority of the task,
  Task handle to keep track of created task
  Core
  */
  xTaskCreatePinnedToCore(
    readGyro,
    "read data",
    4096,
    NULL,
    1,
    &Task1,
    0);
  delay(500);  // needed to start-up task1

  xTaskCreatePinnedToCore(
    sendPost,
    "send data",
    4096,
    NULL,
    1,
    &Task2,
    1);

}


void loop() {

  delay(10);
}
