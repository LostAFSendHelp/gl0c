#include "GL0cArrayBuffer.h"

GL0cArrayBuffer::GL0cArrayBuffer():
GL0cVertexBuffer(GL_ARRAY_BUFFER) { }

GL0cArrayBuffer::~GL0cArrayBuffer() { }

void GL0cArrayBuffer::push(const GL0cVertex& vertex) {
    mVertexData.push_back(vertex.mPosition.x);
    mVertexData.push_back(vertex.mPosition.y);
    mVertexData.push_back(vertex.mPosition.z);

    mVertexData.push_back(vertex.mColor.x);
    mVertexData.push_back(vertex.mColor.y);
    mVertexData.push_back(vertex.mColor.z);
}

void GL0cArrayBuffer::push(const std::vector<GL0cVertex>& vertices) {
    for (const auto& vertex : vertices) {
        push(vertex);
    }
}

void GL0cArrayBuffer::updateData() {
    bind();
    glBufferData(type(), sizeof(float) * mVertexData.size(), &mVertexData[0], GL_STATIC_DRAW);
    glVertexAttribPointer(GL0C_INDEX_LOCATION,
                          GL0cVertex::SIZE_POSITION,
                          GL_FLOAT, GL_FALSE,
                          sizeof(float) * GL0cVertex::SIZE_VERTEX,
                          nullptr);
    glVertexAttribPointer(GL0C_INDEX_COLOR,
                          GL0cVertex::SIZE_COLOR,
                          GL_FLOAT, GL_FALSE,
                          sizeof(float) * GL0cVertex::SIZE_VERTEX,
                          (void*)(sizeof(float) * GL0cVertex::SIZE_POSITION));
    glEnableVertexAttribArray(GL0C_INDEX_LOCATION);
    glEnableVertexAttribArray(GL0C_INDEX_COLOR);
}
