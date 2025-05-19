#pragma once

#include <glm/glm.hpp>
#include <vector>
#include <memory>
#include "world/Chunk.hpp"
#include "world/WaterSimulation.hpp"
#include "world/FireSimulation.hpp"

namespace Natureal {

class WorldGenerator {
public:
    WorldGenerator();
    ~WorldGenerator();

    // Initialize the world generator
    bool initialize();

    // Generate a new world
    void generateWorld(uint64_t seed);

    // Get terrain height at specific coordinates
    float getHeightAt(float x, float z) const;

    // Get water level at specific coordinates
    float getWaterLevelAt(float x, float z) const;

    // Update world generation
    void update(const glm::vec3& playerPosition);

private:
    // Perlin noise layers
    struct NoiseLayer {
        float frequency;
        float amplitude;
        float persistence;
        float lacunarity;
    };

    std::vector<NoiseLayer> m_noiseLayers;
    uint64_t m_seed;

    // Simulation systems
    std::unique_ptr<WaterSimulation> m_waterSim;
    std::unique_ptr<FireSimulation> m_fireSim;

    // Chunk management
    std::vector<std::unique_ptr<Chunk>> m_activeChunks;
    glm::ivec3 m_currentChunk;

    // PIMPL
    class Impl;
    std::unique_ptr<Impl> m_impl;

    // Internal methods
    void generateNoiseLayers();
    float calculateNoise(float x, float z) const;
    void generateChunk(const glm::ivec3& chunkPos);
    void updateChunks(const glm::vec3& playerPosition);
};

} // namespace Natureal 