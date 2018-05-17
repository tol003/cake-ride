
#include "Window.hpp"
//#include "Geode.hpp"


const char* window_title = "Cake Ride";

/*variables*/
bool keyRotate = false;
bool mouseIn = false;
bool firstMouse = true;
bool mouseLeftClick = false;
bool bearCameraView = false;
bool splitscreen = false;
double Window::lastX = width/2.0f;
double Window::lastY = height/2.0f;
double Window::currentX = lastX;
double Window::currentY = lastY;
//double currentX;
//double currentY;
float Window::velocity;
float Window::pitch;
float Window::yaw = -90.0f;
float rotationA;
int Window::skyBoxRender = 4;
double lastTime;


/*vectors*/
glm::vec3 Window::lastMousePos;
glm::vec3 Window::currentMousePos;
glm::vec3 lastPosVector;
glm::vec3 currentPosVector;
glm::vec3 rotationVector;
glm::vec3 normalVector;
glm::vec3 lastPosition;
//glm::mat4 id = glm::mat4(1.0f);
glm::mat4 identity = glm::mat4(1.0f);


/*pointer to objects*/
Cube * cube;
skyBoxObject * skyBox;
OBJObject * cylinder;
OBJObject * pod;
OBJObject * bear;


/*shader programs*/
GLint shaderProgram;
GLint skyShaderProgram;

//Default camera parameters
glm::vec3 cam_pos(10.0f, 20.0f, 30.0f);		// e  | Position of camera
glm::vec3 cam_look_at(0.0f, 0.0f, 0.0f);	// d  | This is where the camera looks at
glm::vec3 cam_up(0.0f, 1.0f, 0.0f);			// up | What orientation "up" is

int Window::width;
int Window::height;

glm::mat4 Window::P;
glm::mat4 Window::V;
glm::mat4 Window::VSplit;
glm::vec3 cameraFront;
MatrixTransform * bearCamera;


//Access to ride
MatrixTransform * ride = new MatrixTransform(identity);

MatrixTransform * mainRotationMatrix = new MatrixTransform(identity);
MatrixTransform * bottomRotationMatrix = new MatrixTransform(identity);
MatrixTransform * middleRotationMatrix = new MatrixTransform(identity);
MatrixTransform * topRotationMatrix = new MatrixTransform(identity);



////constructing the top level of the ride////
MatrixTransform * scale_topBase;
MatrixTransform * translate_topBase;
MatrixTransform * rotate_topBase;


//matrix pointer for top arm1
MatrixTransform * translate_topArm1;
MatrixTransform * translate_topExtendArm1;
MatrixTransform * rotate_topExtendArm1;



//matrix pointer for top arm2
MatrixTransform * translate_topExtendArm2;
MatrixTransform * rotate_topExtendArm2;


//matrix pointer for top arm3
MatrixTransform * translate_topExtendArm3;
MatrixTransform * rotate_topExtendArm3;


//matrix pointer for top arm1
MatrixTransform * rotate_finger1_topArm1;
MatrixTransform * rotate_finger2_topArm1;
MatrixTransform * rotate_finger3_topArm1;
MatrixTransform * translate_finger1_topArm1;
MatrixTransform * translate_finger2_topArm1;
MatrixTransform * translate_finger3_topArm1;

MatrixTransform * rotate_Extendfinger1_topArm1;
MatrixTransform * rotate_Extendfinger2_topArm1;
MatrixTransform * rotate_Extendfinger3_topArm1;
MatrixTransform * translate_Extendfinger1_topArm1;
MatrixTransform * translate_Extendfinger2_topArm1;
MatrixTransform * translate_Extendfinger3_topArm1;

//matrix pointer for top arm2
MatrixTransform * rotate_finger1_topArm2;
MatrixTransform * rotate_finger2_topArm2;
MatrixTransform * rotate_finger3_topArm2;
MatrixTransform * translate_finger1_topArm2;
MatrixTransform * translate_finger2_topArm2;
MatrixTransform * translate_finger3_topArm2;

MatrixTransform * rotate_Extendfinger1_topArm2;
MatrixTransform * rotate_Extendfinger2_topArm2;
MatrixTransform * rotate_Extendfinger3_topArm2;
MatrixTransform * translate_Extendfinger1_topArm2;
MatrixTransform * translate_Extendfinger2_topArm2;
MatrixTransform * translate_Extendfinger3_topArm2;

//matrix pointer for top arm3
MatrixTransform * rotate_finger1_topArm3;
MatrixTransform * rotate_finger2_topArm3;
MatrixTransform * rotate_finger3_topArm3;
MatrixTransform * translate_finger1_topArm3;
MatrixTransform * translate_finger2_topArm3;
MatrixTransform * translate_finger3_topArm3;

MatrixTransform * rotate_Extendfinger1_topArm3;
MatrixTransform * rotate_Extendfinger2_topArm3;
MatrixTransform * rotate_Extendfinger3_topArm3;
MatrixTransform * translate_Extendfinger1_topArm3;
MatrixTransform * translate_Extendfinger2_topArm3;
MatrixTransform * translate_Extendfinger3_topArm3;

MatrixTransform * rotate_topPod1_Arm1;
MatrixTransform * rotate_topPod2_Arm1;
MatrixTransform * rotate_topPod3_Arm1;

MatrixTransform * rotate_topPod1_Arm2;
MatrixTransform * rotate_topPod2_Arm2;
MatrixTransform * rotate_topPod3_Arm2;

MatrixTransform * rotate_topPod1_Arm3;
MatrixTransform * rotate_topPod2_Arm3;
MatrixTransform * rotate_topPod3_Arm3;



//matrix pointer for mid arm1
MatrixTransform * rotate_finger1_midArm1;
MatrixTransform * rotate_finger2_midArm1;
MatrixTransform * rotate_finger3_midArm1;
MatrixTransform * translate_finger1_midArm1;
MatrixTransform * translate_finger2_midArm1;
MatrixTransform * translate_finger3_midArm1;

MatrixTransform * rotate_Extendfinger1_midArm1;
MatrixTransform * rotate_Extendfinger2_midArm1;
MatrixTransform * rotate_Extendfinger3_midArm1;
MatrixTransform * translate_Extendfinger1_midArm1;
MatrixTransform * translate_Extendfinger2_midArm1;
MatrixTransform * translate_Extendfinger3_midArm1;




SceneNode * mid_finger1_midArm1;
SceneNode * mid_finger2_midArm1;
SceneNode * mid_finger3_midArm1;

SceneNode * mid_Extendfinger1_midArm1;
SceneNode * mid_Extendfinger2_midArm1;
SceneNode * mid_Extendfinger3_midArm1;

//matrix pointer for mid arm2
MatrixTransform * rotate_finger1_midArm2 = new MatrixTransform(identity);
MatrixTransform * rotate_finger2_midArm2 = new MatrixTransform(identity);
MatrixTransform * rotate_finger3_midArm2 = new MatrixTransform(identity);
MatrixTransform * translate_finger1_midArm2 = new MatrixTransform(identity);
MatrixTransform * translate_finger2_midArm2 = new MatrixTransform(identity);
MatrixTransform * translate_finger3_midArm2 = new MatrixTransform(identity);

MatrixTransform * rotate_Extendfinger1_midArm2;
MatrixTransform * rotate_Extendfinger2_midArm2;
MatrixTransform * rotate_Extendfinger3_midArm2;
MatrixTransform * translate_Extendfinger1_midArm2;
MatrixTransform * translate_Extendfinger2_midArm2;
MatrixTransform * translate_Extendfinger3_midArm2;

SceneNode * mid_finger1_midArm2;
SceneNode * mid_finger2_midArm2;
SceneNode * mid_finger3_midArm2;

SceneNode * mid_Extendfinger1_midArm2;
SceneNode * mid_Extendfinger2_midArm2;
SceneNode * mid_Extendfinger3_midArm2;

//matrix pointer for mid arm3
MatrixTransform * rotate_finger1_midArm3 = new MatrixTransform(identity);
MatrixTransform * rotate_finger2_midArm3 = new MatrixTransform(identity);
MatrixTransform * rotate_finger3_midArm3 = new MatrixTransform(identity);
MatrixTransform * translate_finger1_midArm3 = new MatrixTransform(identity);
MatrixTransform * translate_finger2_midArm3 = new MatrixTransform(identity);
MatrixTransform * translate_finger3_midArm3 = new MatrixTransform(identity);

MatrixTransform * translate_Extendfinger1_midArm3;
MatrixTransform * translate_Extendfinger2_midArm3;
MatrixTransform * translate_Extendfinger3_midArm3;
MatrixTransform * rotate_Extendfinger1_midArm3;
MatrixTransform * rotate_Extendfinger2_midArm3;
MatrixTransform * rotate_Extendfinger3_midArm3;

SceneNode * mid_finger1_midArm3;
SceneNode * mid_finger2_midArm3;
SceneNode * mid_finger3_midArm3;


SceneNode * mid_Extendfinger1_midArm3;
SceneNode * mid_Extendfinger2_midArm3;
SceneNode * mid_Extendfinger3_midArm3;







////constructing the middle level of the ride////

//matrix pointer for the middle base
MatrixTransform * scale_midBase;
MatrixTransform * translate_midBase;
MatrixTransform * rotate_midBase;


//matrix pointer for the middle arm1
MatrixTransform * scale_midArm1;
MatrixTransform * translate_midArm1;
MatrixTransform * rotate_midArm1;
MatrixTransform * translate2_midArm1;

//matrix pointer for the middle arm2
MatrixTransform * scale_midArm2;
MatrixTransform * translate_midArm2;
MatrixTransform * rotate_midArm2;
MatrixTransform * rotate2_midArm2;
MatrixTransform * scale_midArm3;
MatrixTransform * translate_midArm3;
MatrixTransform * rotate_midArm3;
MatrixTransform * rotate2_midArm3;





//// martrix pointer for the middle extendable arms ////


//extendable middle arm1
MatrixTransform * scale_midExtendArm1;
MatrixTransform * translate_midExtendArm1;
MatrixTransform * rotate_midExtensionArm1;
MatrixTransform * translate2_midExtendArm1;
MatrixTransform * rotate2_midExtensionArm1;

//extendable middle arm2
MatrixTransform * scale_midExtendArm2;
MatrixTransform * translate_midExtendArm2;
MatrixTransform * rotate_midExtensionArm2;
MatrixTransform * translate2_midExtendArm2;
MatrixTransform * rotate2_midExtensionArm2;

//extendable middle arm3
MatrixTransform * scale_midExtendArm3;
MatrixTransform * translate_midExtendArm3;
MatrixTransform * rotate_midExtensionArm3;
MatrixTransform * translate2_midExtendArm3;
MatrixTransform * rotate2_midExtensionArm3;

//pods for middle arms
MatrixTransform * rotate_midPod1_Arm1;
MatrixTransform * rotate_midPod2_Arm1;
MatrixTransform * rotate_midPod3_Arm1;

MatrixTransform * rotate_midPod1_Arm2;
MatrixTransform * rotate_midPod2_Arm2;
MatrixTransform * rotate_midPod3_Arm2;

MatrixTransform * rotate_midPod1_Arm3;
MatrixTransform * rotate_midPod2_Arm3;
MatrixTransform * rotate_midPod3_Arm3;









////constructing the bottom level of the ride////

//matrix pointer for the bottom base
MatrixTransform * scale_bottomBase;
MatrixTransform * rotate_bottomBase;
MatrixTransform * translate_bottomBase;

//matrix pointer for the bottom arm1
MatrixTransform * scale_bottomArm1;
MatrixTransform * translate_bottomArm1;
MatrixTransform * rotate_bottomArm1;

//matrix pointer for the bottom arm2
MatrixTransform * scale_bottomArm2;
MatrixTransform * translate_bottomArm2;
MatrixTransform * rotate1_bottomArm2;
MatrixTransform * rotate2_bottomArm2;

//matrix pointer for the bottom arm3
MatrixTransform * scale_bottomArm3;
MatrixTransform * translate_bottomArm3;
MatrixTransform * rotate1_bottomArm3;
MatrixTransform * rotate2_bottomArm3;



////matrix nodes for the bottom extendable arms////

//extendable bottom arm1
MatrixTransform * scale_bottomExtendArm1;
MatrixTransform * translate_bottomExtendArm1;
MatrixTransform * rotate_bottomExtendArm1;
MatrixTransform * translate2_bottomExtendArm1;
MatrixTransform * scale2_bottomExtendArm1;

//extendable bottom arm2
MatrixTransform * scale_bottomExtendArm2;
MatrixTransform * translate_bottomExtendArm2;
MatrixTransform * rotate_bottomExtendArm2;
MatrixTransform * translate2_bottomExtendArm2;
MatrixTransform * rotate2_bottomExtendArm2;

