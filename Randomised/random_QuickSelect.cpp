//
// Melisa Erica Soria : 14482905
//

#include <iostream>
#include "random_QuickSelect.h"

#include <vector>
#include <random>

/* Planning ... finding the median value of an array using QuickSelect
Given an array of n size (unordered) find the middle value
 median = n / 2
 when n is even .... there are two middle values so
 median = (up mid + lower mid)/2

 Teacher given: ttps://www.cs.cmu.edu/~avrim/451f11/lectures/lect0908.pdf (not really used)
 referenced: https://nh2.me/recent/Quickselect-with-median-of-medians.pdf
 https://en.wikipedia.org/wiki/Quickselect
 https://www.geeksforgeeks.org/dsa/quickselect-algorithm/
 */

// Split into lesser and greater subarray based on random p pivot
int partition(std::vector<int> & array, int left, int right, int pivot) {
 int pValue = array[pivot]; // Stores the raw value pivot pointer points to in array

 // move pivot to end of array for partitioning (right - upper boundary)
 std::swap(array[pivot],array[right]);
 int storeIndex = left;

 // Iterate and sort by moving elements < pivot value before/infront pivot
 for (int i = left; i < right; i++) {
  if (array[i] < pValue) {
   std::swap(array[i],array[storeIndex]); // current element placed before pivot
   storeIndex++;
  }
 }
 // Move pivot into its final sorted position
 std::swap(array[storeIndex],array[right]);
 return storeIndex;
}

// Finds the k-th element within left, right inclusive boundaries
// passed elements include array to search and the current boundaries (left,right) of the
int quickSelect(std::vector<int> & array,int left, int right, int k, std::mt19937& gen) {

 // Select random pivot from current array range
 std::uniform_int_distribution<int> dist(left, right);
 int pivot = dist(gen); // element pivot p

 // Partition(split) into less or more arrays based on p pivot
 pivot = partition(array, left, right, pivot);

 //STEP 3 Median time NEXT STEPS (returning med || recursion on k side)
 if (k == pivot) {
  // pivot is at k (median point) median has been found
  return array[k];
 }
 // k smallest (median) is on the left side (subarray), recurse there
 else if (k < pivot) {
  return quickSelect(array,left, pivot - 1, k, gen);
 }
 // k smallest is on the right side (subarrary), recurse there
 else {
  return quickSelect(array, pivot + 1, right, k, gen);
 }
}

// Finds median, calculating with different approached wheter array is even or Odd + (Determine inital k)
double findMedian(std::vector<int> & array) {
 // Set up random num generator (will be used for random pivot)
 std::random_device ran;
 std::mt19937 gen(ran());

 // Finds middle median (odd array)
 if (array.size() % 2 == 1) {
  int mid = array.size()/2; // Determine what k value is (median)
  return quickSelect(array,0, array.size() - 1, mid, gen);
 }
 //Finds middle median (even array)
 else{
  int up = array.size()/2; // Determine k for higher median pair
  int down = array.size()/2 - 1; // determine k for lower median pair
  int upMedian = quickSelect(array,0,array.size() - 1,up, gen); // upper median pair
  int downMedian = quickSelect(array, 0, array.size() - 1, down, gen); //lower median pair
  return (upMedian + downMedian)/2.0; // real median value for even arrays
  }
}

