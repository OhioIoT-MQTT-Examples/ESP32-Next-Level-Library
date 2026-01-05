#include "mqtt.h"

#define DEVICE_ID "test_device_id"

Mqtt::Mqtt() {}

Mqtt mqtt;

void Mqtt::setup(const char * mqtt_host, int mqtt_port) {

    _mqtt_client.setClient(_wifi_client);
    _mqtt_client.setServer(mqtt_host, mqtt_port);

}

void Mqtt::maintain() {

    if (!_mqtt_client.connected() || !_is_connected) {
        bool should_reconnect = _is_first_connect || millis() - _retry_timer > RETRY_INTERVAL;
        if (should_reconnect) {
            Serial.println("\tmqtt connecting...");
            if (_mqtt_client.connect(DEVICE_ID)) {
                Serial.println("\tmqtt connected...");
                _is_connected = true;

                _subscribe_to_all();

            } else {
                Serial.println("\txx failed to connect to mqtt");
                _is_connected = false;
            }
        }
    } else {
        _mqtt_client.loop();       
    }
  
}


void Mqtt::report_disconnect() {
    _is_connected = false;
}
