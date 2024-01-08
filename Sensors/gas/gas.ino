const int LED = D2;             // Warning output
const int GAS_ANALOG = A0;      // Analog signal
const int GAS_DIGITAL = D4;     // Digital signal

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(GAS_ANALOG, INPUT);
  pinMode(GAS_DIGITAL, INPUT);
}

void loop() {
  int gasSensorAnalog = analogRead(GAS_ANALOG);
  int gasSensorDigital = digitalRead(GAS_DIGITAL);

  Serial.print("Gas sensor: ");
  Serial.print(gasSensorAnalog);
  Serial.print("\t");
  Serial.print(gasSensorDigital);
  Serial.print("\t");
  Serial.print("\t");

  if(gasSensorAnalog > 500) {
    Serial.println("Gas!");
    digitalWrite(LED, HIGH);      // blinking
    delay(1000);
    digitalWrite(LED, LOW);
  } else {
    Serial.println("No gas!");
  }
  delay(100);
}
