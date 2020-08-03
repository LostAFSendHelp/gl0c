#pragma once
#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <memory>
#include "../entity/GL0cCamera.h"
#include "../renderer/program/GL0cRenderer.h"

// TODO: implement this
class GL0cContext {
public:
    GL0cContext(const GL0cRenderer&, GLFWwindow*);
    ~GL0cContext();

    void terminate() const;

    mutable GLFWwindow* mWindow;
    GL0cRenderer mRenderer;
    GL0cCamera mCamera;
    std::vector<std::shared_ptr<GL0cEntity>> mEntities { };

    static std::shared_ptr<GL0cContext> sample(GLFWwindow*);
};