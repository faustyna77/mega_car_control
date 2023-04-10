#include <Arduino.h>
#define pin 5
#define lewy41 41
#define lewy45 45
#define prawy49 49
#define prawy51 51




void setup() {
Serial.begin(9600);
 pinMode(5, OUTPUT); // ustawiamy pin 8 jako wyjście
 pinMode(lewy41,OUTPUT);
 pinMode(lewy45,OUTPUT);
 pinMode(prawy49,OUTPUT);
 pinMode(prawy51,OUTPUT);

 }


void Stop()
{
   digitalWrite(lewy41, LOW);
  digitalWrite(lewy45,LOW);
  digitalWrite(prawy49,LOW);
  digitalWrite(prawy51,LOW);
}
 

 void leftMotor(int V) {
  if (V > 0) { //Jesli predkosc jest wieksza od 0 (dodatnia)
    
    digitalWrite(lewy41, 0); //Kierunek: do przodu
    analogWrite(lewy45, V); //Ustawienie predkosci 
  } else {
    V = abs(V); //Funkcja abs() zwroci wartosc V  bez znaku
   
    digitalWrite(lewy41, 1); //Kierunek: do tyłu
    analogWrite(lewy45, V); //Ustawienie predkosci    
  }
}


void rightMotor(int V) {
  if (V > 0) { //Jesli predkosc jest wieksza od 0 (dodatnia)
   
    digitalWrite(prawy49, 0); //Kierunek: do przodu
    analogWrite(prawy51, V); //Ustawienie predkosci 
  } else {
    V = abs(V); //Funkcja abs() zwroci wartosc V  bez znaku
    
    digitalWrite(prawy49, 1); //Kierunek: do tyłu
    analogWrite(prawy51, V); //Ustawienie predkosci    
  }
}

void Triangle() {
  // Jazda do przodu
   digitalWrite(lewy41, HIGH);
  digitalWrite(lewy45,LOW);
  digitalWrite(prawy49,HIGH);
  digitalWrite(prawy51,LOW);

  delay(1000);

  // Skręcanie w lewo
  analogWrite(lewy41,150);
  digitalWrite(lewy45,LOW);
  digitalWrite(prawy49,LOW);
  analogWrite(prawy51,70);
  delay(500);

  // Jazda do przodu
  analogWrite(lewy41, 50);
  digitalWrite(lewy45,LOW);
  analogWrite(prawy49,70);
  digitalWrite(prawy51,LOW);
  delay(1000);

  // Skręcanie w prawo
  digitalWrite(lewy41, LOW);
   analogWrite(lewy45,50);
  analogWrite(prawy49,70);
  digitalWrite(prawy51,LOW);
  delay(500);

  // Jazda do przodu
  analogWrite(lewy41, 50);
  digitalWrite(lewy45,LOW);
  digitalWrite(prawy49,HIGH);
  digitalWrite(prawy51,LOW);
  delay(1000);
}


void Rounder() {
  // Jazda do przodu
  digitalWrite(lewy41, HIGH);
  digitalWrite(lewy45,LOW);
  digitalWrite(prawy49,HIGH);
  digitalWrite(prawy51,LOW);
  delay(1000);

  // Skręcanie w lewo
  digitalWrite(lewy41, HIGH);
  digitalWrite(lewy45,LOW);
  digitalWrite(prawy49,LOW);
  digitalWrite(prawy51,HIGH);
  delay(1000);

  // Jazda do przodu
  digitalWrite(lewy41, HIGH);
  digitalWrite(lewy45,LOW);
  digitalWrite(prawy49,HIGH);
  digitalWrite(prawy51,LOW);
  delay(1000);

  // Skręcanie w prawo
  digitalWrite(lewy41, LOW);
  digitalWrite(lewy45,HIGH);
  digitalWrite(prawy49,HIGH);
  digitalWrite(prawy51,LOW);
  delay(1000);
}


void Go()
{
  digitalWrite(lewy41, HIGH);
  digitalWrite(lewy45,LOW);
  digitalWrite(prawy49,HIGH);
  digitalWrite(prawy51,LOW);
}

void Right()
{
  digitalWrite(lewy41, LOW);
  digitalWrite(lewy45,HIGH);
  digitalWrite(prawy49,HIGH);
  digitalWrite(prawy51,LOW);
}

void loop() {

 if(Serial.available()>0) //sprawdzamy czy są jakieś bity do odczytania jeśli są to przypisujemy je do zmiennej odczyt typu char.
   {     
      char odczyt= Serial.read(); 
      switch(odczyt) //pętla switch 
      {
        case '1':
         digitalWrite(lewy41, HIGH);
         digitalWrite(lewy45,LOW);
         digitalWrite(prawy49,HIGH);
         digitalWrite(prawy51,LOW);


         break; 
        case '2': 
        digitalWrite(lewy41, LOW);
         digitalWrite(lewy45,HIGH);
         digitalWrite(prawy49,LOW);
         digitalWrite(prawy51,HIGH);
        break; 
        case '3': 
        digitalWrite(lewy41, HIGH);
         digitalWrite(lewy45,LOW);
         digitalWrite(prawy49,LOW);
         digitalWrite(prawy51,HIGH);
        break;
        case '4': 
        digitalWrite(lewy41, LOW);
         digitalWrite(lewy45,HIGH);
         digitalWrite(prawy49,HIGH);
         digitalWrite(prawy51,LOW);
        break;
        case '5': 
        digitalWrite(lewy41, LOW);
         digitalWrite(lewy45,LOW);
         digitalWrite(prawy49,LOW);
         digitalWrite(prawy51,LOW);
        break;

        case '6':
        Triangle();
        Stop();
        break;
        case '7':
        Rounder();
        Stop();
        break;
    case 'c':
     digitalWrite(prawy49,HIGH);
     digitalWrite(prawy51,LOW);
     digitalWrite(lewy41,LOW);
     digitalWrite(lewy45,LOW);
     break;
    case '8':
    for (int i = 0; i < 4; i++) {
    Go(); // Funkcja do poruszania robotem do przodu
    delay(1000); // Opóźnienie, aby robot miał czas na wykonanie ruchu
    Right();
    Stop();
    break;
     }
    case '9':
    leftMotor(-77);
    digitalWrite(prawy49,LOW);
    digitalWrite(prawy51,LOW);
    break;

    

    default : break;
      
      
   }
    Serial.println(odczyt);
   
}
  delay(50);
}

