#ifndef _ARDUINOBIBEF_H_
#define _ARDUINOBIBEF_H_
#include <Arduino.h>
#include <LiquidCrystal.h>
#include "dht11.h"

//LCD
extern void ArduinoBibEF_LCD_Animation(LiquidCrystal *lcd, char const *Text = "super-physik.de");
extern int ArduinoBibEF_LCD_Initialisierung(LiquidCrystal *lcd);

//Temperatursensor
extern void ArduinoBibEF_TempSensorDHT11_LCD_Fehlerabfrage(LiquidCrystal *lcd, dht11 *DHT11);
extern void ArduinoBibEF_TempSensorDHT11_LCD(LiquidCrystal *lcd, dht11 *DHT11, uint32_t Verzoegerung_ms = 250, uint8_t Zeile_Temp = 0, uint8_t Zeile_Feuchte = 1, const char *TemperaturText = "Temp: ", const char *FeuchteText = "Feuchte: ", bool Temperatur = true, bool Feuchte = true);
extern void ArduinoBibEF_TempSensorDHT11_Serial(dht11 *DHT11, const char *TemperaturText = "Temp: ", const char *FeuchteText = "Feuchte: ", unsigned long BaudRate = 9600, bool Temperatur = true, bool Feuchte = true);
extern float ArduinoBibEF_TempSensorDHT11(dht11 *DHT11, bool Feuchte = false, bool Temperatur = true);

//Photostrom
extern void ArduinoBibEF_Photostrom_LCD(LiquidCrystal *lcd, uint8_t Zeile = 1, uint8_t AnalogPin = 0, uint32_t Verzoegerung_ms = 250, const char *Text = "Photostrom: ");
extern void ArduinoBibEF_Photostrom_Serial(uint8_t AnalogPin, uint32_t Verzoegerung_ms, unsigned long BaudRate = 9600);
extern int ArduinoBibEF_Photostrom(uint8_t AnalogPin = 0, uint32_t Verzoegerung_ms = 250);


#endif
