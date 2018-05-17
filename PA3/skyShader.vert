#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normals;

out vec3 fragTexCoords;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;



void main(){

    gl_Position = projection * view * vec4(position, 1.0f);
    
    fragTexCoords = position;
}