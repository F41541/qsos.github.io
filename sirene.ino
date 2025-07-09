#include <WiFi.h>
#include <MQTT.h>

const char ssid[] = "nightside";
const char pass[] = "makanmie";

WiFiClient net;
MQTTClient client;

void connect() {
  Serial.print("checking wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("\nconnecting broker...");
  while (!client.connect("diva-lagi")) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nconnected broker!");

  client.subscribe("diva/#", 1);
}

void messageReceived(String &topic, String &data) {
  Serial.println("incoming: " + topic + " - " + data);
  if(topic == "diva/rumah-a/merah" && data == "1"){
    digitalWrite(25, 1);
    delay(3000);
    digitalWrite(25, 0);
  } 
  if(topic == "diva/rumah-b/kuning" && data == "1"){
    digitalWrite(25, 1);
    delay(3000);
    digitalWrite(25, 0);
  } 
  
}

void setup() {
  pinMode(25, OUTPUT);
  Serial.begin(115200);
  WiFi.begin(ssid, pass);

  client.begin("broker.emqx.io", net);
  client.onMessage(messageReceived);

  connect();
}

void loop() {
  client.loop();
  delay(10);  // <- fixes some issues with WiFi stability

  if (!client.connected()) {
    connect();
  }
}