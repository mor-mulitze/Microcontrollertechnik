//1.) Zählen von 0 bis 65535 und Ausgabe
//2.) Timer2 in den Normal Mode und Prescaler = 128

volatile bool flag = false;

ISR(TIMER2_OVF_vect)
{
  static uint16_t i = 0;
  if (i == 2451) {
    i = 0;
    flag = true;
  }
  i++;
}


void setup()
{
  Serial.begin(9600);
  cli();
  TCCR2A = 0;                              // <------- Mode: Normal
  TCCR2B = (1 <<  CS22) | (1 << CS20);     // <------- Prescaler: 128
  TIMSK2 = (1 << TOIE2);                   // <------- Interrupt wird bei Timer Überlauf ausgelöst
  sei();

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
  if (flag) {
    Serial.println("Game Over!!!");
    flag = false;
  }
//  Serial.print("TCNT2 - Register: "); // <------
//  uint8_t a = TCNT2;                  // <------
//  Serial.println(a);                  // <------
}
