// // Kegiatan 1
#define LIGHT_SENSOR_PIN 15 // ESP32 pin GIOP36 (ADC0)
#define LED_PIN 14

void setup() {
  Serial.begin(9600);
  pinMode (LED_PIN, OUTPUT);
}

void loop() {
  int analogValue = analogRead(LIGHT_SENSOR_PIN);

  int inverse = 4095 - analogValue;

  Serial.print("Analog Value = ");
  Serial.print(inverse);

  if (inverse < 500) {
    Serial.println(" => Dark");
    digitalWrite(LED_PIN, LOW);
  } else if (inverse > 500 && inverse < 1000) {
    Serial.println(" => Dim");
    digitalWrite(LED_PIN, 120);
  } else {
    Serial.println(" => Brigth");
    digitalWrite(LED_PIN, HIGH);
  } 
}

#define LIGHT_SENSOR_PIN  15  // ESP32 pin GPIO36 (ADC0) connected to light sensor
#define BUZZER_PIN        14 // ESP32 pin GPIO22 connected to LED
#define ANALOG_THRESHOLD  500

void setup() {
  // initialize serial communication
  Serial.begin(9600);
  // initialize the ESP32's pin as an input
  pinMode(LIGHT_SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT); // set ESP32 pin to output mode
}

void loop() {
  int analogValue = analogRead(LIGHT_SENSOR_PIN); // read the value on the analog pin

  if (analogValue < ANALOG_THRESHOLD) {
    Serial.println("There is light, i can see it.."); 
    digitalWrite(BUZZER_PIN, LOW);  // turn off LED
  }
  else {
    Serial.println("It is dark AF");
    digitalWrite(BUZZER_PIN, HIGH);  // turn on LED
  }
}