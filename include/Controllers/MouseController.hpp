#ifndef ARDUINO_FEATHER_MOUSECONTROLLER_HPP
#define ARDUINO_FEATHER_MOUSECONTROLLER_HPP

#include "Controller.hpp"
#include "Sensor.hpp"

namespace Maze {
	class MouseController : public Controller {
	public:
		enum class Movement {
			STOP,
			FORWARDS,
			BACKWARDS
		};

	public:
		explicit MouseController(Sensor* sensor);

		const char* name() override {return "MouseController";}

		esp_err_t forward(httpd_req_t *r);
		esp_err_t stop(httpd_req_t *r);
		esp_err_t query(httpd_req_t *r);


	private:
		Movement _movement = Movement::STOP;
		Sensor* _sensor = nullptr;
	};
}

#endif //ARDUINO_FEATHER_MOUSECONTROLLER_HPP
