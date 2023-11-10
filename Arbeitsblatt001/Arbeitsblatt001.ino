void mal16()
{

}

void setup() {
  uint16_t a = 0xa35c;

  Serial.begin(9600);
  Serial.println("1.1");
  Serial.println(a, BIN);

  Serial.println("1.2");
  Serial.println((uint16_t) a);

  Serial.println("1.3");
  Serial.println((int16_t) a);

  Serial.println("1.4");
  Serial.println(a >> 13, BIN);

  Serial.println("1.5");
  Serial.println(0x000f & a, BIN);

  Serial.println("1.6");
  Serial.println(~a, BIN);

  Serial.println("1.7");
  Serial.println(0x0ff0 & a, BIN);

  Serial.println("1.8");
  Serial.println(0x00ff | a, BIN);

  Serial.println("1.9");
  Serial.println(0x8000 ^ a, BIN);

  char* b;

  Serial.println("2.1");
  Serial.println(sizeof(a));
  Serial.println(sizeof(b));

  Serial.println("2.2");
  Serial.println(*b);
  
  Serial.println("2.3");
  Serial.println((uint8_t) &a, HEX);
  Serial.println((uint8_t) &b, HEX);

  Serial.println("2.4");
  b = (char *) &a;
  Serial.println(*b);

  Serial.println("2.5");
}


void loop() {
}
