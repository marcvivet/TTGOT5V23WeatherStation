#include <Arduino.h>

#include "TerminalManager.hpp"
#include "WiFiManager.hpp"
#include "TimeManager.hpp"
#include "OpenWeatherManager.hpp"



void setup() {
  // put your setup code here, to run once:
  TerminalManager& oTM = TerminalManager::getInstance();
  oTM.setAutoFush(true);  
  oTM.println("START Setup");

  WiFiManager::getInstance().connect();
  TimeManager::getInstance();

}

/*  u8g2_for_adafruit_gfx.setFont(u8g2_font_siji_t_6x10);  // icon font
  u8g2_for_adafruit_gfx.setFontMode(1);                 // use u8g2 transparent mode (this is default)
  u8g2_for_adafruit_gfx.drawGlyph(0, 10, 0x0e200);  // Power Supply
  u8g2_for_adafruit_gfx.drawGlyph(12, 10, 0x0e201);  // Charging
  u8g2_for_adafruit_gfx.drawGlyph(24, 10, 0x0e10a);  // Right Arrow
  u8g2_for_adafruit_gfx.drawGlyph(36, 10, 0x0e24b);  // full Battery*/

void loop() {
  TerminalManager& oTM = TerminalManager::getInstance();
  TimeManager& oTimeM = TimeManager::getInstance();
  OpenWeatherManager& oOW = OpenWeatherManager::getInstance();

  oTimeM.printLocalTime();
  oOW.getData();
  // put your main code here, to run repeatedly:
  //oTM.println("loop");
  //delay(1000);
}