#include <Arduino.h>

#include <LiquidCrystal.h>
#include "dht11.h"

LiquidCrystal lcd(12,11,5,4,3,2);
int Temperatur;
dht11 DHT11;

void setup(){
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("super-physik.de");
  lcd.setCursor(6,1);
  lcd.print(";-)");
  lcd.setCursor(15,1);
  delay(5000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Fehlerausgabe:");
  lcd.setCursor(0,1);
  int lesen = DHT11.read(9);
  lcd.print(lesen);
  delay(2000);
  lcd.setCursor(15,1);
  lcd.clear();
}

void loop(){

  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print((float)DHT11.temperature);
  lcd.setCursor(0,1);
  lcd.print("Feuchte: ");
  lcd.print((float)DHT11.humidity);
  lcd.setCursor(15,1);
  delay(5000);
  lcd.clear();
}
