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
			AVAILABLE,
		};

	public:
		bool internalBegin(TwoWire *theWire = nullptr);
		bool readRangeNoWait(uint8_t &range, uint16_t timeout = 0);

		uint8_t internalRead8(uint16_t address);
		void internalWrite8(uint16_t address, uint8_t data);

		unsigned long getTime() const {return _timeLoop;}

	private:
		TwoWire* _internalWire = nullptr;
		State _state = State::IDLE;

		unsigned int _timeAbsolute;
		unsigned int _timeLoop;
	};

	class Range {
	public:
		Range(uint8_t pin, uint8_t address);
		~Range();

		void loop();

		const char* getMessage() const;
		uint8_t getRange() const;
		uint8_t getPin() const {return _pin;}
		unsigned int getTime() const {return _sensor.getTime();}

		bool boot();
		void disable() const {digitalWrite(_pin, LOW);}
		void enable() const {digitalWrite(_pin, HIGH);}

	private:
		bool _initialized = false;

		uint8_t _status = 255;
		uint8_t _range = 255;
		uint8_t _pin;
		uint8_t _address;

		Adafruit_VL6180XInternal _sensor;
	};
}

#endif //MICRO_MOUSE_RANGE_HPP
