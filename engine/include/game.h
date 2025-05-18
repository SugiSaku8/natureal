// game/include/game.h
#ifndef GAME_H
#define GAME_H

#include "renderer.h"
#include "world_generator.h"
#include "material.h"
#include "camera.h"
#include "player.h"
#include "world.h"
#include <GLFW/glfw3.h>

class Game {
private:
    GLFWwindow* window;
    Renderer renderer;
    WorldGenerator worldGen;
    Material terrain;
    Camera camera;
    Player player;
    World world;
    float lastFrame, currentFrame;

public:
    Game();
    void init();
    void update(float deltaTime);
    GLFWwindow* getWindow() const { return window; }
};

#endif // GAME_H