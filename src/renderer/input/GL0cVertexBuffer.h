#pragma once
#include <GL/glew.h>

class GL0cVertexBuffer {
public:
    virtual ~GL0cVertexBuffer();

    void bind();
    void unbind();
    virtual void updateData() = 0;
    GLenum type();
    GLuint id();

private:
    const GLenum mType;
    const GLuint mID;
    
protected:
    GL0cVertexBuffer(GLenum type);
};