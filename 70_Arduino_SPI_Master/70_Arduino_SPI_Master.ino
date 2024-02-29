#include<SPI.h>

unsigned short x = 0x1234;
byte myArray[2];

void setup()
{
  Serial.begin(9600);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV128); //bit rate = 16 MHz/128 = 125 kbit/sec
  digitalWrite(SS, LOW);   //Slave is selected
}

void loop()
{
  SPI.transfer(highByte(x));
  myArray[0] = SPDR;
  SPI.transfer(lowByte(x));
  myArray[1] = SPDR;

  Serial.print("Master:  Slave schickte mir: ");
  Serial.print(myArray[0], HEX);
  Serial.print(" und ");
  Serial.println(myArray[1], HEX);

  //-----------------------
  delay(3000);  //test interval
}
