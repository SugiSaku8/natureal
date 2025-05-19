#include "physics/PhysicsWorld.hpp"
#include <memory>

namespace Natureal {
class PhysicsWorld::Impl {};
PhysicsWorld::PhysicsWorld() : m_impl(std::make_unique<Impl>()) {}
PhysicsWorld::~PhysicsWorld() = default;
bool PhysicsWorld::initialize() { return true; }
void PhysicsWorld::update(float) {}
void PhysicsWorld::addRigidBody(std::shared_ptr<RigidBody>) {}
void PhysicsWorld::removeRigidBody(std::shared_ptr<RigidBody>) {}
void PhysicsWorld::addConstraint(std::shared_ptr<Constraint>) {}
void PhysicsWorld::removeConstraint(std::shared_ptr<Constraint>) {}
void PhysicsWorld::setGravity(const glm::vec3&) {}
PhysicsWorld::RaycastResult PhysicsWorld::raycast(const glm::vec3&, const glm::vec3&, float) { return {}; }
void PhysicsWorld::detectCollisions() {}
void PhysicsWorld::resolveCollisions() {}
void PhysicsWorld::updateConstraints() {}
void PhysicsWorld::integrateForces(float) {}
} // namespace Natureal 