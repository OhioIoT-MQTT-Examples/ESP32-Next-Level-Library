#include "mqtt.h"


void Mqtt::publish(const char * topic, const char * payload) {
    _publish(topic, payload);
}

void Mqtt::publish(const char * topic, float number) {
    char payload[32];
    dtostrf(number, 0, 2, payload);
    _publish(topic, payload);
}

void Mqtt::publish(const char * topic, int number) {
    char payload[32];
    itoa(number, payload, 10);
    _publish(topic, payload);
}

void Mqtt::publish(const char * topic) {
    _publish(topic, "");
}


void Mqtt::_publish(const char * topic, const char * payload) {
    if (_is_connected) {

        char enhanced_topic[128];
        strcpy(enhanced_topic, _device_id);
        strcat(enhanced_topic, "/");
        strcat(enhanced_topic, topic);

        Serial.print("\tsending: ");
        Serial.print(enhanced_topic);
        Serial.print(" / ");
        Serial.println(payload);
        _mqtt_client.publish(enhanced_topic, payload);
    }
}