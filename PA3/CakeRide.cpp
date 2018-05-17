
#include "CakeRide.hpp"
//#include "Geode.hpp"


//default constructor
CakeRide::CakeRide(){

}

//center pillar functions
void CakeRide::addBase(MatrixTransform * parent, MatrixTransform * &scaleM, MatrixTransform * &translateM, MatrixTransform * &rotationM,
                          SceneNode * geodePtr, glm::vec3 scale, glm::vec3 translate, glm::vec3 rotate, float angle){
    
    
    scaleM = new MatrixTransform(identity);
    translateM = new MatrixTransform(identity);
    rotationM = new MatrixTransform(identity);
    
    
    parent -> addChild(rotationM);
    rotationM -> addChild(translateM);
    translateM -> addChild(scaleM);
    scaleM -> addChild(geodePtr);

    scaleM -> M = (glm::mat4(glm::scale(identity, scale)));
    translateM -> M = (glm::mat4(glm::translate(identity, translate)));
    rotationM -> M = (glm::mat4(glm::rotate(identity, angle, rotate)));    
}

////arm functions
void CakeRide::addArm(MatrixTransform * parent, MatrixTransform * &scaleM, MatrixTransform * &translateM, MatrixTransform * &rotationM, SceneNode * geodePtr, glm::vec3 scale, glm::vec3 translate, glm::vec3 rotate, float angle){
    
    
    scaleM = new MatrixTransform(identity);
    translateM = new MatrixTransform(identity);
    rotationM = new MatrixTransform(identity);
    
    
    parent -> addChild(rotationM);
    rotationM -> addChild(translateM);
    translateM -> addChild(scaleM);
    scaleM -> addChild(geodePtr);

    
    scaleM -> M = (glm::mat4(glm::scale(identity, scale)));
    translateM -> M = (glm::mat4(glm::translate(identity, translate)));
    rotationM -> M = (glm::mat4(glm::rotate(identity, angle, rotate)));
}

void CakeRide::addArmR(MatrixTransform * parent, MatrixTransform * &scaleM, MatrixTransform * &translateM, MatrixTransform * &rotationM, MatrixTransform * &rotationM2,
                       SceneNode * geodePtr, glm::vec3 scale, glm::vec3 translate, glm::vec3 rotate, glm::vec3 rotate2,  float angle, float angle2){
    
    scaleM = new MatrixTransform(identity);
    translateM = new MatrixTransform(identity);
    rotationM = new MatrixTransform(identity);
    rotationM2 = new MatrixTransform(identity);
    
    
    parent -> addChild(rotationM2);
    rotationM2 -> addChild(rotationM);
    rotationM -> addChild(translateM);
    translateM -> addChild(scaleM);
    scaleM -> addChild(geodePtr);
    
    
    scaleM -> M = (glm::mat4(glm::scale(identity, scale)));
    translateM -> M = (glm::mat4(glm::translate(identity, translate)));
    rotationM -> M = (glm::mat4(glm::rotate(identity, angle, rotate)));
    rotationM2 -> M = (glm::mat4(glm::rotate(identity, angle2, rotate2)));
}


////arm functions upper levels
void CakeRide::addArmUp(MatrixTransform * parent, /*MatrixTransform * &scaleM, MatrixTransform * &translateM, MatrixTransform * &rotationM,*/ MatrixTransform * &translateM2, SceneNode * geodePtr, glm::vec3 translate2){
    
    
    MatrixTransform * scaleM = new MatrixTransform(identity);
    MatrixTransform * translateM = new MatrixTransform(identity);
    MatrixTransform * rotationM = new MatrixTransform(identity);
    translateM2 = new MatrixTransform(identity);
    
    
    parent -> addChild(translateM2);
    translateM2 -> addChild(rotationM);
    rotationM -> addChild(translateM);
    translateM -> addChild(scaleM);
    scaleM -> addChild(geodePtr);
    
    
    scaleM -> M = (glm::mat4(glm::scale(identity, glm::vec3(0.5f, 5.0f, 1.0f))));//scale)));
    translateM -> M = (glm::mat4(glm::translate(identity, glm::vec3(0.0f, 2.5f, 0.0f))));//translate)));
    rotationM -> M = (glm::mat4(glm::rotate(identity, -90.0f/180.0f * glm::pi<float>()/*angle*/, glm::vec3(0.0f, 0.0f, 1.0f))));//rotate)));
    translateM2 -> M = (glm::mat4(glm::translate(identity, translate2)));//translate2)));
}

