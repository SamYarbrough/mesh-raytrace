#pragma once

#include <string>

#include "Vec3.hpp"

class Ray3 {
public:
    Vec3 org, dir;

    float dist = 1e30f;

    Ray3();
    Ray3(const Vec3, const Vec3);

    std::string toString();

    Vec3 endpoint();
    bool setCloser(const float);
    void normalize();
};

Ray3::Ray3() {
    org = Vec3(0);
    dir = Vec3(1, 0, 0);
}

Ray3::Ray3(const Vec3 o, const Vec3 d) {
    org = o;
    dir = d;
}

std::string Ray3::toString() {
    std::string output = "Ray at " + org.toString() + " headed " + dir.toString() + ", distance " + std::to_string(dist);
    return output;
}

Vec3 Ray3::endpoint() {
    return org + dist * dir;
}

bool Ray3::setCloser(const float d) {
    if (d >= dist) return false;

    dist = d;
    return true;
}

void Ray3::normalize() {
    dir = Vec3::normalize(dir);
}