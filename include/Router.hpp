#ifndef ARDUINO_FEATHER_ROUTER_HPP
#define ARDUINO_FEATHER_ROUTER_HPP

#include "Controllers/MouseController.hpp"
#include "Sensor.hpp"

#include <esp_http_server.h>
#include <memory>
#include <vector>

namespace Maze {
	typedef std::function<esp_err_t(httpd_req_t*)> Callable;

	class Runner;
	class Router {
	public:
		Router(Sensor* sensor);
		void router(Runner* runner) const;

	private:
		std::unique_ptr<MouseController> _mouse = nullptr;

	};
}

#endif //ARDUINO_FEATHER_ROUTER_HPP
