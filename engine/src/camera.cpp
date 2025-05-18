#include "camera.h"
#include <glm/glm.hpp>

Camera::Camera() : position(0.0f) {}
Camera::Camera(const glm::vec3& pos) : position(pos) {}

Camera::Camera(const glm::vec3& position) {
    // 必要に応じて position をメンバ変数に格納
    // 例: this->position = position;
}

void Camera::update(float deltaTime) {
    // 実装例: カメラの移動や回転処理
} 