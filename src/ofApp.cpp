#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    //ofEnableDepthTest();
    //ofDisableSmoothing();
    
    coords.resize(4);
    
    colors.resize(3);
    colors[0].set(getOriginalColor(154, 80), getOriginalColor(69, 80), getOriginalColor(4, 80));
    colors[1] = ofColor::black;
    //colors[2] = ofColor::saddleBrown;
    colors[2].set(getOriginalColor(86, 80), getOriginalColor(79, 80), getOriginalColor(74, 80));
    // 86, 79, 74
    
    
    
    /*
    ofColor sourceColor;
    sourceColor.r = 188; // what should r g & b be?
    sourceColor.g = 120; //
    sourceColor.b = 32;  //
    sourceColor.a = 80;
    
    // to get to the values below?
    
    ofColor destinationColor;
    sourceColor.r = 188;
    sourceColor.g = 120;
    sourceColor.b = 32;
    */
    
    //X = (188 - (1-.31) * 255)/.31
    
    
    
    
    
    
}
int ofApp::getOriginalColor(int sourceValue, float alpha) {
    
    //X = (188 - (1-.31) * 255)/.31
    
    int origValue = (sourceValue - (1 - (alpha/100) * 255) / (alpha/100));
    
    return origValue;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(255);
    ofSeedRandom(mouseX * 1000);
    
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 12; j++) {
            ofPushMatrix();
            
            currentPosition = ofPoint(i * 100 + 100, j * 50 + 100);
            
            //ofSetColor(0);
            ofNoFill();
            
            
            
            int randomDistance = 50;
            
            // muter -- one stays the same
            // duplicater -- in th middle, we draw in stacks -- linear, maybe noise
            // at the edges, random increases -- linear
            // 3 colors, driven by noise?
            
            int numQuads = 1;
            float sinPos;
            if (currentPosition.x < ofGetWidth() / 2) {
                sinPos = sin(ofMap(currentPosition.x, 100, ofGetWidth() - 100, 0, 1));
                
                //numQuads = currentPosition.x / 50;
            } else if (currentPosition.x >= ofGetWidth() / 2) {
                sinPos = sin(ofMap(currentPosition.x, 100, ofGetWidth() - 100, 1, 0));
                //numQuads = (1000 - currentPosition.x) / 50;
            }
            
            numQuads = (sinPos * 10) * (sinPos * 10); // sin and square them out
            if (numQuads == 0) {
                numQuads = 1;
            }
            
            //float randFactor = (1/numQuads) * 100;
            float randFactor = 20;
            
            ofTranslate(currentPosition.x + ofRandom(-randFactor, randFactor), currentPosition.y + ofRandom(-randFactor, randFactor));
            
            
            /*cout << currentPosition.x;
            cout << ", ";
            cout << numQuads;
            cout << ", ";
            cout << ofGetWidth() / 2;
            cout << "\n";
            cout << sinPos;
            cout << "\n";*/
            
            for (int l = 0; l < numQuads; l++) {
                
                int muter = (int)ofRandom(0, 4);
                
                //ofColor color = colors[ofRandom(0, 3)];
                ofColor color;
                float noise = ofNoise(i*0.2, j*0.1);
                
                if (noise < 0.33) {
                    color = colors[0];
                } else if (noise < 0.66) {
                    color = colors[1];
                } else {
                    color = colors[2];
                }
                
                
                color.a = 80;
                
                
                drawQuad(muter, randomDistance, color);
            }
            
            /*coords[0] = ofPoint(0, 0);
            coords[1] = ofPoint(100, 0);
            coords[2] = ofPoint(100, 100);
            coords[3] = ofPoint(0, 100);
            
            for (int k = 0; k < 4; k++) {
                if (k != muter) {
                    coords[k].x += ofRandom(-randomDistance, randomDistance);
                    coords[k].y += ofRandom(-randomDistance, randomDistance);
                }
            }
            
            ofDrawLine(coords[0], coords[1]);
            ofDrawLine(coords[1], coords[2]);
            ofDrawLine(coords[2], coords[3]);
            ofDrawLine(coords[3], coords[0]);*/
            
            
            
            ofPopMatrix();
        }
    }
    
}

//---
void ofApp::drawQuad(int muter, int randomDistance, ofColor color) {
    coords[0] = ofPoint(0, 0);
    coords[1] = ofPoint(100, 0);
    coords[2] = ofPoint(100, 100);
    coords[3] = ofPoint(0, 100);
    
    for (int k = 0; k < 4; k++) {
        if (k != muter) {
            coords[k].x += ofRandom(-randomDistance, randomDistance);
            coords[k].y += ofRandom(-randomDistance, randomDistance);
        }
    }
    
    coords[1].y = coords[0].y; // make the top line straight always
    
    ofSetColor(color);
    
    ofSetLineWidth(3);
    
    ofDrawLine(coords[0], coords[1]);
    ofDrawLine(coords[1], coords[2]);
    ofDrawLine(coords[2], coords[3]);
    ofDrawLine(coords[3], coords[0]);
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
