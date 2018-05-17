//
//  MatrixTransform.cpp
//  PA3
//
//  Created by Tong Lee on 5/4/16.
//  Copyright © 2016 Tong Lee. All rights reserved.
//

#include "MatrixTransform.hpp"
#include "glm/ext.hpp"

MatrixTransform::MatrixTransform(){

}

MatrixTransform::MatrixTransform(glm::mat4 idMatrix){
    
    M = idMatrix;
}

void MatrixTransform::update(glm::mat4 C, bool split){

    
    //M = C;// * M;
    
    //cerr << "Value of maxtrix in transMatrix update is: " << glm::to_string(mNew) << endl;
    
    Group::update(C * M, split);
}
void MatrixTransform::draw(GLuint shaderProgram, bool split){
    
    Group::draw(shaderProgram, split);

}