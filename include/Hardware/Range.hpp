#ifndef MICRO_MOUSE_RANGE_HPP
#define MICRO_MOUSE_RANGE_HPP

#include <Adafruit_VL6180X.h>

namespace Maze {
	class Adafruit_VL6180XInternal : public Adafruit_VL6180X {
		enum class State {
			IDLE,
			REQUEST,
			TRIGGER,
			WAIT,
			AVAILABLE
		};

	public:
		bool internalBegin(TwoWire *theWire = nullptr);
		bool readRangeNoWait(uint8_t &range, uint16_t timeout = 0);

		uint8_t internalRead8(uint16_t address);
		void internalWrite8(uint16_t address, uint8_t data);

	private:
		TwoWire* _internalWire = nullptr;
		State _state = State::IDLE;
		bool _ready = false;
		unsigned long _time = 0l;
	};

	class Range {
	public:
		explicit Range(uint16_t timeout = 0);
		~Range();

		void loop();
		uint8_t range() const;
		const char* message() const;

	private:
		bool _initialized = false;
		unsigned long _time = 0l;
		uint8_t _status = 255;
		uint8_t _range = 0;
		uint16_t _timeout = 0;
		Adafruit_VL6180XInternal _sensor;
	};
}

#endif //MICRO_MOUSE_RANGE_HPP
