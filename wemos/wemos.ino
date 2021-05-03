#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "wemospin.h"

//WiFi dan Token
char auth[] = "uPgIWEteat_fblexZnSM3K88BdC1p_EO";
char ssid[] = "robotku";
char pass[] = "robot1234";

BLYNK_WRITE(V10) {
  int klik = param.asInt();
  Serial.println(klik);

  if (klik)setON();
  else setOFF();
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
}

//Set ON / OFF
void setON() {
  digitalWrite(relay, LOW);
  Blynk.notify("SAKLAR ON");
}
void setOFF() {
  digitalWrite(relay, HIGH);
  Blynk.notify("SAKLAR OFF");
}
