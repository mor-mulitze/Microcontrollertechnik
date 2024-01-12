//const uint8_t pin = 3;

void setup() {
  DDRD |= (1 << PD3);
  cli();
//  pinMode(pin, OUTPUT);
//  noInterrupts();
}

void loop() {
  PORTD ^= (1 << PD3);      //T = 870ns
//  digitalWrite(pin, HIGH);
//  digitalWrite(pin, LOW);  //T = 9.7us = 9700ns
}
