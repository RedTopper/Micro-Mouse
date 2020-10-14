#ifndef ARDUINO_FEATHER_CONTROLLER_HPP
#define ARDUINO_FEATHER_CONTROLLER_HPP

#include <ArduinoJson.hpp>
#include <esp_http_server.h>

namespace Maze {
	class Components;
	class Controller {
	public:
		explicit Controller(Components& components);
		virtual ~Controller();

		virtual const char* name() = 0;

		esp_err_t send(httpd_req_t* r, ArduinoJson::DynamicJsonDocument doc, const char* func);

	protected:
		Components& _components;
	};
}

#endif //ARDUINO_FEATHER_CONTROLLER_HPP