void CakeRide::addArmUpR(MatrixTransform * parent, /*MatrixTransform * &scaleM, MatrixTransform * &translateM, MatrixTransform * &rotationM, MatrixTransform * &rotationM2,*/ SceneNode * geodePtr,/* glm::vec3 scale, glm::vec3 translate, glm::vec3 rotate, glm::vec3 rotate2, float angle,*/ float angle2){
    
    
    MatrixTransform * scaleM = new MatrixTransform(identity);
    MatrixTransform * translateM = new MatrixTransform(identity);
    MatrixTransform * rotationM = new MatrixTransform(identity);
    MatrixTransform * rotationM2 = new MatrixTransform(identity);
    
    
    parent -> addChild(rotationM2);
    rotationM2 -> addChild(rotationM);
    rotationM -> addChild(translateM);
    translateM -> addChild(scaleM);
    scaleM -> addChild(geodePtr);
    
    
    scaleM -> M = (glm::mat4(glm::scale(identity, glm::vec3(0.5f, 5.0f, 1.0f))));
    translateM -> M = (glm::mat4(glm::translate(identity, glm::vec3(0.0f, 2.5f, 0.0f))));
    rotationM -> M = (glm::mat4(glm::rotate(identity, -90.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 0.0f, 1.0f))));
    rotationM2 -> M = (glm::mat4(glm::rotate(identity, angle2, glm::vec3(0.0f, 1.0f, 0.0f))));
}



////extending arm functions
void CakeRide::addExtendArm(MatrixTransform * parent, MatrixTransform * &scaleM, MatrixTransform * &translateM, MatrixTransform * &rotationM, MatrixTransform * &translateM2, SceneNode * geodePtr, glm::vec3 scale, glm::vec3 translate, glm::vec3 rotate, glm::vec3 translate2, float angle){
    
    scaleM = new MatrixTransform(identity);
    translateM = new MatrixTransform(identity);
    rotationM = new MatrixTransform(identity);
    translateM2 = new MatrixTransform(identity);
    
    
    parent -> addChild(translateM2);
    translateM2 -> addChild(rotationM);
    rotationM -> addChild(translateM);
    translateM -> addChild(scaleM);
    scaleM -> addChild(geodePtr);
    
    
    scaleM -> M = (glm::mat4(glm::scale(identity, scale)));
    translateM -> M = (glm::mat4(glm::translate(identity, translate)));
    rotationM -> M = (glm::mat4(glm::rotate(identity, angle, rotate)));
    translateM2 -> M = (glm::mat4(glm::translate(identity, translate2)));
}

void CakeRide::addExtendArmUp(MatrixTransform * parent, /*MatrixTransform * &scaleM, MatrixTransform * &translateM, MatrixTransform * &rotationM,*/ MatrixTransform * &translateM2, MatrixTransform * &rotationM2, SceneNode * geodePtr, /*glm::vec3 scale, glm::vec3 translate, glm::vec3 rotate,*/ glm::vec3 translate2, glm::vec3 rotate2, /*float angle,*/ float angle2){
    
    
    MatrixTransform * scaleM = new MatrixTransform(identity);
    MatrixTransform * translateM = new MatrixTransform(identity);
    translateM2 = new MatrixTransform(identity);
    MatrixTransform * rotationM = new MatrixTransform(identity);
    rotationM2 = new MatrixTransform(identity);

    parent -> addChild(rotationM2);
    rotationM2 -> addChild(translateM2);
    translateM2 -> addChild(rotationM);
    rotationM -> addChild(translateM);
    translateM -> addChild(scaleM);
    scaleM -> addChild(geodePtr);
    
    
    scaleM -> M = (glm::mat4(glm::scale(identity, glm::vec3(0.5f, 5.0f, 1.0f))));
    translateM -> M = (glm::mat4(glm::translate(identity, glm::vec3(0.0f, 2.5f, 0.0f))));
    rotationM -> M = (glm::mat4(glm::rotate(identity, -90.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 0.0f, 1.0f))));
    translateM2 -> M = (glm::mat4(glm::translate(identity, translate2)));
    rotationM2 -> M = (glm::mat4(glm::rotate(identity, angle2, rotate2)));
}

