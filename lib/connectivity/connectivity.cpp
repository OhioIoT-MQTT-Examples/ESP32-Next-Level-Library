#include "connectivity.h"
#include "credentials.h"
#include "wifi_tools.h"
#include "mqtt.h"

Connectivity::Connectivity() {}

Connectivity connectivity;

void Connectivity::setup() {
    wifi_tools.begin(WIFI_SSID, WIFI_PASS);
	mqtt.setup(MQTT_HOST, MQTT_PORT);
}


void Connectivity::loop() {
    if (wifi_tools.is_connected) {
		mqtt.maintain();
	} else {
		wifi_tools.reconnect();
		mqtt.report_disconnect();
	}
}