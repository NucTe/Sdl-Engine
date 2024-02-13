#pragma once

#include <GL/glew.h>
#include <string>

class ShaderLoader {
public:
    static GLuint LoadShader(const char* filePath, GLenum shaderType);
    static GLuint CreateShaderProgram(const char* vertexShaderPath, const char* fragmentShaderPath);
};