#pragma once

#include <string>
#include <stdint.h>

#include "Vec3.hpp"

class Triangle {
public:
    enum Sort { 
        X,
        Y,
        Z
    };
    static Sort sort_by;

    Vec3 v1, v2, v3, norm, centroid;

    Triangle(Vec3, Vec3, Vec3, Vec3);

    bool operator<(const Triangle) const;
    bool operator>(const Triangle) const;

    static void sortBy(const Sort);

    std::string toString(const int);
};

Triangle::Sort Triangle::sort_by = Triangle::Sort::X;

Triangle::Triangle(Vec3 w1, Vec3 w2, Vec3 w3, Vec3 n) {
    v1 = w1; v2 = w2; v3 = w3;
    norm = n;
    centroid = (v1 + v2 + v3) / 3.0;
}

bool Triangle::operator<(const Triangle t) const {
    switch (sort_by) {
        case Sort::X:
            return centroid.x < t.centroid.x;
            break;
        case Sort::Y:
            return centroid.y < t.centroid.y;
            break;
        case Sort::Z:
            return centroid.z < t.centroid.z;
            break;
        default:
            std::cerr << "Unknown sorting scheme.\n";
    }
}

bool Triangle::operator>(const Triangle t) const {
    switch (sort_by) {
        case Sort::X:
            return centroid.x > t.centroid.x;
            break;
        case Sort::Y:
            return centroid.y > t.centroid.y;
            break;
        case Sort::Z:
            return centroid.z > t.centroid.z;
            break;
        default:
            std::cerr << "Unknown sorting scheme.\n";
    }
}

void Triangle::sortBy(const Sort s) {
    sort_by = s;
}

std::string Triangle::toString(const int decimals) {
    std::string output = "V: " + v1.toString(decimals)
        + ", " + v1.toString(decimals) + ", " + v1.toString(decimals) + "  ";
    output += "N: " + norm.toString(decimals);

    return output;
}
