/***************************************************** 
* ESP32 DHT Reading 
* DHT Input: ==> GPIO23.
* 
* MJRoBot.org 9Sept17
*****************************************************/

/* DHT */
#include "DHT.h"
#define DHTPIN 23  
#define DHTTYPE DHT22 
DHT dht(DHTPIN, DHTTYPE);
float localHum = 0;
float localTemp = 0;

void setup()
{
  Serial.begin(115200);
  delay(1000); // give me time to bring up serial monitor
  Serial.println("");
  Serial.println("ESP32 DHT Temperature and Humidity ");
  Serial.println("");
  dht.begin();
}

void loop()
{
  getDHT();
  Serial.print("Temp: ==> ");
  Serial.print(localTemp);
  Serial.print("  Hum ==> ");
  Serial.println(localHum);
  delay(2000);
}

/***************************************************
* Get indoor Temp/Hum data
****************************************************/
void getDHT()
{
  float tempIni = localTemp;
  float humIni = localHum;
  localTemp = dht.readTemperature();
  localHum = dht.readHumidity();
  if (isnan(localHum) || isnan(localTemp))   // Check if any reads failed and exit early (to try again).
  {
    localTemp = tempIni;
    localHum = humIni;
    return;
  }
}
