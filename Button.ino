#define tombolMerah 2
#define tombolKuning 23

#include <WiFi.h>
#include <MQTT.h>
#include <NusabotSimpleTimer.h>

const char ssid[] = "nightside";
const char pass[] = "makanmie";

WiFiClient net;
MQTTClient client;
NusabotSimpleTimer timer;

void connect() {
  Serial.print("checking wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("\nconnecting...");
  while (!client.connect("diva")) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nconnected!");
}

void publish() {
  bool statusMerah  = digitalRead(tombolMerah);
  bool statusKuning = digitalRead(tombolKuning);


  Serial.println(statusMerah);
  Serial.println(statusKuning);

  if(statusMerah == 1){
    client.publish("diva/rumah-a/merah", "1");
  }

  if(statusKuning == 1){
    client.publish("diva/rumah-b/kuning", "1");

  }
  
}

void setup() {
  pinMode(tombolMerah, INPUT);
  pinMode(tombolKuning, INPUT);

  Serial.begin(115200);
  WiFi.begin(ssid, pass);

  client.begin("broker.emqx.io", net);
  timer.setInterval(1000, publish);

  connect();
}

void loop() {
  client.loop();
  timer.run();
  delay(10);  // <- fixes some issues with WiFi stability

  if (!client.connected()) {
    connect();
  }
}
