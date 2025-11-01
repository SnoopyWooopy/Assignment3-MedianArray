// Student ID: 24749956 Houria Rauf.
#include "Deterministic.h"
#include <gtest/gtest.h>
#include <vector>
#include <stdexcept>

//medianSlice Tests
TEST(DeterministicTests, MedianSliceOddSize){ //to check if medianSlic correctl orders odd-length slice and returns median
    std::vector<int> arr = {5, 1, 9, 3, 7};
    EXPECT_EQ(medianSlice(arr, 0, 4), 5); // sorted {1,3,5,7,9}

}

TEST(DeterministicTests, MedianSliceEvenSize){ //to check if medianSlic correctly orders even-length slice and returns median
    std::vector<int> arr = {4, 2, 8, 6};
    EXPECT_EQ(medianSlice(arr, 0, 3), 6); // sorted {2, 4, 6, 8}, middle index = 2
}

//



