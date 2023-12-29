// #define LIGHT_SENSOR_PIN 14
// #define THRESHOLD_DARK 50
// #define THRESHOLD_DIM 500
// #define THRESHOLD_BRIGHT 2000

// #include <MPU6050_tockn.h>
// #include <Wire.h>

// MPU6050 mpu6050(Wire);

// void setup() {
//   Serial.begin(9600);
//   Wire.begin();
//   mpu6050.begin();
//   mpu6050.calcGyroOffsets();
// }

// void loop() {
//   int lightIntensity = analogRead(LIGHT_SENSOR_PIN);

//   Serial.print("Light Intensity: ");
//   Serial.println(lightIntensity);

//   if (lightIntensity >= 0 && lightIntensity < THRESHOLD_DARK) {
//     Serial.println("Keadaan gelap");
//   } else if (lightIntensity >= THRESHOLD_DARK && lightIntensity < THRESHOLD_DIM) {
//     Serial.println("Keadaan redup");
//   } else if (lightIntensity >= THRESHOLD_DIM && lightIntensity < THRESHOLD_BRIGHT) {
//     Serial.println("Cahaya terang");
//   } else {
//     Serial.println("Sangat terang");
//   }

//   mpu6050.update();

//   Serial.print("Angle X: ");
//   Serial.println(mpu6050.getAngleX());
//   Serial.print("Angle Y: ");
//   Serial.println(mpu6050.getAngleY());

//   if (mpu6050.getAngleX() > 10) {
//     Serial.println("Sensor miring kiri");
//   } else if (mpu6050.getAngleX() < -10) {
//     Serial.println("Sensor miring kanan");
//   } else if (mpu6050.getAngleY() > 10) {
//     Serial.println("Sensor miring depan");
//   } else if (mpu6050.getAngleY() < -10) {
//     Serial.println("Sensor miring belakang");
//   }

//   delay(1000);
// }

#include <Arduino.h>
#include <WiFi.h>
#include <Wire.h>
#include <HTTPClient.h>
#include <MPU6050_tockn.h>

MPU6050 mpu6050(Wire);

const char* ssid = "Ulumganteng";
const char* password = "arul12345";
const char* serverName = "http://192.168.156.11/pirdas4/sensor.php";

void setup() {
  Serial.begin(9600);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFI...");
  }

  Serial.println("Connected to WiFi");

  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets();
}

void loop() {
  mpu6050.update();

  int angka_sumbuX = mpu6050.getAngleX();
  int angka_sumbuY = mpu6050.getAngleY();

  Serial.print("Angle X: ");
  Serial.println(angka_sumbuX);
  Serial.print("Angle Y: ");
  Serial.println(angka_sumbuY);

  String kemiringan;

  if (angka_sumbuX > 10) {
    kemiringan = "kiri";
    Serial.println("Sensor miring kiri");
  } else if (angka_sumbuX < -10) {
    kemiringan = "kanan";
    Serial.println("Sensor miring kanan");
  } else if (angka_sumbuY > 10) {
    kemiringan = "depan";
    Serial.println("Sensor miring depan");
  } else if (angka_sumbuY < -10) {
    kemiringan = "belakang";
    Serial.println("Sensor miring belakang");
  } else {
    kemiringan = "tidak miring";
    Serial.println("Tidak ada kemiringan");
  }

  String url = serverName ;
  url += "?angka_sumbuX=";
  url += String(angka_sumbuX);
  url += "&angka_sumbuY=";
  url += String(angka_sumbuY);
  url += "&kemiringan=";
  url += String(kemiringan);

  HTTPClient http;
  http.begin(url);
  int httpResponseCode = http.GET();

  if (httpResponseCode == 200) {
    Serial.println("Data terkirim!");
  } else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  http.end();

  delay(5000);
}
