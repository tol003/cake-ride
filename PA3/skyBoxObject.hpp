
#ifndef skyBox_hpp
#define skyBox_hpp

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/mat4x4.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <cmath>
#include <iostream>
#include <stdio.h>

#include "Window.hpp"

using namespace std;

class skyBoxObject{

public:
    
    
    //varaibles
    int cubeWidth;
    int cubeHeight;
    int indFaceGroup;
    int keyPressed;
    int mountainSky;
    int valleySky;
    int lagoonSky;
    int morningSky;
    float angle;
    glm::mat4 toWorld;
    GLuint VBO, VAO, EBO;
    
    //skybox texture ID
    GLuint textureID;
    
    //vectors
    vector<const char *> faces;
    vector<unsigned int> indices;
    
    //constructors
    skyBoxObject(unsigned int skyToRender);
    
    //functions
    void setSkyBox(GLuint &textureID, int width, int height);
    void skyBoxDraw(GLuint skyShaderProgram);
    
    void deleteSkyBox(GLuint &texture);
    
    void cameraRotate();
    void update();
};


#endif /* skyBox_hpp */
