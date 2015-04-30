//Example 2. An application to capture, display,
// and invert live video from a webcam
// This is ofApp.h

//New text here

#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

    ofVideoGrabber  myVideoGrabber;
    ofTexture    myTexture;
    
    unsigned char*  invertedVideoData;
    int camWidth;
    int camHeight;
    float effectMultiplier; // a modifier to mess with the negative subtraction
    
    
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
