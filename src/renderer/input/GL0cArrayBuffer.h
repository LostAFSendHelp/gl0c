#pragma once
#include <glm/glm.hpp>
#include <vector>
#include "GL0cVertexBuffer.h"
#include "../structs/GL0cVertex.h"

class GL0cArrayBuffer : public GL0cVertexBuffer {
public:
    GL0cArrayBuffer();
    ~GL0cArrayBuffer();

    void push(const GL0cVertex&);
    void push(const std::vector<GL0cVertex>&);
    void updateData() override;

private:
    std::vector<float> mVertexData;
    static const GLuint GL0C_INDEX_LOCATION = 0;
    static const GLuint GL0C_INDEX_COLOR = 1;
};