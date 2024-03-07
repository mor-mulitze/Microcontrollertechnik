#include <avr/power.h>

void setup()
{
  Serial.begin(9600);
  // Setze MISO (PB4) als Ausgang, alles andere als Eingang
  DDRB = (1<<PB4);
  // SPI freigeben
  SPCR = (1<<SPE);
  power_timer0_disable(); //keine Interrupts, sonst gibt es teilweise Übertragungsfehler
}

void loop()
{
  char buffer[11];

  // Warte bis Empfang fertig
  SPDR = 'a';
  while (!(SPSR & (1<<SPIF)));
  // Lese empfangenes Datenbyte
  buffer[0] = SPDR;

  SPDR = 'b';
  while (!(SPSR & (1<<SPIF)));
  buffer[1] = SPDR;

  SPDR = 'c';
  while (!(SPSR & (1<<SPIF)));
  buffer[2] = SPDR;

  SPDR = 'd';
  while (!(SPSR & (1<<SPIF)));
  buffer[3] = SPDR;

  SPDR = 'e';
  while (!(SPSR & (1<<SPIF)));
  buffer[4] = SPDR;

  SPDR = 'f';
  while (!(SPSR & (1<<SPIF)));
  buffer[5] = SPDR;

  SPDR = 'g';
  while (!(SPSR & (1<<SPIF)));
  buffer[6] = SPDR;

  SPDR = 'h';
  while (!(SPSR & (1<<SPIF)));
  buffer[7] = SPDR;

  SPDR = 'i';
  while (!(SPSR & (1<<SPIF)));
  buffer[8] = SPDR;

  SPDR = 'j';
  while (!(SPSR & (1<<SPIF)));
  buffer[9] = SPDR;

  buffer[10] = '\0';
  Serial.println(buffer);
}
