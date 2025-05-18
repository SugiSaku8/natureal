#include "camera.h"

Camera::Camera() : position(0.0f) {}
Camera::Camera(const glm::vec3& pos) : position(pos) {}

void Camera::update(float deltaTime) {
    // 実装例: カメラの移動や回転処理
} 