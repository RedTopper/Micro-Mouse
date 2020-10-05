#include "Router.hpp"
#include "Utility.hpp"

namespace Maze {
	Router::Router(std::unique_ptr<Mouse> mouse) {
		_routes.push_back({
			.uri      = "/move/forward",
			.method   = HTTP_GET,
			.handler  = Mouse::dispatch,
			.user_ctx = mouse->context(&Mouse::forward)
		});

		_routes.push_back({
			.uri      = "/move/stop",
			.method   = HTTP_GET,
			.handler  = Mouse::dispatch,
			.user_ctx = mouse->context(&Mouse::stop)
		});
	}

	void Router::start(httpd_handle_t server) {
		for (auto i : _routes) {
			httpd_register_uri_handler(server, &i);
		}
	}
}
