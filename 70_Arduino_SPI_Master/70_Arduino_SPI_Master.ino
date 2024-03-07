#include <SPI.h>

uint16_t x = 0xabcd;
uint8_t  myArray[2];

void setup()
{
  Serial.begin(9600);
  SPI.begin();
//  SPI.setDataMode(SPI_MODE3);
  SPI.setClockDivider(SPI_CLOCK_DIV128); //bit rate = 16 MHz/128 = 125 kbit/sec
  digitalWrite(SS, LOW);   //Slave is selected
}

void loop()
{
  digitalWrite(SS, LOW);   //Slave is selected
  myArray[0] = SPI.transfer(highByte(x));
  myArray[1] = SPI.transfer(lowByte(x));
  digitalWrite(SS, HIGH);   //Slave is deselected


  Serial.print("Master:  Slave schickte mir: 0x");
  Serial.print(myArray[0], HEX);
  Serial.print(" und 0x");
  Serial.println(myArray[1], HEX);

  //-----------------------
  delay(30);  //test interval
}
