#pragma once
#include "GL0cProgram.h"
#include "../input/GL0cVertexArray.h"
#include "../../entity/GL0cCamera.h"

class GL0cRenderer {
public:
    GL0cRenderer(const GL0cProgram&);
    ~GL0cRenderer();

    void render(const GL0cVertexArray&) const;
    void render(const GL0cCamera&) const;
    void clear() const;
    GL0cProgram mProgram;

    static GL0cRenderer sample();
};