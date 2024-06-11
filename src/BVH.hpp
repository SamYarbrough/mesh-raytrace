#pragma once

#include "Vec3.hpp"

namespace BVH {
    struct Hierarchy {
        int tri;

        Vec3 box_a;
        Vec3 box_b;

        struct Hierarchy *left;
        struct Hierarchy *right;
    };

    struct Hierarchy* newBVH(int, Vec3, Vec3);

    void deleteBVH(Hierarchy &);
};

struct BVH::Hierarchy* BVH::newBVH(int t, Vec3 ba, Vec3 bb) {
    struct BVH::Hierarchy* node = new struct Hierarchy;

    node->tri = t;
    node->box_a = ba;
    node->box_b = bb;

    node->left = NULL;
    node->right = NULL;

    return node;
} 

void BVH::deleteBVH(BVH::Hierarchy n) {
    
}
