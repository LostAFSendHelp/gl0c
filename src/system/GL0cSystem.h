#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "../entity/GL0cEntity.h"
#include "../renderer/program/GL0cRenderer.h"
#include "GL0cContext.h"

class GL0cSystem {
public:
    GL0cSystem(const std::shared_ptr<GL0cContext>&);
    ~GL0cSystem();

    void init();
    void loop();
    void terminate();
    GLFWwindow* window() const;
    const GL0cRenderer& renderer() const;
    GL0cCamera& camera();
    const std::vector<std::shared_ptr<GL0cEntity>>& entities() const;

    std::shared_ptr<GL0cContext> mContext;
};