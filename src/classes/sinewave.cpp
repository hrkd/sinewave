//
//  sinewave.cpp
//  sinewave
//
//  Created by @_hrkd on 2022/04/22.
//  
//

#include "sinewave.hpp"
void sinewave::setup(){
    size = 500;
    step = 50;

    plane.set(size,size,step,step);
    mesh = plane.getMesh();
    vertices = mesh.getVertices();
//    ofColor col(10);
//    mesh.addColor(col);
    ofBackground(0,0,0);
    glPointSize(2);
}

void sinewave::update(){
    float scale = 50.0;
    float freq = 0.05;
    float speed = 2;
    for(int i=0;i<vertices.size();i++){
        glm::vec3 pos = vertices[i];
        int centerPoint = step / 2;
        glm::vec3 center = vertices[vertices.size() / step * centerPoint + centerPoint];

        //distance
        float dist = ofDist(pos.x, pos.y, center.x, center.y);

        //attenuation
        float att = fmax(ofMap(size/2 - dist, 0, size/2, 0, 1),0);

        float z = sin(dist * freq + ofGetElapsedTimef() * speed) * scale * att;

        float noize = ofNoise(pos.x/step,pos.y/step,ofGetElapsedTimef()*speed)*scale;

        mesh.setVertex(i, glm::vec3(pos.x,pos.y,z));
    }
}
void sinewave::draw(){
    cam.begin();
    ofRotateXDeg(-60);
    ofRotateZDeg(20);
    ofTranslate(0, 0, 20);
    mesh.drawVertices();
//    mesh.drawWireframe();
    cam.end();
}
