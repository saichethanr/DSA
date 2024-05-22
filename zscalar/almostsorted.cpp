#include<bits/stdc++.h> 
using namespace std;

//brute force approach
void mindeletionstomakealmostsorted(vector<int> v){
    int cnt=0;
    for(int i=0;i<v.size()-1;i++){
        if(v[i]>v[i+1]){
            cnt++;
        }

    }
    cout<<cnt-1<<endl;
}


//memoization code
//as initially the prev ==-1 we cannot store that in the dp hence its 
//important to consider the coordinate change 
int solve(int ind,int prev,vector<int>&nums, vector<vector<int>> &dp){
        //if the index goes out of bounds 
        if(ind==nums.size()){
            return 0;
        }

        if(dp[ind][prev+1]!=-1){
            return dp[ind][prev+1];
        }
        // if the element at current index is not taken  prev is not changed
        int notake = solve(ind+1,prev,nums,dp);
        int take = 0;

        // if the prev = -1 and the nums at ind is greater than nums at prev then it can be taken 
        // for increasing subsequence
        if(prev==-1 || nums[ind]>nums[prev]){
            take = 1 + solve(ind+1,ind,nums,dp);
        }
        
        //max has to be returened
         dp[ind][prev+1] = max(notake,take);
         return dp[ind][prev+1];
}

int main(){
  vector<int>v = {3,4,2,5,1};
  int n = v.size();
  vector<vector<int>>dp(n,vector<int>(n+1,-1));
  int ans = solve(0,-1,v,dp);
  int x = n-ans-1;
  cout<<x<<endl;

}