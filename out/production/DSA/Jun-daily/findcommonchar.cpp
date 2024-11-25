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




//solved my approcah but need to revise the programming concepts
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char, int> mpp;
        string a = words[0];
        for (int i = 0; i < a.size(); i++) {
            mpp[a[i]]++;
        }

        for (int i = 1; i < words.size(); i++) {
            unordered_map<char, int> mpp1;
            for (int j = 0; j < words[i].size(); j++) {
                mpp1[words[i][j]]++;
            }

            // Iterate through a copy of the map keys to avoid modifying the map while iterating
            for (auto it = mpp.begin(); it != mpp.end();) {
                if (mpp1.find(it->first) != mpp1.end()) {
                    mpp[it->first] = min(mpp1[it->first], mpp[it->first]);
                    ++it;
                } else {
                    it = mpp.erase(it);
                }
            }
        }

        vector<string> ans;
        for (auto& it : mpp) { // Use auto& to modify the original map
            while (it.second > 0) {
                ans.push_back(string(1, it.first)); // Convert char to string
                it.second--;
            }
        }
        return ans;
    }
};
