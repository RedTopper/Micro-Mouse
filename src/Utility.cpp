#include "Utility.hpp"

namespace Maze {
	const char* is(bool ok) {
		return ok ? "OK\r\n" : "Not OK\r\n";
	}

	double clamp(const double v, const double lo, const double hi) {
		return (v < lo) ? lo : (hi < v) ? hi : v;
	}
}
