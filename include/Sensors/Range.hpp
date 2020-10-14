#ifndef MICRO_MOUSE_RANGE_HPP
#define MICRO_MOUSE_RANGE_HPP

#include <Wire.h>
#include <Adafruit_VL6180X.h>

namespace Maze {
	class Range {
	public:
		Range();
		~Range();

		void loop();
		float lux() const;
		uint8_t range() const;
		const char* message() const;

	private:
		bool _initialized = false;
		const char* _message = nullptr;
		float _lux = -1.0f;
		uint8_t _range = -1;
		Adafruit_VL6180X _sensor;
	};
}

#endif //MICRO_MOUSE_RANGE_HPP
