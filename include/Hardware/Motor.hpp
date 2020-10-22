#ifndef MICRO_MOUSE_MOTOR_HPP
#define MICRO_MOUSE_MOTOR_HPP

namespace Maze {
	class Motor {
	public:
		explicit Motor(int pin, int channel);

		void speed(double speed) const;

	private:
		int _channel;
	};
}

#endif //MICRO_MOUSE_MOTOR_HPP
