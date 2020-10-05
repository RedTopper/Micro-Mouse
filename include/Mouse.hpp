#ifndef ARDUINO_FEATHER_MOUSE_HPP
#define ARDUINO_FEATHER_MOUSE_HPP

#include <esp_http_server.h>
#include <vector>
#include <memory>

namespace Maze {
	class Mouse;
	typedef esp_err_t(Mouse::* Request)(httpd_req_t*);

	class Mouse {
	public:
		class Dispatch {
		public:
			Dispatch(Mouse* mouse, Request request);
			Mouse* _mouse;
			Request _request;
		};

		static esp_err_t dispatch(httpd_req_t *r);
		Dispatch* context(Request request);

		esp_err_t forward(httpd_req_t *r);
		esp_err_t stop(httpd_req_t *r);

		std::vector<std::unique_ptr<Mouse::Dispatch>> _context;
	};
}

#endif //ARDUINO_FEATHER_MOUSE_HPP
