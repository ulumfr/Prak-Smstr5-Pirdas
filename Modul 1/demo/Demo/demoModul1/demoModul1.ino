const int switchPin = 15;
const int ledPin = 14;

int switchState = 0;

void setup() {
  Serial.begin(115200);
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  switchState = digitalRead(switchPin);

  if(switchState == HIGH){
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);
  }
}

