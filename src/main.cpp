#include <iostream>
#include <vector>

#include "Util.hpp"
#include "Mesh.hpp"
#include "Sort.hpp"

int main() {
    Mesh suzanne = Mesh("Suzanne");
    suzanne.load("/home/sam/Documents/meshes/suzanne_tri.obj");

    std::cout << suzanne.toString(Mesh::Print::FACES | Mesh::Print::STATS, 2);  

    return 0;
}
