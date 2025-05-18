// engine/src/renderer.cpp
#include "renderer.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <fstream>
#include <sstream>
#include <iostream>

GLuint Renderer::createShaderProgram(const char* vertexPath, const char* fragmentPath) {
    // シェーダーファイルの読み込み
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;

    vShaderFile.open(vertexPath);
    fShaderFile.open(fragmentPath);
    std::stringstream vShaderStream, fShaderStream;
    vShaderStream << vShaderFile.rdbuf();
    fShaderStream << fShaderFile.rdbuf();
    vShaderFile.close();
    fShaderFile.close();
    vertexCode = vShaderStream.str();
    fragmentCode = fShaderStream.str();

    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();

    // 頂点シェーダーのコンパイル
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vShaderCode, NULL);
    glCompileShader(vertexShader);

    // フラグメントシェーダーのコンパイル
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
    glCompileShader(fragmentShader);

    // シェーダープログラムの作成
    GLuint program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    // シェーダーの削除
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return program;
}

void Renderer::init() {
    // シェーダーの初期化
    shaderProgram = createShaderProgram("shaders/particle.vert", "shaders/particle.frag");
    
    // VAOとVBOの作成
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
}

void Renderer::drawParticles(const std::vector<Particle>& particles) {
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