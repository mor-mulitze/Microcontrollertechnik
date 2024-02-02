const uint8_t interruptPin = 3;
const uint8_t ledPin = 13;
const unsigned long totzeit = 100; //0.1 Sekunden
volatile unsigned long lastedge = 0;

#define DEBUG

void toggleLed()
{
  unsigned long now = millis();

#ifdef DEBUG
  static uint8_t anschlag = 0;
  Serial.print("ISR: ");
  Serial.println(anschlag);
  Serial.flush();
  anschlag += 1;     //anschlag = anschlag + 1;
#endif

  if (now - lastedge > totzeit)
  {
    digitalWrite(ledPin, !digitalRead(ledPin));
    lastedge = now;
  }
}


void setup()
{

#ifdef DEBUG
  Serial.begin(9600);
#endif

  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(interruptPin), toggleLed, CHANGE);
}

void loop() {
}
