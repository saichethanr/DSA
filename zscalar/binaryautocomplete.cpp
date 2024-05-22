#include<bits/stdc++.h> 
using namespace std;

//Question : no of deletions to make the array almost sorted

int longestCommonPrefix(const string &str1, const string &str2) {
    int minLength = min(str1.size(), str2.size());
    int i = 0;
    
    
    while (i < minLength && str1[i] == str2[i]) {
        i++;
    }

    return i;
}
vector<int> solve(vector<string> v){
    unordered_map<string,int>mpp;
    for(int i=0;i<v.size();i++){
        mpp[v[i]]=i;
    }
    int n= v.size();
    vector<int> ans(n,0);
    
    for(int i=1;i<v.size();i++){
          for(int j=i-1;j>=0;j--){
              int len = longestCommonPrefix(v[j],v[i]);

          }
    }
    return ans;
}