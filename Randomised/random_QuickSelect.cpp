#include <iostream>
#include "random_QuickSelect.h"

#include <vector>
#include <random>
 // #include <cmath> // ceil round up nah

/*
 Planning Random Quickselect --- To do this you must understand quicksort
 Given array of n size (randomly given? unordered) find middle value (ordered)
 median = n /2 (floor up)
https://www.cs.cmu.edu/~avrim/451f11/lectures/lect0908.pdf
In above, I inteprit k as n / 2
https://www.geeksforgeeks.org/dsa/quickselect-algorithm/
 */

//

void display (std::vector<int> & array) {
 for ( int i : array ) {
  std::cout << i << " ";
 }
}
// Split into lesser and greater subarray based on p pivot
int partition(std::vector<int> & array, int left, int right, int pivot) {
 int pValue = array[pivot]; // Stores the raw value pivot pointer points to in array
 int lessCounter = 0;

 // move pivot to end of array for partitioning (right - upper boundary)
 std::swap(array[pivot],array[right]);

 // Iterate and sort by moving elements < pivot value before/infront pivot
 for (int i = left; i < right; i++) {
  if (array[i] < pValue) {
   std::swap(array[i],array[right]); // current element placed before pivot
   lessCounter++;
  }
 }
 // Move pivot into its final sorted position
 std::swap(array[lessCounter],array[right]);
 return lessCounter;

 //

 // OLD SOLUTION : Pesudo code poor interpritatoin
 /* //STEP 2 split array into less or more
 for ( int i = 0; i < array.size(); i++ ) {
  if (array[i] == array[pivot]) continue;
  if (array[i] < array[pivot]){
   lessCounter++;
   less.push_back(array[i]);
  }
  else {
   more.push_back(array[i]);
  }
 }
 */
}


// Finds the k-th element within left, right inclusive boundaries
int quickSelect(std::vector<int> & array,int left, int right, int k, mt19937& gen) {

 // Select random pivot from
 // Currently only good for inital separation with left right ating as boundaried
 // Initally std::uniform_int_distribution<int> dist(0,array.size() - 1);
 std::uniform_int_distribution<int> dist(left, right);
 int pivot = dist(gen); // element pivot p

 // REMOVE LATER
 // std::cout <<"Pointer: "<< pivot << " with value of " << array[pivot] << std::endl;

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

 // Find random pivot element
 // Split array into less and greater
 std::cout << "less values: ";
 display(less);
 std::cout << std::endl << "more values: ";
 display(more);

 return 0;
}

// Finds median, calculating with different approached wheter array is even or Odd + (Determine inital k)
double findMedian(std::vector<int> & array) {
 // Set up random num generator
 std::random_device ran;
 std::mt19937 gen(ran());

 // Finds middle median (odd)
 if (array.size() % 2 == 1) {
  int mid = array.size()/2;
  return quickSelect(array,0, array.size() - 1, mid), gen;
 }
 else{
  int up = array.size()/2;
  int down = array.size()/2 - 1;
  int upmedian = quickSelect(array,0,array.size() - 1,up, gen);
  int downMedian = quickSelect(array, 0, array.size() - 1, down, gen);
  return (upmedian + downMedian)/2; // real median value for odd
  }
}

int baicTest() {
 return 2;
}

