#include "GL0cProgram.h"
#include <iostream>

GL0cProgram::GL0cProgram():
mID(glCreateProgram()) { }

GL0cProgram::~GL0cProgram() {
    dispose();
}

void GL0cProgram::link() {
    glLinkProgram(mID);
    auto status = getLinkStatus();
    if (status != nullptr) {
        std::cout << "Program link error [ID " << mID << "] : " << status << std::endl;
        delete[] status;
    }
}

void GL0cProgram::use() {
    glUseProgram(mID);
}

void GL0cProgram::dispose() {
    for (auto& shader : mShaders) {
        shader.dispose();
    }

    glDeleteProgram(mID);
}

void GL0cProgram::genShader(const GLint& type, const std::string& path) {
    auto shader = GL0cShader{ type, path };
    glAttachShader(mID, shader.id());
    mShaders.push_back(shader);
}

const unsigned int& GL0cProgram::id() {
    return mID;
}

const char* GL0cProgram::getLinkStatus() {
    int status;
    int length;
    char* log = nullptr;

    glGetProgramiv(mID, GL_LINK_STATUS, &status);
    if (status == GL_FALSE) {
        glGetProgramiv(mID, GL_INFO_LOG_LENGTH, &length);
        log = new char[length];
        glGetProgramInfoLog(mID, length * sizeof(char), nullptr, log);
    }

    return log;
}