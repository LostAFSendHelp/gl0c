#include "GL0cVertexArray.h"
#include <glm/gtc/matrix_transform.hpp>
#include <memory>

GL0cVertexArray::GL0cVertexArray():
mID([]() {
    GLuint vao;
    glGenBuffers(1, &vao);
    return vao;
}()) { }

GL0cVertexArray::~GL0cVertexArray() { }

template<typename T> void GL0cVertexArray::genBuffer() {
    return;
}

template<typename T> void GL0cVertexArray::push(const std::vector<T>& vector) {
    return;
}

void GL0cVertexArray::bind() const {
    glBindVertexArray(mID);    
}

void GL0cVertexArray::unbind() const {
    glBindVertexArray(0);
}

void GL0cVertexArray::translate(float x, float y, float z) {
    mModel = glm::translate(mModel, { x, y, z });
}

void GL0cVertexArray::rotate(const float& radians, const glm::vec3& axis) {
    mModel = glm::rotate(mModel, radians, axis);
}

void GL0cVertexArray::update(GLFWwindow* window) { } // TODO: remove this when implementing Transform

const glm::mat4& GL0cVertexArray::model() const {
    return mModel;
}

const std::size_t GL0cVertexArray::indexCount() const {
    return mIndexBuffer->indexCount();
}

std::shared_ptr<GL0cVertexArray> GL0cVertexArray::createPtr() {
    return std::make_shared<GL0cVertexArray>();
}

template<> void GL0cVertexArray::genBuffer<GL0cArrayBuffer>() {
    if (!mArrayBuffer.has_value()) {
        mArrayBuffer.emplace();
        mArrayBuffer->bind();
    }
}

template<> void GL0cVertexArray::genBuffer<GL0cIndexBuffer>() {
    if (!mIndexBuffer) {
        mIndexBuffer.emplace();
        mIndexBuffer->bind();
    }
}

template<> void GL0cVertexArray::push<GL0cVertex>(const std::vector<GL0cVertex>& vertices) {
    if (!mArrayBuffer.has_value()) {
        genBuffer<GL0cArrayBuffer>();
    }

    mArrayBuffer->push(vertices);
}

template<> void GL0cVertexArray::push<unsigned int>(const std::vector<unsigned int>& indices) {
    if (!mIndexBuffer.has_value()) {
        genBuffer<GL0cIndexBuffer>();
    }

    mIndexBuffer->push(indices);
}

std::shared_ptr<GL0cVertexArray> GL0cVertexArray::sample() {
    auto vao = GL0cVertexArray();
    std::vector<GL0cVertex> vertices {
        {{-.25f, .25f, .25f }, { 0.0f, 0.0f, 1.0f }},     // TLF
        {{ .25f, .25f, .25f }, { 1.0f, 0.0f, 0.0f }},     // TRF
        {{ .25f, -.25f, .25f }, { 1.0f, 1.0f, 0.0f }},     // BRF
        {{-.25f, -.25f, .25f }, { 0.0f, 1.0f, 0.0f }},     // BLF
        
        {{-.25f, .25f, -.25f }, { 0.0f, 0.0f, 1.0f }},    // TLB
        {{ .25f, .25f, -.25f }, { 1.0f, 0.0f, 0.0f }},    // TRB
        {{ .25f, -.25f, -.25f }, { 1.0f, 1.0f, 0.0f }},    // BRB
        {{-.25f, -.25f, -.25f }, { 0.0f, 1.0f, 0.0f }}     // BLB
    };

    std::vector<unsigned int> indices {
        // front
        0, 1, 2,
        2, 3, 0,
        // right
        1, 5, 6,
        6, 2, 1,
        // back
        7, 6, 5,
        5, 4, 7,
        // left
        4, 0, 3,
        3, 7, 4,
        // bottom
        4, 5, 1,
        1, 0, 4,
        // top
        3, 2, 6,
        6, 7, 3
    };

    vao.push(vertices);
    vao.push(indices);
    vao.mArrayBuffer->updateData();
    vao.mIndexBuffer->updateData();

    return std::make_shared<GL0cVertexArray>(std::move(vao));
}