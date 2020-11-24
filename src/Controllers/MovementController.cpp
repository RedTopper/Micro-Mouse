#include "Controllers/MovementController.hpp"

#include "Components.hpp"
#include "Hardware/MotorComponent.hpp"

#include <ArduinoJson.hpp>
#include <ESPAsyncWebServer.h>

using Request = AsyncWebServerRequest;
using DynamicJsonDocument = ArduinoJson::DynamicJsonDocument;

namespace Maze {
	MovementController::~MovementController() = default;

	void MovementController::forward(Request* r) {
		ArduinoJson::DynamicJsonDocument doc(1024);
        _components.motorLeft().setSpeed(0.5);
        _components.motorRight().setSpeed(0.5);
		_movement = Movement::FORWARDS;
		send(200, r, doc, __func__);
	}

	void MovementController::stop(Request* r) {
		ArduinoJson::DynamicJsonDocument doc(1024);
        _components.motorLeft().setSpeed(0);
        _components.motorRight().setSpeed(0);
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

	void MovementController::move(DynamicJsonDocument& request) {
		if (request.containsKey("left") && request["left"].is<double>() &&
		    request.containsKey("right") && request["right"].is<double>()) {
			double left = request["left"];
			double right = request["right"];
			_components.motorLeft().setSpeed(left);
			_components.motorRight().setSpeed(right);
			Serial.printf("[MovementController:socket] left %f, right %f!\r\n", left, right);
		}
	}

	void MovementController::socket(AsyncWebSocketClient* client, AwsEventType type, void* arg, uint8_t* data, size_t len) {
		switch (type) {
		case WS_EVT_CONNECT:
			Serial.printf("[MovementController:socket] Client %u, hello\r\n", client->id());
			return;
		case WS_EVT_DISCONNECT:
			Serial.printf("[MovementController:socket] Client %u, goodbye\r\n", client->id());
			return;
		case WS_EVT_ERROR:
			Serial.printf("[MovementController:socket] Client %u: error %u\r\n", client->id(), *((uint16_t*)arg));
			return;
		case WS_EVT_PONG:
			Serial.printf("[MovementController:socket] Client %u: pong\r\n", client->id());
			return;
		case WS_EVT_DATA:
			Serial.printf("[MovementController:socket] Client %u: getting data ... ", client->id());
		}

		auto* info = (AwsFrameInfo*)arg;
		if(info->opcode != WS_TEXT) return;

		data[len] = 0;
		DynamicJsonDocument json(1024);
		auto error = deserializeJson(json, (const char*)data);

		if (error) {
			Serial.printf("decode error: %s\r\n", error.c_str());
		} else {
			Serial.printf("got:\r\n%s\r\n", (const char*)data);
			move(json);
		}
	}
}
