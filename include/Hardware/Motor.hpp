#ifndef MICRO_MOUSE_MOTOR_HPP
#define MICRO_MOUSE_MOTOR_HPP

#include <stdint.h>

namespace Maze {
	class Motor {
	public:
		explicit Motor(uint8_t pin1, uint8_t pin2, uint8_t pinPWM, uint8_t channel, bool reverse);

		void speed(double speed) const;

	private:
		uint8_t _pin1;
		uint8_t _pin2;
		uint8_t _pinPWM;
		uint8_t _channel;
		bool _reverse;
	};
}

#endif //MICRO_MOUSE_MOTOR_HPP
