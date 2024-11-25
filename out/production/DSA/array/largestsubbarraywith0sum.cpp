#include<bits/stdc++.h> 
using namespace std;

class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {  
       int sum=0;
       int maxlen =0;
       unordered_map<int,int>mpp;
       for(int i=0;i<arr.size();i++){
           sum+=arr[i];
           if(sum==0){
               maxlen = max(maxlen,i+1);
           }
           if(mpp.find(sum)!=mpp.end()){
            maxlen = max(maxlen,i-mpp[sum]);
           }
           else{
               mpp[sum] =i;
           }
       }
       
       return maxlen;
    }
};