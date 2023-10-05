#include <avr/io.h>
#include <avr/interrupt.h>

const uint8_t ledPin = 8;
const uint8_t interruptPin0 = 2;
const uint8_t interruptPin1 = 3;
const uint32_t deadTime = 10000;
volatile bool state = false;
volatile uint32_t time = micros();



ISR(INT0_vect)
{
  uint32_t t = micros();
  if (t-time > deadTime)
  {
    state = !state;
    time = t;
  }
}

ISR(INT1_vect)
{
  uint32_t t = micros();
  if (t-time > deadTime)
  {
    state = !state;
    time = t;
  }
}

void setup() {
  Serial.begin(9600);
  DDRB = DDRB | (1 << PB0); //pinMode(ledPin, OUTPUT);
  DDRD = DDRD & ~((1 << PD2) | (1 << PD3)); //pinMode(interruptPin0, INPUT_PULLUP);
  PORTD = (1 << PD2) | (1 << PD3);          //pinMode(interruptPin1, INPUT_PULLUP);
  
  cli();
  EICRA = (1<<ISC11) | (1<<ISC10) | (1<<ISC01) | (1<<ISC00);	// Interrupt INT0 wird bei jeder Flanke ausgelöst (siehe EICRA Register im Datenblatt) 
  EIMSK = (1<<INT1)  | (1<<INT0);  // Interrupt INT0 setzen
  sei();
}

void loop() {
  static uint16_t cnt = 0;
  ++cnt;
  Serial.println(cnt);

  if (state == true) PORTB = PORTB | (1 << PB0); //  digitalWrite(ledPin, state);
  else PORTB = PORTB & ~(1 << PB0);
}
