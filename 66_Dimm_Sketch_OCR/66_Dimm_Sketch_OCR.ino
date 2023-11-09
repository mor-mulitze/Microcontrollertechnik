void setup() {
  TCCR2A = (1 << WGM20) | (1 << WGM21) | (1 << COM2B1);            //fast PWM-Mode 
  TCCR2B = (1 << WGM22) | (1 << CS20) | (1 << CS21) | (1 << CS22);
  OCR2A = 255;
  OCR2B = 255;
  DDRD |= (1 << PD3);
}

void loop() {
}
