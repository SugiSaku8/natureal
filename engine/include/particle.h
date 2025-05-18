// engine/include/particle.h
#ifndef PARTICLE_H
#define PARTICLE_H

#include <glm/glm.hpp>

class Particle {
public:
    glm::vec3 position;
    glm::vec3 velocity;
    float lifeTime;
    int state; // 0: solid, 1: fluid
    glm::vec4 color;

    Particle();
    void update(float deltaTime);
};

#endif // PARTICLE_H