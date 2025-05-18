// src/game.cpp
#include "game.h"
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <glm/glm.hpp>

Game::Game(GLFWwindow* window)
    : window(window), camera(glm::vec3(0.0f, 5.0f, 5.0f)), lastFrame(0.0f), currentFrame(0.0f) {
    // 必要なら初期設定
}

void Game::init() {
    // レンダラーの初期化
    renderer.init();

    // ワールドの生成
    worldGen.generateWorld(terrain);

    // プレイヤーの初期化
    player.init(window);

    lastFrame = 0.0f;
}

void Game::update(float deltaTime) {
    currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    // 物理シミュレーションの更新
    terrain.update(deltaTime);
    
    // プレイヤーの更新
    player.update(deltaTime);
    
    // レンダリング
    renderer.drawParticles(terrain.particles);
}