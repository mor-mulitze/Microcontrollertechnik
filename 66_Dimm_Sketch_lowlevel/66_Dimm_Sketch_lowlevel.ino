/*
Linienrichter B:
Register: OCR2B = 10;
ISR für OCR2B
*/

ISR(TIMER2_OVF_vect) {
  PORTB = (1 << PB5);  // turn on PB5
}

ISR(TIMER2_COMPB_vect) {
  PORTB = 0x00;  // turn off PB5
}

void setup() {
  TCCR2A = 0x00;                                     // Wave Form Generation Mode 0: Normal Mode; OC2A disconnected
  OCR2B = 1;
  TCCR2B = (1 << CS22) + (1 << CS21) + (1 << CS20);  // prescaler = 1024
  TIMSK2 = (1 << TOIE2) + (1 << OCIE2B);                             // interrupt when TCNT2 is overflowed
  DDRB |= (1 << PB5);                                // Portmanipulation: replaces pinMode(13, OUTPUT);
}

void loop() {
  OCR2B = analogRead(A0) >> 2;
  delay(100);
  // do something else
}
