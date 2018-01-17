/************************************************************
************************************************************/
#include "ofApp.h"


/************************************************************
************************************************************/

/******************************
******************************/
ofApp::ofApp()
: t_LastCamUpdate(0)
, FrameRate(0)
{
}

/******************************
******************************/
ofApp::~ofApp()
{
}

//--------------------------------------------------------------
void ofApp::setup(){
	/********************
	********************/
	ofSetWindowTitle("BlackMagic");
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofSetWindowShape(WIDTH, HEIGHT);
	ofSetEscapeQuitsApp(false);
	
	ofEnableAlphaBlending();
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	// ofEnableBlendMode(OF_BLENDMODE_ADD);
	// ofEnableSmoothing();
	
	/********************
	********************/
	b_fullScreen = false;
	fbo.allocate(W_BLACKMAGIC, H_BLACKMAGIC, GL_RGBA);
	
	ofSetLogLevel(OF_LOG_VERBOSE);
	cam.setup(W_BLACKMAGIC, H_BLACKMAGIC, 30);
}

/******************************
******************************/
void ofApp::exit(){
	cam.close();
}

//--------------------------------------------------------------
void ofApp::update(){
	float now = ofGetElapsedTimef();
	
	if(cam.update()){
		float _FrameRate = 1 / (now - t_LastCamUpdate);
		float smoothing = 0.9;
		FrameRate = smoothing * FrameRate + (1 - smoothing) * _FrameRate;
		
		t_LastCamUpdate = now;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	/********************
	********************/
	fbo.begin();
		ofClear(0, 0, 0, 0);
		ofSetColor(255);
		cam.drawColor();
		// cam.drawYuv();
    fbo.end();
	
	/********************
	********************/
	ofBackground(0);
	ofSetColor(255);
	fbo.draw(0, 0, ofGetWidth(), ofGetHeight());
	
	/********************
	********************/
	char buf[BUF_SIZE];
	sprintf(buf, "%5.1f", FrameRate);
	
	ofSetColor(255, 0, 0, 255);
	ofDrawBitmapString(buf, 10, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch(key){
		case 'f':
			b_fullScreen = !b_fullScreen;
			
			if(b_fullScreen){
				ofSetFullscreen(true);
			}else{
				ofSetFullscreen(false);
				ofSetWindowShape(WIDTH, HEIGHT);
			}
			
			break;
	}
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
