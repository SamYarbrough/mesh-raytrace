#pragma once

#include <cmath>
#include <string>

#include "Util.hpp"

class Vec2 {
public:
    float x, y;

    Vec2();
    Vec2(const float);
    Vec2(const float, const float);

    std::string toString();
    std::string toString(int);

    float lengthSquared();
    float length();

    Vec2 operator+(const Vec2) const;
    Vec2 operator+(const float) const;
    void operator+=(const Vec2);
    void operator+=(const float);

    Vec2 operator-(const Vec2) const;
    Vec2 operator-(const float) const;
    void operator-=(const Vec2);
    void operator-=(const float);

    Vec2 operator*(const Vec2) const;
    Vec2 operator*(const float) const;
    void operator*=(const Vec2);
    void operator*=(const float);

    Vec2 operator/(const Vec2) const;
    Vec2 operator/(const float) const;
    void operator/=(const Vec2);
    void operator/=(const float);

    Vec2 operator-() const;

    // non object specific

    static float dot(const Vec2, const Vec2);
    static float distance(const Vec2, const Vec2);
    static float distanceSquared(const Vec2, const Vec2);
    static Vec2 reflect(const Vec2, const Vec2);
    static Vec2 refract(const Vec2, const Vec2, const float);
    static Vec2 abs(const Vec2);
    static Vec2 step(const Vec2, const Vec2);
    static Vec2 sign(const Vec2);
};

// more prototypes

Vec2 operator+(const float, const Vec2);
Vec2 operator-(const float, const Vec2);
Vec2 operator*(const float, const Vec2);
Vec2 operator/(const float, const Vec2);

// ----------------------------------------

Vec2::Vec2() { x = y = 0.0; }
Vec2::Vec2(const float val) { x = y = val; }
Vec2::Vec2(const float val1, const float val2) { x = val1; y = val2; }

std::string Vec2::toString() {
    std::string output = "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    return output;
}

std::string Vec2::toString(int decimals) {
    std::string output = "(" + Util::trunc(x, decimals) + ", "
        + Util::trunc(y, decimals) + ")";
    return output;
}

float Vec2::lengthSquared() { return x*x + y*y; }
float Vec2::length() { return std::sqrt(x*x + y*y); }

Vec2 Vec2::operator+(const Vec2 vec) const { return Vec2(x + vec.x, y + vec.y); }
Vec2 Vec2::operator+(const float val) const { return Vec2(x + val, y + val); }
void Vec2::operator+=(const Vec2 vec) { x += vec.x; y += vec.y; }
void Vec2::operator+=(const float val) { x += val; y += val; }

Vec2 Vec2::operator-(const Vec2 vec) const { return Vec2(x - vec.x, y - vec.y); }
Vec2 Vec2::operator-(const float val) const { return Vec2(x - val, y - val); }
void Vec2::operator-=(const Vec2 vec) { x -= vec.x; y -= vec.y; }
void Vec2::operator-=(const float val) { x -= val; y -= val; }

Vec2 Vec2::operator*(const Vec2 vec) const { return Vec2(x * vec.x, y * vec.y); }
Vec2 Vec2::operator*(const float val) const { return Vec2(x * val, y * val); }
void Vec2::operator*=(const Vec2 vec) { x *= vec.x; y *= vec.y; }
void Vec2::operator*=(const float val) { x *= val; y *= val; }

Vec2 Vec2::operator/(const Vec2 vec) const { return Vec2(x / vec.x, y / vec.y); }
Vec2 Vec2::operator/(const float val) const { return Vec2(x / val, y / val); }
void Vec2::operator/=(const Vec2 vec) { x /= vec.x; y /= vec.y; }
void Vec2::operator/=(const float val) { x /= val; y /= val; }

Vec2 Vec2::operator-() const { return Vec2(-x, -y); }

// more definitions

Vec2 operator+(const float val, const Vec2 vec) { return Vec2(val + vec.x, val + vec.y); }
Vec2 operator-(const float val, const Vec2 vec) { return Vec2(val - vec.x, val - vec.y); }
Vec2 operator*(const float val, const Vec2 vec) { return Vec2(val * vec.x, val * vec.y); }
Vec2 operator/(const float val, const Vec2 vec) { return Vec2(val / vec.x, val / vec.y); }

// non object specific

float Vec2::dot(const Vec2 a, const Vec2 b) { 
    return a.x*b.x + a.y*b.y; 
}

float Vec2::distance(const Vec2 a, const Vec2 b) {
    return (a - b).length();
}

float Vec2::distanceSquared(const Vec2 a, const Vec2 b) {
    return (a - b).lengthSquared();
}

Vec2 Vec2::reflect(const Vec2 i, const Vec2 n) {
    return i - 2.0 * dot(i, n) * n;
}

Vec2 Vec2::refract(const Vec2 i, const Vec2 n, const float eta) {
    float d = dot(n, i);
    float k = 1.0 - eta*eta * (1.0 - d*d);

    return (k < 0.0) ? Vec2(0.0) : eta * i - (eta * d + std::sqrt(k)) * n; 
}

Vec2 Vec2::abs(const Vec2 vec) {
    return Vec2(std::abs(vec.x), std::abs(vec.y));
}

Vec2 Vec2::step(const Vec2 edge, const Vec2 x) {
    return Vec2(
        (x.x < edge.x) ? 0.0 : 1.0,
        (x.y < edge.y) ? 0.0 : 1.0
    );
}

Vec2 Vec2::sign(const Vec2 vec) {
    return Vec2(
        (vec.x < 0.0) ? -1.0 : ((vec.x > 0.0) ? 1.0 : 0.0),
        (vec.y < 0.0) ? -1.0 : ((vec.y > 0.0) ? 1.0 : 0.0)
    );
}
