#include "Router.hpp"

#include "Components.hpp"
#include "Controllers/DataController.hpp"
#include "Controllers/MovementController.hpp"

#include <ESPAsyncWebServer.h>

using Request = AsyncWebServerRequest;

namespace Maze {
	Router::Router(AsyncWebServer& server, Components& components) : _server(server) {
		// Create the needed controllers
		_movement = std::make_unique<MovementController>(components);
		_data = std::make_unique<DataController>(components);
		_socket = std::make_unique<AsyncWebSocket>("/ws");
	}

	Router::~Router() = default;

	void Router::router() {
		auto& server = _server;
		auto& socket = *_socket;

		server.onNotFound([&](Request *r) {r->send(404, "text/plain", "Not Found");});
		server.on("/", [&](Request *r) {r->send(200, "text/plain", "Micro-Mouse");});

		// Add routes here
		server.on("/move/forward", HTTP_GET, [&](Request* r){
			_movement->forward(r);
		});

		server.on("/move/stop", HTTP_GET, [&](Request* r){
			_movement->stop(r);
		});

		server.on("/move", HTTP_GET, [&](Request* r){
			_movement->status(r);
		});

		server.on("/status", HTTP_GET, [&](Request* r){
			_data->status(r);
		});

		socket.onEvent([&](AsyncWebSocket*, AsyncWebSocketClient* client, AwsEventType type, void* arg, uint8_t* data, size_t len) {
			_movement->socket(client, type, arg, data, len);
		});

		server.addHandler(_socket.get());
	}
}
