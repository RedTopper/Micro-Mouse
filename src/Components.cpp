#include "Utility.hpp"
#include "Components.hpp"

#include "Hardware/EncoderComponent.hpp"
#include "Hardware/MotorComponent.hpp"
#include "Hardware/RangeComponent.hpp"

namespace Maze {
	Components::Components(Runner &runner, uint8_t pinEnable) : _runner(runner) {
		_rangeFront = std::make_unique<RangeComponent>(4, 0x30, "front");
		_rangeLeft  = std::make_unique<RangeComponent>(21, 0x31, "left");
		_rangeRight = std::make_unique<RangeComponent>(27, 0x32, "right");
		_motorLeft  = std::make_unique<MotorComponent>(32, 14, 26, 1, false, "left");
		_motorRight = std::make_unique<MotorComponent>(33, 15, 25, 3, true, "right");
		_encoderLeft = std::make_unique<EncoderComponent>(39, 150, 40.0, "left");
		_encoderRight = std::make_unique<EncoderComponent>(34, 150, 40.0,  "right");
		_pinEnable  = pinEnable;
		pinMode(pinEnable, OUTPUT);
	}

	Components::~Components() = default;

	void Components::setup() {
		std::array<RangeComponent *, 3> sensors = {
				_rangeFront.get(),
				_rangeLeft.get(),
				_rangeRight.get()
		};

		for (const auto *sensor : sensors) sensor->disable();
		delay(50);

		for (const auto *sensor : sensors) sensor->enable();
		delay(50);

		for (const auto *sensor : sensors) sensor->disable();
		delay(50);

		for (auto *sensorBoot : sensors) {
			for (const auto *sensor : sensors) {
				if (sensor == sensorBoot) {
					sensor->enable();
				}
			}

			delay(50);
			auto status = sensorBoot->boot();
			Serial.printf("[Components:setup] Sensor on pin '%d' is:   ... %s", sensorBoot->getPin(), is(status));
			delay(50);
		}
	}

	void Components::loop(double dilation) {
		_rangeFront->loop(dilation);
		_rangeLeft->loop(dilation);
		_rangeRight->loop(dilation);
		_motorLeft->loop(dilation);
		_motorRight->loop(dilation);
		_encoderLeft->loop(dilation);

		if (_motorLeft->isEnabled() || _motorRight->isEnabled()) {
			digitalWrite(_pinEnable, HIGH);
		} else {
			digitalWrite(_pinEnable, LOW);
		}
	}
}