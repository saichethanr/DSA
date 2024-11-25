#include<bits/stdc++.h> 
#include <string>
using namespace std;


// You are given a string word. A letter c is called special if it appears both in lowercase and uppercase in word, and every lowercase occurrence of c appears before the first uppercase occurrence of c.

// Return the number of special letters in word.



class Solution {
public:
    int numberOfSpecialChars(string word) {
      
       map<char,pair<int,vector<int>>> mpp;
       for(int i=0;i<word.size();i++){
           if(isupper(word[i]) &&  mpp.find(word[i])==mpp.end()){
              mpp[word[i]].first = i;
           }
       }
       
       for(int i=0;i<word.size();i++){
            if(islower(word[i])){
                mpp[toupper(word[i])].second.push_back(i);
            }
       }
       

       int cnt=0;
        for( auto it : mpp){
            vector <int> v;
            v=it.second.second;
             if(!v.empty()){
                bool check = false;
                 for(int i=0;i<v.size();i++){
                    if(v[i]<it.second.first){
                        check = true;
                    }
                    else{
                        check = false;
                        break;
                    }
                 }
                 if(check==true){
                    cnt++;
                 }
             }
        }
        return cnt;
    }
    
};