void setup() {
  Serial.begin(9600);
  Serial.print("\tBraun\tHuwald\n\tWildfeuer\tDemirbas\tAkin\tPantele\n");
  char a[] = "a";
  char b[] = "ä";
  Serial.println(sizeof(a));
  Serial.println(sizeof(b));

  float c = 0.5;
  float d = -7.0;
  Serial.println(c);
  Serial.println(d/0.0);
  Serial.println(sqrt(-1.0));
}

void loop() {

}
