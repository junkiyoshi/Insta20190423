#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofNoFill();
	ofSetLineWidth(2);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	if (ofGetFrameNum() % 120 == 0) {

		for (int i = 0; i < 50; i++) {

			this->agents.push_back(Agent(glm::vec2()));
		}
	}

	for(int i = this->agents.size() - 1; i >= 0; i--){

		this->agents[i].update();

		if (this->agents[i].is_dead()) {

			this->agents.erase(this->agents.begin() + i);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	for (auto& agent : this->agents) {

		agent.draw();
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}