// engine/src/particle.cpp
#include "particle.h"
#include <glm/glm.hpp>

Particle::Particle() : position(0.0f), velocity(0.0f), color(1.0f) {}

void Particle::update(float deltaTime) {
    position += velocity * deltaTime;
}