//extendable bottom arm3
MatrixTransform * scale_bottomExtendArm3;
MatrixTransform * translate_bottomExtendArm3;
MatrixTransform * translate2_bottomExtendArm3;
MatrixTransform * rotate_bottomExtendArm3;
MatrixTransform * rotate2_bottomExtendArm3;




////matrix nodes for fingers on bottom arm1////

//matrix for bottom finger1 on arm1
MatrixTransform * scale_bottomFinger1_Arm1;
MatrixTransform * translate_bottomFinger1_Arm1;
MatrixTransform * translate2_bottomFinger1_Arm1;
MatrixTransform * rotate_bottomFinger1_Arm1;
MatrixTransform * translate3_bottomFinger1_Arm1;
MatrixTransform * rotate2_bottomFinger1_Arm1;


//matrix for bottom finger2 on arm1
MatrixTransform * scale_bottomFinger2_Arm1;
MatrixTransform * translate_bottomFinger2_Arm1;
MatrixTransform * translate2_bottomFinger2_Arm1;
MatrixTransform * rotate_bottomFinger2_Arm1;
MatrixTransform * translate3_bottomFinger2_Arm1;
MatrixTransform * rotate2_bottomFinger2_Arm1;


//matrix for bottom finger3 on arm1
MatrixTransform * scale_bottomFinger3_Arm1;
MatrixTransform * translate_bottomFinger3_Arm1;
MatrixTransform * translate2_bottomFinger3_Arm1;
MatrixTransform * rotate_bottomFinger3_Arm1;
MatrixTransform * translate3_bottomFinger3_Arm1;
MatrixTransform * rotate2_bottomFinger3_Arm1;




////matrix nodes for fingers on bottom arm2////

//matrix for bottom finger1 on arm2
MatrixTransform * scale_bottomFinger1_Arm2;
MatrixTransform * rotate_bottomFinger1_Arm2;
MatrixTransform * translate_bottomFinger1_Arm2;
MatrixTransform * translate2_bottomFinger1_Arm2;
MatrixTransform * rotate2_bottomFinger1_Arm2;
MatrixTransform * translate3_bottomFinger1_Arm2;

//matrix for bottom finger2 on arm2
MatrixTransform * scale_bottomFinger2_Arm2;
MatrixTransform * rotate_bottomFinger2_Arm2;
MatrixTransform * translate_bottomFinger2_Arm2;
MatrixTransform * translate2_bottomFinger2_Arm2;
MatrixTransform * rotate2_bottomFinger2_Arm2;
MatrixTransform * translate3_bottomFinger2_Arm2;

//matrix for bottom finger3 on arm2
MatrixTransform * scale_bottomFinger3_Arm2;
MatrixTransform * rotate_bottomFinger3_Arm2;
MatrixTransform * translate_bottomFinger3_Arm2;
MatrixTransform * translate2_bottomFinger3_Arm2;
MatrixTransform * rotate2_bottomFinger3_Arm2;
MatrixTransform * translate3_bottomFinger3_Arm2;




////matrix nodes for fingers on bottom arm3////

//matrix for bottom finger1 on arm3
MatrixTransform * scale_bottomFinger1_Arm3;
MatrixTransform * rotate_bottomFinger1_Arm3;
MatrixTransform * translate_bottomFinger1_Arm3;
MatrixTransform * translate2_bottomFinger1_Arm3;
MatrixTransform * rotate2_bottomFinger1_Arm3;
MatrixTransform * translate3_bottomFinger1_Arm3;

//matrix for bottom finger2 on arm3
MatrixTransform * scale_bottomFinger2_Arm3;
MatrixTransform * rotate_bottomFinger2_Arm3;
MatrixTransform * translate_bottomFinger2_Arm3;
MatrixTransform * translate2_bottomFinger2_Arm3;
MatrixTransform * rotate2_bottomFinger2_Arm3;
MatrixTransform * translate3_bottomFinger2_Arm3;

//matrix for bottom finger3 on arm3
MatrixTransform * scale_bottomFinger3_Arm3;
MatrixTransform * rotate_bottomFinger3_Arm3;
MatrixTransform * translate_bottomFinger3_Arm3;
MatrixTransform * translate2_bottomFinger3_Arm3;
MatrixTransform * rotate2_bottomFinger3_Arm3;
MatrixTransform * translate3_bottomFinger3_Arm3;







////extending fingers for bottom arm1////


//matrix for bottom finger1 extending on arm1
MatrixTransform * scale_bottomExtFinger1_Arm1;
MatrixTransform * translate_bottomExtFinger1_Arm1;
MatrixTransform * translate2_bottomExtFinger1_Arm1;
MatrixTransform * rotate_bottomExtFinger1_Arm1;
MatrixTransform * translate3_bottomExtFinger1_Arm1;
MatrixTransform * rotate2_bottomExtFinger1_Arm1;

//matrix for bottom finger2 extending on arm1
MatrixTransform * scale_bottomExtFinger2_Arm1;
MatrixTransform * translate_bottomExtFinger2_Arm1;
MatrixTransform * translate2_bottomExtFinger2_Arm1;
MatrixTransform * rotate_bottomExtFinger2_Arm1;
MatrixTransform * translate3_bottomExtFinger2_Arm1;
MatrixTransform * rotate2_bottomExtFinger2_Arm1;

//matrix for bottom finger3 extending on arm1
MatrixTransform * scale_bottomExtFinger3_Arm1;
MatrixTransform * rotate_bottomExtFinger3_Arm1;
MatrixTransform * translate_bottomExtFinger3_Arm1;
MatrixTransform * translate2_bottomExtFinger3_Arm1;
MatrixTransform * rotate2_bottomExtFinger3_Arm1;
MatrixTransform * translate3_bottomExtFinger3_Arm1;




////extending fingers for bottom arm2////

//matrix for bottom finger1 extending on arm2
MatrixTransform * scale_bottomExtFinger1_Arm2;
MatrixTransform * rotate_bottomExtFinger1_Arm2;
MatrixTransform * translate_bottomExtFinger1_Arm2;
MatrixTransform * translate2_bottomExtFinger1_Arm2;
MatrixTransform * rotate2_bottomExtFinger1_Arm2;
MatrixTransform * translate3_bottomExtFinger1_Arm2;

//matrix for bottom finger2 extending on arm2
MatrixTransform * scale_bottomExtFinger2_Arm2;
MatrixTransform * rotate_bottomExtFinger2_Arm2;
MatrixTransform * translate_bottomExtFinger2_Arm2;
MatrixTransform * translate2_bottomExtFinger2_Arm2;
MatrixTransform * rotate2_bottomExtFinger2_Arm2;
MatrixTransform * translate3_bottomExtFinger2_Arm2;

//matrix for bottom finger3 extending on arm2
MatrixTransform * scale_bottomExtFinger3_Arm2;
MatrixTransform * rotate_bottomExtFinger3_Arm2;
MatrixTransform * translate_bottomExtFinger3_Arm2;
MatrixTransform * translate2_bottomExtFinger3_Arm2;
MatrixTransform * rotate2_bottomExtFinger3_Arm2;
MatrixTransform * translate3_bottomExtFinger3_Arm2;

//matrix for bottom finger1 extending on arm3
MatrixTransform * scale_bottomExtFinger1_Arm3;
MatrixTransform * rotate_bottomExtFinger1_Arm3;
MatrixTransform * translate_bottomExtFinger1_Arm3;
MatrixTransform * translate2_bottomExtFinger1_Arm3;
MatrixTransform * rotate2_bottomExtFinger1_Arm3;
MatrixTransform * translate3_bottomExtFinger1_Arm3;

//matrix for bottom finger2 extending on arm3
MatrixTransform * scale_bottomExtFinger2_Arm3;
MatrixTransform * rotate_bottomExtFinger2_Arm3;
MatrixTransform * translate_bottomExtFinger2_Arm3;
MatrixTransform * translate2_bottomExtFinger2_Arm3;
MatrixTransform * rotate2_bottomExtFinger2_Arm3;
MatrixTransform * translate3_bottomExtFinger2_Arm3;

//matrix for bottom finger3 extending on arm3
MatrixTransform * scale_bottomExtFinger3_Arm3;
MatrixTransform * rotate_bottomExtFinger3_Arm3;
MatrixTransform * translate_bottomExtFinger3_Arm3;
MatrixTransform * translate2_bottomExtFinger3_Arm3;
MatrixTransform * rotate2_bottomExtFinger3_Arm3;
MatrixTransform * translate3_bottomExtFinger3_Arm3;

////////// matrices for bottom arm1 //////////

//matrix bottom pod1 for arm1
MatrixTransform * scale_bottomPod1_Arm1;
MatrixTransform * rotate_bottomPod1_Arm1;
MatrixTransform * translate_bottomPod1_Arm1;
MatrixTransform * translate2_bottomPod1_Arm1;

//matrix bottom pod2 for arm1
MatrixTransform * scale_bottomPod2_Arm1;
MatrixTransform * rotate_bottomPod2_Arm1;
MatrixTransform * translate_bottomPod2_Arm1;
MatrixTransform * translate2_bottomPod2_Arm1;

//matrix bottom pod3 for arm1
MatrixTransform * scale_bottomPod3_Arm1;
MatrixTransform * rotate_bottomPod3_Arm1;
MatrixTransform * translate_bottomPod3_Arm1;
MatrixTransform * translate2_bottomPod3_Arm1;

////////// matrices for bottom arm2 //////////

//matrix bottom pod1 for arm1
MatrixTransform * scale_bottomPod1_Arm2;
MatrixTransform * rotate_bottomPod1_Arm2;
MatrixTransform * translate_bottomPod1_Arm2;
MatrixTransform * translate2_bottomPod1_Arm2;

//matrix bottom pod2 for arm1
MatrixTransform * scale_bottomPod2_Arm2;
MatrixTransform * rotate_bottomPod2_Arm2;
MatrixTransform * translate_bottomPod2_Arm2;
MatrixTransform * translate2_bottomPod2_Arm2;

//matrix bottom pod3 for arm1
MatrixTransform * scale_bottomPod3_Arm2;
MatrixTransform * rotate_bottomPod3_Arm2;
MatrixTransform * translate_bottomPod3_Arm2;
MatrixTransform * translate2_bottomPod3_Arm2;

////////// matrices for bottom arm3 //////////

//matrix bottom pod1 for arm1
MatrixTransform * scale_bottomPod1_Arm3;
MatrixTransform * rotate_bottomPod1_Arm3;
MatrixTransform * translate_bottomPod1_Arm3;
MatrixTransform * translate2_bottomPod1_Arm3;

//matrix bottom pod1 for arm2
MatrixTransform * scale_bottomPod2_Arm3;
MatrixTransform * rotate_bottomPod2_Arm3;
MatrixTransform * translate_bottomPod2_Arm3;
MatrixTransform * translate2_bottomPod2_Arm3;

//matrix bottom pod1 for arm3
MatrixTransform * scale_bottomPod3_Arm3;
MatrixTransform * rotate_bottomPod3_Arm3;
MatrixTransform * translate_bottomPod3_Arm3;
MatrixTransform * translate2_bottomPod3_Arm3;




////////// smallBase for bottom arms //////////


//matrix for smallBase bottom arm1
MatrixTransform * scale_smallBase_Arm1;
MatrixTransform * translate_smallBase_Arm1;
MatrixTransform * translate2_smallBase_Arm1;

//matrix for smallBase bottom arm2
MatrixTransform * scale_smallBase_Arm2;
MatrixTransform * translate_smallBase_Arm2;
MatrixTransform * translate2_smallBase_Arm2;

//matrix for smallBase bottom arm3
MatrixTransform * scale_smallBase_Arm3;
MatrixTransform * translate_smallBase_Arm3;
MatrixTransform * translate2_smallBase_Arm3;





////top geodes////
SceneNode * top_base;



//geode pointer for the top arms
SceneNode * top_arm1;
SceneNode * top_arm2;
SceneNode * top_arm3;
SceneNode * top_arm1Extend;
SceneNode * top_arm2Extend;
SceneNode * top_arm3Extend;




////middle geodes////
SceneNode * mid_pod1_Arm1;
SceneNode * mid_pod2_Arm1;
SceneNode * mid_pod3_Arm1;

SceneNode * mid_pod1_Arm2;
Geode * mid_pod2_Arm2;
SceneNode * mid_pod3_Arm2;

SceneNode * mid_pod1_Arm3;
SceneNode * mid_pod2_Arm3;
SceneNode * mid_pod3_Arm3;






//geode pointer for the middle base
SceneNode * mid_base;


//geode pointer for the middle arms
SceneNode * mid_arm1;
SceneNode * mid_arm2;
SceneNode * mid_arm3;





////bottom geodes////


//geode pointer for the bottom base
SceneNode * bottom_base;

