
#include "Texture.hpp"


unsigned int Texture::indFaceGroup = 0;

using namespace std;


//constructor
Texture::Texture(){}


//functions
unsigned char * Texture::loadPPM(const char * filename, int &width, int &height){

    const int bufferSize = 128;
    FILE * filePtr;
    unsigned int read;
    unsigned char * rawData;
    char buf [3][bufferSize];
    char * retval_fgets;
    size_t retval_sscanf;
    
    filePtr = fopen(filename, "rb");
    
    if(filePtr == NULL){
        
        cerr << "error reading  texture file, could not be located." << filename << endl;
        
        width = 0;
        height = 0;
        
        return NULL;
    }
    
    
    // read the magic number
    retval_fgets = fgets(buf[0], bufferSize, filePtr);
    
    // read the width and height
    do{
        retval_fgets = fgets(buf[0], bufferSize, filePtr);
    }while(buf[0][0] == '#');
    retval_sscanf=sscanf(buf[0], "%s %s", buf[1], buf[2]);
    width  = atoi(buf[1]);
    height = atoi(buf[2]);
    
    // read the maxval
    do{
        
        retval_fgets=fgets(buf[0], bufferSize, filePtr);
    }while (buf[0][0] == '#');
    
    rawData = new unsigned char[width * height * 3];
    read = fread(rawData, width * height * 3, 1, filePtr);
    
    fclose(filePtr);
    
    if(read != 1){
        
        cerr << "error parsing ppm file, incomplete data" << endl;
        delete[] rawData;
        
        width = 0;
        height = 0;
        
        return NULL;
    }
    
    return rawData;
}

void Texture::loadTexture(const char * filename, unsigned int i){
    
    //textureID[1];     // storage for one texture
    int twidth;
    int theight;   // texture width/height [pixels]
    unsigned char* tdata;  // texture pixel data
    
    // Load image file
    tdata = loadPPM(filename, twidth, theight);
    if (tdata==NULL) return;
    
    // Generate the texture
    glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, twidth, theight, 0, GL_RGB, GL_UNSIGNED_BYTE, tdata);
}

void Texture::setParameters(){

    //single sided triangle culling
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    
    // making sure no bytes are padded
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    
    // select GL_MODULATE to mix texture with polygon color for shading
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    
    // Set bi-linear filtering for both minification and magnification
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    
}

void Texture::pushFaces(vector<const char*> &faces, const char * filename){  
    
    indFaceGroup = ++indFaceGroup;
    
    faces.push_back(filename);
}