
#ifndef MatrixTransform_hpp
#define MatrixTransform_hpp


#include <stdio.h>

#include "Group.hpp"


class MatrixTransform : public Group{

    
public:
    
    //matrices
    glm::mat4 M;
    
    
    //constructors
    MatrixTransform();
    MatrixTransform(glm::mat4 idMatrix);
    
    
    //functions
    void update(glm::mat4 C, bool split);
    void draw(GLuint shaderProgram, bool split);
};

#endif /* MatrixTransform_hpp */
