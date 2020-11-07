#ifndef MICRO_MOUSE_MOTORCOMPONENT_HPP
#define MICRO_MOUSE_MOTORCOMPONENT_HPP

#include "Hardware/Component.hpp"

#include <cstdint>

namespace Maze {
	class MotorComponent : public Component {
	public:
		explicit MotorComponent(uint8_t pin1, uint8_t pin2, uint8_t pinPWM, uint8_t channel, bool reverse, const char* name);

		const char* name() const override {return _name;}

		void loop(double dilation) override;

		void setSpeed(double speed);
		double getSpeedTarget() const {return _speedTarget;}
		double getSpeedCurrent() const {return _speedCurrent;}

		bool isEnabled() const { return _enabled; }

	private:
		uint8_t _pin1;
		uint8_t _pin2;
		uint8_t _channel;
		bool _reverse;
		bool _enabled;

		double _speedTarget{};
		double _speedCurrent{};

		const char* _name;
	};
}

#endif //MICRO_MOUSE_MOTORCOMPONENT_HPP
