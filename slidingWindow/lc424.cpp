#include<bits/stdc++.h> 
using namespace std;

// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

// Return the length of the longest substring containing the same letter you can get after performing the above operations.
int brute(string s, int k) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int maxlen = INT_MIN;
        for(int i=0;i<s.size();i++){
            int maxfreq=0;
            int hash[26] = {0};
            for(int j=i;j<s.size();j++){
                hash[s[j]-'A']++;
                maxfreq = max(maxfreq,hash[s[j]-'A']);
                int changes = (j-i+1) - maxfreq;
                if(changes<=k){
                     maxlen = max(maxlen,(j-i+1));
                }
                else{
                    break;
                }
            }
        }
        return maxlen;
    }

    int better(string s, int k) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int maxlen = INT_MIN;
        int maxfreq =0;
        int l=0;
        int r=0;
        int hash[26] = {0};
        while(r<s.size()){
            hash[s[r]-'A']++;
            maxfreq = max(maxfreq,hash[s[r]-'A']);
            int changes = (r-l+1) - maxfreq;

            while(changes>k){
                hash[s[l]-'A']--;
                maxfreq=0;
                for(int i=0;i<26;i++){
                    maxfreq = max(maxfreq,hash[i]);
                }
                l++;
                changes = (r-l+1) - maxfreq;
            }

            changes = (r-l+1) - maxfreq;
            if(changes<=k){
                maxlen = max(maxlen,r-l+1);
            }
            r++;
          
        }

        return maxlen;
    }
