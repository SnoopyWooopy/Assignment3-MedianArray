#include <iostream>
#include "random_QuickSelect.h"

#include <vector>
#include <random>
#include <cmath> // ceil round up

/*
 Planning Random Quickselect --- To do this you must understand quicksort
 Given array of n size (randomly given? unordered) find middle value (ordered)
 median = n /2 (floor up)
https://www.cs.cmu.edu/~avrim/451f11/lectures/lect0908.pdf
In above, I inteprit k as n / 2
https://www.geeksforgeeks.org/dsa/quickselect-algorithm/
 */

//
int partition(std::vector<int> & array) {
 return 0;
}

void display (std::vector<int> & array) {
 for ( int i : array ) {
  std::cout << i << " ";
 }
}
// Finds median, calculating with different approached wheter array is even or Odd + (Determine inital k)
double findMedian(std::vector<int> & array) {
 // Set up random num generator
 std::random_device ran;
 std::mt19937 gen(ran());

 // Finds middle median (odd)
 if (array.size() % 2 == 1) {
  int k = array.size()/2;
  return quickSelect(array,k);
 }
 // Find (upper median element + lower median element) / 2
 else {
  int up = array.size()/2;
  int down = array.size()/2 - 1;
  double medianEven = avg(up,down);
  return medianEven;
 }
 return 2;
}

int baicTest() {
 return 2;
}

// Finds the k-th element (median)
int quickSelect(std::vector<int> & array,  int k) {
 
 // Pick random pivot from
 // Currently only good for inital separation
 std::uniform_int_distribution<int> dist(0,array.size() - 1);

 int pivot = dist(gen); // element pivot p
 // REMOVE LATER
 std::cout <<"Pointer: "<< pivot << " with value of " << array[pivot] << std::endl;

 // Less and more subarrays
 std::vector<int> less;
 std::vector<int> more;
 int lessCounter = 0; // Counting L elements
 // int medianPoint = ceil(array.size()/2); //median pointers (if sorted)
 int median = array.size() / 2; //basic

 //STEP 2 split array into less or more
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
 //STEP 3 Median time
 if (lessCounter == k - 1) return pivot;
 if (lessCounter > k - 1) {
  quickSelect(less,k);
 }
 else {
  quickSelect(more,k - lessCounter - 1);
 }

 // Find random pivot element
 // Split array into less and greater
 std::cout << "less values: ";
 display(less);
 std::cout << std::endl << "more values: ";
 display(more);

 return 0;
}

