#include "Router.hpp"

#include "Components.hpp"
#include "Controllers/DataController.hpp"
#include "Controllers/MovementController.hpp"
#include "Runner.hpp"

#include <WebServer.h>

namespace Maze {
	Router::Router(WebServer& server, Components& components) {
		// Create the needed controllers
		_movement = std::make_unique<MovementController>(server, components);
		_data = std::make_unique<DataController>(server, components);
	}

	Router::~Router() = default;

	void Router::router(WebServer& server) const {
		server.onNotFound([&]() {server.send(404, "text/plain", "Not Found");});
		server.on("/", [&]() {server.send(200, "text/plain", "Micro-Mouse");});

		// Add routes here
		server.on("/move/forward", HTTP_GET, [&](){_movement->forward();});
		server.on("/move/stop", HTTP_GET, [&](){_movement->stop();});
		server.on("/move", HTTP_GET, [&](){_movement->status();});

		server.on("/status", HTTP_GET, [&](){_data->status();});
	}
}
