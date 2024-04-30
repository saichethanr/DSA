#include<bits/stdc++.h> 
#include <string>
using namespace std;
    
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