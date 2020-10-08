#ifndef ARDUINO_FEATHER_MOUSECONTROLLER_HPP
#define ARDUINO_FEATHER_MOUSECONTROLLER_HPP

#include "Controller.hpp"

namespace Maze {
	class MouseController : public Controller {
	public:
		enum class Movement {
			STOP,
			FORWARDS,
			BACKWARDS
		};

	public:
		const char* name() override {return "MouseController";}

		esp_err_t forward(httpd_req_t *r);
		esp_err_t stop(httpd_req_t *r);
		esp_err_t query(httpd_req_t *r);


	private:
		Movement _movement = Movement::STOP;
	};
}

#endif //ARDUINO_FEATHER_MOUSECONTROLLER_HPP
