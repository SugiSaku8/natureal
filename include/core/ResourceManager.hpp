#pragma once

#include <memory>
#include <string>
#include <unordered_map>

namespace Natureal {

class Mesh;
class Texture;
class Shader;
class Material;

class ResourceManager {
public:
    ResourceManager();
    ~ResourceManager();

    // Load resources
    std::shared_ptr<Mesh> loadMesh(const std::string& path);
    std::shared_ptr<Texture> loadTexture(const std::string& path);
    std::shared_ptr<Shader> loadShader(const std::string& vertexPath, const std::string& fragmentPath);
    std::shared_ptr<Material> createMaterial(const std::string& name);

    // Get resources
    std::shared_ptr<Mesh> getMesh(const std::string& path);
    std::shared_ptr<Texture> getTexture(const std::string& path);
    std::shared_ptr<Shader> getShader(const std::string& vertexPath, const std::string& fragmentPath);
    std::shared_ptr<Material> getMaterial(const std::string& name);

    // Clear resources
    void clear();

private:
    // Resource caches
    std::unordered_map<std::string, std::shared_ptr<Mesh>> m_meshes;
    std::unordered_map<std::string, std::shared_ptr<Texture>> m_textures;
    std::unordered_map<std::string, std::shared_ptr<Shader>> m_shaders;
    std::unordered_map<std::string, std::shared_ptr<Material>> m_materials;
};

} // namespace Natureal 