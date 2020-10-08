#include "Controllers/MouseController.hpp"

#include <ArduinoJson.hpp>
#include <Arduino.h>

namespace Maze {
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

		Serial.printf("[Mouse:query] Query!\r\n");

		return send(r, doc, __func__);
	}
}
