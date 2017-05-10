#include <ESP8266WiFi.h>

const char* ssid ="SSID";
const char* password = "PASSWORD";

void setup() {
 Serial.begin(115200);
 WiFi.mode(WIFI_STA); //Station mode
 WiFi.disconnect(); //Disconnect from any WiFi network
 delay(100);
 Serial.println();
 Serial.print("Connecting to ");
 Serial.println(ssid);
 WiFi.begin(ssid, password); //Begin with ssid and pass
 while (WiFi.status() != WL_CONNECTED) {   // wait for WiFi
    delay(500);
    Serial.print(".");
 }
 Serial.println("");
 Serial.println("WiFi connected");
 Serial.println("IP address: ");
 Serial.println(WiFi.localIP());
 delay(1000);
}

void loop() {
}