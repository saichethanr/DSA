#include<bits/stdc++.h> 
using namespace std;



class Solution {
public:
    int minimumChairs(string s) {
        stack<char>st;
        int cnt=0;
        int ans=INT_MIN;
        for(int i=0;i<s.size();i++){
            if(s[i]=='E'){
                st.push(s[i]);
                cnt++;
                ans=max(ans,cnt);
            }
            else if(st.top()=='E' && s[i]=='L'){
                st.pop();
                cnt--;
            }
        }
        
        return ans;
    }
};