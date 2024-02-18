#include "SdlEngine/Renderer/ShaderLoader.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <filesystem>

GLuint ShaderLoader::LoadShader(const char* filePath, GLenum shaderType) {
    if (!std::filesystem::exists(filePath)) {
        std::cerr << "Shader file does not exist: " << filePath << std::endl;
        return 0;
    }

    std::ifstream shaderFile(filePath);
    if (!shaderFile.is_open()) {
        std::cerr << "Failed to open shader file: " << filePath << std::endl;
        return 0;
    }

    std::stringstream shaderStream;
    shaderStream << shaderFile.rdbuf();
    shaderFile.close();

    std::string shaderCode = shaderStream.str();
    if (shaderCode.empty()) {
        std::cerr << "Shader file is empty: " << filePath << std::endl;
        return 0;
    }

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

GLuint ShaderLoader::LoadShaderFromMemory(const char* shaderCode, GLenum shaderType) {
    const char* shaderCodePtr = shaderCode;

    GLuint shaderID = glCreateShader(shaderType);
    glShaderSource(shaderID, 1, &shaderCodePtr, nullptr);
    glCompileShader(shaderID);

    GLint success;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
    if (!success) {
        GLchar infoLog[512];
        glGetShaderInfoLog(shaderID, sizeof(infoLog), nullptr, infoLog);
        std::cerr << "Shader compilation error:\n" << infoLog << std::endl;
        return 0;
    }

    return shaderID;
}


GLuint ShaderLoader::CreateShaderProgram(const char* mvertexShader, const char* mfragmentShader, bool ShaderMem) {
    GLuint vertexShader, fragmentShader;
    if (ShaderMem) {
        vertexShader = LoadShaderFromMemory(mvertexShader, GL_VERTEX_SHADER);
        fragmentShader = LoadShaderFromMemory(mfragmentShader, GL_FRAGMENT_SHADER);
    }
    else {
        vertexShader = LoadShader(mvertexShader, GL_VERTEX_SHADER);
        fragmentShader = LoadShader(mfragmentShader, GL_FRAGMENT_SHADER);
    }
    

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
