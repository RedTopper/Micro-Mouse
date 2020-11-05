#include "Hardware/Motor.hpp"

#include <Arduino.h>

#define LEDC_BASE_FREQ     5000
#define LEDC_TIMER_13_BIT  13
#define LEDC_TIMER_13_BIT_MAX 8191

namespace Maze {
	Motor::Motor(uint8_t pin1, uint8_t pin2, uint8_t pinPWM, uint8_t channel, bool reverse) :
			_pin1(pin1),
			_pin2(pin2),
			_pinPWM(pinPWM),
			_channel(channel),
			_reverse(reverse) {
		pinMode(pin1, OUTPUT);
		pinMode(pin2, OUTPUT);
		ledcSetup(channel, LEDC_BASE_FREQ, LEDC_TIMER_13_BIT);
		ledcAttachPin(pinPWM, channel);
		_channel = channel;
	}

	void Motor::speed(double speed) const {
		auto limit = min(1.0, max(-1.0, speed));
		if (_reverse) limit *= -1.0;

		if (limit > 0.01) {
			// Clockwise
			digitalWrite(_pin1, HIGH);
			digitalWrite(_pin2, LOW);
		} else if (limit < 0.01) {
			// Counterclockwise
			digitalWrite(_pin1, LOW);
			digitalWrite(_pin2, HIGH);
		} else {
			// Stop
			digitalWrite(_pin1, LOW);
			digitalWrite(_pin2, LOW);
		}

		double multiplier = LEDC_TIMER_13_BIT_MAX;
		uint32_t duty = multiplier * limit;
		ledcWrite(_channel, duty);
	}
}