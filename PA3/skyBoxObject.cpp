
#include "skyBoxObject.hpp"
#include "Texture.hpp"


#define INDEX_OFFSET 6

using namespace std;


GLfloat skyVertices[] = {
    
    // Front vertices
    400.0, 400.0,  -400.0,
    -400.0, 400.0,  -400.0,
    -400.0,  -400.0,  -400.0,
    400.0,  -400.0,  -400.0,
    // Back vertices
    400.0, 400.0, 400.0,
    -400.0, 400.0, 400.0,
    -400.0,  -400.0, 400.0,
    400.0,  -400.0, 400.0
    
    /*// Front vertices
     -500.0, -500.0,  500.0,
     500.0, -500.0,  500.0,
     500.0,  500.0,  500.0,
     -500.0,  500.0,  500.0,
     // Back vertices
     -500.0, -500.0, -500.0,
     500.0, -500.0, -500.0,
     500.0,  500.0, -500.0,
     -500.0,  500.0, -500.0*/
    
    
    /*// Front vertices
    -0.5, -0.5,  0.5,
    0.5, -0.5,  0.5,
    0.5,  0.5,  0.5,
    -0.5,  0.5,  0.5,
    // Back vertices
    -0.5, -0.5, -0.5,
    0.5, -0.5, -0.5,
    0.5,  0.5, -0.5,
    -0.5,  0.5, -0.5*/
};

GLuint skyIndices[] = {  // Note that we start from 0!
    // Front face
    0, 1, 2,
    2, 3, 0,
    // Top face
    1, 5, 6,
    6, 2, 1,
    // Back face
    7, 6, 5,
    5, 4, 7,
    // Bottom face
    4, 0, 3,
    3, 7, 4,
    // Left face
    4, 5, 1,
    1, 0, 4,
    // Right face
    3, 2, 6,
    6, 7, 3
};


skyBoxObject::skyBoxObject(unsigned skyToRender){
    
    
    
    this -> toWorld = glm::mat4(1.0f);
    
    this -> angle = 0.0f;
    
    Texture texCube;
    
    mountainSky = 0;
    valleySky = 0;
    lagoonSky = 0;
    morningSky = 0;
    
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

    /*****push faces into the vector in this order(right, left, top, bottom, back, front)*****/
    
    //Mountain range(indices: 0 - 5)
    texCube.pushFaces(faces, "/Users/ReloadSyndrome/Documents/Objects_and_Textures/Textures/mp_heresy/bloody-heresy_rt.ppm");
    
    texCube.pushFaces(faces, "/Users/ReloadSyndrome/Documents/Objects_and_Textures/Textures/mp_heresy/bloody-heresy_lf.ppm");
    
    texCube.pushFaces(faces, "/Users/ReloadSyndrome/Documents/Objects_and_Textures/Textures/mp_heresy/bloody-heresy_up.ppm");
    
    texCube.pushFaces(faces, "/Users/ReloadSyndrome/Documents/Objects_and_Textures/Textures/mp_heresy/bloody-heresy_dn.ppm");
    
    texCube.pushFaces(faces, "/Users/ReloadSyndrome/Documents/Objects_and_Textures/Textures/mp_heresy/bloody-heresy_bk.ppm");
    
    texCube.pushFaces(faces, "/Users/ReloadSyndrome/Documents/Objects_and_Textures/Textures/mp_heresy/bloody-heresy_ft.ppm");
    
    mountainSky = texCube.indFaceGroup;
    
    //snow valley
    texCube.pushFaces(faces, "/Users/ReloadSyndrome/Documents/Objects_and_Textures/Textures/ame_siege/siege_rt.ppm");
    texCube.pushFaces(faces, "/Users/ReloadSyndrome/Documents/Objects_and_Textures/Textures/ame_siege/siege_lf.ppm");
    texCube.pushFaces(faces, "/Users/ReloadSyndrome/Documents/Objects_and_Textures/Textures/ame_siege/siege_up.ppm");
    texCube.pushFaces(faces, "/Users/ReloadSyndrome/Documents/Objects_and_Textures/Textures/ame_siege/siege_dn.ppm");
    texCube.pushFaces(faces, "/Users/ReloadSyndrome/Documents/Objects_and_Textures/Textures/ame_siege/siege_bk.ppm");
    texCube.pushFaces(faces, "/Users/ReloadSyndrome/Documents/Objects_and_Textures/Textures/ame_siege/siege_ft.ppm");
    
    valleySky = texCube.indFaceGroup;
    
    //lagoon
    texCube.pushFaces(faces, "/Users/ReloadSyndrome/Documents/Objects_and_Textures/Textures/hw_lagoon/lagoon_rt.ppm");
    texCube.pushFaces(faces, "/Users/ReloadSyndrome/Documents/Objects_and_Textures/Textures/hw_lagoon/lagoon_lf.ppm");
    texCube.pushFaces(faces, "/Users/ReloadSyndrome/Documents/Objects_and_Textures/Textures/hw_lagoon/lagoon_up.ppm");
    texCube.pushFaces(faces, "/Users/ReloadSyndrome/Documents/Objects_and_Textures/Textures/hw_lagoon/lagoon_dn.ppm");
    texCube.pushFaces(faces, "/Users/ReloadSyndrome/Documents/Objects_and_Textures/Textures/hw_lagoon/lagoon_bk.ppm");
    texCube.pushFaces(faces, "/Users/ReloadSyndrome/Documents/Objects_and_Textures/Textures/hw_lagoon/lagoon_ft.ppm");
    
    lagoonSky = texCube.indFaceGroup;
    
    //morning
    texCube.pushFaces(faces, "/Users/ReloadSyndrome/Documents/Objects_and_Textures/Textures/hw_morning/morning_rt.ppm");
    texCube.pushFaces(faces, "/Users/ReloadSyndrome/Documents/Objects_and_Textures/Textures/hw_morning/morning_lf.ppm");
    texCube.pushFaces(faces, "/Users/ReloadSyndrome/Documents/Objects_and_Textures/Textures/hw_morning/morning_up.ppm");
    texCube.pushFaces(faces, "/Users/ReloadSyndrome/Documents/Objects_and_Textures/Textures/hw_morning/morning_dn.ppm");
    texCube.pushFaces(faces, "/Users/ReloadSyndrome/Documents/Objects_and_Textures/Textures/hw_morning/morning_bk.ppm");
    texCube.pushFaces(faces, "/Users/ReloadSyndrome/Documents/Objects_and_Textures/Textures/hw_morning/morning_ft.ppm");
    
    morningSky = texCube.indFaceGroup;
    
    
    if(skyToRender== 1){
        
        int i = mountainSky - INDEX_OFFSET;
        
        for(int index = 0; index < 6; index++){
        
            texCube.loadTexture(faces[i], index);
            i++;
        }
    }
    
    if(skyToRender== 2){
        
        int i = valleySky - INDEX_OFFSET;
        
        for(int index = 0; index < 6; index++){
            
            texCube.loadTexture(faces[i], index);
            i++;
        }
    }
    
    if(skyToRender== 3){
        
        int i = lagoonSky - INDEX_OFFSET;
        
        for(int index = 0; index < 6; index++){
            
            texCube.loadTexture(faces[i], index);
            i++;
        }
    }
    
    if(skyToRender== 4){
        
        int i = morningSky - INDEX_OFFSET;
        
        for(int index = 0; index < 6; index++){
            
            texCube.loadTexture(faces[i], index);
            i++;
        }
    }
    
    
    texCube.setParameters();

    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(skyVertices), skyVertices, GL_STATIC_DRAW);

    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(skyIndices), skyIndices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid *)0);
    
    glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    glBindVertexArray(0);
}

