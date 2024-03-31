#include<bits/stdc++.h> 
using namespace std;

int removethelastsetbit(int n){
    return n&(n-1);
}
int main(){
    cout<<removethelastsetbit(13)<<endl;
}