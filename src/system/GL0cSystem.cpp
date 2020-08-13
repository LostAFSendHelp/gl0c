#include "GL0cSystem.h"

GL0cSystem::GL0cSystem(const std::shared_ptr<GL0cContext>& context):
mContext(context) { }

GL0cSystem::~GL0cSystem() { }

void GL0cSystem::init() {
    glfwSetWindowUserPointer(window(), &camera());
    glfwSetFramebufferSizeCallback(window(), [](GLFWwindow* w, int width, int height) {
        glViewport(0, 0, width, height);
        auto camera = static_cast<GL0cCamera*>(glfwGetWindowUserPointer(w));
        camera->updatePerspective(width, height);
    });
}

void GL0cSystem::loop() {
    while (!glfwWindowShouldClose(window())) {
        glfwSwapBuffers(window());
        glfwPollEvents();

        renderer().clear();
        renderer().render(camera());
        camera().update(window());

        for (auto& entity : entities()) {
            entity->update(window());

            if (auto vao = entity->getComponent<GL0cVertexArray>()) {
                renderer().render(*vao);
            }
        }

        if (glfwGetKey(window(), GLFW_KEY_ESCAPE) || glfwGetKey(window(), GLFW_KEY_Q)) {
            glfwSetWindowShouldClose(window(), GL_TRUE);
        }
    }
}

void GL0cSystem::terminate() {
    glfwTerminate();
}

GLFWwindow* GL0cSystem::window() const {
    return mContext->mWindow;
}

const GL0cRenderer& GL0cSystem::renderer() const {
    return mContext->mRenderer;
}

GL0cCamera& GL0cSystem::camera() {
    return mContext->mCamera;
}

const std::vector<std::shared_ptr<GL0cEntity>>& GL0cSystem::entities() const {
    return mContext->mEntities;
}