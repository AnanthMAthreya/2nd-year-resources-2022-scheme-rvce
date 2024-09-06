#include <DHT.h>
#define DHTTYPE DHT11
#define DHT_PIN 4 
#define LED_LOW_PIN  5
#define LED_MED_PIN 12 
#define LED_HIGH_PIN 2 

DHT dht(DHT_PIN, DHTTYPE);

void setup() 
{
  pinMode(LED_LOW_PIN, OUTPUT);
  pinMode(LED_MED_PIN, OUTPUT);
  pinMode(LED_HIGH_PIN, OUTPUT);
  dht.begin();
}

void loop() 
{
  float temperature = dht.readTemperature();

  if (temperature < 20) 
  {
    digitalWrite(LED_LOW_PIN, HIGH);
    digitalWrite(LED_MED_PIN, LOW);
    digitalWrite(LED_HIGH_PIN, LOW);
  } 

  else if (temperature < 30) 
  {
    digitalWrite(LED_LOW_PIN, LOW);
    digitalWrite(LED_MED_PIN, HIGH);
    digitalWrite(LED_HIGH_PIN, LOW);
  } 

  else 
  {
    digitalWrite(LED_LOW_PIN, LOW);
    digitalWrite(LED_MED_PIN, LOW);
    digitalWrite(LED_HIGH_PIN, HIGH);
  }
}
