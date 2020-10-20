#ifndef MICRO_MOUSE_DATACONTROLLER_HPP
#define MICRO_MOUSE_DATACONTROLLER_HPP

#include "Controller.hpp"

class WebServer;
namespace Maze {
	class DataController : public Controller {
	public:
		explicit DataController(WebServer& server, Components& components) : Controller(server, components) {};
		~DataController() override;

		const char* name() override {return "DataController";}

		void status();
	};
}

#endif //MICRO_MOUSE_DATACONTROLLER_HPP
