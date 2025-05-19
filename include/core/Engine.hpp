#pragma once

#include <memory>
#include <string>
#include <vector>

namespace Natureal {

class Renderer;
class PhysicsWorld;
class WorldGenerator;
class ResourceManager;

class Engine {
public:
    Engine();
    ~Engine();

    // Initialize the engine
    bool initialize(const std::string& configPath = "");

    // Main game loop
    void run();

    // Shutdown and cleanup
    void shutdown();

private:
    // Core systems
    std::unique_ptr<Renderer> m_renderer;
    std::unique_ptr<PhysicsWorld> m_physics;
    std::unique_ptr<WorldGenerator> m_worldGen;
    std::unique_ptr<ResourceManager> m_resources;

    // Engine state
    bool m_isRunning;
    double m_lastFrameTime;
    double m_deltaTime;

    // Internal methods
    void processInput();
    void update();
    void render();
    void calculateDeltaTime();
};

} // namespace Natureal 