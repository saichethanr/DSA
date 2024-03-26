#include<bits/stdc++.h> 
using namespace std;

void reverseastring(string &s, int l, int r){
  if(l>=r){
    cout<<s<<endl;
    return;
  }

  swap(s[l],s[r]);

  return reverseastring(s,l+1,r-1);
}
int main(){
    int l=0;
    string s  = "abcd";
    int r = s.size()-1;
    reverseastring(s,l,r);
  return 0;  
}