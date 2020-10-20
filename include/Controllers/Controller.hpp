#ifndef ARDUINO_FEATHER_CONTROLLER_HPP
#define ARDUINO_FEATHER_CONTROLLER_HPP

#include <ArduinoJson.hpp>

class WebServer;
namespace Maze {
	class Components;
	class Controller {
	public:
		Controller(WebServer& server, Components& components);
		virtual ~Controller();

		virtual const char* name() = 0;

		void send(int status, ArduinoJson::DynamicJsonDocument doc, const char* func);

	protected:
		WebServer& _server;
		Components& _components;
	};
}

#endif //ARDUINO_FEATHER_CONTROLLER_HPP
