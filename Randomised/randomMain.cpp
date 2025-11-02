#include <gtest/gtest.h>
#include <iostream>
#include "random_QuickSelect.h"
// To calculate the median answers to expect I used: https://www.gigacalculator.com/calculators/median-calculator.php
// Random generator used for stricter correctness tests (shuffled unordered)
std::random_device ran;
std::mt19937 gen(ran());

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

// EXTENDED TESTS: Ensures strong correctness with randomised array orders,negatives and longer arrays

// randomly sorted and long
TEST(Extended, Long) {
    std::vector<int> array = {12, 7, 9, 15, 22, 3, 18, 11, 6, 14, 8, 10, 5, 20, 17, 4, 13, 19, 16, 21, 2, 1, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50};
    std::shuffle(array.begin(),array.end(), gen);
    EXPECT_EQ(findMedian(array), 25.50);
}

TEST(Extended,Duplicate) {
    std::vector<int> array = {9, 10, 10, 10, 10, 60,321,534,3,5134,5642,12523,63542,5134,9};
    EXPECT_EQ(findMedian(array), 60);

}
// The algorithm is able to handle negative values and larger numbers
TEST(Extended, Negatives) {
    std::vector<int> array = {-53,24124,32,-432,23,23, -432, 43, 43, -45, 12,43,62,53,54, 31, 432};
    EXPECT_EQ(findMedian(array), 32);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}