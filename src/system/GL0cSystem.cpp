#include "GL0cSystem.h"

GL0cSystem::GL0cSystem() {
    glfwInit();
    glfwWindowHint(GLFW_VERSION_MINOR, 3);
    mWindow = glfwCreateWindow(800, 600, "0c", NULL, NULL);
    glfwMakeContextCurrent(mWindow);
}

GL0cSystem::~GL0cSystem() {
    glfwTerminate();
}

void GL0cSystem::loop() {
    while (!glfwWindowShouldClose(mWindow)) {
        glfwSwapBuffers(mWindow);
        glfwPollEvents();

        for (auto& entity : mEntities) {
            entity.update();
        }

        if (glfwGetKey(mWindow, GLFW_KEY_ESCAPE) || glfwGetKey(mWindow, GLFW_KEY_Q)) {
            glfwSetWindowShouldClose(mWindow, GL_TRUE);
        }
    }
}