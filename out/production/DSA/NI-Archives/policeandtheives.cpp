//greedy
#include<bits/stdc++.h> 
using namespace std;
class Solution{
    public:
    int catchThieves(char arr[], int n, int k) 
    {
       int ans=0;
       for(int i=0;i<n;i++){
           if(arr[i]=='P'){
               //check for thhe left part of the poilice 
               int j = max(0,i-k);
               bool flag = true;
               for(int run = j;run<i;run++){
                   if(arr[run]=='T'){
                       arr[run]='C';
                       ans++;
                       flag=false;
                       break;
                   }
                   
               }
               //if you did not find the answer in the left part of police then check for right
               //if found no need to check
               if(flag){
                   j=min(n,i+k);
                   for(int run=i;run<=j;run++){
                       if(arr[run]=='T'){
                           arr[run]='C';
                           ans++;
                           flag=false;
                           break;
                       }
                   }
               }
               
           }
       }
       return ans;
    }
};