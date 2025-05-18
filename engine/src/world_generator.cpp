#include "world_generator.h"
#include <glm/glm.hpp>

void WorldGenerator::generateWorld(Material& terrain) {
    // 簡単なテスト用のパーティクルを生成
    for (int i = 0; i < 1000; ++i) {
        Particle particle;
        particle.position = glm::vec3(
            (rand() % 1000) / 100.0f - 5.0f,
            (rand() % 1000) / 100.0f - 5.0f,
            (rand() % 1000) / 100.0f - 5.0f
        );
        particle.velocity = glm::vec3(0.0f);
        particle.lifeTime = 1.0f;
        particle.state = 0;
        particle.color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        terrain.addParticle(particle);
    }
} 