#include<bits/stdc++.h> 
#include <vector>
#include <string>



class Solution {
public:
    void removesubstr(string &s,string &part){
        int found = s.find(part);
        //O(nm);    
        if(found!=string::npos){
            string left_part = s.substr(0,found);
            string right_part = s.substr(found+part.size(),s.size());
            //find left part and right part and join
            s =  left_part + right_part;
            removesubstr(s,part);
        } 
        else{
            return;
        }
    }
    string removeOccurrences(string s, string part) {
        removesubstr(s,part);
        return s;
    }
};
