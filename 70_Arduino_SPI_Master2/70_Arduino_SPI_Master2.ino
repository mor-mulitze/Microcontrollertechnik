#include <SPI.h>


uint8_t send[16] = {'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e', 'F', 'f', 'G', 'g', 'H', 'h'};
uint8_t receive[16];
uint8_t slaveSelectPin = 9;

void setup()
{
  pinMode(slaveSelectPin, OUTPUT);
  digitalWrite(slaveSelectPin, HIGH);   //Slave is selected
  Serial.begin(9600);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV64); //bit rate = 16 MHz/128 = 125 kbit/sec
}

void loop()
{
  digitalWrite(slaveSelectPin, LOW);   //Slave is selected
  for (uint8_t i = 0; i < sizeof(send); ++i)
  {
    receive[i] = SPI.transfer(send[i]);
  }
  digitalWrite(slaveSelectPin, HIGH);   //Slave is selected

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
