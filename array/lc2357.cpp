#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
       priority_queue<int,vector<int>,greater<int>>pq;
       int sum=0;
       for(int i=0;i<nums.size();i++){
         sum+=nums[i];
         pq.push(nums[i]);
       }

       while(pq.top()==0 && !pq.empty()){
          pq.pop();
       }
       if(pq.empty()){
        return 0;
       }

       
       unordered_map <int,int> mpp;
       while(!pq.empty()){
         mpp[pq.top()]++;
         pq.pop();
       }



       return mpp.size();

    }
};