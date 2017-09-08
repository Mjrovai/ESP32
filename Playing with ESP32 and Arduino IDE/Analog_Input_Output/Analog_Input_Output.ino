/***************************************************** 
* ESP32 Analog Input/Output Test 
* Analog Input: ADC_1_0 pin ==> GPIO36 (VP).
* PWM LED pin   ==> GPIO 02
* 
* MJRoBot.org 6Sept17
*****************************************************/
//Analog Input
#define ANALOG_PIN_0 36
int analog_value = 0;

// PMW LED
#define LED_PIN 2
int freq = 5000;
int ledChannel = 0;
int resolution = 8;
int dutyCycle = 0;

void setup()
{
  Serial.begin(115200);
  delay(1000); // give me time to bring up serial monitor
  Serial.println("ESP32 Analog IN/OUT Test");

  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(LED_PIN, ledChannel);
  ledcWrite(ledChannel, dutyCycle);
}

void loop()
{
  analog_value = analogRead(ANALOG_PIN_0);
  Serial.println(analog_value);
  dutyCycle = map(analog_value, 0, 4095, 0, 255);
  ledcWrite(ledChannel, dutyCycle);
  delay(500);
}
