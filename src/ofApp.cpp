// Example 2. An application to capture, invert
// and display live video from a webcam.
// This is ofApp.cpp

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // Set capture dimension of 320x240, a common video size.
    camWidth  = 640;
    camHeight  = 480;
    
    //Open an ofVideoGrabber for the default camera
    myVideoGrabber.initGrabber (camWidth,camHeight);
    
    // Create resources to store and display another copy of the data
    invertedVideoData = new unsigned char [camWidth*camHeight*3];
    myTexture.allocate (camWidth,camHeight, GL_RGB);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // Ask the grabber to refresh its data
    myVideoGrabber.update();
    
    // Initialise the effectMultiplier factor
    effectMultiplier = ofGetFrameNum() / 2;
    cout << effectMultiplier << endl; // Send the value of effectMultiplier to the console
    
    // If the grabber indeed has gresh data,
    if (myVideoGrabber.isFrameNew()){
        
        // Obtain a pointer to the grabber's image data.
        unsigned char* pixelData = myVideoGrabber.getPixels();
        
        // For every byte of the new RGB image data,
        int nTotalByte = camWidth*camHeight*3;
        for (int i=0; i<nTotalByte; i++){
            
            // PixelData[i] is the i'th byte of the image;
            // Subtract it from 255, to make a "photo negative"
            // Add in the multiplier to reveal how the image is being updated
            // colour by colour in the application
            // Change the sign to - to reverse direction of colour flow
            
            invertedVideoData[i]= 255 - pixelData[i] + effectMultiplier;
            }
        
        // Now stash the inverted data in an ofTexture
        myTexture.loadData (invertedVideoData, camWidth,camHeight, GL_RGB);
    }
    }

        
        

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(  100,100,100);
    ofSetColor(  255,255,255);
    
    // Draw the grabber, and next to it, the "negative" ofTexture.
    myVideoGrabber.draw( 10,10);
    myTexture.draw( 640, 10);
    
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
