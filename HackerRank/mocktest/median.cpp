#include<bits/stdc++.h> 
using namespace std;

// The median of a list of numbers is essentially its middle element after sorting. The same number of
// elements occur after it as before. Given a list of numbers with an odd number of elements, find the median?\



int findMedian(vector<int> arr) {
    sort(arr.begin(),arr.end());
    int idx = floor(arr.size()/2);
    return arr[idx];
}