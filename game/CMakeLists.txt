# game/CMakeLists.txt
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH 
    "/opt/homebrew"
    "/opt/homebrew/opt/glfw"
    "/opt/homebrew/lib/cmake"
)
# ゲーム実行ファイルの作成
add_executable(particle_game
    src/main.cpp
    src/game.cpp
    src/player.cpp
    src/world.cpp
)

# インクルードディレクトリの設定
target_include_directories(particle_game
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/engine/include
)

# エンジンライブラリの依存関係を追加
target_link_libraries(particle_game
    PRIVATE
        engine
        glfw
        GLEW::GLEW
        glm::glm
        spdlog::spdlog
)

# インストールターゲットの追加
install(TARGETS particle_game
        DESTINATION bin)