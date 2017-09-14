/*****************************************************
 * ESP32 DHT Reading, Time Stamping and OLED diplay 
 * DHT Input: ==> GPIO23.
 * 128 X 32 SSD1306  - Library by Daniel Eichhorn
 * 
 * MJRoBot.org 13Sept17
 *****************************************************/

/* WiFi parameters and credentials */
#include <WiFi.h>
const char* ssid     = "YOUR SSID";
const char* password = "your password";

/* Time Stamp */
#include <NTPClient.h>
#include <WiFiUdp.h>

#define NTP_OFFSET  -3  * 60 * 60 // In seconds
#define NTP_INTERVAL 60 * 1000    // In miliseconds
#define NTP_ADDRESS  "0.pool.ntp.org"

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, NTP_ADDRESS, NTP_OFFSET, NTP_INTERVAL);

/* modified font created at http://oleddisplay.squix.ch/ */
#include "modified_font.h"

/*  SSD1306 */
#include "SSD1306.h" 
#define SDA_PIN 21// GPIO21 -> SDA
#define SCL_PIN 22// GPIO22 -> SCL
#define SSD_ADDRESS 0x3c
SSD1306  display(SSD_ADDRESS, SDA_PIN, SCL_PIN);

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
  Serial.println("");
  Serial.println("ESP32 DHT Temp & Humidity with Time Stamp - OLED Display");
  Serial.println("");
  connectWiFi();
  timeClient.begin();
  dht.begin();

  display.init();

  display.flipScreenVertically();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(Open_Sans_Condensed_Light_20); // set a font
}

void loop() 
{
  getDHT();
  timeClient.update();
  displayData();
  delay(2000);
}

/***************************************************
* Get indoor Temp/Hum data
****************************************************/
void getDHT()
{
  localTemp = dht.readTemperature();
  localHum = dht.readHumidity();
  if (isnan(localHum) || isnan(localTemp))   // Check if any reads failed and exit early (to try again).
  {
    return;
  }
}

/***************************************************
* Display Data
****************************************************/
void displayData() 
{
  String formattedTime = timeClient.getFormattedTime();
  Serial.print(formattedTime);
  
  Serial.print("  Temp: ==> ");
  Serial.print(localTemp);
  Serial.print("  Hum ==> ");
  Serial.println(localHum);

  display.clear();   // clear the display
  
  display.setFont(Open_Sans_Condensed_Light_20);
  display.drawString(0, 0,  "t:");
  display.drawString(10, 0,  String(localTemp));
  display.drawString(47, 0,  "oC");
  display.drawString(75, 0, "h:");
  display.drawString(85, 0,  String(localHum));
  display.drawString(120, 0 ,  "%");

  display.setFont(ArialMT_Plain_24);
  display.drawString(20, 31,  String(formattedTime));

  display.display();   // write the buffer to the display
  delay(10);
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
