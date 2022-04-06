//I.I.S. Edoardo Amaldi, Liceo Scientifico 
//sketch "semaforo" per la lezione "Introduzione ad Arduino"
//by Alfonso Maria Giorgini 

//ASSOCIO IL PIN AL NOME DEL COLORE DEL LED
int led_rosso = 5;
int led_giallo = 6;
int led_verde = 7;

void setup() {
  //definisco se il pin è output oppure input
  pinMode(led_rosso, OUTPUT);
  pinMode(led_giallo, OUTPUT);
  pinMode(led_verde, OUTPUT);
}

void loop() {
  digitalWrite(led_rosso, HIGH);
  delay(5000);
  digitalWrite(led_rosso, LOW);
  digitalWrite(led_verde, HIGH);
  delay(4000);
  digitalWrite(led_verde, LOW);
  digitalWrite(led_giallo, HIGH);
  delay(3000);
  digitalWrite(led_giallo, LOW);

}
