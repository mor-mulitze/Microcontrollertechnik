#include <SPI.h>

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
  myArray[0] = SPI.transfer(highByte(x));
  myArray[1] = SPI.transfer(lowByte(x));

  Serial.print("Master:  Slave schickte mir: 0x");
  Serial.print(myArray[0], HEX);
  Serial.print(" und 0x");
  Serial.println(myArray[1], HEX);

  //-----------------------
  delay(3000);  //test interval
}
