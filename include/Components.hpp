#ifndef MICRO_MOUSE_COMPONENTS_HPP
#define MICRO_MOUSE_COMPONENTS_HPP

#include <memory>

namespace Maze {
	class Range;
	class Motor;
	class Components {
	public:
		Components();
		~Components();

		void setup();
		void loop();

		Range& rangeFront() {return *_rangeFront;}
		Range& rangeLeft() {return *_rangeLeft;}
		Range& rangeRight() {return *_rangeRight;}
		Motor& motorLeft() {return *_motorLeft;}
		Motor& motorRight() {return *_motorRight;}

		unsigned int getTime() const {return _timeLoop;}

	private:
		std::unique_ptr<Range> _rangeFront;
		std::unique_ptr<Range> _rangeLeft;
		std::unique_ptr<Range> _rangeRight;

		std::unique_ptr<Motor> _motorLeft;
		std::unique_ptr<Motor> _motorRight;

		unsigned long _timeAbsolute;
		unsigned long _timeLoop;
	};
}

#endif //MICRO_MOUSE_COMPONENTS_HPP
