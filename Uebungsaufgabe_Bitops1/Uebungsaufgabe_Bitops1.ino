uint16_t newColor(uint8_t r, uint8_t g, uint8_t b) 
{
  return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
}


void setup() {
  
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
