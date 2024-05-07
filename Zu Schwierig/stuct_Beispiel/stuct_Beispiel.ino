struct coordinate_t
{
  float x;
  float y;
};


void setup() {
  Serial.begin(9600);

  coordinate_t joystick_position;
  coordinate_t ursprung = {0.0, 0.0};

  Serial.print("X - Koordinate von joystick_position: ");
  Serial.println(joystick_position.x);
  Serial.print("X - Koordinate von joystick_position: ");
  Serial.println(joystick_position.y);
  Serial.print("X - Koordinate von ursprung: ");
  Serial.println(ursprung.x);
  Serial.print("X - Koordinate von ursprung: ");
  Serial.println(ursprung.y);

  //gerechnet wird erstmal ganz normal nur mit den einzelnen Elementen bei uns: .x und .y

  ursprung.x = ursprung.x + 3.0;
  ursprung.y = ursprung.y + 5.0;

  Serial.print("X - Koordinate von ursprung: ");
  Serial.println(ursprung.x);
  Serial.print("X - Koordinate von ursprung: ");
  Serial.println(ursprung.y);
}

void loop()
{
}
