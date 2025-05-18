// engine/src/renderer.cpp
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "renderer.h"
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
    
    if (!vShaderFile.is_open()) {
        throw std::runtime_error(std::string("頂点シェーダーファイルを開けません: ") + vertexPath);
    }
    if (!fShaderFile.is_open()) {
        throw std::runtime_error(std::string("フラグメントシェーダーファイルを開けません: ") + fragmentPath);
    }

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

    // コンパイルエラーチェック
    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        throw std::runtime_error(std::string("頂点シェーダーのコンパイルに失敗しました: ") + infoLog);
    }

    // フラグメントシェーダーのコンパイル
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
    glCompileShader(fragmentShader);

    // コンパイルエラーチェック
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        throw std::runtime_error(std::string("フラグメントシェーダーのコンパイルに失敗しました: ") + infoLog);
    }

    // シェーダープログラムの作成
    GLuint program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);

    // attribute indexのバインド
    glBindAttribLocation(program, 0, "position");
    glBindAttribLocation(program, 1, "velocity");
    glBindAttribLocation(program, 2, "color");

    glLinkProgram(program);

    // リンクエラーチェック
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        throw std::runtime_error(std::string("シェーダープログラムのリンクに失敗しました: ") + infoLog);
    }

    // シェーダーの削除
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return program;
}

void Renderer::init() {
    // シェーダーの初期化
    shaderProgram = createShaderProgram("../../shader/particle.vert", "../../shader/particle.frag");
    
    // VAOとVBOの作成
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    
    // VAOの設定
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    
    // 頂点属性の設定
    // position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Particle), (void*)offsetof(Particle, position));
    glEnableVertexAttribArray(0);
    
    // velocity
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Particle), (void*)offsetof(Particle, velocity));
    glEnableVertexAttribArray(1);
    
    // color
    glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(Particle), (void*)offsetof(Particle, color));
    glEnableVertexAttribArray(2);
    
    // バッファのバインドを解除
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Renderer::drawParticles(const std::vector<Particle>& particles) {
    if (particles.empty()) return;
    
    glUseProgram(shaderProgram);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    
    // パーティクルデータの転送
    glBufferData(GL_ARRAY_BUFFER, 
        particles.size() * sizeof(Particle), 
        particles.data(), 
        GL_STREAM_DRAW);
    
    glDrawArrays(GL_POINTS, 0, particles.size());
    
    // バッファのバインドを解除
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glUseProgram(0);
}