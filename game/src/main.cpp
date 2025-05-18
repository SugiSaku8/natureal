// game/src/main.cpp
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "game.h"
#include "world_generator.h"
#include <iostream>

int main() {
    try {
        // GLFWの初期化
        if (!glfwInit()) {
            throw std::runtime_error("GLFWの初期化に失敗しました");
        }

        // ウィンドウの作成
        GLFWwindow* window = glfwCreateWindow(1280, 720, "Particle Engine", NULL, NULL);
        if (!window) {
            glfwTerminate();
            throw std::runtime_error("ウィンドウの作成に失敗しました");
        }

        // コンテキストの作成と設定
        glfwMakeContextCurrent(window);
        glfwSwapInterval(1); // VSyncを有効化

        // GLEWの初期化
        if (glewInit() != GLEW_OK) {
            glfwTerminate();
            throw std::runtime_error("GLEWの初期化に失敗しました");
        }

        // ゲームの初期化
        Game game(window);
        game.init();

        // レンダラーの初期化
        Renderer renderer;
        renderer.init();

        // ワールドの生成
        WorldGenerator worldGen;
        Material terrain;
        worldGen.generateWorld(terrain);

        // メインループ
        while (!glfwWindowShouldClose(game.getWindow())) {
            float deltaTime = 0.016f; // 60FPSを想定
            game.update(deltaTime);
            glfwSwapBuffers(game.getWindow());
            glfwPollEvents();
        }

        glfwTerminate();
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "エラーが発生しました: " << e.what() << std::endl;
        return 1;
    }
}