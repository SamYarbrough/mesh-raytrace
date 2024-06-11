#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "Util.hpp"
#include "Vec3.hpp"
#include "Triangle.hpp"
#include "BVH.hpp"
//#include "Sort.hpp"

class Mesh {
private:
    std::string name;

    //Vec3 scale, rot, pos;

    std::vector<Triangle> tris;

    Vec3 center;

    struct BVH::Hierarchy* genBVH(std::vector<Triangle> &, Vec2, Vec2);

public:
    enum Print {
        FACES = 0b0100,
        STATS = 0b1000
    };

    Mesh();
    Mesh(const std::string);
    
    // takes limited Wavefront OBJ with
    // verts, norms, faces support only
    bool load(const std::string, const bool = false);
    bool validate();

    struct BVH::Hierarchy* genBVH();

    std::string toString(int, int = 2);
};

Mesh::Mesh() {
    tris = std::vector<Triangle>();

    name = "Unnamed";
}

Mesh::Mesh(const std::string n) {
    tris = std::vector<Triangle>();

    name = n;
}

bool Mesh::load(const std::string filepath, const bool zflip) {
    std::ifstream meshf = std::ifstream(filepath, std::ios_base::in);
    if (meshf.fail()) {
        std::cerr << "\"" << filepath << "\" not found when loading to \"" << name << "\".\n";
        return false; 
    }

    bool successful_parse = true;

    std::vector<Vec3> verts = std::vector<Vec3>();
    std::vector<Vec3> norms = std::vector<Vec3>();

    for (std::string line; std::getline(meshf, line); ) {
        if (line.size() == 0) { continue; }

        std::vector<std::string> tokens = Util::split(line, " ");

        std::string l_type = tokens[0];
        bool isVert = l_type.compare("v") == 0;
        bool isNorm = l_type.compare("vn") == 0;
        bool isFace = l_type.compare("f") == 0;

        if (isVert || isNorm || isFace) {
            if (tokens.size() < 4) { // unexpected vert/norm/face line
                Util::insufTokens(filepath, line);
                successful_parse = false;
            } else {
                if (!isFace) { // is norm or vert
                    Vec3 tmp = Vec3(std::stof(tokens[1]), std::stof(tokens[2]), std::stof(tokens[3]));
                    if (isVert) {
                        verts.push_back(tmp);
                    } else {
                        norms.push_back(Vec3::normalize(tmp));
                    }
                } else { // is face
                    std::vector<Vec3> tmpv = std::vector<Vec3>();
                    std::vector<Vec3> tmpn = std::vector<Vec3>();
                    for (int i = 1; i < 4; i++) {
                        std::vector<std::string> subtok = Util::split(tokens[i], "/");
                        if (subtok.size() != 3) { // line did not contain normal indices
                            Util::insufTokens(filepath, line);
                            successful_parse = false;
                        } else {
                            tmpv.push_back(verts[(std::stoi(subtok[0])-1)%verts.size()]);
                            tmpn.push_back(verts[(std::stoi(subtok[2])-1)%norms.size()]);
                        }
                    }
                    Triangle tmp = Triangle(tmpv[0], tmpv[1], tmpv[2], tmpn[0]);
                    tris.push_back(tmp);
                }
            }
        }
    }

    return successful_parse;
}

// TODO
bool Mesh::validate() {
    return false;
}

// TODO faces
std::string Mesh::toString(int list, int decims) {
    std::string r = "Mesh: \"" + name + "\"\n";
    
    if (list & Print::STATS) {
        r += "# Tris: " + std::to_string(tris.size()) + "\n";
        r += "-\n";
    }

    if (list & Print::FACES) {
        r += "Tris: \n";
        for (int i = 0; i < tris.size(); i++) {
            r += tris[i].toString(decims);
            if (i%2 == 1) { r += "\n"; }
            else { r += "  "; }
        }
        if (tris.size()%2 ==1) { r += "\n"; }
        r += "-\n";
    }

    return r;
}

/*
if tri group < 1 tri
    set tri in bvh, return
if tri group > 1 tri
    find bounds of tri group
    find average centroid point
    if bounds wider than tall use centroid avg x coord
    else use centroid avg y coord
    split tri group based on coord
    pass each tri group to bvh, add bvh returns to current
    return
*/

struct BVH::Hierarchy* Mesh::genBVH(std::vector<Triangle>& ts, Vec2 a, Vec2 b) {
    return NULL;
}

struct BVH::Hierarchy* Mesh::genBVH() {
    return NULL;
}
