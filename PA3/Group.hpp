
#ifndef Group_hpp
#define Group_hpp


#include <list>

#include "SceneNode.hpp"

using namespace std;

class Group: public SceneNode{

public:
    
    //list
    list<SceneNode *> children;
    
    //constructor
    Group();
    
    //iterators
    list<SceneNode *>::iterator beginPtr = children.begin();
    list<SceneNode * >::iterator endPtr = children.end();
    
    //functions
    void addChild(SceneNode * child);
    void removeChild(SceneNode * child);
    virtual void update(glm::mat4 C, bool split);
    virtual void draw(GLuint shaderProgram, bool split);
    
};

#endif /* Group_hpp */
