const int RELAY = D1;

void setup() {
  Serial.begin(115200);
  Serial.println();
  pinMode(RELAY, OUTPUT);
  Serial.println("Motor Shield 12E Initialized");
  delay(5000);
}

void loop() {
  Serial.println("Turn on light!");
  digitalWrite(RELAY, HIGH); // if using Normally Open then send LOW signal to light up
  delay(4500);
  Serial.println("Turn off light!"); // if using Normally Open then send HIGH signal to light down
  digitalWrite(RELAY, LOW);
  delay(4500);
}
