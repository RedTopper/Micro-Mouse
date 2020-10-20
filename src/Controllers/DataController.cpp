#include "Controllers/DataController.hpp"

#include "Components.hpp"
#include "Hardware/Range.hpp"

namespace Maze {
	DataController::~DataController() = default;

	void DataController::status() {
		ArduinoJson::DynamicJsonDocument doc(1024);
		auto& front = _components.rangeFront();
		doc["range"] = front.range();
		doc["message"] = front.message();
		send(200, doc, __func__);
	}
}
