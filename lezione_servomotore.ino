//I.I.S. Edoardo Amaldi, Liceo Scientifico
//Potenziometro e servomotore
//by Alfonso Maria Giorgini

#define pinServo 8 //assegno un nome al pin
#define pinPotenziometro A1 
#include <Servo.h>

Servo servomotore; //definisco un nome per il servomotore
int LetturaValore = 0; //definisco la variabile che leggerà i valori da 0 a 1023
int n = 0; //n è il numero di cicli, per leggere i valori nel monitor seriale
int angoloDesiderato = 0; //definisco la variabile dell'angolo del servomotore
float LetturainVolt = 0; //definisco la variabile che conterrà i valori in volt

void setup() {
  Serial.begin(9600); //inizializzo e apro il monitor seriale
  servomotore.attach(pinServo); //dico a quale pin è collegato il servomotore
  
}

void loop() {
  n = n + 1; 
  Serial.print("ciclo numero:");
  Serial.print(n);
  Serial.print("  "); //questa parte scriverà il numero ciclo sul monitor seriale
  
  LetturaValore = analogRead(pinPotenziometro); //leggerà dal pin analogico i valori del potenziometro [0;1023]
  LetturainVolt = ((float) LetturaValore)*(5.0/1023.0); //ottengo il valore in volt

  Serial.print("valore potenziometro:");
  Serial.print(LetturainVolt); //scrivo il valore in volt sul monitor seriale
  Serial.print("  ");

  angoloDesiderato = map(LetturaValore, 0, 1023, 0, 180);

  Serial.print("angolo servo motore");
  Serial.println(angoloDesiderato);
  servomotore.write(angoloDesiderato);
}
