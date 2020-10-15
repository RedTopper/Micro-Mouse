#include "Controllers/MouseController.hpp"

#include "Components.hpp"
#include "Sensors/Range.hpp"

#include <ArduinoJson.hpp>
#include <Arduino.h>

namespace Maze {
	MouseController::~MouseController() = default;

	esp_err_t MouseController::forward(httpd_req_t* r) {
		ArduinoJson::DynamicJsonDocument doc(1024);

		Serial.printf("[Mouse:forward] Forward march!\r\n");
		_movement = Movement::FORWARDS;

		return send(r, doc, __func__);
	}

	esp_err_t MouseController::stop(httpd_req_t* r) {
		ArduinoJson::DynamicJsonDocument doc(1024);

		Serial.printf("[Mouse:stop] And halt!\r\n");
		_movement = Movement::STOP;

		return send(r, doc, __func__);
	}

	esp_err_t MouseController::query(httpd_req_t* r) {
		ArduinoJson::DynamicJsonDocument doc(1024);
		doc["status"] = _movement == Movement::STOP ? "Stop" : (_movement == Movement::FORWARDS ? "Forwards" : "Backwards");

		auto& front = _components.rangeFront();
		doc["range"] = front.range();
		doc["message"] = front.message();

		Serial.printf("[Mouse:query] Query!\r\n");

		return send(r, doc, __func__);
	}
}
