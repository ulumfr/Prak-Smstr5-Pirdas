// #define BLYNK_TEMPLATE_ID "TMPL6kUuAil2r"
// #define BLYNK_TEMPLATE_NAME "M4"
// #define BLYNK_AUTH_TOKEN "EgxkrrA38G-Dhzs5pRKcUJfnHX3ePsTd"
// #define BLYNK_PRINT Serial
// #include <WiFi.h>
// #include <WiFiClient.h>
// #include <BlynkSimpleEsp32.h>
// #define LIGHT_SENSOR_PIN 32
// #define RELAY_PIN 27
// #define ANALOG_THRESHOLD 500

// BlynkTimer timer;

// char auth[] = BLYNK_AUTH_TOKEN;
// char ssid[] = "Ulumganteng";
// char pass[] = "arul12345";

// void send_data() {
//   int analogValue = analogRead(LIGHT_SENSOR_PIN);
//   Serial.print("Analog Value = ");
//   Serial.println(analogValue);

//   if (analogValue < ANALOG_THRESHOLD) {
//     digitalWrite(RELAY_PIN, HIGH);
//     Blynk.virtualWrite(V1, "Lampu Menyala");
//   } else {
//     digitalWrite(RELAY_PIN, LOW);
//     Blynk.virtualWrite(V1, "Lampu Mati");
//   }

//   Serial.print("Relay Status: ");
//   Serial.println(digitalRead(RELAY_PIN));

//   Blynk.virtualWrite(V0, analogValue);
// }

// void setup() {
//   pinMode(RELAY_PIN, OUTPUT);
//   Serial.begin(9600);
//   Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
//   timer.setInterval(1000L, send_data);
// }

// void loop() {
//   Blynk.run();
//   timer.run();
// }

#define BLYNK_TEMPLATE_ID "TMPL6kUuAil2r"
#define BLYNK_TEMPLATE_NAME "M4"
#define BLYNK_AUTH_TOKEN "EgxkrrA38G-Dhzs5pRKcUJfnHX3ePsTd"
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#define RELAY_PIN 27

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Ulumganteng";
char pass[] = "arul12345";

BLYNK_WRITE(V2) {
  int pinValue = param.asInt();
  if (pinValue == 1) {
    digitalWrite(RELAY_PIN, HIGH);
    Blynk.virtualWrite(V1, "Lampu Menyala");
  } else {
    digitalWrite(RELAY_PIN, LOW);
    Blynk.virtualWrite(V1, "Lampu Mati");
  }
  Serial.print("Relay Status: ");
  Serial.println(digitalRead(RELAY_PIN));
}

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  Blynk.run();
}