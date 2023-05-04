void setup() {
  TCCR2A = (1 << WGM21) + (1 << COM2A0);               // Wave Form Generation Mode 2: CTC, OC2A disconnected
  TCCR2B = (1 << CS22) + (1 << CS21) + (1 << CS20);  // prescaler = 1024
  OCR2A = 124;
  DDRB |= (1 << PB3);   //pinMode(11, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
}
