/***************************************************** 
* ESP32 Analog Input/Output Test 
* Analog Input: ADC_1_0 pin ==> GPIO36 (VP).
* PWM SERVO pin   ==> GPIO 05
* 
* MJRoBot.org 6Sept17
*****************************************************/
//Analog Input
#define ANALOG_PIN_0 36
int analog_value = 0;

// PMW SERVO
#define SERVO_PIN 5
int freq = 50;
int channel = 0;
int resolution = 8;
int dutyCycle = 21;

void setup()
{
  Serial.begin(115200);
  delay(1000); // give me time to bring up serial monitor
  Serial.println("ESP32 Servo Control");

  ledcSetup(channel, freq, resolution);
  ledcAttachPin(SERVO_PIN, channel);
  ledcWrite(channel, dutyCycle);
}

void loop()
{
  analog_value = analogRead(ANALOG_PIN_0);
  Serial.print(analog_value);
  Serial.print(" Duty Cycle ==> ");
  Serial.println(dutyCycle);
  dutyCycle = map(analog_value, 0, 4095, 10, 33);
  ledcWrite(channel, dutyCycle);
  delay(50);
}
