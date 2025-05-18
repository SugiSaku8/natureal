#ifndef PLAYER_H
#define PLAYER_H

#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

class Player {
public:
    glm::vec3 position;
    glm::vec3 velocity;
    float yaw, pitch;
    GLFWwindow* window;
    float lastMouseX, lastMouseY;

    Player();
    void init(GLFWwindow* window);
    void update(float deltaTime);
};

#endif // PLAYER_H 