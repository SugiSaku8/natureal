# Add test executable
add_executable(NaturealTests EngineTest.cpp)

# Link test executable with main library and GTest
target_link_libraries(NaturealTests
    PRIVATE
        Natureal
        gtest
        gtest_main
)

# Add test command
add_test(NAME NaturealTests COMMAND NaturealTests)

# Set output directory
set_target_properties(NaturealTests PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
) 