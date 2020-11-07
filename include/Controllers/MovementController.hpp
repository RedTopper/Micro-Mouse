#ifndef ARDUINO_FEATHER_MOUSECONTROLLER_HPP
#define ARDUINO_FEATHER_MOUSECONTROLLER_HPP

#include "Controller.hpp"

class AsyncWebServer;
class AsyncWebSocket;
namespace Maze {
	class MovementController : public Controller {
	public:
		explicit MovementController(Components& components) : Controller(components) {};
		~MovementController() override;

		enum class Movement {
			STOP,
			FORWARDS,
			BACKWARDS
		};

		const char* name() const override {return "MouseController";}
		static const char* getMovement(Movement movement);

		void forward(AsyncWebServerRequest* r);
		void stop(AsyncWebServerRequest* r);
		void status(AsyncWebServerRequest* r);

		void socket(AsyncWebSocketClient* client, AwsEventType type, void* arg, uint8_t* data, size_t len);

	private:
		Movement _movement = Movement::STOP;

		void move(ArduinoJson::DynamicJsonDocument& request);
	};
}

#endif //ARDUINO_FEATHER_MOUSECONTROLLER_HPP
