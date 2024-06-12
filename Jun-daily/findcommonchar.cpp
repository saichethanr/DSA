#include<bits/stdc++.h> 
using namespace std;
//tried something but couldnt solve with a perfect approach
//  #wrong
class Solution {
public:
    vector<string> getAllSubstrings(const string &str) {
        vector<string> substrings;
        int n = str.size();

        // Generate all substrings
        for (int i = 0; i < n; i++) {
            for (int len = 1; len <= n - i; len++) {
                substrings.push_back(str.substr(i, len));
            }
        }

        return substrings;
    }
    vector<string> commonChars(vector<string>& words) {
       int leastlen = INT_MAX;
       int ind = -1;
       for(int i=0;i<words.size();i++){
          sort(words[i].begin(),words[i].end());
          if(words[i].size()<leastlen){
            leastlen = words[i].size();
            ind = i;
          }
       }
       string ans = "";
       int n = words[ind].size();
       vector<string>sub = getAllSubstrings(words[ind]);
       int cnt=0;
       for(int i=0;i<sub.size();i++){
          for(int i=0;i<words.size();i++){
                if(words[i].find(sub[i]) != string::npos){
                    cnt++;
                    if(cnt==words.size()){
                            ans = sub[i];
                            break;
                    }
                }
          }
       }
       

       vector<string>a;
       cout<<ans<<endl;
       for(int i=0;i<ans.size();i++){
            a.push_back(to_string(ans[i]));
       }

       
       return a;

        
    }
};