// game/src/main.cpp
#include "game.h"
#include "world_generator.h"
#include <GLFW/glfw3.h>

class Game {
private:
    Renderer renderer;
    WorldGenerator worldGen;
    Material terrain;
    Camera camera;
    Player player;

public:
    void init() {
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
        renderer.init();

        // ワールドの生成
        worldGen.generateWorld(terrain);
    }

    void update(float deltaTime) {
        // 物理シミュレーションの更新
        terrain.update(deltaTime);
        
        // プレイヤーの更新
        player.update(deltaTime);
        
        // レンダリング
        renderer.drawParticles(terrain.particles);
    }
};