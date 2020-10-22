#include "Runner.hpp"

#include "Components.hpp"
#include "Controllers/MovementController.hpp"
#include "Hardware/Range.hpp"
#include "Router.hpp"
#include "Utility.hpp"

#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <ESPmDNS.h>
#include <WiFi.h>

namespace Maze {
	const char* HOSTNAME = "micromouse";
	const char* AP = "micromouse";
	const char* PASSWORD = "micromouse-password";

	Runner::Runner() = default;
	Runner::~Runner() = default;

	void Runner::setup() {
		_components = std::make_unique<Components>();
		Serial.printf("[Runner:setup] Components created!\r\n");

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
		Serial.printf("[Runner:setup] Set Hostname: ... %s", is(ok)) ;

		Serial.printf("\r\n");

		Serial.printf("[Runner:setup] MAC:           [%s]\r\n", WiFi.softAPmacAddress().c_str());
		Serial.printf("[Runner:setup] Hostname:      %s\r\n", HOSTNAME);

		if (MDNS.begin(HOSTNAME)) {
			Serial.printf("[Runner:setup] MDNS Hostname: %s\r\n", HOSTNAME);
		}

		Serial.printf("\r\n");
		Serial.printf("[Runner:setup] IP:            %s\r\n", WiFi.softAPIP().toString().c_str());
		Serial.printf("[Runner:setup] AP:            %s\r\n", AP);
		Serial.printf("[Runner:setup] Password:      %s\r\n\r\n", PASSWORD);

		_server = std::make_unique<AsyncWebServer>(80);
		_router = std::make_unique<Router>(*_server, *_components);
		_router->router(*_server);
		_server->begin();
	}

	void Runner::loop() const {
		_components->loop();
	}
}

