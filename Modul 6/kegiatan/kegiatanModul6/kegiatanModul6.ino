// #include <DHT.h>
// #define DHT_SENSOR_PIN 21    // ESP32 pin GPIO21 connected to DHT11 sensor
// #define DHT_SENSOR_TYPE DHT11
// #define BUZZER_PIN 32

// DHT dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

// void setup() {
//   Serial.begin(9600);
//   dht_sensor.begin();          // initialize the DHT sensor
//   pinMode(BUZZER_PIN, OUTPUT); // set Buzzer pin as an output
// }

// void loop() {
//   // read humidity
//   float humi = dht_sensor.readHumidity();
//   // read temperature in Celsius
//   float tempC = dht_sensor.readTemperature();
//   // read temperature in Fahrenheit
//   float tempF = dht_sensor.readTemperature(true);

//   // check whether the reading is successful or not
//   if (isnan(tempC) || isnan(tempF) || isnan(humi)) {
//     Serial.println("Failed to read from DHT sensor!");
//   } else {
//     Serial.print("Humidity: ");
//     Serial.print(humi);
//     Serial.print("%");

//     Serial.print("  |  ");

//     Serial.print("Temperature: ");
//     Serial.print(tempC);
//     Serial.print("°C  ~  ");
//     Serial.print(tempF);
//     Serial.println("°F");

//     // Check temperature conditions and control the buzzer
//     if (tempC > 30.0) { // High temperature - Suhu panas
//       tone(BUZZER_PIN, 1000); // High-frequency buzzer - Frekuensi buzzer kencang
//       Serial.println("High temperature! Turn on the ventilation immediately."); // Keterangan: Suhu tinggi, nyalakan ventilasi segera
//     } else if (tempC > 25.0) { // Moderate temperature - Suhu hangat
//       tone(BUZZER_PIN, 500); // Moderate-frequency buzzer - Frekuensi buzzer sedang
//       Serial.println("Moderate temperature. Consider turning on the ventilation."); // Keterangan: Suhu sedang, pertimbangkan untuk menyalakan ventilasi
//     } else { // Normal temperature - Suhu normal
//       noTone(BUZZER_PIN); // Turn off the buzzer - Matikan buzzer
//       Serial.println("Temperature is normal. Buzzer turned off."); // Keterangan: Suhu normal, buzzer dimatikan
//     }
//   }

//   // wait 2 seconds between readings
//   delay(2000);
// }

// #define BLYNK_TEMPLATE_ID "TMPL6kUuAil2r"
// #define BLYNK_TEMPLATE_NAME "M4"
// #define BLYNK_AUTH_TOKEN "EgxkrrA38G-Dhzs5pRKcUJfnHX3ePsTd"
// #define BLYNK_PRINT Serial
// #include <WiFi.h>
// #include <WiFiClient.h>
// #include <BlynkSimpleEsp32.h>
// #include <DHT.h>
// #define DHT_SENSOR_PIN 21    // ESP32 pin GPIO21 connected to DHT11 sensor
// #define DHT_SENSOR_TYPE DHT11
// #define BUZZER_PIN 32

// DHT dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

// BlynkTimer timer;

// char auth[] = BLYNK_AUTH_TOKEN; // Your Blynk Auth Token
// char ssid[] = "Ulumganteng";
// char pass[] = "arul12345";


// void send_data() {
//   float tempC = dht_sensor.readTemperature();

//   if (isnan(tempC)) {
//     Serial.println("Failed to read from DHT sensor!");
//     return;
//   }

//   Blynk.virtualWrite(V3, tempC); // Send temperature data to Blynk V5 widget

//   // Check temperature conditions and control the buzzer
//   if (tempC > 30.0) { // High temperature - Suhu panas
//     tone(BUZZER_PIN, 1000); // High-frequency buzzer - Frekuensi buzzer kencang
//     Blynk.virtualWrite(V4, "High Temperature"); // Send status to Blynk V1 widget
//   } else if (tempC > 25.0) { // Moderate temperature - Suhu hangat
//     tone(BUZZER_PIN, 500); // Moderate-frequency buzzer - Frekuensi buzzer sedang
//     Blynk.virtualWrite(V4, "Moderate Temperature"); // Send status to Blynk V1 widget
//   } else { // Normal temperature - Suhu normal
//     noTone(BUZZER_PIN); // Turn off the buzzer - Matikan buzzer
//     Blynk.virtualWrite(V4, "Normal Temperature"); // Send status to Blynk V1 widget
//   }

//   Serial.print("Temperature: ");
//   Serial.print(tempC);
//   Serial.println("°C");
// }

// void setup() {
//   Serial.begin(9600);
//   dht_sensor.begin();          // initialize the DHT sensor
//   pinMode(BUZZER_PIN, OUTPUT); // set Buzzer pin as an output

//   Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
//   timer.setInterval(1000L, send_data);
// }

// void loop() {
//   Blynk.run();
//   timer.run();
// }


#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>

#define DHT_SENSOR_PIN 21
#define DHT_SENSOR_TYPE DHT11

DHT dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);
const char *ssid = "Ulumganteng";
const char *password = "arul12345";

void setup() {
  Serial.begin(9600);
  dht_sensor.begin();
  connectToWiFi();
}

void loop() {
  float tempC = dht_sensor.readTemperature();

  if (!isnan(tempC)) {
    sendTemperature(tempC);
    delay(5000); // Sending data every 5 seconds
  } else {
    Serial.println("Failed to read temperature!");
  }
}

void connectToWiFi() {
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
}

void sendTemperature(float tempC) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String serverUrl = "http://your_server_ip/pirdas6/send.php?sensor=" + String(tempC);
    
    http.begin(serverUrl);

    int httpCode = http.GET();
    if (httpCode > 0) {
      if (httpCode == HTTP_CODE_OK) {
        String payload = http.getString();
        Serial.println(payload);
      }
    } else {
      Serial.println("Error on HTTP request");
    }

    http.end();
  }
}
