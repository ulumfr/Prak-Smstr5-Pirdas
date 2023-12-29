#include <WiFi.h>
#include <HTTPClient.h>

#define RELAY_PIN 4
#define MOISTURE_PIN 34
#define THRESHOLD 45
int kelembaban;

char ssid[] = "Ulumganteng";
char password[] = "arul12345";
const char *serverUrl = "http://192.168.39.216/uappirdas/send.php";

bool isAutoMode = true;

void setup() {
  Serial.begin(9600); 
  pinMode(RELAY_PIN, OUTPUT);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  int value = analogRead(MOISTURE_PIN);
  kelembaban = 100 - ((value / 4095.00) * 100);
  
  String kondisi = (kelembaban < THRESHOLD) ? "DRY" : "WET";

  if (kelembaban < THRESHOLD) {
    Serial.println("The soil is DRY => turn pump ON");
    digitalWrite(RELAY_PIN, LOW);
    kondisi = "DRY";
  } else {
    Serial.println("The soil is WET => turn pump OFF");
    digitalWrite(RELAY_PIN, HIGH);
    kondisi = "WET";
  }

  Serial.print("Kelembaban: ");
  Serial.print(kelembaban);
  Serial.print("%, Kondisi: ");
  Serial.println(kondisi);

  String json_data = "{\"kelembaban\":" + String(kelembaban) + ",\"kondisi\":\"" + kondisi + "\"}";

  HTTPClient http;
  http.begin(serverUrl);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

  int httpCode = http.POST("kelembaban=" + String(kelembaban) + "&kondisi=" + kondisi);

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

  delay(3000);
}