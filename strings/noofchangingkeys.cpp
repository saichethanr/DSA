#include<bits/stdc++.h> 
#include <string>
using namespace std;

class Solution {
public:
    int countKeyChanges(string s) {
        string str = "";
        for(int i=0;i<s.size();i++){
            char c=  tolower(s[i]);
            str+=c;
        }
       int prev=0;
       int cnt=0;
      stack<char>st;
     
      for(int i=0;i<str.size();i++){
        if(st.empty()){
            st.push(str[i]);
            continue;
        }
        if(str[i]!=st.top()){
            cnt++;
            st.pop();
        }
        st.push(str[i]);
      }


       

        return cnt;
    }
};