void setup()
{
  Serial.begin(9600);
  // Setze MISO (PB4) als Ausgang, alles andere als Eingang
  DDRB = (1<<PB4);
  // SPI freigeben
  SPCR = (1<<SPE);
 
}

void loop()
{
  char buffer[11];

  // Warte bis Empfang fertig
  while (!(SPSR & (1<<SPIF)));
  // Lese empfangenes Datenbyte
  buffer[0] = SPDR;

  while (!(SPSR & (1<<SPIF)));
  buffer[1] = SPDR;

  while (!(SPSR & (1<<SPIF)));
  buffer[2] = SPDR;

  while (!(SPSR & (1<<SPIF)));
  buffer[3] = SPDR;

  while (!(SPSR & (1<<SPIF)));
  buffer[4] = SPDR;

  while (!(SPSR & (1<<SPIF)));
  buffer[5] = SPDR;

  while (!(SPSR & (1<<SPIF)));
  buffer[6] = SPDR;

  while (!(SPSR & (1<<SPIF)));
  buffer[7] = SPDR;

  while (!(SPSR & (1<<SPIF)));
  buffer[8] = SPDR;

  while (!(SPSR & (1<<SPIF)));
  buffer[9] = SPDR;

  buffer[10] = '\0';
  Serial.println(buffer);
}
