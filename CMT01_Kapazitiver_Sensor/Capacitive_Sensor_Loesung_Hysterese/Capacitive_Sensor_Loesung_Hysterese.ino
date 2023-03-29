#include <CapacitiveSensor.h>

CapacitiveSensor Sensor = CapacitiveSensor(4, 6); /* sendpin 3; receivepin 5 */
uint8_t ledPinBlue = 13; /* LED auf Pin 13 */
bool anwesend = false;


void setup()
{
  Serial.begin(9600);
  pinMode(ledPinBlue, OUTPUT);
}

void loop()
{
  /* Nur duch Berührung mit einem Metallstift soll im folgenden eine blaue LED eingeschaltet werden */
  long val = Sensor.capacitiveSensor(30);
  Serial.println(val);

  if ((anwesend == true) && (val < 500))
  {
    digitalWrite(ledPinBlue, LOW);   // sets the LED off
    anwesend = false;
  }
  if ((anwesend == false) && (val >= 1000))
  {
    digitalWrite(ledPinBlue, HIGH);
    anwesend = true;
  }
}
