# Add test executable
add_executable(NaturealTests
    main.cpp
)

# Link against the main library
target_link_libraries(NaturealTests
    PRIVATE
        Natureal
        gtest
        gtest_main
)

# Add tests
add_test(NAME NaturealTests COMMAND NaturealTests) 