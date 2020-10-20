#include "Components.hpp"

#include "Hardware/Range.hpp"

namespace Maze {
	Components::Components() {
		_rangeFront = std::make_unique<Range>();
	}

	Components::~Components() = default;

	void Components::loop() {
		_rangeFront->loop();
	}
}