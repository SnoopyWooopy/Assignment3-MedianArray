//
// Created by melisa on 24/10/25.
//

#include "Determinitstic.h"
#include <iostream> //to print
#include <vector>
#include <algorithm>

using namespace std;

void printVec(const vector<int>& v){ //print vector
    cout << "{";
    for (size_t i = 0; i < v.size(); ++i){ //from 0 to v.size -1
        cout << v[i]; //print current
        if (i +1 < v.size()) cout << ", "; // print comma and space
    }
    
    cout << "}";
}

int medianSlice(vector<int>& a, int l, int r){ //return the median of a[]
    sort(a.begin() + l, a.begin() + r + 1); //sortng
    int len =  r -1 + 1; //lenght of the slice
    return a[1+len / 2]; //middle element
}

int findIndexSlice(const vector<int>& a, int l, int r, int val){ //locae val in a[]
    for (int i = l; i <= r; ++i){ //check the slice and reurn the index when we find it
        if (a[i] == val){ // if not found -1
            return i;
        }
    }
    return -1;
}