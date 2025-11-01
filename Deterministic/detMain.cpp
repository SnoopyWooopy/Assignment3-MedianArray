// Student ID: 24749956 Houria Rauf.
#include "Determinitstic.h"
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

//findIndexSlice Tests
TEST(DeterministicTests, FindIndexSliceExists) { //tests finding a value that exists in the slice and returns the correct index.
    std::vector<int> arr = {10, 20, 30};
    EXPECT_EQ(findIndexSlice(arr, 0, 2, 20), 1);
}

TEST(DeterministicTests, FindIndexSliceNotExists) { //findIndexSlice returns -1 if the value is not in the slice.
    std::vector<int> arr = {10, 20, 30}; 
    EXPECT_EQ(findIndexSlice(arr, 0, 2, 25), -1);
}


//splitByPivot Tests

TEST(DeterministicTests, SplitByPivotBasic) { //partitions the array correctly around the pivot, smaller than pivot go left, larger go right
    std::vector<int> arr = {3, 2, 1};
    int pivotIndex = splitByPivot(arr, 0, 2, 2);
    EXPECT_EQ(arr[pivotIndex], 2);
    EXPECT_TRUE(arr[0] < 2 && arr[2] > 2);
}

TEST(DeterministicTests, SplitByPivotPivotNotInArray) { //when the pivot value is not in the array, ensure no crash and partition still works
    std::vector<int> arr = {5, 1, 4};
    int pivotIndex = splitByPivot(arr, 0, 2, 3); //3 is not ins the array
    EXPECT_EQ(arr[pivotIndex], 4); //default to last element
}

//findMedianDeterministic Tests
TEST(DeterministicTests, MedianOddLength) { // correctly find the kth smallest element
    std::vector<int> arr = {7, 2, 1, 6, 3, 5, 4};
    EXPECT_EQ(findMedianDeterministic(arr), 4); // k=3 corresponds to the 4th smallest element, which is 4
}

TEST(DeterministicTests, MedianEvenLength) { //test if it finds the lower median for an even-length array
    std::vector<int> arr = {8, 1, 2, 7};
    EXPECT_EQ(findMedianDeterministic(arr), 99);
}

TEST(DeterministicTests, MedianEmptyArray) { //throwsan exception for empty arrays
    std::vector<int> arr = {};
    EXPECT_THROW(findMedianDeterministic(arr), std::invalid_argument);
}