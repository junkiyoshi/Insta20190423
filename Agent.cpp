#include "Agent.h"

//--------------------------------------------------------------
Agent::Agent(glm::vec2 location) {

	this->start_location = location;
	this->radius = 10;
	this->deg = ofRandom(360);
	this->life = 0;
}

//--------------------------------------------------------------
void Agent::update() {

	if (this->life % 15 == 0) {
	
		int r = ofRandom(4);
		switch (r){

		case 0:
		case 3:
			this->radius_step = 2;
			this->deg_step = 0;
			break;
		case 1:
			this->radius_step = 0;
			this->deg_step = 2;
			break;
		case 2:
			this->radius_step = 0;
			this->deg_step = -2;
			break;
		}
	}
	else {

		this->radius += this->radius_step;
		this->deg += this->deg_step;
	}

	auto location = this->start_location + glm::vec2(this->radius * cos(this->deg * DEG_TO_RAD), this->radius * sin(this->deg * DEG_TO_RAD));
	this->log.push_front(location);

	while (this->log.size() > 20) {

		this->log.pop_back();
	}

	this->life++;
}

//--------------------------------------------------------------
void Agent::draw() {

	ofBeginShape();
	for (int i = 0; i < this->log.size(); i++) {

		ofVertex(this->log[i]);
	}
	ofEndShape();
}

//--------------------------------------------------------------
bool Agent::is_dead() {

	return this->radius > 150;
}