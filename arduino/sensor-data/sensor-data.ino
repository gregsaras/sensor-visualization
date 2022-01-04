#include <SPI.h>
#include <WiFiNINA.h>

#include "config.h";

void setup() {
  Serial.begin(9600);
  while(!Serial) { ; }

  if(WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed");

    // Don't continue if no WiFi module is detected
    while(true);
  }
}

void loop() {
  Serial.println("Connecting to WiFi network: ");
  Serial.println(SSID);
  delay(10000);
}
