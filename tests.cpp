#include <iostream>
#include <gtest/gtest.h>
#include "Stack.h"

TEST(StackTest, PushAndPop) {
  Stack<int> stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);

  EXPECT_EQ(stack.pop(), 3);
  EXPECT_EQ(stack.pop(), 2);
  EXPECT_EQ(stack.pop(), 1);
}

TEST(StackTest, Top) {
  Stack<int> stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);

  EXPECT_EQ(stack.top(), 3);
}

TEST(StackTest, empty) {
  Stack<int> stack;

  EXPECT_TRUE(stack.empty());

  stack.push(1);

  EXPECT_FALSE(stack.empty());
}

// Add more test cases for other methods...

/*
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
*/
