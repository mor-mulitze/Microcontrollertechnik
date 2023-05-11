uint16_t newColor(uint8_t r, uint8_t g, uint8_t b) 
{
  return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
}


void setup() {
  Serial.begin(9600);
  uint16_t a = newColor(0, 0, 0);
  Serial.println(a, BIN);

  uint16_t b = newColor(255, 0, 0);
  Serial.println(b, BIN);

  Serial.println(0xF8, BIN);

  uint16_t c = newColor(0, 255, 0);
  Serial.println(c, BIN);

  
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
