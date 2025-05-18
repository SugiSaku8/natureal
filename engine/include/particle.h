// engine/include/particle.h
#ifndef PARTICLE_H
#define PARTICLE_H

#include <glm/glm.hpp>

class Particle {
public:
    glm::vec3 position;
    glm::vec3 velocity;
    glm::vec4 color;

    Particle();
    void update(float deltaTime);
};

#endif // PARTICLE_H