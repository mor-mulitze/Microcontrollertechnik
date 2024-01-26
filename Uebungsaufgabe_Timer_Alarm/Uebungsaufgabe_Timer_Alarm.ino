//1.) Zählen von 0 bis 65535 und Ausgabe
//2.) Timer2 in den Normal Mode und Prescaler = 128

void setup()
{
  Serial.begin(9600);
  TCCR2A = 0;                              // <-------
  TCCR2B = (1 << CS22) | (1 << CS20);      // <-------
/*
         0000 0100
    +    0000 0001
------------------
         0000 0101
*/

/*
  TCCR2A // WGM21 = 0; WGM20 = 0;
  TCCR2B // WGM22 = 0; CS22 = 1; CS21 = 0; CS20 = 1;
*/
}

void loop()
{
  static uint16_t vielArbeit = 0;
  vielArbeit++;
  Serial.print("Main Loop Arbeit: ");
  Serial.println(vielArbeit);
  Serial.print("TCNT2 - Register: "); // <------
  uint8_t a = TCNT2;                  // <------
  Serial.println(a);                  // <------
}
