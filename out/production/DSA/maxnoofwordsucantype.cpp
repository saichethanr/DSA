#include<bits/stdc++.h> 
#include <string>
using namespace std;


class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char,int>mpp;
        for(int i=0;i<brokenLetters.size();i++){
            mpp[brokenLetters[i]]++;
        }
        vector<string> words;
        stringstream ss(text);
        string word;
        while (ss >> word) {
            bool check = false;
            for(int i=0;i<word.size();i++){
                if(mpp.find(word[i])!=mpp.end()){
                    check = true;
                    break;
                }
            }
            if(!check){
               words.push_back(word);
            }
            
        }
        return words.size();
    }
};