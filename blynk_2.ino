#include <Servo.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
Servo servo;
char auth[] = ”LsU-iY9BGpw0Z7MBIMaQq1c0MBo-D5gu“;//Enter your Blynk auth token
char ssid[] = ”RAHUL 4G“;//Enter your WIFI name
char pass[] = ”poorva2000“;//Enter your WIFI password
 
BLYNK_WRITE(V0){
  servo.write(param.asInt());
}
void setup() {
  Serial.begin(9600);
  servo.attach(D4);
  Blynk.begin(auth, ssid, pass);
}
 
void loop() {
  Blynk.run();
}
 
