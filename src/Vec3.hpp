#pragma once

#include <cmath>
#include <string>

#include "Vec2.hpp"
#include "Util.hpp"

class Vec3 {
public:
    float x, y, z;

    Vec3();
    Vec3(const float);
    Vec3(const float, const float, const float);
    Vec3(const Vec2, const float);
    Vec3(const float, const Vec2);

    std::string toString();
    std::string toString(int);

    float lengthSquared();
    float length();

    Vec3 operator+(const Vec3) const;
    Vec3 operator+(const float) const;
    void operator+=(const Vec3);
    void operator+=(const float);

    Vec3 operator-(const Vec3) const;
    Vec3 operator-(const float) const;
    void operator-=(const Vec3);
    void operator-=(const float);

    Vec3 operator*(const Vec3) const;
    Vec3 operator*(const float) const;
    void operator*=(const Vec3);
    void operator*=(const float);

    Vec3 operator/(const Vec3) const;
    Vec3 operator/(const float) const;
    void operator/=(const Vec3);
    void operator/=(const float);

    Vec3 operator-() const;

    // non object specific

    static float dot(const Vec3, const Vec3);
    static float distance(const Vec3, const Vec3);
    static float distanceSquared(const Vec3, const Vec3);
    static Vec3 normalize(Vec3);
    static Vec3 cross(const Vec3, const Vec3);
    static Vec3 reflect(const Vec3, const Vec3);
    static Vec3 refract(const Vec3, const Vec3, const float);
    static Vec3 abs(const Vec3);
    static Vec3 step(const Vec3, const Vec3);
    static Vec3 sign(const Vec3);
    static Vec3 min(const Vec3, const Vec3);
    static Vec3 max(const Vec3, const Vec3);
    static Vec3 lerp(const Vec3, const Vec3, const Vec3);
    static Vec3 pow(const Vec3, const Vec3);
};

// more prototypes

Vec3 operator+(const float, const Vec3);
Vec3 operator-(const float, const Vec3);
Vec3 operator*(const float, const Vec3);
Vec3 operator/(const float, const Vec3);

// ----------------------------------------

Vec3::Vec3() { x = y = z = 0.0; }
Vec3::Vec3(const float val) { x = y = z = val; }
Vec3::Vec3(const float val1, const float val2, const float val3) { x = val1; y = val2; z = val3; }
Vec3::Vec3(const Vec2 vec, const float val) { x = vec.x; y = vec.y; z = val; }
Vec3::Vec3(const float val, const Vec2 vec) { x = val; y = vec.x; z = vec.y; }

std::string Vec3::toString() {
    std::string output = "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
    return output;
}

std::string Vec3::toString(int decimals) {
    std::string output = "(" + Util::trunc(x, decimals) + ", "
        + Util::trunc(y, decimals) + ", " + Util::trunc(z, decimals) + ")";
    return output;
}

float Vec3::lengthSquared() { return x*x + y*y + z*z; }
float Vec3::length() { return std::sqrt(x*x + y*y + z*z); }

Vec3 Vec3::operator+(const Vec3 vec) const { return Vec3(x + vec.x, y + vec.y, z + vec.z); }
Vec3 Vec3::operator+(const float val) const { return Vec3(x + val, y + val, z + val); }
void Vec3::operator+=(const Vec3 vec) { x += vec.x; y += vec.y; z += vec.z; }
void Vec3::operator+=(const float val) { x += val; y += val; z += val; }

Vec3 Vec3::operator-(const Vec3 vec) const { return Vec3(x - vec.x, y - vec.y, z - vec.z); }
Vec3 Vec3::operator-(const float val) const { return Vec3(x - val, y - val, z - val); }
void Vec3::operator-=(const Vec3 vec) { x -= vec.x; y -= vec.y; z -= vec.z; }
void Vec3::operator-=(const float val) { x -= val; y -= val; z -= val; }

Vec3 Vec3::operator*(const Vec3 vec) const { return Vec3(x * vec.x, y * vec.y, z * vec.z); }
Vec3 Vec3::operator*(const float val) const { return Vec3(x * val, y * val, z * val); }
void Vec3::operator*=(const Vec3 vec) { x *= vec.x; y *= vec.y; z *= vec.z; }
void Vec3::operator*=(const float val) { x *= val; y *= val; z *= val; }

