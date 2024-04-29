#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int i=1;
 
    while(i<=n){
        int val=i;
        int j=1;
        while(j<=n){
            char ch='A'+val-1;
            cout<<ch;
            val=val+1;
            j=j+1;
        }
        
        cout<<endl;
        i=i+1;

    }
    return 0;
}