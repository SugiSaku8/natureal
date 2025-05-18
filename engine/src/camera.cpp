#include "camera.h"
#include <glm/glm.hpp>

Camera::Camera() : position(0.0f) {}
Camera::Camera(const glm::vec3& pos) : position(pos) {}

void Camera::update(float deltaTime) {
    // カメラの更新処理（必要に応じて実装）
} 