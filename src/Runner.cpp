#include "Mouse.hpp"
#include "Runner.hpp"
#include "Utility.hpp"

#include <Arduino.h>
#include <WiFi.h>

namespace Maze {
	const char* HOSTNAME = "micromouse";
	const char* AP = "micromouse";
	const char* PASSWORD = "micromouse-password";

	void Runner::setup() {
		Serial.begin(115200);
		Serial.printf("[Runner:setup] Serial Connected!\r\n");

		bool ok;
		IPAddress ip(172, 16, 0, 1);
		IPAddress mask(255, 255, 255, 0);

		ok = WiFiClass::mode(WIFI_AP);
		Serial.printf("[Runner:setup] Set AP Mode:  ... %s", is(ok)) ;

		ok = WiFi.softAP(AP, PASSWORD);
		Serial.printf("[Runner:setup] Set Soft AP:  ... %s", is(ok)) ;

		delay(100);

		WiFi.softAPConfig(ip, ip, mask);
		Serial.printf("[Runner:setup] Set Config:   ... %s", is(ok)) ;

		WiFi.softAPsetHostname(HOSTNAME);
		Serial.printf("[Runner:setup] Set Hostname: ... %s\r\n", is(ok)) ;

		Serial.printf("[Runner:setup] MAC:      [%s]\r\n", WiFi.softAPmacAddress().c_str());
		Serial.printf("[Runner:setup] Hostname: %s\r\n\r\n", HOSTNAME);

		Serial.printf("[Runner:setup] IP:       %s\r\n", WiFi.softAPIP().toString().c_str());
		Serial.printf("[Runner:setup] AP:       %s\r\n", AP);
		Serial.printf("[Runner:setup] Password: %s\r\n\r\n", PASSWORD);

		httpd_config_t config = HTTPD_DEFAULT_CONFIG();
		ok = httpd_start(&_server, &config);
		Serial.printf("[Runner:setup] Starting http server: ... %s", is(ok == ESP_OK));

		_router = std::make_unique<Router>(std::make_unique<Mouse>());
		_router->start(_server);
	}

	void Runner::loop() {

	}


}

