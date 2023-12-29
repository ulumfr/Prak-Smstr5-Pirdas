// // Kegiatan 1
// #include <WiFi.h>

// const char* ssid = "cari wifi y?"; // Ganti dengan SSID jaringan WiFi yang ingin Anda hubungkan
// const char* password = "1sampai9"; // Ganti dengan password jaringan WiFi yang ingin Anda hubungkan

// void setup() {
//   Serial.begin(9600);

//   // Menghubungkan ESP32 ke jaringan WiFi yang memiliki SSID dan password
//   Serial.print("Menghubungkan ke ");
//   Serial.println(ssid);
//   WiFi.begin(ssid, password);

//   while (WiFi.status() != WL_CONNECTED) {
//     delay(1000);
//     Serial.println("Gagal terhubung ke jaringan WiFi. Mencoba koneksi ke jaringan terbuka...");
    
//     // Mencoba terhubung ke jaringan WiFi terbuka
//     WiFi.begin("", ""); // Tidak ada SSID atau password
//   }

//   Serial.println("Terhubung ke jaringan WiFi");
//   Serial.print("Nama SSID: ");
//   Serial.println(WiFi.SSID());
// }

// void loop() {
//   // Kode Anda dapat ditempatkan di sini
// }

// #include <WiFi.h>

// const char* ssid = "cari wifi y?";
// const char* password =  "1sampai9";

// void setup() {
//   Serial.begin(9600);

//   if (WiFi.begin(ssid, password) == WL_CONNECTED) {
//     Serial.println("Connected to the WiFi network");
//     Serial.print("SSID: ");
//     Serial.println(ssid);
//   } else {
//     Serial.println("Failed to connect to the specified network. Trying to connect to an open network...");
//     WiFi.disconnect();
//     delay(1000);

//     int numNetworks = WiFi.scanNetworks();
//     for (int i = 0; i < numNetworks; i++) {
//       if (WiFi.encryptionType(i) == WIFI_AUTH_OPEN) {
//         Serial.println("Connecting to an open WiFi network...");
//         WiFi.begin(WiFi.SSID(i).c_str());
//         while (WiFi.status() != WL_CONNECTED) {
//           delay(500);
//           Serial.println("Connecting to WiFi..");
//         }

//         Serial.println("Connected to an open WiFi network");
//         Serial.print("SSID: ");
//         Serial.println(WiFi.SSID(i));
//         break;      
//       }
//     }
//   }

//   Serial.println("WiFi connected.");
//   Serial.println("IP address: ");
//   Serial.println(WiFi.localIP());
// }

// void loop() {}


// Kegiatan 2
#include <MPU6050_tockn.h>
#include <WiFi.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

const char* ssid = "cekulum";

const int buzzerPin = 25;

void setup() {
  Serial.begin(115200);
  pinMode(buzzerPin, OUTPUT);
  WiFi.begin(ssid);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets();
}

void loop() {
  mpu6050.update();
  Serial.print("Angle X : ");
  Serial.print(mpu6050.getAngleX());
  Serial.print("\tAngle Y : ");
  Serial.println(mpu6050.getAngleY());
  if (mpu6050.getAngleX() > 20) {
    analogWrite(buzzerPin, 63);
    Serial.println("Tilted Forward");
  } else if (mpu6050.getAngleX() < -20) {
    analogWrite(buzzerPin, 126);
    Serial.println("Tilted Back");
  } else if (mpu6050.getAngleY() > 20) {
    analogWrite(buzzerPin, 189);
    Serial.println("Tilted To The Left");
  } else if (mpu6050.getAngleY() < -20) {
    analogWrite(buzzerPin, 255);
    Serial.println("Tilted To The Right");
  } else {
    analogWrite(buzzerPin, 0);
  }
  delay(500);
}