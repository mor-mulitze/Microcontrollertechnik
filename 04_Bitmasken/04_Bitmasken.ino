void setup()
{
  Serial.begin(9600);

  uint8_t zahl     = 0b11111100;
  uint8_t bitmaske = 0b00010000;

  Serial.println(zahl & bitmaske, BIN);
 }

void loop()
{
}
