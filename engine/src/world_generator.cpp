#include "world_generator.h"
#include <glm/glm.hpp>

void WorldGenerator::generateWorld(Material& terrain) {
    // 仮実装: 1000個のテスト粒子を生成
    for (int i = 0; i < 1000; ++i) {
        Particle p;
        p.position = glm::vec3(i % 100, 0.0f, i / 100);
        p.velocity = glm::vec3(0.0f);
        p.color = glm::vec4(1.0f);
        terrain.addParticle(p);
    }
} 