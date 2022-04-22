//
//  sinewave.hpp
//  sinewave
//
//  Created by @_hrkd on 2022/04/22.
//  
//

#ifndef sinewave_hpp
#define sinewave_hpp

#include <stdio.h>
#include "ofMain.h"

class sinewave : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
private:
    ofEasyCam cam;
    ofMesh mesh;
    ofPlanePrimitive plane;
    vector<glm::vec3> vertices;
    int size;
    int step;
};

#endif /* sinewave_hpp */
