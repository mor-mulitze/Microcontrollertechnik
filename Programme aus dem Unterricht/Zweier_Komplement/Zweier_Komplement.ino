void setup() {
  uint8_t stellung = 129;
  uint8_t handarbeit = ~stellung + 1;

  Serial.begin(9600);
  Serial.print("Zahl: ");
  Serial.println(stellung, BIN);
  Serial.print("Zahl + Zweierkomplement: ");
  Serial.println((uint8_t)(stellung + handarbeit));
  Serial.print("Zweierkomplement: ");
  Serial.println(handarbeit, BIN);
  Serial.print("Zweierkomplement (unsigned): ");
  Serial.println((uint8_t) handarbeit);
  Serial.print("Zweierkomplement (signed): ");
  Serial.println((int8_t) handarbeit);


  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}
