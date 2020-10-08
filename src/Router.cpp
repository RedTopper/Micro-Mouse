#include "Controllers/Controller.hpp"
#include "Router.hpp"
#include "Runner.hpp"

#include <ArduinoJson.hpp>

namespace Maze {
	Router::Router() {
		// Create the needed controllers
		_mouse = std::make_unique<MouseController>();
	}

	void Router::router(Runner* runner) const {
		// Add routes here
		runner->get("/move/forward", [&](httpd_req_t *r){return _mouse->forward(r);});
		runner->get("/move/stop", [&](httpd_req_t *r){return _mouse->stop(r);});
		runner->get("/move", [&](httpd_req_t *r){return _mouse->query(r);});
	}
}
