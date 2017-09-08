/**************************************************************
 * Local Time Stamp with ESP32
 * Developed by Marcelo Rovai - 8 September 2017
 **************************************************************/
#include <NTPClient.h>
#include <WiFi.h>
#include <WiFiUdp.h>

#define NTP_OFFSET  -3  * 60 * 60 // In seconds
#define NTP_INTERVAL 60 * 1000    // In miliseconds
#define NTP_ADDRESS  "europe.pool.ntp.org"

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, NTP_ADDRESS, NTP_OFFSET, NTP_INTERVAL);

void setup()
{
  Serial.begin(115200);
  timeClient.begin();
}

void loop() 
{
  timeClient.update();
  String formattedTime = timeClient.getFormattedTime();
  Serial.println(formattedTime);
  delay(1000);
}
