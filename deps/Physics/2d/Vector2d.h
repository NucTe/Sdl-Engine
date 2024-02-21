#pragma once

#include <cmath>
#include <vector>



class Vector2d {
public:
    double x;
    double y;

    Vector2d() : x(0.0), y(0.0) {}
    Vector2d(double x, double y) : x(x), y(y) {}

    double squaredNorm() const {
        return x * x + y * y;
    }

    Vector2d operator+(const Vector2d& other) const {
        return Vector2d(x + other.x, y + other.y);
    }

    Vector2d operator-(const Vector2d& other) const {
        return Vector2d(x - other.x, y - other.y);
    }

    Vector2d operator*(double scalar) const {
        return Vector2d(x * scalar, y * scalar);
    }

    Vector2d operator/(double scalar) const {
        return Vector2d(x / scalar, y / scalar);
    }

    Vector2d& operator+=(const Vector2d& other) {
        x += other.x;
        y += other.y;
        return *this;
    }


    double dot(const Vector2d& other) const {
        return x * other.x + y * other.y;
    }

    double cross(const Vector2d& other) const {
        return x * other.y - y * other.x;
    }

    double magnitude() const {
        return sqrt(x * x + y * y);
    }

    Vector2d normalized() const {
        double mag = magnitude();
        return mag > 0 ? *this / mag : *this;
    }
};
