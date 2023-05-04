uint8_t f(uint8_t x) {
  x = x+100;
  return x;
}

void setup() {
  Serial.begin(9600);

  uint8_t a = f(3);
  Serial.println(a);
}

void loop() {
}
