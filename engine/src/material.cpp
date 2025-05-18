// engine/src/material.cpp
#include "material.h"
#include <vector>

class Material {
public:
    std::vector<Particle> particles;
    glm::vec3 bounds;
    int materialType;
    std::string atomicStructure;

    void addParticle(const Particle& particle) {
        particles.push_back(particle);
    }

    void update(float deltaTime) {
        for (auto& particle : particles) {
            particle.update(deltaTime);
        }
    }
};