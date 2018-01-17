/************************************************************
************************************************************/
#pragma once

/************************************************************
************************************************************/
#include "ofMain.h"
#include "ofxBlackMagic.h"

/************************************************************
************************************************************/
class ofApp : public ofBaseApp{
	/****************************************
	****************************************/
	enum{
		BUF_SIZE = 512,
	};
	
	enum{
		WIDTH = 1280,
		HEIGHT = 720,
	};
	enum{
	//*
		W_BLACKMAGIC = 1920,
		H_BLACKMAGIC = 1080,
	/*/
		W_BLACKMAGIC = 1280,
		H_BLACKMAGIC = 720,
	// */
	};
	
	/****************************************
	****************************************/
	float t_LastCamUpdate;
	float FrameRate;
	
	ofxBlackMagic cam;
	ofFbo fbo;
	bool b_fullScreen;

public:
	/****************************************
	****************************************/
	ofApp();
	~ofApp();
	
	void setup();
	void update();
	void draw();
	void exit();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
};
