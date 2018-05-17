#ifndef OBJOBJECT_H
#define OBJOBJECT_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/mat4x4.hpp>
#include <glm/glm.hpp>
#include <vector>
#include <cmath>
#include <iostream>



class OBJObject
{
public:
    std::vector<unsigned int> indices;
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec3> normals;
    glm::mat4 toWorld;
    GLuint VAO, VBO, EBO, NBO;
    GLFWwindow * windowPtr;

	
    int count = 0;
    float size;
    float angle;
    float avgX = 0.0f;
    float avgY = 0.0f;
    float avgZ = 0.0f;
    float minX = -INFINITY;
    float maxX = INFINITY;
    float minY = -INFINITY;
    float maxY = INFINITY;
    float minZ = -INFINITY;
    float maxZ = INFINITY;
    int lightOn = 1;
    bool lightMovement;
    bool mouseRButton = false;
    bool splitscreen;
   
    /*inserted variables for PA2*/
    double lastX = INFINITY;
    double lastY = INFINITY;
    glm::vec3 lightPos = glm::vec3(0.0f, 0.0f, -20.0f);
    float yValue;
    
    //material data
    glm::vec3 ambientMat;
    glm::vec3 diffuseMat;
    glm::vec3 specMat;
    float shininess;
    
    //constructors
    OBJObject(const char* filepath);
    OBJObject();

	void parse(const char* filepath);
    void draw();
    void modernDraw(GLuint shaderProgram, glm::mat4 M, bool split);
    void update();
    void spin(float);
    void objManipulate(int, int);
    void bindMaterial(GLuint);
    void mouseLight();
    glm::vec3 getDirections(glm::vec3);
    void setSplitScreen(bool split);
};


#endif