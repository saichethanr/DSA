#include <vector>
#include<bits/stdc++.h> 
using namespace std;   
vector<int> findAnagrams(string s, string p) {
      int l=0;
      int r= p.size()-1;
      int n=s.size();
      vector<int> ans;
      sort(p.begin(),p.end());
      while(r<n){
           string str = s.substr(l,(r-l+1));
           sort(str.begin(),str.end());
           if(str==p){
             ans.push_back(l);
           }
           r++;
           l++;
      }

      return ans;
    }