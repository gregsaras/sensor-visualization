#include <SPI.h>
#include <WiFiNINA.h>

#include "config.h";

void setup() {
  Serial.begin(9600);
  while(!Serial) { ; }

  if(!has_WiFiModule) {
    Serial.println("Communication with WiFi module failed, halting program");
    while(true);
  } else {
    Serial.println("Successfully detected WiFi module");
  }

  printFirmwareInformation(); 
}

void loop() {
  Serial.println("Connecting to WiFi network: ");
  Serial.println(SSID);
  delay(10000);
}

boolean has_WiFiModule() {
  return WiFi.status() != WL_NO_MODULE;
}

void printFirmwareInformation(){
   String fv = WiFi.firmwareVersion();
  if(fv < WIFI_FIRMWARE_LATEST_VERSION) {
    Serial.println("Latest firmware version ");
    Serial.println(WIFI_FIRMWARE_LATEST_VERSION);
  } else {
    Serial.println("Firmware up to date");
  }

   Serial.println("Current Version: ");
   Serial.println(fv);  
}
