#pragma once

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <SDL2/SDL.h>
#include <Engine/utils.h>
#include <Engine/Input/InputManager.h>

namespace NUCTE_NS {

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

        void Update() {
            SDL_Event event;

            while (SDL_PollEvent(&event))
            {
                switch (event.type)
                {
                case SDL_MOUSEWHEEL:
                    if (m_InputManager->isKeyPressed(KeyboardKey::KEY_LEFT_CTRL)) {
                        if (event.wheel.y > 0) {
                            float newZoom = GetZoom() * 1.1f;
                            std::cout << newZoom << std::endl;
                            SetZoom(newZoom);
                        }
                        else if (event.wheel.y < 0) {
                            float newZoom = GetZoom() / 1.1f;
                            std::cout << newZoom << std::endl;
                            SetZoom(newZoom);
                        }
                    }
                    break;
                }

            }
        }

        float GetZoom() {
            return m_Zoom;
        }

        const glm::mat4& GetViewProjectionMatrix() const {
            glm::vec3 eye(m_Position.x, m_Position.y, 1.0f);
            glm::vec3 target(m_Position.x, m_Position.y, 0.0f);
            glm::vec3 up(0.0f, 1.0f, 0.0f);

            return m_Projection * glm::lookAt(eye, target, up);
        }


        glm::vec2 Camera::ScreenToWorld(const glm::vec2& screenPos) const {
            glm::mat4 inverseViewProjection = glm::inverse(GetViewProjectionMatrix());

            glm::vec4 normalizedDevicePos;
            normalizedDevicePos.x = (2.0f * screenPos.x) / m_Width - 1.0f;
            normalizedDevicePos.y = 1.0f - (2.0f * screenPos.y) / m_Height;
            normalizedDevicePos.z = 0.0f;
            normalizedDevicePos.w = 1.0f;

            glm::vec4 worldPos = inverseViewProjection * normalizedDevicePos;
            worldPos /= worldPos.w;

            return glm::vec2(worldPos);
        }

        glm::vec2 GetPosition() const { return m_Position; }

        void SetInputManager(InputManager* inputManager) {
            m_InputManager = inputManager;
        }


    private:
        InputManager* m_InputManager;
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
}