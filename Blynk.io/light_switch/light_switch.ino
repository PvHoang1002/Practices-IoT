#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL6esfxMUoR"
#define BLYNK_TEMPLATE_NAME "Light"
#define BLYNK_AUTH_TOKEN "X766T9gA7bpGe31Jre6J-fQKDK0-o4Eb"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Phòng máy 401";
char pass[] = "UET@#VNU";

int lightSensor = 0;

BlynkTimer timer; 

void myTimer() 
{
  // This function describes what will happen with each timer tick
  // e.g. writing sensor value to datastream V2
  Blynk.virtualWrite(V2, lightSensor);  
}

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000, myTimer); 
}

BLYNK_WRITE(V1) // Executes when the value of virtual pin 0 changes
{
  if(param.asInt() == 1)
  {
    // execute this code if the switch widget is now ON
    digitalWrite(2,LOW);  // Set digital pin 2 HIGH
    lightSensor = 1;
  }
  else
  {
    // execute this code if the switch widget is now OFF
    digitalWrite(2,HIGH);  // Set digital pin 2 LOW    
    lightSensor = 0;
  }
}

void loop()
{
  Blynk.run();
  timer.run();
}
