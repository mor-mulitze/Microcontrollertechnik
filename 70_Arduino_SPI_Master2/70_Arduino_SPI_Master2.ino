#include <SPI.h>


uint8_t send[16] = {'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e', 'F', 'f', 'G', 'g', 'H', 'h'};
uint8_t receive[16];

void setup()
{
  Serial.begin(9600);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV64); //bit rate = 16 MHz/128 = 125 kbit/sec
  digitalWrite(SS, LOW);   //Slave is selected
}

void loop()
{
  for (uint8_t i = 0; i < sizeof(send); ++i)
  {
    receive[i] = SPI.transfer(send[i]);
  }

  Serial.print("Master:  Slave schickte mir:");
  for (uint8_t j = 0; j < sizeof(receive); ++j)
  {
    Serial.print(" ");
    Serial.print((char) receive[j]);
  }
  Serial.print("\n");
  //-----------------------
  delay(1000);  //test interval
}
