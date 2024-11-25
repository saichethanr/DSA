#include<bits/stdc++.h> 
#include <vector>
using namespace std;
class Solution {
  public:
    void solve(int ind,vector<int>arr,vector<int> &ans,int &sum){
        if(ind==arr.size()){
            ans.push_back(sum);
            return;
        }
        
        sum+=arr[ind];
        solve(ind+1,arr,ans,sum);
        sum-=arr[ind];
        solve(ind+1,arr,ans,sum);
    }
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int> ans;
        int sum=0;
        solve(0,arr,ans,sum);
        return ans;
    }
};