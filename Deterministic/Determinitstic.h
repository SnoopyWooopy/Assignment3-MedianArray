//
// Student ID: 24749956 Houria Rauf.
//

#ifndef ASSIGNMENT3_DETERMINITSTIC_H
#define ASSIGNMENT3_DETERMINITSTIC_H

#include <vector>
#include <stdexcept>

int medianSlice(std::vector<int>& a, int l, int r);
int findIndexSlice(const std::vector<int>& a, int l, int r, int val);
int splitByPivot(std::vector<int>& a, int l, int r, int pivotVal);
int findDeterministic(std::vector<int>& a, int l, int r, int k);
int findMedianDeterministic(const std::vector<int>& input);





//test

#endif //ASSIGNMENT3_DETERMINITSTIC_H