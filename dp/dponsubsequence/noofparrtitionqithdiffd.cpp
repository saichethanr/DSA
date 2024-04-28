#include <bits/stdc++.h> 
using namespace std;

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

int solve(int idx,int n,int target,vector<int>&nums,vector <vector<int>>dp){
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

int main(){
  
}