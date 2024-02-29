#include<SPI.h>

volatile int i = 0;
byte myArray[2];

void setup()
{
  Serial.begin(9600);
  pinMode(SS, INPUT_PULLUP);
  pinMode(MOSI, OUTPUT);
  pinMode(SCK, INPUT);
  SPCR |= _BV(SPE);
  SPI.attachInterrupt();  //allows SPI interrupt
}

void loop(void)
{
  if (i == 2)
  {
    Serial.print("Slave:  Master schickte mir: ");
    Serial.print(myArray[0], HEX);
    Serial.print(" und ");
    Serial.println(myArray[1], HEX);
    i=0;
  }
}

ISR (SPI_STC_vect)   //Interrupt routine function
{
  myArray[i] = SPDR;
  i++;
}

