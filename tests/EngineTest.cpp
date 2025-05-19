#include <gtest/gtest.h>
#include "core/Engine.hpp"

TEST(EngineTest, Initialization) {
    Natureal::Engine engine;
    EXPECT_TRUE(engine.initialize());
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 