// Student ID: 24749956 Houria Rauf.
#include "Deterministic.h"
#include <gtest/gtest.h>
#include <vector>
#include <stdexcept>

//medianSlice Tests
TEST(findDeterministicTests, MedianSliceOddSize){ //to check if medianSlic correctl orders odd-length slice and returns median
    std::vector<int> arr = {5, 1, 9, 3, 7};
    EXPECT_EQ(medianSlice(arr, 0, 4), 5); // sorted {1,3,5,7,9}

}




