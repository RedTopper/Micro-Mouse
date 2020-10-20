#ifndef ARDUINO_FEATHER_ROUTER_HPP
#define ARDUINO_FEATHER_ROUTER_HPP

#include <memory>
#include <WebServer.h>


namespace Maze {
	class Runner;
	class MovementController;
	class DataController;
	class Components;
	class Router {
	public:
		explicit Router(WebServer& server, Components& components);
		~Router();

		void router(WebServer& server) const;

	private:
		std::unique_ptr<MovementController> _movement;
		std::unique_ptr<DataController> _data;
	};
}

#endif //ARDUINO_FEATHER_ROUTER_HPP
