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

		void loop();

		Range& rangeFront() {return *_rangeFront;}
		Motor& motorLeft() {return *_motorLeft;}
		Motor& motorRight() {return *_motorRight;}

	private:
		std::unique_ptr<Range> _rangeFront;
		std::unique_ptr<Motor> _motorLeft;
		std::unique_ptr<Motor> _motorRight;
	};
}

#endif //MICRO_MOUSE_COMPONENTS_HPP
