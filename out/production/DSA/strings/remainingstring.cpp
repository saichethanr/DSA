#include<bits/stdc++.h> 
#include <string>


using namespace std;

class Solution {
  public:

    string printString(string s, char ch, int count) {
        int cnt=0;
        string str ="";
        for(int i=0;i<s.size();i++){
            if(s[i]==ch){
                cnt++;
                if(cnt==count){
                    str =  s.substr(i+1,s.size()-(i+1));
                    break;
                }
            }
            
           
        }
        return str;
    }
};