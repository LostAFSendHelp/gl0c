#version 330 core

in vec3 vColor;
out vec4 fColor;

void main() {
    fColor = vec4(abs(vColor), 1.0f);
}