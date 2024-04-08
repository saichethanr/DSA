#include<bits/stdc++.h> 
using namespace std;
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector <int> t(arr);
        int n = arr.size();
        int k=1;
        vector <int> ans(n,0);
        sort(t.begin(),t.end());
        unordered_map<int,int> mpp;
        for(int i=0;i<t.size();i++){
              if(mpp[t[i]]==0){
                 mpp[t[i]]=k;
                 k++;
              }
        }
        for(int i=0;i<arr.size();i++){
            ans[i] = mpp[arr[i]];
        }
        return ans;

    }
};