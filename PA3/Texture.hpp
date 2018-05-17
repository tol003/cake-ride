
#ifndef Texture_hpp
#define Texture_hpp

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/mat4x4.hpp>
#include <glm/glm.hpp>
#include <vector>
#include <cmath>
#include <iostream>
#include <stdio.h>


using namespace std;

class Texture{
    
public:
    
    //variables
    static unsigned int indFaceGroup;
    
    
    //vectors
    vector<unsigned char *> faces;
    
    //constructors
    Texture(const char * filename, int &width, int &height, GLuint textureID, unsigned int i);
    
    Texture();
    
    
    //functions
    unsigned char * loadPPM(const char * filename, int &width, int &height);
    void loadTexture(const char * filename, unsigned int i);
    void setParameters();
    void pushFaces(vector<const char*> &face, const char * filename);
};

#endif /* Texture_hpp */
