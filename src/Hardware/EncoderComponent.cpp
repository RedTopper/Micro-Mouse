#include "Hardware/EncoderComponent.hpp"

#include <Arduino.h>

namespace Maze {
	EncoderComponent::EncoderComponent(uint8_t pin, uint32_t ratio, double diameter, const char *name) {
		_pin = pin;
		_name = name;
		_ratio = ratio;
		_diameter = diameter;

		pinMode(pin, INPUT);
		attachInterruptArg(pin, +[](void* object) {
			auto encoder = static_cast<EncoderComponent*>(object);
			encoder->tick();
		}, static_cast<void*>(this), CHANGE);
	}
}