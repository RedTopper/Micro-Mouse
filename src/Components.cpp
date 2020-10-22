#include "Components.hpp"

#include "Hardware/Range.hpp"
#include "Hardware/Motor.hpp"

namespace Maze {
	Components::Components() {
		_rangeFront = std::make_unique<Range>();
		_motorLeft = std::make_unique<Motor>(33, 0);
		_motorRight = std::make_unique<Motor>(27, 1);
	}

	Components::~Components() = default;

	void Components::loop() {
		_rangeFront->loop();
	}
}