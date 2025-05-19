# Add test executable
add_executable(NaturealTests
    EngineTest.cpp
)

# Link test executable with main library
target_link_libraries(NaturealTests
    PRIVATE
        Natureal
        gtest
        gtest_main
)

# Add tests
add_test(NAME NaturealTests COMMAND NaturealTests) 