//geode pointers for the bottom arms
SceneNode * bottom_arm1;
SceneNode * bottom_arm2;
SceneNode * bottom_arm3;

//geode pointers for the bottom arm extensions
SceneNode * bottom_arm1Extend;
SceneNode * bottom_arm2Extend;
SceneNode * bottom_arm3Extend;

//geode pointer for fingers on arm1
SceneNode * bottom_finger1_arm1;
SceneNode * bottom_finger2_arm1;
SceneNode * bottom_finger3_arm1;

//geode pointer for fingers on arm2
SceneNode * bottom_finger1_arm2;
SceneNode * bottom_finger2_arm2;
SceneNode * bottom_finger3_arm2;

//geode pointer for fingers on arm3
SceneNode * bottom_finger1_arm3;
SceneNode * bottom_finger2_arm3;
SceneNode * bottom_finger3_arm3;

//geode pointer for one set extending fingers on arm1
SceneNode * bottom_ExtFinger1_arm1;
SceneNode * bottom_ExtFinger2_arm1;
SceneNode * bottom_ExtFinger3_arm1;

//geode pointer for one set extending fingers on arm2
SceneNode * bottom_ExtFinger1_arm2;
SceneNode * bottom_ExtFinger2_arm2;
SceneNode * bottom_ExtFinger3_arm2;

//geode pointer for one set extending fingers on arm3
SceneNode * bottom_ExtFinger1_arm3;
SceneNode * bottom_ExtFinger2_arm3;
SceneNode * bottom_ExtFinger3_arm3;

//geode pointer for pods on arm1
SceneNode * bottom_pod1_Arm1;
SceneNode * bottom_pod2_Arm1;
SceneNode * bottom_pod3_Arm1;

//geode pointer for pods on arm2
SceneNode * bottom_pod1_Arm2;
SceneNode * bottom_pod2_Arm2;
SceneNode * bottom_pod3_Arm2;

//geode pointer for pods on arm3
SceneNode * bottom_pod1_Arm3;
SceneNode * bottom_pod2_Arm3;
SceneNode * bottom_pod3_Arm3;




//geode pointer for bottom small base
SceneNode * bottom_smallBase_Arm1;
SceneNode * bottom_smallBase_Arm2;
SceneNode * bottom_smallBase_Arm3;



//bear
Geode * bearPointer;


using namespace std;


void Window::initialize_objects(){
    
    cube = new Cube();
    
    skyBox = new skyBoxObject(4);
    
    cylinder = new OBJObject("/Users/ReloadSyndrome/Documents/PA3/PA3/cylinder.obj");
    
    //cylinder materials
    cylinder -> ambientMat = glm::vec3(0.25f, 0.20725f, 0.20725f);
    cylinder -> diffuseMat = glm::vec3(1.0f, 0.829f, 0.829f);
    cylinder -> specMat = glm::vec3(0.296648f, 0.296648f, 0.296648f);
    cylinder -> shininess = 11.264f;
    
    pod = new OBJObject("/Users/ReloadSyndrome/Documents/PA3/PA3/pod.obj");
    
    //pod materials
    pod -> ambientMat = glm::vec3(0.0f,0.0f,0.0f);
    pod -> diffuseMat = glm::vec3(0.5f,0.0f,0.0f);
    pod -> specMat = glm::vec3(0.7f,0.6f,0.6f);
    pod -> shininess = 32.0f;
    
    
    
    bear = new OBJObject("/Users/ReloadSyndrome/Documents/Objects_and_Textures/Objects/bear.obj");
    
    //bear materials
    bear -> ambientMat = glm::vec3(0.2125f, 0.1275f, 0.054f);
    bear -> diffuseMat = glm::vec3(0.714f, 0.4284f, 0.18144f);
    bear -> specMat = glm::vec3(0.393548f, 0.271906f, 0.166721f);
    bear -> shininess = 25.6f;
    
    
    
    CakeRide cakeRide;
    
    
    
    //node for top base
    top_base = new Geode(cylinder);
    
    

    //node for middle base
    mid_base = new Geode(cylinder);
    
    
    //nodes for top arms and fingers
    SceneNode * top_arm1 = new Geode(cylinder);
    SceneNode * top_arm2 = new Geode(cylinder);
    SceneNode * top_arm3 = new Geode(cylinder);
    SceneNode * top_arm1Extend = new Geode(cylinder);
    SceneNode * top_arm2Extend = new Geode(cylinder);
    SceneNode * top_arm3Extend = new Geode(cylinder);
    SceneNode * top_finger1_topArm1 = new Geode(cylinder);
    SceneNode * top_finger2_topArm1 = new Geode(cylinder);
    SceneNode * top_finger3_topArm1 = new Geode(cylinder);
    SceneNode * top_Extendfinger1_topArm1 = new Geode(cylinder);
    SceneNode * top_Extendfinger2_topArm1 = new Geode(cylinder);
    SceneNode * top_Extendfinger3_topArm1 = new Geode(cylinder);
    
    SceneNode * top_finger1_topArm2 = new Geode(cylinder);
    SceneNode * top_finger2_topArm2 = new Geode(cylinder);
    SceneNode * top_finger3_topArm2 = new Geode(cylinder);
    SceneNode * top_Extendfinger1_topArm2 = new Geode(cylinder);
    SceneNode * top_Extendfinger2_topArm2 = new Geode(cylinder);
    SceneNode * top_Extendfinger3_topArm2 = new Geode(cylinder);
    
    SceneNode * top_finger1_topArm3 = new Geode(cylinder);
    SceneNode * top_finger2_topArm3 = new Geode(cylinder);
    SceneNode * top_finger3_topArm3 = new Geode(cylinder);
    SceneNode * top_Extendfinger1_topArm3 = new Geode(cylinder);
    SceneNode * top_Extendfinger2_topArm3 = new Geode(cylinder);
    SceneNode * top_Extendfinger3_topArm3 = new Geode(cylinder);
    
    
    
    
    
    
    
    
    SceneNode * top_pod1_Arm1 = new Geode(pod);
    SceneNode * top_pod2_Arm1 = new Geode(pod);
    SceneNode * top_pod3_Arm1 = new Geode(pod);
    
    SceneNode * top_pod1_Arm2 = new Geode(pod);
    SceneNode * top_pod2_Arm2 = new Geode(pod);
    SceneNode * top_pod3_Arm2 = new Geode(pod);
    
    SceneNode * top_pod1_Arm3 = new Geode(pod);
    SceneNode * top_pod2_Arm3 = new Geode(pod);
    SceneNode * top_pod3_Arm3 = new Geode(pod);
    
    SceneNode * top_smallBase_Arm1 = new Geode(cylinder);
    SceneNode * top_smallBase_Arm2 = new Geode(cylinder);
    SceneNode * top_smallBase_Arm3 = new Geode(cylinder);
    
    
    
    
////////// middle geodes //////////
    
    
    //nodes for middle arms and fingers
    SceneNode * mid_arm1 = new Geode(cylinder);
    SceneNode * mid_arm2 = new Geode(cylinder);
    SceneNode * mid_arm3 = new Geode(cylinder);

    
    SceneNode * mid_arm1Extend = new Geode(cylinder);
    SceneNode * mid_arm2Extend = new Geode(cylinder);
    SceneNode * mid_arm3Extend = new Geode(cylinder);
    
    SceneNode * mid_finger1_midArm1 = new Geode(cylinder);
    SceneNode * mid_finger2_midArm1 = new Geode(cylinder);
    SceneNode * mid_finger3_midArm1 = new Geode(cylinder);
    
    SceneNode * mid_finger1_midArm2 = new Geode(cylinder);
    SceneNode * mid_finger2_midArm2 = new Geode(cylinder);
    SceneNode * mid_finger3_midArm2 = new Geode(cylinder);
    
    SceneNode * mid_finger1_midArm3 = new Geode(cylinder);
    SceneNode * mid_finger2_midArm3 = new Geode(cylinder);
    SceneNode * mid_finger3_midArm3 = new Geode(cylinder);
    
    SceneNode * mid_Extendfinger1_midArm1 = new Geode(cylinder);
    SceneNode * mid_Extendfinger2_midArm1 = new Geode(cylinder);
    SceneNode * mid_Extendfinger3_midArm1 = new Geode(cylinder);
    
    SceneNode * mid_Extendfinger1_midArm2 = new Geode(cylinder);
    SceneNode * mid_Extendfinger2_midArm2 = new Geode(cylinder);
    SceneNode * mid_Extendfinger3_midArm2 = new Geode(cylinder);
    
    SceneNode * mid_Extendfinger1_midArm3 = new Geode(cylinder);
    SceneNode * mid_Extendfinger2_midArm3 = new Geode(cylinder);
    SceneNode * mid_Extendfinger3_midArm3 = new Geode(cylinder);
    
    SceneNode * mid_pod1_Arm1 = new Geode(pod);
    SceneNode * mid_pod2_Arm1 = new Geode(pod);
    SceneNode * mid_pod3_Arm1 = new Geode(pod);
    
    SceneNode * mid_pod1_Arm2 = new Geode(pod);
    Geode * mid_pod2_Arm2 = new Geode(pod);
    SceneNode * mid_pod3_Arm2 = new Geode(pod);
    
    SceneNode * mid_pod1_Arm3 = new Geode(pod);
    SceneNode * mid_pod2_Arm3 = new Geode(pod);
    SceneNode * mid_pod3_Arm3 = new Geode(pod);
    
    SceneNode * mid_smallBase_Arm1 = new Geode(cylinder);
    SceneNode * mid_smallBase_Arm2 = new Geode(cylinder);
    SceneNode * mid_smallBase_Arm3 = new Geode(cylinder);
    
    
////////// bottom geodes //////////
    
    //node for bottom base
    bottom_base = new Geode(cylinder);
    
    //nodes for bottom arms
    bottom_arm1 = new Geode(cylinder);
    bottom_arm2 = new Geode(cylinder);
    bottom_arm3 = new Geode(cylinder);
    
    //nodes for bottom extending arms
    bottom_arm1Extend = new Geode(cylinder);
    bottom_arm2Extend = new Geode(cylinder);
    bottom_arm3Extend = new Geode(cylinder);
    
    //nodes for bottom fingers on arm1
    bottom_finger1_arm1 = new Geode(cylinder);
    bottom_finger2_arm1 = new Geode(cylinder);
    bottom_finger3_arm1 = new Geode(cylinder);
    
    //nodes for bottom extending finger on arm1
    bottom_ExtFinger1_arm1 = new Geode(cylinder);
    bottom_ExtFinger2_arm1 = new Geode(cylinder);
    bottom_ExtFinger3_arm1 = new Geode(cylinder);
    
    //nodes for bottom fingers on arm2
    bottom_finger1_arm2 = new Geode(cylinder);
    bottom_finger2_arm2 = new Geode(cylinder);
    bottom_finger3_arm2 = new Geode(cylinder);
    
    //nodes for bottom extending finger on arm2
    bottom_ExtFinger1_arm2 = new Geode(cylinder);
    bottom_ExtFinger2_arm2 = new Geode(cylinder);
    bottom_ExtFinger3_arm2 = new Geode(cylinder);
    
    //nodes for bottom fingers on arm3
    bottom_finger1_arm3 = new Geode(cylinder);
    bottom_finger2_arm3 = new Geode(cylinder);
    bottom_finger3_arm3 = new Geode(cylinder);
    
    //nodes for bottom extending finger on arm3
    bottom_ExtFinger1_arm3 = new Geode(cylinder);
    bottom_ExtFinger2_arm3 = new Geode(cylinder);
    bottom_ExtFinger3_arm3 = new Geode(cylinder);
    
    //nodes for bottom pods on arm1
    bottom_pod1_Arm1 = new Geode(pod);
    bottom_pod2_Arm1 = new Geode(pod);
    bottom_pod3_Arm1 = new Geode(pod);
    
    //nodes for bottom pods on arm2
    bottom_pod1_Arm2 = new Geode(pod);
    bottom_pod2_Arm2 = new Geode(pod);
    bottom_pod3_Arm2 = new Geode(pod);
    
    //nodes for bottom pods on arm3
    bottom_pod1_Arm3 = new Geode(pod);
    bottom_pod2_Arm3 = new Geode(pod);
    bottom_pod3_Arm3 = new Geode(pod);
    
    
    //nodes for smallBase bottom arms
    bottom_smallBase_Arm1 = new Geode(cylinder);
    bottom_smallBase_Arm2 = new Geode(cylinder);
    bottom_smallBase_Arm3 = new Geode(cylinder);
    
    
    
    
    //node for bear
    bearPointer = new Geode(bear);
    
    
    
    
    //main rotationMatrix for ride
    ride -> addChild(mainRotationMatrix);
    mainRotationMatrix -> addChild(topRotationMatrix);
    mainRotationMatrix -> addChild(middleRotationMatrix);
    mainRotationMatrix -> addChild(bottomRotationMatrix);
    
    
    
    ////top base
    cakeRide.addBase(topRotationMatrix, scale_topBase, translate_topBase, rotate_topBase, top_base, glm::vec3(0.84f, 10.0f, 0.84f), glm::vec3(0.0f, 5.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), 0.0f);
    
    //top arm1
    cakeRide.addArmUp(translate_topBase, translate_topArm1, top_arm1, glm::vec3(0.0f, 4.8f, 0.0f));
    
    //top arm2
    cakeRide.addArmUpR(translate_topArm1, top_arm2, 120.0f/180.0f * glm::pi<float>());
    
    //top arm3
    cakeRide.addArmUpR(translate_topArm1, top_arm3, -120.0f/180.0f * glm::pi<float>());
    
    //top arm1Extend
    cakeRide.addExtendArmUp(translate_topArm1, translate_topExtendArm1, rotate_topExtendArm1, top_arm1Extend, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), 0.0f/180.0f * glm::pi<float>());
    
    //top arm2Extend
    cakeRide.addExtendArmUp(translate_topArm1, translate_topExtendArm2, rotate_topExtendArm2, top_arm2Extend, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), 120.0f/180.0f * glm::pi<float>());
    
    //top arm2Extend
    cakeRide.addExtendArmUp(translate_topArm1, translate_topExtendArm3, rotate_topExtendArm3, top_arm3Extend, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), -120.0f/180.0f * glm::pi<float>());
    
    
    //top fingers arm1
    cakeRide.addFingerUp(translate_topExtendArm1, rotate_finger1_topArm1, translate_finger1_topArm1, top_finger1_topArm1, 0.0f/180.0f * glm::pi<float>());
    
    cakeRide.addFingerUpR(rotate_finger1_topArm1, rotate_finger2_topArm1, translate_finger2_topArm1, top_finger2_topArm1, 120.0f/180.0f * glm::pi<float>());
    
    cakeRide.addFingerUpR(rotate_finger1_topArm1, rotate_finger3_topArm1, translate_finger3_topArm1, top_finger3_topArm1, -120.0f/180.0f * glm::pi<float>());
    
    //top extension finger arm1
    cakeRide.addFingerUpR(rotate_finger1_topArm1, rotate_Extendfinger1_topArm1, translate_Extendfinger1_topArm1, top_Extendfinger1_topArm1, 0.0f/180.0f * glm::pi<float>());
    
    cakeRide.addFingerUpR(rotate_finger1_topArm1, rotate_Extendfinger2_topArm1, translate_Extendfinger2_topArm1, top_Extendfinger2_topArm1, 120.0f/180.0f * glm::pi<float>());
    
    cakeRide.addFingerUpR(rotate_finger1_topArm1, rotate_Extendfinger3_topArm1, translate_Extendfinger3_topArm1, top_Extendfinger3_topArm1, -120.0f/180.0f * glm::pi<float>());
    
    
    //top fingers arm2
    cakeRide.addFingerUp(translate_topExtendArm2, rotate_finger1_topArm2, translate_finger1_topArm2, top_finger1_topArm2, 0.0f/180.0f * glm::pi<float>());
    
    cakeRide.addFingerUpR(rotate_finger1_topArm2, rotate_finger2_topArm2, translate_finger2_topArm2, top_finger2_topArm2, 120.0f/180.0f * glm::pi<float>());
    
    cakeRide.addFingerUpR(rotate_finger1_topArm2, rotate_finger3_topArm2, translate_finger3_topArm2, top_finger3_topArm2, -120.0f/180.0f * glm::pi<float>());
    
    //top extension finger arm2
    cakeRide.addFingerUpR(rotate_finger1_topArm2, rotate_Extendfinger1_topArm2, translate_Extendfinger1_topArm2, top_Extendfinger1_topArm2, 0.0f/180.0f * glm::pi<float>());
    
    cakeRide.addFingerUpR(rotate_finger1_topArm2, rotate_Extendfinger2_topArm2, translate_Extendfinger2_topArm2, top_Extendfinger2_topArm2, 120.0f/180.0f * glm::pi<float>());
    
    cakeRide.addFingerUpR(rotate_finger1_topArm2, rotate_Extendfinger3_topArm2, translate_Extendfinger3_topArm2, top_Extendfinger3_topArm2, -120.0f/180.0f * glm::pi<float>());
    
    
    //top fingers arm3
    cakeRide.addFingerUp(translate_topExtendArm3, rotate_finger1_topArm3, translate_finger1_topArm3, top_finger1_topArm3, 0.0f/180.0f * glm::pi<float>());
    
    cakeRide.addFingerUpR(rotate_finger1_topArm3, rotate_finger2_topArm3, translate_finger2_topArm3, top_finger2_topArm3, 120.0f/180.0f * glm::pi<float>());
    
    cakeRide.addFingerUpR(rotate_finger1_topArm3, rotate_finger3_topArm3, translate_finger3_topArm3, top_finger3_topArm3, -120.0f/180.0f * glm::pi<float>());
    
    //top extension finger arm3
    cakeRide.addFingerUpR(rotate_finger1_topArm3, rotate_Extendfinger1_topArm3, translate_Extendfinger1_topArm3, top_Extendfinger1_topArm3, 0.0f/180.0f * glm::pi<float>());
    
    cakeRide.addFingerUpR(rotate_finger1_topArm3, rotate_Extendfinger2_topArm3, translate_Extendfinger2_topArm3, top_Extendfinger2_topArm3, 120.0f/180.0f * glm::pi<float>());
    
    cakeRide.addFingerUpR(rotate_finger1_topArm3, rotate_Extendfinger3_topArm3, translate_Extendfinger3_topArm3, top_Extendfinger3_topArm3, -120.0f/180.0f * glm::pi<float>());
    
