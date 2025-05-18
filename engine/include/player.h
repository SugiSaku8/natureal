#ifndef PLAYER_H
#define PLAYER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Player {
public:
    glm::vec3 position;
    glm::vec3 velocity;
    float yaw, pitch;
    GLFWwindow* window;
    float lastMouseX, lastMouseY;
    glm::vec3 cameraFront;
    glm::vec3 cameraRight;
    glm::vec3 worldUp;

    Player();
    void init(GLFWwindow* window);
    void update(float deltaTime);
};

#endif // PLAYER_H 