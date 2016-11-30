#include <Arduino.h>
#include <LiquidCrystal.h>


void Startbildschirm(){

  //Erzeuge lcd Objekt mit angeschlossenen Pins
  //https://www.arduino.cc/en/Reference/LiquidCrystalConstructor
  LiquidCrystal lcd(12,11,5,4,3,2);
  //#define Webseite "super-physik.de"
  char *Webseite = "super-physik.de";

  //Definition der Displaygröße
  lcd.begin(16, 2);
  //Cursorposition festlegen, hier oben links
  lcd.setCursor(0, 0);
  //AUsgabe auf den Bildschirm
  lcd.print(Webseite);
  //Verzögerung
  delay(2000);

  //Animation
  int Position = 0;
  int StringElement = 0;

  for(; Position <= 15; Position++){
    lcd.setCursor(Position, 0);
    lcd.print(" ");
    lcd.setCursor(Position, 1);
    if(Webseite[StringElement] != '\0'){
      lcd.print(Webseite[StringElement]);
    }
    else{
      break;
    }
    StringElement++;
    delay(100);
  }
  delay(2000);

  //Positioniere den Cursor in die Mitte
  lcd.setCursor(6, 0);
  lcd.print(";-)");
  delay(2500);
  //LCD bereinigen
  lcd.clear();

}

void setup(){

  Startbildschirm();

}

void loop(){
  //Serial.print("RS232 Verbindung steht");


}
