#include "Runner.hpp"

#include "Components.hpp"
#include "Controllers/MovementController.hpp"
#include "Hardware/RangeComponent.hpp"
#include "Router.hpp"
#include "Utility.hpp"

#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <ESPmDNS.h>
#include <WiFi.h>

namespace Maze {
	const char *HOSTNAME = "micromouse";
	const char *AP = "micromouse";
	const char *PASSWORD = "micromouse-password";

	Runner::Runner() = default;

	Runner::~Runner() = default;

	void Runner::setup() {
		_components = std::make_unique<Components>(*this, 13);
		Serial.printf("[Runner:setup] Components created!\r\n");

		_components->setup();
		Serial.printf("[Runner:setup] Components set up!\r\n");

		bool ok;
		IPAddress ip(172, 16, 0, 1);
		IPAddress mask(255, 255, 255, 0);

		ok = WiFiClass::mode(WIFI_AP);
		Serial.printf("[Runner:setup] Set AP Mode:  ... %s", is(ok));

		ok = WiFi.softAP(AP, PASSWORD);
		Serial.printf("[Runner:setup] Set Soft AP:  ... %s", is(ok));

		delay(100);

		WiFi.softAPConfig(ip, ip, mask);
		Serial.printf("[Runner:setup] Set Config:   ... %s", is(ok));

		WiFi.softAPsetHostname(HOSTNAME);
		Serial.printf("[Runner:setup] Set Hostname: ... %s", is(ok));

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
		_router->router();
		_server->begin();

		Serial.printf("[Runner:setup] Setup Complete!\r\n");
	}

	void Runner::loop(int frequency) {
		// Compute the fraction of a second it took for the last loop
		double dilation = (double) _timeLoop / 1000.0;

		// Start timer
		_timeAbsolute = millis();

		_components->loop(dilation);
		// Other loop-able stuff here

		// Calculate times
		_timeCompute = millis() - _timeAbsolute;
		delay(clamp(1000.0 / frequency - _timeCompute, 0, 1000));
		_timeLoop = millis() - _timeAbsolute;
	}
}

