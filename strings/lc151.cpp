#include<bits/stdc++.h> 
#include <string>
using namespace std;


class Solution {
public:
    vector<string> extractWords(const string& str) {
    vector<string> words;
    stringstream ss(str);
    string word;
    while (ss >> word) {
        words.push_back(word);
    }

    return words;
}
    string reverseWords(string s) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        vector <string> words = extractWords(s);
        reverse(words.begin(),words.end());
        string ans = "";
        for(int i=0;i<words.size();i++){
            ans+=words[i];
            if(i!=words.size()-1){
                ans+=" ";
            }
        }
        return ans;
    }
};