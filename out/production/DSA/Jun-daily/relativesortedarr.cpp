#include<bits/stdc++.h> 
using namespace std;
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>mpp;
        for(int i=0;i<arr1.size();i++){
            mpp[arr1[i]]++;
        }

        vector<int>ans;
        vector<int>t;
        for(int i=0;i<arr2.size();i++){
            if(mpp.find(arr2[i])!=mpp.end()){
                  while(mpp[arr2[i]]>0){
                     ans.push_back(arr2[i]);
                     mpp[arr2[i]]--;
                  }
            }
        }

        for(auto it : mpp){
            if(it.second!=0){
                while(it.second>0){
                    t.push_back(it.first);
                    it.second--;
                }
            }
        }
        sort(t.begin(),t.end());
        ans.insert(ans.end(),t.begin(),t.end());
        return ans;
    }
};