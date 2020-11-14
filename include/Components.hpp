#ifndef MICRO_MOUSE_COMPONENTS_HPP
#define MICRO_MOUSE_COMPONENTS_HPP

#include <memory>

namespace Maze {
	class RangeComponent;
	class MotorComponent;
	class EncoderComponent;
	class Runner;
	class Components {
	public:
		Components(Runner& runner, uint8_t pinEnable);
		~Components();

		void setup();
		void loop(double dilation);

		RangeComponent& rangeFront() {return *_rangeFront;}
		RangeComponent& rangeLeft() {return *_rangeLeft;}
		RangeComponent& rangeRight() {return *_rangeRight;}
		MotorComponent& motorLeft() {return *_motorLeft;}
		MotorComponent& motorRight() {return *_motorRight;}
		EncoderComponent& encoderLeft() {return *_encoderLeft;}
		EncoderComponent& encoderRight() {return *_encoderRight;}

		Runner& runner() const {return _runner;}

	private:
		Runner& _runner;

		std::unique_ptr<RangeComponent> _rangeFront;
		std::unique_ptr<RangeComponent> _rangeLeft;
		std::unique_ptr<RangeComponent> _rangeRight;

		std::unique_ptr<MotorComponent> _motorLeft;
		std::unique_ptr<MotorComponent> _motorRight;

		std::unique_ptr<EncoderComponent> _encoderLeft;
		std::unique_ptr<EncoderComponent> _encoderRight;

		uint8_t _pinEnable;
	};
}

#endif //MICRO_MOUSE_COMPONENTS_HPP
