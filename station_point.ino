#include <ESP8266WiFi.h>
byte Pin1 = 2;
char ssid[] = "Test";           // SSID of your AP
char pass[] = "";         // password of your AP
IPAddress server(192,168,39,101);     // IP address of the AP
WiFiClient client;
void setup() {
  Serial.begin(115200);

  pinMode(Pin1, OUTPUT);
  digitalWrite(Pin1,LOW);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);           // connects to the WiFi AP
  Serial.println();
  Serial.println("Connection to the AP");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println("Connected");
  Serial.println("Test");
  Serial.print("LocalIP:"); Serial.println(WiFi.localIP());
  Serial.println("MAC:" + WiFi.macAddress());
  Serial.print("Gateway:"); Serial.println(WiFi.gatewayIP());
  Serial.print("AP MAC:"); Serial.println(WiFi.BSSIDstr());
}
void loop() {
  client.connect(server, 80);
  Serial.println("********************************");
  
  String answer = "";
  answer = client.readStringUntil('\r');
  Serial.println("From the AP: " + answer);
  
  if(answer.equals("blink"))
  {
      digitalWrite(Pin1, HIGH);
      delay(70);
      digitalWrite(Pin1, LOW);
      delay(70);
  }
  else if(answer.equals("dont blink"))
  {
     digitalWrite(Pin1, LOW);
     delay(100);
  }
  
  digitalWrite(Pin1,LOW);
  
  client.flush();
  //digitalWrite(ledPin, HIGH);
  client.stop();
  delay(50);
}