////////// top pods and small base covers //////////
    
    cakeRide.addPodUp(translate_Extendfinger1_topArm1, rotate_topPod1_Arm1, top_pod1_Arm1);
    cakeRide.addPodUp(translate_Extendfinger2_topArm1, rotate_topPod2_Arm1, top_pod2_Arm1);
    cakeRide.addPodUp(translate_Extendfinger3_topArm1, rotate_topPod3_Arm1, top_pod3_Arm1);
    
    cakeRide.addPodUp(translate_Extendfinger1_topArm2, rotate_topPod1_Arm2, top_pod1_Arm2);
    cakeRide.addPodUp(translate_Extendfinger2_topArm2, rotate_topPod2_Arm2, top_pod2_Arm2);
    cakeRide.addPodUp(translate_Extendfinger3_topArm2, rotate_topPod3_Arm2, top_pod3_Arm2);
    
    cakeRide.addPodUp(translate_Extendfinger1_topArm3, rotate_topPod1_Arm3, top_pod1_Arm3);
    cakeRide.addPodUp(translate_Extendfinger2_topArm3, rotate_topPod2_Arm3, top_pod2_Arm3);
    cakeRide.addPodUp(translate_Extendfinger3_topArm3, rotate_topPod3_Arm3, top_pod3_Arm3);
    
    
    cakeRide.addSmallBase(translate_topExtendArm1, top_smallBase_Arm1);
    cakeRide.addSmallBase(translate_topExtendArm2, top_smallBase_Arm2);
    cakeRide.addSmallBase(translate_topExtendArm3, top_smallBase_Arm3);
    
    
    
    
    
    
    
    ////middle base
    cakeRide.addBase(middleRotationMatrix, scale_midBase, translate_midBase, rotate_midBase, mid_base, glm::vec3(0.92f, 6.0f, 0.92f), glm::vec3(0.0f, 3.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), 0.0f);
    
    //middle arm1
    cakeRide.addArmUp(translate_midBase, translate2_midArm1, mid_arm1, glm::vec3(0.0f, 2.5f, 0.0f));
    
    //middle arm2
    cakeRide.addArmUpR(translate2_midArm1, mid_arm2, 120.0f/180.0f * glm::pi<float>());
    
    //middle arm3
    cakeRide.addArmUpR(translate2_midArm1, mid_arm3, -120.0f/180.0f * glm::pi<float>());
    
    //middle extension arm1
    cakeRide.addExtendArmUp(translate2_midArm1, translate2_midExtendArm1, rotate2_midExtensionArm1, mid_arm1Extend, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), 0.0f/180.0f * glm::pi<float>());

    //middle extension arm2
    cakeRide.addExtendArmUp(translate2_midArm1, translate2_midExtendArm2, rotate2_midExtensionArm2, mid_arm2Extend, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), 120.0f/180.0f * glm::pi<float>());
    
    //middle extension arm3
    cakeRide.addExtendArmUp(translate2_midArm1, translate2_midExtendArm3, rotate2_midExtensionArm3, mid_arm3Extend, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), -120.0f/180.0f * glm::pi<float>());

    
    
    //middle fingers arm1
    cakeRide.addFingerUp(translate2_midExtendArm1, rotate_finger1_midArm1, translate_finger1_midArm1, mid_finger1_midArm1, 0.0f/180.0f * glm::pi<float>());
    
    cakeRide.addFingerUpR(rotate_finger1_midArm1, rotate_finger2_midArm1, translate_finger2_midArm1, mid_finger2_midArm1, 120.0f/180.0f * glm::pi<float>());
    
    cakeRide.addFingerUpR(rotate_finger1_midArm1, rotate_finger3_midArm1, translate_finger3_midArm1, mid_finger3_midArm1, -120.0f/180.0f * glm::pi<float>());
    
    //middle extension finger arm1
    cakeRide.addFingerUpR(rotate_finger1_midArm1, rotate_Extendfinger1_midArm1, translate_Extendfinger1_midArm1, mid_Extendfinger1_midArm1, 0.0f/180.0f * glm::pi<float>());
    
    cakeRide.addFingerUpR(rotate_finger1_midArm1, rotate_Extendfinger2_midArm1, translate_Extendfinger2_midArm1, mid_Extendfinger2_midArm1, 120.0f/180.0f * glm::pi<float>());
    
    cakeRide.addFingerUpR(rotate_finger1_midArm1, rotate_Extendfinger3_midArm1, translate_Extendfinger3_midArm1, mid_Extendfinger3_midArm1, -120.0f/180.0f * glm::pi<float>());
    
    //middle fingers arm2
    cakeRide.addFingerUp(translate2_midExtendArm2, rotate_finger1_midArm2, translate_finger1_midArm2, mid_finger1_midArm2, 0.0f/180.0f * glm::pi<float>());
    
    cakeRide.addFingerUpR(rotate_finger1_midArm2, rotate_finger2_midArm2, translate_finger2_midArm2, mid_finger2_midArm2, 120.0f/180.0f * glm::pi<float>());
    
    cakeRide.addFingerUpR(rotate_finger1_midArm2, rotate_finger3_midArm2, translate_finger3_midArm2, mid_finger3_midArm2, -120.0f/180.0f * glm::pi<float>());
    
    //middle extension fingers arm2
    cakeRide.addFingerUpR(rotate_finger1_midArm2, rotate_Extendfinger1_midArm2, translate_Extendfinger1_midArm2, mid_Extendfinger1_midArm2, 0.0f/180.0f * glm::pi<float>());
    
    cakeRide.addFingerUpR(rotate_finger1_midArm2, rotate_Extendfinger2_midArm2, translate_Extendfinger2_midArm2, mid_Extendfinger2_midArm2, 120.0f/180.0f * glm::pi<float>());
    
    cakeRide.addFingerUpR(rotate_finger1_midArm2, rotate_Extendfinger3_midArm2, translate_Extendfinger3_midArm2, mid_Extendfinger3_midArm2, -120.0f/180.0f * glm::pi<float>());
    
    //middle fingers arm3
    cakeRide.addFingerUp(translate2_midExtendArm3, rotate_finger1_midArm3, translate_finger1_midArm3, mid_finger1_midArm3, 0.0f/180.0f * glm::pi<float>());
    
    cakeRide.addFingerUpR(rotate_finger1_midArm3, rotate_finger2_midArm3, translate_finger2_midArm3, mid_finger2_midArm3, 120.0f/180.0f * glm::pi<float>());
    
    cakeRide.addFingerUpR(rotate_finger1_midArm3, rotate_finger3_midArm3, translate_finger3_midArm3, mid_finger3_midArm3, -120.0f/180.0f * glm::pi<float>());
    
    //middle extenstion fingers arm3
    cakeRide.addFingerUpR(rotate_finger1_midArm3, rotate_Extendfinger1_midArm3, translate_Extendfinger1_midArm3, mid_Extendfinger1_midArm3, 0.0f/180.0f * glm::pi<float>());
    
    cakeRide.addFingerUpR(rotate_finger1_midArm3, rotate_Extendfinger2_midArm3, translate_Extendfinger2_midArm3, mid_Extendfinger2_midArm3, 120.0f/180.0f * glm::pi<float>());
    
    cakeRide.addFingerUpR(rotate_finger1_midArm3, rotate_Extendfinger3_midArm3, translate_Extendfinger3_midArm3, mid_Extendfinger3_midArm3, -120.0f/180.0f * glm::pi<float>());

    
