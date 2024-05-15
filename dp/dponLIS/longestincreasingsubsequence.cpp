 #include<bits/stdc++.h> 
using namespace std;

    int solve(int ind,int prev,vector<int>&nums){
        //if the index goes out of bounds 
        if(ind==nums.size()){
            return 0;
        }
        // if the element at current index is not taken  prev is not changed
        int notake = solve(ind+1,prev,nums);
        int take = 0;

        // if the prev = -1 and the nums at ind is greater than nums at prev then it can be taken 
        // for increasing subsequence
        if(prev==-1 || nums[ind]>nums[prev]){
            take = 1 + solve(ind+1,ind,nums);
        }
        
        //max has to be returened
        return max(notake,take);
    }
