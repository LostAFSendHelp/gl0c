#include "GL0cControl.h"

GL0cControl::GL0cControl() { }

GL0cControl::~GL0cControl() { }

GL0cControl& GL0cControl::poll(const GL0cFunc& func) {
    mFuncs.push_back(func);
    return *this;
}

GL0cControl& GL0cControl::poll(int positive, int negative, const std::function<void(float)>& func) {
    mFuncs.push_back({ positive, negative, func });
    return *this;
}

void GL0cControl::update(GLFWwindow* window) {
    for (const auto& func : mFuncs) {
        func.poll(window);
    }
}
