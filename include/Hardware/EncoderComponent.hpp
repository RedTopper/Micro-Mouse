#ifndef MICRO_MOUSE_ENCODERCOMPONENT_HPP
#define MICRO_MOUSE_ENCODERCOMPONENT_HPP

#include "Component.hpp"

#include <cstdint>
#include <Arduino.h>

namespace Maze {
	class EncoderComponent : public Component {
	public:
		EncoderComponent(uint8_t pin, uint32_t ratio, double diameter, const char *name);

		double getDistance() const {return (_ticks / (6.0 * _ratio)) * M_PI * _diameter;}
		uint32_t getTicks() const {return _ticks;}

		const char* name() const override {return _name;}
		void loop(double dilation) override {};

	private:
		void tick() {_ticks++;}

		const char* _name;
		uint8_t _pin;
		uint32_t _ratio;

		uint32_t _ticks{};
		double _distance{};
		double _diameter;
	};
}

#endif //MICRO_MOUSE_ENCODERCOMPONENT_HPP
