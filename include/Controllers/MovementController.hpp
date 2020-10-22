#ifndef ARDUINO_FEATHER_MOUSECONTROLLER_HPP
#define ARDUINO_FEATHER_MOUSECONTROLLER_HPP

#include "Controller.hpp"

class AsyncWebServer;
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

		const char* name() override {return "MouseController";}
		static const char* getMovement(Movement movement);

		void forward(AsyncWebServerRequest* r);
		void stop(AsyncWebServerRequest* r);
		void status(AsyncWebServerRequest* r);

	private:
		Movement _movement = Movement::STOP;
	};
}

#endif //ARDUINO_FEATHER_MOUSECONTROLLER_HPP
