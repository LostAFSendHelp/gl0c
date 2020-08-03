#pragma once
#include <vector>
#include "GL0cComponent.h"
#include "../utils/GL0cFunc.h"

class GL0cControl : public GL0cComponent {
public:
    GL0cControl();
    ~GL0cControl();

    GL0cControl& poll(const GL0cFunc&);
    GL0cControl& poll(int, int, const std::function<void(float)>&);
    void update(GLFWwindow*) override;

private:
    std::vector<GL0cFunc> mFuncs{ };
    GLFWwindow* mWindow;
};