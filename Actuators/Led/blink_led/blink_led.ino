/*
ESP8266 Blink
Blink the blue LED on the ESP8266 module
*/

#define LED D0 //Define blinking LED pin

void setup() {
  pinMode(LED, OUTPUT); // Initialize the LED pin as an output
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED, HIGH); // Turn the LED on (Note that HIGH is the voltage level)
  delay(1000); // Wait for a second
  digitalWrite(LED, LOW); // Turn the LED off by making the voltage LOW
  delay(2000); // Wait for two seconds
}