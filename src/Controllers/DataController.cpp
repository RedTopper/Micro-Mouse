#include "Controllers/DataController.hpp"

#include "Components.hpp"
#include "Hardware/Range.hpp"

#include <ESPAsyncWebServer.h>

using Request = AsyncWebServerRequest;

namespace Maze {
	DataController::~DataController() = default;

	void DataController::status(Request* r) {
		ArduinoJson::DynamicJsonDocument doc(1024);
		std::array<Range*, 3> sensors = {
			&_components.rangeFront(),
			&_components.rangeLeft(),
			&_components.rangeRight()
		};

		auto data = doc.createNestedObject("sensors");
		for (const auto* sensor : sensors) {
			String key;
			key += sensor->getPin();
			auto json = data.createNestedObject(key);
			json["range"] = sensor->getRange();
			json["message"] = sensor->getMessage();
			json["ms"] = sensor->getTime();
		}

		doc["ms"] = _components.getTime();

		send(200, r, doc, __func__);
	}
}
