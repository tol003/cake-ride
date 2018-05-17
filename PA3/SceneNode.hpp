
#ifndef SceneNode_hpp
#define SceneNode_hpp

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <iostream>
#include <stdio.h>



class SceneNode{
    
public:
    
    
    //constructors
    SceneNode();
    
    //functions
    virtual void update(glm::mat4 M, bool split) = 0;
    virtual void draw(GLuint shaderProgram, bool split) = 0;
};

#endif /* SceneNode_hpp */
