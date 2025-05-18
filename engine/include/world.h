#ifndef WORLD_H
#define WORLD_H

#include "material.h"
#include "particle.h"
#include <random>
#include <glm/glm.hpp>

class World {
private:
    std::mt19937 generator;
    int octaves;
    float persistence;
    float lacunarity;
    float scale;

    float getPerlinNoise(float x, float y, float z);
    float fade(float t);
    float grad(int hash, float x, float y, float z);

public:
    World();
    void generateTerrain(Material& terrain);
    void update(float deltaTime);
};

#endif // WORLD_H 