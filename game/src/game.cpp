// src/game.cpp
#include "game.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

Game::Game() : camera(glm::vec3(0.0f, 5.0f, 5.0f)) {
    // 初期設定
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    lastFrame = 0.0f;
}

void Game::init() {
    // GLFWの初期化
    if (!glfwInit()) {
        throw std::runtime_error("GLFWの初期化に失敗しました");
    }

    // ウィンドウの作成
    window = glfwCreateWindow(1280, 720, "Particle Engine", NULL, NULL);
    if (!window) {
        glfwTerminate();
        throw std::runtime_error("ウィンドウの作成に失敗しました");
    }

    // コンテキストの作成と設定
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // VSyncを有効化

    // レンダラーの初期化
    renderer.init();

    // ワールドの生成
    worldGen.generateWorld(terrain);

    // プレイヤーの初期化
    player.init(window);
}

void Game::update(float deltaTime) {
    // 物理シミュレーションの更新
    terrain.update(deltaTime);
    
    // プレイヤーの更新
    player.update(deltaTime);
    
    // レンダリング
    renderer.drawParticles(terrain.particles);
    
    // フレームレートの制御
    currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
}