#include<bits/stdc++.h> 
#include <string>
using namespace std;


class Solution {
public:
    int beautifulSubstrings(string s, int k) {
       set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
       set<char> consonants;
       for (char ch = 'a'; ch <= 'z'; ++ch) {
            if (!vowels.count(ch)) {
                consonants.insert(ch);
            }
        }
        int l=0;
        int cnt=0;
        int r=0;
        int numvowel=0;
        int numconsonant=0;

        for(int i=0;i<s.size();i++){
            numvowel=0;
            numconsonant=0;
            for(int j=i;j<s.size();j++){
                if(vowels.find(s[j])!=vowels.end()){
                    numvowel++;
                }
                if(consonants.find(s[j])!=consonants.end()){
                    numconsonant++;
                }

                if(numvowel==numconsonant && (numvowel * numconsonant)%k==0){
                    cnt++;
                }
                
            }
        }
        return cnt;

    }
};