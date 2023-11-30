#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(255);
    ofSetFrameRate(60);
    
    vidGarden.load("movies/garden_portal.mov");
    vidGarden.play();
   
    spacingX = 10;
    spacingY = 10;
    startPosX = spacingX/2;
    startPosY = spacingY/2;
    ofSetRectMode(OF_RECTMODE_CENTER);

}

//--------------------------------------------------------------
void ofApp::update(){
    vidGarden.update();
    pixels = vidGarden.getPixels();
}

//--------------------------------------------------------------
void ofApp::draw(){
    //vidGarden.draw(0,0,ofGetWidth(),ofGetHeight());
    
    
    
    for (int i = 0; i < ofGetWidth() / spacingX; i++) // x+= 1
    {
        for (int j = 0; j < ofGetHeight() / spacingY; j++) //y+= 1
        {
            int locX = startPosX + i * spacingX;
            int locY = startPosY + j * spacingY;
            
            ofPushMatrix();
        
            ofColor c = pixels.getColor(locX,locY);
            
            int brightness = c.getBrightness();
            
           
            
            
            int maxSize = 50;
            float radius = ofMap(brightness, 0, 255,maxSize, 0);
            
            ofMap(brightness, 0, 255,maxSize, 0);
           
            
            if (radius <= 50 && radius > 40) {
                
                ofFill();
                
                ofColor r = c;
                ofColor b = ofColor(ofRandom(255),0,0,ofRandom(50));
                b.lerp(r, 0.5);
                ofSetColor(b.lerp(r, 0.1));
                
                ofSetCircleResolution(6);
                
                ofDrawCircle(locX, locY, radius/3, radius/3);
                
                ofNoFill();
                ofSetColor(255,0,0);
                ofSetLineWidth(radius/25);
                
                ofDrawCircle(locX, locY, radius/3, radius/3);
            }
            if (radius < 40 && radius > 30) {
                
                ofFill();
                
                ofColor r = c;
                ofColor b = ofColor(0,ofRandom(255),0,ofRandom(50));
                b.lerp(r, 0.5);
                ofSetColor(b.lerp(r, 0.1));
                
                ofSetCircleResolution(5);
                
                ofDrawCircle(locX, locY, radius/3, radius/3);
                
                ofNoFill();
                ofSetColor(0,255,0);
                
                ofSetLineWidth(radius/25);
                
                ofDrawCircle(locX, locY, radius/3, radius/3);
            }
            if (radius < 30) {
                
                ofFill();
                
                ofColor r = c;
                ofColor b = ofColor(0,0,ofRandom(255),ofRandom(50));
                b.lerp(r, 0.1);
                ofSetColor(b.lerp(r, 0.5));
                
                ofSetCircleResolution(4);
                
                ofDrawCircle(locX, locY, radius/2, radius/2);
                
                ofNoFill();
                ofSetColor(0,0,255);
                ofSetLineWidth(radius/25);
                
                ofDrawCircle(locX, locY, radius/2, radius/2);
            }
            
//
            
            ofPopMatrix();
        }
        
    }
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
