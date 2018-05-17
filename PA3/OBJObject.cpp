#include <iostream>
#include <stdio.h>

#include "OBJObject.h"
#include "Window.hpp"

#define SHIFT_X 58

using namespace std;

double currentX;
double currentY;
double posX;
double posY;
double posXNext;
double posYNext;
char stuff[BUFSIZ];

int faceCount = 0;
int verticeCount = 0;
int normalCount = 0;

//float angle;
float velocity;
float fTransX;
float fTransY;

glm::vec3 normalVec;
glm::vec3 lastPosVec;
glm::vec3 currentPosVec;
glm::vec3 directVec;
GLFWwindow * winAccessPtr;


OBJObject::OBJObject(const char *filepath)
{
	this -> toWorld = glm::mat4(1.0f);
    this -> angle = 0.0f;
	parse(filepath);
    
    // Generate arrays
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glGenBuffers(1, &NBO);
    
    glBindVertexArray(VAO);
    
    //vertices data
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * vertices.size(), vertices.data(), GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    
    //normals data
    glBindBuffer(GL_ARRAY_BUFFER, NBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * normals.size(), normals.data(), GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    
    //indices data
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(),indices.data(),GL_STATIC_DRAW);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    glBindVertexArray(0);
}

void OBJObject::parse(const char *filepath) 
{
	//TODO parse the OBJ file
	// Populate the face indices, vertices, and normals vectors with the OBJ Object data
    FILE * fp;
    unsigned int a, c, d, an, cn, dn;
    float x, y, z;
    float r, g, b;
    float dimX = 0;
    float dimY = 0;
    float dimZ = 0;
    float maxDim = 0;

    int ch1, ch2;
    
    fp = fopen(filepath, "rb");
    
    if (fp == NULL){
        cerr << "Error loading file" << endl;
        
        exit(EXIT_FAILURE);
    }
    
    while (true){
        
        ch1 = fgetc(fp);
        
        if (ch1 == '\n'){
            
            ch1 = fgetc(fp);
        }
        
        ch2 = fgetc(fp);
        
        if(ch1 == EOF || ch2 == EOF){
            
            break;
        }
        
        if (ch1 == 'v' && ch2 == ' '){
            
            fscanf(fp, "%f %f %f" /*%f %f %f*/, &x, &y, &z/*, &r, &g, &b*/);
            
            if(minX == -INFINITY || x < minX){
            
                minX = x;
            }
            
            if(maxX == INFINITY || x > maxX){
            
                maxX = x;
            }
            
            if(minY == -INFINITY || y < minY){
                
                minY = y;
            }
            
            if(maxY == INFINITY || y > maxY){
                
                maxY = y;
            }
            
            if(minZ == -INFINITY || z < minZ){
                
                minZ = z;
            }
            
            if(maxZ == INFINITY || z > maxZ){
                
                maxZ = z;
            }
            
            vertices.push_back(glm::vec3(x, y, z));
            
            verticeCount++;
        }
        
        else if (ch1 == 'v' && ch2 == 'n'){
            
            fscanf(fp, "%f %f %f", &x, &y, &z);
            normals.push_back(glm::normalize(glm::vec3(x, y, z)));
            
            normalCount++;
        }
        
        else if(ch1 == 'f' && ch2 == ' '){
        
            fscanf(fp, "%d//%d %d//%d %d//%d", &a, &an, &c, &cn, &d, &dn);
            
            /*cerr << "Value of a: " << a << ". Value of c: " << c << ". Value of d: " << d << endl;*/
            
            indices.push_back(a - 1);
            indices.push_back(c - 1);
            indices.push_back(d - 1);
            
            faceCount++;
        }
        
        else if(ch1 == '#'){
            
            fgets(stuff, BUFSIZ, fp);
        }
    }
    
    //cerr << "verticeCount is: " << verticeCount << endl;
    //cerr << "normalCount is: " << normalCount << endl;
    //cerr << "faceCount is: " << faceCount << endl;
    
    //Finding the averages
    avgX = (minX + maxX)/2.0f;
    avgY = (minY + maxY)/2.0f;
    avgZ = (minZ + maxZ)/2.0f;
    
    /*cerr << "Average x is: " << avgX << endl;
    cerr << "Average y is: " << avgY << endl;
    cerr << "Average z is: " << avgZ << endl;
    
    cerr << "MinX is: " << minX << " and maxX is: " << maxX << endl;
    cerr << "MinY is: " << minY << " and maxY is: " << maxY << endl;
    cerr << "MinZ is: " << minZ << " and maxZ is: " << maxZ << endl;*/
    
    //Finding the max Dimensions
    dimX = maxX - minX;
    dimY = maxY - minY;
    dimZ = maxZ - minZ;
    
    if(dimX < dimY){
    
        maxDim = dimY;
        
        if(dimY < dimZ){
        
            maxDim = dimZ;
        }
    }
    
    else{

        maxDim = dimX;
        
        if(dimX < dimZ){
        
            maxDim = dimZ;
        }
    }
    
    //cerr << "The count is: " << count << endl;
    
    for(unsigned int i = 0; i < vertices.size(); i++){
        
        vertices[i].x -= avgX;
        vertices[i].y -= avgY;
        vertices[i].z -= avgZ;
        
        vertices[i] /= maxDim;
    }
    
    //cerr << "maxDim is: " << maxDim << endl;
    
    fclose(fp);
}

