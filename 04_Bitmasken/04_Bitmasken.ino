void setup() {
  Serial.begin(9600);

  uint8_t zahl     = 0b11111100;
  uint8_t bitmaske = 0b00010000;

  Serial.println(zahl & bitmaske, BIN);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
