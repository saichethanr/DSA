#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    
    int distance(char char1, char char2) {
        const int asize = 26;
        int distance = std::abs(char2 - char1);

        
        if (distance > asize / 2)
            distance = asize - distance;

        return distance;
    }
    string getSmallestString(string s, int k) {
        if(k==0){
            return s;
        }
        
        for(int i=0;i<s.size();i++){
            
            int j=0;
            while(j<26 && k>=0){
                char dis = j+'a';
                int t = distance(s[i],dis);
                cout<<s[i]<<endl;
                cout<<dis<<endl;
                cout<<t<<endl;
                if(t<=k){
                    s[i]=j+'a';
                    k-=t;
                    break;
                }
            
                j++;
            }
        }
        return s;
    }
};