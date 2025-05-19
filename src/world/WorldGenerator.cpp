#include "world/WorldGenerator.hpp"
#include <glm/glm.hpp>
#include <memory>

namespace Natureal {
class Chunk {};
class WaterSimulation {};
class FireSimulation {};
class WorldGenerator::Impl {};
WorldGenerator::WorldGenerator() : m_impl(std::make_unique<Impl>()) {}
WorldGenerator::~WorldGenerator() = default;
bool WorldGenerator::initialize() { return true; }
void WorldGenerator::generateWorld(uint64_t) {}
float WorldGenerator::getHeightAt(float, float) const { return 0.0f; }
float WorldGenerator::getWaterLevelAt(float, float) const { return 0.0f; }
void WorldGenerator::update(const glm::vec3&) {}
void WorldGenerator::generateNoiseLayers() {}
float WorldGenerator::calculateNoise(float, float) const { return 0.0f; }
void WorldGenerator::generateChunk(const glm::ivec3&) {}
void WorldGenerator::updateChunks(const glm::vec3&) {}
} // namespace Natureal 