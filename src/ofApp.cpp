#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	wavePhase = 0;
	
	ofSoundStreamSettings settings;
	settings.numOutputChannels = 4;
	settings.sampleRate = 44100;
	settings.bufferSize = 512;
	settings.numBuffers = 4;
	settings.setOutListener(this);
	soundStream.setup(settings);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------
void ofApp::audioOut(ofSoundBuffer &outBuffer) {

	// base frequency of the lowest sine wave in cycles per second (hertz)
	float frequency = 440;
	
	// mapping frequencies from Hz into full oscillations of sin() (two pi)
	float wavePhaseStep = (frequency / outBuffer.getSampleRate()) * TWO_PI;
	float positionPhaseStep = TWO_PI / outBuffer.getSampleRate(); 
	
	for(size_t i = 0; i < outBuffer.getNumFrames(); i++) {
		
		float sample = sin(wavePhase);
		sample *= 0.5;
	
		outBuffer.getSample(i, 0) = sample * ((sin(positionPhase) + 1) * 0.1);
		outBuffer.getSample(i, 1) = sample * ((cos(positionPhase) + 1) * 0.1);
		outBuffer.getSample(i, 2) = sample * (-(sin(positionPhase) + 1) * 0.1);
		outBuffer.getSample(i, 3) = sample * (-(cos(positionPhase) + 1) * 0.1);
		
		wavePhase += wavePhaseStep;
		positionPhase += positionPhaseStep;
	}
}
