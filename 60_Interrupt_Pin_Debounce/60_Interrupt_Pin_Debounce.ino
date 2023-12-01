const uint8_t interruptPin = 3;
const uint8_t ledPin = 13;

void toggleLed()
{
  digitalWrite(ledPin, !digitalRead(ledPin));
}


void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), toggleLed, FALLING);
}

void loop() {
}
