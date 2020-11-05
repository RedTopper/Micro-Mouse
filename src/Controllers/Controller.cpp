#include "Controllers/Controller.hpp"

#include <ESPAsyncWebServer.h>

using Request = AsyncWebServerRequest;

namespace Maze {
	Controller::Controller(Components& components) : _components(components) {}
	Controller::~Controller() = default;

	void Controller::send(int status, Request* r, ArduinoJson::DynamicJsonDocument doc, const char* func) {
		doc["action"] = func;
		doc["controller"] = name();

		if (!doc.containsKey("response")) {
			doc["response"] = "ok";
		}

		Serial.printf("[Controller:send] Sending %s:%s...\r\n", name(), func);
		r->send(status, "application/json", doc.as<String>().c_str());
	}
}