#include <bits/stdc++.h>
using namespace std; 

int ones(vector <int> nums){
   int cnt =0;
   int maxcnt=INT_MIN;
   for(int i=0;i<nums.size();i++){
      if(nums[i]==1){
        cnt++;
        maxcnt = max(maxcnt,cnt);
      }
      else{
        cnt=0;
      }
   }

   return maxcnt;
}


int main(){
   vector<int>a = {0,1,1,1,1,1,0,1,0,1};
   int ans = ones(a);
   cout<<ans<<endl;
}