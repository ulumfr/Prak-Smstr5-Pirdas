// // Latihan 1

// #include <WiFi.h>

// const char* ssid = "CekUlum";

// void setup() {
//   Serial.begin(9600);
//   WiFi.begin(ssid);

//   while (WiFi.status() != WL_CONNECTED){
//     delay(1000);
//     Serial.println("Connecting to Wifi....");
//   }

//   Serial.println("Connected to Wifi");
// }

// void loop() {
//   // put your main code here, to run repeatedly:

// }


// Latihan 2
// #include <MPU6050_tockn.h>
// #include <Wire.h>

// MPU6050 mpu6050(Wire);

// void setup(){
//   Serial.begin(9600);
//   Wire.begin();
//   mpu6050.begin();
//   mpu6050.calcGyroOffsets();
// }

// void loop(){
//   mpu6050.update();
//   Serial.println("anglex : ");
//   Serial.println(mpu6050.getAngleX());
//   Serial.println("angleY : ");
//   Serial.println(mpu6050.getAngleY());
//   Serial.println("angleZ : ");
//   Serial.println(mpu6050.getAngleZ());
//   delay(1000);
// }
