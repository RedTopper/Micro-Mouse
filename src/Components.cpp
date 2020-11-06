#include <Utility.hpp>
#include "Components.hpp"

#include "Hardware/Range.hpp"
#include "Hardware/Motor.hpp"

namespace Maze {
	Components::Components(uint8_t pinEnable) {
		_rangeFront = std::make_unique<Range>(4, 0x30);
		_rangeLeft = std::make_unique<Range>(21, 0x31);
		_rangeRight = std::make_unique<Range>(27, 0x32);
		_motorLeft = std::make_unique<Motor>(32, 14, 26, 1, false);
		_motorRight = std::make_unique<Motor>(33, 15, 25, 3, true);
		_pinEnable = pinEnable;
		pinMode(pinEnable, OUTPUT);
	}

	Components::~Components() = default;

	void Components::setup() {
		std::array<Range*, 3> sensors = {
			_rangeFront.get(),
			_rangeLeft.get(),
			_rangeRight.get()
		};

		for (const auto* sensor : sensors) sensor->disable();
		delay(50);

		for (const auto* sensor : sensors) sensor->enable();
		delay(50);

		for (const auto* sensor : sensors) sensor->disable();
		delay(50);

		for (auto* sensorBoot : sensors) {
			for (const auto* sensor : sensors) {
				if(sensor == sensorBoot) {
					sensor->enable();
				}
			}

			delay(50);
			auto status = sensorBoot->boot();
			Serial.printf("[Components:setup] Sensor on pin '%d' is:   ... %s", sensorBoot->getPin(), is(status));
			delay(50);
		}
	}

	void Components::loop() {
		_timeAbsolute = millis();
		_rangeFront->loop();
		_rangeLeft->loop();
		_rangeRight->loop();
		_timeLoop = millis() - _timeAbsolute;

		if (_motorLeft->enabled() || _motorRight->enabled()) {
			digitalWrite(_pinEnable, HIGH);
		} else {
			digitalWrite(_pinEnable, LOW);
		}
	}
}