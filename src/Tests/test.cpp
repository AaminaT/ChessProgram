#include "gtest/gtest.h"

#include "Messages/move_tests.hpp"
#include "Model/coordinate_tests.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
