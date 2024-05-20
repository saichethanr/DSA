#include<bits/stdc++.h> 
using namespace std;

//in this he message sent by the mars explored is changed so we have to find the no 
//of corrupted bits

int marsExploration(string s) {
  string t ="SOS";
  int cnt =0;
  for(int i=0;i<s.size();i+=3){
      int k=0;
       for(int j=i;j<i+t.size();j++){
           if(t[k]!=s[j]){
               cnt++;
           }
           k++;
       }
  }
}