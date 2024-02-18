#include "SdlEngine/Renderer/OpenGLRenderer.h"
#include "SdlEngine/Renderer/ShaderLoader.h"
#include "SdlEngine/Renderer/texturemanager.h"

#include <iostream>
#include <glm/ext/matrix_transform.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>


GLuint OpenGLRenderer::shaderProgram = 0;

OpenGLRenderer::OpenGLRenderer() {};
OpenGLRenderer::~OpenGLRenderer() {};

void OpenGLRenderer::Render(const NUCTE_NS::GameWorld& gameWorld) {
    const std::vector<NUCTE_NS::Entity*>& entities = gameWorld.GetEntities();
    for (NUCTE_NS::Entity* entity : entities) {
        Vector2 entityPosition = entity->GetPosition();
        float width = entity->GetSize().x;
        float height = entity->GetSize().y;
        std::string filepath = entity->GetTextureFilePath();
        if (entity->HasTexture()) {
            int Vao = CreateTextureRectVAO(filepath, width, height);
            DrawTextureRect(Vao, glm::vec2(entityPosition.x, entityPosition.y), width, height);
        }
        else {
            int Vao = CreateRectangleVAO();
            DrawRectangle(Vao, glm::vec2(entityPosition.x, entityPosition.y), width, height, {0, 0, 0, 0}, true);
        }
    }
}

GLuint OpenGLRenderer::Initialize(const char* vertexShaderPath, const char* fragmentShaderPath) {
    GLuint ShaderProgram = CreateShaderProgram(vertexShaderPath, fragmentShaderPath);
    if (ShaderProgram == 0) {
        // Something
    }


    std::cout << ShaderProgram << std::endl;
    return ShaderProgram;
};

// GLuint
GLuint OpenGLRenderer::CreateShaderProgram(const char* vertexShaderPath, const char* fragmentShaderPath) {
    return ShaderLoader::CreateShaderProgram(vertexShaderPath, fragmentShaderPath);
}

GLuint OpenGLRenderer::CreateRectangleVAO() {
    GLfloat vertices[] = {
        0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,  
        0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,  
       -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,  
       -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f   
    };

    GLuint indices[] = {
        0, 1, 3,   
        1, 2, 3   
    };

    GLuint VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);

    return VAO;
}

GLuint OpenGLRenderer::CreateTextureRectVAO(const std::string& filePath, int width, int height) {
    GLuint vaoID, vboID, textureID;

    textureID = TextureManager::LoadTexture(filePath);

    GLfloat vertices[] = {

        0.0f, 0.0f, 0.0f, 1.0f, 
        1.0f, 0.0f, 1.0f, 1.0f, 
        1.0f, 1.0f, 1.0f, 0.0f, 
        0.0f, 1.0f, 0.0f, 0.0f  
    };

    glGenVertexArrays(1, &vaoID);
    glBindVertexArray(vaoID);


    glGenBuffers(1, &vboID);
    glBindBuffer(GL_ARRAY_BUFFER, vboID);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)(2 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    return vaoID;
}

// Drawing Funcions

GLuint OpenGLRenderer::DrawTextureRect(GLuint vaoID, const glm::vec2& position, int width, int height) {
    glBindVertexArray(vaoID);

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(position.x, position.y, 0.0f));
    model = glm::scale(model, glm::vec3(width, height, 1.0f));

    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(glm::value_ptr(model));

    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

    glBindVertexArray(0);

    return vaoID;
}

GLuint OpenGLRenderer::DrawRectangle(GLuint vaoID, const glm::vec2& position, float width, float height, const glm::vec4& color, bool fill) {
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(position.x, position.y, 0.0f));
    model = glm::scale(model, glm::vec3(width, height, 1.0f));

    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(glm::value_ptr(model));

    glBindVertexArray(vaoID);

    if (fill) {
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    }
    else {
        glDrawArrays(GL_LINE_LOOP, 0, 4);
    }

    glBindVertexArray(0);

    return vaoID;
}


void OpenGLRenderer::DrawPoint(const glm::vec2& point, const glm::vec4& color) {
    glBegin(GL_POINTS);
    glColor4f(color.r, color.g, color.b, color.a);
    glVertex2f(point.x, point.y);
    glEnd();
}

void OpenGLRenderer::DrawLine(const glm::vec2& start, const glm::vec2& end, const glm::vec4& color) {
    glBegin(GL_LINES);
    glColor4f(color.r, color.g, color.b, color.a);
    glVertex2f(start.x, start.y);
    glVertex2f(end.x, end.y);
    glEnd();
}