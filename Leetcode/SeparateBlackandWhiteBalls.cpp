#include<bits/stdc++.h> 
using namespace std;


//bruteforce
long long minimumSteps(string s) {
        if(s.size()==1){
            return 0;
        }
        string temp= "";
        int c1=0;
        int c0=0;
        for(int i=0;i<s.size();i++){
              if(s[i]=='1'){
                  c1++;
              }
              else{
                  c0++;
              }
        }
        for(int i=0;i<c0;i++){
            temp.push_back('0');
        }
        for(int i=0;i<c1;i++){
            temp.push_back('1');
        }
        cout<<temp<<endl;
        int cnt=0;
        int l=0;
        int r=1;
        while(s!=temp){
                l=0;
                r=1;
                while(r<s.size()){
                if(s[l]=='1' && s[r]=='0'){
                    swap(s[l],s[r]);
                    cnt++;
                }
                r++;
                l++;
            }
        }

        return cnt;
    }