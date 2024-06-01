#include<bits/stdc++.h> 
#include <string>


using namespace std;
class Solution {
public:
    int scoreOfString(string s) {
      
        int prev=-1;
        int sum=0;
        for(int i=0;i<s.size();i++){
            if(prev==-1){
                 int asciiValue = static_cast<int>(s[i]);
                 prev = asciiValue;
            }
             
            int asciiValue = static_cast<int>(s[i]);
            sum+=abs(prev-asciiValue);
            prev = asciiValue;
             
        }
        return sum;
    }
};