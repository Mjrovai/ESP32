/**************************************************************
 * Online Local Time Stamp with ESP32
 * Developed by Marcelo Rovai - 11 October 2017
 **************************************************************/

/* WiFi parameters and credentials */
#include <WiFi.h>
const char* ssid     = "YOUR NETWORK SSID";
const char* password = "YOUR PASSWORD";

/* Time Stamp */
#include <NTPClient.h>
#include <WiFiUdp.h>

#define NTP_OFFSET  -3  * 60 * 60 // In seconds
#define NTP_INTERVAL 60 * 1000    // In miliseconds
#define NTP_ADDRESS  "0.pool.ntp.org"

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, NTP_ADDRESS, NTP_OFFSET, NTP_INTERVAL);

void setup()
{
  Serial.begin(115200);
  connectWiFi();
  timeClient.begin();
}

void loop() 
{
  timeClient.update();
  String formattedTime = timeClient.getFormattedTime();
  Serial.println(formattedTime);
  delay(1000);
}

/***************************************************
* Connecting to a WiFi network
****************************************************/
void connectWiFi(void)
{
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
