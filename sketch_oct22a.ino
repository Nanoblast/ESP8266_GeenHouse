#include "DHTesp.h"
#include <ArduinoJson.h>
 
DHTesp dht;
 
void setup() {
    Serial.begin(115200);
}
 
void loop() {
    dht.setup(D7, DHTesp::DHT11);
    float h = dht.getHumidity();
    float t = dht.getTemperature();
    char* json = "\"Humidity\": ";
    char* c_h;

    StaticJsonDocument<200> doc;
    doc["sensor"] = "dht11";
    JsonArray data = doc.createNestedArray("data");
    data.add(h);
    serializeJson(doc, Serial);
    Serial.print("\n");
    Serial.print("{\"humidity\": ");
    Serial.print(h);
    Serial.print(", \"temp\": ");
    Serial.print(t);
    Serial.print("}\n");
 
    delay(2000);
}
