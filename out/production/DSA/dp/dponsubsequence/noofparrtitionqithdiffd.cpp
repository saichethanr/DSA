#include <bits/stdc++.h> 
using namespace std;
int mod = (int)(1e9 +7);

  int solve(int idx,int n,int target,vector<int>&nums){
 
   if(idx==0){
        if(target==0 && nums[0]==0){
            return 2;
        }
        if(target==0 || nums[idx]==target){
            return 1;
        }
        return 0;
   }

   int notake = solve(idx-1,n,target,nums);
   int take = 0;
   if(target>=nums[idx]){
     take = solve(idx-1,n,target-nums[idx],nums);
   }
   return take+notake;
}

int countPartitions(int n, int d, vector<int> &arr) {
int totsum=0;
for(auto &it : arr){
    totsum+=it;
}
if(totsum-d<0 || (totsum-d)%2!=0){
    return false;
}
int target = totsum/2;
return solve(n-1,n,target,arr);
}