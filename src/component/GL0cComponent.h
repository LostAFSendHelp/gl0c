#pragma once
#include <GLFW/glfw3.h>

class GL0cComponent {
public:
    virtual ~GL0cComponent();

    virtual void update(GLFWwindow*) = 0;

protected:
    GL0cComponent();
};