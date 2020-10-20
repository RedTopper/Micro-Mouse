#include "Controllers/Controller.hpp"

#include <WebServer.h>

namespace Maze {
	Controller::Controller(WebServer& server, Components& components) : _server(server), _components(components) {}
	Controller::~Controller() = default;

	void Controller::send(int status, ArduinoJson::DynamicJsonDocument doc, const char* func) {
		doc["action"] = func;
		doc["controller"] = this->name();

		if (!doc.containsKey("response")) {
			doc["response"] = "ok";
		}

		_server.send(status, "application/json", doc.as<String>().c_str());
	}
}