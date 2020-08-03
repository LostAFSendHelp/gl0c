#pragma once
#include <GL/glew.h>
#include <string>

class GL0cShader {
public:
    GL0cShader(GLenum type, const std::string& path);
    ~GL0cShader();

    const unsigned int& id() const;
    const std::string& source() const;
    void dispose() const;

private:
    const unsigned int mID;
    std::string mSource;
    const char* getCompileStatus();
};