////////// middle pods and small base covers//////////
    
    cakeRide.addPodUp(translate_Extendfinger1_midArm1, rotate_midPod1_Arm1, mid_pod1_Arm1);
    cakeRide.addPodUp(translate_Extendfinger2_midArm1, rotate_midPod2_Arm1, mid_pod2_Arm1);
    cakeRide.addPodUp(translate_Extendfinger3_midArm1, rotate_midPod3_Arm1, mid_pod3_Arm1);
    
    cakeRide.addPodUp(translate_Extendfinger1_midArm2, rotate_midPod1_Arm2, mid_pod1_Arm2);
    //cakeRide.addPodUp(translate_Extendfinger2_midArm2, rotate_midPod2_Arm2, mid_pod2_Arm2);
    
    /*****bear camera******/
    cakeRide.addBearPod(translate_Extendfinger2_midArm2, bearCamera, rotate_midPod2_Arm2, mid_pod2_Arm2);
    cakeRide.addPodUp(translate_Extendfinger3_midArm2, rotate_midPod3_Arm2, mid_pod3_Arm2);
    
    cakeRide.addPodUp(translate_Extendfinger1_midArm3, rotate_midPod1_Arm3, mid_pod1_Arm3);
    cakeRide.addPodUp(translate_Extendfinger2_midArm3, rotate_midPod2_Arm3, mid_pod2_Arm3);
    cakeRide.addPodUp(translate_Extendfinger3_midArm3, rotate_midPod3_Arm3, mid_pod3_Arm3);
    
    cakeRide.addSmallBase(translate2_midExtendArm1, mid_smallBase_Arm1);
    cakeRide.addSmallBase(translate2_midExtendArm2, mid_smallBase_Arm2);
    cakeRide.addSmallBase(translate2_midExtendArm3, mid_smallBase_Arm3);
  
////////// Bottom Base, Arms1, Arm2, and Arm3 //////////
    
    ////bottom base
    cakeRide.addBase(bottomRotationMatrix, scale_bottomBase, translate_bottomBase, rotate_bottomBase, bottom_base, glm::vec3(1.0f, 4.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), 0.0f);
    
    //bottom arm1
    cakeRide.addArm(bottomRotationMatrix, scale_bottomArm1, translate_bottomArm1, rotate_bottomArm1, bottom_arm1, glm::vec3(0.5f, 5.0f, 1.0f), glm::vec3(0.0f, 2.5f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), -90.0f/180.0f * glm::pi<float>());
    
    //bottom arm2
    cakeRide.addArmR(bottomRotationMatrix, scale_bottomArm2, translate_bottomArm2, rotate1_bottomArm2, rotate2_bottomArm2,  bottom_arm2, glm::vec3(0.5f, 5.0f, 1.0f), glm::vec3(0.0f, 2.5f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f), -90.0f/180.0f * glm::pi<float>(), 120.0f/180.0f * glm::pi<float>());
    
    //bottom arm3
    cakeRide.addArmR(bottomRotationMatrix, scale_bottomArm3, translate_bottomArm3, rotate1_bottomArm3, rotate2_bottomArm3,   bottom_arm3, glm::vec3(0.5f, 5.0f, 1.0f), glm::vec3(0.0f, 2.5f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f), -90.0f/180.0f * glm::pi<float>(), -120.0f/180.0f * glm::pi<float>());
    
    //bottom arm1Extend
    cakeRide.addExtendArm(bottomRotationMatrix, scale_bottomExtendArm1, translate_bottomExtendArm1, rotate_bottomExtendArm1, translate2_bottomExtendArm1, bottom_arm1Extend, glm::vec3(0.5f, 5.0f, 1.0f), glm::vec3(0.0f, 2.5f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), -90.0f/180.0f * glm::pi<float>());

    
    //bottom arm2Extend
    cakeRide.addExtendArmR(bottomRotationMatrix, scale_bottomExtendArm2, translate_bottomExtendArm2, rotate_bottomExtendArm2, translate2_bottomExtendArm2, rotate2_bottomExtendArm2, bottom_arm2Extend, glm::vec3(0.5f, 5.0f, 1.0f), glm::vec3(0.0f, 2.5f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f),  -90.0f/180.0f * glm::pi<float>(), 120.0f/180.0f * glm::pi<float>());
    
    
    //bottom arm3Extend
    cakeRide.addExtendArmR(bottomRotationMatrix, scale_bottomExtendArm3, translate_bottomExtendArm3, rotate_bottomExtendArm3, translate2_bottomExtendArm3, rotate2_bottomExtendArm3, bottom_arm3Extend, glm::vec3(0.5f, 5.0f, 1.0f), glm::vec3(0.0f, 2.5f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f),  -90.0f/180.0f * glm::pi<float>(), -120.0f/180.0f * glm::pi<float>());
    
    
