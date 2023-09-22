void setup() {
  Serial.begin(9600);
  uint8_t x = 0xff+1;
  Serial.print("Dezimalzahl: ");
  Serial.println(x);
  Serial.print("Hexadezimalzahl: ");
  Serial.println(x, HEX);
  Serial.print("Binärzahl: ");
  Serial.println(x, BIN);

  Serial.println("int8\tuint8\tHEX\tBIN");
  for (uint16_t i = 0; i < 256; ++i)
  {
    Serial.print((int8_t) i);
    Serial.print("\t");
    Serial.print(i);
    Serial.print("\t");
    Serial.print(i, HEX);
    Serial.print("\t");
    Serial.println(i, BIN);
  }
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
