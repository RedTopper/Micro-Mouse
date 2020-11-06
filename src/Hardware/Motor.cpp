#include "Hardware/Motor.hpp"

#include "Utility.hpp"

#include <Arduino.h>


#define LEDC_BASE_FREQ     5000
#define LEDC_TIMER_13_BIT  13
#define LEDC_TIMER_13_BIT_MAX 8191

namespace Maze {
	Motor::Motor(uint8_t pin1, uint8_t pin2, uint8_t pinPWM, uint8_t channel, bool reverse) :
			_pin1(pin1),
			_pin2(pin2),
			_channel(channel),
			_reverse(reverse),
			_enabled(false) {
		pinMode(pin1, OUTPUT);
		pinMode(pin2, OUTPUT);
		ledcSetup(channel, LEDC_BASE_FREQ, LEDC_TIMER_13_BIT);
		ledcAttachPin(pinPWM, channel);
	}

	void Motor::speed(double speed) {
		auto limit = clamp(speed, -1.0, 1.0);
		if (_reverse) limit *= -1.0;

		if (limit > 0.01) {
			// Clockwise
			digitalWrite(_pin1, HIGH);
			digitalWrite(_pin2, LOW);
			double multiplier = LEDC_TIMER_13_BIT_MAX;
			uint32_t duty = multiplier * limit;
			ledcWrite(_channel, duty);
			_enabled = true;
		} else if (limit < -0.01) {
			// Counterclockwise
			digitalWrite(_pin1, LOW);
			digitalWrite(_pin2, HIGH);
			double multiplier = LEDC_TIMER_13_BIT_MAX;
			uint32_t duty = -1.0 * multiplier * limit;
			ledcWrite(_channel, duty);
			_enabled = true;
		} else {
			// Stop
			digitalWrite(_pin1, LOW);
			digitalWrite(_pin2, LOW);
			ledcWrite(_channel, 0);
			_enabled = false;
		}
	}
}