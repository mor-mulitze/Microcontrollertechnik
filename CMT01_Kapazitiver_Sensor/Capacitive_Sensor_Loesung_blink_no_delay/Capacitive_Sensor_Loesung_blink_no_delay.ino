#include <CapacitiveSensor.h>
CapacitiveSensor Sensor = CapacitiveSensor(4, 6);
int32_t val;
uint8_t led = 13;
bool blink = false;
uint32_t starttime;

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop()
{
  val = 2000;
//  val = Sensor.capacitiveSensor(30);
  Serial.println(val);
  
  if (val >= 1000) {
    uint32_t time = millis();
    if (blink == false) starttime = time;
    if (millis() - starttime > 1000)
    {
      digitalWrite(led, !digitalRead(13));
      starttime = time;
    }
    blink = true;
  }

  else if (val < 1000) {
    blink = false;
    digitalWrite(led, LOW);   
  }

  delay(10);
}
