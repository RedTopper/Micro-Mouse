#include "Hardware/Motor.hpp"

#include <Arduino.h>

#define LEDC_BASE_FREQ     5000
#define LEDC_TIMER_13_BIT  13
#define LEDC_TIMER_13_BIT_MAX 8191

namespace Maze {
	Motor::Motor(int pin, int channel) {
		ledcSetup(channel, LEDC_BASE_FREQ, LEDC_TIMER_13_BIT);
		ledcAttachPin(pin, channel);
		_channel = channel;
	}

	void Motor::speed(double speed) const {
		auto limit = min(1.0, max(0.0, speed));
		double multiplier = LEDC_TIMER_13_BIT_MAX;
		uint32_t duty = multiplier * limit;

		ledcWrite(_channel, duty);
	}
}