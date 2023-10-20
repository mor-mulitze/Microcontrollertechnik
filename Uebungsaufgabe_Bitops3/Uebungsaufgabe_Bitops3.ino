#define SEPP 0x5e

void setup() {

  uint8_t sepp;

  // -----------------
  // |7|6|5|4|3|2|1|0|
  // -----------------
  //1.) 0-tes Bit setzen
  //2.) 6-tes Bit setzen
  //3.) 5-tes und 4-tes Bit setzen

  //4.) 0-tes Bit löschen
  //5.) 6-tes Bit löschen
  //6.) 5-tes und 4-tes Bit löschen

  //7.) 0-tes Bit umschalten
  //8.) 6-tes Bit umschalten
  //9.) 5-tes und 4-tes Bit umschalten


  Serial.begin(38400);

  sepp = SEPP;
  Serial.println("Aufgabe 1: ");
  Serial.print("Alter Wert: ");
  Serial.println(sepp, BIN);
  sepp |= (1<<0); //sepp |= 0b00000001; // kurz für   sepp = sepp | 0b00000001;
  Serial.print("Neuer Wert: ");
  Serial.println(sepp, BIN);


  sepp = SEPP;
  Serial.println("Aufgabe 2: ");
  Serial.print("Alter Wert: ");
  Serial.println(sepp, BIN);
  sepp |= (1<<6); //sepp |= 0b01000000; // kurz für   sepp = sepp | 0b00000001;
  Serial.print("Neuer Wert: ");
  Serial.println(sepp, BIN);

  sepp = SEPP;
  Serial.println("Aufgabe 3: ");
  Serial.print("Alter Wert: ");
  Serial.println(sepp, BIN);
  sepp |= (1<<5) + (1<<4);   //sepp |= 0b00110000; // kurz für   sepp = sepp | 0b00000001;
  Serial.print("Neuer Wert: ");
  Serial.println(sepp, BIN);


  sepp = SEPP;
  Serial.println("Aufgabe 4: ");
  Serial.print("Alter Wert: ");
  Serial.println(sepp, BIN);
  sepp &= ~0b00000001; // kurz für   sepp = sepp | 0b00000001;
  Serial.print("Neuer Wert: ");
  Serial.println(sepp, BIN);

  sepp = SEPP;
  Serial.println("Aufgabe 5: ");
  Serial.print("Alter Wert: ");
  Serial.println(sepp, BIN);
  sepp &= ~0b01000000; // kurz für   sepp = sepp | 0b00000001;
  Serial.print("Neuer Wert: ");
  Serial.println(sepp, BIN);

  sepp = SEPP;
  Serial.println("Aufgabe 6: ");
  Serial.print("Alter Wert: ");
  Serial.println(sepp, BIN);
  sepp &= ~0b00110000; // kurz für   sepp = sepp | 0b00000001;
  Serial.print("Neuer Wert: ");
  Serial.println(sepp, BIN);

  sepp = SEPP;
  Serial.println("Aufgabe 7: ");
  Serial.print("Alter Wert: ");
  Serial.println(sepp, BIN);
  sepp ^= 0b00000001; // kurz für   sepp = sepp | 0b00000001;
  Serial.print("Neuer Wert: ");
  Serial.println(sepp, BIN);

  sepp = SEPP;
  Serial.println("Aufgabe 8: ");
  Serial.print("Alter Wert: ");
  Serial.println(sepp, BIN);
  sepp ^= 0b01000000; // kurz für   sepp = sepp | 0b00000001;
  Serial.print("Neuer Wert: ");
  Serial.println(sepp, BIN);

  sepp = SEPP;
  Serial.println("Aufgabe 9: ");
  Serial.print("Alter Wert: ");
  Serial.println(sepp, BIN);
  sepp ^= 0b00110000; // kurz für   sepp = sepp | 0b00000001;
  Serial.print("Neuer Wert: ");
  Serial.println(sepp, BIN);
}

void loop() {
  // put your main code here, to run repeatedly:

}
