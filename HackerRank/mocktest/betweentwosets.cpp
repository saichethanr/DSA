#include<bits/stdc++.h> 
using namespace std;

int getTotalX(vector<int> a, vector<int> b) {
  int start =  *max_element(a.begin(),a.end());
  int end = *min_element(b.begin(),b.end());
  int cnt=0;
  for(int i=start;i<=end;i++){
      bool flag=true;
      for(int j=0;j<a.size();j++){
          if(i%a[j]!=0){
              flag=false;
              break;
          }
      }
      if(flag){
         for(int k=0;k<b.size();k++){
             if(b[k]%i!=0){
                 flag=false;
                 break;
             }
         }   
      }
      
      if(flag){
          cnt++;
      }
  }
   return cnt;
}