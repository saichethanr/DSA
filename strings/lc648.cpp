#include<bits/stdc++.h> 
#include <string>
using namespace std;

// In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word successor. For example, when the root "help" is followed by the successor word "ful", we can form a new word "helpful".

// Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the successors in the sentence with the root forming it. If a successor can be replaced by more than one root, replace it with the root that has the shortest length.

// Return the sentence after the replacement.

    class Solution {
    public:
        string replaceWords(vector<string>& dictionary, string sentence) {
            vector<string> words;
            stringstream ss(sentence);
            string word;
        
            while (ss >> word) {
                words.push_back(word);
            }

            for(int i=0;i<words.size();i++){
                for(int j=0;j<dictionary.size();j++){
                    
                        int n = dictionary[j].size();
                        string t = words[i].substr(0,n);
                        if(t==dictionary[j]){
                            words[i] = dictionary[j];
                        }   
                }
            }
        string ans ="";
        for(int i=0;i<words.size();i++){
            ans+=words[i];
            if(i!=words.size()-1){
                ans+=" ";
            }
        }
        return ans;
        }
    };