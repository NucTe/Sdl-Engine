#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stb/stb_image.h>
#include <iostream>
#include "Engine/EMS/Entity.h"

class Draw {
public:
    // Drawing functions
    static void Point(const glm::vec2& point, const glm::vec4& color);
    static void Line(const glm::vec2& start, const glm::vec2& end, const glm::vec4& color);
    static void Rectangle(const glm::vec2& position, float width, float height, const glm::vec4& color, bool fill = true, PhysicsObject* physicsObject = nullptr);
    static void TextureRect(const std::string& filePath, const glm::vec2& position, int width, int height, PhysicsObject* physicsObject);
    static void tEntity(const Entity* entity, const glm::vec4& color, bool fill = true);

};