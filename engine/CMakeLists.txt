# engine/CMakeLists.txt
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH 
    "/opt/homebrew"
    "/opt/homebrew/opt/glfw"
    "/opt/homebrew/lib/cmake"
)
# エンジンライブラリの作成
add_library(engine STATIC
    include/particle.h
    include/material.h
    include/renderer.h
    include/game.h
    src/particle.cpp
    src/material.cpp
    src/renderer.cpp
)

# インクルードディレクトリの設定
target_include_directories(engine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# 依存関係の追加
target_link_libraries(engine
    PRIVATE
        glfw
        GLEW::GLEW
        glm::glm
        spdlog::spdlog
)

# インストールターゲットの追加
install(TARGETS engine
        DESTINATION lib)

install(DIRECTORY include/
        DESTINATION include/ParticleEngine)