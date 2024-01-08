#define RED_LED D1
#define YELLOW_LED D2
#define GREEN_LED D4

int currentState = 0;
unsigned long previousMillis = 0;
const long redLightDuration = 5000;
const long yellowLightDuration = 3000;
const long greenLightDuration = 6000;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pins as outputs.
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  unsigned long currentMillis = millis();

  switch (currentState) {
    case 0:
      // Red light for 5 seconds
      digitalWrite(RED_LED, HIGH);
      digitalWrite(YELLOW_LED, LOW);
      digitalWrite(GREEN_LED, LOW);

      if (currentMillis - previousMillis >= redLightDuration) {
        currentState = 1;
        previousMillis = currentMillis;
      }
      break;

    case 1:
      // Yellow light for 3 seconds
      digitalWrite(RED_LED, LOW);
      digitalWrite(YELLOW_LED, HIGH);
      digitalWrite(GREEN_LED, LOW);

      if (currentMillis - previousMillis >= yellowLightDuration) {
        currentState = 2;
        previousMillis = currentMillis;
      }
      break;

    case 2:
      // Green light for 6 seconds
      digitalWrite(RED_LED, LOW);
      digitalWrite(YELLOW_LED, LOW);
      digitalWrite(GREEN_LED, HIGH);

      if (currentMillis - previousMillis >= greenLightDuration) {
        currentState = 0;
        previousMillis = currentMillis;
      }
      break;
  }
}
