#include<bits/stdc++.h> 
using namespace std;


class Solution {
public:
    string removeTrailingZeros(string num) {
        int n = num.size();
        
        int cnt=0;
        for(int i=n-1;i>=0;i--){
            if(num[i]=='0'){
                cnt++;
            }
            else{
                break;
            }
        }
        cout<<cnt<<endl;
        string ans ="";
        int resize = n-cnt;
        if(resize==n){
            return num;
        }
        for(int i=0;i<resize;i++){
            ans+=num[i];
        }

        return ans;
    }
};