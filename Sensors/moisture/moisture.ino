const int LED = D1;             // Warning output
const int ANALOG_SIG = A0;      // Analog signal
const int DIGITAL_SIG = D2;     // Digital signal

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(ANALOG_SIG, INPUT);
  pinMode(DIGITAL_SIG, INPUT);
}

void loop() {
  // Read analog value of soil moisture and convert to percent
  // Read ten times and then takes the average of real value
  int real_value = 0;
  for(int i = 0; i < 9; i++) {
    real_value += analogRead(ANALOG_SIG);
  }
  int value = real_value / 10;

  // Mapping the real analog value (getting by experiments) to percent 0-100
  int percent = map(value, 500, 1023, 0, 100);

  // By default, 100% means dry, 0% means wet. This command to reverse it
  percent = 100 - percent;

  Serial.print("Level of soil moisture (in percent): ");
  Serial.print(percent);
  Serial.print("%");
  Serial.print('\n');

  // Read digital value of soil moisture
  int moistureDigital = digitalRead(DIGITAL_SIG);

  // Turn on LED if detecting moisture
  if(moistureDigital == 0) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}
