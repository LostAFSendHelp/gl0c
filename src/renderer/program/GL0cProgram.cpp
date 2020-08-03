#include "GL0cProgram.h"
#include <iostream>
#include <glm/gtc/type_ptr.hpp>

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

void GL0cProgram::genShader(const GLenum& type, const std::string& path) {
    auto shader = GL0cShader{ type, path };
    glAttachShader(mID, shader.id());
    mShaders.push_back(shader);
}

// TODO: cache the locations
void GL0cProgram::setUniformMat4(const glm::mat4& matrix, const char* name) const {
    auto location = glGetUniformLocation(mID, name);
    if (location > -1) {
        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
    }
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

GL0cProgram GL0cProgram::sample() {
    auto program = GL0cProgram();
    program.genShader(GL_VERTEX_SHADER, "src/assets/vertex_shader.glsl");
    program.genShader(GL_FRAGMENT_SHADER, "src/assets/fragment_shader.glsl");
    program.link();
    program.use();

    return program;
}