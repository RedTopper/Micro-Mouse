#include "Runner.hpp"

#include <Arduino.h>

Maze::Runner* runner;

void setup() {
	Serial.begin(115200);
	Serial.printf("[Main:setup] Serial Connected!\r\n");
	runner = new Maze::Runner();
	runner->setup();
}

void loop() {
	runner->loop();
}
