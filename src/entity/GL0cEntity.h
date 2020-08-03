#pragma once
#include <vector>
#include <GLFW/glfw3.h>

class GL0cEntity {
public:
    GL0cEntity(GLFWwindow* const);
    ~GL0cEntity();

    virtual void update() = 0;
private:
    GLFWwindow* mWindow;
};