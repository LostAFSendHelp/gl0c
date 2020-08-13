#include "system/GL0cSystem.h"

static GLFWwindow* init(int width, int height, const char* title) {
    glfwInit();
    glfwWindowHint(GLFW_VERSION_MINOR, 3);
    auto window = glfwCreateWindow(width, height, title, NULL, NULL);
    glfwMakeContextCurrent(window);
    glewInit();
    glViewport(0, 0, width, height);
    glEnable(GL_DEPTH_TEST);

    return window;
}

int main() {
    auto window = init(800, 600, "0c");
    auto system = GL0cSystem(GL0cContext::sample(window));
    system.init();
    system.loop();
    system.terminate();

    return 0;
}