Vec3 Vec3::operator/(const Vec3 vec) const { return Vec3(x / vec.x, y / vec.y, z / vec.z); }
Vec3 Vec3::operator/(const float val) const { return Vec3(x / val, y / val, z / val); }
void Vec3::operator/=(const Vec3 vec) { x /= vec.x; y /= vec.y; z /= vec.z; }
void Vec3::operator/=(const float val) { x /= val; y /= val; z /= val; }

Vec3 Vec3::operator-() const { return Vec3(-x, -y, -z); }

// more definitions

Vec3 operator+(const float val, const Vec3 vec) { return Vec3(val + vec.x, val + vec.y, val + vec.z); }
Vec3 operator-(const float val, const Vec3 vec) { return Vec3(val - vec.x, val - vec.y, val - vec.z); }
Vec3 operator*(const float val, const Vec3 vec) { return Vec3(val * vec.x, val * vec.y, val * vec.z); }
Vec3 operator/(const float val, const Vec3 vec) { return Vec3(val / vec.x, val / vec.y, val / vec.z); }

// non object specific

float Vec3::dot(const Vec3 a, const Vec3 b) { 
    return a.x*b.x + a.y*b.y + a.z*b.z; 
}

float Vec3::distance(const Vec3 a, const Vec3 b) {
    return (a - b).length();
}

float Vec3::distanceSquared(const Vec3 a, const Vec3 b) {
    return (a - b).lengthSquared();
}

Vec3 Vec3::normalize(Vec3 vec) {
    return vec / vec.length();
}

Vec3 Vec3::cross(const Vec3 a, const Vec3 b) {
    return Vec3(
        a.y*b.z - b.y*a.z,
        a.z*b.x - b.z*a.x,
        a.x*b.y - b.x*a.y
    );
}

Vec3 Vec3::reflect(const Vec3 i, const Vec3 n) {
    return i - 2.0 * dot(i, n) * n;
}

Vec3 Vec3::refract(const Vec3 i, const Vec3 n, const float eta) {
    float d = dot(n, i);
    float k = 1.0 - eta*eta * (1.0 - d*d);

    return (k < 0.0) ? Vec3(0.0) : eta * i - (eta * d + std::sqrt(k)) * n; 
}

Vec3 Vec3::abs(const Vec3 vec) {
    return Vec3(std::abs(vec.x), std::abs(vec.y), std::abs(vec.z));
}

Vec3 Vec3::step(const Vec3 edge, const Vec3 x) {
    return Vec3(
        (x.x < edge.x) ? 0.0 : 1.0,
        (x.y < edge.y) ? 0.0 : 1.0,
        (x.z < edge.z) ? 0.0 : 1.0
    );
}

Vec3 Vec3::sign(const Vec3 vec) {
    return Vec3(
        (vec.x < 0.0) ? -1.0 : ((vec.x > 0.0) ? 1.0 : 0.0),
        (vec.y < 0.0) ? -1.0 : ((vec.y > 0.0) ? 1.0 : 0.0),
        (vec.z < 0.0) ? -1.0 : ((vec.z > 0.0) ? 1.0 : 0.0)
    );
}

Vec3 Vec3::min(const Vec3 a, const Vec3 b) {
    return Vec3(
        std::min(a.x, b.x),
        std::min(a.y, b.y),
        std::min(a.z, b.z)
    );
}

Vec3 Vec3::max(const Vec3 a, const Vec3 b) {
    return Vec3(
        std::max(a.x, b.x),
        std::max(a.y, b.y),
        std::max(a.z, b.z)
    );
}

Vec3 Vec3::lerp(const Vec3 a, const Vec3 b, const Vec3 xv) {
    Vec3 x = min(max(xv, Vec3(0.0)), Vec3(1.0));

    return a*(1.0 - x) + b*x;
}

Vec3 Vec3::pow(const Vec3 vec, const Vec3 pw) {
    return Vec3(
        std::pow(vec.x, pw.x),
        std::pow(vec.y, pw.y),
        std::pow(vec.z, pw.z)
    );
}
