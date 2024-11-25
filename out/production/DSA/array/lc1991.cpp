  #include<bits/stdc++.h> 
using namespace std;

// Given a 0-indexed integer array nums, find the leftmost middleIndex (i.e., the smallest amongst all the possible ones).

// A middleIndex is an index where nums[0] + nums[1] + ... + nums[middleIndex-1] == nums[middleIndex+1] + nums[middleIndex+2] + ... + nums[nums.length-1].

// If middleIndex == 0, the left side sum is considered to be 0. Similarly, if middleIndex == nums.length - 1, the right side sum is considered to be 0.

// Return the leftmost middleIndex that satisfies the condition, or -1 if there is no such index.

 


class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int>lr(n,0);
        vector<int>rl(n,0);
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            lr[i]=sum;
        }
        sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=nums[i];
            rl[i]=sum;
        }
        int ans=-1;

        for(int i=0;i<n;i++){
            if(lr[i]==rl[i]){
                ans = i;
                break;
            }
        }
        return ans;
    }
};