#pragma once
#include <vector>
#include <memory>
#include <GLFW/glfw3.h>
#include "../component/GL0cComponent.h"

class GL0cEntity {
public:
    GL0cEntity();
    virtual ~GL0cEntity();

    virtual void update(GLFWwindow*);
    void push(const std::shared_ptr<GL0cComponent>&);
    template<typename T> T* getComponent();

protected:
    std::vector<std::shared_ptr<GL0cComponent>> mComponents;
};

template<typename T> T* GL0cEntity::getComponent() {
    for (const auto& component : mComponents) {
        if (auto ptr = dynamic_cast<T*>(component.get())) {
            return ptr;
        }
    }

    return nullptr;
}