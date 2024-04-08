#include<bits/stdc++.h> 
#include <string>
using namespace std;
class Solution {
public:
    int maxDepth(string s) {
        int maxdepth = INT_MIN;
        int t = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                t++;
            }
            else if (s[i]==')'){
                t--;
            }
           maxdepth = max(maxdepth,t);

        }
        return maxdepth;
    }

};