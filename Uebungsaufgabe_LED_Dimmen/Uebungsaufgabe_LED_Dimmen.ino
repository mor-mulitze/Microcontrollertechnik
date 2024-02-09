/**
 Eigentlich 257 Zeitscheiben aber mit
 COM2B1 = 1; COM2B0 = 0; können nur 1-257 Zeitscheiben gesteuert werden
 COM2B1 = 1; COM2B0 = 1; können nur 0-256 Zeitscheiben gesteuert werden

 Deshalb ist OCR2B = 64 nicht genau 25% Duty-Cycle sondern:
 (64+1)/257 = 25.2918%
 mit OCR2B = 63 wären wir etwas näher an den 25%:
 (63+1)/257 = 24.9027%
*/


void setup()
{
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  cli();
  TCCR2A = (1 << COM2B1) | (1 << WGM21) | (1 << WGM20);    // <------- Mode: Fast PWM Mode 3; Ausgabe auf OC2B-Pin 
  TCCR2B = (1 <<   CS22) | (1 <<  CS21) | (1 <<  CS20);    // <------- Prescaler: 1024
  OCR2B = 64;                                              //OCR2B = 0.25*256 = 64

  sei();

/*
  TCCR2A // COM2B1 = 1; COM2B0 = 0; WGM21 = 1; WGM20 = 1;
  TCCR2B // WGM22 = 0; CS22 = 1; CS21 = 1; CS20 = 1;
*/
}

void loop()
{
}
