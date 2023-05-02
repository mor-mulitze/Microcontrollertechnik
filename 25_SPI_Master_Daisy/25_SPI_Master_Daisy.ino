void setup()
{
  Serial.begin(9600);

  char buffer[11];

  // Setze MOSI (PB3), SCK (PB5), SS (PB2) als Ausgang, alles andere als Eingang
  DDRB = (1<<PB3) | (1<<PB5) | (1<<PB2);
  // SPI-Master freigeben, Taktfrequenz = fck/16
  SPCR = (1<<SPE) | (1<<MSTR) | (1<<SPR0);

  PORTB &= ~(1 << PB2); // enable Slave Select

  // Starte Daten-Senden
  SPDR = 'A';
  // Warte bis Senden fertig
  while (!(SPSR & (1<<SPIF)));

  SPDR = 'B';
  while (!(SPSR & (1<<SPIF)));
 
  SPDR = 'C';
  while (!(SPSR & (1<<SPIF)));
  buffer[0] = SPDR;

  PORTB |= (1 << PB2); // disable Slave Select

  buffer[1] = '\0';
  Serial.println(buffer);
}

void loop()
{
}
