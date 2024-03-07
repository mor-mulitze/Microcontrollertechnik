#include <SPI.h>
#include <avr/power.h>

volatile uint8_t i = 0;
uint8_t myArray[2];

void setup()
{
  Serial.begin(9600);
//  SPI.setDataMode(SPI_MODE3);
  pinMode(SS,   INPUT);
  pinMode(MOSI, INPUT);
  pinMode(MISO, OUTPUT);
  pinMode(SCK,  INPUT);
  SPCR |= (1 << SPE);
  SPI.attachInterrupt();  //allows SPI interrupt
  power_timer0_disable(); //keine Interrupts, sonst gibt es teilweise Übertragungsfehler
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

