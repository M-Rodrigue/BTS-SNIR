#include <LCD16x2.h>
#include <Wire.h>
#define LED 13

LCD16x2 lcd;
char text[16];
volatile int count = 0;

// Timer
ISR(TIMER1_COMPA_vect) {
  count++;
  digitalWrite(LED, digitalRead(LED) ^ 1);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);

  // Wire
  Wire.begin(); // Configure l'I2C utilisé par l'afficheur

  // LCD16x2
  lcd.lcdClear(); //Efface l'afficheur
  lcd.lcdSetBlacklight(100);
  lcd.lcdGoToXY(5, 1);
  lcd.lcdWrite("Bonjour");
  delay(500);
  lcd.lcdGoToXY(5, 2);
  lcd.lcdWrite("Hello");
  delay(500);
  lcd.lcdClear();

  // Timer
  noInterrupts(); // désactive toutes les interruptions
  TCCR1A = 0;     // registre de contrôle du Timer 1
  TCCR1B = 0;     // registre de contrôle du Timer 1
  TCCR1C = 0;     // registre de contrôle du Timer 1
  TCNT1  = 0;     // compteur 16-bits
  // Valeur maximale de comptage de TCNT1 pour comparaison avec OCR1A
  OCR1A = 6250;
  TCCR1B |= (1 << WGM12);       // CTC mode
  //Solution 1 : prescaleur de 256
  TCCR1B |= (1 << CS12);        // divise par 256 (prédiviseur)
  //Solution 2 : prescaleur de 64
  //TCCR1B |= (1<<CS11) | (1<<CS10);
  TIMSK1 |= (1 << OCIE1A);      // active l’interruption du Timer 1
  interrupts();
}

void loop() {
  // put your main code here, to run repeatedly:
  //  digitalWrite(LED, HIGH);
  //  delay(500);
  //  digitalWrite(LED, LOW);
  //  delay(500);

  lcd.lcdGoToXY(3, 1);
  sprintf(text, "CHRONOMETRE");
  lcd.lcdWrite(text);

  lcd.lcdGoToXY(6, 2);
  while (true) {
    //   Chronomètre simple
    sprintf(text, "%d\"%d'", count / 10, count % 10);
    lcd.lcdWrite(text);

    unsigned char btn = lcd.readButtons();
    bool enable = true;
    if ((btn & 1) == 0) {
      lcd.lcdWrite("        ");
      count = 0;
    } else {
      if ((btn & 1 << 3) == 0 ) {
        TIMSK1 &= (0 << OCIE1A); 
      };
    };
  }
}
