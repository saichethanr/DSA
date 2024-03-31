#include<bits/stdc++.h> 
using namespace std;

bool checkifpowof2(int n){
    if(n && !(n & (n - 1))){
        return true;
    }
    return false;
}

int main(){
    cout << checkifpowof2(16) << endl;
    return 0;
}
