#version 330 core

layout (location = 0) in vec3 inLocation;
layout (location = 1) in vec3 inColor;

uniform mat4 uModel;
uniform mat4 uView;
uniform mat4 uProjection;

out vec3 vColor;

void main() {
    gl_Position = uProjection * uView * uModel * vec4(inLocation, 1.0f);
    vColor = inColor;
}