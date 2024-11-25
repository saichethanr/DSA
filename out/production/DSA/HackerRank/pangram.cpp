#include<bits/stdc++.h> 
using namespace std;

//if all the characters are used in a string its called pangram else its not a pangram
//s[i]-'a' is appplies to only lowercase letters
//transform fucntion is a litile new and i learnnt it 
string pangrams(string s) {
  int hash[26] = {0};
  transform(s.begin(), s.end(), s.begin(), ::tolower);
  for(int i=0;i<s.size();i++){
      hash[s[i]-'a']++;
  }
  
  for(int i=0;i<26;i++){
      if(hash[i]==0){
          return "not pangram";
      }
  }
  return "pangram";
}