#include "core/Engine.hpp"
#include "renderer/Renderer.hpp"
#include "physics/PhysicsWorld.hpp"
#include "world/WorldGenerator.hpp"
#include <chrono>

namespace Natureal {

Engine::Engine()
    : m_isRunning(false)
    , m_lastFrameTime(0.0)
    , m_deltaTime(0.0)
{
}

Engine::~Engine() {
    shutdown();
}

bool Engine::initialize(const std::string& configPath) {
    // Initialize core systems
    m_renderer = std::make_unique<Renderer>();
    m_physics = std::make_unique<PhysicsWorld>();
    m_worldGen = std::make_unique<WorldGenerator>();

    if (!m_renderer->initialize()) {
        return false;
    }

    if (!m_physics->initialize()) {
        return false;
    }

    if (!m_worldGen->initialize()) {
        return false;
    }

    m_isRunning = true;
    return true;
}

void Engine::run() {
    while (m_isRunning) {
        calculateDeltaTime();
        processInput();
        update();
        render();
    }
}

void Engine::shutdown() {
    m_isRunning = false;
    m_renderer.reset();
    m_physics.reset();
    m_worldGen.reset();
}

void Engine::processInput() {
    // TODO: Implement input processing
}

void Engine::update() {
    // Update physics
    m_physics->update(m_deltaTime);

    // Update world
    // TODO: Get player position
    glm::vec3 playerPos(0.0f);
    m_worldGen->update(playerPos);
}

void Engine::render() {
    m_renderer->beginFrame();
    // TODO: Render scene
    m_renderer->endFrame();
}

void Engine::calculateDeltaTime() {
    auto currentTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(
        currentTime.time_since_epoch()
    );
    double currentFrameTime = duration.count();
    
    m_deltaTime = currentFrameTime - m_lastFrameTime;
    m_lastFrameTime = currentFrameTime;
}

} // namespace Natureal 