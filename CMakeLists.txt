cmake_minimum_required(VERSION 3.10)
project(ParticleEngine)

# Homebrewのパスを設定
set(CMAKE_PREFIX_PATH 
    "/opt/homebrew"
    "/opt/homebrew/opt/glfw"
    "/opt/homebrew/lib/cmake"
)

# GLFWのパスを明示的に設定
set(GLFW_ROOT "/opt/homebrew/opt/glfw")

# 必要なパッケージの検索
find_package(GLEW REQUIRED)
find_package(glfw3 3.4 REQUIRED)
find_package(glm REQUIRED)
find_package(spdlog REQUIRED)

# エンジン部分
add_subdirectory(engine)

# ゲーム部分
add_subdirectory(game)

# インストールターゲットの追加
install(TARGETS engine particle_game
        DESTINATION bin)

install(DIRECTORY shaders/
        DESTINATION .)