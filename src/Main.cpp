#include "Runner.hpp"

#include <Arduino.h>

Maze::Runner* runner;

void setup() {
	runner = new Maze::Runner();
	runner->setup();
}

void loop() {
	runner->loop();
}