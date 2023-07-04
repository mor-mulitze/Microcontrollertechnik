void verdoppeln(double* x)
{
  (*x) = (*x) * 2;
}

void setup() {
  Serial.begin(9600);
  double y = 5.0;
  verdoppeln(&y);
  Serial.println(y);
}

void loop() { 
}
