#pragma once
#include <GL/glew.h>
#include <vector>
#include <string>
#include "GL0cShader.h"

class GL0cProgram {
public:
    GL0cProgram();
    ~GL0cProgram();

    void link();
    void use();
    void dispose();
    void genShader(const GLint&, const std::string&);
    const unsigned int& id();

private:
    const unsigned int mID;
    std::vector<GL0cShader> mShaders;
    const char* getLinkStatus();
};