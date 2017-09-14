/*****************************************************
 * Simplified 128 X 32 SSD1306 Test
 * The MIT License (MIT)
 * Copyright (c) 2016 by Daniel Eichhorn
 * Original fonts included in library:
 *   ArialMT_Plain_10
 *   ArialMT_Plain_16
 *   ArialMT_Plain_24
 * 
 * Adapted by MJRoBot.org 12Sept17
 *****************************************************/
 
/* modified font created at http://oleddisplay.squix.ch/ */
#include "modified_font.h"

/*  SSD1306 */
#include "SSD1306.h" 
#define SDA_PIN 21// GPIO21 -> SDA
#define SCL_PIN 22// GPIO22 -> SCL
#define SSD_ADDRESS 0x3c

SSD1306  display(SSD_ADDRESS, SDA_PIN, SCL_PIN);

void setup() 
{
  Serial.begin(115200);
  Serial.println();
  Serial.println();

  display.init();

  display.flipScreenVertically();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(Open_Sans_Condensed_Light_20); // set a font
}

void hello_World() 
{
  display.drawString(0, 0,  "*** hello world ***");
  display.drawString(0, 32, "      mjrobot.org");
}


void loop() 
{
  display.clear();   // clear the display
  hello_World();
  display.display();   // write the buffer to the display
  delay(10);
}
