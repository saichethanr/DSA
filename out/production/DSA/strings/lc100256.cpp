#include<bits/stdc++.h> 
#include <string>
using namespace std;
class Solution {
public:
    string findLatestTime(string s) {
        string hrs = "";
        string min = "";
        string ans="";
        for(int i=0;i<2;i++){
            hrs.push_back(s[i]);
        }
        for(int i=3;i<s.size();i++){
            min.push_back(s[i]);
        }
        if(hrs[0]=='?' && hrs[1]=='?'){
          hrs[0]='1';
          hrs[1] ='1';
         }
         if(hrs[0]=='?' && hrs[1]!='?'){
             if(hrs[1]=='1' || hrs[1]=='0'){
                 hrs[0]='1';
             }
             else{
                 hrs[0]='0';
             }
         }
         else if(hrs[1]=='?' && hrs[0]!='?'){
             if(hrs[0]=='1'){
                 hrs[1] = '1';
             }
             else{
                 hrs[1]='9';
             }
         }
        if(min[0]=='?' && min[1]=='?'){
            min[0]='5';
            min[1]='9';
        }
         
        if(min[0]=='?'){
            min[0] = '5';
        }
        else if(min[1]=='?'){
            min[1] ='9';
        }
        ans = hrs+':'+min;
        cout<<ans<<endl;
        return ans;
    }
};