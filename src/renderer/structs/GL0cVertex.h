#pragma once
#include <glm/glm.hpp>

struct GL0cVertex {
    glm::vec3 mPosition;
    glm::vec3 mColor;

    static const unsigned int SIZE_POSITION = 3;
    static const unsigned int SIZE_COLOR = 3;
    static const unsigned int SIZE_VERTEX = 6;
};