#include "ofApp.h"

float rX =0;
float rY =0;
float rZ =0;
float dScaleX =1;
float dScaleY =1;
float dScaleZ =1;

ofFbo fbo;


//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableAlphaBlending();
    ofBackground(255,255,255);
    
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F);
    
    fbo.begin();
    ofClear(255,255,255, 0);
    fbo.end();
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    float time = ofGetElapsedTimef();
    rX = ofSignedNoise(time * 0.2, time*0.2, time*0.2)*200.0;
    rY = ofSignedNoise(time * 0.2)*200.0;
    rZ = ofSignedNoise(time*0.4)*200.0;
    dScaleX = 1 - ofNoise(time *0.1);
    dScaleY = 1-ofNoise(time*0.2);
    dScaleZ = 1 -ofNoise(time*0.3);
}

//--------------------------------------------------------------
void ofApp::draw(){
    fbo.begin();
    ofSetColor(255,255,255, 10); // background color with alpha  / change color for halo effect
    ofDrawRectangle(0,0, ofGetWidth(), ofGetHeight());
    
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    ofScale(dScaleX,dScaleY,dScaleZ);
    ofRotateX(rX);
    ofRotateY(rY);
    ofRotateZ(rZ);
    ofFill();
    ofSetColor(200,100,100);
    ofDrawLine(-20,850,20,650);
    ofPopMatrix();
    
    fbo.end();
    
    
    ofSetColor(255,255,255);  // always set the color before drawing the fbo
    fbo.draw(0,0);
    
    
    
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
