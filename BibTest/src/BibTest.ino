#include <Arduino.h>
#include <LiquidCrystal.h>

#include "ArduinoBibEF.h"
#include "dht11.h"

LiquidCrystal lcd(12,11,5,4,3,2);
dht11 DHT11_Sensor;


void setup(){
  ArduinoBibEF_LCD_Initialisierung(&lcd);
  ArduinoBibEF_LCD_Animation(&lcd);
  ArduinoBibEF_TempSensorDHT11_LCD_Fehlerabfrage(&lcd, &DHT11_Sensor);

}

void loop(){
  ArduinoBibEF_TempSensorDHT11_LCD(&lcd, &DHT11_Sensor);
  delay(2000);
  ArduinoBibEF_Photostrom_LCD(&lcd);
  delay(2000);

}
