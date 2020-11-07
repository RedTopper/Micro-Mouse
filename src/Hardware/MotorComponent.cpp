#include "Hardware/MotorComponent.hpp"

#include "Utility.hpp"

#include <Arduino.h>


#define LEDC_BASE_FREQ     5000
#define LEDC_TIMER_13_BIT  13
#define LEDC_TIMER_13_BIT_MAX 8191

namespace Maze {
	MotorComponent::MotorComponent(uint8_t pin1, uint8_t pin2, uint8_t pinPWM, uint8_t channel, bool reverse, const char* name) :
			_pin1(pin1),
			_pin2(pin2),
			_channel(channel),
			_reverse(reverse),
			_enabled(false),
			_name(name) {
		pinMode(pin1, OUTPUT);
		pinMode(pin2, OUTPUT);
		ledcSetup(channel, LEDC_BASE_FREQ, LEDC_TIMER_13_BIT);
		ledcAttachPin(pinPWM, channel);
	}

	void MotorComponent::setSpeed(double speed) {
		auto limit = clamp(speed, -1.0, 1.0);
		if (_reverse) limit *= -1.0;
		_speedTarget = limit;
	}

	void MotorComponent::loop(double dilation) {
		const double ACCELERATION = 0.5;

		double sign = _speedTarget < 0 ? -1.0 : 1.0;
		if (abs(_speedCurrent) < abs(_speedTarget)) {
			_speedCurrent += ACCELERATION * dilation * sign;
		} else {
			_speedCurrent = _speedTarget;
		}

		if (_speedCurrent > 0.01) {
			// Clockwise
			digitalWrite(_pin1, HIGH);
			digitalWrite(_pin2, LOW);
			double multiplier = LEDC_TIMER_13_BIT_MAX;
			uint32_t duty = multiplier * _speedCurrent;
			ledcWrite(_channel, duty);
			_enabled = true;
		} else if (_speedCurrent < -0.01) {
			// Counterclockwise
			digitalWrite(_pin1, LOW);
			digitalWrite(_pin2, HIGH);
			double multiplier = LEDC_TIMER_13_BIT_MAX;
			uint32_t duty = -1.0 * multiplier * _speedCurrent;
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