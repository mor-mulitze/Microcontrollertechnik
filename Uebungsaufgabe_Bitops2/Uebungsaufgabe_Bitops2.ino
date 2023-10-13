void setup() {
  Serial.begin(9600);

  uint8_t x;
  uint16_t y;
  uint32_t z;

  Serial.print("Aufgabe 1: ");
  Serial.println((uint8_t) 47, HEX);

  Serial.print("Aufgabe 2: ");
  Serial.println((uint16_t) 0xffea, DEC);

  Serial.print("Aufgabe 3: ");
  x = 0xff;
  Serial.println(x, DEC);

  Serial.print("Aufgabe 4: ");
  y = 0xffff;
  Serial.println(y, DEC);

  Serial.print("Aufgabe 5: ");
  z = 0xffffffff;
  Serial.println(z, DEC);

  Serial.print("Aufgabe 6: ");
  Serial.println(sizeof(float));

  Serial.print("Aufgabe 7: ");
  Serial.println(sizeof(double));

  Serial.print("Aufgabe 8: ");
  Serial.println((uint8_t) 0xfa, BIN);
  Serial.println((uint8_t) (~0xfa), BIN);

  Serial.print("Aufgabe 9: ");
  Serial.println((uint8_t) 69, BIN);
  Serial.println((uint8_t) (~69), BIN);

  Serial.print("Aufgabe 10: ");
  Serial.println((uint8_t) (~69 + 1), BIN);
  Serial.println((uint8_t) (-69), BIN);

  Serial.print("Aufgabe 11: ");
  Serial.println((uint8_t) (~69 + 1), BIN);
  Serial.println((uint8_t) (~69 + 1), DEC);
  Serial.println((int8_t) (~69 + 1), DEC);

  Serial.print("Aufgabe 12.1: ");
  DDRD = 0b10101010;
  DDRD = DDRD & ~((1 << PD2) | (1 << PD3));
  Serial.println(DDRD, BIN);
  
  Serial.print("Aufgabe 12.2: ");
  Serial.println(PD2);
  Serial.println(PD3);
  Serial.println((uint8_t) ~((1 << PD2) | (1 << PD3)), BIN);


  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
