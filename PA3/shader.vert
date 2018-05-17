#version 330 core

// This is an example vertex shader. GLSL is very similar to C.
// You can define extra functions if needed, and the main() function is
// called when the vertex shader gets run.
// The vertex shader gets called once per vertex.

layout (location = 0) in vec3 vertices;
layout (location = 1) in vec3 normals;

out vec3 fragNormals;
out vec3 fragPos;

uniform mat4 MVP;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

//out vec3 fragNormals;

void main()
{
    fragNormals = normals;
    gl_Position = MVP * vec4(vertices.x, vertices.y, vertices.z, 1.0);
    fragPos = vec3(model * vec4(vertices, 1.0f));
    fragNormals = mat3(transpose(inverse(model))) * normals;
}
