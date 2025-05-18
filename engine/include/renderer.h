
// engine/include/renderer.h
#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Renderer {
private:
    GLuint shaderProgram;
    GLuint vbo, vao;

public:
    void init();
    void drawParticles(const std::vector<Particle>& particles);
};

#endif // RENDERER_H