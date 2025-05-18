
// engine/include/material.h
#ifndef MATERIAL_H
#define MATERIAL_H

#include <vector>
#include "particle.h"

class Material {
public:
    std::vector<Particle> particles;
    glm::vec3 bounds;
    int materialType;
    std::string atomicStructure;

    void addParticle(const Particle& particle);
    void update(float deltaTime);
};

#endif // MATERIAL_H
