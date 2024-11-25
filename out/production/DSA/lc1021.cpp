#include<bits/stdc++.h> 
#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        stack <char> st;
        string str = "";
        for(int i=0;i<s.size();i++){
           if(st.empty()){
            st.push(s[i]);
           }
           else{
             if( st.top()=='(' && s[i]=='('){
                str+=s[i];
                st.push(s[i]);
             }
             else if(st.size()>1 && st.top()=='(' && s[i]==')'){
                str+=s[i];
                st.pop();
             }
             else if(st.size()==1 && st.top()=='(' && s[i]==')'){
                st.pop();
             }
              
           
           }
        }
        return str;
    }
};