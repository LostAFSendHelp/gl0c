#pragma once
#include <GLFW/glfw3.h>

class GL0cComponent {
public:
    GL0cComponent(GLFWwindow* const);
    ~GL0cComponent();

private:
    GLFWwindow* mWindow;
};