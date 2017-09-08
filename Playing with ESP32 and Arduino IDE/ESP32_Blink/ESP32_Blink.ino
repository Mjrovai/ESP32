/*
  ESP 32 Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
  The ESP32 has an internal blue LED at D2 (GPIO 02)
  
*/

int LED_BUILTIN = 2;

void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() 
{
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}


