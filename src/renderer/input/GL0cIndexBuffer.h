#pragma once
#include <vector>
#include "GL0cVertexBuffer.h"

class GL0cIndexBuffer : public GL0cVertexBuffer {
public:
    GL0cIndexBuffer();
    ~GL0cIndexBuffer();

    void push(const unsigned int&);
    void push(const std::vector<unsigned int>&);
    void updateData() override;
    std::size_t indexCount() const;

private:
    std::vector<unsigned int> mIndices;
};