void OBJObject::modernDraw(GLuint shaderProgram, glm::mat4 M, bool split)
{
    
    /************working above******************/
    
    directVec = (glm::vec3(this -> lightPos.x, this -> lightPos.y, this -> lightPos.z));
    
    // directional light
    glUniform3f(glGetUniformLocation(shaderProgram, "dirLight.direction"), directVec.x, directVec.y, directVec.z);
    
    glUniform3f(glGetUniformLocation(shaderProgram, "dirLight.ambient"), 1.0f, 1.0f, 1.0f);
    
    glUniform3f(glGetUniformLocation(shaderProgram, "dirLight.diffuse"), 1.0f, 1.0f, 1.0f);
    
    glUniform3f(glGetUniformLocation(shaderProgram, "dirLight.specular"), 1.0f, 1.0f, 1.0f);
    
    glUniform1i(glGetUniformLocation(shaderProgram, "dirLight.lightsOn"), 1);
    
    glUniform3f(glGetUniformLocation(shaderProgram, "material.ambient"), ambientMat.x, ambientMat.y, ambientMat.z);
    
    glUniform3f(glGetUniformLocation(shaderProgram, "material.diffuse"), diffuseMat.x, diffuseMat.y, diffuseMat.z);
    glUniform3f(glGetUniformLocation(shaderProgram, "material.specular"), specMat.x, specMat.y, specMat.z);
    
    glUniform1f(glGetUniformLocation(shaderProgram, "material.shininess"), shininess);
    
    
    if(split){
        
        glViewport(Window::width/2, 0, Window::width/2, Window::height);
        
        glm::mat4 MVP = Window::P * Window::V * M;
        
        Window::P = glm::perspective(45.0f, ((float)Window::width/2.0f) / (float)Window::height, 0.1f, 1000.0f);
        
        GLuint MatrixID = glGetUniformLocation(shaderProgram, "MVP");
        
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
        
        // model passed to shader
        GLuint toWorld = glGetUniformLocation(shaderProgram, "model");
        
        glUniformMatrix4fv(toWorld, 1, GL_FALSE, &M[0][0]);
        
        //view passed to shader
        GLuint view = glGetUniformLocation(shaderProgram, "view");
        
        glUniformMatrix4fv(view, 1, GL_FALSE, &Window::V[0][0]);
        
        //projection passed to shader
        GLuint projection = glGetUniformLocation(shaderProgram, "projection");
        
        glUniformMatrix4fv(projection, 1, GL_FALSE, &Window::P[0][0]);
        
        glUniform3f(glGetUniformLocation(shaderProgram, "viewPos"), 0.0f, 0.0f, -20.0f);
        
        glBindVertexArray(VAO);
        
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
        
        glBindVertexArray(0);
        
       
        ////////// left half of split screen //////////
        
        glViewport(0, 0, Window::width/2, Window::height);
        
        MVP = Window::P * Window::VSplit * M;
        //glm::mat4 model = toWorld;
        
        MatrixID = glGetUniformLocation(shaderProgram, "MVP");
        
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
        
        // model passed to shader
        toWorld = glGetUniformLocation(shaderProgram, "model");
        
        glUniformMatrix4fv(toWorld, 1, GL_FALSE, &M[0][0]);
        
        //view passed to shader
        view = glGetUniformLocation(shaderProgram, "view");
        
        glUniformMatrix4fv(view, 1, GL_FALSE, &Window::VSplit[0][0]);
        
        //projection passed to shader
        projection = glGetUniformLocation(shaderProgram, "projection");
        
        glUniformMatrix4fv(projection, 1, GL_FALSE, &Window::P[0][0]);
        
        glUniform3f(glGetUniformLocation(shaderProgram, "viewPos"), 0.0f, 0.0f, -20.0f);
        
        glBindVertexArray(VAO);
        
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
        
        glBindVertexArray(0);
    }
    
    else{
    
        //cerr << "Beginning of the object draw function" << endl;
        
        glm::mat4 MVP = Window::P * Window::V * M;
        //glm::mat4 model = toWorld;
        
        Window::P = glm::perspective(45.0f, (float)Window::width / (float)Window::height, 0.1f, 1000.0f);
        
        GLuint MatrixID = glGetUniformLocation(shaderProgram, "MVP");
        
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
        
        // model passed to shader
        GLuint toWorld = glGetUniformLocation(shaderProgram, "model");
        
        glUniformMatrix4fv(toWorld, 1, GL_FALSE, &M[0][0]);
        
        //view passed to shader
        GLuint view = glGetUniformLocation(shaderProgram, "view");
        
        glUniformMatrix4fv(view, 1, GL_FALSE, &Window::V[0][0]);
        
        //projection passed to shader
        GLuint projection = glGetUniformLocation(shaderProgram, "projection");
        
        glUniformMatrix4fv(projection, 1, GL_FALSE, &Window::P[0][0]);
        
        glUniform3f(glGetUniformLocation(shaderProgram, "viewPos"), 0.0f, 0.0f, -20.0f);
        
        glViewport(0, 0, Window::width, Window::height);
        
        glBindVertexArray(VAO);
        
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
        
        glBindVertexArray(0);
    }
}

void OBJObject::update(){

    spin(1.0f);
}

void OBJObject::spin(float deg){

    this->angle = deg;
    if (this->angle > 360.0f || this->angle < -360.0f) this->angle = 0.0f;
    // This creates the matrix to rotate the cube
    this->toWorld *= glm::rotate(glm::mat4(1.0f), this->angle / 180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f));
}

