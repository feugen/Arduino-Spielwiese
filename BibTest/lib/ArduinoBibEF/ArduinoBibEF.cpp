#include <Arduino.h>
#include <LiquidCrystal.h>

#include "ArduinoBibEF.h"
#include "dht11.h"


/**
****************************************
 *LCD Funktionen
****************************************
**/

int ArduinoBibEF_LCD_Initialisierung(LiquidCrystal *lcd){

  //https://www.arduino.cc/en/Reference/LiquidCrystalConstructor
  //Man braucht ein Pointer auf das LCD Objekt

  lcd->begin(16,2);
  lcd->setCursor(0, 0);
  return 0;

}

//Startbildschirm mit Animation
void ArduinoBibEF_LCD_Animation(LiquidCrystal *lcd, char const *Text){

  lcd->clear();
  //Cursorposition festlegen, hier oben links
  lcd->setCursor(0, 0);
  //Ausgabe auf den Bildschirm
  lcd->print(Text);
  //Verzögerung
  delay(2000);

  //Animation
  int Position = 0;
  int StringElement = 0;

  for(; Position <= 15; Position++){
    lcd->setCursor(Position,0);
    lcd->print(" ");
    lcd->setCursor(Position, 1);
    if(Text[StringElement] != '\0'){
      lcd->print(Text[StringElement]);
    }
    else{
      break;
    }
    StringElement++;
    delay(100);
  }
  delay(2000);

  //Positioniere den Cursor in die Mitte
  lcd->setCursor(6, 0);
  lcd->print(";-)");
  delay(2500);

}

/**
****************************************
 *Temperaturfunktionen für DHT11 Sensor
****************************************
**/

void ArduinoBibEF_TempSensorDHT11_LCD_Fehlerabfrage(LiquidCrystal *lcd, dht11 *DHT11){

  lcd->setCursor(15,1);
  lcd->clear();
  lcd->setCursor(0,0);
  lcd->print("Fehlerausgabe:");
  lcd->setCursor(0,1);
  int lesen = DHT11->read(9);
  lcd->print(lesen);
  delay(2000);

}

void ArduinoBibEF_TempSensorDHT11_LCD(LiquidCrystal *lcd, dht11 *DHT11, uint32_t Verzoegerung_ms, uint8_t Zeile_Temp, uint8_t Zeile_Feuchte, const char *TemperaturText, const char *FeuchteText, bool Temperatur, bool Feuchte){

  lcd->setCursor(15,1);
  lcd->clear();
  if(Temperatur == true){
    lcd->setCursor(0,Zeile_Temp);
    lcd->print(TemperaturText);
    lcd->print((float)DHT11->temperature);
  }
  if(Feuchte == true){
    lcd->setCursor(0,Zeile_Feuchte);
    lcd->print(FeuchteText);
    lcd->print((float)DHT11->humidity);
  }
  lcd->setCursor(15,1);
  delay(Verzoegerung_ms);

}

void ArduinoBibEF_TempSensorDHT11_Serial(dht11 *DHT11, const char *TemperaturText, const char *FeuchteText, unsigned long BaudRate, bool Temperatur, bool Feuchte){

  Serial.begin(BaudRate);
  if(Temperatur == true){
    Serial.print(TemperaturText);
    Serial.print((float)DHT11->temperature);
  }
  if(Feuchte == true){
    Serial.print(FeuchteText);
    Serial.print((float)DHT11->humidity);
  }
  Serial.end();

}

float ArduinoBibEF_TempSensorDHT11(dht11 *DHT11, bool Feuchte, bool Temperatur){

  //Entweder Temp oder Feuchte ausgeben
  float Messwert = 0;
  if(Feuchte == true){
    Messwert = DHT11->humidity;
  }
  if(Temperatur == true){
    Messwert = DHT11->temperature;
  }
  return Messwert;

}

/**
****************************************
 *Photostromfunktionen für KY-018 Sensor
****************************************
**/

//Photowiderstand auf LCD ausgeben
void ArduinoBibEF_Photostrom_LCD(LiquidCrystal *lcd, uint8_t Zeile, uint8_t AnalogPin, uint32_t Verzoegerung_ms, const char *Text){

  lcd->setCursor(15,1);
  lcd->clear();
  int Photostrom = analogRead(AnalogPin);
  lcd->setCursor(0,Zeile);
  lcd->print(Text);
  lcd->print(Photostrom);
  delay(Verzoegerung_ms);

}

//Photowiderstand auf serielle Schnittstelle ausgeben
void ArduinoBibEF_Photostrom_Serial(uint8_t AnalogPin, uint32_t Verzoegerung_ms, unsigned long BaudRate){

  int Photostrom = analogRead(AnalogPin);
  delay(Verzoegerung_ms);
  Serial.begin(BaudRate);
  Serial.print(Photostrom);
  Serial.end();

}

//Photowiderstand
int ArduinoBibEF_Photostrom(uint8_t AnalogPin, uint32_t Verzoegerung_ms){

  int Photostrom = analogRead(AnalogPin);
  delay(Verzoegerung_ms);
  return Photostrom;

}
