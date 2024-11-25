#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int fb;
        int n=s.size()-1;
        int la;

        for(int i=0;i<s.size();i++){
            if(s[i]=='b'){
                fb=i;
                break;
            }
        }

        for(int i=n-1;i>=0;i--){
            if(s[i]=='a'){
                la = i;
                break;
            }
        }

        int acnt=0;
        int bcnt=0;
        for(int i=fb;i<s.size();i++){
            if(s[i]=='a'){
                acnt++;
            }
        }


        for(int i=0;i<la;i++){
            if(s[i]=='b'){
                bcnt++;
            }
        }

        int ans = min(acnt,bcnt);
        return ans;


    }
};