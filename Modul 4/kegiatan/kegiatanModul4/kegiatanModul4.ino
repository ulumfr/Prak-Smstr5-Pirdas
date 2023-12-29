// int LDR_Val = 0;
// int SENSOR = 34;
// int LED = 25;

// void setup(){
//     Serial.begin(9600);
//     pinMode(LED, OUTPUT);
// }

// void loop(){
//     LDR_Val = analogRead(SENSOR);
//     Serial.print("LDR Output: ");
//     Serial.println(LDR_Val);
//     if(LDR_Val > 100){
//         Serial.println("Cahaya Terang");
//         digitalWrite(LED, LOW);
//     }else{
//         Serial.println("Cahaya Gelap");
//         digitalWrite(LED, HIGH);
//     }
//     delay(1000);
// }


#include <Arduino.h>
#include <HTTPClient.h>
#include <WiFi.h>

#define SENSORPIN 34
#define LEDPIN 25

const char* ssid = "hotspot";
const char* password = "passwordhotspot";
const char* serverName = "http://iniipv4/pirdas_modul4/cahaya.php";

void setup(){
    Serial.begin(9600);
    pinMode(LEDPIN, OUTPUT);
    delay(1000);

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED){
        delay(1000);
        Serial.println("Connecting to WiFI...");
    }

    String wifiName = WiFi.SSID();
    String localWifiIp = WiFi.localIP().toString();
    Serial.println();
    Serial.println("Connected to: " + wifiName);
    Serial.println("Local IP WIFI: " + localWifiIp);
}

void loop(){
    int ldr_value = analogRead(SENSORPIN);

    if (ldr_value > 100){
        Serial.println("=== Cahaya Terang ===");
        digitalWrite(LEDPIN, LOW);
        Serial.print("Intensitas Cahaya: ");
        Serial.print(ldr_value);
        Serial.println();
    } else{
        Serial.println("=== Cahaya Gelap ===");
        digitalWrite(LEDPIN, HIGH);
        Serial.print("Intensitas Cahaya: ");
        Serial.print(ldr_value);
        Serial.println();
    }
    delay(1000);

    String url = serverName;
    url += "?ldr_value=";
    url += String(ldr_value);
 
    HTTPClient http;
    http.begin(url);
    int httpResponseCode = http.GET();

    if (httpResponseCode == 200){
        Serial.println("Date send successfully!");
    } else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
    }
    http.end();
    delay(5000);
}
