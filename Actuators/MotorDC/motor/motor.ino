const int pwmMotorA = D1;
const int dirMotorA = D3;

// const int pwmMotorB = D2;
// const int dirMotorB = D4;
int motorSpeed = 100;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();
  pinMode(pwmMotorA, OUTPUT);
  pinMode(dirMotorA, OUTPUT);
  Serial.println("Motor Shield 12E Initialized");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Activate A");
  analogWrite(pwmMotorA, motorSpeed);
  digitalWrite(dirMotorA, LOW);
  delay(4500);
  Serial.println("Reverse A");
  digitalWrite(dirMotorA, HIGH);
  delay(4500);
  Serial.println("Stop A");
  analogWrite(pwmMotorA, 0);
  digitalWrite(dirMotorA, LOW);
  delay(2000);
}
