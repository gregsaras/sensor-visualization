#include <SPI.h>
#include <WiFiNINA.h>

#include "config.h";

int status = WL_IDLE_STATUS;

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

  Serial.print("Starting connection to SSID: ");
  Serial.println(SSID);

  connectToWiFi();
  if(!is_connectedToWiFi()) {
    Serial.print("Failed to connect to SSID: ");
    Serial.println(SSID);

    while(true);
  } else {
    Serial.print("Successfully connected to SSID: ");
    Serial.println(SSID);
  }
}

void loop() {
  static const uint8_t analog_pins[] = { A0, A1, A2, A3, A4, A5 }; // all analog pins (WiFi Rev2)
  static const int sensorCount = 5; // sensors that are connected, assumes that you go from A0-A5 in that order

  for(int i = 0; i < sensorCount; i++){
    Serial.println(analogRead(analog_pins[i]));
  }
  
  delay(1000);
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

   Serial.print("Current Version: ");
   Serial.println(fv);  
}

void connectToWiFi() {
  int attemptsLeft = 3;
  while(status != WL_CONNECTED && attemptsLeft > 0) {
    status = WiFi.begin(SSID, PASS);
    attemptsLeft--;
    delay(10000);
  }
}

boolean is_connectedToWiFi() {
  return status == WL_CONNECTED;
}
