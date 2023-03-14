#include <avr/io.h>
#include <avr/interrupt.h>

void setup() {
  //Wir machen unseren Atmega328p langsam
  cli();
  CLKPR = 1 << CLKPCE; //jetzt darf der Takt geändert werden 
//  CLKPR = 1 << CLKPS3; //62.5kHz Taktfrequenz
  CLKPR = 0; //16MHz Taktfrequenz
  sei();

  // WGM22/WGM20 all set -> Mode 5, phase correct PWM
  TCCR2A = (1 << COM2B1) | (1 << WGM20);  // Set OC2A at bottom, clear OC2B at compare match
  TCCR2B = (1 << CS22) | (1 << CS21) | (1 << CS20) | (1 << WGM22);    // prescaler = 1024;
  OCR2A = 249;
  OCR2B = 49;
  DDRD |= (1 << PD3);
}

void loop() {}
