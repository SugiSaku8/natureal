#include "material.h"
#include <vector>

void Material::addParticle(const Particle& particle) {
    particles.push_back(particle);
}

void Material::update(float deltaTime) {
    for (auto& particle : particles) {
        particle.update(deltaTime);
    }
} 