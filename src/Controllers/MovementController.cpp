#include "Controllers/MovementController.hpp"

#include "Components.hpp"
#include "Hardware/Motor.hpp"

#include <ArduinoJson.hpp>
#include <ESPAsyncWebServer.h>

using Request = AsyncWebServerRequest;

namespace Maze {
	MovementController::~MovementController() = default;

	void MovementController::forward(Request* r) {
		ArduinoJson::DynamicJsonDocument doc(1024);
		_components.motorLeft().speed(0.5);
		_components.motorRight().speed(0.5);
		_movement = Movement::FORWARDS;
		send(200, r, doc, __func__);
	}

	void MovementController::stop(Request* r) {
		ArduinoJson::DynamicJsonDocument doc(1024);
		_components.motorLeft().speed(0);
		_components.motorRight().speed(0);
		_movement = Movement::STOP;
		send(200, r, doc, __func__);
	}

	void MovementController::status(Request* r) {
		ArduinoJson::DynamicJsonDocument doc(1024);
		doc["status"] = getMovement(_movement);
		send(200, r, doc, __func__);
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
