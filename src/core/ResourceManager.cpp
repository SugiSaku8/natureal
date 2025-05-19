#include "core/ResourceManager.hpp"
#include "utils/Logger.hpp"

namespace Natureal {

ResourceManager::ResourceManager() {
}

ResourceManager::~ResourceManager() {
    clear();
}

std::shared_ptr<Mesh> ResourceManager::loadMesh(const std::string& path) {
    // TODO: Implement mesh loading
    return nullptr;
}

std::shared_ptr<Texture> ResourceManager::loadTexture(const std::string& path) {
    // TODO: Implement texture loading
    return nullptr;
}

std::shared_ptr<Shader> ResourceManager::loadShader(const std::string& vertexPath, const std::string& fragmentPath) {
    // TODO: Implement shader loading
    return nullptr;
}

std::shared_ptr<Material> ResourceManager::createMaterial(const std::string& name) {
    // TODO: Implement material creation
    return nullptr;
}

std::shared_ptr<Mesh> ResourceManager::getMesh(const std::string& path) {
    auto it = m_meshes.find(path);
    if (it != m_meshes.end()) {
        return it->second;
    }
    return loadMesh(path);
}

std::shared_ptr<Texture> ResourceManager::getTexture(const std::string& path) {
    auto it = m_textures.find(path);
    if (it != m_textures.end()) {
        return it->second;
    }
    return loadTexture(path);
}

std::shared_ptr<Shader> ResourceManager::getShader(const std::string& vertexPath, const std::string& fragmentPath) {
    std::string key = vertexPath + ":" + fragmentPath;
    auto it = m_shaders.find(key);
    if (it != m_shaders.end()) {
        return it->second;
    }
    return loadShader(vertexPath, fragmentPath);
}

std::shared_ptr<Material> ResourceManager::getMaterial(const std::string& name) {
    auto it = m_materials.find(name);
    if (it != m_materials.end()) {
        return it->second;
    }
    return createMaterial(name);
}

void ResourceManager::clear() {
    m_meshes.clear();
    m_textures.clear();
    m_shaders.clear();
    m_materials.clear();
}

} // namespace Natureal 