// game/src/main.cpp
#include "game.h"
#include "world_generator.h"
#include <GLFW/glfw3.h>
#include <iostream>

int main() {
    try {
        Game game;
        game.init();

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