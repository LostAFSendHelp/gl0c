#include "GL0cEntity.h"

GL0cEntity::GL0cEntity() { }

GL0cEntity::~GL0cEntity() { }

void GL0cEntity::push(const std::shared_ptr<GL0cComponent>& component) {
    mComponents.push_back(component);
}

void GL0cEntity::update(GLFWwindow* window) {
    for (auto& component : mComponents) {
        component->update(window);
    }
}