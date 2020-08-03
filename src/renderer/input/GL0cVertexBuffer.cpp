#include "GL0cVertexBuffer.h"

GL0cVertexBuffer::~GL0cVertexBuffer() { }

void GL0cVertexBuffer::bind() {
    glBindBuffer(mType, mID);
}

void GL0cVertexBuffer::unbind() {
    glBindBuffer(mType, 0);
}

GLenum GL0cVertexBuffer::type() {
    return mType;
}

GLuint GL0cVertexBuffer::id() {
    return mID;    
}

GL0cVertexBuffer::GL0cVertexBuffer(GLenum type):
mType(type),
mID([]() {
    GLuint id;
    glGenBuffers(1, &id);
    return id;
}()) { }