////////// Bottom fingers for bottom arm1 //////////
    
    //bottom finger1 on arm1
    cakeRide.addFinger(translate2_bottomExtendArm1, scale_bottomFinger1_Arm1, rotate_bottomFinger1_Arm1, translate_bottomFinger1_Arm1, translate2_bottomFinger1_Arm1, rotate2_bottomFinger1_Arm1, translate3_bottomFinger1_Arm1, bottom_finger1_arm1, glm::vec3(0.24f, 2.0f, 0.24f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.2f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(5.0f, 0.0f, 0.0f), -90.0f/180.0f * glm::pi<float>(), 0.0f/180.0f * glm::pi<float>());
    
    //bottom finger1 extending on arm1
    cakeRide.addFinger(rotate2_bottomFinger1_Arm1, scale_bottomExtFinger1_Arm1, rotate_bottomExtFinger1_Arm1, translate_bottomExtFinger1_Arm1, translate2_bottomExtFinger1_Arm1, rotate2_bottomExtFinger1_Arm1, translate3_bottomExtFinger1_Arm1, bottom_ExtFinger1_arm1, glm::vec3(0.24f, 2.0f, 0.24f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.2f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), -90.0f/180.0f * glm::pi<float>(), 0.0f/180.0f * glm::pi<float>());
    
    
    //bottom finger2 on arm1
    cakeRide.addFinger(rotate2_bottomFinger1_Arm1, scale_bottomFinger2_Arm1, rotate_bottomFinger2_Arm1, translate_bottomFinger2_Arm1, translate2_bottomFinger2_Arm1, rotate2_bottomFinger2_Arm1, translate3_bottomFinger2_Arm1, bottom_finger2_arm1, glm::vec3(0.24f, 2.0f, 0.24f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.2f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), -90.0f/180.0f * glm::pi<float>(), 120.0f/180.0f * glm::pi<float>());
    
    
    //bottom finger2 extending on arm1
    cakeRide.addFinger(rotate2_bottomFinger1_Arm1, scale_bottomExtFinger2_Arm1, rotate_bottomExtFinger2_Arm1, translate_bottomExtFinger2_Arm1, translate2_bottomExtFinger2_Arm1, rotate2_bottomExtFinger2_Arm1, translate3_bottomExtFinger2_Arm1, bottom_ExtFinger2_arm1, glm::vec3(0.24f, 2.0f, 0.24f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.2f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), -90.0f/180.0f * glm::pi<float>(), 120.0f/180.0f * glm::pi<float>());
    
    //bottom finger3 on arm1
    cakeRide.addFinger(rotate2_bottomFinger1_Arm1, scale_bottomFinger3_Arm1, rotate_bottomFinger3_Arm1, translate_bottomFinger3_Arm1, translate2_bottomFinger3_Arm1, rotate2_bottomFinger3_Arm1, translate3_bottomFinger3_Arm1, bottom_finger3_arm1, glm::vec3(0.24f, 2.0f, 0.24f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.2f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), -90.0f/180.0f * glm::pi<float>(), -120.0f/180.0f * glm::pi<float>());
    
    //bottom finger3 extending on arm1
    cakeRide.addFinger(rotate2_bottomFinger1_Arm1, scale_bottomExtFinger3_Arm1, rotate_bottomExtFinger3_Arm1, translate_bottomExtFinger3_Arm1, translate2_bottomExtFinger3_Arm1, rotate2_bottomExtFinger3_Arm1, translate3_bottomExtFinger3_Arm1, bottom_ExtFinger3_arm1, glm::vec3(0.24f, 2.0f, 0.24f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.2f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), -90.0f/180.0f * glm::pi<float>(), -120.0f/180.0f * glm::pi<float>());
    
////////// Bottom fingers for bottom arm2 //////////
    
    //bottom finger1 on arm2
    cakeRide.addFinger(translate2_bottomExtendArm2, scale_bottomFinger1_Arm2, rotate_bottomFinger1_Arm2, translate_bottomFinger1_Arm2, translate2_bottomFinger1_Arm2, rotate2_bottomFinger1_Arm2, translate3_bottomFinger1_Arm2, bottom_finger1_arm2, glm::vec3(0.24f, 2.0f, 0.24f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.2f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(5.0f, 0.0f, 0.0f), -90.0f/180.0f * glm::pi<float>(), 0.0f/180.0f * glm::pi<float>());
    
    //bottom finger1 extending on arm2
    cakeRide.addFinger(rotate2_bottomFinger1_Arm2, scale_bottomExtFinger1_Arm2, rotate_bottomExtFinger1_Arm2, translate_bottomExtFinger1_Arm2, translate2_bottomExtFinger1_Arm2, rotate2_bottomExtFinger1_Arm2, translate3_bottomExtFinger1_Arm2, bottom_ExtFinger1_arm2, glm::vec3(0.24f, 2.0f, 0.24f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.2f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), -90.0f/180.0f * glm::pi<float>(), 0.0f/180.0f * glm::pi<float>());
    
    //bottom finger2 on arm2
    cakeRide.addFinger(rotate2_bottomFinger1_Arm2, scale_bottomFinger2_Arm2, rotate_bottomFinger2_Arm2, translate_bottomFinger2_Arm2, translate2_bottomFinger2_Arm2, rotate2_bottomFinger2_Arm2, translate3_bottomFinger2_Arm2, bottom_finger2_arm2, glm::vec3(0.24f, 2.0f, 0.24f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.2f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), -90.0f/180.0f * glm::pi<float>(), 120.0f/180.0f * glm::pi<float>());
 
    //bottom finger2 extending on arm2
    cakeRide.addFinger(rotate2_bottomFinger1_Arm2, scale_bottomExtFinger2_Arm2, rotate_bottomExtFinger2_Arm2, translate_bottomExtFinger2_Arm2, translate2_bottomExtFinger2_Arm2, rotate2_bottomExtFinger2_Arm2, translate3_bottomExtFinger2_Arm2, bottom_ExtFinger2_arm2, glm::vec3(0.24f, 2.0f, 0.24f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.2f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), -90.0f/180.0f * glm::pi<float>(), 120.0f/180.0f * glm::pi<float>());
    
    //bottom finger3 on arm2
    cakeRide.addFinger(rotate2_bottomFinger1_Arm2, scale_bottomFinger3_Arm2, rotate_bottomFinger3_Arm2, translate_bottomFinger3_Arm2, translate2_bottomFinger3_Arm2, rotate2_bottomFinger3_Arm2, translate3_bottomFinger3_Arm2, bottom_finger3_arm2, glm::vec3(0.24f, 2.0f, 0.24f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.2f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), -90.0f/180.0f * glm::pi<float>(), -120.0f/180.0f * glm::pi<float>());

    //bottom finger3 extending on arm2
    cakeRide.addFinger(rotate2_bottomFinger1_Arm2, scale_bottomExtFinger3_Arm2, rotate_bottomExtFinger3_Arm2, translate_bottomExtFinger3_Arm2, translate2_bottomExtFinger3_Arm2, rotate2_bottomExtFinger3_Arm2, translate3_bottomExtFinger3_Arm2, bottom_ExtFinger3_arm2, glm::vec3(0.24f, 2.0f, 0.24f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.2f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), -90.0f/180.0f * glm::pi<float>(), -120.0f/180.0f * glm::pi<float>());

 
////////// Bottom fingers for bottom arm3 //////////
    
    //bottom finger1 on arm3
    cakeRide.addFinger(translate2_bottomExtendArm3, scale_bottomFinger1_Arm3, rotate_bottomFinger1_Arm3, translate_bottomFinger1_Arm3, translate2_bottomFinger1_Arm3, rotate2_bottomFinger1_Arm3, translate3_bottomFinger1_Arm3, bottom_finger1_arm3, glm::vec3(0.24f, 2.0f, 0.24f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.2f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(5.0f, 0.0f, 0.0f), -90.0f/180.0f * glm::pi<float>(), 0.0f/180.0f * glm::pi<float>());
    
    //bottom finger1 extending on arm3
    cakeRide.addFinger(rotate2_bottomFinger1_Arm3, scale_bottomExtFinger1_Arm3, rotate_bottomExtFinger1_Arm3, translate_bottomExtFinger1_Arm3, translate2_bottomExtFinger1_Arm3, rotate2_bottomExtFinger1_Arm3, translate3_bottomExtFinger1_Arm3, bottom_ExtFinger1_arm3, glm::vec3(0.24f, 2.0f, 0.24f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.2f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), -90.0f/180.0f * glm::pi<float>(), 0.0f/180.0f * glm::pi<float>());
    
    //bottom finger2 on arm3
    cakeRide.addFinger(rotate2_bottomFinger1_Arm3, scale_bottomFinger2_Arm3, rotate_bottomFinger2_Arm3, translate_bottomFinger2_Arm3, translate2_bottomFinger2_Arm3, rotate2_bottomFinger2_Arm3, translate3_bottomFinger2_Arm3, bottom_finger2_arm3, glm::vec3(0.24f, 2.0f, 0.24f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.2f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), -90.0f/180.0f * glm::pi<float>(), 120.0f/180.0f * glm::pi<float>());
    
    //bottom finger2 extending on arm3
    cakeRide.addFinger(rotate2_bottomFinger1_Arm3, scale_bottomExtFinger2_Arm3, rotate_bottomExtFinger2_Arm3, translate_bottomExtFinger2_Arm3, translate2_bottomExtFinger2_Arm3, rotate2_bottomExtFinger2_Arm3, translate3_bottomExtFinger2_Arm3, bottom_ExtFinger2_arm3, glm::vec3(0.24f, 2.0f, 0.24f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.2f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), -90.0f/180.0f * glm::pi<float>(), 120.0f/180.0f * glm::pi<float>());
    
    //bottom finger3 on arm3
    cakeRide.addFinger(rotate2_bottomFinger1_Arm3, scale_bottomFinger3_Arm3, rotate_bottomFinger3_Arm3, translate_bottomFinger3_Arm3, translate2_bottomFinger3_Arm3, rotate2_bottomFinger3_Arm3, translate3_bottomFinger3_Arm3, bottom_finger3_arm3, glm::vec3(0.24f, 2.0f, 0.24f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.2f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), -90.0f/180.0f * glm::pi<float>(), -120.0f/180.0f * glm::pi<float>());
    
    //bottom finger3 extending on arm3
    cakeRide.addFinger(rotate2_bottomFinger1_Arm3, scale_bottomExtFinger3_Arm3, rotate_bottomExtFinger3_Arm3, translate_bottomExtFinger3_Arm3, translate2_bottomExtFinger3_Arm3, rotate2_bottomExtFinger3_Arm3, translate3_bottomExtFinger3_Arm3, bottom_ExtFinger3_arm3, glm::vec3(0.24f, 2.0f, 0.24f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.2f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), -90.0f/180.0f * glm::pi<float>(), -120.0f/180.0f * glm::pi<float>());
 
    

////////// bottom pods for arm1 //////////
    
    cakeRide.addPod(translate2_bottomExtFinger1_Arm1, rotate_bottomPod1_Arm1, bottom_pod1_Arm1);
    
    cakeRide.addPod(translate2_bottomExtFinger2_Arm1,rotate_bottomPod2_Arm1, bottom_pod2_Arm1);
    
    cakeRide.addPod(translate2_bottomExtFinger3_Arm1,rotate_bottomPod3_Arm1, bottom_pod3_Arm1);

    
////////// bottom pods for arm2 //////////
    
    cakeRide.addPod(translate2_bottomExtFinger1_Arm2,rotate_bottomPod1_Arm2, bottom_pod1_Arm2);
    
    cakeRide.addPod(translate2_bottomExtFinger2_Arm2,rotate_bottomPod2_Arm2, bottom_pod2_Arm2);
    
    cakeRide.addPod(translate2_bottomExtFinger3_Arm2,rotate_bottomPod3_Arm2, bottom_pod3_Arm2);
    
    
////////// bottom pods for arm3 //////////
    
    cakeRide.addPod(translate2_bottomExtFinger1_Arm3,rotate_bottomPod1_Arm3, bottom_pod1_Arm3);
    
    cakeRide.addPod(translate2_bottomExtFinger2_Arm3,rotate_bottomPod2_Arm3, bottom_pod2_Arm3);
    
    cakeRide.addPod(translate2_bottomExtFinger3_Arm3,rotate_bottomPod3_Arm3, bottom_pod3_Arm3);
    
    
    
    
////////// smallBase for bottom arms //////////
    cakeRide.addSmallBase(translate2_bottomExtendArm1,bottom_smallBase_Arm1);
    
    cakeRide.addSmallBase(translate2_bottomExtendArm2,bottom_smallBase_Arm2);
    
    cakeRide.addSmallBase(translate2_bottomExtendArm3,bottom_smallBase_Arm3);
    
    
    //add bear and camera
    cakeRide.addBear(rotate_midPod2_Arm2, bearPointer);
    
    //add camera
    //cakeRide.addCamera(rotate_midPod2_Arm2, camPosition);
    
    
    
    
    
    // Load the shader program. Similar to the .obj objects, different platforms expect a different directory for files
#ifdef _WIN32 // Windows (both 32 and 64 bit versions)
    shaderProgram = LoadShaders("../shader.vert", "../shader.frag");
#else // Not windows
    shaderProgram = LoadShaders("/Users/ReloadSyndrome/Documents/PA3/PA3/shader.vert", "/Users/ReloadSyndrome/Documents/PA3/PA3/shader.frag");
    skyShaderProgram = LoadShaders("/Users/ReloadSyndrome/Documents/PA3/PA3/skyShader.vert", "/Users/ReloadSyndrome/Documents/PA3/PA3/skyShader.frag");
#endif
}

void Window::clean_up(){
    
    delete(cube);
    glDeleteProgram(shaderProgram);
    glDeleteProgram(skyShaderProgram);
}

GLFWwindow* Window::create_window(int width, int height){
    
    // Initialize GLFW
    if (!glfwInit())
    {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return NULL;
    }
    
    // 4x antialiasing
    glfwWindowHint(GLFW_SAMPLES, 4);
    
    //inserted code from piazza
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    // Create the GLFW window
    GLFWwindow* window = glfwCreateWindow(width, height, window_title, NULL, NULL);
    
    // Check if the window could not be created
    if (!window)
    {
        fprintf(stderr, "Failed to open GLFW window.\n");
        glfwTerminate();
        return NULL;
    }
    
    // Make the context of the window
    glfwMakeContextCurrent(window);
    
    // Set swap interval to 1
    glfwSwapInterval(1);
    
    // Get the width and height of the framebuffer to properly resize the window
    glfwGetFramebufferSize(window, &width, &height);
    // Call the resize callback to make sure things get drawn immediately
    Window::resize_callback(window, width, height);
    
    return window;
}

void Window::resize_callback(GLFWwindow* window, int width, int height){
    
    Window::width = width;
    Window::height = height;
    
    // Set the viewport size
    glViewport(0, 0, width, height);
    
    
    if (height > 0)
    {
        P = glm::perspective(45.0f, (float)width / (float)height, 0.1f, 1000.0f);
        V = glm::lookAt(cam_pos, cam_look_at, cam_up);
    }
}

void Window::idle_callback(){

    
    /*if(firstMouse){
    
        //cerr << "inside camera look" << endl;
        V = glm::lookAt(cam_pos, cam_look_at, cam_up);
    }*/
    
    /*else{
        
        //cerr << "inside else for camera look" << endl;
        //update for mouse look around
        V = glm::lookAt(cam_pos + cameraFront, cam_pos, cam_up + cameraFront);
    }*/

    //bear camera
    glm::mat3 bearRot = glm::mat3(bearPointer -> M);
    glm::vec3 bearTrans = glm::vec3(bearPointer -> M[3][0], bearPointer -> M[3][1], bearPointer -> M[3][2]);
    
    glm::mat4 finalBearRot = glm::transpose(glm::mat4(bearRot));
    
    glm::mat4 finalBearTrans = glm::translate(identity, -bearTrans + glm::vec3(0.0f, -1.2f, 0.0f));
    
    glm::mat4 finalCamera = finalBearRot * finalBearTrans;

    
    VSplit = finalCamera;
    
    if(bearCameraView){
        
        V = finalCamera;
    }
        
    ride -> update(identity, splitscreen);

    
    //// rotations for each part of the ride ////
    
    //top set finger rotation
    rotate_finger1_topArm1 -> M = (glm::rotate(identity, 1.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) *rotate_finger1_topArm1 -> M;
    
    rotate_finger1_topArm2 -> M = (glm::rotate(identity, 1.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) *rotate_finger1_topArm2 -> M;
    
    rotate_finger1_topArm3 -> M = (glm::rotate(identity, 1.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) *rotate_finger1_topArm3 -> M;
    
    //middle set finger rotation
    rotate_finger1_midArm1 -> M = (glm::rotate(identity, 1.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * rotate_finger1_midArm1 -> M;
    
    rotate_finger1_midArm2 -> M = (glm::rotate(identity, 1.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * rotate_finger1_midArm2 -> M;
    
    rotate_finger1_midArm3 -> M = (glm::rotate(identity, 1.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * rotate_finger1_midArm3 -> M;
    
    
    
    //bottom set finger rotation
    rotate2_bottomFinger1_Arm1 -> M = (glm::rotate(identity, 1.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * rotate2_bottomFinger1_Arm1 -> M;
    
    rotate2_bottomFinger1_Arm2 -> M = (glm::rotate(identity, 1.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * rotate2_bottomFinger1_Arm2 -> M;
    
    rotate2_bottomFinger1_Arm3 -> M = (glm::rotate(identity, 1.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * rotate2_bottomFinger1_Arm3 -> M;
    
    //rotation of the pods
    
    //top pods
    rotate_topPod1_Arm1 -> M = (glm::rotate(identity, 6.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * rotate_topPod1_Arm1 -> M;
    rotate_topPod2_Arm1 -> M = (glm::rotate(identity, 6.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * rotate_topPod2_Arm1 -> M;
    rotate_topPod3_Arm1 -> M = (glm::rotate(identity, 6.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * rotate_topPod3_Arm1 -> M;
    
    rotate_topPod1_Arm2 -> M = (glm::rotate(identity, 6.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * rotate_topPod1_Arm2 -> M;
    rotate_topPod2_Arm2 -> M = (glm::rotate(identity, 6.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * rotate_topPod2_Arm2 -> M;
    rotate_topPod3_Arm2 -> M = (glm::rotate(identity, 6.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * rotate_topPod3_Arm2 -> M;
    
    rotate_topPod1_Arm3 -> M = (glm::rotate(identity, 6.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * rotate_topPod1_Arm3 -> M;
    rotate_topPod2_Arm3 -> M = (glm::rotate(identity, 6.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * rotate_topPod2_Arm3 -> M;
    rotate_topPod3_Arm3 -> M = (glm::rotate(identity, 6.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * rotate_topPod3_Arm3 -> M;
    
    
    
    //middle pods
    rotate_midPod1_Arm1 -> M = (glm::rotate(identity, 2.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * rotate_midPod1_Arm1 -> M;
    rotate_midPod2_Arm1 -> M = (glm::rotate(identity, 2.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * rotate_midPod2_Arm1 -> M;
    rotate_midPod3_Arm1 -> M = (glm::rotate(identity, 2.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * rotate_midPod3_Arm1 -> M;
    
    rotate_midPod1_Arm2 -> M = (glm::rotate(identity, 2.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * rotate_midPod1_Arm2 -> M;
    rotate_midPod2_Arm2 -> M = (glm::rotate(identity, 2.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * rotate_midPod2_Arm2 -> M;
    rotate_midPod3_Arm2 -> M = (glm::rotate(identity, 2.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * rotate_midPod3_Arm2 -> M;
    
    rotate_midPod1_Arm3 -> M = (glm::rotate(identity, 2.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * rotate_midPod1_Arm3 -> M;
    rotate_midPod2_Arm3 -> M = (glm::rotate(identity, 2.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * rotate_midPod2_Arm3 -> M;
    rotate_midPod3_Arm3 -> M = (glm::rotate(identity, 2.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * rotate_midPod3_Arm3 -> M;
    
    
    
    //bottom pods
    rotate_bottomPod1_Arm1 -> M = (glm::rotate(identity, 4.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * rotate_bottomPod1_Arm1 -> M;
    
    rotate_bottomPod2_Arm1 -> M = (glm::rotate(identity, 4.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * rotate_bottomPod2_Arm1 -> M;
    
    rotate_bottomPod3_Arm1 -> M = (glm::rotate(identity, 4.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * rotate_bottomPod3_Arm1 -> M;
    
    rotate_bottomPod1_Arm2 -> M = (glm::rotate(identity, 4.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * rotate_bottomPod1_Arm2 -> M;
    
    rotate_bottomPod2_Arm2 -> M = (glm::rotate(identity, 4.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * rotate_bottomPod2_Arm2 -> M;
    
    rotate_bottomPod3_Arm2 -> M = (glm::rotate(identity, 4.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * rotate_bottomPod3_Arm2 -> M;
    
    rotate_bottomPod1_Arm3 -> M = (glm::rotate(identity, 4.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * rotate_bottomPod1_Arm3 -> M;
    
    rotate_bottomPod2_Arm3 -> M = (glm::rotate(identity, 4.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * rotate_bottomPod2_Arm3 -> M;
    
    rotate_bottomPod3_Arm3 -> M = (glm::rotate(identity, 4.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * rotate_bottomPod3_Arm3 -> M;
    
    
    
    
    ////main pillar rotation////
    
    double time = glfwGetTime();
    double centerTime = time + 1;
    
    
    
    //top
    if(floor(fmod(centerTime, 2)) == 0){
        
        
        if(topRotationMatrix -> M[3][1] < 4.0f){
            
            topRotationMatrix -> M = glm::translate(identity, glm::vec3(0.0f, 0.05f, 0.0f)) * (glm::rotate(identity, 6.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * topRotationMatrix -> M;
        }
    }
    
    else{
        
        if(topRotationMatrix -> M[3][1] > 0.0f){
            
            topRotationMatrix -> M = glm::translate(identity, glm::vec3(0.0f, -0.05f, 0.0f)) * (glm::rotate(identity, 6.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * topRotationMatrix -> M;
        }
    }
    
    
    //middle
    if(floor(fmod(time, 2)) == 0){
        
        
        if(middleRotationMatrix -> M[3][1] < 2.0f){
            
            middleRotationMatrix -> M = glm::translate(identity, glm::vec3(0.0f, 0.05f, 0.0f)) * (glm::rotate(identity, -2.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * middleRotationMatrix -> M;
        }
    }
    
    else{
        
        if(middleRotationMatrix -> M[3][1] > -3.0f){
    
        
            middleRotationMatrix -> M = glm::translate(identity, glm::vec3(0.0f, -0.05f, 0.0f)) * (glm::rotate(identity, -2.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * middleRotationMatrix -> M;
        }
    }

    //bottom
    bottomRotationMatrix -> M = (glm::rotate(identity, 4.0f/180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f))) * bottomRotationMatrix -> M;
    
    
    
    
    //double time = glfwGetTime();
    double time2 = time + 1;
    double time3 = time + 2;
    
    if(floor(fmod(time, 3)) == 0){
        
        //top arm extensions
        if(translate_topExtendArm1 -> M[3][0] <= 9){
        
            translate_topExtendArm1 -> M = glm::translate(identity, glm::vec3(0.06f, 0.0f, 0.0f)) * translate_topExtendArm1 -> M;
            
            translate_Extendfinger1_topArm1 -> M = glm::translate(identity, glm::vec3(0.02f, 0.0f, 0.0f)) *translate_Extendfinger1_topArm1 -> M;
            
            translate_Extendfinger1_topArm2 -> M = glm::translate(identity, glm::vec3(0.02f, 0.0f, 0.0f)) *translate_Extendfinger1_topArm2 -> M;
            
            translate_Extendfinger1_topArm3 -> M = glm::translate(identity, glm::vec3(0.02f, 0.0f, 0.0f)) *translate_Extendfinger1_topArm3 -> M;
        
        }
        
        //middle arm extensions
        if(translate2_midExtendArm1 -> M[3][0] <= 9){
        
            translate2_midExtendArm1 -> M = glm::translate(identity, glm::vec3(0.06f, 0.0f, 0.0f)) * translate2_midExtendArm1 -> M;
            
            translate_Extendfinger1_midArm1 -> M = glm::translate(identity, glm::vec3(0.02f, 0.0f, 0.0f)) * translate_Extendfinger1_midArm1 -> M;
            
            translate_Extendfinger1_midArm2 -> M = glm::translate(identity, glm::vec3(0.02f, 0.0f, 0.0f)) * translate_Extendfinger1_midArm2 -> M;
            
            translate_Extendfinger1_midArm3 -> M = glm::translate(identity, glm::vec3(0.02f, 0.0f, 0.0f)) *translate_Extendfinger1_midArm3 -> M;
        }
        
        
        
        
        //bottom arm extensions
        if(translate2_bottomExtendArm1 -> M[3][0] <= 9){
        
            translate2_bottomExtendArm1 -> M = glm::translate(identity, glm::vec3(0.04f, 0.0f, 0.0f)) * translate2_bottomExtendArm1 -> M;
            
            translate2_bottomExtFinger1_Arm1 -> M = glm::translate(identity, glm::vec3(0.02f, 0.0f, 0.0f)) * translate2_bottomExtFinger1_Arm1 -> M;
            
            translate2_bottomExtFinger1_Arm2 -> M = glm::translate(identity, glm::vec3(0.02f, 0.0f, 0.0f)) * translate2_bottomExtFinger1_Arm2 -> M;
            
            translate2_bottomExtFinger1_Arm3 -> M = glm::translate(identity, glm::vec3(0.02f, 0.0f, 0.0f)) * translate2_bottomExtFinger1_Arm3 -> M;
        }
    }
    
    else{
        
        //top arm extensions
        if(translate_topExtendArm1 -> M[3][0] > 0){
            
            translate_topExtendArm1 -> M = glm::translate(identity, glm::vec3(-0.06f, 0.0f, 0.0f)) * translate_topExtendArm1 -> M;
            
            translate_Extendfinger1_topArm1 -> M = glm::translate(identity, glm::vec3(-0.02f, 0.0f, 0.0f)) *translate_Extendfinger1_topArm1 -> M;
            
            translate_Extendfinger1_topArm2 -> M = glm::translate(identity, glm::vec3(-0.02f, 0.0f, 0.0f)) *translate_Extendfinger1_topArm2 -> M;
            
            translate_Extendfinger1_topArm3 -> M = glm::translate(identity, glm::vec3(-0.02f, 0.0f, 0.0f)) *translate_Extendfinger1_topArm3 -> M;
        }
        
        //middle arm extensions
        if(translate2_midExtendArm1 -> M[3][0] > 0){
            
            translate2_midExtendArm1 -> M = glm::translate(identity, glm::vec3(-0.06f, 0.0f, 0.0f)) * translate2_midExtendArm1 -> M;
            
            translate_Extendfinger1_midArm1 -> M = glm::translate(identity, glm::vec3(-0.02f, 0.0f, 0.0f)) * translate_Extendfinger1_midArm1 -> M;
            
            translate_Extendfinger1_midArm2 -> M = glm::translate(identity, glm::vec3(-0.02f, 0.0f, 0.0f)) * translate_Extendfinger1_midArm2 -> M;
            
            translate_Extendfinger1_midArm3 -> M = glm::translate(identity, glm::vec3(-0.02f, 0.0f, 0.0f)) *translate_Extendfinger1_midArm3 -> M;
        }
        
        
        //bottom arm extensions
        if(translate2_bottomExtendArm1 -> M[3][0] > 0){
        
            translate2_bottomExtendArm1 -> M = glm::translate(identity, glm::vec3(-0.04f, 0.0f, 0.0f)) * translate2_bottomExtendArm1 -> M;
            
            translate2_bottomExtFinger1_Arm1 -> M = glm::translate(identity, glm::vec3(-0.02f, 0.0f, 0.0f)) * translate2_bottomExtFinger1_Arm1 -> M;
            
            translate2_bottomExtFinger1_Arm2 -> M = glm::translate(identity, glm::vec3(-0.02f, 0.0f, 0.0f)) * translate2_bottomExtFinger1_Arm2 -> M;
            
            translate2_bottomExtFinger1_Arm3 -> M = glm::translate(identity, glm::vec3(-0.02f, 0.0f, 0.0f)) * translate2_bottomExtFinger1_Arm3 -> M;
        }
    }
    
    if(floor(fmod(time2, 3)) == 0){
        
        
        //top arm extensions
        if(translate_topExtendArm2 -> M[3][0] <= 9){
            
            translate_topExtendArm2 -> M = glm::translate(identity, glm::vec3(0.06f, 0.0f, 0.0f)) * translate_topExtendArm2 -> M;
            
            translate_Extendfinger2_topArm1 -> M = glm::translate(identity, glm::vec3(0.02f, 0.0f, 0.0f)) *translate_Extendfinger2_topArm1 -> M;
            
            translate_Extendfinger2_topArm2 -> M = glm::translate(identity, glm::vec3(0.02f, 0.0f, 0.0f)) *translate_Extendfinger2_topArm2 -> M;
            
            translate_Extendfinger2_topArm3 -> M = glm::translate(identity, glm::vec3(0.02f, 0.0f, 0.0f)) *translate_Extendfinger2_topArm3 -> M;
            
        }
        
        //middle extensions
        if(translate2_midExtendArm2 -> M[3][0] <= 9){
        
            translate2_midExtendArm2 -> M = glm::translate(identity, glm::vec3(0.04f, 0.0f, 0.0f)) * translate2_midExtendArm2 -> M;
            
            translate_Extendfinger2_midArm1 -> M = glm::translate(identity, glm::vec3(0.02f, 0.0f, 0.0f)) * translate_Extendfinger2_midArm1 -> M;
            
            translate_Extendfinger2_midArm2 -> M = glm::translate(identity, glm::vec3(0.02f, 0.0f, 0.0f)) * translate_Extendfinger2_midArm2 -> M;
            
            bearCamera = translate_Extendfinger2_midArm2;
            
            translate_Extendfinger2_midArm3 -> M = glm::translate(identity, glm::vec3(0.02f, 0.0f, 0.0f)) *translate_Extendfinger2_midArm3 -> M;
        }
        
        //bottom extensions
        if(translate2_bottomExtendArm2 -> M[3][0] <= 9){
        
            translate2_bottomExtendArm2 -> M = glm::translate(identity, glm::vec3(0.06f, 0.0f, 0.0f)) * translate2_bottomExtendArm2 -> M;
            
            translate2_bottomExtFinger2_Arm1 -> M = glm::translate(identity, glm::vec3(0.02f, 0.0f, 0.0f)) * translate2_bottomExtFinger2_Arm1 -> M;
            
            translate2_bottomExtFinger2_Arm2 -> M = glm::translate(identity, glm::vec3(0.02f, 0.0f, 0.0f)) * translate2_bottomExtFinger2_Arm2 -> M;
            
            translate2_bottomExtFinger2_Arm3 -> M = glm::translate(identity, glm::vec3(0.02f, 0.0f, 0.0f)) * translate2_bottomExtFinger2_Arm3 -> M;
        }
    }
    
    else{
        
        //top arm extensions
        if(translate_topExtendArm2 -> M[3][0] > 0){
            
            translate_topExtendArm2 -> M = glm::translate(identity, glm::vec3(-0.06f, 0.0f, 0.0f)) * translate_topExtendArm2 -> M;
            
            translate_Extendfinger2_topArm1 -> M = glm::translate(identity, glm::vec3(-0.02f, 0.0f, 0.0f)) *translate_Extendfinger2_topArm1 -> M;
            
            translate_Extendfinger2_topArm2 -> M = glm::translate(identity, glm::vec3(-0.02f, 0.0f, 0.0f)) *translate_Extendfinger2_topArm2 -> M;
            
            translate_Extendfinger2_topArm3 -> M = glm::translate(identity, glm::vec3(-0.02f, 0.0f, 0.0f)) *translate_Extendfinger2_topArm3 -> M;
            
        }
        
        //middle extensions
        if(translate2_midExtendArm2 -> M[3][0] > 0){
            
            translate2_midExtendArm2 -> M = glm::translate(identity, glm::vec3(-0.04f, 0.0f, 0.0f)) * translate2_midExtendArm2 -> M;
            
            translate_Extendfinger2_midArm1 -> M = glm::translate(identity, glm::vec3(-0.02f, 0.0f, 0.0f)) * translate_Extendfinger2_midArm1 -> M;
            
            translate_Extendfinger2_midArm2 -> M = glm::translate(identity, glm::vec3(-0.02f, 0.0f, 0.0f)) * translate_Extendfinger2_midArm2 -> M;
            
            translate_Extendfinger2_midArm3 -> M = glm::translate(identity, glm::vec3(-0.02f, 0.0f, 0.0f)) *translate_Extendfinger2_midArm3 -> M;
        }
        
        
        //bottom extensions
        if(translate2_bottomExtendArm2 -> M[3][0] > 0){
            
            translate2_bottomExtendArm2 -> M = glm::translate(identity, glm::vec3(-0.06f, 0.0f, 0.0f)) * translate2_bottomExtendArm2 -> M;
            
            translate2_bottomExtFinger2_Arm1 -> M = glm::translate(identity, glm::vec3(-0.02f, 0.0f, 0.0f)) * translate2_bottomExtFinger2_Arm1 -> M;
            
            translate2_bottomExtFinger2_Arm2 -> M = glm::translate(identity, glm::vec3(-0.02f, 0.0f, 0.0f)) * translate2_bottomExtFinger2_Arm2 -> M;
            
            translate2_bottomExtFinger2_Arm3 -> M = glm::translate(identity, glm::vec3(-0.02f, 0.0f, 0.0f)) * translate2_bottomExtFinger2_Arm3 -> M;
        }
    }
    
    if(floor(fmod(time3, 3)) == 0){
        
        //top arm extensions
        if(translate_topExtendArm3 -> M[3][0] <= 9){
            
            translate_topExtendArm3 -> M = glm::translate(identity, glm::vec3(0.06f, 0.0f, 0.0f)) * translate_topExtendArm3 -> M;
            
            translate_Extendfinger3_topArm1 -> M = glm::translate(identity, glm::vec3(0.02f, 0.0f, 0.0f)) *translate_Extendfinger3_topArm1 -> M;
            
            translate_Extendfinger3_topArm2 -> M = glm::translate(identity, glm::vec3(0.02f, 0.0f, 0.0f)) *translate_Extendfinger3_topArm2 -> M;
            
            translate_Extendfinger3_topArm3 -> M = glm::translate(identity, glm::vec3(0.02f, 0.0f, 0.0f)) *translate_Extendfinger3_topArm3 -> M;
        }
        
        //middle extensions
        if(translate2_midExtendArm3 -> M[3][0] <= 9){
            
            translate2_midExtendArm3 -> M = glm::translate(identity, glm::vec3(0.04f, 0.0f, 0.0f)) * translate2_midExtendArm3 -> M;
            
            translate_Extendfinger3_midArm1 -> M = glm::translate(identity, glm::vec3(0.02f, 0.0f, 0.0f)) * translate_Extendfinger3_midArm1 -> M;
            
            translate_Extendfinger3_midArm2 -> M = glm::translate(identity, glm::vec3(0.02f, 0.0f, 0.0f)) * translate_Extendfinger3_midArm2 -> M;
            
            translate_Extendfinger3_midArm3 -> M = glm::translate(identity, glm::vec3(0.02f, 0.0f, 0.0f)) *translate_Extendfinger3_midArm3 -> M;
        }
        
        //bottom extensions
        if(translate2_bottomExtendArm3 -> M[3][0] <= 9){
        
            translate2_bottomExtendArm3 -> M = glm::translate(identity, glm::vec3(0.06f, 0.0f, 0.0f)) * translate2_bottomExtendArm3 -> M;
            
            translate2_bottomExtFinger3_Arm1 -> M = glm::translate(identity, glm::vec3(0.02f, 0.0f, 0.0f)) * translate2_bottomExtFinger3_Arm1 -> M;
            
            translate2_bottomExtFinger3_Arm2 -> M = glm::translate(identity, glm::vec3(0.02f, 0.0f, 0.0f)) * translate2_bottomExtFinger3_Arm2 -> M;
            
            translate2_bottomExtFinger3_Arm3 -> M = glm::translate(identity, glm::vec3(0.02f, 0.0f, 0.0f)) * translate2_bottomExtFinger3_Arm3 -> M;
        }
    }
    
    else{
        
        //top armm extensions
        if(translate_topExtendArm3 -> M[3][0] > 0){
            
            translate_topExtendArm3 -> M = glm::translate(identity, glm::vec3(-0.06f, 0.0f, 0.0f)) * translate_topExtendArm3 -> M;
            
            translate_Extendfinger3_topArm1 -> M = glm::translate(identity, glm::vec3(-0.02f, 0.0f, 0.0f)) *translate_Extendfinger3_topArm1 -> M;
            
            translate_Extendfinger3_topArm2 -> M = glm::translate(identity, glm::vec3(-0.02f, 0.0f, 0.0f)) *translate_Extendfinger3_topArm2 -> M;
            
            translate_Extendfinger3_topArm3 -> M = glm::translate(identity, glm::vec3(-0.02f, 0.0f, 0.0f)) *translate_Extendfinger3_topArm3 -> M;
            
        }
        
        //middle extensions
        if(translate2_midExtendArm3 -> M[3][0] > 0){
            
            translate2_midExtendArm3 -> M = glm::translate(identity, glm::vec3(-0.04f, 0.0f, 0.0f)) * translate2_midExtendArm3 -> M;
            
            translate_Extendfinger3_midArm1 -> M = glm::translate(identity, glm::vec3(-0.02f, 0.0f, 0.0f)) * translate_Extendfinger3_midArm1 -> M;
            
            translate_Extendfinger3_midArm2 -> M = glm::translate(identity, glm::vec3(-0.02f, 0.0f, 0.0f)) * translate_Extendfinger3_midArm2 -> M;
            
            translate_Extendfinger3_midArm3 -> M = glm::translate(identity, glm::vec3(-0.02f, 0.0f, 0.0f)) *translate_Extendfinger3_midArm3 -> M;
        }
        
        //bottom extensions
        if(translate2_bottomExtendArm3 -> M[3][0] > 0){
            
            translate2_bottomExtendArm3 -> M = glm::translate(identity, glm::vec3(-0.06f, 0.0f, 0.0f)) * translate2_bottomExtendArm3 -> M;
            
            translate2_bottomExtFinger3_Arm1 -> M = glm::translate(identity, glm::vec3(-0.02f, 0.0f, 0.0f)) * translate2_bottomExtFinger3_Arm1 -> M;
            
            translate2_bottomExtFinger3_Arm2 -> M = glm::translate(identity, glm::vec3(-0.02f, 0.0f, 0.0f)) * translate2_bottomExtFinger3_Arm2 -> M;
            
            translate2_bottomExtFinger3_Arm3 -> M = glm::translate(identity, glm::vec3(-0.02f, 0.0f, 0.0f)) * translate2_bottomExtFinger3_Arm3 -> M;
        }
    }
}

void Window::display_callback(GLFWwindow* window)
{
    
    //if(splitscreen){
    
        // Clear the color and depth buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        // Use the shader of programID
        glUseProgram(shaderProgram);
        
        /*glViewport(Window::width/2, 0, Window::width/2, Window::height);
        
        V = VSplit;
        
        //Render Ride
        ride -> draw(shaderProgram, splitscreen);
        
        // Clear the color and depth buffers
        //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        // Use the shader of programID
        //glUseProgram(shaderProgram);
        
        glViewport(0, 0, Window::width/2, Window::height);
        
        V = glm::lookAt(cam_pos, cam_look_at, cam_up);
        
        //Render Ride
        ride -> draw(shaderProgram, splitscreen);
    //}
    
    //else{
        
        // Clear the color and depth buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        // Use the shader of programID
        glUseProgram(shaderProgram);*/
        
        //Render Ride
        ride -> draw(shaderProgram, splitscreen);
    
    //}
    
    
    if(splitscreen){
    
        glViewport(Window::width/2, 0, Window::width/2, Window::height);
        
        //calls to use skyBox shaders
        glUseProgram(skyShaderProgram);
        
        skyBox -> skyBoxDraw(skyShaderProgram);
        
        glViewport(Window::width/2, 0, Window::width/2, Window::height);
        
        V = VSplit;
        
        //Render Ride
        //ride -> draw(shaderProgram, splitscreen);
        ride -> update(identity, splitscreen);
        
        
        //// left side of the screen
        glViewport(0, 0, Window::width/2, Window::height);
        
        glUseProgram(skyShaderProgram);
        
        skyBox -> skyBoxDraw(skyShaderProgram);
        
        glViewport(0, 0, Window::width/2, Window::height);
        
        V = glm::lookAt(cam_pos, cam_look_at, cam_up);
        
        //Render Ride
        ride -> update(identity, splitscreen);
    }
    
    else{
    
        glUseProgram(skyShaderProgram);
        
        skyBox -> skyBoxDraw(skyShaderProgram);
    }

    // Gets events, including input such as keyboard and mouse or window resizing
    glfwPollEvents();
    // Swap buffers
    glfwSwapBuffers(window);
}

void Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
    
    //glm::mat4 cameraMatrix = glm::lookAt(cam_pos, cam_look_at, cam_up);
    
    // Check for a key press
    if (action == GLFW_PRESS){
        
        // Check if escape was pressed
        if (key == GLFW_KEY_ESCAPE){
            
            // Close the window. This causes the program to also terminate.
            glfwSetWindowShouldClose(window, GL_TRUE);
        }
        
        if(key == GLFW_KEY_R){
        
            V = glm::lookAt(cam_pos, cam_look_at, cam_up);
        }
        
        if(key == GLFW_KEY_C){
        
            if(bearCameraView == false){
            
                bearCameraView = true;
            }
            
            else{
            
                bearCameraView = false;
 
                V = glm::lookAt(cam_pos, cam_look_at, cam_up);
            }
        }
        
        if(key == GLFW_KEY_S){
        
            
            if(splitscreen == false){
            
                splitscreen = true;
            }
            
            else{
                
                splitscreen = false;
            }
        }
    }
}


void Window::cursor_position_callback(GLFWwindow* window, double xpos, double ypos){
    
    
    if(mouseLeftClick){
     
        glfwGetCursorPos(window, &currentX, &currentY);
     
        glm::vec3 currentPosition = mousePosTracking(currentX * 2.0f, currentY* 2.0f);
        
        glm::vec3 dirVec = currentPosition - lastPosition;
        
        float velocity = glm::length(dirVec);
        
        if(velocity > 0.0001){
            
            rotationVector = glm::cross(lastPosition, currentPosition);
            
            normalVector = glm::normalize(rotationVector);
            
            rotationA = velocity * 20.0f;
        }
        
        if(rotationA > 360.0f || rotationA < -360.0f){
        
            rotationA = 0.0f;
        }
        
        V = V * glm::rotate(glm::mat4(1.0f), rotationA/180.0f * glm::pi<float>(), normalVector);
        
        lastPosition = currentPosition;
        
        firstMouse = false;
    }
    
    
    
    /*// code from opengl tutorials http://learnopengl.com/#!Getting-started/Camera
    glm::vec3 front;
    
    if (firstMouse){
        
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }
    
    
    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // Reversed since y-coordinates go from bottom to left
    lastX = xpos;
    lastY = ypos;
    
    float sensitivity = 0.05f;	// Change this value to your liking
    xoffset *= sensitivity;
    yoffset *= sensitivity;
    
    yaw   += xoffset;
    pitch += yoffset;
    
    // Make sure that when pitch is out of bounds, screen doesn't get flipped
    if (pitch > 89.0f){
        
        pitch = 89.0f;
    }
    
    if (pitch < -89.0f){
        
        pitch = -89.0f;
    }

    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    cameraFront = glm::normalize(front);*/
}

void Window::mouse_button_callback(GLFWwindow* window, int button, int action, int mods){

    
    if(button == GLFW_MOUSE_BUTTON_LEFT){
    
        mouseLeftClick = true;
        
        glfwGetCursorPos(window, &lastX, &lastY);
        
        lastPosition = mousePosTracking(lastX * 2.0f, lastY * 2.0f);
        
        //glMatrixMode(GL_MODELVIEW);
    }
    
    if(action == GLFW_RELEASE && button == GLFW_MOUSE_BUTTON_LEFT){
    
        mouseLeftClick = false;
    }
    
}

/*void Window::cursor_enter_callback(GLFWwindow* window, int entered){
    
    if(entered){
        
        mouseIn = true;
    }
    
    else{
    
        mouseIn = false;
    }
}*/

glm::vec3 Window::mousePosTracking(double x, double y){
    
    glm::vec3 v;
    float d;
    v.x = (2.0f*x - Window::width) / Window::width;
    v.y = (Window::height - 2.0f*y) / Window::height;
    v.z = 0.0;
    d = glm::length(v);
    d = (d<1.0f) ? d : 1.0f;
    v.z = sqrtf(1.001 - d*d);
    glm::normalize(v); // Still need to normalize, since we only capped d, not v.
    return v;
}

void Window::scroll_callback(GLFWwindow* window, double xoffset, double yoffset){

    if(yoffset > 0){
        
        V[3][0] *= 0.90f;
        V[3][1] *= 0.90f;
        V[3][2] *= 0.90f;
    }
    
    else{
    
        V[3][0] *= 1.10f;
        V[3][1] *= 1.10f;
        V[3][2] *= 1.10f;
    }
}