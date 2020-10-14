#ifndef ARDUINO_FEATHER_RUNNER_HPP
#define ARDUINO_FEATHER_RUNNER_HPP

#include <functional>
#include <memory>
#include <esp_http_server.h>
#include <vector>

namespace Maze {
	typedef std::function<esp_err_t(httpd_req_t*)> Callable;

	class Router;
	class Components;
	class Runner {
	public:
		Runner();
		~Runner();

		void setup();
		void loop() const;
		void get(const char* route, const Callable& callable);
		static esp_err_t dispatch(httpd_req_t *r);

	private:
		httpd_handle_t _server = nullptr;
		std::unique_ptr<Router> _router;
		std::unique_ptr<Components> _components;
		std::vector<std::unique_ptr<Callable>> _callables;
	};
}

#endif //ARDUINO_FEATHER_RUNNER_HPP
