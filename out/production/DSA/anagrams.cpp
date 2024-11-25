#include<bits/stdc++.h> 
#include <string>
using namespace std;
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        int freq1[26]={0};
        int freq2[26]={0};
        
        for(int i=0;i<a.size();i++){
            freq1[a[i]-'a']++;
        }
        
        for(int i=0;i<b.size();i++){
            freq2[b[i]-'a']++;
        }
        
        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i]){
                return false;
            }
        }
        
        return true;
       
    }

};