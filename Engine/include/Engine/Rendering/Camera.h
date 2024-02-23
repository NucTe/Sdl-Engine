#pragma once

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera {
public:
    Camera(float width, float height) : m_Width(width), m_Height(height), m_Position(0.0f, 0.0f), m_Zoom(1.0f) {
        UpdateProjection();
    }

    void SetPosition(const glm::vec2& position) {
        m_Position = position;
    }

    void SetZoom(float zoom) {
        m_Zoom = zoom;
        UpdateProjection();
    }

    const glm::mat4& GetViewProjectionMatrix() const {
        return m_Projection * glm::translate(glm::mat4(1.0f), glm::vec3(-m_Position.x, -m_Position.y, 0.0f));
    }

private:
    float m_Width;
    float m_Height;
    glm::vec2 m_Position;
    float m_Zoom;
    glm::mat4 m_Projection;

    void UpdateProjection() {
        float zoomedWidth = m_Width / m_Zoom;
        float zoomedHeight = m_Height / m_Zoom;
        m_Projection = glm::ortho(0.0f, zoomedWidth, 0.0f, zoomedHeight, -1.0f, 1.0f);
    }
};