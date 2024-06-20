#include <bits/stdc++.h>
using namespace std;
vector<int> removeDuplicates(vector<int>& nums) {
       map<int,int> mpp;
       for(int i=0;i<nums.size();i++){
          mpp[nums[i]]++;
       }
       vector<int> ans;
       for(auto it : mpp){
          ans.push_back(it.first);
       }
      return ans;
}


int main() {
   vector<int>a = {1,1,2,3,4,4,5};
   vector<int> ans = removeDuplicates(a);
   for(int i=0;i<ans.size();i++){
       cout<<ans[i];
   }
   return 0;
}