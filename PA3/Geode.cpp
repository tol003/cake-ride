//
//  Geode.cpp
//  PA3
//
//  Created by Tong Lee on 5/4/16.
//  Copyright © 2016 Tong Lee. All rights reserved.
//

#include "Geode.hpp"

Geode::Geode(OBJObject * fromDraw){

    toDraw = fromDraw;
}

void Geode::update(glm::mat4 C, bool split){

    M = C;// * M;
    geoSplit = split;
}
void Geode::draw(GLuint shaderProgram, bool split){
    
    //toDraw -> toWorld = M;
    
    geoSplit = split;
    
    toDraw -> modernDraw(shaderProgram, M, geoSplit);
    
    //toDraw -> toWorld = glm::mat4(1.0f);
    
    
}