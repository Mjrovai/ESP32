/***************************************************** 
* ESP32 Touch Test and LED Ctrl
* Touch pin ==> Touch0 is T0 which is on GPIO 4 (D4).
* LED pin   ==> D2
* 
* MJRoBot.org 6Sept17
*****************************************************/

#define TOUTCH_PIN T0 // ESP32 Pin D4
#define LED_PIN 2
int touch_value = 100;

void setup()
{
  Serial.begin(115200);
  delay(1000); // give me time to bring up serial monitor
  Serial.println("ESP32 Touch Test");
  pinMode(LED_PIN, OUTPUT);
  digitalWrite (LED_PIN, LOW);
}

void loop()
{
  touch_value = touchRead(TOUTCH_PIN);
  Serial.println(touch_value);  // get value using T0 
  if (touch_value < 50)
  {
    digitalWrite (LED_PIN, HIGH);
  }
  else
  {
    digitalWrite (LED_PIN, LOW);
  }
  
  delay(1000);
}
