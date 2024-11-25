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
    int maximumValue(vector<string>& strs) {
        int maxval =  INT_MIN;
        for(int i=0;i<strs.size();i++){
            if(isInteger(strs[i])){
                int a = stoi(strs[i]);
                maxval = max(maxval,a);
            }
            else{
                int s = strs[i].size();
                maxval = max(maxval,s);
            }
        }
        return maxval;
    }
};