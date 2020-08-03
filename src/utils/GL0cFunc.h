#pragma once
#include <GLFW/glfw3.h>
#include <functional>

class GL0cFunc {
public:
    GL0cFunc(int, int, const std::function<void(int)>&);
    ~GL0cFunc();

    void poll(GLFWwindow*) const;

private:
    const int mPositive;
    const int mNegative;
    const std::function<void(int)> mFunc;
};