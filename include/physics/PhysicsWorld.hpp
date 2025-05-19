#pragma once

#include <glm/glm.hpp>
#include <memory>
#include <vector>

namespace Natureal {

class RigidBody;
class Collider;
class Constraint;

class PhysicsWorld {
public:
    PhysicsWorld();
    ~PhysicsWorld();

    // Initialize the physics world
    bool initialize();

    // Update physics simulation
    void update(float deltaTime);

    // Add/Remove objects
    void addRigidBody(std::shared_ptr<RigidBody> body);
    void removeRigidBody(std::shared_ptr<RigidBody> body);
    void addConstraint(std::shared_ptr<Constraint> constraint);
    void removeConstraint(std::shared_ptr<Constraint> constraint);

    // Set gravity
    void setGravity(const glm::vec3& gravity);

    // Ray casting
    struct RaycastResult {
        bool hit;
        glm::vec3 point;
        glm::vec3 normal;
        float distance;
        std::shared_ptr<RigidBody> body;
    };
    RaycastResult raycast(const glm::vec3& origin, const glm::vec3& direction, float maxDistance);

private:
    // Physics engine implementation
    class Impl;
    std::unique_ptr<Impl> m_impl;

    // World settings
    glm::vec3 m_gravity;
    float m_timeStep;
    int m_maxIterations;

    // Object collections
    std::vector<std::shared_ptr<RigidBody>> m_bodies;
    std::vector<std::shared_ptr<Constraint>> m_constraints;

    // Internal methods
    void detectCollisions();
    void resolveCollisions();
    void updateConstraints();
    void integrateForces(float deltaTime);
};

} // namespace Natureal 