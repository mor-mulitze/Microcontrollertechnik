void setup() {
  char ascii = '\xF8';
  char text[] = "Südtirol"; //C
  char *dahoam = "Bayern";
/*  char[] text1 = "Suedtirol";//java */
  Serial.begin(9600);
  Serial.print("Ascii: ");
  Serial.println(ascii);
  Serial.print("Ascii Code: ");
  Serial.println((uint8_t) ascii);

  Serial.print("Text: ");
  Serial.println(text);
  Serial.print("Text: ");
  dahoam[6] = '#';
  Serial.println(dahoam);
  Serial.print("7tes Zeichen dahoam: ");
  Serial.println((uint8_t) dahoam[6]);
  Serial.print("3tes Zeichen text: ");
  Serial.println(text[2]);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
