#include "GL0cRenderer.h"

GL0cRenderer::GL0cRenderer(const GL0cProgram& program):
mProgram(program) { }

GL0cRenderer::~GL0cRenderer() { }

void GL0cRenderer::render(const GL0cVertexArray& vao) const {
    vao.unbind();
    vao.bind();
    mProgram.setUniformMat4(vao.model(), "uModel");
    glDrawElements(GL_TRIANGLES, vao.indexCount(), GL_UNSIGNED_INT, nullptr);
    vao.unbind();
}

void GL0cRenderer::render(const GL0cCamera& camera) const {
    mProgram.setUniformMat4(camera.view(), "uView");
    mProgram.setUniformMat4(camera.projection(), "uProjection");
}

void GL0cRenderer::clear() const {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

GL0cRenderer GL0cRenderer::sample() {
    return GL0cRenderer{ GL0cProgram::sample() };
}