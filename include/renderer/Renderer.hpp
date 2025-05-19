#pragma once

#include <glm/glm.hpp>
#include <memory>
#include <vector>
#include <string>

namespace Natureal {

class Shader;
class Mesh;
class Texture;
class Material;

class Renderer {
public:
    Renderer();
    ~Renderer();

    // Initialize the renderer
    bool initialize();

    // Begin/End frame
    void beginFrame();
    void endFrame();

    // Render a mesh
    void renderMesh(const Mesh& mesh, const Material& material, const glm::mat4& transform);

    // Set view and projection matrices
    void setViewMatrix(const glm::mat4& view);
    void setProjectionMatrix(const glm::mat4& projection);

    // Load resources
    std::shared_ptr<Shader> loadShader(const std::string& vertexPath, const std::string& fragmentPath);
    std::shared_ptr<Texture> loadTexture(const std::string& path);
    std::shared_ptr<Material> createMaterial(const std::string& name);

private:
    // Graphics API specific implementations
    class Impl;
    std::unique_ptr<Impl> m_impl;

    // Current state
    glm::mat4 m_viewMatrix;
    glm::mat4 m_projectionMatrix;

    // Resource management
    std::vector<std::shared_ptr<Shader>> m_shaders;
    std::vector<std::shared_ptr<Texture>> m_textures;
    std::vector<std::shared_ptr<Material>> m_materials;

    // Internal methods
    void initializeGraphicsAPI();
    void createDefaultResources();
    void setupRenderPass();
};

} // namespace Natureal 