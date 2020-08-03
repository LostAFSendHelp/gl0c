#include "GL0cContext.h"

GL0cContext::GL0cContext(const GL0cRenderer& renderer, GLFWwindow* window):
mRenderer(renderer),
mWindow(window) { }

GL0cContext::~GL0cContext() { }

void GL0cContext::terminate() const {
    glfwTerminate();
}

std::shared_ptr<GL0cContext> GL0cContext::sample(GLFWwindow* window) {
    auto context = std::make_shared<GL0cContext>(GL0cRenderer::sample(), window);
    auto box1 = std::make_shared<GL0cEntity>();
    auto box2 = std::make_shared<GL0cEntity>();
    box1->push(GL0cVertexArray::sample());
    box1->getComponent<GL0cVertexArray>()->translate(-.5f, .0f, .0f );
    box2->push(GL0cVertexArray::sample());
    box2->getComponent<GL0cVertexArray>()->translate(.5f, .0f, .0f );
    context->mEntities.push_back(box1);
    context->mEntities.push_back(box2);
    return context;
}