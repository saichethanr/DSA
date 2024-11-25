#include<bits/stdc++.h> 
using namespace std;

int approach1(vector<int>& nums){
      int ans =0;
        for(int bitidx=0;bitidx<32;bitidx++){
            int cnt=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]&(1<<bitidx)){
                    cnt++;
                }
            }
            if(cnt%3!=0){
                ans = ans | (1<<bitidx);
            }
        }
        return ans;
}


int approach2(vector<int>& nums){
      sort(nums.begin(),nums.end());
      int i=1;
      while(i<nums.size()){
          if(nums[i]==nums[i-1]){
            i=i+3;
          }
          else{
            return nums[i-1];
          }
      }
   int n= nums.size();
   return nums[n-1];     
}

int main(){
    vector <int> test = {0,1,0,1,0,1,99};
    cout<<approach2(test)<<endl;
}