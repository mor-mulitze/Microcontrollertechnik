const uint8_t led = 13;
const uint8_t intervall = 100;
uint8_t       startZeit = millis();

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  Serial.print("\n\nStart Zeit\tAktuelle Zeit\n");
}

void loop()
{
  uint8_t aktuelleZeit = millis();

  Serial.print(startZeit);
  Serial.print("\t\t");
  Serial.println(aktuelleZeit);

  if ((uint8_t)(aktuelleZeit - startZeit) >= intervall )
  {
    digitalWrite(led, !digitalRead(led));
    startZeit = aktuelleZeit;
  }
}
