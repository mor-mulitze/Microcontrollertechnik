#include <SPI.h>
#include <avr/power.h>
#include <avr/sleep.h>


volatile uint8_t i = 0;
uint8_t send[16] = {'H', 'o', 'l', 'l', 'y', ' ', 'F', 'u', 'c', 'k', ' ', '!', '!', '?', '!', '?'};
uint8_t receive[16];

void setup()
{
  Serial.begin(9600);
  pinMode(SS, INPUT_PULLUP);
  pinMode(MOSI, INPUT);
  pinMode(MISO, OUTPUT);
  pinMode(SCK, INPUT);
  SPCR |= (1 << SPE);
  SPI.attachInterrupt();  //allows SPI interrupt
  power_timer0_disable(); 
//  set_sleep_mode (SLEEP_MODE_IDLE);
}

void loop(void)
{
  if (i == 16)
  {
    Serial.print("Slave:  Master schickte mir:");
    for (uint8_t j = 0; j < sizeof(receive); ++j)
    {
      Serial.print(" ");
      Serial.print((char) receive[j]);
    }
    Serial.print("\n");
    i=0;
  }
}

ISR (SPI_STC_vect)   //Interrupt routine function
{
  SPDR = send[i]; // Beachte die Reihenfolge!! SPDR lesend != SPDR schreibend
  receive[i] = SPDR;
  i++;
}

