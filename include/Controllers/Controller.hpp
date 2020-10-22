#ifndef ARDUINO_FEATHER_CONTROLLER_HPP
#define ARDUINO_FEATHER_CONTROLLER_HPP

#include <ArduinoJson.hpp>
#include <ESPAsyncWebServer.h>

namespace Maze {
	class Components;
	class Controller {
	public:
		explicit Controller(Components& components);
		virtual ~Controller();

		virtual const char* name() = 0;

		void send(int status, AsyncWebServerRequest* request, ArduinoJson::DynamicJsonDocument document, const char* functionName);

	protected:
		Components& _components;
	};
}

#endif //ARDUINO_FEATHER_CONTROLLER_HPP
