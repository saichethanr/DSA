#include<bits/stdc++.h> 
#include <string>
using namespace std;


    int findPermutationDifference(string s, string t) {
     unordered_map<char,int> mpp;

     for(int i=0;i<s.size();i++){
        mpp[s[i]] =i;
     }

     int sum=0;
     for(int i=0;i<t.size();i++){
        if(mpp.find(t[i])!=mpp.end()){
            sum+=abs(i-mpp[t[i]]);
        }
     }

     return sum;

  



    }