void CakeRide::addExtendArmR(MatrixTransform * parent, MatrixTransform * &scaleM, MatrixTransform * &translateM, MatrixTransform * &rotationM, MatrixTransform * &translateM2, MatrixTransform * &rotationM2,  SceneNode * geodePtr, glm::vec3 scale, glm::vec3 translate, glm::vec3 rotate, glm::vec3 translate2, glm::vec3 rotate2, float angle, float angle2){
    
    scaleM = new MatrixTransform(identity);
    translateM = new MatrixTransform(identity);
    rotationM = new MatrixTransform(identity);
    rotationM2 = new MatrixTransform(identity);
    translateM2 = new MatrixTransform(identity);
    
    
    parent -> addChild(rotationM2);
    rotationM2 -> addChild(translateM2);
    translateM2 -> addChild(rotationM);
    rotationM -> addChild(translateM);
    translateM -> addChild(scaleM);
    scaleM -> addChild(geodePtr);
    
    scaleM -> M = (glm::mat4(glm::scale(identity, scale)));
    translateM -> M = (glm::mat4(glm::translate(identity, translate)));
    rotationM -> M = (glm::mat4(glm::rotate(identity, angle, rotate)));
    translateM2 -> M = (glm::mat4(glm::translate(identity, translate2)));
    rotationM2 -> M = (glm::mat4(glm::rotate(identity, angle2, rotate2)));
}

//finger functions
void CakeRide::addFinger(MatrixTransform * parent, MatrixTransform * &scaleM, MatrixTransform * &rotationM, MatrixTransform * &translateM, MatrixTransform * &translateM2, MatrixTransform * &rotationM2, MatrixTransform * &translateM3,
               SceneNode * geodePtr, glm::vec3 scale, glm::vec3 rotate, glm::vec3 translate, glm::vec3 translate2, glm::vec3 rotate2, glm::vec3 translate3, float angle, float angle2){

    scaleM = new MatrixTransform(identity);
    rotationM = new MatrixTransform(identity);
    translateM = new MatrixTransform(identity);
    translateM2 = new MatrixTransform(identity);
    rotationM2 = new MatrixTransform(identity);
    translateM3 = new MatrixTransform(identity);
    
    
    parent -> addChild(translateM3);
    translateM3 -> addChild(rotationM2);
    rotationM2 -> addChild(translateM2);
    translateM2 -> addChild(translateM);
    translateM -> addChild(rotationM);
    rotationM -> addChild(scaleM);
    scaleM -> addChild(geodePtr);
    
    
    scaleM -> M = (glm::mat4(glm::scale(identity, scale)));
    rotationM -> M = (glm::mat4(glm::rotate(identity, angle, rotate)));
    translateM -> M = (glm::mat4(glm::translate(identity, translate)));
    translateM2 -> M = (glm::mat4(glm::translate(identity, translate2)));
    rotationM2 -> M = (glm::mat4(glm::rotate(identity, angle2, rotate2)));
    translateM3 -> M = (glm::mat4(glm::translate(identity, translate3)));
}

