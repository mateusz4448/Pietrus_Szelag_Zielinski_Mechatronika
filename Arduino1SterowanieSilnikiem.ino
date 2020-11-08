/*Praca na Arduino Mega
  Wyświetlacz HD44780
  Zaimportować bibliotekę Bounce2 z linku https://www.arduinolibraries.info/libraries/bounce2
 */

#include <Bounce2.h>  // Biblioteka dla przycisków eliminująca drganie styków
#include <LiquidCrystal.h>
LiquidCrystal lcd(22, 23, 24, 25, 26, 27);  // Informacja o podłączeniu nowego wyświetlacza

int SW1=28;  // Pin przycisku pierwszego
int SW2=29;  // Pin przycisku drugiego
int SW3=30;  // Pin przycisku trzeciego
int a=0;

// Inicjalizacja obiektu Bounce
Bounce debouncer = Bounce(); 

void setup() {

  // Konfiguracja pinu przycisków :
  pinMode(SW1,INPUT);
  pinMode(SW2,INPUT);
  pinMode(SW3,INPUT);
  // Po konfiguracji przycisków, ustawienie działania funkcji Bounce :
  debouncer.attach(SW1);
  debouncer.attach(SW2);
  debouncer.attach(SW3);
  debouncer.interval(5);  // Interwał jest wyrażony w ms
  // Deklaracja typu wyświetlcza
  lcd.begin(16, 2);  // Deklaracja typu
  // Konfiguracja pinów wychodzących na silnik
  pinMode(31,OUTPUT);  // Zadanie stanu wysokiego na pin 31 będzię obracać silnik w lewą stronę
  pinMode(32,OUTPUT);  // Zadanie stanu wysokiego na pin 32 będzię obracać silnik w prawą stronę
}

void loop() {
  // Aktualizacja funkcji Bounce :
  debouncer.update();

  // Odczyt zaktualizowanej wartości (value) :
  int value = debouncer.read();
  
  //
  a=digitalRead(SW1);
  if (a==HIGH) {
    a++;
    lcd.setCursor(0, 0);  //Ustawienie kursora na początku wyświetlacza
    lcd.print(a);  //Wyświetlenie liczby odpalonych programów
  } 

  //Obrót silnika w lewo
  int b;
  b=digitalRead(SW2);
  if ((a==HIGH) && (b==HIGH)) {
    digitalWrite(31,HIGH);
    digitalWrite(32,LOW);
  }

  //Obrót silnika w prawo
  int c;
  c=digitalRead(SW3);
  if ((a==HIGH) && (c==HIGH)) {
    digitalWrite(31,LOW);
    digitalWrite(32,HIGH);
  }

  //Blokowanie obrotu przy jednoczesnym wciśnięciu SW2 i SW3
  if ((b==HIGH) && (c==HIGH)) {
    digitalWrite(31,LOW);
    digitalWrite(32,LOW);
  }
}
