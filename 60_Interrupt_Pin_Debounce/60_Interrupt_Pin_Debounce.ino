const uint8_t interruptPin = 3;
const uint8_t ledPin = 13;
const unsigned long totzeit = 100; //0.01 Sekunden
volatile unsigned long lastedge = 0;


void toggleLed()
{
  unsigned long now = millis();
//  Serial.println("ISR");
//  Serial.flush();
  
  if (now - lastedge > totzeit)
  {
    digitalWrite(ledPin, !digitalRead(ledPin));
    lastedge = now;
  }
}


void setup()
{
//  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), toggleLed, FALLING);
}

void loop() {
}
