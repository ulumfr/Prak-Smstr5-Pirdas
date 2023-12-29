


#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>



#define LIGHT_SENSOR_PIN 32
BlynkTimer timer;

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Ulumganteng";
char pass[] = "arul12345"

void send_data() {
  delay(1000);
  int analogValue = analogRead(LIGHT_SENSOR_PIN);
  Serial.print("Analog Value = ");
  Serial.println(analogValue);

  Blynk.virtualWrite(V0, analogValue);
}

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  time.setInterval(1000L, send_data);
}

void loop() {
  Blynk.run();
  timer.run();
}
