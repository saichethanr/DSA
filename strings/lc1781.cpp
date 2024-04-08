#include<bits/stdc++.h> 
#include <string>
using namespace std;



    
    vector<int>  freq(unordered_map <char,int> &mpp){
       int maxf=INT_MIN;
       int minf=INT_MAX;
         vector <int> ans;
       for(auto it : mpp){
          maxf = max(maxf,it.second);
          minf = min(minf,it.second);
       }
       return {maxf,minf};
    }

   
    int beautySumbrute(string s) {
        int maxf=0;
        int minf=0;

        int sum=0;
        for(int i=0;i<s.size();i++){
            unordered_map <char,int> mpp;
            for(int j=i;j<s.size();j++){
                   mpp[s[j]]++;
                   if(mpp.size()>1){
                          vector <int> t = freq(mpp);
                          
                          sum+=(t[0]-t[1]);
                   }
            }
        }
        return sum;
    }
