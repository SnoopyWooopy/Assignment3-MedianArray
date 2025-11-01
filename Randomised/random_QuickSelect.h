
#ifndef ASSIGNMENT3_QUICKSELECT_RANDOM_QUICKSELECT_H
#define ASSIGNMENT3_QUICKSELECT_RANDOM_QUICKSELECT_H

#include <vector>

//class random_QuickSelect {
    int partition(std::vector<int> &array);

    // Display the contents of the array
    void display(std::vector<int> &array);

    // Determine if the array size is odd or even (returns median index)
    double findMedian(std::vector<int> &array);

    // Basic test function
    int baicTest();

    // QuickSelect algorithm to find the k-th smallest element
    int quickSelect(std::vector<int> &array, int k);
//};


#endif //ASSIGNMENT3_QUICKSELECT_RANDOM_QUICKSELECT_H