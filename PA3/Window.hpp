
#ifndef Window_hpp
#define Window_hpp


#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <iostream>

#include "Cube.h"
#include "shader.h"
#include "skyBoxObject.hpp"
#include "OBJObject.h"


//includes from PA3
#include "SceneNode.hpp"
#include "glm/ext.hpp"

#include "MatrixTransform.hpp"
#include "CakeRide.hpp"

class Window{

public:
    
    //variables
    static int width;
    static int height;
    static double lastX;
    static double lastY;
    static double currentX;
    static double currentY;
    static float velocity;
    static float pitch;
    static float yaw;
    static int skyBoxRender;
    
    
    //matrices and vectors
    static glm::mat4 P;
    static glm::mat4 V;
    static glm::mat4 VSplit;
    static glm::vec3 lastMousePos;
    static glm::vec3 currentMousePos;
    
    
    //functions
    static void initialize_objects();
    static void clean_up();
    static GLFWwindow* create_window(int width, int height);
    static void resize_callback(GLFWwindow* window, int width, int height);
    static void idle_callback();
    static void display_callback(GLFWwindow*);
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
    static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
    static void cursor_enter_callback(GLFWwindow* window, int entered);
    static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
    static glm::vec3 mousePosTracking(double x, double y);
    
    static void rotationCalc();
    static void cameraLook();
    
    //PA3 functions
    static void addCakePart(OBJObject * ridePart, float x, float y, float z);
    static void translatePart(glm::mat4 &tempMatrix, float x, float y, float z);
};


#endif /* Window_hpp */
