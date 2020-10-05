#ifndef ARDUINO_FEATHER_ROUTER_HPP
#define ARDUINO_FEATHER_ROUTER_HPP

#include "Mouse.hpp"
#include "Utility.hpp"

#include <memory>
#include <esp_http_server.h>
#include <vector>

namespace Maze {
	class Router {
	public:
		explicit Router(std::unique_ptr<Mouse> mouse);
		void start(httpd_handle_t server);

	private:
		std::unique_ptr<Mouse> _mouse;
		std::vector<httpd_uri_t> _routes;
	};
}

#endif //ARDUINO_FEATHER_ROUTER_HPP
