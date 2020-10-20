#ifndef ARDUINO_FEATHER_MOUSECONTROLLER_HPP
#define ARDUINO_FEATHER_MOUSECONTROLLER_HPP

#include "Controller.hpp"

class WebServer;
namespace Maze {
	class MovementController : public Controller {
	public:
		explicit MovementController(WebServer& server, Components& components) : Controller(server, components) {};
		~MovementController() override;

		enum class Movement {
			STOP,
			FORWARDS,
			BACKWARDS
		};

		const char* name() override {return "MouseController";}
		static const char* getMovement(Movement movement);

		void forward();
		void stop();
		void status();

	private:
		Movement _movement = Movement::STOP;
	};
}

#endif //ARDUINO_FEATHER_MOUSECONTROLLER_HPP
