#include <SPI.h>

volatile int i = 0;
byte myArray[2];

void setup()
{
  Serial.begin(9600);
  pinMode(SS, INPUT_PULLUP);
  pinMode(MOSI, INPUT);
  pinMode(MISO, OUTPUT);
  pinMode(SCK, INPUT);
  SPCR |= _BV(SPE);
  SPI.attachInterrupt();  //allows SPI interrupt
}

void loop(void)
{
  if (i == 2)
  {
    Serial.print("Slave:  Master schickte mir: 0x");
    Serial.print(myArray[0], HEX);
    Serial.print(" und 0x");
    Serial.println(myArray[1], HEX);
    i=0;
  }
}

ISR (SPI_STC_vect)   //Interrupt routine function
{
  myArray[i] = SPDR;
  i++;
}

