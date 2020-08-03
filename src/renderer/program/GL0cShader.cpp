#include "GL0cShader.h"
#include <iostream>
#include <fstream>

GL0cShader::GL0cShader(GLenum type, const std::string& path):
mID(glCreateShader(type)) {
    std::fstream reader(path);
    std::string line;

    while (std::getline(reader, line)) {
        mSource.append(line + "\n");
    }

    auto sourceString = mSource.c_str();
    glShaderSource(mID, 1, &sourceString, nullptr);
    glCompileShader(mID);
    
    std::cout << "Shader [ID" << mID << "] source:\n" << mSource << std::endl;
    auto status = getCompileStatus();
    if (status != nullptr) {
        std::cout << "Shader compilation error [ID " << mID << "] : " << status << std::endl;
        delete[] status;
    }
}

GL0cShader::~GL0cShader() {
    dispose();
}

const unsigned int& GL0cShader::id() const {
    return mID;
}

const std::string& GL0cShader::source() const {
    return mSource;
}

void GL0cShader::dispose() const {
    glDeleteShader(mID);
}

const char* GL0cShader::getCompileStatus() {
    int status;
    int length;
    char* log = nullptr;
    
    glGetShaderiv(mID, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE) {
        glGetShaderiv(mID, GL_INFO_LOG_LENGTH, &length);
        log = new char[length];
        glGetShaderInfoLog(mID, length * sizeof(char), nullptr, log);
    }

    return log;
}
