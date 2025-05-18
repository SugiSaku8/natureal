// src/world.cpp
#include "world.h"
#include <random>
#include <glm/glm.hpp>

World::World() : generator(42) {
    // ノイズパラメータの初期化
    octaves = 15;
    persistence = 0.5f;
    lacunarity = 2.0f;
    scale = 50.0f;
}

void World::generateTerrain(Material& terrain) {
    // グリッドサイズの設定
    const int gridSize = 256;
    const float cellSize = 1.0f;
    
    // ランダムな高さの生成
    std::vector<float> heights;
    heights.resize(gridSize * gridSize);
    
    for (int z = 0; z < gridSize; z++) {
        for (int x = 0; x < gridSize; x++) {
            float height = 0.0f;
            float frequency = 1.0f;
            float amplitude = 1.0f;
            
            // 15層のPerlinノイズを重ね合わせる
            for (int i = 0; i < octaves; i++) {
                height += getPerlinNoise(x * frequency * scale, 0.0f, z * frequency * scale) * amplitude;
                frequency *= lacunarity;
                amplitude *= persistence;
            }
            
            heights[z * gridSize + x] = height;
        }
    }
    
    // 粒子の生成
    for (int z = 0; z < gridSize; z++) {
        for (int x = 0; x < gridSize; x++) {
            float height = heights[z * gridSize + x];
            
            // 地形の粒子を生成
            for (float y = 0.0f; y < height; y += 0.5f) {
                Particle particle;
                particle.position = glm::vec3(x, y, z);
                particle.state = 0; // 固体
                terrain.addParticle(particle);
            }
        }
    }
}

float World::getPerlinNoise(float x, float y, float z) {
    // 3次元Perlinノイズの実装
    int X = int(floor(x)) & 255;
    int Y = int(floor(y)) & 255;
    int Z = int(floor(z)) & 255;
    
    x -= floor(x);
    y -= floor(y);
    z -= floor(z);
    
    float u = fade(x);
    float v = fade(y);
    float w = fade(z);
    
    int A = perm[X] + Y, B = perm[X + 1] + Y;
    return lerp(w, lerp(v, lerp(u, grad(perm[A], x, y, z),
                                 grad(perm[B], x - 1, y, z)),
                         lerp(u, grad(perm[A + 1], x, y - 1, z),
                                 grad(perm[B + 1], x - 1, y - 1, z))),
                 lerp(v, lerp(u, grad(perm[A + 256], x, y, z - 1),
                                 grad(perm[B + 256], x - 1, y, z - 1)),
                         lerp(u, grad(perm[A + 1 + 256], x, y - 1, z - 1),
                                 grad(perm[B + 1 + 256], x - 1, y - 1, z - 1))));
}