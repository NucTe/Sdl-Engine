#pragma once

#include "Vector2d.h"

class PhysicsObject {
public:
    float width;
    float height;
    Vector2d position;
    Vector2d velocity;
    double bounciness;
    bool isStatic;
    double angle;

    PhysicsObject(const Vector2d& velocity, double bounciness, bool isStatic, double angle)
        : velocity(velocity), bounciness(bounciness), isStatic(isStatic), angle(angle) {}

    bool intersect(const PhysicsObject& other) const {
        double thisMinX = position.x - width / 2.0;
        double thisMaxX = position.x + width / 2.0;
        double thisMinY = position.y - height / 2.0;
        double thisMaxY = position.y + height / 2.0;

        double otherMinX = other.position.x - other.width / 2.0;
        double otherMaxX = other.position.x + other.width / 2.0;
        double otherMinY = other.position.y - other.height / 2.0;
        double otherMaxY = other.position.y + other.height / 2.0;

        bool intersectX = thisMinX <= otherMaxX && thisMaxX >= otherMinX;
        bool intersectY = thisMinY <= otherMaxY && thisMaxY >= otherMinY;

        return intersectX && intersectY;
    }
    Vector2d PhysicsObject::getSupport(const Vector2d& direction) const {
        double halfWidth = width / 2.0;
        double halfHeight = height / 2.0;

        Vector2d supportPoint(
            direction.x >= 0 ? halfWidth : -halfWidth,
            direction.y >= 0 ? halfHeight : -halfHeight
        );

        double angle = this->angle;
        double cosAngle = cos(angle);
        double sinAngle = sin(angle);
        Vector2d rotatedSupportPoint(
            supportPoint.x * cosAngle - supportPoint.y * sinAngle,
            supportPoint.x * sinAngle + supportPoint.y * cosAngle
        );

        return position + rotatedSupportPoint;
    }

};

struct Body {
    Vector2d position;
    Vector2d velocity;
    double mass;
};

class Collider {
public:
    PhysicsObject* physicsObject;
    Body* body;

    Collider(PhysicsObject* physicsObject, Body* body) : physicsObject(physicsObject), body(body) {}

    bool intersect(const Collider& other) const {
        return physicsObject->intersect(*(other.physicsObject));
    }

    Vector2d getSupport(const Vector2d& direction) const {
        return physicsObject->getSupport(direction);
    }
};

class World {
public:
    std::vector<Body> bodies;
    std::vector<Collider> colliders;

    void addBody(const Body& body) {
        bodies.push_back(body);
    }

    void addCollider(const Collider& collider) {
        colliders.push_back(collider);
    }

    void step(double dt) {
    }
};



