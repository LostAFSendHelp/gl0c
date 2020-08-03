#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "../entity/GL0cEntity.h"

class GL0cSystem {
public:
    GL0cSystem();
    ~GL0cSystem();

    void loop();
private:
    GLFWwindow* mWindow;
    std::vector<GL0cEntity> mEntities;
};