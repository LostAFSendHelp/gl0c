#pragma once
#include <optional>
#include <memory>
#include "GL0cArrayBuffer.h"
#include "GL0cIndexBuffer.h"
#include "../../component/GL0cComponent.h"

// TODO: wrap this with Transform
class GL0cVertexArray : public GL0cComponent {
public:
    GL0cVertexArray();
    ~GL0cVertexArray();

    template<typename T> void genBuffer();
    template<typename T> void push(const std::vector<T>&);
    void bind() const;
    void unbind() const;
    void translate(float, float, float);
    void rotate(const float&, const glm::vec3&);
    void update(GLFWwindow*) override;

    const glm::mat4& model() const;
    const std::size_t indexCount() const;

    static std::shared_ptr<GL0cVertexArray> createPtr();
    static std::shared_ptr<GL0cVertexArray> sample();

private:
    std::optional<GL0cArrayBuffer> mArrayBuffer;
    std::optional<GL0cIndexBuffer> mIndexBuffer;
    const GLuint mID;
    glm::mat4 mModel{ 1.0f };
};

template<> void GL0cVertexArray::genBuffer<GL0cArrayBuffer>();
template<> void GL0cVertexArray::genBuffer<GL0cIndexBuffer>();

template<> void GL0cVertexArray::push<GL0cVertex>(const std::vector<GL0cVertex>&);
template<> void GL0cVertexArray::push<unsigned int>(const std::vector<unsigned int>&);