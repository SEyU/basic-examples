#include "ESP8266WiFi.h"

const char* ssid = "SSID";
const char* password = "PASS";

WiFiServer server(80);

void setup() {
  Serial.begin(115200);

  pinMode(LED_BUILTIN, OUTPUT);

  IPAddress ip(192, 168, 1, 99);
  IPAddress gateway(192, 168, 1, 1);
  IPAddress subnet(255, 255, 255, 0);
  WiFi.config(ip, gateway, subnet);

  WiFi.begin(ssid, password);

  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (!client)
    return;

  Serial.println("new client");
  while(!client.available()) // Esperar petición
    delay(1);

  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();

  int val;
  if ( req.indexOf("/led/0") != -1)
    val = 0;
  else if (req.indexOf("/led/1") != -1)
    val = 1;
  else
  {
    Serial.println("invalid request");
    client.stop();
    return;
  }

  digitalWrite(LED_BUILTIN, val);

  String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\nGPIO is now ";
  s += (val)?"high":"low";
  s += "</html>\n";

  client.print(s); // Enviar el resultado de val al cliente
  delay(1);
  Serial.println("Client disonnected");
}
