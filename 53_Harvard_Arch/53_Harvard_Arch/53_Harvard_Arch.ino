/*
leeres Programm:

Der Sketch verwendet 444 Bytes (1%) des Programmspeicherplatzes. Das Maximum sind 32256 Bytes.
Globale Variablen verwenden 9 Bytes (0%) des dynamischen Speichers, 2039 Bytes für lokale Variablen verbleiben. Das Maximum sind 2048 Bytes.
*/

/*
Serial.begin(9600)

Der Sketch verwendet 1438 Bytes (4%) des Programmspeicherplatzes. Das Maximum sind 32256 Bytes.
Globale Variablen verwenden 184 Bytes (8%) des dynamischen Speichers, 1864 Bytes für lokale Variablen verbleiben. Das Maximum sind 2048 Bytes.
*/

/*
Serial.begin(9600);
Serial.print("123456789");

Der Sketch verwendet 1464 Bytes (4%) des Programmspeicherplatzes. Das Maximum sind 32256 Bytes.
Globale Variablen verwenden 194 Bytes (9%) des dynamischen Speichers, 1854 Bytes für lokale Variablen verbleiben. Das Maximum sind 2048 Bytes.
*/

/*
Serial.begin(9600);
Serial.print(F("123456789"));

Der Sketch verwendet 1476 Bytes (4%) des Programmspeicherplatzes. Das Maximum sind 32256 Bytes.
Globale Variablen verwenden 184 Bytes (8%) des dynamischen Speichers, 1864 Bytes für lokale Variablen verbleiben. Das Maximum sind 2048 Bytes.
*/

void setup() {
  // put your setup code here, to run once:
  PROGMEM const int32_t pin = 11;
  Serial.begin(9600);
  Serial.print(F("123456789"));
  digitalRead(pin);
  Serial.print(pin);

}

void loop() {
  // put your main code here, to run repeatedly:

}
