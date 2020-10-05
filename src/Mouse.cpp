#include "Mouse.hpp"

#include <Arduino.h>

namespace Maze {
	Mouse::Dispatch::Dispatch(Mouse* mouse, Request request) {
		_mouse = mouse;
		_request = request;
	}

	esp_err_t Mouse::dispatch(httpd_req_t *r) {
		Serial.printf("[Mouse:dispatch] Going to dispatch...\r\n");
		auto* func = static_cast<Dispatch*>(r->user_ctx);
		auto mouse = func->_mouse;
		auto request = func->_request;
		Serial.printf("[Mouse:dispatch] ctx: %p, _mouse: %p, _request: %p...\r\n", func, mouse, static_cast<void*>(request));
		Serial.printf("[Mouse:dispatch] Dispatching...\r\n");
		return (mouse->*request)(r);
	}

	Mouse::Dispatch* Mouse::context(Request request) {
		Serial.printf("[Mouse:context] Adding context.\r\n");
		_context.push_back(std::make_unique<Dispatch>(this, request));
		return _context.back().get();
	}

	esp_err_t Mouse::forward(httpd_req_t* r) {
		Serial.printf("[Mouse:forward] Forward march!\r\n");
		httpd_resp_set_hdr(r, "Content-Type", "text/json");
		httpd_resp_send(r, "{ok: 'ok'}", -1);
		return ESP_OK;
	}

	esp_err_t Mouse::stop(httpd_req_t* r) {
		Serial.printf("[Mouse:stop] And halt!\r\n");
		httpd_resp_set_hdr(r, "Content-Type", "text/json");
		httpd_resp_send(r, "{ok: 'ok'}", -1);
		return ESP_OK;
	}
}
