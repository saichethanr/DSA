#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        set <char> st;
        int cnt=0;
        for(int i=0;i<word.size();i++){
            if(islower(word[i])){
                st.insert(word[i]);
            }
        }
        
          for(int i=0;i<word.size();i++){
            if(isupper(word[i])){
               if(st.find(tolower(word[i]))!=st.end()){
                   cnt++;
                   st.erase(tolower(word[i]));
               }
            }
        }
        
        return cnt;
    }
};