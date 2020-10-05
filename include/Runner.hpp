#ifndef ARDUINO_FEATHER_RUNNER_HPP
#define ARDUINO_FEATHER_RUNNER_HPP

#include "Router.hpp"

#include <esp_http_server.h>

namespace Maze {
	class Runner {
	public:
		void setup();
		void loop();

		httpd_handle_t _server = nullptr;
		std::unique_ptr<Router> _router = nullptr;
	};
}

#endif //ARDUINO_FEATHER_RUNNER_HPP
