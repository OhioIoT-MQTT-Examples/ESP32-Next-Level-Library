#include "device.h"
#include "mqtt.h"

Device::Device() {}

Device device;

void Device::setup() {
    static const char * subscription_list[] = {
        "beacon"
    };
    mqtt.set_subscriptions(subscription_list, 1);   // make this digit match the length of your list
    mqtt.set_callback(message_handler);
}


void Device::loop() {
    float temperature = 69.0 + (random(0,200) / 100.0);
    mqtt.publish("temperature", temperature);
    delay(2000);
}


void Device::message_handler(char* topic, char* payload) {
    Serial.print("\treceived: ");
    Serial.print(topic);
    Serial.print(" / ");
    Serial.println(payload);
}