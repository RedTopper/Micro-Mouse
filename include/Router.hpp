#ifndef ARDUINO_FEATHER_ROUTER_HPP
#define ARDUINO_FEATHER_ROUTER_HPP

#include <ESPAsyncWebServer.h>

#include <memory>

namespace Maze {
	class Runner;
	class MovementController;
	class DataController;
	class Components;
	class Router {
	public:
		explicit Router(AsyncWebServer& server, Components& components);
		~Router();

		void router(AsyncWebServer& server) const;

	private:
		std::unique_ptr<MovementController> _movement;
		std::unique_ptr<DataController> _data;
	};
}

#endif //ARDUINO_FEATHER_ROUTER_HPP
