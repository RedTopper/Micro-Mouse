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
		void loop(int frequency);
		AsyncWebServer& server() {return *_server;}

        unsigned int getTimeCompute() const {return _timeCompute;}
        unsigned int getTimeLoop() const {return _timeLoop;}

	private:
		std::unique_ptr<AsyncWebServer> _server;
		std::unique_ptr<Router> _router;
		std::unique_ptr<Components> _components;

        unsigned long _timeAbsolute = 0;
        unsigned long _timeLoop = 0;
        unsigned long _timeCompute = 0;
	};
}

#endif //ARDUINO_FEATHER_RUNNER_HPP
