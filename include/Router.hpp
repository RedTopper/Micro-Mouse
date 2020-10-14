#ifndef ARDUINO_FEATHER_ROUTER_HPP
#define ARDUINO_FEATHER_ROUTER_HPP

#include <esp_http_server.h>
#include <memory>

namespace Maze {
	class Runner;
	class MouseController;
	class Components;
	class Router {
	public:
		explicit Router(Components& components);
		~Router();

		void router(Runner& runner) const;

	private:
		std::unique_ptr<MouseController> _mouse;

	};
}

#endif //ARDUINO_FEATHER_ROUTER_HPP
