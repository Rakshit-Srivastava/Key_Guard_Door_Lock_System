#include <WiFiManager.h>
#include <strings_en.h>
#include <wm_consts_en.h>
#include <wm_strings_en.h>
#include <wm_strings_es.h>

#include <ArduinoWiFiServer.h>
#include <BearSSLHelpers.h>
#include <CertStoreBearSSL.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiGratuitous.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiClientSecureBearSSL.h>
#include <WiFiServer.h>
#include <WiFiServerSecure.h>
#include <WiFiServerSecureBearSSL.h>
#include <WiFiUdp.h>

#include <ESP8266HTTPClient.h>
WiFiClient Client;
HTTPClient http;
int p ;
void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.begin("Redmi Note 10S", "gsvv9767");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }
  Serial.println("Connected to WiFi");
}

void loop()
{
  if (Serial.available() > 0)
  {
  String receivedData = Serial.readStringUntil('\n');
  String password = receivedData.substring(0, receivedData.indexOf(" "));
  Serial.println(password);

  // Create a new HTTPClient instance for this request
  HTTPClient http;
  http.begin(Client, "http://api.thingspeak.com/update?api_key=IDISD4YQI18TI6UI&field1=" + String(password));
  Serial.print("Waiting for response");
  p = http.GET();
  
  if (p > 0) 
  {
    Serial.println("Success");
  } else 
  {
    Serial.println("error");
  }

  http.end();
  delay(10000);
  }
}

