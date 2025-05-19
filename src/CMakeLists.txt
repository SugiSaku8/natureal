# Add source files
set(SOURCES
    core/Engine.cpp
    renderer/Renderer.cpp
    physics/PhysicsWorld.cpp
    world/WorldGenerator.cpp
    utils/Logger.cpp
)

# Create the main library
add_library(Natureal ${SOURCES})

# Set include directories
target_include_directories(Natureal
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# Link dependencies
target_link_libraries(Natureal
    PUBLIC
        glm
        Vulkan::Vulkan
    PRIVATE
        ${CMAKE_DL_LIBS}
)

# Add Metal support for Apple platforms
if(APPLE)
    target_link_libraries(Natureal
        PRIVATE
            "-framework Metal"
            "-framework MetalKit"
            "-framework Cocoa"
    )
endif() 