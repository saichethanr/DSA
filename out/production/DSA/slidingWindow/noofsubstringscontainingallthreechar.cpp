#include<bits/stdc++.h> 
using namespace std;


//tle
 int myapproch(string s) {
        int l=0;
        int ac=0;
        int bc =0;
        int cc =0;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            ac=0;
            cc=0;
            bc=0;
            for(int j=i;j<s.size();j++){
                if(s[j]=='a'){
                    ac++;
                }
                else if(s[j]=='b'){
                    bc++;
                }
                else{
                    cc++;
                }
                if(ac>0 && bc>0 && cc>0){
                    cnt++;
                }
            }
        }
        return cnt;
    }