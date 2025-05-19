#include "world/WorldGenerator.hpp"
#include <random>
#include <cmath>

namespace Natureal {

class WorldGenerator::Impl {
public:
    Impl() = default;
    ~Impl() = default;

    bool initialize() {
        return true;
    }

    float calculateNoise(float x, float z, const std::vector<NoiseLayer>& layers) {
        float total = 0.0f;
        float amplitude = 1.0f;
        float frequency = 1.0f;
        float maxValue = 0.0f;

        for (const auto& layer : layers) {
            total += amplitude * std::sin(x * frequency + z * frequency);
            maxValue += amplitude;
            amplitude *= layer.persistence;
            frequency *= layer.lacunarity;
        }

        return total / maxValue;
    }
};

WorldGenerator::WorldGenerator()
    : m_impl(std::make_unique<Impl>())
    , m_seed(0)
{
}

WorldGenerator::~WorldGenerator() = default;

bool WorldGenerator::initialize() {
    return m_impl->initialize();
}

void WorldGenerator::generateWorld(uint64_t seed) {
    m_seed = seed;
    generateNoiseLayers();
}

float WorldGenerator::getHeightAt(float x, float z) const {
    return m_impl->calculateNoise(x, z, m_noiseLayers);
}

float WorldGenerator::getWaterLevelAt(float x, float z) const {
    // TODO: Implement water level calculation
    return 0.0f;
}

void WorldGenerator::update(const glm::vec3& playerPosition) {
    // Update active chunks based on player position
    glm::ivec3 newChunk(
        static_cast<int>(std::floor(playerPosition.x / 16.0f)),
        static_cast<int>(std::floor(playerPosition.y / 16.0f)),
        static_cast<int>(std::floor(playerPosition.z / 16.0f))
    );

    if (newChunk != m_currentChunk) {
        m_currentChunk = newChunk;
        updateChunks(playerPosition);
    }
}

void WorldGenerator::generateNoiseLayers() {
    m_noiseLayers.clear();
    
    // Create 15 layers of noise with different parameters
    for (int i = 0; i < 15; ++i) {
        NoiseLayer layer;
        layer.frequency = 0.01f * std::pow(2.0f, i);
        layer.amplitude = 1.0f / std::pow(2.0f, i);
        layer.persistence = 0.5f;
        layer.lacunarity = 2.0f;
        m_noiseLayers.push_back(layer);
    }
}

float WorldGenerator::calculateNoise(float x, float z) const {
    return m_impl->calculateNoise(x, z, m_noiseLayers);
}

void WorldGenerator::generateChunk(const glm::ivec3& chunkPos) {
    // TODO: Implement chunk generation
}

void WorldGenerator::updateChunks(const glm::vec3& playerPosition) {
    // TODO: Implement chunk updates
}

} // namespace Natureal 