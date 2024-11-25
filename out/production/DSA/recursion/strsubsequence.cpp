#include<bits/stdc++.h> 
using namespace std;
void subsequence(string test, string output,int i){
   if(i>=test.size()){
    cout<<output<<endl;
      return;
   }

   // do not include 
   subsequence(test,output,i+1);
   //include
   output.push_back(test[i]);
   subsequence(test,output,i+1);
}

int main(){
    string test = "abc";
    string output = "";
    subsequence(test,output,0);
    return 0;
}