#include "Sensors/Range.hpp"

namespace Maze {
	Range::Range() {
		_sensor = Adafruit_VL6180X();
		_initialized = _sensor.begin();
	}

	Range::~Range() = default;

	void Range::loop() {
		if (!_initialized) {
			_message = "Failed to initialize";
			return;
		}

		_lux = _sensor.readLux(VL6180X_ALS_GAIN_5);
		_range = _sensor.readRange();
		uint8_t status = _sensor.readRangeStatus();

		Serial.printf("%d ", _range);

		if ((status >= VL6180X_ERROR_SYSERR_1) && (status <= VL6180X_ERROR_SYSERR_5)) {
			_message = "System error";
		}
		else if (status == VL6180X_ERROR_ECEFAIL) {
			_message = "ECE failure";
		}
		else if (status == VL6180X_ERROR_NOCONVERGE) {
			_message = "No convergence";
		}
		else if (status == VL6180X_ERROR_RANGEIGNORE) {
			_message = "Ignoring range";
		}
		else if (status == VL6180X_ERROR_SNR) {
			_message = "Signal/Noise error";
		}
		else if (status == VL6180X_ERROR_RAWUFLOW) {
			_message = "Raw reading underflow";
		}
		else if (status == VL6180X_ERROR_RAWOFLOW) {
			_message = "Raw reading overflow";
		}
		else if (status == VL6180X_ERROR_RANGEUFLOW) {
			_message = "Range reading underflow";
		}
		else if (status == VL6180X_ERROR_RANGEOFLOW) {
			_message = "Range reading overflow";
		}
	}

	float Range::lux() const {
		if (!_initialized) return -1;
		return _lux;
	}

	uint8_t Range::range() const {
		if (!_initialized) return -1;
		return _range;
	}

	const char* Range::message() const {
		return _message;
	}
}