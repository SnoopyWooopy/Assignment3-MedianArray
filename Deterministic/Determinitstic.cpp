//
// Created by melisa on 24/10/25.
//

#include "Determinitstic.h"
#include <iostream> //to print
#include <vector>
#include <algorithm>
#include <stdexcept> //for invalid argument


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
    int len =  r -l + 1; //lenght of the slice
    return a[l+len / 2]; //middle element
}

int findIndexSlice(const vector<int>& a, int l, int r, int val){ //locae val in a[]
    for (int i = l; i <= r; ++i){ //check the slice and reurn the index when we find it
        if (a[i] == val){ // if not found -1
            return i;
        }
    }
    return -1;
}

int splitByPivot(vector<int>& a, int l, int r, int pivotVal){
    int pivotIDx = findIndexSlice(a, l, r, pivotVal); // find where the val currently is
    if (pivotIDx == -1){
        pivotIDx = r; //if not found use r as the pivot index
    }
    swap(a[pivotIDx], a[r]); //move to end
    int store = l; //next smaller than pivot
    for (int i = l; i < r; ++i){ //iterate all except r
        if (a[i] < pivotVal){
            swap(a[store], a[i]); ++store; //move smaller elements left of store
        }
    }
    swap(a[store], a[r]); //final positon
    return store; //return pivot final index

}

int findDeterministic(vector<int>& a, int l, int r, int k){
    if (l == r){
        return a[l]; //base case only 1 element
    }

    vector<int> medians; //divide into group of 5 and find each grpups median
    for (int i = l; i <= r; i += 5){
        int groupRight = min(i + 4, r); //end of group
        medians.push_back(medianSlice(a, i, groupRight)); //store median

    }

    int pivotVal; //median of medians so we can use it as a pivot
    if (medians.size() == 1){
        pivotVal = medians[0]; // only one median 
    }else{
        vector<int> medCopy = medians; //copy to safely work on
        pivotVal = findDeterministic(medCopy, 0, (int)medCopy.size() - 1, (int)medCopy.size()/ 2 );
    }

    int pivotInd = splitByPivot(a, l, r, pivotVal); //partition array arount pivotval

    int numLeft = pivotInd - l; //how many elemtents smaller than pivot

    if (k == numLeft){ //where is kth element
        return a[pivotInd]; //pivot is the k th element
    }else if(k < numLeft){
        return findDeterministic(a, l, pivotInd -1, k); //search left
    }else{
        return findDeterministic(a, pivotInd + 1, r, k - numLeft - 1); //search right
    }

}

int findMedianDeterministic(const vector<int>& input){
    int n = (int)input.size();
    if (n==0) throw invalid_argument("Array is empty");
    vector<int> a = input; //copy
    int k = (n%2 == 0) ? (n -1) / 2: n/2; //lower median for even n
    return findDeterministic(a, 0, n-1, k);
}

int main(){
    vector<int> arr = {12, 3, 5, 7, 4, 19, 26};
    try{
        cout << "Median: " << findMedianDeterministic(arr) <<endl;
    } catch (const exception& e){
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}