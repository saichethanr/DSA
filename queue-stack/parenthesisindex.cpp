#include<bits/stdc++.h> 
using namespace std;

// User function template for C++
class Solution {
  public:
  vector<int> bracketNumbers(string str) {
        int k=1;
        stack<int>st;
        vector<int> results;
        for(int i=0;i<str.size();i++){
            if(str[i]=='('){
                st.push(k);
                results.push_back(k);
                k++;
            }
            else if(str[i]==')'){
              results.push_back(st.top());
              st.pop();
            }
        }
        
        return results;
    }
};