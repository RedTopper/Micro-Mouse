#include "Controllers/DataController.hpp"

#include "Components.hpp"
#include "Hardware/Range.hpp"

#include <ESPAsyncWebServer.h>

using Request = AsyncWebServerRequest;

namespace Maze {
	DataController::~DataController() = default;

	void DataController::status(Request* r) {
		ArduinoJson::DynamicJsonDocument doc(1024);
		auto& front = _components.rangeFront();
		doc["range"] = front.range();
		doc["message"] = front.message();
		send(200, r, doc, __func__);
	}
}
