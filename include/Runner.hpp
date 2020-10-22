#ifndef ARDUINO_FEATHER_RUNNER_HPP
#define ARDUINO_FEATHER_RUNNER_HPP

#include <functional>
#include <memory>
#include <vector>

class AsyncWebServer;

namespace Maze {
	class Router;
	class Components;
	class Runner {
	public:
		Runner();
		~Runner();

		void setup();
		void loop() const;
		AsyncWebServer& server() {return *_server;}

	private:
		std::unique_ptr<AsyncWebServer> _server;
		std::unique_ptr<Router> _router;
		std::unique_ptr<Components> _components;
	};
}

#endif //ARDUINO_FEATHER_RUNNER_HPP
