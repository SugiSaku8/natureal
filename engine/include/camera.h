#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

class Camera {
public:
    glm::vec3 position;
    Camera();
    Camera(const glm::vec3& pos);
    void update(float deltaTime);
};

#endif // CAMERA_H 