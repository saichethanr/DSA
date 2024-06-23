#include<bits/stdc++.h> 
#include <string>
using namespace std;

class Solution {
  public:
     bool isInteger(string  s) {
            for (char c : s) {
                if (!isdigit(c)) {
                    return false;
                }
            }
            return !s.empty();
    }
     bool contains9(string str) {
        return str.find('9') != string::npos;
    }
    long long ExtractNumber(string sentence) {
       stringstream ss(sentence);
       long long int ans =-1;
       string word;
       while(ss>>word){
           if(isInteger(word)){
               if(!contains9(word)){
                long long int a = stoll(word);
                 ans = max(a,ans);
               }
           }
       }
       
       return ans;
    }
};