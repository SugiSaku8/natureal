#include "world/WorldGenerator.hpp"
#include <glm/glm.hpp>

namespace Natureal {
WorldGenerator::WorldGenerator() {}
WorldGenerator::~WorldGenerator() {}
bool WorldGenerator::initialize() { return true; }
void WorldGenerator::update(const glm::vec3&) {}
} // namespace Natureal 