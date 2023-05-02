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
  buffer[0] = SPDR; //zwar ist dieses Byte nicht für diesen Slave bestimmt, ABER erst durch diesen lesenden Zugriff wird SPIF wieder gelöscht!

  while (!(SPSR & (1<<SPIF)));
  buffer[0] = SPDR; //zwar ist dieses Byte nicht für diesen Slave bestimmt, ABER erst durch diesen lesenden Zugriff wird SPIF wieder gelöscht!

  while (!(SPSR & (1<<SPIF)));
  buffer[0] = SPDR; //Daisy-Chain Länge und Nachrichten-Länge ist drei => das ist unser Byte!
                    //Alternative: weitermachen bis SS(PB2) wieder high ist

  buffer[1] = '\0';
  Serial.println(buffer);
}
