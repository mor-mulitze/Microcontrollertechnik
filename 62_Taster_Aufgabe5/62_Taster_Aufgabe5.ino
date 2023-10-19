#include <avr/io.h>
#include <avr/interrupt.h>

const uint8_t ledPin = 8;
const uint8_t interruptPin0 = 2;
const uint8_t interruptPin1 = 3;
volatile bool state = false;


ISR(INT0_vect)
{
  state = !state;
}

ISR(INT1_vect)
{
  state = !state;
}

void setup() {
  Serial.begin(9600);
  DDRB = DDRB | (1 << PB0); //pinMode(ledPin, OUTPUT);
  DDRD = DDRD & ~(1 << PD2); //pinMode(interruptPin0, INPUT_PULLUP);
  DDRD = DDRD & ~(1 << PD3); //pinMode(interruptPin1, INPUT_PULLUP);

  PORTD = (1 << PD2) | (1 << PD3);
  
  cli();
  EICRA = (1<<ISC11) | (1<<ISC10) | (1<<ISC01) | (1<<ISC00);	// Interrupt INT0 wird bei jeder Flanke ausgelöst (siehe EICRA Register im Datenblatt) 
  EIMSK = (1<<INT1)  | (1<<INT0);  // Interrupt INT0 setzen
  sei();
}

void loop() {
  static uint16_t cnt = 0;
  ++cnt;
  Serial.println(cnt);

  if (state == true) PORTB = (1 << PB0); //  digitalWrite(ledPin, state);
  else PORTB = 0;
}
