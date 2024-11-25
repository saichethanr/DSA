#include<bits/stdc++.h> 
using namespace std;


//iterative approach TLE
class Solution {
public:
    const int MOD = 1e9 + 7;

    int countGoodNumbers(long long n) {
        long long evenChoices = 1; 
        long long oddChoices = 1;  
         long long nextEven;
         long long nextOdd;
        for (long long i = 0; i < n; ++i) {

            if(i%2==0){
                nextEven = (evenChoices * 5) % MOD;
            }
            else{
                 nextOdd = (oddChoices * 4) % MOD; 
            }
      

            evenChoices = nextEven;
            oddChoices = nextOdd;
        }

    
        return (evenChoices * oddChoices) % MOD;
    }
};


//recursive approach TLE
class Solution {
public:
    const int MOD = 1e9 + 7;
    void solve(long long  i,long long n,long long int &ans){
         if(i>=n){
            return;
         }

         if(i%2==0){
            ans =(ans*5)%MOD;
            solve(i+1,n,ans);
         }
         else{
           ans = (ans*4)%MOD;
           solve(i+1,n,ans);
         }

    }
    int countGoodNumbers(long long n) {
         long long int ans =1;
        solve(0,n,ans);
         return ans;
    }
};



//working version
class Solution {
public:
    void solve(int ind,vector<int>& nums,vector<int>t, int target,  vector<vector<int> >&ans){
        //if the target has exeeded hen that subsequence has to be stored and call has to be made
        if(target==0){
            ans.push_back(t);
            return;
        }
        //you have to loop through all the posibility of taking the next index
        for(int i=ind;i<nums.size();i++){
            //check to prevent picking duplicate elements
            if(i>ind && nums[i]==nums[i-1]){
                continue;
            }
            //check to prevent target going negative
            if(nums[i]>target){
                break;
            }
            t.push_back(nums[i]);
            solve(i+1,nums,t,target-nums[i],ans);
            t.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int> >ans;
        vector<int>t;
        //we have to sort initially as we want the combinations in a sorted order
        sort(nums.begin(),nums.end());
        solve(0,nums,t,target,ans);
        return ans;
    }
};