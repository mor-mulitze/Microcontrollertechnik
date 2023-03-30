void setup() {
  cli();
  TCCR2A = 0;                                     
  TCCR2B = 0;

  TIMSK2 = 0;
  OCR2A  = 255;
  OCR2B  = 51;
  TCNT2 = 0;

  DDRD |= (1 << PD3);   

  TCCR2A = (1 << COM2B1) + (1 << WGM20);                                     
  TCCR2B = (1 << WGM22) + (1 << CS22) + (1 << CS21) + (1 << CS20);  

  sei();
}

void loop() {
}