//finger functions
void CakeRide::addFingerUp(MatrixTransform * parent, MatrixTransform * &rotationM2, MatrixTransform * &translateM2, SceneNode * geodePtr, float angle){
    
    MatrixTransform * scaleM = new MatrixTransform(identity);
    MatrixTransform * rotationM = new MatrixTransform(identity);
    MatrixTransform * translateM = new MatrixTransform(identity);
    translateM2 = new MatrixTransform(identity);
    rotationM2 = new MatrixTransform(identity);
    MatrixTransform * translateM3 = new MatrixTransform(identity);
    
    
    parent -> addChild(translateM3);
    translateM3 -> addChild(rotationM2);
    rotationM2 -> addChild(translateM2);
    translateM2 -> addChild(translateM);
    translateM -> addChild(rotationM);
    rotationM -> addChild(scaleM);
    scaleM -> addChild(geodePtr);
    
    
    scaleM -> M = (glm::mat4(glm::scale(identity, glm::vec3(0.24f, 2.0f, 0.24f))));
    rotationM -> M = (glm::mat4(glm::rotate(identity, -90.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 0.0f, 1.0f))));
    translateM -> M = (glm::mat4(glm::translate(identity, glm::vec3(0.0f, 0.35f, 0.0f))));
    translateM2 -> M = (glm::mat4(glm::translate(identity, glm::vec3(1.0f, 0.0f, 0.0f))));
    rotationM2 -> M = (glm::mat4(glm::rotate(identity, angle, glm::vec3(0.0f, 1.0f, 0.0f))));
    translateM3 -> M = (glm::mat4(glm::translate(identity, glm::vec3(5.0f, 0.0f, 0.0f))));
}

void CakeRide::addFingerUpR(MatrixTransform * parent, MatrixTransform * &rotationM2, MatrixTransform * &translateM2, SceneNode * geodePtr, float angle){
    
    rotationM2 = new MatrixTransform(identity);
    translateM2 = new MatrixTransform(identity);
    MatrixTransform * scaleM = new MatrixTransform(identity);
    MatrixTransform * rotationM = new MatrixTransform(identity);
    MatrixTransform * translateM = new MatrixTransform(identity);
    
    
    parent -> addChild(rotationM2);
    rotationM2 -> addChild(translateM2);
    translateM2 -> addChild(translateM);
    translateM -> addChild(rotationM);
    rotationM -> addChild(scaleM);
    scaleM -> addChild(geodePtr);
    
    
    scaleM -> M = (glm::mat4(glm::scale(identity, glm::vec3(0.24f, 2.0f, 0.24f))));
    rotationM -> M = (glm::mat4(glm::rotate(identity, -90.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 0.0f, 1.0f))));
    translateM -> M = (glm::mat4(glm::translate(identity, glm::vec3(0.0f, 0.35f, 0.0f))));
    translateM2 -> M = (glm::mat4(glm::translate(identity, glm::vec3(1.0f, 0.0f, 0.0f))));
    rotationM2 -> M = (glm::mat4(glm::rotate(identity, angle, glm::vec3(0.0f, 1.0f, 0.0f))));
}

void CakeRide::addPod(MatrixTransform * parent, MatrixTransform * &rotationM, SceneNode * geodePtr){

    MatrixTransform * scaleM = new MatrixTransform(identity);
    rotationM = new MatrixTransform(identity);
    MatrixTransform * translateM = new MatrixTransform(identity);
    MatrixTransform * translateM2 = new MatrixTransform(identity);
    
    parent -> addChild(translateM2);
    translateM2 -> addChild(translateM);
    translateM -> addChild(rotationM);
    rotationM -> addChild(scaleM);
    scaleM -> addChild(geodePtr);
    
    
    translateM2 -> M = (glm::mat4(glm::translate(identity, glm::vec3(0.0f, 1.1f, 0.0f))));
    translateM -> M = (glm::mat4(glm::translate(identity, glm::vec3(1.0f, 0.0f, 0.0f))));
    rotationM -> M = (glm::mat4(glm::rotate(identity, 30.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))));
    scaleM -> M = (glm::mat4(glm::scale(identity, glm::vec3(2.0f, 2.0f, 2.0f))));
}

