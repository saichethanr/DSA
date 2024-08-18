#include<bits/stdc++.h> 
using namespace std;


//initial solution does not solve the case where there are multiple permutation of occurence of a particular set of zeros
class Solution {
public:
//initial solution
    long long zeroFilledSubarray(vector<int>& nums) {
        map<int,int> mpp;
        int r=0;
        int n = nums.size();
        int l=0;
        int cnt=0;
        int z=0;
        while(r<n){
          if(nums[r]==0){
              mpp[1]++;
              if(l==0 && r!=l){
                 l=r;
              }
              else if(l!=0 && r!=l){
                 mpp[(r-l+1)]++;
              }
          }
          else{
            l=0;
          }
          r++;
        }
         
        int res=0;
        for(auto it : mpp){
          res+=it.second;
        }

        return res;
    }
};





//answer
class Solution {
public:
//initial solution
    long long zeroFilledSubarray(vector<int>& nums) {
        map<long long  ,long long> mpp;
        int r=0;
        int n = nums.size();
        int l=-1;
        int cnt=0;
        int z=0;
        while(r<n){
          if(nums[r]==0){
             if(l==-1){
                 l=r;
             }
            
          }
          else{
            if(l!=-1){
               long long x = r-l;
               mpp[x]+=(x*(x+1))/2;
            }
            l=-1;
          }
          r++;
        }
        
         if(l!=-1){
               long long  x = r-l;
               mpp[x]+=(x*(x+1))/2;
        }

         
        long long int  res=0;
        for(auto it : mpp){
            cout<<it.first<<" "<<it.second<<endl;
            res+=it.second;
        }

        return res;
    }
};