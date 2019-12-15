#include <ESP8266WiFi.h>

WiFiServer server(80);
IPAddress IP(192,168,39,101);
IPAddress mask = (255, 255, 255, 0);
byte Pin1 = D0;
void setup() {
 Serial.begin(115200);
 WiFi.mode(WIFI_AP);
 WiFi.softAP("Test", "");
 WiFi.softAPConfig(IP, IP, mask);
 server.begin();
 pinMode(Pin1, INPUT);
 Serial.println();
 Serial.println("Test");
 Serial.println("Server started.");
 Serial.print("IP: "); Serial.println(WiFi.softAPIP());
 Serial.print("MAC:"); Serial.println(WiFi.softAPmacAddress());
}
void loop() {
 WiFiClient client = server.available();
 if (!client) 
 {
  return;
  }
 if(digitalRead(Pin1)==HIGH)
 {
    Serial.print("Byte sent to the station: ");
    Serial.println(client.println("blink"));
 }
  else if(digitalRead(Pin1)==LOW)
 {
    Serial.print("Byte sent to the station: ");
    Serial.println(client.println("dont blink"));
 }
}
