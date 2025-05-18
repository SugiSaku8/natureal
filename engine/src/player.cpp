#include "player.h"

Player::Player() : position(0.0f), velocity(0.0f), yaw(0.0f), pitch(0.0f), window(nullptr), lastMouseX(0.0f), lastMouseY(0.0f) {}

void Player::init(GLFWwindow* window) {
    this->window = window;
    lastMouseX = 1280.0f / 2.0f;
    lastMouseY = 720.0f / 2.0f;
}

void Player::update(float deltaTime) {
    // 実装例: 入力処理や移動処理をここに記述
} 