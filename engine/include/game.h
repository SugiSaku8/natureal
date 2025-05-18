// game/include/game.h
#ifndef GAME_H
#define GAME_H

#include "renderer.h"
#include "world_generator.h"
#include "material.h"
#include "camera.h"
#include "player.h"
#include <GLFW/glfw3.h>

class Game {
private:
    Renderer renderer;
    WorldGenerator worldGen;
    Material terrain;
    Camera camera;
    Player player;

public:
    void init();
    void update(float deltaTime);
};

#endif // GAME_H