#include<bits/stdc++.h> 
using namespace std;

// Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

// In one move, you can increment or decrement an element of the array by 1.

// Test cases are designed so that the answer will fit in a 32-bit integer.



// intuition : find the element which is absolute near to every other element to find the minimum operation
   int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size()-1;
        int median = (0+n)/2;
        int totaldis=0;
        cout<<median<<endl;
        for(int i=0;i<nums.size();i++){
            if(i!=median){
                totaldis += abs(nums[i]-nums[median]);
            }
        }
        return totaldis;
    }