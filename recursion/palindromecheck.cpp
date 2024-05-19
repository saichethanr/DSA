#include<bits/stdc++.h> 
using namespace std;
bool palindromecheck(string &s,int l,int r){
  if(l>=r){
    return true;
  }

  if(s[l]!=s[r]){
    return false;
  }

  return palindromecheck(s,l+1,r-1);
}
int main(){
    int l=0;
    string s = "malayalam";
    int r =s.size()-1;
    bool flag = palindromecheck(s,l,r);
    cout<<flag<<endl;
    return 0;
}

//there is a lso another single pointer approach with a tiime complexity of n/2