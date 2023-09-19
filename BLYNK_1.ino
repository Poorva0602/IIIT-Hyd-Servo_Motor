#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

char auth[] = "QGbY1mvyMAZpII81xgg6SzqR2qWKIn_w";
char ssid[] = "RAHUL 4G";
char pass[] = "poorva2000";

Servo servo;
void cradle()
{
  int pos;
  for(pos = 0; pos <= 180; pos += 1)
  {
    servo.write(pos);
    delay(5);
  }
  for(pos = 180; pos >= 0; pos -= 1)
  {
    servo.write(pos);
    delay(10);
  }
}
BLYNK_WRITE(V3)
{
  int pinValue = param.asInt();
  if (pinValue == 1)
  {
    cradle();
    Blynk.syncVirtual(V3);
  }
}
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  servo.attach(D4);
}
void loop()
{
  Blynk.run();
}
