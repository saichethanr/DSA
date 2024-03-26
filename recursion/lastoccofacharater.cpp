#include<bits/stdc++.h> 
using namespace std;

void lastoccofchar(string s, int i,int &lastocc){
 if(i==s.size()){
   cout<<lastocc<<endl;
   return;
 }
 //solve one case
 if(s[i]=='b'){
    lastocc = i;
 }
 return lastoccofchar(s,i+1,lastocc);
}
int main(){
string s  = "abbeyaybl";
int i=0;
int lastocc = -1;
lastoccofchar(s,i,lastocc);
return 0;
}