#include "Hardware/RangeComponent.hpp"

#include <Wire.h>

namespace Maze {
	RangeComponent::RangeComponent(uint8_t pin, uint8_t address, const char* name) :
			_pin(pin),
			_address(address),
			_name(name) {
		_sensor = Adafruit_VL6180XInternal();
		pinMode(pin, OUTPUT);
	}

	RangeComponent::~RangeComponent() = default;

	void RangeComponent::loop(double) {
        if (!_initialized) return;
		uint8_t range;
		if (_sensor.readRangeNoWait(range)) {
			_range = range;
			_status = _sensor.readRangeStatus();
		}
	}

	uint8_t RangeComponent::getRange() const {
		if (!_initialized) return 255;
		return _range;
	}

	const char* RangeComponent::getMessage() const {
		switch (_status) {
		case 255:
			return "Failed to initialize";
		case 0:
			return "OK";
		case VL6180X_ERROR_SYSERR_1:
		case VL6180X_ERROR_SYSERR_1 + 1:
		case VL6180X_ERROR_SYSERR_1 + 2:
		case VL6180X_ERROR_SYSERR_1 + 3:
		case VL6180X_ERROR_SYSERR_5:
			return "System Error";
		case VL6180X_ERROR_ECEFAIL:
			return "ECE failure";
		case VL6180X_ERROR_NOCONVERGE:
			return "No convergence";
		case VL6180X_ERROR_RANGEIGNORE:
			return "Ignoring range";
		case VL6180X_ERROR_SNR:
			return "Signal/Noise error";
		case VL6180X_ERROR_RAWUFLOW:
			return "Raw reading underflow";
		case VL6180X_ERROR_RAWOFLOW:
			return "Raw reading overflow";
		case VL6180X_ERROR_RANGEUFLOW:
			return "Range reading underflow";
		case VL6180X_ERROR_RANGEOFLOW:
			return "Range reading overflow";
		default:
			return "Unknown Error";
		}
	}

	bool RangeComponent::boot() {
		_initialized = _sensor.internalBegin();
		if (!_initialized) return false;
		_sensor.setAddress(_address);
		return true;
	}


	bool Adafruit_VL6180XInternal::readRangeNoWait(uint8_t& range) {
		switch (_state) {
		case State::IDLE:
			// initiate a read
			_state = State::REQUEST;
			_timeAbsolute = millis();
			return false;

		case State::REQUEST:
			// wait for device to be ready for range measurement
			if ((internalRead8(VL6180X_REG_RESULT_RANGE_STATUS) & 0x01u))
				_state = State::TRIGGER;
			return false;

		case State::TRIGGER:
			// Start a range measurement
			internalWrite8(VL6180X_REG_SYSRANGE_START, 0x01);
			_state = State::WAIT;
			return false;

		case State::WAIT:
			// wait for data to be available, Poll until bit 2 is set
			if ((internalRead8(VL6180X_REG_RESULT_INTERRUPT_STATUS_GPIO) & 0x04u))
				_state = State::AVAILABLE;
			return false;

		case State::AVAILABLE:
			// read & cleanup, flag data is there
			range = internalRead8(VL6180X_REG_RESULT_RANGE_VAL);
			internalWrite8(VL6180X_REG_SYSTEM_INTERRUPT_CLEAR, 0x07);
			_state = State::IDLE; // go back to Idle state
			_timeLoop = millis() - _timeAbsolute;
			return true;
		}

		return false;
	}

	uint8_t Adafruit_VL6180XInternal::internalRead8(uint16_t address) {
		_internalWire->beginTransmission(getAddress());
		_internalWire->write(address >> 8u);
		_internalWire->write(address);
		_internalWire->endTransmission();
		_internalWire->requestFrom(getAddress(), (uint8_t)1);
		return _internalWire->read();
	}

	void Adafruit_VL6180XInternal::internalWrite8(uint16_t address, uint8_t data) {
		_internalWire->beginTransmission(getAddress());
		_internalWire->write(address >> 8u);
		_internalWire->write(address);
		_internalWire->write(data);
		_internalWire->endTransmission();
	}

	boolean Adafruit_VL6180XInternal::internalBegin(TwoWire* theWire) {
		_internalWire = theWire ? theWire : &Wire;
		return Adafruit_VL6180X::begin(theWire);
	}
}
