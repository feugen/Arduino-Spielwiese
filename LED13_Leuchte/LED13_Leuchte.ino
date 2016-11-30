//Globale Variablen deklarieren
int Leuchtintervall;

/**************
 * Startfunktion vorbereiten und ausführen
 **************/

void setup(){

  //Leuchtintervall in ms zuweisen
  Leuchtintervall = 200;
  //Pinmodus 13 auf Ausgang gesetzt
  pinMode(13, OUTPUT); 

}

/**************
 * Schleifenfunktion vorbereiten und ausführen
 **************/

void loop(){

  //Leuchte einschalten
  digitalWrite(13, HIGH);
  //Verzögern  
  delay(Leuchtintervall);
  //Leuchte ausschalten  
  digitalWrite(13, LOW);
  //verzögern  
  delay(Leuchtintervall);  

}

