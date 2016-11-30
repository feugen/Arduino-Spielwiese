#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);
int Loopzaehler;

void setup(){

  //Auf 1 setzten, wir sind Menschen, wir zählen ab 1
  Loopzaehler = 1;
  //Festlegung der Displaygröße
  lcd.begin(16,2);
  //Positionierung des Cursers
  lcd.setCursor(0,0);
  //Ausgabe auf erste Zeile
  lcd.print("super-physik.de");
  //Positionierung des Cursors mittig auf 2. Zeile
  lcd.setCursor(6,1);
  //Ausgabe auf 2. Zeile
  lcd.print(":-)");
  //Cursor ans Ende setzen damit
  //mit "lcd.clear" alles gelöscht wird
  lcd.setCursor(15,1);
  //Verzögere um 5 Sekunden
  delay(5000);
  //Lösche den Bildschirminhalt
  lcd.clear();
}

void loop(){

  //Cursor auf 2. Zeile setzen
  lcd.setCursor(0,1);
  //AUsgabe in 2 Zeilen, da die print funktion nicht mehr hergibt.
  lcd.print("Loopnummer:");
  lcd.print(Loopzaehler);
  //Verzögerung um 50 ms, damit nicht zu schnell gezählt wird.
  delay(50);
  //Wenn der Zähler 999 erreicht hat so fange neu an.
  if(Loopzaehler == 999){
    Loopzaehler = 1;
    lcd.setCursor(15,1);
    lcd.clear();
  }
  else{
    //Falls das Ziel nicht erreicht ist, so zähle hoch
    Loopzaehler++;
  }

}


