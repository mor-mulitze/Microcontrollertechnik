void setup() {
  char a = '~';
  Serial.begin(9600);

/*
  Serial.println(a);
  Serial.println((uint8_t) a);
  Serial.println((uint8_t) a, HEX);
*/

  char b[] = ":)";
  char c[] = "Essen";
  int16_t d = 17;
  int16_t e = 26;
  Serial.println(b);
  Serial.println(c);
  Serial.println((uint8_t) b[3]);
  Serial.println((uint8_t) c[6]);
  //Adresse von b und c
  Serial.println((uint16_t) &b);
  Serial.println((uint16_t) &c);
  Serial.println((uint16_t) &d);
  Serial.println((uint16_t) &e);
  
}

void loop() {
}
