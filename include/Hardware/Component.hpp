#ifndef MICRO_MOUSE_COMPONENT_HPP
#define MICRO_MOUSE_COMPONENT_HPP

namespace Maze {
	class Component  {
	public:
		Component();
		virtual ~Component();

		virtual const char* name() const = 0;
		virtual void loop(double dilation) = 0;
	};
}

#endif //MICRO_MOUSE_COMPONENT_HPP
