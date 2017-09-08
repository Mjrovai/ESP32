/***************************************************** 
* ESP32 Analog Input Test 
* Analog Input: ADC_1_0 pin ==> GPIO36 (VP).
* 
* MJRoBot.org 6Sept17
*****************************************************/
//Analog Input
#define ANALOG_PIN_0 36
int analog_value = 0;

void setup()
{
  Serial.begin(115200);
  delay(1000); // give me time to bring up serial monitor
  Serial.println("ESP32 Analog IN Test");
}

void loop()
{
  analog_value = analogRead(ANALOG_PIN_0);
  Serial.println(analog_value);
  delay(500);
}
