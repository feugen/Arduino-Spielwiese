#ifndef _ARDUINOBIBEF_H_
#define _ARDUINOBIBEF_H_
#include <Arduino.h>
#include <LiquidCrystal.h>
#include "dht11.h"

//LCD
extern void ArduinoBibEF_LCD_Animation(LiquidCrystal *lcd, char const *Text = "super-physik.de");
extern int ArduinoBibEF_LCD_Initialisierung(LiquidCrystal *lcd);

//Temperatursensor
extern void ArduinoBibEF_TempSensorDHT11_LCD_Fehlerabfrage(LiquidCrystal *lcd, dht11 *dht11);
extern void ArduinoBibEF_TempSensorDHT11_LCD(LiquidCrystal *lcd, dht11 *DHT11, const uint32_t &verzoegerung_ms = 250, const uint8_t &zeile_Temp = 0, uint8_t zeile_Feuchte = 1, const char *temperaturText = "Temp: ", const char *feuchteText = "Feuchte: ", const bool &temperatur = true, const bool &feuchte = true);
extern void ArduinoBibEF_TempSensorDHT11_Serial(dht11 *dht11, const char *temperaturText = "Temp: ", const char *feuchteText = "Feuchte: ", unsigned long baudRate = 9600, const bool &temperatur = true, const bool &feuchte = true);
extern float ArduinoBibEF_TempSensorDHT11(dht11 *dht11, const bool &feuchte = false, const bool &temperatur = true);

//Photostrom
extern void ArduinoBibEF_Photostrom_LCD(LiquidCrystal *lcd, uint8_t Zeile = 1, const uint8_t &analogPin = 0, const uint32_t &verzoegerung_ms = 250, const char *text = "Photostrom: ");
extern void ArduinoBibEF_Photostrom_Serial(const uint8_t &analogPin, const uint32_t &verzoegerung_ms, unsigned long &baudRate = 9600);
extern int ArduinoBibEF_Photostrom(const uint8_t &analogPin = 0, const uint32_t &verzoegerung_ms = 250);


#endif
