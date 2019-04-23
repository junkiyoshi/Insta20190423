#pragma once
#include "ofMain.h"

class Agent {
public:

	Agent(glm::vec2 location);
	void update();
	void draw();
	bool is_dead();

private:

	glm::vec2 start_location;
	deque<glm::vec2> log;
	int life;
	int radius;
	int deg;
	int radius_step;
	int deg_step;
};