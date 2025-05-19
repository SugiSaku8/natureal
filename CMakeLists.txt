cmake_minimum_required(VERSION 3.20)
project(Natureal VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find required packages
find_package(Vulkan REQUIRED)
if(APPLE)
    # Metal is part of the system framework on macOS
    set(METAL_FOUND TRUE)
endif()

# Add subdirectories
add_subdirectory(src)
add_subdirectory(tests)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Enable testing
enable_testing()

# Set compiler flags
if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

# Set Metal specific flags for Apple platforms
if(APPLE)
    add_compile_definitions(USE_METAL)
endif() 