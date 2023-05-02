uint8_t counterStart = 131;  // alternative: 6
uint16_t scaleFactor = 500;  // alternative: 1000

ISR(TIMER2_OVF_vect) {
  static uint16_t counter = 0;
  TCNT2 = counterStart;
  counter++;
  if (counter == scaleFactor) {
    PORTB ^= (1 << PB5);
    counter = 0;
  }
}

void setup() {
  TCCR2A = 0x00;                       // OC2A and OC2B disconnected; Wave Form Generation Mode 0: Normal Mode
  TCCR2B = (1 << CS22) + (1 << CS21);  // prescaler = 256
                                       // TCCR2B = (1<<CS22); // prescaler = 64;
  TIMSK2 = (1 << TOIE2);               // interrupt when TCNT2 is overflowed
  TCNT2 = counterStart;
  DDRB |= (1 << PB5);
}

void loop() {
  // do something else
}

