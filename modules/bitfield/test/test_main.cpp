// Copyright 2016 Baydina Olya

#include <gtest/gtest.h>


int maian(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  RUN_ALL_TESTS();
  getchar();
  return 0;
}
