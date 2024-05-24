#include<bits/stdc++.h> 
#include <string>


using namespace std;

class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3){
            return false;
        }
       
        set<char>st;
        vector<char>v = {'a','e','i','o','u','A','E','I','O','U'};

        bool checkv= false;
        bool checkc = false;
        for(int i=0;i<v.size();i++){
              st.insert(v[i]);
        } 


        for(int i=0;i<word.size();i++){
            if(!isalpha(word[i])){
                if(!isdigit(word[i])){
                    return false;
                }
            }

           if(isalpha(word[i])){
                 if(st.find(word[i])!=st.end()){
                     checkv = true;
                 }
                 else{
                    checkc = true;
                 }


           }

        }

        return checkv&&checkc;

    }
};