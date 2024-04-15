#include<bits/stdc++.h> 
using namespace std;
//baakwaas approach
int minMoves(vector<int>& nums) {
       int minel = *min_element(nums.begin(),nums.end());
       int cnt=0;
       for(int i=0;i<nums.size();i++){
         cnt+=(nums[i]-minel);
       }
       return  cnt;
    }