#include <gtest/gtest.h>
#include <iostream>
#include "random_QuickSelect.h"

TEST(Random, BasicTwo) {
    EXPECT_EQ(baicTest(), 2);
}

// BASIC OPERATIONS: Tests core functionality

// Handles ordered array (odd size) = middle value
TEST(BasicOperations, oddArray) {
    std::vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    EXPECT_EQ(findMedian(array), 6);
}

// Handles ordered array (even size) = (upper+lower)/2
TEST(BasicOperations, evenArray) {
    std::vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    EXPECT_EQ(findMedian(array), 5.5);
}

// Unordered and odd sized
TEST(BasicOperations, unsortedOdd) {
    std::vector<int> array = {24,5,11,1,18};
    EXPECT_EQ(findMedian(array), 11);
}

// Unordered and even sized
TEST(BasicOperations, unsortedEven) {
    std::vector<int> array = {9, 6, 2, 4};
    EXPECT_EQ(findMedian(array), 5);
}

// RANDOMISED TESTS: Ensures strong correctness



//Basic test used to track current values (TO BE DISCARED
/*
TEST(Trash, basicCheck) {
    std::vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int answer = quickSelect(array,array.size()/2);
    system("clear"); // remove when I don't want clarifications
    std::cout << "Median Value = " << answer << std::endl;
}
*/

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}