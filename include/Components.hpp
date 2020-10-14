#ifndef MICRO_MOUSE_COMPONENTS_HPP
#define MICRO_MOUSE_COMPONENTS_HPP

#include <memory>

namespace Maze {
	class Range;
	class Components {
	public:
		Components();
		~Components();

		void loop();

		Range& rangeFront() {return *_rangeFront;}

	private:
		std::unique_ptr<Range> _rangeFront;
	};
}

#endif //MICRO_MOUSE_COMPONENTS_HPP
