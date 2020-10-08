#ifndef ARDUINO_FEATHER_RUNNER_HPP
#define ARDUINO_FEATHER_RUNNER_HPP

#include "Controllers/MouseController.hpp"
#include "Router.hpp"

#include <esp_http_server.h>

namespace Maze {
	class Runner {
	public:
		void setup();
		void loop();
		void get(const char* route, const Callable& callable);
		static esp_err_t dispatch(httpd_req_t *r);

		httpd_handle_t _server = nullptr;
		std::unique_ptr<Router> _router = nullptr;
		std::vector<std::unique_ptr<Callable>> _callables;
	};
}

#endif //ARDUINO_FEATHER_RUNNER_HPP
