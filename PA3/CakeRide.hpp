
#ifndef CakeRide_hpp
#define CakeRide_hpp

#include <stdio.h>

#include "SceneNode.hpp"
#include "MatrixTransform.hpp"
#include "Geode.hpp"

class CakeRide{
    
    
public:
    
    //variables
    glm::mat4 identity = glm::mat4(1.0f);
    
    //constructors
    CakeRide();
    
    
    //functions
    void addBase(MatrixTransform * parent, /*MatrixTransform * &mainPillar,*/ MatrixTransform * &scaleM, MatrixTransform * &translateM, MatrixTransform * &rotationM,
                    SceneNode * geodePtr, glm::vec3 scale, glm::vec3 translate, glm::vec3 rotate, float angle);
    
    //arms that need only one rotation
    void addArm(MatrixTransform * parent, MatrixTransform * &scaleM, MatrixTransform * &translateM, MatrixTransform * &rotationM,
                  SceneNode * geodePtr, glm::vec3 scale, glm::vec3 translate, glm::vec3 rotate, float angle);
    
    //arms that need two rotations
    void addArmR(MatrixTransform * parent, MatrixTransform * &scaleM, MatrixTransform * &translateM, MatrixTransform * &rotationM, MatrixTransform * &rotationM2,
                 SceneNode * geodePtr, glm::vec3 scale, glm::vec3 translate, glm::vec3 rotate, glm::vec3 rotate2, float angle, float angle2);
    
    //arms on upper level that needs two translates
    void addArmUp(MatrixTransform * parent,/* MatrixTransform * &scaleM, MatrixTransform * &translateM, MatrixTransform * &rotationM,*/ MatrixTransform * &translateM2, SceneNode * geodePtr, glm::vec3 translate2);
    
    //arms on upper level once first one is set
    void addArmUpR(MatrixTransform * parent,/* MatrixTransform * &scaleM, MatrixTransform * &translateM, MatrixTransform * &rotationM, MatrixTransform * &rotationM2,*/ SceneNode * geodePtr,/* glm::vec3 scale, glm::vec3 translate, glm::vec3 rotate, glm::vec3 rotate2, float angle,*/ float angle2);
    
    //extension arms
    void addExtendArm(MatrixTransform * parent, MatrixTransform * &scaleM, MatrixTransform * &translateM, MatrixTransform * &rotationM, MatrixTransform * &translateM2, SceneNode * geodePtr, glm::vec3 scale, glm::vec3 translate, glm::vec3 rotate, glm::vec3 translate2, float angle);
    
    //extension arms that need two rotations
    void addExtendArmR(MatrixTransform * parent, MatrixTransform * &scaleM, MatrixTransform * &translateM, MatrixTransform * &rotationM, MatrixTransform * &translateM2, MatrixTransform * &rotationM2,  SceneNode * geodePtr, glm::vec3 scale, glm::vec3 translate, glm::vec3 rotate, glm::vec3 translate2, glm::vec3 rotate2,  float angle, float angle2);
    
    //extension upper level
    void addExtendArmUp(MatrixTransform * parent, /*MatrixTransform * &scaleM, MatrixTransform * &translateM, MatrixTransform * &rotationM,*/ MatrixTransform * &translateM2, MatrixTransform * &rotationM2, SceneNode * geodePtr,/* glm::vec3 scale, glm::vec3 translate, glm::vec3 rotate,*/ glm::vec3 translate2, glm::vec3 rotate2, /*float angle,*/ float angle2);
    
    //fingers
    void addFinger(MatrixTransform * parent, MatrixTransform * &scaleM, MatrixTransform * &rotationM, MatrixTransform * &translateM, MatrixTransform * &translateM2, MatrixTransform * &rotationM2, MatrixTransform * &translateM3, SceneNode * geodePtr, glm::vec3 scale, glm::vec3 rotate, glm::vec3 translate, glm::vec3 translate2, glm::vec3 rotate2, glm::vec3 translate3, float angle, float angle2);
    
    //fingers middle level
    void addFingerUp(MatrixTransform * parent, MatrixTransform * &rotationM2, MatrixTransform * &translateM2, SceneNode * geodePtr, float angle);
    
    void addFingerUpR(MatrixTransform * parent, MatrixTransform * &rotationM2, MatrixTransform * &translateM2, SceneNode * geodePtr, float angle);
    
    
    
    //pods
    void addPod(MatrixTransform * parent, MatrixTransform * &rotationM, SceneNode * geodePtr);
    
    void addPodUp(MatrixTransform * parent, MatrixTransform * &rotationM, SceneNode * geodePtr);

    
    void addSmallBase(MatrixTransform * parent, SceneNode * geodePtr);
    
    void addBear(MatrixTransform * parent, SceneNode * geodePtr);
    
    void addBearPod(MatrixTransform * parent, MatrixTransform * &camera, MatrixTransform * &rotationM, Geode * geodePtr);
};

#endif /* CakeRide_hpp */
