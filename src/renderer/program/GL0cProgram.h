#pragma once
#include <GL/glew.h>
#include <vector>
#include <string>
#include <glm/glm.hpp>
#include "GL0cShader.h"

class GL0cProgram {
public:
    GL0cProgram();
    ~GL0cProgram();

    void link();
    void use();
    void dispose();
    void genShader(const GLenum&, const std::string&);
    void setUniformMat4(const glm::mat4&, const char*) const;
    const unsigned int& id();

    static GL0cProgram sample();

private:
    const unsigned int mID;
    std::vector<GL0cShader> mShaders;
    const char* getLinkStatus();
};