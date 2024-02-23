/**
 Eigentlich 257 Zeitscheiben aber mit
 COM2B1 = 1; COM2B0 = 0; können nur 1-256 Zeitscheiben gesteuert werden (OCR2B = 0...255)
 COM2B1 = 1; COM2B0 = 1; können nur 0-255 Zeitscheiben gesteuert werden (OCR2B = 255...0)

 Deshalb ist OCR2B = 64 nicht genau 25% Duty-Cycle sondern:
 (64+1)/257 = 25.29182879%
 mit OCR2B = 63 wären wir besser an den 25%:
 (63+1)/257 = 24.90272374%
*/


void setup()
{
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  const uint16_t x = 64; //x = 0...256
  cli();
  if (x < 128)
  {
    //inverting mode: gut für dunkel
    TCCR2A = (1 << COM2B1) | (1 << COM2B0) | (1 << WGM21) | (1 << WGM20);    // <------- Mode: Fast PWM Mode 3; Ausgabe auf OC2B-Pin 
    TCCR2B = (1 <<   CS22) | (1 <<   CS21) | (1 <<  CS20);                   // <------- Prescaler: 1024
    OCR2B = 255 - x;                                                              //OCR2B = 0.25*256 = 64
  } else {
    //non-inverting mode: gut für hell
    TCCR2A = (1 << COM2B1) | (1 << WGM21) | (1 << WGM20);    // <------- Mode: Fast PWM Mode 3; Ausgabe auf OC2B-Pin 
    TCCR2B = (1 <<   CS22) | (1 <<  CS21) | (1 <<  CS20);                   // <------- Prescaler: 1024
    OCR2B = x-1;
  }                                                              //OCR2B = 0.25*256 = 64

  sei();

/*
  TCCR2A // COM2B1 = 1; COM2B0 = 0; WGM21 = 1; WGM20 = 1;
  TCCR2B // WGM22 = 0; CS22 = 1; CS21 = 1; CS20 = 1;
*/
}

void loop()
{
}
