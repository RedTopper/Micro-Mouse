#include "Controllers/Controller.hpp"

namespace Maze {
	Controller::Controller(Components& components) : _components(components) {}
	Controller::~Controller() = default;

	esp_err_t Controller::send(httpd_req_t* r, ArduinoJson::DynamicJsonDocument doc, const char* func) {
		doc["action"] = func;
		doc["controller"] = this->name();

		if (!doc.containsKey("response")) {
			doc["response"] = "ok";
		}

		httpd_resp_set_type(r, "application/json");
		httpd_resp_send(r, doc.as<String>().c_str(), -1);
		return ESP_OK;
	}


}