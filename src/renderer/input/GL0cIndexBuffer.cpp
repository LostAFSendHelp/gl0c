#include "GL0cIndexBuffer.h"

GL0cIndexBuffer::GL0cIndexBuffer():
GL0cVertexBuffer(GL_ELEMENT_ARRAY_BUFFER) { }

GL0cIndexBuffer::~GL0cIndexBuffer() { }

void GL0cIndexBuffer::push(const unsigned int& index) {
    mIndices.push_back(index);
}

void GL0cIndexBuffer::push(const std::vector<unsigned int>& indices) {
    mIndices.reserve(mIndices.size() + indices.size());
    mIndices.insert(mIndices.end(), indices.begin(), indices.end());
}

void GL0cIndexBuffer::updateData() {
    bind();
    glBufferData(type(), sizeof(unsigned int) * mIndices.size(), &mIndices[0], GL_STATIC_DRAW);
}

std::size_t GL0cIndexBuffer::indexCount() const {
    return mIndices.size();
}
