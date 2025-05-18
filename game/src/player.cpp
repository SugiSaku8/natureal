// src/player.cpp
#include "player.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

Player::Player() : position(0.0f, 0.0f, 0.0f), 
                  velocity(0.0f), 
                  yaw(0.0f), 
                  pitch(0.0f) {}

void Player::init(GLFWwindow* window) {
    this->window = window;
    lastMouseX = 1280.0f / 2.0f;
    lastMouseY = 720.0f / 2.0f;
}

void Player::update(float deltaTime) {
    // カメラの移動
    float speed = 5.0f * deltaTime;
    
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        position += cameraFront * speed;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        position -= cameraFront * speed;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        position -= cameraRight * speed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        position += cameraRight * speed;
    
    // マウス入力による視点の変更
    double mouseX, mouseY;
    glfwGetCursorPos(window, &mouseX, &mouseY);
    
    float xOffset = float(mouseX - lastMouseX);
    float yOffset = float(lastMouseY - mouseY);
    lastMouseX = mouseX;
    lastMouseY = mouseY;
    
    float sensitivity = 0.1f;
    xOffset *= sensitivity;
    yOffset *= sensitivity;
    
    yaw += xOffset;
    pitch += yOffset;
    
    // カメラの向きの更新
    pitch = glm::clamp(pitch, -89.0f, 89.0f);
    cameraFront = glm::vec3(
        cos(glm::radians(yaw)) * cos(glm::radians(pitch)),
        sin(glm::radians(pitch)),
        sin(glm::radians(yaw)) * cos(glm::radians(pitch))
    );
    cameraRight = glm::normalize(glm::cross(cameraFront, worldUp));
}