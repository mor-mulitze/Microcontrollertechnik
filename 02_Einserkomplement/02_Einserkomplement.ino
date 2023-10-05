void setup() {
  uint8_t a = 0b01100111;
  Serial.begin(9600);
  Serial.print("Zahl:\t\t\t\t");
  Serial.println((uint8_t)a, BIN);
  Serial.print("Einserkomplement:\t\t");
  Serial.println((uint8_t)~a, BIN);
  Serial.print("Zahl + Einserkomplement:\t");
  Serial.println((uint8_t)(a+(~a)), BIN);
  Serial.print("Zahl + Zweierkomplement:\t");
  Serial.println((uint8_t)(a+(~a+1)), BIN);

  Serial.print("\nZahl dezimal:\t");
  Serial.println(a, DEC);
  Serial.print("Zweikomplement dezimal:\t");
  Serial.println((~a+1), DEC);

  for (int8_t i = 0; i < 129; ++i)
  {
    Serial.println("Hallo Welt!");
  }


  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