void skyBoxObject::skyBoxDraw(GLuint skyShaderProgram){
    
    glm::mat4 projection = Window::P;
    glm::mat4 view = Window::V;
    glm::mat4 model = this -> toWorld;
    glm::mat4 restrictView = glm::mat4(glm::mat3(view));
    
    GLuint projectID = glGetUniformLocation(skyShaderProgram, "projection");
    glUniformMatrix4fv(projectID, 1, GL_FALSE, &projection[0][0]);
    
    GLint viewID = glGetUniformLocation(skyShaderProgram, "view");
    glUniformMatrix4fv(viewID, 1, GL_FALSE, &restrictView[0][0]);
    
    GLint toWorldID = glGetUniformLocation(skyShaderProgram, "model");
    glUniformMatrix4fv(toWorldID, 1, GL_FALSE, &model[0][0]);
    
    glBindVertexArray(VAO);
    
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    
    glBindVertexArray(0);
}

void skyBoxObject::cameraRotate(){

    if(keyPressed == GLFW_KEY_RIGHT){
    
        Window::V = glm::rotate(Window::V, 0.008f, glm::vec3(0.0f, 1.0f, 0.0f));
    }
    
    else if(keyPressed == GLFW_KEY_LEFT){
    
        Window::V = glm::rotate(Window::V, 0.008f, glm::vec3(0.0f, -1.0f, 0.0f));
    }
    
    else if(keyPressed == GLFW_KEY_UP){
    
        Window::V = glm::rotate(Window::V, 0.008f, glm::vec3(-1.0f, 0.0f, 0.0f));
    }
    
    else{
        
        Window::V = glm::rotate(Window::V, 0.008f, glm::vec3(1.0f, 0.0f, 0.0f));
    }
}

void skyBoxObject::update(){
    
    cameraRotate();    
}

void skyBoxObject::deleteSkyBox(GLuint &texture){
 
    glDeleteTextures(1, &texture);
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}


