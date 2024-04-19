const uint8_t interruptPin = 3;
const uint8_t ledPin = 13;

//#define DEBUG

ISR(INT1_vect)
{
  const uint32_t totzeit = 100; //0.1 Sekunden
  uint32_t now = millis();
  static uint32_t lastedge = 0;

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

  //attachInterrupt(digitalPinToInterrupt(interruptPin), toggleLed, CHANGE);

  cli();
  EICRA |=  (1 << ISC10);
  EICRA &= ~(1 << ISC11);
  EIMSK |=  (1 << INT1);
  sei();
  
}

void loop() {
}
