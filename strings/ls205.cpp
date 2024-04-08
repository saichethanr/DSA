#include<bits/stdc++.h> 
#include <string>


using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t){
        string str="";
        if(s.size()!=t.size()){
            return false;
        }
        unordered_map<char,char> mpp;
        set<char>st;
        for(int i=0;i<s.size();i++){
            if(mpp.find(s[i])==mpp.end()){
                if(st.find(t[i])==st.end()){
                    mpp[s[i]]=t[i];
                    st.insert(t[i]);
                    
                }
                else{
                    return false;
                    
                }
                
            }
            
            str+=mpp[s[i]];
      
        }
        if(str==t){
            return true;
        }
       return false;
    }
};