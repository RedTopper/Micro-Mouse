#include "Controllers/DataController.hpp"

#include "Components.hpp"
#include "Hardware/RangeComponent.hpp"
#include "Hardware/MotorComponent.hpp"
#include "Hardware/EncoderComponent.hpp"
#include "Runner.hpp"

#include <ESPAsyncWebServer.h>

using Request = AsyncWebServerRequest;

namespace Maze {
	DataController::~DataController() = default;

	void DataController::status(Request* r) {
		ArduinoJson::DynamicJsonDocument doc(1024);
		std::array<RangeComponent*, 3> sensors = {
				&_components.rangeFront(),
				&_components.rangeLeft(),
				&_components.rangeRight()
		};

		std::array<MotorComponent*, 2> motors = {
				&_components.motorLeft(),
				&_components.motorRight()
		};

		std::array<EncoderComponent*, 2> encoders = {
				&_components.encoderLeft(),
				&_components.encoderRight()
		};

		auto dataSensors = doc.createNestedObject("sensors");
		for (const auto* sensor : sensors) {
			auto json = dataSensors.createNestedObject(sensor->name());
			json["range"] = sensor->getRange();
			json["message"] = sensor->getMessage();
			json["ms"] = sensor->getTime();
			json["ms"] = sensor->getTime();
		}

		auto dataMotors = doc.createNestedObject("motors");
		for (const auto* motor : motors) {
			auto json = dataMotors.createNestedObject(motor->name());
			json["speedTarget"] = motor->getSpeedTarget();
			json["speedCurrent"] = motor->getSpeedCurrent();
		}

		auto dataEncoders = doc.createNestedObject("encoders");
		for (const auto* encoder : encoders) {
			auto json = dataEncoders.createNestedObject(encoder->name());
			json["ticks"] = encoder->getTicks();
			json["distance"] = encoder->getDistance();
		}

		doc["msProcess"] = _components.runner().getTimeCompute();
		doc["msLoop"] = _components.runner().getTimeLoop();

		send(200, r, doc, __func__);
	}
}
