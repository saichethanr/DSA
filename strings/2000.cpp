#include<bits/stdc++.h> 
#include <string>
using namespace std;


string reversePrefix(string word, char ch) {
        int idx=-1;
        for(int i=0;i<word.size();i++){
            if(word[i]==ch){
                idx=i;
                break;
            }
        }
        if(idx==-1){
            return word;
        }
        int n= word.size();
        string str = word.substr(0,idx+1);
        reverse(str.begin(),str.end());
        for(int i=0;i<=idx;i++){
           word[i]=str[i];
        }
        cout<<word<<endl;
        return word;
}