
#include "credentials.h"
#include "wifi_tools.h"
#include "mqtt.h"
#include "device.h"

void setup() {
	Serial.begin(115200);
	Serial.println("\n\tawake...");
	wifi_tools.begin(WIFI_SSID, WIFI_PASS);
	mqtt.setup(MQTT_HOST, MQTT_PORT);
	device.setup();
}

void loop() {
	if (wifi_tools.is_connected) {
		mqtt.maintain();
		device.loop();
	} else {
		wifi_tools.reconnect();
		mqtt.report_disconnect();
	}
}

