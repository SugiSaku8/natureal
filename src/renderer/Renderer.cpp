#include "renderer/Renderer.hpp"
#include <memory>

namespace Natureal {
Renderer::Renderer() {}
Renderer::~Renderer() {}
bool Renderer::initialize() { return true; }
void Renderer::beginFrame() {}
void Renderer::endFrame() {}
void Renderer::renderMesh(const Mesh&, const Material&, const glm::mat4&) {}
void Renderer::setViewMatrix(const glm::mat4&) {}
void Renderer::setProjectionMatrix(const glm::mat4&) {}
std::shared_ptr<Shader> Renderer::loadShader(const std::string&, const std::string&) { return nullptr; }
std::shared_ptr<Texture> Renderer::loadTexture(const std::string&) { return nullptr; }
std::shared_ptr<Material> Renderer::createMaterial(const std::string&) { return nullptr; }
void Renderer::initializeGraphicsAPI() {}
void Renderer::createDefaultResources() {}
void Renderer::setupRenderPass() {}
} // namespace Natureal 