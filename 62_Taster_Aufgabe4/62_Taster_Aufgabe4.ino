#include <avr/io.h>
#include <avr/interrupt.h>

const uint8_t ledPin = 8;
const uint8_t interruptPin0 = 2;
const uint8_t interruptPin1 = 3;
volatile bool state = false;


ISR(INT0_vect)
{
  if (digitalRead(interruptPin0) == HIGH) state = false;
  else /** interruptPin0 == LOW */ state = true;
}

ISR(INT1_vect)
{
  if (digitalRead(interruptPin1) == HIGH) state = false;
  else /** interruptPin0 == LOW */ state = true;
}

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin0, INPUT_PULLUP); //INPUT_PULLUP heißt: mit einem internen 10kOhm Wiedersstand mit 5V verbunden. D.h im unbeschaltenten Zustand: HIGH
  pinMode(interruptPin1, INPUT_PULLUP); //INPUT_PULLUP heißt: mit einem internen 10kOhm Wiedersstand mit 5V verbunden. D.h im unbeschaltenten Zustand: HIGH
  cli();
  EICRA = (1<<ISC10) | (1<<ISC00);	// Interrupt INT0 wird bei jeder Flanke ausgelöst (siehe EICRA Register im Datenblatt) 
  EIMSK = (1<<INT1)  | (1<<INT0);  // Interrupt INT0 setzen
  sei();
}

void loop() {
  static uint16_t cnt = 0;
  ++cnt;
  Serial.println(cnt);
  digitalWrite(ledPin, state);
}
