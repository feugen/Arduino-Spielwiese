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
void ArduinoBibEF_LCD_Animation(LiquidCrystal *lcd, char const *text){

  lcd->clear();
  //Cursorposition festlegen, hier oben links
  lcd->setCursor(0, 0);
  //Ausgabe auf den Bildschirm
  lcd->print(text);
  //Verzögerung
  delay(2000);

  //Animation
  int position = 0;
  int stringElement = 0;

  for(; position <= 15; position++){
    lcd->setCursor(position,0);
    lcd->print(" ");
    lcd->setCursor(position, 1);
    if(text[stringElement] != '\0'){
      lcd->print(text[stringElement]);
    }
    else{
      break;
    }
    stringElement++;
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

void ArduinoBibEF_TempSensorDHT11_LCD_Fehlerabfrage(LiquidCrystal *lcd, dht11 *dht11){

  lcd->setCursor(15,1);
  lcd->clear();
  lcd->setCursor(0,0);
  lcd->print("Fehlerausgabe:");
  lcd->setCursor(0,1);
  int lesen = dht11->read(9);
  lcd->print(lesen);
  delay(2000);

}

void ArduinoBibEF_TempSensorDHT11_LCD(LiquidCrystal *lcd, dht11 *dht11, const uint32_t &verzoegerung_ms, const uint8_t &zeile_Temp, uint8_t zeile_Feuchte, const char *temperaturText, const char *feuchteText, const bool &temperatur, const bool &feuchte){

  lcd->setCursor(15,1);
  lcd->clear();
  if(temperatur == true){
    lcd->setCursor(0,zeile_Temp);
    lcd->print(temperaturText);
    lcd->print((float)dht11->temperature);
  }
  if(feuchte == true){
    lcd->setCursor(0,zeile_Feuchte);
    lcd->print(feuchteText);
    lcd->print((float)dht11->humidity);
  }
  lcd->setCursor(15,1);
  delay(verzoegerung_ms);

}

void ArduinoBibEF_TempSensorDHT11_Serial(dht11 *dht11, const char *temperaturText, const char *feuchteText, unsigned long baudRate, const bool &temperatur, const bool &feuchte){

  Serial.begin(baudRate);
  if(temperatur == true){
    Serial.print(temperaturText);
    Serial.print((float)dht11->temperature);
  }
  if(feuchte == true){
    Serial.print(feuchteText);
    Serial.print((float)dht11->humidity);
  }
  Serial.end();

}

float ArduinoBibEF_TempSensorDHT11(dht11 *dht11, const bool &feuchte, const bool &temperatur){

  //Entweder Temp oder Feuchte ausgeben
  float messwert = 0;
  if(feuchte == true){
    messwert = dht11->humidity;
  }
  if(temperatur == true){
    messwert = dht11->temperature;
  }
  return messwert;

}

/**
****************************************
 *Photostromfunktionen für KY-018 Sensor
****************************************
**/

//Photowiderstand auf LCD ausgeben
void ArduinoBibEF_Photostrom_LCD(LiquidCrystal *lcd, const uint8_t &zeile, const uint8_t &analogPin, const uint32_t &verzoegerung_ms, const char *text){

  lcd->setCursor(15,1);
  lcd->clear();
  int Photostrom = analogRead(analogPin);
  lcd->setCursor(0,zeile);
  lcd->print(text);
  lcd->print(Photostrom);
  delay(verzoegerung_ms);

}

//Photowiderstand auf serielle Schnittstelle ausgeben
void ArduinoBibEF_Photostrom_Serial(const uint8_t &analogPin, const uint32_t &verzoegerung_ms, unsigned long &baudRate){

  int photostrom = analogRead(analogPin);
  delay(verzoegerung_ms);
  Serial.begin(baudRate);
  Serial.print(photostrom);
  Serial.end();

}

//Photowiderstand
int ArduinoBibEF_Photostrom(const uint8_t &analogPin, const uint32_t &verzoegerung_ms){

  int photostrom = analogRead(analogPin);
  delay(verzoegerung_ms);
  return photostrom;

}
