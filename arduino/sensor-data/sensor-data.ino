#include <SPI.h>
#include <WiFiNINA.h>

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
  Serial.println("Scanning available networks");
  listNetworks();
  delay(10000);
}

void listNetworks() {
  Serial.println("** Scan Networks **");
  int numSsid = WiFi.scanNetworks();
  if(numSsid == -1) {
    Serial.println("Could reach any WiFi networks");
    while(true);
  }

  for(int thisNet = 0; thisNet < numSsid; thisNet++) {
    Serial.print(thisNet);
    Serial.print(") ");
    Serial.print(WiFi.SSID(thisNet));
    Serial.print("\tSignal: ");
    Serial.print(WiFi.RSSI(thisNet));
    Serial.print(" dBm");
    Serial.print("\tEncryption: ");
    Serial.print(WiFi.encryptionType(thisNet));
    Serial.print("\n");
  }
}
