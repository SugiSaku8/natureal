// engine/src/renderer.cpp
#include "renderer.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Renderer {
private:
    GLuint shaderProgram;
    GLuint vbo, vao;

public:
    void init() {
        // シェーダーの初期化
        shaderProgram = createShaderProgram("shaders/particle.vert", "shaders/particle.frag");
        
        // VAOとVBOの作成
        glGenVertexArrays(1, &vao);
        glGenBuffers(1, &vbo);
    }

    void drawParticles(const std::vector<Particle>& particles) {
        glUseProgram(shaderProgram);
        glBindVertexArray(vao);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        
        // パーティクルデータの転送
        glBufferData(GL_ARRAY_BUFFER, 
            particles.size() * sizeof(Particle), 
            particles.data(), 
            GL_STREAM_DRAW);
        
        glDrawArrays(GL_POINTS, 0, particles.size());
    }
};