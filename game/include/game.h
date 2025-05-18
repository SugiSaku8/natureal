#ifndef GAME_H
#define GAME_H

#include <GLFW/glfw3.h>
#include "renderer.h"
#include "world_generator.h"
#include "material.h"
#include "camera.h"
#include "player.h"
#include "world.h"

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
    Game(GLFWwindow* window);
    void init();
    void update(float deltaTime);
    GLFWwindow* getWindow() const { return window; }
};

#endif // GAME_H 