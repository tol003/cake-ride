
#include "Group.hpp"


using namespace std;

//constructor
Group::Group(){

    
}

//add a child
void Group::addChild(SceneNode * child){
    
    children.push_back(child);
}

//remove a child
void Group::removeChild(SceneNode * child){
    
    children.pop_back();
}

//call draw on all children
void Group::draw(GLuint shaderProgram, bool split){
    
    list<SceneNode *>::iterator beginPtr = children.begin();
    list<SceneNode * >::iterator endPtr = children.end();
    
    
    for(; beginPtr != endPtr; beginPtr++){
    
        //Geode * child = *beginPtr;
        
        (*beginPtr) -> draw(shaderProgram,split);
    }
    
    //beginPtr = children.begin();
}

//call update on all children
void Group::update(glm::mat4 C, bool split){
    
    list<SceneNode *>::iterator beginPtr = children.begin();
    list<SceneNode * >::iterator endPtr = children.end();
    
    for(; beginPtr != endPtr; beginPtr++){
        
        //Geode * child = *beginPtr;
        
        (*beginPtr) -> update(C, split);
    }
    
    //beginPtr = children.begin();
}