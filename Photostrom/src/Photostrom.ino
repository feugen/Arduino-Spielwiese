#include <Arduino.h>
#include <LiquidCrystal.h>

//LCD Pins festlegen
LiquidCrystal lcd(12,11,5,4,3,2);
int Widerstand;

void setup(){

  //LCD Größe definieren
  lcd.begin(16, 2);

}

void loop(){

  Widerstand = analogRead(0);
  lcd.setCursor(0, 1);
  lcd.print("Photostrom: ");
  lcd.print(Widerstand);
  lcd.setCursor(15,1);
  delay(250);
  lcd.clear();

}
