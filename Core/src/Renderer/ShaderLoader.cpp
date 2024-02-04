#include "SdlEngine/Renderer/ShaderLoader.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <filesystem>

GLuint ShaderLoader::LoadShader(const char* filePath, GLenum shaderType) {
    std::ifstream shaderFile(filePath);
    if (!shaderFile.is_open()) {
        std::cerr << "Failed to open shader file: " << filePath << std::endl;
        return 0;
    }

    std::stringstream shaderStream;
    shaderStream << shaderFile.rdbuf();
    shaderFile.close();

    std::string shaderCode = shaderStream.str();
    const char* shaderCodePtr = shaderCode.c_str();

    GLuint shaderID = glCreateShader(shaderType);
    glShaderSource(shaderID, 1, &shaderCodePtr, nullptr);
    glCompileShader(shaderID);

    GLint success;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
    if (!success) {
        GLchar infoLog[512];
        glGetShaderInfoLog(shaderID, sizeof(infoLog), nullptr, infoLog);
        std::cerr << "Shader compilation error in file " << filePath << ":\n" << infoLog << std::endl;
        return 0;
    }

    return shaderID;
}

GLuint ShaderLoader::CreateShaderProgram(const char* vertexShaderPath, const char* fragmentShaderPath) {
    std::filesystem::path absoluteVertexPath = std::filesystem::absolute(vertexShaderPath);
    std::filesystem::path absoluteFragmentPath = std::filesystem::absolute(fragmentShaderPath);
    std::string aVertexPath = absoluteVertexPath.string();
    std::string afragmentPath = absoluteFragmentPath.string();

    GLuint vertexShader = LoadShader(aVertexPath.c_str(), GL_VERTEX_SHADER);
    GLuint fragmentShader = LoadShader(afragmentPath.c_str(), GL_FRAGMENT_SHADER);

    if (vertexShader == 0 || fragmentShader == 0) {
        std::cerr << "Failed to load shaders." << std::endl;
        return 0;
    }

    GLuint programID = glCreateProgram();
    glAttachShader(programID, vertexShader);
    glAttachShader(programID, fragmentShader);
    glLinkProgram(programID);

    GLint success;
    glGetProgramiv(programID, GL_LINK_STATUS, &success);
    if (!success) {
        GLchar infoLog[512];
        glGetProgramInfoLog(programID, sizeof(infoLog), nullptr, infoLog);
        std::cerr << "Shader program linking error:\n" << infoLog << std::endl;
        return 0;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return programID;
}
