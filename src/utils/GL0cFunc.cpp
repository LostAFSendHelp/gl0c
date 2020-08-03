#include "GL0cFunc.h"

GL0cFunc::GL0cFunc(int positive, int negative, const std::function<void(int)>& func):
mPositive(positive),
mNegative(negative),
mFunc(func) { }

GL0cFunc::~GL0cFunc() {
}

void GL0cFunc::poll(GLFWwindow* window) const {
    auto pos = glfwGetKey(window, mPositive);
    auto neg = glfwGetKey(window, mNegative);
    auto magnitude = mPositive == mNegative ? pos * neg : pos - neg;
    
    mFunc(magnitude);
}
