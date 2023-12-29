#include <MPU6050_tockn.h>
#include <Wire.h>
#include <WiFi.h>
#include <HTTPClient.h>

#define LED 32

MPU6050 mpu6050(Wire);

const int buzzerPin = 26;

char ssid[] = "Ulumganteng";
char password[] = "arul12345";
const char *serverUrl = "http://192.168.63.216/demopirdas6/send.php";

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(LED, OUTPUT);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets();

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  mpu6050.update();
  float angleX = mpu6050.getAngleX();
  float angleY = mpu6050.getAngleY();
  String status = (angleX > -50 && angleX < 50 && angleY > -50 && angleY < 50) ? "Safe" : "Tilted";

  Serial.print("Angle X : ");
  Serial.print(angleX);
  Serial.print("\tAngle Y : ");
  Serial.println(angleY);
  Serial.println("Status: " + status);

  // Create JSON data
  String json_data = "{\"angleX\":" + String(angleX) + ",\"angleY\":" + String(angleY) + ",\"status_sensor\":\"" + status + "\"}";

// Send data to PHP script
  HTTPClient http;
  http.begin(serverUrl);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

  int httpCode = http.POST("angleX=" + String(angleX) + "&angleY=" + String(angleY) + "&status_sensor=" + status);
  if (httpCode > 0) {
      Serial.printf("[HTTP] POST... code: %d\n", httpCode);
      if (httpCode == HTTP_CODE_OK) {
          String payload = http.getString();
          Serial.println(payload);
      }
  } else {
      Serial.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }

  http.end();

  if (angleX > -50 && angleX < 50 && angleY > -50 && angleY < 50) {
    // MPU6050 is in a flat position
    digitalWrite(LED, HIGH); // Turn on LED
    analogWrite(buzzerPin, 0); // Turn off Buzzer
    Serial.println("Safe");
  } else {
    // MPU6050 is tilted
    digitalWrite(LED, LOW); // Turn off LED
    analogWrite(buzzerPin, 255); // Turn on Buzzer with a loud sound
    Serial.println("Tilted!");
  }

  delay(3000); // 3-second delay

}