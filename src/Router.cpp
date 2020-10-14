#include "Router.hpp"

#include "Controllers/MouseController.hpp"
#include "Sensors/Range.hpp"
#include "Components.hpp"
#include "Runner.hpp"

namespace Maze {
	Router::Router(Components& components) {
		// Create the needed controllers
		_mouse = std::make_unique<MouseController>(components);
	}

	Router::~Router() = default;

	void Router::router(Runner& runner) const {
		// Add routes here
		runner.get("/move/forward", [&](httpd_req_t *r){return _mouse->forward(r);});
		runner.get("/move/stop", [&](httpd_req_t *r){return _mouse->stop(r);});
		runner.get("/move", [&](httpd_req_t *r){return _mouse->query(r);});
	}
}
