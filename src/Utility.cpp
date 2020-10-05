#include "Utility.hpp"

namespace Maze {
	const char* is(bool ok) {
		return ok ? "OK\r\n" : "Not OK\r\n";
	}
}
