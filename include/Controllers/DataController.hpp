#ifndef MICRO_MOUSE_DATACONTROLLER_HPP
#define MICRO_MOUSE_DATACONTROLLER_HPP

#include "Controller.hpp"

class WebServer;
namespace Maze {
	class DataController : public Controller {
	public:
		explicit DataController(Components& components) : Controller(components) {};
		~DataController() override;

		const char* name() const override {return "DataController";}

		void status(AsyncWebServerRequest* r);
	};
}

#endif //MICRO_MOUSE_DATACONTROLLER_HPP
