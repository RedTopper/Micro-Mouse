#include "Controllers/MovementController.hpp"

#include <ArduinoJson.hpp>
#include <WebServer.h>

namespace Maze {
	MovementController::~MovementController() = default;

	void MovementController::forward() {
		ArduinoJson::DynamicJsonDocument doc(1024);
		_movement = Movement::FORWARDS;
		send(200, doc, __func__);
	}

	void MovementController::stop() {
		ArduinoJson::DynamicJsonDocument doc(1024);
		_movement = Movement::STOP;
		send(200, doc, __func__);
	}

	void MovementController::status() {
		ArduinoJson::DynamicJsonDocument doc(1024);
		doc["status"] = getMovement(_movement);
		send(200, doc, __func__);
	}

	const char* MovementController::getMovement(MovementController::Movement movement) {
		switch (movement) {
			case Movement::FORWARDS: return "Forwards";
			case Movement::BACKWARDS: return "Backwards";
			case Movement::STOP: return "Stopped";
		}

		return "Unknown";
	}
}
