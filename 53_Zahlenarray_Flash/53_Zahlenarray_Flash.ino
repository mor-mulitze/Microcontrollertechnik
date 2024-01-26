#include <avr/pgmspace.h>


void setup() {
  const uint16_t zahlen[] = {0, 1, 10, 100, 1000, 10000};
  static const PROGMEM uint16_t zahlen_flash[] = {0, 1, 10, 100, 1000, 10000};  //dies muss unbedingt eine globale oder eine static Variable sein!

  Serial.begin(9600);

 
  Serial.print("Bytegröße des Arrays: ");
  Serial.println(sizeof(zahlen));

  for(uint8_t i = 0; i < sizeof(zahlen)/sizeof(zahlen[0]); i++) {
    Serial.print(i+1);
    Serial.print(".te Zahl:\t\t");     //zahlen      ist das Selbe wie    &zahlen[0]  
    Serial.println(*(zahlen + i));     //zahlen[i]   ist das Selbe wie    *(zahlen + i) 
    Serial.print(i+1);
    Serial.print(".te Flash-Zahl:\t");                
    Serial.println(pgm_read_word(zahlen_flash + i)); 
  }
}

void loop() {
}