void CakeRide::addPodUp(MatrixTransform * parent, MatrixTransform * &rotationM, SceneNode * geodePtr){
    
    MatrixTransform * scaleM = new MatrixTransform(identity);
    rotationM = new MatrixTransform(identity);
    MatrixTransform * translateM = new MatrixTransform(identity);
    MatrixTransform * translateM2 = new MatrixTransform(identity);
    
    parent -> addChild(translateM2);
    translateM2 -> addChild(translateM);
    translateM -> addChild(rotationM);
    rotationM -> addChild(scaleM);
    scaleM -> addChild(geodePtr);
    
    
    translateM2 -> M = (glm::mat4(glm::translate(identity, glm::vec3(0.0f, 1.24f, 0.0f))));
    translateM -> M = (glm::mat4(glm::translate(identity, glm::vec3(1.0f, 0.0f, 0.0f))));
    rotationM -> M = (glm::mat4(glm::rotate(identity, 30.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))));
    scaleM -> M = (glm::mat4(glm::scale(identity, glm::vec3(2.0f, 2.0f, 2.0f))));
}



//smallBase covers for end of large arms
void CakeRide::addSmallBase(MatrixTransform * parent, SceneNode * geodePtr){

    MatrixTransform * scaleM = new MatrixTransform(identity);
    MatrixTransform * translateM = new MatrixTransform(identity);
    MatrixTransform * translateM2 = new MatrixTransform(identity);
    
    parent -> addChild(translateM2);
    translateM2 -> addChild(translateM);
    translateM -> addChild(scaleM);
    scaleM -> addChild(geodePtr);
    
    translateM2 -> M = (glm::mat4(glm::translate(identity, glm::vec3(5.0f, 0.0f, 0.0f))));
    translateM -> M = (glm::mat4(glm::translate(identity, glm::vec3(0.0f, 0.25f, 0.0f))));
    scaleM -> M = (glm::mat4(glm::scale(identity, glm::vec3(1.0f, 0.5f, 1.0f))));
}

void CakeRide::addBear(MatrixTransform * parent, SceneNode * geodePtr){

    
    MatrixTransform * translateM = new MatrixTransform(identity);
    MatrixTransform * scaleM = new MatrixTransform(identity);
    
    parent -> addChild(translateM);
    translateM -> addChild(scaleM);
    scaleM -> addChild(geodePtr);
    
    
    translateM -> M = (glm::mat4(glm::translate(identity, glm::vec3(0.0f, 0.25f, 0.0f))));
    scaleM -> M = (glm::mat4(glm::scale(identity, glm::vec3(1.5f, 1.5f, 1.5f))));
}

void CakeRide::addBearPod(MatrixTransform * parent, MatrixTransform * &camera, MatrixTransform * &rotationM, Geode * geodePtr){
    
    camera = new MatrixTransform(identity);
    MatrixTransform * scaleM = new MatrixTransform(identity);
    rotationM = new MatrixTransform(identity);
    MatrixTransform * translateM = new MatrixTransform(identity);
    MatrixTransform * translateM2 = new MatrixTransform(identity);
    
    parent -> addChild(translateM2);
    translateM2 -> addChild(translateM);
    translateM -> addChild(rotationM);
    rotationM -> addChild(scaleM);
    scaleM -> addChild(camera);
    camera -> addChild(geodePtr);
    
    
    translateM2 -> M = (glm::mat4(glm::translate(identity, glm::vec3(0.0f, 1.24f, 0.0f))));
    translateM -> M = (glm::mat4(glm::translate(identity, glm::vec3(1.0f, 0.0f, 0.0f))));
    rotationM -> M = (glm::mat4(glm::rotate(identity, 30.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))));
    scaleM -> M = (glm::mat4(glm::scale(identity, glm::vec3(2.0f, 2.0f, 2.0f))));
}
