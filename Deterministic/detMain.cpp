// Student ID: 24749956 Houria Rauf.
#include <gtest/gtest.h>
#include "../Deterministic/Determinitstic.h"
#include <vector>
#include <iostream>

//testing the median slice
TEST(DeterministicTests, MedianSliceBasic) { //does it correctly sort and return the correct median element
    std::vector<int> arr = {5, 1, 9, 3, 7}; //make an array
    int result = medianSlice(arr, 0, 4);
    EXPECT_EQ(result, 5); // median of sorted {1,3,5,7,9}
}