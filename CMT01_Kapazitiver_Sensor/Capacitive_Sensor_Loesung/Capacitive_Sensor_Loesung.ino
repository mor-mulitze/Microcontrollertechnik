#include <CapacitiveSensor.h> 

CapacitiveSensor Sensor = CapacitiveSensor(4, 6); /* sendpin 3; receivepin 5 */
int ledPinBlue = 13; /* LED auf Pin 13 */



void setup() 
{
  Serial.begin(9600);
  pinMode(ledPinBlue, OUTPUT);
} 
 
void loop() 
{ 
  /* Nur duch Berührung mit einem Metallstift soll im folgenden eine blaue LED eingeschaltet werden */
  long val = Sensor.capacitiveSensor(30);

  if (val < 1000)
  {
    digitalWrite(ledPinBlue, LOW);   // sets the LED off
  } else if (val >= 1000)
  {
    digitalWrite(ledPinBlue, HIGH);   // sets the LED on
  }
  
  delay(10); 
}
