#include <SPI.h>


uint8_t send[16] = {'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e', 'F', 'f', 'G', 'g', 'H', 'h'};
uint8_t receive[16];

void setup()
{
  Serial.begin(9600);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV128); //bit rate = 16 MHz/128 = 125 kbit/sec
  for (uint8_t i = 0; i < 16; ++i)
  {
    digitalWrite(SS, LOW);   //Slave is selected
    receive[i] = SPI.transfer(send[i]);
    digitalWrite(SS, HIGH);   //Slave is selected
    delay(1000);
  }

  for (uint8_t i = 0; i < 16; ++i)
  {
    Serial.print("Master:  Slave schickte mir ");
    Serial.print(i);
    Serial.print(". :\t");
    Serial.print(receive[i], HEX);
    Serial.print("\t");
    Serial.print((char)receive[i]);
    Serial.print("\n");
  }
}

void loop()
{
}
