#include "Runner.hpp"

#include "Controllers/MouseController.hpp"
#include "Sensors/Range.hpp"
#include "Components.hpp"
#include "Utility.hpp"
#include "Router.hpp"

#include <Arduino.h>
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
		Serial.printf("[Runner:setup] Set Hostname: ... %s\r\n", is(ok)) ;

		Serial.printf("[Runner:setup] MAC:      [%s]\r\n", WiFi.softAPmacAddress().c_str());
		Serial.printf("[Runner:setup] Hostname: %s\r\n\r\n", HOSTNAME);

		Serial.printf("[Runner:setup] IP:       %s\r\n", WiFi.softAPIP().toString().c_str());
		Serial.printf("[Runner:setup] AP:       %s\r\n", AP);
		Serial.printf("[Runner:setup] Password: %s\r\n\r\n", PASSWORD);

		httpd_config_t config = HTTPD_DEFAULT_CONFIG();
		ok = httpd_start(&_server, &config);
		Serial.printf("[Runner:setup] Starting http server: ... %s", is(ok == ESP_OK));

		_router = std::make_unique<Router>(*_components);
		_router->router(*this);
	}

	void Runner::loop() const {
		_components->loop();
	}

	esp_err_t Runner::dispatch(httpd_req_t *r) {
		auto* func = static_cast<Callable*>(r->user_ctx);
		return (*func)(r);
	}

	void Runner::get(const char* route, const Callable& callable) {
		auto pointer = std::make_unique<Callable>(callable);
		auto context = pointer.get();
		_callables.push_back(std::move(pointer));
		httpd_uri_t data {
				.uri = route,
				.method = HTTP_GET,
				.handler = &Runner::dispatch,
				.user_ctx = context
		};

		httpd_register_uri_handler(_server, &data);
	}
}

