//
//  Geode.hpp
//  PA3
//
//  Created by Tong Lee on 5/4/16.
//  Copyright © 2016 Tong Lee. All rights reserved.
//

#ifndef Geode_hpp
#define Geode_hpp

#include <stdio.h>

//#include "Window.hpp"
#include "SceneNode.hpp"
#include "OBJObject.h"

class Geode: public SceneNode{

public:
    
    //variable
    glm::mat4 M;
    OBJObject * toDraw;
    bool geoSplit;
    
    //constructors
    Geode();
    Geode(OBJObject * fromDraw);
    
    //functions
    void update(glm::mat4 C, bool split);
    void draw(GLuint, bool split);
};

#endif /* Geode_hpp */
