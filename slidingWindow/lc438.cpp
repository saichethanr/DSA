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
vector<int> findAnagrams(string s, string p) {
      int l=0;
      int r= 0;
      int n=s.size();
      vector<int>s_freq(26,0);
      vector<int>p_freq(26,0);
      vector<int> ans;
      for(int i=0;i<p.size();i++){
        p_freq[p[i]-'a']++;
      }
      while(r<n){
          s_freq[s[r]-'a']++;
          if((r-l+1)>p.size()){
            s_freq[s[l]-'a']--;
            l++;
          }

          if(s_freq==p_freq){
            ans.push_back(l);
          }
          r++;
      }

      return ans;
    }