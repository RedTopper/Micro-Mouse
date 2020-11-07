#ifndef MICRO_MOUSE_RANGECOMPONENT_HPP
#define MICRO_MOUSE_RANGECOMPONENT_HPP

#include "Hardware/Component.hpp"

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
		bool readRangeNoWait(uint8_t &range);

		uint8_t internalRead8(uint16_t address);
		void internalWrite8(uint16_t address, uint8_t data);

		unsigned long getTime() const {return _timeLoop;}

	private:
		TwoWire* _internalWire = nullptr;
		State _state = State::IDLE;

		unsigned int _timeAbsolute{};
		unsigned int _timeLoop{};
	};

	class RangeComponent : public Component {
	public:
		RangeComponent(uint8_t pin, uint8_t address, const char* name);
		~RangeComponent();

		void loop(double dilation) override;

		const char* name() const override {return _name;}

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

		const char* _name;

		Adafruit_VL6180XInternal _sensor;
	};
}

#endif //MICRO_MOUSE_RANGECOMPONENT_HPP
